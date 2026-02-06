cmake_minimum_required(VERSION 3.16)
project(matiec VERSION 0.3.0 LANGUAGES CXX C)

# Options
option(MATIEC_BUILD_SHARED "Build shared library" ON)
option(MATIEC_BUILD_STATIC "Build static library" ON)
option(MATIEC_BUILD_TOOLS "Build command-line tools (iec2c, iec2iec)" ON)
option(MATIEC_BUILD_TESTS "Build unit and integration tests" OFF)
option(MATIEC_INSTALL "Generate install targets" ON)
option(MATIEC_ENABLE_CLANG_TIDY "Enable clang-tidy analysis on matiec targets (optional)" OFF)
option(MATIEC_ENABLE_SANITIZERS "Enable Address/Undefined sanitizers (optional)" OFF)
option(MATIEC_ENABLE_LEGACY_AST_COMPAT "Temporarily enable legacy AST compatibility adapters" OFF)

# C++ standard - C++17 for std::optional, std::string_view, etc.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Position independent code (required for shared library)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# macOS Homebrew paths for flex/bison
if(APPLE)
    # Apple Silicon
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/flex")
    list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/bison")
    # Intel Mac
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/flex")
    list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/bison")
endif()

# Windows winflexbison auto-detection
if(WIN32)
    find_program(BISON_EXECUTABLE NAMES bison win_bison HINTS
        "C:/ProgramData/chocolatey/bin"
        "$ENV{PROGRAMFILES}/win_flex_bison"
        "$ENV{PROGRAMFILES}/WinFlexBison"
    )
    find_program(FLEX_EXECUTABLE NAMES flex win_flex HINTS
        "C:/ProgramData/chocolatey/bin"
        "$ENV{PROGRAMFILES}/win_flex_bison"
        "$ENV{PROGRAMFILES}/WinFlexBison"
    )
endif()

# Find required tools
find_package(BISON 2.4 REQUIRED)
find_package(FLEX REQUIRED)

# Compiler-specific options (target-scoped)
set(MATIEC_COMMON_COMPILE_OPTIONS)
set(MATIEC_COMMON_COMPILE_DEFINITIONS)
set(MATIEC_SANITIZER_COMPILE_OPTIONS)
set(MATIEC_SANITIZER_LINK_OPTIONS)
set(MATIEC_SANITIZER_SUPPORTED OFF)
set(MATIEC_GIT_COMPILE_DEFINITION "")

if(MATIEC_ENABLE_LEGACY_AST_COMPAT)
    list(APPEND MATIEC_COMMON_COMPILE_DEFINITIONS MATIEC_ENABLE_LEGACY_AST_COMPAT=1)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Clang (including clang-cl on Windows and AppleClang on macOS)
    list(APPEND MATIEC_COMMON_COMPILE_OPTIONS
        -Wall
        -Wpointer-arith
        -Wwrite-strings
        -Wno-unused
        # Disable warnings that are errors in older code
        -Wno-overloaded-virtual
        -Wno-deprecated-register
        # Disable C++11 literal suffix warning (code uses old-style PRId64 macros)
        -Wno-reserved-user-defined-literal
    )
    if(WIN32)
        list(APPEND MATIEC_COMMON_COMPILE_DEFINITIONS _CRT_SECURE_NO_WARNINGS)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC
    list(APPEND MATIEC_COMMON_COMPILE_OPTIONS -Wall -Wpointer-arith -Wwrite-strings -Wno-unused)
elseif(MSVC)
    # MSVC (fallback support)
    list(APPEND MATIEC_COMMON_COMPILE_OPTIONS
        /W3
        # Make source/execution character set explicit on Windows to avoid
        # codepage warnings (e.g. C4819) and keep diagnostics reproducible.
        /utf-8
    )
    list(APPEND MATIEC_COMMON_COMPILE_DEFINITIONS _CRT_SECURE_NO_WARNINGS)
endif()

