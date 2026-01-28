## 1. Workflow
- [x] 1.1 新增 release workflow（仅正式 tag 触发）
- [x] 1.2 校验必要 secrets 与 fork 配置（缺失时失败并给出提示）
- [x] 1.3 拉取 vcpkg fork，生成/更新 `ports/matiec/` 内容
- [x] 1.4 计算源码归档 SHA512 并更新 portfile 引用
- [x] 1.5 运行 `vcpkg x-add-version matiec` 更新 versions 元数据
- [x] 1.6 提交到 fork 分支并创建 PR 到 `microsoft/vcpkg`

## 2. Documentation
- [x] 2.1 更新 `docs/INTEGRATION.md`：说明自动提 PR 的前置条件与 secrets 配置
