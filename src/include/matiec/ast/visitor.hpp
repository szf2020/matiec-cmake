/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_AST_VISITOR_HPP
#define MATIEC_AST_VISITOR_HPP

#include "matiec/ast/generated/ast_nodes_fwd.gen.hpp"
#include "matiec/ast/symbol.hpp"
#include "matiec/ast/visitor_result.hpp"

namespace matiec::ast {

class Visitor {
public:
    Visitor() = default;
    virtual ~Visitor() = default;

    Visitor(const Visitor&) = delete;
    Visitor& operator=(const Visitor&) = delete;
    Visitor(Visitor&&) = default;
    Visitor& operator=(Visitor&&) = default;

    [[nodiscard]] virtual VisitorResult visit(Symbol& /*symbol*/) { return {}; }
    [[nodiscard]] virtual VisitorResult visit(Token& /*symbol*/) { return {}; }
    [[nodiscard]] virtual VisitorResult visit(List& /*symbol*/) { return {}; }

    #include "matiec/ast/generated/visitor_methods_decl.gen.hpp"
};

inline VisitorResult Token::accept(Visitor& visitor) {
    return visitor.visit(*this);
}

inline VisitorResult List::accept(Visitor& visitor) {
    return visitor.visit(*this);
}

} // namespace matiec::ast

#endif // MATIEC_AST_VISITOR_HPP