# Optional: sanitizers (ASan/UBSan)
# Keep default OFF to avoid toolchain coupling; enable explicitly when needed.
if(MATIEC_ENABLE_SANITIZERS)
    if(MSVC)
        message(WARNING "MATIEC_ENABLE_SANITIZERS=ON is not supported with MSVC/clang-cl; ignoring.")
    elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang|GNU")
        message(STATUS "Enabling sanitizers (address,undefined)")
        set(MATIEC_SANITIZER_SUPPORTED ON)
        list(APPEND MATIEC_SANITIZER_COMPILE_OPTIONS -fsanitize=address,undefined -fno-omit-frame-pointer)
        list(APPEND MATIEC_SANITIZER_LINK_OPTIONS -fsanitize=address,undefined)
    else()
        message(WARNING "MATIEC_ENABLE_SANITIZERS=ON but unsupported compiler '${CMAKE_CXX_COMPILER_ID}'; ignoring.")
    endif()
endif()

function(matiec_apply_project_options target_name)
    if(NOT TARGET ${target_name})
        return()
    endif()

    if(MATIEC_COMMON_COMPILE_OPTIONS)
        target_compile_options(${target_name} PRIVATE ${MATIEC_COMMON_COMPILE_OPTIONS})
    endif()

    if(MATIEC_COMMON_COMPILE_DEFINITIONS)
        target_compile_definitions(${target_name} PRIVATE ${MATIEC_COMMON_COMPILE_DEFINITIONS})
    endif()

    if(MATIEC_GIT_COMPILE_DEFINITION)
        target_compile_definitions(${target_name} PRIVATE ${MATIEC_GIT_COMPILE_DEFINITION})
    endif()

    if(MATIEC_SANITIZER_SUPPORTED)
        target_compile_options(${target_name} PRIVATE ${MATIEC_SANITIZER_COMPILE_OPTIONS})

        get_target_property(_target_type ${target_name} TYPE)
        if(_target_type STREQUAL "EXECUTABLE"
            OR _target_type STREQUAL "SHARED_LIBRARY"
            OR _target_type STREQUAL "MODULE_LIBRARY")
            target_link_options(${target_name} PRIVATE ${MATIEC_SANITIZER_LINK_OPTIONS})
        endif()
    endif()
endfunction()

# Optional: clang-tidy (static analysis)
# Keep default OFF to avoid toolchain coupling; enable explicitly when needed.
set(MATIEC_CLANG_TIDY_EXE "")
if(MATIEC_ENABLE_CLANG_TIDY)
    find_program(MATIEC_CLANG_TIDY_EXE NAMES clang-tidy clang-tidy.exe)
    if(NOT MATIEC_CLANG_TIDY_EXE)
        message(WARNING "MATIEC_ENABLE_CLANG_TIDY=ON but clang-tidy was not found; disabling.")
        set(MATIEC_ENABLE_CLANG_TIDY OFF)
    endif()
endif()

function(matiec_enable_clang_tidy target_name)
    if(MATIEC_ENABLE_CLANG_TIDY AND MATIEC_CLANG_TIDY_EXE AND TARGET ${target_name})
        set_target_properties(${target_name} PROPERTIES CXX_CLANG_TIDY "${MATIEC_CLANG_TIDY_EXE}")
    endif()
endfunction()

# Git version info (optional, replaces Mercurial)
find_package(Git QUIET)
if(GIT_FOUND)
    execute_process(
        COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GIT_VERSION
        OUTPUT_STRIP_TRAILING_WHITESPACE
        ERROR_QUIET
    )
    if(GIT_VERSION)
        set(MATIEC_GIT_COMPILE_DEFINITION HGVERSION="${GIT_VERSION}")
    endif()
endif()

# Platform feature detection
include(CheckIncludeFile)
include(CheckFunctionExists)
include(CheckTypeSize)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

check_include_file(float.h HAVE_FLOAT_H)
check_include_file(limits.h HAVE_LIMITS_H)
check_include_file(stdint.h HAVE_STDINT_H)
check_include_file(stdlib.h HAVE_STDLIB_H)
check_include_file(string.h HAVE_STRING_H)
check_include_file(strings.h HAVE_STRINGS_H)
check_include_file(sys/timeb.h HAVE_SYS_TIMEB_H)
check_include_file(unistd.h HAVE_UNISTD_H)
check_include_file(stdbool.h HAVE_STDBOOL_H)
check_include_file(inttypes.h HAVE_INTTYPES_H)

check_function_exists(clock_gettime HAVE_CLOCK_GETTIME)
check_function_exists(memset HAVE_MEMSET)
check_function_exists(pow HAVE_POW)
check_function_exists(strcasecmp HAVE_STRCASECMP)
check_function_exists(strdup HAVE_STRDUP)
check_function_exists(strtoul HAVE_STRTOUL)
check_function_exists(strtoull HAVE_STRTOULL)
check_function_exists(malloc HAVE_MALLOC)
check_function_exists(realloc HAVE_REALLOC)
check_function_exists(mktime HAVE_MKTIME)

