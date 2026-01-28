## Context
发布新版本时，需要将端口同步到官方 vcpkg。官方仓库不接受直接推送，只能通过 PR。
因此需要在本仓库发布时自动更新 fork 并发起 PR。

## Goals / Non-Goals
- Goals:
  - 正式 tag 自动创建到 microsoft/vcpkg 的 PR
  - 端口版本与 SHA512 自动更新并生成 versions 元数据
  - 失败时有清晰的诊断提示
- Non-Goals:
  - 直接推送/合并到官方仓库
  - 预发布 tag（包含 `-`）自动提 PR
  - 自动通过审核或自动合并

## Decisions
- 使用 GitHub Actions workflow 触发于 `push` tag `v*`，在 job 中过滤包含 `-` 的 tag
- 使用 token（Secret: `VCPKG_PR_TOKEN`）对 fork 写入并在上游创建 PR
  - 首选 Classic PAT（`public_repo`），可对公共仓库创建 PR
  - Fine-grained PAT 仅在可选择 `microsoft/vcpkg` 时可用
- 在 workflow 中拉取 `microsoft/vcpkg` fork，更新端口与 `versions/`，使用 `vcpkg x-add-version`
- 使用 `gh` 创建 PR，标题格式为 `matiec: update to v<version>`
- fork 固定为 `https://github.com/lusipad/vcpkg`，默认分支 `master`

## Risks / Trade-offs
- 需要维护 PAT，存在凭据泄露风险（采用最小权限、仅限 fork/上游）
- `vcpkg x-add-version` 需要 bootstrap，workflow 会变慢
- 官方审核规则可能随时间变化，workflow 需定期维护

## Migration Plan
1. 创建 vcpkg fork
2. 创建 PAT 并配置 secrets
3. 先在测试 tag 上演练（预期自动跳过）
4. 发布正式 tag 并观察 PR 产物

## Open Questions
- 暂无
