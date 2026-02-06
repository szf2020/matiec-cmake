## 1. Governance & Baseline
- [x] 1.1 创建 `refactor-modern-cpp-l2-l5` 变更提案与设计文档
- [x] 1.2 新增 `modernization-governance` 规范增量（里程碑+门禁+回滚）
- [x] 1.3 冻结 CLI/C API/codegen 行为基线并写入回归资产

## 2. Build System (L2)
- [x] 2.1 将顶层公共编译/链接选项收敛为 target-scoped 应用函数
- [x] 2.2 移除顶层全局 `include_directories(...)`
- [x] 2.3 将 tests 目标接入统一构建选项应用函数
- [x] 2.4 在 CI 中新增构建配置一致性检查

## 3. Core Architecture (L3-L4)
- [x] 3.1 AST/Visitor 主路径收敛并移除 legacy adapter
- [x] 3.2 类型系统在 stage3 完整替换 legacy 双轨路径
- [x] 3.3 stage4 引入统一 emitter 并建立 golden 白名单机制

## 4. Public Interface & Release (L5)
- [x] 4.1 发布稳定 `matiec.hpp` C++ API
- [x] 4.2 升级 `matiec.h` 到 v1 并给出旧新接口映射
- [x] 4.3 CLI v1 参数治理与迁移指南
- [x] 4.4 发布 `v0.3.0` 与发布后回归观察
