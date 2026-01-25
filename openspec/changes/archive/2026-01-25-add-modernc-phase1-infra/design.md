## Context
Phase 1 introduces foundational, additive headers to support the modern C++
refactor described in docs/MODERNC_DESIGN.md. The change is scoped to new
infrastructure only; no existing visitor APIs or runtime behaviors are altered.

## Goals / Non-Goals
- Goals:
  - Provide a type-safe visitor result abstraction for future AST work.
  - Provide a CompilationUnit RAII container for AST ownership and error access.
  - Keep the change additive and compatible with the current C++17 baseline.
- Non-Goals:
  - No migration of existing AST nodes or visitors in this phase.
  - No change to CLI behavior, C API, or generated output.
  - No C++20 upgrade.

## Decisions
- Use a std::variant-based VisitorResult with small helper utilities
  (get_result<T>, holds_result<T>, is_empty) in matiec::ast.
- Implement CompilationUnit in matiec::compiler owning an AST root via
  std::unique_ptr, exposing ErrorReporter, and storing source metadata.
- Keep headers standalone and limited to C++17 standard library types.

## Risks / Trade-offs
- Additive headers may drift from later implementations; unit tests will lock
  down expected behavior.
- Naming collisions are possible; keep namespaced and focused.

## Migration Plan
1) Add headers and unit tests in this change.
2) Later phases adopt these types in AST/visitor rewrites.

## Open Questions
- Should CompilationUnit store source paths as std::string or
  std::filesystem::path? (Default to std::string for now.)
