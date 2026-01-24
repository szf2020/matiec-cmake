/*
 *  matiec - a compiler for the programming languages defined in IEC 61131-3
 */

#ifndef MATIEC_AST_SYMBOL_HPP
#define MATIEC_AST_SYMBOL_HPP

#include <cstddef>
#include <memory>
#include <string>
#include <string_view>
#include <utility>
#include <vector>

#include "matiec/ast/visitor_result.hpp"
#include "matiec/error.hpp"

namespace matiec::ast {

class Visitor;

struct SourceRange {
    SourceLocation start;
    SourceLocation end;

    [[nodiscard]] bool isValid() const noexcept {
        return start.isValid();
    }
};

class Symbol {
public:
    Symbol() = default;
    explicit Symbol(SourceRange range) : range_(std::move(range)) {}
    virtual ~Symbol() = default;

    Symbol(const Symbol&) = delete;
    Symbol& operator=(const Symbol&) = delete;
    Symbol(Symbol&&) = default;
    Symbol& operator=(Symbol&&) = default;

    [[nodiscard]] virtual VisitorResult accept(Visitor& visitor) = 0;
    [[nodiscard]] virtual std::string_view typeName() const noexcept = 0;

    [[nodiscard]] const SourceRange& range() const noexcept { return range_; }
    void setRange(SourceRange range) noexcept { range_ = std::move(range); }

    [[nodiscard]] Symbol* parent() const noexcept { return parent_; }
    void setParent(Symbol* parent) noexcept { parent_ = parent; }

private:
    SourceRange range_{};
    Symbol* parent_ = nullptr;
};

class Token : public Symbol {
public:
    Token() = default;
    explicit Token(std::string value, SourceRange range = {})
        : Symbol(std::move(range)), value_(std::move(value)) {}

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override { return "Token"; }

    [[nodiscard]] std::string_view value() const noexcept { return value_; }
    void setValue(std::string value) { value_ = std::move(value); }

private:
    std::string value_;
};

class List : public Symbol {
public:
    using iterator = std::vector<std::unique_ptr<Symbol>>::iterator;
    using const_iterator = std::vector<std::unique_ptr<Symbol>>::const_iterator;

    List() = default;
    explicit List(SourceRange range) : Symbol(std::move(range)) {}

    [[nodiscard]] VisitorResult accept(Visitor& visitor) override;
    [[nodiscard]] std::string_view typeName() const noexcept override { return "List"; }

    [[nodiscard]] size_t size() const noexcept { return elements_.size(); }
    [[nodiscard]] bool empty() const noexcept { return elements_.empty(); }

    [[nodiscard]] Symbol* operator[](size_t index) const { return elements_[index].get(); }
    [[nodiscard]] Symbol* at(size_t index) const { return elements_.at(index).get(); }

    void add(std::unique_ptr<Symbol> elem) {
        if (elem) {
            elem->setParent(this);
        }
        elements_.push_back(std::move(elem));
    }

    template<typename T, typename... Args>
    T* emplace(Args&&... args) {
        auto elem = std::make_unique<T>(std::forward<Args>(args)...);
        T* ptr = elem.get();
        add(std::move(elem));
        return ptr;
    }

    void insert(size_t pos, std::unique_ptr<Symbol> elem) {
        if (elem) {
            elem->setParent(this);
        }
        elements_.insert(elements_.begin() + static_cast<ptrdiff_t>(pos), std::move(elem));
    }

    std::unique_ptr<Symbol> remove(size_t pos) {
        auto elem = std::move(elements_[pos]);
        elements_.erase(elements_.begin() + static_cast<ptrdiff_t>(pos));
        if (elem) {
            elem->setParent(nullptr);
        }
        return elem;
    }

    void clear() { elements_.clear(); }

    [[nodiscard]] iterator begin() noexcept { return elements_.begin(); }
    [[nodiscard]] iterator end() noexcept { return elements_.end(); }
    [[nodiscard]] const_iterator begin() const noexcept { return elements_.begin(); }
    [[nodiscard]] const_iterator end() const noexcept { return elements_.end(); }
    [[nodiscard]] const_iterator cbegin() const noexcept { return elements_.cbegin(); }
    [[nodiscard]] const_iterator cend() const noexcept { return elements_.cend(); }

private:
    std::vector<std::unique_ptr<Symbol>> elements_;
};

} // namespace matiec::ast

#endif // MATIEC_AST_SYMBOL_HPP
