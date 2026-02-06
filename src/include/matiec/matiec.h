/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Copyright (C) 2003-2011  Mario de Sousa (msousa@fe.up.pt)
 *  Copyright (C) 2007-2011  Laurent Bessard and Edouard Tisserant
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file matiec.h
 * @brief Public C API for the matiec IEC 61131-3 compiler library
 *
 * This header provides a C-compatible API for integrating the matiec
 * compiler into external applications.
 *
 * Example usage:
 * @code
 * #include <matiec/matiec.h>
 *
 * int main() {
 *     matiec_options_t opts;
 *     matiec_options_init(&opts);
 *     opts.include_dir = "/path/to/lib";
 *     opts.output_dir = "/path/to/output";
 *
 *     matiec_result_t result;
 *     int ret = matiec_compile_file("program.st", &opts, &result);
 *
 *     if (ret == MATIEC_OK) {
 *         printf("Compiled successfully!\n");
 *         for (int i = 0; i < result.output_file_count; i++) {
 *             printf("  Generated: %s\n", result.output_files[i]);
 *         }
 *     } else {
 *         printf("Error: %s\n", result.error_message);
 *     }
 *
 *     matiec_result_free(&result);
 *     return ret;
 * }
 * @endcode
 */

#ifndef MATIEC_H
#define MATIEC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdbool.h>

/* Library version */
#define MATIEC_VERSION_MAJOR 0
#define MATIEC_VERSION_MINOR 3
#define MATIEC_VERSION_PATCH 0
#define MATIEC_VERSION_STRING "0.3.0"

/* Stable C API contract level */
#define MATIEC_C_API_LEVEL 1
#define MATIEC_HAS_V1_API 1

/* Export/import macros for shared library */
#if defined(_WIN32) || defined(__CYGWIN__)
    #ifdef MATIEC_BUILDING_DLL
        #define MATIEC_API __declspec(dllexport)
    #elif defined(MATIEC_USING_DLL)
        #define MATIEC_API __declspec(dllimport)
    #else
        #define MATIEC_API
    #endif
#else
    #if defined(__GNUC__) && __GNUC__ >= 4
        #define MATIEC_API __attribute__((visibility("default")))
    #else
        #define MATIEC_API
    #endif
#endif

/**
 * @brief Error codes returned by matiec functions
 */
typedef enum {
    MATIEC_OK = 0,              /**< Success */
    MATIEC_ERROR_INVALID_ARG,   /**< Invalid argument */
    MATIEC_ERROR_FILE_NOT_FOUND,/**< Input file not found */
    MATIEC_ERROR_PARSE,         /**< Parsing error (lexical/syntax) */
    MATIEC_ERROR_SEMANTIC,      /**< Semantic error (type checking) */
    MATIEC_ERROR_CODEGEN,       /**< Code generation error */
    MATIEC_ERROR_IO,            /**< I/O error (cannot write output) */
    MATIEC_ERROR_INTERNAL       /**< Internal compiler error */
} matiec_error_t;

/**
 * @brief Output format for code generation
 */
typedef enum {
    MATIEC_OUTPUT_C,            /**< Generate ANSI C code (default) */
    MATIEC_OUTPUT_IEC           /**< Generate normalized IEC 61131-3 code */
} matiec_output_format_t;

/**
 * @brief Compiler options
 */
typedef struct {
    /* Input/Output paths */
    const char *include_dir;           /**< Directory for included files (-I) */
    const char *output_dir;            /**< Output directory (-T) */

    /* Output format */
    matiec_output_format_t output_format; /**< Output format (C or IEC) */

    /* Language extensions */
    bool allow_forward_refs;           /**< Allow forward references (-p) */
    bool relaxed_datatype_model;       /**< Relaxed datatype equivalence (-l) */
    bool safe_extensions;              /**< Enable SAFE datatypes (-s) */
    bool nested_comments;              /**< Allow nested comments (-n) */
    bool ref_extensions;               /**< Enable REF_TO, REF, ^, NULL (-r) */
    bool ref_nonstandard;              /**< Enable REF_TO ANY and REF in structs (-R) */
    bool nonliteral_array_size;        /**< Allow non-literals in array size (-a) */
    bool allow_void_functions;         /**< Allow functions returning VOID (-b) */
    bool allow_missing_var_in;         /**< Allow POUs with no parameters (-i) */
    bool disable_implicit_en_eno;      /**< Disable EN/ENO generation (-e) */
    bool conversion_functions;         /**< Generate conversion functions (-c) */

    /* Error reporting */
    bool full_token_location;          /**< Full token location in errors (-f) */

    /* Reserved for future use */
    void *reserved[8];
} matiec_options_t;

