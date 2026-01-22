# P2：RAII Sweep Pass2（Stage4 generate_c.cc + Stage3 search_* 指针）

目标：在不改变默认构建与输出行为的前提下，继续消除“局部/明确所有权”的 `new/delete`，提升异常/早退路径的内存安全，为后续更大范围的 P2（AST 所有权）改造降低风险。

非目标：
- 不在本 pass 内改动 AST 节点的所有权模型（`absyntax/*` 仍按现有方式分配/释放）。
- 不修改对外 API（`new_code_generator/delete_code_generator` 仍使用 raw pointer）。
- 不做全库格式化或纯风格重排。

## 步骤（E2E loop）
1) plan → issues：见 `issues/p2-raii-sweep-pass2.csv`
2) implement：
   - D1：`stage4/generate_c/generate_c.cc` 中局部 helper/临时对象改为栈对象或 `std::unique_ptr`
   - D2：`stage3/array_range_check` 的 `search_varfb_instance_type` 改为 `std::unique_ptr`
   - D3：`stage3/lvalue_check` 的 `search_*` 指针改为 `std::unique_ptr`
3) test：每个 issue 至少 Windows Release build + `ctest`；全部完成后跑 WSL(ASan+LSan) 全量 `ctest`
4) review：确认不改语义/输出；确认未引入新的生命周期问题
5) commit：按 issue 粒度小提交
6) regression：执行 D4，并依赖 CI 验证（含 Sanitizers + LSan 门禁）

## 默认验证命令
- Windows：`cmake --build build-vs --config Release`；`ctest --test-dir build-vs -C Release --output-on-failure`
- WSL（ASan+LSan）：`ASAN_OPTIONS=detect_leaks=1 ctest --test-dir build-wsl-asan --output-on-failure`

## 风险
- 将 heap 临时对象改为栈对象可能改变构造/析构时机；若原逻辑依赖副作用顺序，需要额外小心。
- 个别 helper 可能隐式依赖动态分配或多态；若无法安全栈化则改用 `std::unique_ptr` 或保持原状（记录原因）。

## 回滚/安全
- 每个 issue 独立 commit，可逐个 `git revert <sha>` 回滚；默认行为不改。

