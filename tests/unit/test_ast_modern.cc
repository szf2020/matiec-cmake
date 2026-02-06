/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for the modern AST scaffolding.
 */

#include <gtest/gtest.h>

#include "matiec/ast/generated/ast_nodes.gen.hpp"
#include "matiec/ast/visitor.hpp"

namespace {

struct StringVisitor final : public matiec::ast::Visitor {
    [[nodiscard]] matiec::ast::VisitorResult visit(matiec::ast::identifier_c& /*symbol*/) override {
        return std::string("ok");
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

TEST(ModernAstTest, ListRemoveClearsParent) {
    matiec::ast::library_c list;
    auto child = std::make_unique<matiec::ast::identifier_c>("foo");
    matiec::ast::Symbol* raw = child.get();
    list.add(std::move(child));

    auto removed = list.remove(0);

    ASSERT_NE(removed, nullptr);
    EXPECT_EQ(raw->parent(), nullptr);
}

TEST(ModernAstTest, VisitorDispatchReturnsTypedResult) {
    matiec::ast::identifier_c ident("name");
    StringVisitor visitor;

    const auto result = ident.accept(visitor);
    const auto value = matiec::ast::get_result<std::string>(result);

    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "ok");
}
