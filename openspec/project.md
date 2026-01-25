# Project Context

## Purpose
Provide a CMake-based build of matiec, an IEC 61131-3 compiler that translates
PLC languages (ST/IL/SFC) into ANSI C and ships tools (iec2c/iec2iec) plus the
standard runtime library.

## Tech Stack
- C/C++ (C++17 enforced by CMake; generated output is ANSI C)
- CMake 3.16+ build system, CTest for tests
- Flex + Bison (WinFlexBison on Windows)
- Optional: clang-tidy, sanitizers, Git version metadata
- Integration: CPM.cmake, FetchContent, vcpkg overlay port

## Project Conventions

### Code Style
- Follow .editorconfig: 4-space indent, LF endings, trim trailing whitespace
- Follow .clang-format: LLVM base, 4-space indent, column limit 100
- Avoid repository-wide formatting; limit formatting to touched code

### Architecture Patterns
- Compiler pipeline by stages: src/stage1_2 (Flex/Bison), src/stage3 (semantics),
  src/stage4 (code generation)
- AST in src/absyntax and src/absyntax_utils; runtime and IEC library in src/lib/

### Testing Strategy
- Tests are built with MATIEC_BUILD_TESTS and run via CTest
- Default verification per docs/testing-policy.md (build-vs Release + ctest)
- Prefer narrow tests first; expand to full ctest for higher-risk changes

### Git Workflow
- No explicit branching policy documented; keep small, reviewable commits
- Use Angular commit messages: type(scope): subject (per AGENTS.md)

## Domain Context
- IEC 61131-3 compiler for PLC languages (ST/IL/SFC; FBD/LD partial)
- Outputs ANSI C plus runtime support from src/lib/; ships iec2c/iec2iec tools

## Important Constraints
- Cross-platform support (Windows/Linux/macOS) and portable toolchains
- Flex/Bison required; CMake enforces C++17
- Avoid large-format churn in legacy code
- GPL-3.0 licensing applies

## External Dependencies
- Flex/Bison (WinFlexBison on Windows)
- C/C++ toolchain (MSVC/Clang/GCC)
- CMake 3.16+
- Optional: clang-tidy, sanitizers, Git for version metadata
