# Change: L2-L5 一次性现代化改造（破坏性升级）

## Why
当前仓库已经具备 C++17、跨平台 CI、测试与部分现代化模块，但总体仍处于“新旧并存”状态：
- 构建配置存在全局编译选项与全局 include，目标边界不够清晰；
- AST/类型/语义/代码生成仍有双轨实现与历史接口耦合；
- 对外接口（CLI/C API/C++ API）缺少统一的版本化升级契约。

为了将项目升级为可持续演进的现代 C++ 编译器平台，需要在单主线上完成 L2-L5 全量改造，并建立严格阶段门禁，确保破坏性升级可控。

## What Changes
- 新增 `modernization-governance` 能力：定义 L2-L5 里程碑、阶段门禁、回滚机制与验收标准。
- 在构建系统中推进 target-scoped 配置：
  - 移除全局 `include_directories(...)`；
  - 将公共编译/链接选项收敛到目标级应用函数；
  - 统一核心目标的 clang-tidy/编译选项挂载点。
- 按阶段推进 AST/类型/语义/代码生成主路径收敛，最终发布 breaking `v0.3.0`。

## Impact
- Affected specs: 新增 `modernization-governance`
- Affected code: `CMakeLists.txt`、后续 `src/**`、`tests/**`、`docs/**`
- Breaking changes: 是（CLI/C API/C++ API 将按 v1 统一升级）
