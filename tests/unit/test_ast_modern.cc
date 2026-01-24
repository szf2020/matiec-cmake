/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for the modern AST scaffolding.
 */

#include <gtest/gtest.h>

#include "matiec/ast/generated/ast_nodes.gen.hpp"
#include "matiec/ast/legacy_compat.hpp"
#include "matiec/ast/visitor.hpp"

namespace {

struct StringVisitor final : public matiec::ast::Visitor {
    [[nodiscard]] matiec::ast::VisitorResult visit(matiec::ast::identifier_c& /*symbol*/) override {
        return std::string("ok");
    }
};

struct LegacyEchoVisitor final : public matiec::ast::legacy::visitor_c {
    void* visit(matiec::ast::legacy::symbol_c* symbol) override {
        return symbol;
    }
};

struct SymbolVisitor final : public matiec::ast::Visitor {
    [[nodiscard]] matiec::ast::VisitorResult visit(matiec::ast::identifier_c& symbol) override {
        return &symbol;
    }
};

} // namespace

TEST(ModernAstTest, ListSetsParentOnInsert) {
    matiec::ast::library_c list;
    auto child = std::make_unique<matiec::ast::identifier_c>("foo");
    matiec::ast::Symbol* raw = child.get();

    list.add(std::move(child));

    EXPECT_EQ(raw->parent(), &list);
}

TEST(ModernAstTest, VisitorDispatchReturnsTypedResult) {
    matiec::ast::identifier_c ident("name");
    StringVisitor visitor;

    const auto result = ident.accept(visitor);
    const auto value = matiec::ast::get_result<std::string>(result);

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "ok");
}

TEST(ModernAstTest, LegacyAdapterBridgesToModernVisitor) {
    matiec::ast::identifier_c ident("name");
    LegacyEchoVisitor legacy;
    matiec::ast::legacy::adapter adapter(legacy);

    const auto result = ident.accept(adapter);
    const auto value = matiec::ast::get_result<matiec::ast::Symbol*>(result);

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, &ident);
}

TEST(ModernAstTest, ModernAdapterBridgesToLegacyInterface) {
    matiec::ast::identifier_c ident("name");
    SymbolVisitor visitor;
    matiec::ast::legacy::modern_adapter adapter(visitor);

    void* result = adapter.visit(static_cast<matiec::ast::legacy::symbol_c*>(&ident));
    EXPECT_EQ(result, &ident);
}