/**
 * @brief Compilation result
 */
typedef struct {
    matiec_error_t error_code;         /**< Error code (MATIEC_OK if successful) */
    char *error_message;               /**< Error message (NULL if successful) */
    int error_line;                    /**< Line number of error (0 if N/A) */
    int error_column;                  /**< Column number of error (0 if N/A) */
    const char *error_file;            /**< File where error occurred */

    char **output_files;               /**< Array of generated output file paths */
    int output_file_count;             /**< Number of output files */

    /* Reserved for future use */
    void *reserved[4];
} matiec_result_t;

/**
 * @brief Error callback function type
 *
 * @param file      Source file where error occurred
 * @param line      Line number
 * @param column    Column number
 * @param message   Error message
 * @param user_data User-provided context
 */
typedef void (*matiec_error_callback_t)(
    const char *file,
    int line,
    int column,
    const char *message,
    void *user_data
);

/* ============================================================================
 * Core API Functions
 * ============================================================================ */

/**
 * @brief Initialize compiler options to default values
 *
 * @param opts      Pointer to options structure
 */
MATIEC_API void matiec_options_init(matiec_options_t *opts);

/**
 * @brief Compile an IEC 61131-3 source file
 *
 * @param input_file    Path to input file (.st, .il, etc.)
 * @param opts          Compiler options (NULL for defaults)
 * @param result        Output result structure
 * @return              MATIEC_OK on success, error code otherwise
 */
MATIEC_API matiec_error_t matiec_compile_file(
    const char *input_file,
    const matiec_options_t *opts,
    matiec_result_t *result
);

/**
 * @brief Compile IEC 61131-3 source code from a string
 *
 * @param source        Source code string
 * @param source_len    Length of source string (0 for null-terminated)
 * @param source_name   Virtual filename for error messages
 * @param opts          Compiler options (NULL for defaults)
 * @param result        Output result structure
 * @return              MATIEC_OK on success, error code otherwise
 */
MATIEC_API matiec_error_t matiec_compile_string(
    const char *source,
    size_t source_len,
    const char *source_name,
    const matiec_options_t *opts,
    matiec_result_t *result
);

/**
 * @brief v1 compile entrypoint (stable alias of matiec_compile_file)
 */
MATIEC_API matiec_error_t matiec_compile_file_v1(
    const char *input_file,
    const matiec_options_t *opts,
    matiec_result_t *result
);

/**
 * @brief v1 compile-string entrypoint (stable alias of matiec_compile_string)
 */
MATIEC_API matiec_error_t matiec_compile_string_v1(
    const char *source,
    size_t source_len,
    const char *source_name,
    const matiec_options_t *opts,
    matiec_result_t *result
);

/**
 * @brief Free resources allocated in a result structure
 *
 * @param result    Result structure to free
 */
MATIEC_API void matiec_result_free(matiec_result_t *result);

/**
 * @brief v1 result cleanup entrypoint (stable alias of matiec_result_free)
 */
MATIEC_API void matiec_result_free_v1(matiec_result_t *result);

/**
 * @brief Set error callback for detailed error reporting
 *
 * @param callback  Callback function (NULL to disable)
 * @param user_data User-provided context passed to callback
 */
MATIEC_API void matiec_set_error_callback(
    matiec_error_callback_t callback,
    void *user_data
);

/* ============================================================================
 * Utility Functions
 * ============================================================================ */

/**
 * @brief Get library version string
 *
 * @return Version string (e.g., "0.3.0")
 */
MATIEC_API const char* matiec_version(void);

/**
 * @brief Get human-readable error description
 *
 * @param error     Error code
 * @return          Error description string
 */
MATIEC_API const char* matiec_error_string(matiec_error_t error);

/**
 * @brief Check if a file extension is supported
 *
 * @param extension File extension (e.g., ".st", ".il")
 * @return          true if supported, false otherwise
 */
MATIEC_API bool matiec_is_supported_extension(const char *extension);

#ifdef __cplusplus
}
#endif

#endif /* MATIEC_H */
