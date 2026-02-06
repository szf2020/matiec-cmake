# External Integration Guide

This document describes how to integrate matiec into your project using various package managers.

## Prerequisites

All methods require `flex` and `bison` to be installed on the build machine:

- **Windows**: `choco install winflexbison3`
- **macOS**: `brew install flex bison`
- **Linux (Debian/Ubuntu)**: `apt install flex bison`

---

## Usage Methods Overview

| Method | Use Case |
|--------|----------|
| **Library API** | Embed compiler functionality directly in your C/C++ application |
| **Command-line** | Run iec2c/iec2iec as external tools in build scripts |
| **CPM/FetchContent** | Include as CMake dependency for source builds |
| **find_package** | Link against installed library |
| **vcpkg** | Enterprise package management |

---

## Method 1: Library API (Recommended for Embedding)

matiec provides a C library API for embedding the compiler directly in your application.

### Basic Usage

```c
#include <matiec/matiec.h>

int main() {
    // Initialize options
    matiec_options_t opts;
    matiec_options_init(&opts);
    opts.include_dir = "/path/to/matiec/lib";
    opts.output_dir = "/path/to/output";

    // Compile a file
    matiec_result_t result;
    matiec_error_t ret = matiec_compile_file("program.st", &opts, &result);

    if (ret == MATIEC_OK) {
        printf("Compilation successful!\n");
    } else {
        printf("Error: %s\n", matiec_error_string(ret));
        if (result.error_message) {
            printf("Details: %s\n", result.error_message);
        }
    }

    // Clean up
    matiec_result_free(&result);
    return ret;
}
```

### Compile from String

```c
const char *source =
    "PROGRAM main\n"
    "VAR\n"
    "    counter : INT := 0;\n"
    "END_VAR\n"
    "    counter := counter + 1;\n"
    "END_PROGRAM\n";

matiec_result_t result;
matiec_error_t ret = matiec_compile_string(
    source,
    0,              // 0 = auto-detect length
    "main.st",      // virtual filename for errors
    &opts,
    &result
);
```

### CMake Integration (Library)

```cmake
cmake_minimum_required(VERSION 3.16)
project(my_compiler_frontend)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME matiec
    GITHUB_REPOSITORY lusipad/matiec-cmake
    GIT_TAG v0.3.0
)

add_executable(my_app main.c)

# Link against the library
target_link_libraries(my_app PRIVATE matiec::matiec)

# If you also need the IEC standard library path
target_compile_definitions(my_app PRIVATE
    MATIEC_LIB_DIR="${MATIEC_LIB_DIR}"
)
```

### API Reference

#### Types

| Type | Description |
|------|-------------|
| `matiec_options_t` | Compiler options structure |
| `matiec_result_t` | Compilation result structure |
| `matiec_error_t` | Error code enumeration |
| `matiec_output_format_t` | Output format (C or IEC) |

#### Functions

| Function | Description |
|----------|-------------|
| `matiec_options_init()` | Initialize options to defaults |
| `matiec_compile_file()` | Compile from file |
| `matiec_compile_string()` | Compile from string |
| `matiec_compile_file_v1()` | Stable v1 alias for `matiec_compile_file()` |
| `matiec_compile_string_v1()` | Stable v1 alias for `matiec_compile_string()` |
| `matiec_result_free()` | Free result resources |
| `matiec_result_free_v1()` | Stable v1 alias for `matiec_result_free()` |
| `matiec_version()` | Get library version |
| `matiec_error_string()` | Get error description |

#### C++ Wrapper API (`matiec/matiec.hpp`)

```cpp
#include <matiec/matiec.hpp>

matiec::CompilerOptions options;
options.includeDir = MATIEC_LIB_DIR;
options.outputDir = "./out";

matiec::Compiler compiler(options);
auto result = compiler.compileFile("program.st");
if (!result.ok()) {
    std::fprintf(stderr, "compile failed: %s
", result.diagnostic.message.c_str());
}
```

#### Compiler Options

```c
typedef struct {
    const char *include_dir;       // -I: Include directory
    const char *output_dir;        // -T: Output directory
    matiec_output_format_t output_format; // C or IEC output

    bool allow_forward_refs;       // -p: Forward references
    bool relaxed_datatype_model;   // -l: Relaxed type checking
    bool safe_extensions;          // -s: SAFE datatypes
    bool nested_comments;          // -n: Nested comments
    bool ref_extensions;           // -r: REF_TO, REF, ^, NULL
    bool ref_nonstandard;          // -R: REF_TO ANY
    bool nonliteral_array_size;    // -a: Non-literal array sizes
    bool allow_void_functions;     // -b: VOID return type
    bool allow_missing_var_in;     // -i: POUs without parameters
    bool disable_implicit_en_eno;  // -e: No EN/ENO generation
    bool conversion_functions;     // -c: Type conversion functions
    bool full_token_location;      // -f: Full error locations
} matiec_options_t;
```

