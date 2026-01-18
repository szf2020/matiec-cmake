# Documentation

This directory contains documentation for the matiec project.

## Files

| File | Description |
|------|-------------|
| [INTEGRATION.md](INTEGRATION.md) | Guide for integrating matiec into external projects (CPM, vcpkg, FetchContent) |
| [legacy/ARCHITECTURE.txt](legacy/ARCHITECTURE.txt) | Original detailed architecture documentation (compiler internals) |
| [legacy/BUILD_AUTOTOOLS.txt](legacy/BUILD_AUTOTOOLS.txt) | Legacy Autotools build instructions (deprecated) |

## Quick Links

- **Main README**: [../README.md](../README.md)
- **License**: [../COPYING](../COPYING)
- **Standard Library**: [../lib/](../lib/)

## Building

See the main [README.md](../README.md) for CMake build instructions.

## Architecture Overview

The matiec compiler works in 4 stages:

1. **Stage 1 (Lexer)**: Tokenizes IEC 61131-3 source code using Flex
2. **Stage 2 (Parser)**: Builds abstract syntax tree using Bison
3. **Stage 3 (Semantics)**: Type checking and flow control analysis
4. **Stage 4 (Code Gen)**: Generates C code (iec2c) or normalized IEC code (iec2iec)

For detailed architecture documentation, see [legacy/ARCHITECTURE.txt](legacy/ARCHITECTURE.txt).
