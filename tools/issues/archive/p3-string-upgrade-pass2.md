# P3：字符串处理升级（Pass2）

目标：在 Pass1 的基础上，继续清理编译器 C++ 代码中残留的 C 风格字符串比较（主要是 `strcmp`），统一使用 `std::string_view` + `matiec::sv_or_empty()` 做 NULL-safe 的字面量比较，降低 UB 与平台差异风险；改动尽量小、可回滚。

非目标（本次不做）：
- 不触碰 `stage1_2/iec_bison.yy` / `stage1_2/iec_flex.ll`（涉及生成代码与语法动作，高风险，需单独计划与评审）。
- 不改运行时库/生成代码的字符串语义（例如 `STR_MAX_LEN` 等）。

## E2E loop
1) plan → issues：见 `issues/p3-string-upgrade-pass2.csv`
2) implement：按 issue 优先级逐个小提交（每个 issue 一个 commit）
3) test：每个 code issue 至少 Windows Release build + `ctest`
4) review：重点检查：
   - `std::string_view` 与 `const char*` 的边界（NULL/空串语义）
   - 比较语义保持不变（本次均为大小写敏感的字面量比较）
   - stage4 代码生成路径的行为一致性
5) commit：按 issue 粒度提交，方便回滚
6) regression：Windows 全量 ctest + CI（linux-x64-sanitizers）通过

## 默认验证命令
- Windows：`cmake --build build-vs --config Release`；`ctest --test-dir build-vs -C Release --output-on-failure`
- CI：GitHub Actions `linux-x64-sanitizers`（ASan+LSan detect_leaks=1）

## 风险
- stage4 属于代码生成关键路径：比较逻辑微调可能影响生成输出，需要依赖现有测试与 CI 门禁兜底。

## 回滚/安全
- 每个 issue 独立 commit；可按 commit 粒度 `git revert <sha>` 回滚。
- 默认保持 ABI/API 与既有输出语义不变；若必须变更，在 issue Notes 里记录并补充验证。

