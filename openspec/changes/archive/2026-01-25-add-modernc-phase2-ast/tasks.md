## 1. Implementation
- [x] 1.1 Update gen_absyntax.py to emit modern node classes and visitor
      declarations returning VisitorResult.
- [x] 1.2 Add include/matiec/ast headers (Symbol/Token/List, Visitor,
      generated declarations).
- [x] 1.3 Add legacy compatibility shim bridging symbol_c/visitor_c to the
      new visitor interface.
- [x] 1.4 Add unit tests for AST ownership, visitor dispatch, and compatibility.
- [x] 1.5 Register new unit tests in tests/CMakeLists.txt.

## 2. Verification
- [x] 2.1 Build (WSL): cmake --build build-wsl
- [x] 2.2 Unit tests: ctest --test-dir build-wsl -R ModernAstTest --output-on-failure
