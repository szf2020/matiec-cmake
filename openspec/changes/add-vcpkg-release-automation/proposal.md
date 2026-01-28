# Change: 正式发布自动提 vcpkg 官方 PR

## Why
当前需要手工同步端口到 microsoft/vcpkg，流程繁琐且容易遗漏版本与 SHA512 更新。

## What Changes
- 新增 release workflow：仅在正式 tag（例如 `v1.2.3`）触发，自动在 fork 更新端口并向 microsoft/vcpkg 提 PR
- 在 workflow 中完成 SHA512 计算、端口更新、`vcpkg x-add-version` 版本元数据生成
- 补充文档：说明 fork、token、secrets 配置与发布流程

## Impact
- Affected specs: 新增 `vcpkg-publish` 能力
- Affected code: `.github/workflows/`、`docs/INTEGRATION.md`
- Breaking changes: 无