---

## Method 2: Command-line Tools

Use iec2c and iec2iec as external build tools.

### CPM.cmake

```cmake
cmake_minimum_required(VERSION 3.16)
project(my_plc_project)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME matiec
    GITHUB_REPOSITORY lusipad/matiec-cmake
    GIT_TAG master
)

# Compile IEC source to C
add_custom_command(
    OUTPUT ${CMAKE_BINARY_DIR}/generated/my_program.c
    COMMAND iec2c
        -I ${MATIEC_LIB_DIR}
        -T ${CMAKE_BINARY_DIR}/generated
        ${CMAKE_SOURCE_DIR}/src/my_program.st
    DEPENDS iec2c ${CMAKE_SOURCE_DIR}/src/my_program.st
    COMMENT "Compiling IEC 61131-3 to C"
)

add_custom_target(generate_plc_code ALL
    DEPENDS ${CMAKE_BINARY_DIR}/generated/my_program.c
)

# Compile the generated C code
add_library(plc_runtime STATIC ${CMAKE_BINARY_DIR}/generated/my_program.c)
target_include_directories(plc_runtime PRIVATE
    ${MATIEC_LIB_DIR}/C
    ${CMAKE_BINARY_DIR}/generated
)
add_dependencies(plc_runtime generate_plc_code)
```

### FetchContent (CMake built-in)

```cmake
cmake_minimum_required(VERSION 3.16)
project(my_plc_project)

include(FetchContent)

FetchContent_Declare(
    matiec
    GIT_REPOSITORY https://github.com/lusipad/matiec-cmake.git
    GIT_TAG master
)

FetchContent_MakeAvailable(matiec)

# Use the same variables as CPM method
```

---

## Method 3: find_package (Installed Library)

If matiec is installed on your system:

```cmake
cmake_minimum_required(VERSION 3.16)
project(my_app)

find_package(matiec REQUIRED)

add_executable(my_app main.c)
target_link_libraries(my_app PRIVATE matiec::matiec)

# Access IEC standard library
message(STATUS "IEC lib path: ${MATIEC_LIB_DIR}")
```

### Installing matiec

```bash
cmake -B build -DCMAKE_INSTALL_PREFIX=/usr/local
cmake --build build
cmake --install build
```

---

## Method 4: vcpkg

### Using Custom Port (Overlay)

The repository provides an overlay under `tools/vcpkg-port/`. Use or customize the following files:
Note: the vcpkg port installs the CLI tools and IEC standard library data only (no linkable libraries).

**`tools/vcpkg-port/portfile.cmake`**:
```cmake
vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO lusipad/matiec-cmake
    REF master
    SHA512 0  # Update with actual SHA512
)

vcpkg_cmake_configure(
    SOURCE_PATH "${SOURCE_PATH}"
)

vcpkg_cmake_build()
vcpkg_cmake_install()

vcpkg_copy_tools(TOOL_NAMES iec2c iec2iec AUTO_CLEAN)

file(INSTALL "${SOURCE_PATH}/src/lib/"
    DESTINATION "${CURRENT_PACKAGES_DIR}/share/${PORT}/iec-lib"
    FILES_MATCHING PATTERN "*.txt" PATTERN "*.h")

vcpkg_install_copyright(FILE_LIST
    "${SOURCE_PATH}/COPYING"
    "${SOURCE_PATH}/src/lib/COPYING.LESSER"
)
```

**`tools/vcpkg-port/vcpkg.json`**:
```json
{
    "name": "matiec",
    "version": "0.3.0",
    "description": "IEC 61131-3 compiler - converts IEC code to C",
    "homepage": "https://github.com/lusipad/matiec-cmake",
    "license": "GPL-3.0-only AND LGPL-3.0-or-later",
    "dependencies": [
        { "name": "vcpkg-cmake", "host": true },
        { "name": "vcpkg-cmake-config", "host": true }
    ]
}
```

Install with:
```bash
vcpkg install matiec --overlay-ports=./tools/vcpkg-port
```

