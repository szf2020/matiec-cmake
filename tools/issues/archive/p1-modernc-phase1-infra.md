# P1: Modern C++ Phase 1 Infrastructure (VisitorResult + CompilationUnit)

Goal: add additive C++17 headers for visitor results and compilation units to
support later modernization work without changing runtime behavior.

Non-goals:
- No migration of existing AST nodes or visitor interfaces.
- No changes to CLI behavior, C API, or generated output.
- No C++20 upgrade.

## Steps (E2E loop)
1) plan -> issues: generate Issue CSV (A1-A2).
2) implement: add headers and unit tests.
3) test: build + targeted unit tests.
4) review: confirm additive scope and no behavior changes.
5) commit: per-issue commits if needed.
6) regression: run full ctest only after A1-A2 complete.

## Verification
- Build (WSL): cmake --build build-wsl
- Tests: ctest --test-dir build-wsl -R VisitorResultTest --output-on-failure
- Tests: ctest --test-dir build-wsl -R CompilationUnitTest --output-on-failure

## Risks
- Additive headers may drift from later phases; lock expectations via unit tests.
- Mis-scoped APIs could cause rework in later AST refactors.

## Rollback / Safety
- Revert the change commit(s); no data migrations involved.
