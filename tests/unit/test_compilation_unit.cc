/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for CompilationUnit.
 */

#include <gtest/gtest.h>

#include "matiec/ast/symbol.hpp"
#include "matiec/compiler/compilation_unit.hpp"

namespace {

class DummySymbol final : public matiec::ast::Symbol {
public:
    ~DummySymbol() override = default;
    [[nodiscard]] matiec::ast::VisitorResult accept(matiec::ast::Visitor& /*visitor*/) override {
        return {};
    }
    [[nodiscard]] std::string_view typeName() const noexcept override {
        return "DummySymbol";
    }
};

} // namespace

TEST(CompilationUnitTest, OwnershipTransfersThroughSetAndRelease) {
    matiec::compiler::CompilationUnit unit;
    auto root = std::make_unique<DummySymbol>();
    DummySymbol* raw = root.get();

    unit.setAstRoot(std::move(root));
    EXPECT_EQ(unit.astRoot(), raw);

    auto released = unit.releaseAst();
    EXPECT_EQ(released.get(), raw);
    EXPECT_EQ(unit.astRoot(), nullptr);
}

TEST(CompilationUnitTest, ValidityReflectsAstAndErrors) {
    matiec::compiler::CompilationUnit unit;
    EXPECT_FALSE(unit.isValid());

    unit.setAstRoot(std::make_unique<DummySymbol>());
    EXPECT_TRUE(unit.isValid());

    unit.errors().reportSemanticError("semantic error");
    EXPECT_FALSE(unit.isValid());
}

TEST(CompilationUnitTest, StoresSourceFilePath) {
    matiec::compiler::CompilationUnit unit;
    unit.setSourceFile("source.st");

    EXPECT_EQ(unit.sourceFile(), "source.st");
}
