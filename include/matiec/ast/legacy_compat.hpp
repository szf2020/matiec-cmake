/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_AST_LEGACY_COMPAT_HPP
#define MATIEC_AST_LEGACY_COMPAT_HPP

#include <variant>

#include "matiec/ast/visitor.hpp"
#include "matiec/ast/visitor_result.hpp"

namespace matiec::ast::legacy {

using symbol_c = Symbol;
using token_c = Token;
using list_c = List;

class visitor_c {
public:
    virtual ~visitor_c() = default;
    virtual void* visit(symbol_c* symbol) = 0;

    #include "matiec/ast/generated/legacy_visitor_methods.gen.hpp"
};

[[nodiscard]] inline VisitorResult from_legacy(void* ptr) {
    return static_cast<symbol_c*>(ptr);
}

[[nodiscard]] inline void* to_legacy_ptr(const VisitorResult& result) {
    if (const auto* ptr = std::get_if<symbol_c*>(&result)) {
        return static_cast<void*>(*ptr);
    }
    if (const auto* ptr = std::get_if<std::unique_ptr<symbol_c>>(&result)) {
        return static_cast<void*>(ptr->get());
    }
    return nullptr;
}

class adapter final : public Visitor {
public:
    explicit adapter(visitor_c& legacy) : legacy_(legacy) {}

    [[nodiscard]] VisitorResult visit(Symbol& symbol) override {
        return from_legacy(legacy_.visit(&symbol));
    }

    #include "matiec/ast/generated/legacy_adapter_methods.gen.hpp"

private:
    visitor_c& legacy_;
};

class modern_adapter final : public visitor_c {
public:
    explicit modern_adapter(Visitor& visitor) : visitor_(visitor) {}

    void* visit(symbol_c* symbol) override {
        if (!symbol) {
            return nullptr;
        }
        return to_legacy_ptr(symbol->accept(visitor_));
    }

private:
    Visitor& visitor_;
};

} // namespace matiec::ast::legacy

#endif // MATIEC_AST_LEGACY_COMPAT_HPP
