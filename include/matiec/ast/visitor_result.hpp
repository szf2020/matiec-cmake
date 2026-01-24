/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_AST_VISITOR_RESULT_HPP
#define MATIEC_AST_VISITOR_RESULT_HPP

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

namespace matiec::ast {

class Symbol;

using VisitorResult = std::variant<
    std::monostate,
    bool,
    int64_t,
    double,
    std::string,
    Symbol*,
    std::unique_ptr<Symbol>,
    std::vector<Symbol*>>;

template<typename T>
[[nodiscard]] inline std::optional<T> get_result(const VisitorResult& result) {
    if (const auto* value = std::get_if<T>(&result)) {
        return *value;
    }
    return std::nullopt;
}

template<typename T>
[[nodiscard]] inline bool holds_result(const VisitorResult& result) {
    return std::holds_alternative<T>(result);
}

[[nodiscard]] inline bool is_empty(const VisitorResult& result) {
    if (std::holds_alternative<std::monostate>(result)) {
        return true;
    }
    if (const auto* ptr = std::get_if<Symbol*>(&result)) {
        return *ptr == nullptr;
    }
    return false;
}

} // namespace matiec::ast

#endif // MATIEC_AST_VISITOR_RESULT_HPP
