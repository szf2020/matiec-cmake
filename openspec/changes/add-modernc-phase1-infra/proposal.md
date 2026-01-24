# Change: Phase 1 Modern C++ Infrastructure (VisitorResult + CompilationUnit)

## Why
Phase 1 establishes small, additive infrastructure needed for the modern C++ refactor
without changing runtime behavior. The goal is to make later AST and compiler work
safer (type-safe visitor results and RAII ownership) while keeping C++17 and existing
APIs intact.

## What Changes
- Add include/matiec/ast/visitor_result.hpp defining VisitorResult and helper
  utilities for type-safe visitor return values.
- Add include/matiec/compiler/compilation_unit.hpp defining CompilationUnit to
  own the AST root and expose error reporting and source metadata.
- Add unit tests for both headers.
- No breaking changes; existing visitor interfaces remain unchanged in this phase.

## Impact
- Affected specs: ast-visitor-result, compiler-compilation-unit
- Affected code: include/matiec/ast/visitor_result.hpp,
  include/matiec/ast/symbol.hpp, include/matiec/compiler/compilation_unit.hpp,
  unit tests, tests/CMakeLists.txt
- Risk level: low (additive, header-only)
