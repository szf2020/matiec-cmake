# v1 Baseline Assets

This document defines the frozen regression baseline for the v1 modernization release.

## CLI Baseline

Validated by `tests/e2e/test_cli_v1.cc`:

- `-h` and `--help` output must remain identical.
- `-v` and `--version` output must remain identical.
- `--include` and `--target-dir` must compile a minimal fixture successfully.

## C API Baseline

Validated by `tests/unit/test_matiec_api.cc`:

- `MATIEC_C_API_LEVEL == 1`
- `MATIEC_HAS_V1_API == 1`
- `matiec_compile_file_v1(...)` compiles parity with existing entrypoint.
- `matiec_result_free_v1(...)` behaves as stable cleanup alias.

## C++ API Baseline

Validated by `tests/unit/test_cpp_api.cc`:

- `matiec::Compiler::compileString(...)` success path.
- `matiec::Compiler::compileFile(...)` error propagation path.

## Codegen Baseline

Validated by `tests/e2e/test_codegen_regression.cc` against:

- `tests/fixtures/codegen/POUS.c`
- `tests/fixtures/codegen/POUS.h`
- `tests/fixtures/codegen/simple_program.iec`
- whitelist file `tests/fixtures/codegen/golden_whitelist.txt`

Line endings are normalized during assertions to keep baseline portable across Windows/Linux/macOS.
