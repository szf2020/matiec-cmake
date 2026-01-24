/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 *
 *  Unit tests for VisitorResult helpers.
 */

#include <gtest/gtest.h>

#include "matiec/ast/symbol.hpp"
#include "matiec/ast/visitor_result.hpp"

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

TEST(VisitorResultTest, GetResultReturnsStoredString) {
    matiec::ast::VisitorResult result = std::string("hello");

    const auto value = matiec::ast::get_result<std::string>(result);
    ASSERT_TRUE(value.has_value());
    EXPECT_EQ(*value, "hello");
}

TEST(VisitorResultTest, HoldsResultMatchesActiveType) {
    matiec::ast::VisitorResult result = true;

    EXPECT_TRUE(matiec::ast::holds_result<bool>(result));
    EXPECT_FALSE(matiec::ast::holds_result<int64_t>(result));
}

TEST(VisitorResultTest, IsEmptyDetectsMonostate) {
    matiec::ast::VisitorResult result = std::monostate{};

    EXPECT_TRUE(matiec::ast::is_empty(result));
}

TEST(VisitorResultTest, IsEmptyDetectsNullSymbolPointer) {
    matiec::ast::Symbol* ptr = nullptr;
    matiec::ast::VisitorResult result = ptr;

    EXPECT_TRUE(matiec::ast::is_empty(result));
}

TEST(VisitorResultTest, IsEmptyIsFalseForNonNullSymbol) {
    DummySymbol symbol;
    matiec::ast::VisitorResult result = &symbol;

    EXPECT_FALSE(matiec::ast::is_empty(result));
}