# Type checks
check_type_size(int8_t HAVE_INT8_T)
check_type_size(int16_t HAVE_INT16_T)
check_type_size(int32_t HAVE_INT32_T)
check_type_size(int64_t HAVE_INT64_T)
check_type_size(uint8_t HAVE_UINT8_T)
check_type_size(uint16_t HAVE_UINT16_T)
check_type_size(uint32_t HAVE_UINT32_T)
check_type_size(uint64_t HAVE_UINT64_T)

# Generate config.h
configure_file(
    ${CMAKE_SOURCE_DIR}/config/config.h.in
    ${CMAKE_BINARY_DIR}/config/config.h
    @ONLY
)

# ==============================================================================
# Common infrastructure: modern error reporter (shared by tools + library)
# ==============================================================================
add_library(matiec_error STATIC
    src/error_reporter.cc
)
target_include_directories(matiec_error PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/include
    ${CMAKE_BINARY_DIR}
)

# Add subdirectories for internal libraries
add_subdirectory(src/absyntax)
add_subdirectory(src/absyntax_utils)
add_subdirectory(src/stage1_2)
add_subdirectory(src/stage3)
add_subdirectory(src/stage4)

# ==============================================================================
# Library: libmatiec
# ==============================================================================

# Collect all internal library sources for the unified library
set(MATIEC_CORE_LIBS
    stage1_2
    stage3
    stage4_c
    stage4_iec_alt
    absyntax
    absyntax_utils
)

# Library source files
# Note: runtime_options.cc provides runtime_options and error_exit
# main.cc is NOT included - it's only for command-line tools
# getopt_compat.c is NOT included - it's only for command-line tools on Windows
set(MATIEC_LIB_SOURCES
    src/matiec_lib.cc
    src/runtime_options.cc
)

