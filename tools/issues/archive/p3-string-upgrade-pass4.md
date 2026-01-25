# P3：字符串处理升级（Pass4）

目标：在不改变编译器行为的前提下，进一步收敛 token/文件名的生命周期风险，减少对 `cstr_pool` 指针存活期的隐式依赖，并补充单测验证。

非目标（本次不做）：
- 不将 Bison `%union` 从 `char*` 升级为 `std::string`（高风险，需单独评审与迁移策略）。
- 不改变语义或输出格式（仅做存储/生命周期安全增强）。

## E2E loop
1) plan → issues：见 `issues/p3-string-upgrade-pass4.csv`
2) implement：按 issue 优先级逐个小提交（每个 issue 一个 commit）
3) test：每个 code issue 至少 Windows Release build + `ctest`
4) review：重点检查：
   - `first_file/last_file` 复制后不依赖 `cstr_pool` 生命周期
   - list_c 的查找行为与大小写语义保持不变
5) commit：按 issue 粒度提交，方便回滚
6) regression：Windows 全量 ctest

## 默认验证命令
- Windows：`cmake --build build-vs --config Release`；`ctest --test-dir build-vs -C Release --output-on-failure`

## 风险
- AST 内部新增字符串副本可能增加少量内存占用（但换来更清晰的生命周期边界）。

## 回滚/安全
- 每个 issue 独立 commit；可按 commit 粒度 `git revert <sha>` 回滚。
- 不引入对外行为变更；仅强化生命周期安全。