### Official vcpkg PR automation (release tags)

This repository includes a release workflow that updates the port in the fork
`lusipad/vcpkg` and opens a PR to `microsoft/vcpkg` when a tag `vX.Y.Z` is pushed.
Tags containing `-` are treated as pre-releases and are skipped.

Prerequisites:
1. Ensure the fork exists: `https://github.com/lusipad/vcpkg`
2. Create a token for automation:
   - Preferred: **Classic PAT** with scope `public_repo` (allows creating PRs to public repos)
   - Fine-grained PAT only works if you can select `microsoft/vcpkg`, which is often not possible
3. Add the token to this repo as `VCPKG_PR_TOKEN`

Release steps:
1. Create and push a tag `vX.Y.Z`
2. The workflow generates port updates, runs `vcpkg x-add-version`, tests
   `vcpkg install matiec --triplet x64-linux`, and opens the PR

---

## Method 5: Git Submodule

```bash
git submodule add https://github.com/lusipad/matiec-cmake.git external/matiec
```

```cmake
add_subdirectory(external/matiec)

# Variables are automatically available
message(STATUS "matiec lib: ${MATIEC_LIB_DIR}")
```

---

## Exported Variables & Targets

### Variables (when used as subdirectory)

| Variable | Description |
|----------|-------------|
| `MATIEC_LIB_DIR` | Path to IEC standard library |
| `MATIEC_INCLUDE_DIR` | Path to C API headers |
| `MATIEC_IEC2C_EXECUTABLE` | Path to iec2c executable |
| `MATIEC_IEC2IEC_EXECUTABLE` | Path to iec2iec executable |

### CMake Targets

| Target | Description |
|--------|-------------|
| `matiec::matiec` | Default library (shared if available) |
| `matiec::shared` | Shared library |
| `matiec::static` | Static library |
| `iec2c` | IEC to C compiler executable |
| `iec2iec` | IEC normalizer executable |

---

## CMake Build Options

| Option | Default | Description |
|--------|---------|-------------|
| `MATIEC_BUILD_SHARED` | ON | Build shared library |
| `MATIEC_BUILD_STATIC` | ON | Build static library |
| `MATIEC_BUILD_TOOLS` | ON | Build iec2c and iec2iec |
| `MATIEC_INSTALL` | ON | Generate install targets |

Example:
```bash
cmake -B build \
    -DMATIEC_BUILD_SHARED=OFF \
    -DMATIEC_BUILD_STATIC=ON \
    -DMATIEC_BUILD_TOOLS=ON
```

---

## Complete Example: PLC Runtime with Library API

```cmake
cmake_minimum_required(VERSION 3.16)
project(plc_controller)

include(cmake/CPM.cmake)

CPMAddPackage(
    NAME matiec
    GITHUB_REPOSITORY lusipad/matiec-cmake
    GIT_TAG v0.3.0
)

# Your PLC compiler frontend using the library API
add_executable(plc_compiler
    src/compiler_main.c
)
target_link_libraries(plc_compiler PRIVATE matiec::matiec)
target_compile_definitions(plc_compiler PRIVATE
    MATIEC_LIB_DIR="${MATIEC_LIB_DIR}"
)

# Or use command-line tools for build-time compilation
set(IEC_SOURCES
    ${CMAKE_SOURCE_DIR}/plc/main.st
    ${CMAKE_SOURCE_DIR}/plc/motors.st
)

set(GENERATED_DIR ${CMAKE_BINARY_DIR}/generated)
file(MAKE_DIRECTORY ${GENERATED_DIR})

foreach(IEC_FILE ${IEC_SOURCES})
    get_filename_component(IEC_NAME ${IEC_FILE} NAME_WE)
    list(APPEND GENERATED_C_FILES ${GENERATED_DIR}/${IEC_NAME}.c)

    add_custom_command(
        OUTPUT ${GENERATED_DIR}/${IEC_NAME}.c
        COMMAND iec2c -I ${MATIEC_LIB_DIR} -T ${GENERATED_DIR} ${IEC_FILE}
        DEPENDS iec2c ${IEC_FILE}
        COMMENT "Compiling ${IEC_NAME}.st"
    )
endforeach()

add_library(plc_runtime ${GENERATED_C_FILES})
target_include_directories(plc_runtime PUBLIC
    ${MATIEC_LIB_DIR}/C
    ${GENERATED_DIR}
)

add_executable(controller src/main.c)
target_link_libraries(controller PRIVATE plc_runtime)
```
