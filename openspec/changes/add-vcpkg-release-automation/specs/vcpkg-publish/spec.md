## ADDED Requirements

### Requirement: 自动创建 vcpkg 官方 PR
当发布正式 tag 时，系统 MUST 在 vcpkg fork 上更新 matiec 端口并向 microsoft/vcpkg 发起 PR。

#### Scenario: 正式发布触发
- **WHEN** 推送 Git tag `v1.2.3`
- **THEN** 生成包含端口更新的 fork 分支并创建 PR 至 `microsoft/vcpkg`

#### Scenario: 预发布跳过
- **WHEN** 推送 Git tag `v1.2.3-beta.1`
- **THEN** workflow 退出且不创建 PR

### Requirement: 缺少凭据时失败并提示
当缺少用于写入 fork 或创建 PR 的凭据时，系统 MUST 失败并输出明确提示。

#### Scenario: 未配置 token
- **WHEN** workflow 运行且 `VCPKG_PR_TOKEN` 未设置
- **THEN** job 失败并提示缺失的 secret 名称
