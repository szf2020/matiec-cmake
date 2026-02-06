# v0.3.0 Release Runbook

This runbook tracks the release gate and post-release observation for `v0.3.0`.

## Preflight Gate

Run all checks from a clean tree:

```bash
openspec validate refactor-modern-cpp-l2-l5 --strict
cmake -S . -B build -DMATIEC_BUILD_TESTS=ON
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
```

Run build-combination consistency check:

```bash
python3 tools/ci/check_build_consistency.py
```

## Baseline Assets to Review

- `tests/fixtures/codegen/POUS.c`
- `tests/fixtures/codegen/POUS.h`
- `tests/fixtures/codegen/simple_program.iec`
- `tests/fixtures/codegen/golden_whitelist.txt`
- `tests/e2e/test_cli_v1.cc`
- `tests/unit/test_matiec_api.cc`
- `tests/unit/test_cpp_api.cc`

## Tagging

```bash
git tag v0.3.0
git push origin v0.3.0
```

## Rollback Reference

If a severe regression is found immediately after release:

1. Mark the release as deprecated in release notes.
2. Revert to previous stable tag in downstream packaging.
3. Prepare hotfix branch from `v0.3.0` and re-run full gate.

## Post-release Observation (T+7)

Track during the first seven days:

- CLI compatibility issues (`--help/--version/--include/--target-dir`)
- C API consumer feedback on `_v1` aliases
- C++ wrapper adoption issues (`matiec/matiec.hpp`)
- Codegen diffs against golden fixtures

If no blocking issues are found in the first 7 days, mark `v0.3.0` as fully stabilized.
