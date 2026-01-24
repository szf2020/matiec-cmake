## Context
Phase 2 updates the AST and visitor interfaces based on the modern C++ design
in docs/MODERNC_DESIGN.md. The change is core plumbing but is scoped to keep
runtime behavior and legacy entry points intact via a compatibility layer.

## Goals / Non-Goals
- Goals:
  - Modernize AST node ownership with std::unique_ptr.
  - Replace void* visitor returns with VisitorResult.
  - Preserve existing behavior via a legacy adapter.
- Non-Goals:
  - No semantic or codegen behavior changes.
  - No C API or CLI changes.

## Decisions
- Generate node classes and visitor declarations from gen_absyntax.py to avoid
  hand edits across 500+ nodes.
- Use non-owning parent pointers and owning child pointers.
- Provide legacy_compat.hpp that maps modern visitor results to void*.

## Risks / Trade-offs
- Large header surface; errors in the generator can impact many nodes.
- Compatibility shim increases maintenance cost until Phase 6 removal.

## Migration Plan
1) Add modern AST headers and generator output.
2) Introduce compatibility shim and keep legacy code compiling.
3) Move call sites over in later phases.

## Open Questions
- Should generated nodes live under include/matiec/ast/generated/ or be split
  by category (declarations/expressions/statements)?
