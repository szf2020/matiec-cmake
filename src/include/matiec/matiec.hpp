/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_HPP
#define MATIEC_HPP

#include "matiec/matiec.h"

#include <filesystem>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace matiec {

enum class OutputFormat {
    C,
    IEC,
};

struct CompilerOptions {
    std::filesystem::path includeDir;
    std::filesystem::path outputDir;
    OutputFormat outputFormat = OutputFormat::C;

    bool allowForwardRefs = false;
    bool relaxedDatatypeModel = false;
    bool safeExtensions = false;
    bool nestedComments = false;
    bool refExtensions = false;
    bool refNonstandard = false;
    bool nonliteralArraySize = false;
    bool allowVoidFunctions = false;
    bool allowMissingVarIn = false;
    bool disableImplicitEnEno = false;
    bool conversionFunctions = false;
    bool fullTokenLocation = false;
};

struct Diagnostic {
    matiec_error_t code = MATIEC_OK;
    std::string message;
    std::string file;
    int line = 0;
    int column = 0;
};

struct CompilerResult {
    Diagnostic diagnostic;
    std::vector<std::filesystem::path> outputFiles;

    [[nodiscard]] bool ok() const noexcept { return diagnostic.code == MATIEC_OK; }
};

class Compiler {
public:
    Compiler() = default;
    explicit Compiler(CompilerOptions options) : options_(std::move(options)) {}

    [[nodiscard]] const CompilerOptions& options() const noexcept { return options_; }
    void setOptions(CompilerOptions options) { options_ = std::move(options); }

    [[nodiscard]] CompilerResult compileFile(const std::filesystem::path& inputFile) const {
        std::string includeDirBuffer;
        std::string outputDirBuffer;
        matiec_options_t cOptions = makeCOptions(options_, includeDirBuffer, outputDirBuffer);

        matiec_result_t cResult{};
        const std::string input = inputFile.string();
        (void)matiec_compile_file_v1(input.c_str(), &cOptions, &cResult);

        CompilerResult result = fromCResult(cResult);
        matiec_result_free_v1(&cResult);
        return result;
    }

    [[nodiscard]] CompilerResult compileString(
        std::string_view source,
        std::string_view sourceName = "<string>") const {
        std::string includeDirBuffer;
        std::string outputDirBuffer;
        matiec_options_t cOptions = makeCOptions(options_, includeDirBuffer, outputDirBuffer);

        std::string sourceBuffer(source);
        std::string sourceNameBuffer(sourceName);

        matiec_result_t cResult{};
        (void)matiec_compile_string_v1(
            sourceBuffer.c_str(),
            sourceBuffer.size(),
            sourceNameBuffer.c_str(),
            &cOptions,
            &cResult);

        CompilerResult result = fromCResult(cResult);
        matiec_result_free_v1(&cResult);
        return result;
    }

private:
    static matiec_options_t makeCOptions(
        const CompilerOptions& options,
        std::string& includeDirBuffer,
        std::string& outputDirBuffer) {
        matiec_options_t cOptions;
        matiec_options_init(&cOptions);

        if (!options.includeDir.empty()) {
            includeDirBuffer = options.includeDir.string();
            cOptions.include_dir = includeDirBuffer.c_str();
        }

        if (!options.outputDir.empty()) {
            outputDirBuffer = options.outputDir.string();
            cOptions.output_dir = outputDirBuffer.c_str();
        }

        cOptions.output_format =
            (options.outputFormat == OutputFormat::IEC) ? MATIEC_OUTPUT_IEC : MATIEC_OUTPUT_C;

        cOptions.allow_forward_refs = options.allowForwardRefs;
        cOptions.relaxed_datatype_model = options.relaxedDatatypeModel;
        cOptions.safe_extensions = options.safeExtensions;
        cOptions.nested_comments = options.nestedComments;
        cOptions.ref_extensions = options.refExtensions;
        cOptions.ref_nonstandard = options.refNonstandard;
        cOptions.nonliteral_array_size = options.nonliteralArraySize;
        cOptions.allow_void_functions = options.allowVoidFunctions;
        cOptions.allow_missing_var_in = options.allowMissingVarIn;
        cOptions.disable_implicit_en_eno = options.disableImplicitEnEno;
        cOptions.conversion_functions = options.conversionFunctions;
        cOptions.full_token_location = options.fullTokenLocation;
        return cOptions;
    }

    static CompilerResult fromCResult(const matiec_result_t& cResult) {
        CompilerResult out;
        out.diagnostic.code = cResult.error_code;
        if (cResult.error_message != nullptr) {
            out.diagnostic.message = cResult.error_message;
        }
        if (cResult.error_file != nullptr) {
            out.diagnostic.file = cResult.error_file;
        }
        out.diagnostic.line = cResult.error_line;
        out.diagnostic.column = cResult.error_column;

        for (int i = 0; i < cResult.output_file_count; ++i) {
            if (cResult.output_files != nullptr && cResult.output_files[i] != nullptr) {
                out.outputFiles.emplace_back(cResult.output_files[i]);
            }
        }
        return out;
    }

    CompilerOptions options_{};
};

} // namespace matiec

#endif // MATIEC_HPP
