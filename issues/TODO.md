# TODO List（按优先级）

说明：本仓库使用 Issue CSV 作为“执行契约”，字段含义与格式要求见 `issues/README.md`。本清单仅用于快速导航；以 CSV 中的状态为准。

## 进行中

- 当前无进行中的 Issue CSV（已完成一次 P2 回归并写回状态）

## 下一步（按优先级）

1) P3（字符串处理升级）拆分为 Issue CSV（来自 `C:\\Users\\lus\\.claude\\plans\\tingly-riding-volcano.md`）
   - token_c 改为 `std::string`（可能需要同步调整 Flex/Bison 交互）
   - 只读参数改用 `std::string_view`
   - 移除固定长度缓冲区与不安全的 C 字符串拼接
   - 统一字符串比较/大小写/路径处理等工具函数

2) P2（内存管理）后续路线梳理（在 `docs/AST-OWNERSHIP.md` 基础上）
   - 明确是否继续推进“子树级所有权”（高风险：Bison + SYM_REF* 宏）
   - 若继续推进：优先做小范围试点并补强回归门禁（ASan/LSan/CI）

## 已完成（DONE）

- `issues/p-modern-cpp-style-overview.csv`：M1-M8
- `issues/p2-memory-safety-guardrails-pass1.csv`：B1-B3
- `issues/p2-memory-safety-guardrails-pass2.csv`：C1-C3
- `issues/p2-stage4-raii-pass1.csv`：A1-A4
- `issues/p2-raii-sweep-pass2.csv`：D1-D4
- `issues/p2-ast-ownership-pilot-pass1.csv`：E1-E4（含回归；CI run 21267483767）
