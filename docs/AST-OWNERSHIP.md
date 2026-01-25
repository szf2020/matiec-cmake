# AST 生命周期与所有权（现状与渐进式改造）

本文说明 matiec 在“库/测试环境”下的 AST 与 lexer 字符串生命周期管理方式，并给出后续 P2（内存管理/所有权）改造的推荐边界与演进路径。

## 1. 现状：以“编译为单位”的集中式释放

### 1.1 AST 节点的分配与跟踪
- 所有 AST 节点（`symbol_c` 及其派生类）通过 `new` 分配。
- `symbol_c` 重载了 `operator new/delete`，把每次 `new` 分配的指针登记到全局集合里（heap tracking）。
- 目的：在编译结束时可以“统一释放本次编译产生的所有 heap AST 节点”，而无需逐类实现复杂的递归析构。

关键实现：`src/absyntax/ast_memory.cc`。

### 1.2 lexer/parser 产生的 C 字符串池（token/文件名）
历史代码大量使用 `const char*`/`char*` 保存 token 值和文件名，这些字符串需要在一次编译过程中保持稳定地址。
- `matiec::cstr_pool_*` 将这些字符串的生命周期绑定到“编译结束清理”。
- `matiec::cstr_pool_clear()` 在编译结束时统一释放池中字符串。

### 1.3 “不应释放”的 AST 节点：pin 机制
部分对象可能是“进程级缓存/单例”（例如某些阶段化缓存的字面量或共享节点）。
- `matiec::ast_pin(symbol)` 会将该对象及其可达子图标记为 pinned。
- pinned 节点会被 `ast_delete` 跳过，从而在多次编译中复用。

注意：pin 是一个强语义工具；只有确实需要进程级存活且可证明安全时才使用。

### 1.4 统一释放：`matiec::ast_delete`
`matiec::ast_delete(root)`/`ast_delete(root1, root2)` 做两件事：
1) 从 root 出发遍历语法子节点（通过 visitor 推子节点）+ 泛化处理“注解边”（`token/datatype/scope/candidate_datatypes/anotations_map`），收集可删除节点；
2) 额外删除“本次编译产生但未挂到 root 的节点”（例如错误恢复路径产生的临时节点）。

这使得 **调用一次 `ast_delete` 即可完成一次编译的 AST 释放**（除了 pinned 节点）。

## 2. 编译结束的推荐清理顺序（非常重要）

由于一些全局表会缓存“指向 AST 的裸指针”，清理顺序必须稳定：
1) `absyntax_utils_reset()`：先清空引用 AST 的全局表
2) `matiec::ast_delete(tree_root, ordered_tree_root)`：释放 AST（含 stage3 可能产生的 reordered root）
3) `matiec::cstr_pool_clear()`：释放 token/文件名字符串池
4) `stage1_2_reset()`：清空 lexer/parser 的全局符号表与状态（为下一次编译做准备）

CLI 与 C API 都应遵循同一顺序，避免“多次调用编译 API”场景出现 UAF/泄漏。

## 3. 关键约束与常见坑

### 3.1 不要在“编译尚未结束”时随意调用 `ast_delete`
`ast_delete` 的语义是“释放本次编译产生的 heap AST 节点集合”，并不等同于“释放某个子树”。
因此：
- 只能在“确认不再需要当前编译产生的 AST”时调用；
- 若要释放某个临时 AST（例如预解析生成的临时树），必须保证该临时树对应的分配集合与后续编译阶段不交叉。

### 3.2 不要跨编译持有 AST 裸指针
一旦下一次编译开始并执行清理，之前的 AST 指针将失效。
如果需要跨编译持久化信息，应复制为值类型（如字符串/结构化数据），而不是保存 `symbol_c*`。

### 3.3 pin 的风险
pin 会让对象跨编译存活，带来：
- 进程内存增长（pinned 永不释放）；
- 线程安全/重入风险（若未来并行编译）；
- 逻辑耦合（pin 的对象必须与编译输入无关，且不可持有编译态资源）。

## 4. 渐进式所有权/unique_ptr 改造建议（P2 路线）

在当前机制下，“把每个 AST 成员都改成 `std::unique_ptr`”属于高风险大改造（涉及 bison 生成代码、`SYM_REF*` 宏展开、list/visitor 语义等）。

建议优先从 **编译边界（compilation boundary）** 入手：
1) 使用 `std::unique_ptr + 自定义 deleter` 在入口处绑定“编译级资源”的释放（AST roots / cstr_pool / stage resets），保证所有退出路径（early return/异常）都能清理；
2) 提取可复用的 `compilation_cleanup_guard`，让 CLI 与 C API 共享同一套清理逻辑，减少分叉；
3) 在 stage3/stage4 等模块继续推进“局部、明确所有权”的 RAII（已经在 P2 RAII sweep 中验证有效）；
4) 当需要真正的“子树级所有权”时，再评估：
   - 引入 per-compilation arena（区域分配）并在编译结束统一释放；或
   - 逐类引入显式析构（递归释放语法子节点）并相应调整 `ast_delete` 的策略。

## 5. 验证建议
- Windows：`ctest --test-dir build-vs -C Release --output-on-failure`
- WSL（ASan+LSan）：`ASAN_OPTIONS=detect_leaks=1 ctest --test-dir build-wsl-asan --output-on-failure`
- CI：关注 `linux-x64-sanitizers`（含 LeakSanitizer 门禁）
