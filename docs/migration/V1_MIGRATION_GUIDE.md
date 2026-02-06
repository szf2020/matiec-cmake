# matiec v1 Migration Guide

This guide summarizes migration tasks for the v0.3.0 release (with v1 API contracts).

## 1) CLI Option Governance

All historical short options remain available. v1 introduces stable long aliases.

| Legacy | v1 long option | Notes |
|---|---|---|
| `-h` | `--help` | Show usage |
| `-v` | `--version` | Show version + changeset |
| `-I <dir>` | `--include <dir>` | Include search root |
| `-T <dir>` | `--target-dir <dir>` | Generated file directory |
| `-O <opts>` | `--output-options <opts>` | Stage4 options |
| `-f` | `--full-token-location` | Full token diagnostics |
| `-p` | `--allow-forward-refs` | Pre-parsing mode |
| `-l` | `--relaxed-datatype-model` | Relaxed type equivalence |
| `-s` | `--safe-extensions` | PLCopen SAFE extensions |
| `-n` | `--nested-comments` | IEC 61131-3 v3 comment nesting |
| `-r` | `--ref-extensions` | REF_TO/REF/^/NULL |
| `-R` | `--ref-nonstandard` | REF_TO ANY + struct/array extensions |
| `-a` | `--nonliteral-array-size` | Non-literal array bounds |
| `-i` | `--allow-missing-var-in` | POUs without VAR_IN |
| `-b` | `--allow-void-functions` | `VOID` return extension |
| `-e` | `--disable-implicit-en-eno` | Disable implicit EN/ENO |
| `-c` | `--conversion-functions` | Enum conversion generation |

## 2) C API v1 Contract

### Versioning and contract macros

- `MATIEC_VERSION_MAJOR`, `MATIEC_VERSION_MINOR`, `MATIEC_VERSION_PATCH`
- `MATIEC_VERSION_STRING`
- `MATIEC_C_API_LEVEL` (v1 defines `1`)
- `MATIEC_HAS_V1_API` (v1 defines `1`)

### Entrypoint mapping

| Existing API | v1 stable alias |
|---|---|
| `matiec_compile_file(...)` | `matiec_compile_file_v1(...)` |
| `matiec_compile_string(...)` | `matiec_compile_string_v1(...)` |
| `matiec_result_free(...)` | `matiec_result_free_v1(...)` |

Existing symbols are still available. v1 aliases are provided for explicit contract pinning in downstream integrations.

## 3) C++ API (`matiec/matiec.hpp`)

v1 introduces a stable RAII-friendly C++ wrapper:

```cpp
#include <matiec/matiec.hpp>

matiec::CompilerOptions options;
options.includeDir = MATIEC_LIB_DIR;
options.outputDir = "./out";
options.outputFormat = matiec::OutputFormat::C;

matiec::Compiler compiler(options);
auto result = compiler.compileFile("program.st");
if (!result.ok()) {
    std::fprintf(stderr, "compile failed: %s\n", result.diagnostic.message.c_str());
}
```

## 4) AST Legacy Adapter Policy

- Default build path does **not** include legacy AST adapter compatibility.
- `matiec/ast/legacy_compat.hpp` now requires opt-in macro `MATIEC_ENABLE_LEGACY_AST_COMPAT`.
- Recommended migration: move visitors to `matiec::ast::Visitor` and `VisitorResult`.

## 5) Suggested Upgrade Checklist

1. Replace scripted CLI invocations with long options (optional but recommended).
2. Switch C consumers to `_v1` API aliases for contract stability.
3. For C++ consumers, migrate to `matiec::Compiler` wrapper.
4. Remove dependencies on `legacy_compat.hpp` adapters.
5. Re-run your regression suites against v1 generated outputs.
