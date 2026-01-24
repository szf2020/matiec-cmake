## 1. Implementation
- [x] 1.1 Add include/matiec/ast/visitor_result.hpp (VisitorResult + helpers).
- [x] 1.2 Add include/matiec/compiler/compilation_unit.hpp (AST ownership,
      ErrorReporter access, source metadata).
- [x] 1.3 Add unit tests for VisitorResult and CompilationUnit.
- [x] 1.4 Register new unit tests in tests/CMakeLists.txt.

## 2. Verification
- [x] 2.1 Build (WSL): cmake --build build-wsl
- [x] 2.2 Unit tests: ctest --test-dir build-wsl -R VisitorResultTest --output-on-failure
- [x] 2.3 Unit tests: ctest --test-dir build-wsl -R CompilationUnitTest --output-on-failure
