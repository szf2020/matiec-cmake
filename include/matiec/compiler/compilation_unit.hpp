/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_COMPILER_COMPILATION_UNIT_HPP
#define MATIEC_COMPILER_COMPILATION_UNIT_HPP

#include <memory>
#include <string>
#include <utility>

#include "matiec/ast/symbol.hpp"
#include "matiec/error.hpp"

namespace matiec::compiler {

class CompilationUnit {
public:
    CompilationUnit() = default;
    ~CompilationUnit() = default;

    CompilationUnit(const CompilationUnit&) = delete;
    CompilationUnit& operator=(const CompilationUnit&) = delete;
    CompilationUnit(CompilationUnit&&) = default;
    CompilationUnit& operator=(CompilationUnit&&) = default;

    void setAstRoot(std::unique_ptr<ast::Symbol> root) {
        ast_root_ = std::move(root);
    }

    [[nodiscard]] ast::Symbol* astRoot() const noexcept {
        return ast_root_.get();
    }

    [[nodiscard]] std::unique_ptr<ast::Symbol> releaseAst() {
        return std::move(ast_root_);
    }

    [[nodiscard]] ErrorReporter& errors() noexcept { return errors_; }
    [[nodiscard]] const ErrorReporter& errors() const noexcept { return errors_; }

    void setSourceFile(std::string path) { source_file_ = std::move(path); }
    [[nodiscard]] const std::string& sourceFile() const noexcept { return source_file_; }

    [[nodiscard]] bool isValid() const noexcept {
        return ast_root_ != nullptr && !errors_.hasErrors();
    }

private:
    std::unique_ptr<ast::Symbol> ast_root_;
    ErrorReporter errors_;
    std::string source_file_;
};

} // namespace matiec::compiler

#endif // MATIEC_COMPILER_COMPILATION_UNIT_HPP
