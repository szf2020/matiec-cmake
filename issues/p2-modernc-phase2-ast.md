# P2: Modern C++ Phase 2 AST and Visitor Modernization

Goal: modernize AST ownership and visitor interfaces with a compatibility layer
so later phases can migrate semantics and codegen safely.

Non-goals:
- No semantic or codegen behavior changes.
- No CLI or C API changes.

## Steps (E2E loop)
1) plan -> issues: generate Issue CSV (A1-A3).
2) implement: generator updates, new headers, compatibility shim.
3) test: build + AST/visitor unit tests.
4) review: verify behavior remains unchanged via regression tests.
5) commit: per-issue commits if needed.
6) regression: run full ctest after A1-A3 complete.

## Verification
- Build (WSL): cmake --build build-wsl
- Tests: ctest --test-dir build-wsl -R ModernAstTest --output-on-failure

## Risks
- Generator errors can impact many nodes.
- Compatibility shim may diverge from modern visitor semantics.

## Rollback / Safety
- Revert the change commit(s); keep legacy headers in place until Phase 6.