# Static library
if(MATIEC_BUILD_STATIC)
    add_library(matiec_static STATIC ${MATIEC_LIB_SOURCES})
    target_include_directories(matiec_static
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/src
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(matiec_static
        PRIVATE
            ${MATIEC_CORE_LIBS}
        PUBLIC
            matiec_error
    )
    set_target_properties(matiec_static PROPERTIES
        OUTPUT_NAME matiec
        ARCHIVE_OUTPUT_NAME matiec
    )
    # On Windows, a shared library also generates an import library with a .lib
    # extension. Avoid clobbering that file by giving the static archive a
    # distinct name.
    if(WIN32)
        set_target_properties(matiec_static PROPERTIES
            OUTPUT_NAME matiec_static
            ARCHIVE_OUTPUT_NAME matiec_static
        )
    endif()

    # Alias for use in subdirectory builds
    add_library(matiec::static ALIAS matiec_static)
endif()

# Shared library
if(MATIEC_BUILD_SHARED)
    add_library(matiec_shared SHARED ${MATIEC_LIB_SOURCES})
    target_compile_definitions(matiec_shared PRIVATE MATIEC_BUILDING_DLL)
    target_include_directories(matiec_shared
        PUBLIC
            $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
        PRIVATE
            ${CMAKE_SOURCE_DIR}
            ${CMAKE_SOURCE_DIR}/src
            ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(matiec_shared PRIVATE ${MATIEC_CORE_LIBS} matiec_error)
    set_target_properties(matiec_shared PROPERTIES
        OUTPUT_NAME matiec
        VERSION ${PROJECT_VERSION}
        SOVERSION ${PROJECT_VERSION_MAJOR}
    )

    # Alias for use in subdirectory builds
    add_library(matiec::shared ALIAS matiec_shared)
endif()

# Default library alias (prefer shared if available)
if(MATIEC_BUILD_SHARED)
    add_library(matiec::matiec ALIAS matiec_shared)
elseif(MATIEC_BUILD_STATIC)
    add_library(matiec::matiec ALIAS matiec_static)
endif()

# ==============================================================================
# Command-line tools
# ==============================================================================

if(MATIEC_BUILD_TOOLS)
    # Tool sources
    set(TOOL_SOURCES src/main.cc)
    if(WIN32)
        list(APPEND TOOL_SOURCES src/util/getopt_compat.c)
    endif()

    # Executable: iec2c (IEC 61131-3 to C)
    add_executable(iec2c ${TOOL_SOURCES})
    target_include_directories(iec2c PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/include
        ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(iec2c PRIVATE
        stage1_2
        stage3
        stage4_c
        absyntax
        absyntax_utils
    )

    # Executable: iec2iec (IEC 61131-3 normalizer)
    add_executable(iec2iec ${TOOL_SOURCES})
    target_include_directories(iec2iec PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/src/include
        ${CMAKE_BINARY_DIR}
    )
    target_link_libraries(iec2iec PRIVATE
        stage1_2
        stage3
        stage4_iec
        absyntax
        absyntax_utils
    )
endif()

# Apply project-wide compile options + clang-tidy to matiec targets only
# (avoid third-party code like GoogleTest).
set(MATIEC_LOCAL_TARGETS
    matiec_error
    absyntax
    absyntax_utils
    stage1_2
    stage3
    stage4_base
    stage4_c
    stage4_iec
    stage4_iec_alt
    matiec_static
    matiec_shared
    iec2c
    iec2iec
)

foreach(_target_name IN LISTS MATIEC_LOCAL_TARGETS)
    matiec_apply_project_options(${_target_name})
    matiec_enable_clang_tidy(${_target_name})
endforeach()

# ==============================================================================
# Export targets for external usage (CPM, FetchContent, add_subdirectory)
# ==============================================================================

if(NOT CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
    # Being used as a subdirectory - export variables to parent scope
    set(MATIEC_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/lib PARENT_SCOPE)
    set(MATIEC_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include PARENT_SCOPE)

    if(MATIEC_BUILD_TOOLS)
        set(MATIEC_IEC2C_EXECUTABLE $<TARGET_FILE:iec2c> PARENT_SCOPE)
        set(MATIEC_IEC2IEC_EXECUTABLE $<TARGET_FILE:iec2iec> PARENT_SCOPE)
    endif()
endif()

# ==============================================================================
# Installation
# ==============================================================================

if(MATIEC_INSTALL)
    # Install executables
    if(MATIEC_BUILD_TOOLS)
        install(TARGETS iec2c iec2iec
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    endif()

    # Install libraries
    set(INSTALL_TARGETS)
    if(MATIEC_BUILD_STATIC)
        list(APPEND INSTALL_TARGETS matiec_static)
    endif()
    if(MATIEC_BUILD_SHARED)
        list(APPEND INSTALL_TARGETS matiec_shared)
    endif()

    if(INSTALL_TARGETS)
        install(TARGETS ${INSTALL_TARGETS}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )
    endif()

    # Install headers
    install(DIRECTORY src/include/matiec
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    )

    # Install IEC standard library
    install(DIRECTORY src/lib/
        DESTINATION ${CMAKE_INSTALL_DATADIR}/matiec/lib
        FILES_MATCHING
        PATTERN "*.txt"
        PATTERN "*.h"
    )
endif()

# ==============================================================================
# Testing
# ==============================================================================

if(MATIEC_BUILD_TESTS)
    enable_testing()

    # Fetch GoogleTest
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Include GoogleTest module for gtest_discover_tests
    include(GoogleTest)

    add_subdirectory(tests)
endif()

# ==============================================================================
# Print configuration summary
# ==============================================================================

message(STATUS "")
message(STATUS "matiec ${PROJECT_VERSION} configuration:")
message(STATUS "  C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  C++ compiler: ${CMAKE_CXX_COMPILER_ID} ${CMAKE_CXX_COMPILER_VERSION}")
message(STATUS "  Bison: ${BISON_EXECUTABLE}")
message(STATUS "  Flex: ${FLEX_EXECUTABLE}")
message(STATUS "  Build shared library: ${MATIEC_BUILD_SHARED}")
message(STATUS "  Build static library: ${MATIEC_BUILD_STATIC}")
message(STATUS "  Build tools: ${MATIEC_BUILD_TOOLS}")
message(STATUS "  Build tests: ${MATIEC_BUILD_TESTS}")
message(STATUS "  Clang-tidy: ${MATIEC_ENABLE_CLANG_TIDY}")
message(STATUS "  Legacy AST compat: ${MATIEC_ENABLE_LEGACY_AST_COMPAT}")
if(GIT_VERSION)
    message(STATUS "  Git version: ${GIT_VERSION}")
endif()
message(STATUS "")
