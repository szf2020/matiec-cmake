# Change: Phase 2 Modern C++ AST and Visitor Modernization

## Why
Phase 2 modernizes the AST and visitor interfaces to enable safer ownership,
type-safe traversal, and a path to later semantic and codegen refactors while
keeping current behavior intact.

## What Changes
- Update gen_absyntax.py to generate modern AST node classes with
  std::unique_ptr ownership and VisitorResult-based dispatch.
- Add new AST headers under include/matiec/ast/ (Symbol/Token/List, Visitor,
  generated declarations).
- Provide a legacy compatibility layer to bridge symbol_c/isitor_c with the
  modern API.
- Add unit tests for AST ownership, visitor dispatch, and the compatibility shim.

## Impact
- Affected specs: ast-modernization
- Affected code: gen_absyntax.py, include/matiec/ast/*, unit tests,
  	ests/CMakeLists.txt
- Risk level: medium (core AST plumbing, but compatibility layer keeps behavior)
