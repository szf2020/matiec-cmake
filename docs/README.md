# Documentation

This directory contains documentation for the matiec project.

## Files

| File | Description |
|------|-------------|
| [INTEGRATION.md](INTEGRATION.md) | Guide for integrating matiec into external projects (CPM, vcpkg, FetchContent) |
| [migration/V1_MIGRATION_GUIDE.md](migration/V1_MIGRATION_GUIDE.md) | Breaking-change migration mapping for CLI/C API/C++ API |
| [testing/V1_BASELINE.md](testing/V1_BASELINE.md) | Frozen CLI/C API/C++ API/codegen regression baseline |
| [release/V0_3_0_RELEASE_RUNBOOK.md](release/V0_3_0_RELEASE_RUNBOOK.md) | v0.3.0 release gate, rollback, and observation checklist |
| [architecture/ARCHITECTURE.txt](architecture/ARCHITECTURE.txt) | Detailed architecture documentation (compiler internals) |
| [architecture/CMAKE_MIGRATION_PLAN.md](architecture/CMAKE_MIGRATION_PLAN.md) | Historical CMake migration plan |

## Quick Links

- **Main README**: [../README.md](../README.md)
- **License**: [../COPYING](../COPYING)
- **Standard Library**: [../src/lib/](../src/lib/)

## Building

See the main [README.md](../README.md) for CMake build instructions.

## Architecture Overview

The matiec compiler works in 4 stages:

1. **Stage 1 (Lexer)**: Tokenizes IEC 61131-3 source code using Flex
2. **Stage 2 (Parser)**: Builds abstract syntax tree using Bison
3. **Stage 3 (Semantics)**: Type checking and flow control analysis
4. **Stage 4 (Code Gen)**: Generates C code (iec2c) or normalized IEC code (iec2iec)

For detailed architecture documentation, see [architecture/ARCHITECTURE.txt](architecture/ARCHITECTURE.txt).
