// Generated file. Do not edit manually.
// Source: absyntax/absyntax.def (SYM_LIST/SYM_TOKEN/SYM_REF* entries)

#pragma once

#include "matiec/ast/visitor.hpp"

namespace matiec::ast {

class invalid_type_name_c final : public Symbol {
public:
    invalid_type_name_c() = default;
    explicit invalid_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "invalid_type_name_c"; }
private:
};

class disable_code_generation_pragma_c final : public Symbol {
public:
    disable_code_generation_pragma_c() = default;
    explicit disable_code_generation_pragma_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "disable_code_generation_pragma_c"; }
private:
};

class enable_code_generation_pragma_c final : public Symbol {
public:
    enable_code_generation_pragma_c() = default;
    explicit enable_code_generation_pragma_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "enable_code_generation_pragma_c"; }
private:
};

class pragma_c final : public Token {
public:
    pragma_c() = default;
    explicit pragma_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "pragma_c"; }
};

class library_c final : public List {
public:
    library_c() = default;
    explicit library_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "library_c"; }
};

class identifier_c final : public Token {
public:
    identifier_c() = default;
    explicit identifier_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "identifier_c"; }
};

class derived_datatype_identifier_c final : public Token {
public:
    derived_datatype_identifier_c() = default;
    explicit derived_datatype_identifier_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "derived_datatype_identifier_c"; }
};

class poutype_identifier_c final : public Token {
public:
    poutype_identifier_c() = default;
    explicit poutype_identifier_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "poutype_identifier_c"; }
};

class ref_value_null_literal_c final : public Symbol {
public:
    ref_value_null_literal_c() = default;
    explicit ref_value_null_literal_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ref_value_null_literal_c"; }
private:
};

class real_c final : public Token {
public:
    real_c() = default;
    explicit real_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "real_c"; }
};

class integer_c final : public Token {
public:
    integer_c() = default;
    explicit integer_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "integer_c"; }
};

class binary_integer_c final : public Token {
public:
    binary_integer_c() = default;
    explicit binary_integer_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "binary_integer_c"; }
};

class octal_integer_c final : public Token {
public:
    octal_integer_c() = default;
    explicit octal_integer_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "octal_integer_c"; }
};

class hex_integer_c final : public Token {
public:
    hex_integer_c() = default;
    explicit hex_integer_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "hex_integer_c"; }
};

class neg_real_c final : public Symbol {
public:
    neg_real_c() = default;
    neg_real_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "neg_real_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class neg_integer_c final : public Symbol {
public:
    neg_integer_c() = default;
    neg_integer_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "neg_integer_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class integer_literal_c final : public Symbol {
public:
    integer_literal_c() = default;
    integer_literal_c(std::unique_ptr<Symbol> type,
        std::unique_ptr<Symbol> value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_(std::move(type)), value_(std::move(value)) {
        if (type_) {
            type_->setParent(this);
        }
        if (value_) {
            value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "integer_literal_c"; }
    [[nodiscard]] Symbol* type() const noexcept { return type_.get(); }
    void set_type(std::unique_ptr<Symbol> value) {
        type_ = std::move(value);
        if (type_) {
            type_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* value() const noexcept { return value_.get(); }
    void set_value(std::unique_ptr<Symbol> value) {
        value_ = std::move(value);
        if (value_) {
            value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_;
    std::unique_ptr<Symbol> value_;
};

class real_literal_c final : public Symbol {
public:
    real_literal_c() = default;
    real_literal_c(std::unique_ptr<Symbol> type,
        std::unique_ptr<Symbol> value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_(std::move(type)), value_(std::move(value)) {
        if (type_) {
            type_->setParent(this);
        }
        if (value_) {
            value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "real_literal_c"; }
    [[nodiscard]] Symbol* type() const noexcept { return type_.get(); }
    void set_type(std::unique_ptr<Symbol> value) {
        type_ = std::move(value);
        if (type_) {
            type_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* value() const noexcept { return value_.get(); }
    void set_value(std::unique_ptr<Symbol> value) {
        value_ = std::move(value);
        if (value_) {
            value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_;
    std::unique_ptr<Symbol> value_;
};

class bit_string_literal_c final : public Symbol {
public:
    bit_string_literal_c() = default;
    bit_string_literal_c(std::unique_ptr<Symbol> type,
        std::unique_ptr<Symbol> value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_(std::move(type)), value_(std::move(value)) {
        if (type_) {
            type_->setParent(this);
        }
        if (value_) {
            value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "bit_string_literal_c"; }
    [[nodiscard]] Symbol* type() const noexcept { return type_.get(); }
    void set_type(std::unique_ptr<Symbol> value) {
        type_ = std::move(value);
        if (type_) {
            type_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* value() const noexcept { return value_.get(); }
    void set_value(std::unique_ptr<Symbol> value) {
        value_ = std::move(value);
        if (value_) {
            value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_;
    std::unique_ptr<Symbol> value_;
};

class boolean_literal_c final : public Symbol {
public:
    boolean_literal_c() = default;
    boolean_literal_c(std::unique_ptr<Symbol> type,
        std::unique_ptr<Symbol> value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_(std::move(type)), value_(std::move(value)) {
        if (type_) {
            type_->setParent(this);
        }
        if (value_) {
            value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "boolean_literal_c"; }
    [[nodiscard]] Symbol* type() const noexcept { return type_.get(); }
    void set_type(std::unique_ptr<Symbol> value) {
        type_ = std::move(value);
        if (type_) {
            type_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* value() const noexcept { return value_.get(); }
    void set_value(std::unique_ptr<Symbol> value) {
        value_ = std::move(value);
        if (value_) {
            value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_;
    std::unique_ptr<Symbol> value_;
};

class boolean_true_c final : public Symbol {
public:
    boolean_true_c() = default;
    explicit boolean_true_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "boolean_true_c"; }
private:
};

class boolean_false_c final : public Symbol {
public:
    boolean_false_c() = default;
    explicit boolean_false_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "boolean_false_c"; }
private:
};

class double_byte_character_string_c final : public Token {
public:
    double_byte_character_string_c() = default;
    explicit double_byte_character_string_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "double_byte_character_string_c"; }
};

class single_byte_character_string_c final : public Token {
public:
    single_byte_character_string_c() = default;
    explicit single_byte_character_string_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "single_byte_character_string_c"; }
};

class neg_time_c final : public Symbol {
public:
    neg_time_c() = default;
    explicit neg_time_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "neg_time_c"; }
private:
};

class duration_c final : public Symbol {
public:
    duration_c() = default;
    duration_c(std::unique_ptr<Symbol> type_name,
        std::unique_ptr<Symbol> neg,
        std::unique_ptr<Symbol> interval,
        SourceRange range = {})
        : Symbol(std::move(range)), type_name_(std::move(type_name)), neg_(std::move(neg)), interval_(std::move(interval)) {
        if (type_name_) {
            type_name_->setParent(this);
        }
        if (neg_) {
            neg_->setParent(this);
        }
        if (interval_) {
            interval_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "duration_c"; }
    [[nodiscard]] Symbol* type_name() const noexcept { return type_name_.get(); }
    void set_type_name(std::unique_ptr<Symbol> value) {
        type_name_ = std::move(value);
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* neg() const noexcept { return neg_.get(); }
    void set_neg(std::unique_ptr<Symbol> value) {
        neg_ = std::move(value);
        if (neg_) {
            neg_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* interval() const noexcept { return interval_.get(); }
    void set_interval(std::unique_ptr<Symbol> value) {
        interval_ = std::move(value);
        if (interval_) {
            interval_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_name_;
    std::unique_ptr<Symbol> neg_;
    std::unique_ptr<Symbol> interval_;
};

class interval_c final : public Symbol {
public:
    interval_c() = default;
    interval_c(std::unique_ptr<Symbol> days,
        std::unique_ptr<Symbol> hours,
        std::unique_ptr<Symbol> minutes,
        std::unique_ptr<Symbol> seconds,
        std::unique_ptr<Symbol> milliseconds,
        SourceRange range = {})
        : Symbol(std::move(range)), days_(std::move(days)), hours_(std::move(hours)), minutes_(std::move(minutes)), seconds_(std::move(seconds)), milliseconds_(std::move(milliseconds)) {
        if (days_) {
            days_->setParent(this);
        }
        if (hours_) {
            hours_->setParent(this);
        }
        if (minutes_) {
            minutes_->setParent(this);
        }
        if (seconds_) {
            seconds_->setParent(this);
        }
        if (milliseconds_) {
            milliseconds_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "interval_c"; }
    [[nodiscard]] Symbol* days() const noexcept { return days_.get(); }
    void set_days(std::unique_ptr<Symbol> value) {
        days_ = std::move(value);
        if (days_) {
            days_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* hours() const noexcept { return hours_.get(); }
    void set_hours(std::unique_ptr<Symbol> value) {
        hours_ = std::move(value);
        if (hours_) {
            hours_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* minutes() const noexcept { return minutes_.get(); }
    void set_minutes(std::unique_ptr<Symbol> value) {
        minutes_ = std::move(value);
        if (minutes_) {
            minutes_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* seconds() const noexcept { return seconds_.get(); }
    void set_seconds(std::unique_ptr<Symbol> value) {
        seconds_ = std::move(value);
        if (seconds_) {
            seconds_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* milliseconds() const noexcept { return milliseconds_.get(); }
    void set_milliseconds(std::unique_ptr<Symbol> value) {
        milliseconds_ = std::move(value);
        if (milliseconds_) {
            milliseconds_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> days_;
    std::unique_ptr<Symbol> hours_;
    std::unique_ptr<Symbol> minutes_;
    std::unique_ptr<Symbol> seconds_;
    std::unique_ptr<Symbol> milliseconds_;
};

class fixed_point_c final : public Token {
public:
    fixed_point_c() = default;
    explicit fixed_point_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fixed_point_c"; }
};

class time_of_day_c final : public Symbol {
public:
    time_of_day_c() = default;
    time_of_day_c(std::unique_ptr<Symbol> type_name,
        std::unique_ptr<Symbol> daytime = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_name_(std::move(type_name)), daytime_(std::move(daytime)) {
        if (type_name_) {
            type_name_->setParent(this);
        }
        if (daytime_) {
            daytime_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "time_of_day_c"; }
    [[nodiscard]] Symbol* type_name() const noexcept { return type_name_.get(); }
    void set_type_name(std::unique_ptr<Symbol> value) {
        type_name_ = std::move(value);
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* daytime() const noexcept { return daytime_.get(); }
    void set_daytime(std::unique_ptr<Symbol> value) {
        daytime_ = std::move(value);
        if (daytime_) {
            daytime_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_name_;
    std::unique_ptr<Symbol> daytime_;
};

class daytime_c final : public Symbol {
public:
    daytime_c() = default;
    daytime_c(std::unique_ptr<Symbol> day_hour,
        std::unique_ptr<Symbol> day_minute,
        std::unique_ptr<Symbol> day_second,
        SourceRange range = {})
        : Symbol(std::move(range)), day_hour_(std::move(day_hour)), day_minute_(std::move(day_minute)), day_second_(std::move(day_second)) {
        if (day_hour_) {
            day_hour_->setParent(this);
        }
        if (day_minute_) {
            day_minute_->setParent(this);
        }
        if (day_second_) {
            day_second_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "daytime_c"; }
    [[nodiscard]] Symbol* day_hour() const noexcept { return day_hour_.get(); }
    void set_day_hour(std::unique_ptr<Symbol> value) {
        day_hour_ = std::move(value);
        if (day_hour_) {
            day_hour_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* day_minute() const noexcept { return day_minute_.get(); }
    void set_day_minute(std::unique_ptr<Symbol> value) {
        day_minute_ = std::move(value);
        if (day_minute_) {
            day_minute_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* day_second() const noexcept { return day_second_.get(); }
    void set_day_second(std::unique_ptr<Symbol> value) {
        day_second_ = std::move(value);
        if (day_second_) {
            day_second_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> day_hour_;
    std::unique_ptr<Symbol> day_minute_;
    std::unique_ptr<Symbol> day_second_;
};

class date_c final : public Symbol {
public:
    date_c() = default;
    date_c(std::unique_ptr<Symbol> type_name,
        std::unique_ptr<Symbol> date_literal = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_name_(std::move(type_name)), date_literal_(std::move(date_literal)) {
        if (type_name_) {
            type_name_->setParent(this);
        }
        if (date_literal_) {
            date_literal_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "date_c"; }
    [[nodiscard]] Symbol* type_name() const noexcept { return type_name_.get(); }
    void set_type_name(std::unique_ptr<Symbol> value) {
        type_name_ = std::move(value);
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* date_literal() const noexcept { return date_literal_.get(); }
    void set_date_literal(std::unique_ptr<Symbol> value) {
        date_literal_ = std::move(value);
        if (date_literal_) {
            date_literal_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_name_;
    std::unique_ptr<Symbol> date_literal_;
};

class date_literal_c final : public Symbol {
public:
    date_literal_c() = default;
    date_literal_c(std::unique_ptr<Symbol> year,
        std::unique_ptr<Symbol> month,
        std::unique_ptr<Symbol> day,
        SourceRange range = {})
        : Symbol(std::move(range)), year_(std::move(year)), month_(std::move(month)), day_(std::move(day)) {
        if (year_) {
            year_->setParent(this);
        }
        if (month_) {
            month_->setParent(this);
        }
        if (day_) {
            day_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "date_literal_c"; }
    [[nodiscard]] Symbol* year() const noexcept { return year_.get(); }
    void set_year(std::unique_ptr<Symbol> value) {
        year_ = std::move(value);
        if (year_) {
            year_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* month() const noexcept { return month_.get(); }
    void set_month(std::unique_ptr<Symbol> value) {
        month_ = std::move(value);
        if (month_) {
            month_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* day() const noexcept { return day_.get(); }
    void set_day(std::unique_ptr<Symbol> value) {
        day_ = std::move(value);
        if (day_) {
            day_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> year_;
    std::unique_ptr<Symbol> month_;
    std::unique_ptr<Symbol> day_;
};

class date_and_time_c final : public Symbol {
public:
    date_and_time_c() = default;
    date_and_time_c(std::unique_ptr<Symbol> type_name,
        std::unique_ptr<Symbol> date_literal,
        std::unique_ptr<Symbol> daytime,
        SourceRange range = {})
        : Symbol(std::move(range)), type_name_(std::move(type_name)), date_literal_(std::move(date_literal)), daytime_(std::move(daytime)) {
        if (type_name_) {
            type_name_->setParent(this);
        }
        if (date_literal_) {
            date_literal_->setParent(this);
        }
        if (daytime_) {
            daytime_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "date_and_time_c"; }
    [[nodiscard]] Symbol* type_name() const noexcept { return type_name_.get(); }
    void set_type_name(std::unique_ptr<Symbol> value) {
        type_name_ = std::move(value);
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* date_literal() const noexcept { return date_literal_.get(); }
    void set_date_literal(std::unique_ptr<Symbol> value) {
        date_literal_ = std::move(value);
        if (date_literal_) {
            date_literal_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* daytime() const noexcept { return daytime_.get(); }
    void set_daytime(std::unique_ptr<Symbol> value) {
        daytime_ = std::move(value);
        if (daytime_) {
            daytime_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_name_;
    std::unique_ptr<Symbol> date_literal_;
    std::unique_ptr<Symbol> daytime_;
};

class time_type_name_c final : public Symbol {
public:
    time_type_name_c() = default;
    explicit time_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "time_type_name_c"; }
private:
};

class bool_type_name_c final : public Symbol {
public:
    bool_type_name_c() = default;
    explicit bool_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "bool_type_name_c"; }
private:
};

class sint_type_name_c final : public Symbol {
public:
    sint_type_name_c() = default;
    explicit sint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "sint_type_name_c"; }
private:
};

class int_type_name_c final : public Symbol {
public:
    int_type_name_c() = default;
    explicit int_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "int_type_name_c"; }
private:
};

class dint_type_name_c final : public Symbol {
public:
    dint_type_name_c() = default;
    explicit dint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "dint_type_name_c"; }
private:
};

class lint_type_name_c final : public Symbol {
public:
    lint_type_name_c() = default;
    explicit lint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "lint_type_name_c"; }
private:
};

class usint_type_name_c final : public Symbol {
public:
    usint_type_name_c() = default;
    explicit usint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "usint_type_name_c"; }
private:
};

class uint_type_name_c final : public Symbol {
public:
    uint_type_name_c() = default;
    explicit uint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "uint_type_name_c"; }
private:
};

class udint_type_name_c final : public Symbol {
public:
    udint_type_name_c() = default;
    explicit udint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "udint_type_name_c"; }
private:
};

class ulint_type_name_c final : public Symbol {
public:
    ulint_type_name_c() = default;
    explicit ulint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ulint_type_name_c"; }
private:
};

class real_type_name_c final : public Symbol {
public:
    real_type_name_c() = default;
    explicit real_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "real_type_name_c"; }
private:
};

class lreal_type_name_c final : public Symbol {
public:
    lreal_type_name_c() = default;
    explicit lreal_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "lreal_type_name_c"; }
private:
};

class date_type_name_c final : public Symbol {
public:
    date_type_name_c() = default;
    explicit date_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "date_type_name_c"; }
private:
};

class tod_type_name_c final : public Symbol {
public:
    tod_type_name_c() = default;
    explicit tod_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "tod_type_name_c"; }
private:
};

class dt_type_name_c final : public Symbol {
public:
    dt_type_name_c() = default;
    explicit dt_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "dt_type_name_c"; }
private:
};

class byte_type_name_c final : public Symbol {
public:
    byte_type_name_c() = default;
    explicit byte_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "byte_type_name_c"; }
private:
};

class word_type_name_c final : public Symbol {
public:
    word_type_name_c() = default;
    explicit word_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "word_type_name_c"; }
private:
};

class dword_type_name_c final : public Symbol {
public:
    dword_type_name_c() = default;
    explicit dword_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "dword_type_name_c"; }
private:
};

class lword_type_name_c final : public Symbol {
public:
    lword_type_name_c() = default;
    explicit lword_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "lword_type_name_c"; }
private:
};

class string_type_name_c final : public Symbol {
public:
    string_type_name_c() = default;
    explicit string_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "string_type_name_c"; }
private:
};

class wstring_type_name_c final : public Symbol {
public:
    wstring_type_name_c() = default;
    explicit wstring_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "wstring_type_name_c"; }
private:
};

class void_type_name_c final : public Symbol {
public:
    void_type_name_c() = default;
    explicit void_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "void_type_name_c"; }
private:
};

class safetime_type_name_c final : public Symbol {
public:
    safetime_type_name_c() = default;
    explicit safetime_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safetime_type_name_c"; }
private:
};

class safebool_type_name_c final : public Symbol {
public:
    safebool_type_name_c() = default;
    explicit safebool_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safebool_type_name_c"; }
private:
};

class safesint_type_name_c final : public Symbol {
public:
    safesint_type_name_c() = default;
    explicit safesint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safesint_type_name_c"; }
private:
};

class safeint_type_name_c final : public Symbol {
public:
    safeint_type_name_c() = default;
    explicit safeint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safeint_type_name_c"; }
private:
};

class safedint_type_name_c final : public Symbol {
public:
    safedint_type_name_c() = default;
    explicit safedint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safedint_type_name_c"; }
private:
};

class safelint_type_name_c final : public Symbol {
public:
    safelint_type_name_c() = default;
    explicit safelint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safelint_type_name_c"; }
private:
};

class safeusint_type_name_c final : public Symbol {
public:
    safeusint_type_name_c() = default;
    explicit safeusint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safeusint_type_name_c"; }
private:
};

class safeuint_type_name_c final : public Symbol {
public:
    safeuint_type_name_c() = default;
    explicit safeuint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safeuint_type_name_c"; }
private:
};

class safeudint_type_name_c final : public Symbol {
public:
    safeudint_type_name_c() = default;
    explicit safeudint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safeudint_type_name_c"; }
private:
};

class safeulint_type_name_c final : public Symbol {
public:
    safeulint_type_name_c() = default;
    explicit safeulint_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safeulint_type_name_c"; }
private:
};

class safereal_type_name_c final : public Symbol {
public:
    safereal_type_name_c() = default;
    explicit safereal_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safereal_type_name_c"; }
private:
};

class safelreal_type_name_c final : public Symbol {
public:
    safelreal_type_name_c() = default;
    explicit safelreal_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safelreal_type_name_c"; }
private:
};

class safedate_type_name_c final : public Symbol {
public:
    safedate_type_name_c() = default;
    explicit safedate_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safedate_type_name_c"; }
private:
};

class safetod_type_name_c final : public Symbol {
public:
    safetod_type_name_c() = default;
    explicit safetod_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safetod_type_name_c"; }
private:
};

class safedt_type_name_c final : public Symbol {
public:
    safedt_type_name_c() = default;
    explicit safedt_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safedt_type_name_c"; }
private:
};

class safebyte_type_name_c final : public Symbol {
public:
    safebyte_type_name_c() = default;
    explicit safebyte_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safebyte_type_name_c"; }
private:
};

class safeword_type_name_c final : public Symbol {
public:
    safeword_type_name_c() = default;
    explicit safeword_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safeword_type_name_c"; }
private:
};

class safedword_type_name_c final : public Symbol {
public:
    safedword_type_name_c() = default;
    explicit safedword_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safedword_type_name_c"; }
private:
};

class safelword_type_name_c final : public Symbol {
public:
    safelword_type_name_c() = default;
    explicit safelword_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safelword_type_name_c"; }
private:
};

class safestring_type_name_c final : public Symbol {
public:
    safestring_type_name_c() = default;
    explicit safestring_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safestring_type_name_c"; }
private:
};

class safewstring_type_name_c final : public Symbol {
public:
    safewstring_type_name_c() = default;
    explicit safewstring_type_name_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "safewstring_type_name_c"; }
private:
};

class generic_type_any_c final : public Symbol {
public:
    generic_type_any_c() = default;
    explicit generic_type_any_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "generic_type_any_c"; }
private:
};

class data_type_declaration_c final : public Symbol {
public:
    data_type_declaration_c() = default;
    data_type_declaration_c(std::unique_ptr<Symbol> type_declaration_list,
        SourceRange range = {})
        : Symbol(std::move(range)), type_declaration_list_(std::move(type_declaration_list)) {
        if (type_declaration_list_) {
            type_declaration_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "data_type_declaration_c"; }
    [[nodiscard]] Symbol* type_declaration_list() const noexcept { return type_declaration_list_.get(); }
    void set_type_declaration_list(std::unique_ptr<Symbol> value) {
        type_declaration_list_ = std::move(value);
        if (type_declaration_list_) {
            type_declaration_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_declaration_list_;
};

class type_declaration_list_c final : public List {
public:
    type_declaration_list_c() = default;
    explicit type_declaration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "type_declaration_list_c"; }
};

class simple_type_declaration_c final : public Symbol {
public:
    simple_type_declaration_c() = default;
    simple_type_declaration_c(std::unique_ptr<Symbol> simple_type_name,
        std::unique_ptr<Symbol> simple_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), simple_type_name_(std::move(simple_type_name)), simple_spec_init_(std::move(simple_spec_init)) {
        if (simple_type_name_) {
            simple_type_name_->setParent(this);
        }
        if (simple_spec_init_) {
            simple_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "simple_type_declaration_c"; }
    [[nodiscard]] Symbol* simple_type_name() const noexcept { return simple_type_name_.get(); }
    void set_simple_type_name(std::unique_ptr<Symbol> value) {
        simple_type_name_ = std::move(value);
        if (simple_type_name_) {
            simple_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* simple_spec_init() const noexcept { return simple_spec_init_.get(); }
    void set_simple_spec_init(std::unique_ptr<Symbol> value) {
        simple_spec_init_ = std::move(value);
        if (simple_spec_init_) {
            simple_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> simple_type_name_;
    std::unique_ptr<Symbol> simple_spec_init_;
};

class simple_spec_init_c final : public Symbol {
public:
    simple_spec_init_c() = default;
    simple_spec_init_c(std::unique_ptr<Symbol> simple_specification,
        std::unique_ptr<Symbol> constant = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), simple_specification_(std::move(simple_specification)), constant_(std::move(constant)) {
        if (simple_specification_) {
            simple_specification_->setParent(this);
        }
        if (constant_) {
            constant_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "simple_spec_init_c"; }
    [[nodiscard]] Symbol* simple_specification() const noexcept { return simple_specification_.get(); }
    void set_simple_specification(std::unique_ptr<Symbol> value) {
        simple_specification_ = std::move(value);
        if (simple_specification_) {
            simple_specification_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* constant() const noexcept { return constant_.get(); }
    void set_constant(std::unique_ptr<Symbol> value) {
        constant_ = std::move(value);
        if (constant_) {
            constant_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> simple_specification_;
    std::unique_ptr<Symbol> constant_;
};

class subrange_type_declaration_c final : public Symbol {
public:
    subrange_type_declaration_c() = default;
    subrange_type_declaration_c(std::unique_ptr<Symbol> subrange_type_name,
        std::unique_ptr<Symbol> subrange_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), subrange_type_name_(std::move(subrange_type_name)), subrange_spec_init_(std::move(subrange_spec_init)) {
        if (subrange_type_name_) {
            subrange_type_name_->setParent(this);
        }
        if (subrange_spec_init_) {
            subrange_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "subrange_type_declaration_c"; }
    [[nodiscard]] Symbol* subrange_type_name() const noexcept { return subrange_type_name_.get(); }
    void set_subrange_type_name(std::unique_ptr<Symbol> value) {
        subrange_type_name_ = std::move(value);
        if (subrange_type_name_) {
            subrange_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* subrange_spec_init() const noexcept { return subrange_spec_init_.get(); }
    void set_subrange_spec_init(std::unique_ptr<Symbol> value) {
        subrange_spec_init_ = std::move(value);
        if (subrange_spec_init_) {
            subrange_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> subrange_type_name_;
    std::unique_ptr<Symbol> subrange_spec_init_;
};

class subrange_spec_init_c final : public Symbol {
public:
    subrange_spec_init_c() = default;
    subrange_spec_init_c(std::unique_ptr<Symbol> subrange_specification,
        std::unique_ptr<Symbol> signed_integer = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), subrange_specification_(std::move(subrange_specification)), signed_integer_(std::move(signed_integer)) {
        if (subrange_specification_) {
            subrange_specification_->setParent(this);
        }
        if (signed_integer_) {
            signed_integer_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "subrange_spec_init_c"; }
    [[nodiscard]] Symbol* subrange_specification() const noexcept { return subrange_specification_.get(); }
    void set_subrange_specification(std::unique_ptr<Symbol> value) {
        subrange_specification_ = std::move(value);
        if (subrange_specification_) {
            subrange_specification_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* signed_integer() const noexcept { return signed_integer_.get(); }
    void set_signed_integer(std::unique_ptr<Symbol> value) {
        signed_integer_ = std::move(value);
        if (signed_integer_) {
            signed_integer_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> subrange_specification_;
    std::unique_ptr<Symbol> signed_integer_;
};

class subrange_specification_c final : public Symbol {
public:
    subrange_specification_c() = default;
    subrange_specification_c(std::unique_ptr<Symbol> integer_type_name,
        std::unique_ptr<Symbol> subrange = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), integer_type_name_(std::move(integer_type_name)), subrange_(std::move(subrange)) {
        if (integer_type_name_) {
            integer_type_name_->setParent(this);
        }
        if (subrange_) {
            subrange_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "subrange_specification_c"; }
    [[nodiscard]] Symbol* integer_type_name() const noexcept { return integer_type_name_.get(); }
    void set_integer_type_name(std::unique_ptr<Symbol> value) {
        integer_type_name_ = std::move(value);
        if (integer_type_name_) {
            integer_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* subrange() const noexcept { return subrange_.get(); }
    void set_subrange(std::unique_ptr<Symbol> value) {
        subrange_ = std::move(value);
        if (subrange_) {
            subrange_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> integer_type_name_;
    std::unique_ptr<Symbol> subrange_;
};

class subrange_c final : public Symbol {
public:
    subrange_c() = default;
    subrange_c(std::unique_ptr<Symbol> lower_limit,
        std::unique_ptr<Symbol> upper_limit = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), lower_limit_(std::move(lower_limit)), upper_limit_(std::move(upper_limit)) {
        if (lower_limit_) {
            lower_limit_->setParent(this);
        }
        if (upper_limit_) {
            upper_limit_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "subrange_c"; }
    [[nodiscard]] Symbol* lower_limit() const noexcept { return lower_limit_.get(); }
    void set_lower_limit(std::unique_ptr<Symbol> value) {
        lower_limit_ = std::move(value);
        if (lower_limit_) {
            lower_limit_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* upper_limit() const noexcept { return upper_limit_.get(); }
    void set_upper_limit(std::unique_ptr<Symbol> value) {
        upper_limit_ = std::move(value);
        if (upper_limit_) {
            upper_limit_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> lower_limit_;
    std::unique_ptr<Symbol> upper_limit_;
};

class enumerated_type_declaration_c final : public Symbol {
public:
    enumerated_type_declaration_c() = default;
    enumerated_type_declaration_c(std::unique_ptr<Symbol> enumerated_type_name,
        std::unique_ptr<Symbol> enumerated_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), enumerated_type_name_(std::move(enumerated_type_name)), enumerated_spec_init_(std::move(enumerated_spec_init)) {
        if (enumerated_type_name_) {
            enumerated_type_name_->setParent(this);
        }
        if (enumerated_spec_init_) {
            enumerated_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "enumerated_type_declaration_c"; }
    [[nodiscard]] Symbol* enumerated_type_name() const noexcept { return enumerated_type_name_.get(); }
    void set_enumerated_type_name(std::unique_ptr<Symbol> value) {
        enumerated_type_name_ = std::move(value);
        if (enumerated_type_name_) {
            enumerated_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* enumerated_spec_init() const noexcept { return enumerated_spec_init_.get(); }
    void set_enumerated_spec_init(std::unique_ptr<Symbol> value) {
        enumerated_spec_init_ = std::move(value);
        if (enumerated_spec_init_) {
            enumerated_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> enumerated_type_name_;
    std::unique_ptr<Symbol> enumerated_spec_init_;
};

class enumerated_spec_init_c final : public Symbol {
public:
    enumerated_spec_init_c() = default;
    enumerated_spec_init_c(std::unique_ptr<Symbol> enumerated_specification,
        std::unique_ptr<Symbol> enumerated_value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), enumerated_specification_(std::move(enumerated_specification)), enumerated_value_(std::move(enumerated_value)) {
        if (enumerated_specification_) {
            enumerated_specification_->setParent(this);
        }
        if (enumerated_value_) {
            enumerated_value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "enumerated_spec_init_c"; }
    [[nodiscard]] Symbol* enumerated_specification() const noexcept { return enumerated_specification_.get(); }
    void set_enumerated_specification(std::unique_ptr<Symbol> value) {
        enumerated_specification_ = std::move(value);
        if (enumerated_specification_) {
            enumerated_specification_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* enumerated_value() const noexcept { return enumerated_value_.get(); }
    void set_enumerated_value(std::unique_ptr<Symbol> value) {
        enumerated_value_ = std::move(value);
        if (enumerated_value_) {
            enumerated_value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> enumerated_specification_;
    std::unique_ptr<Symbol> enumerated_value_;
};

class enumerated_value_list_c final : public List {
public:
    enumerated_value_list_c() = default;
    explicit enumerated_value_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "enumerated_value_list_c"; }
};

class enumerated_value_c final : public Symbol {
public:
    enumerated_value_c() = default;
    enumerated_value_c(std::unique_ptr<Symbol> type,
        std::unique_ptr<Symbol> value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), type_(std::move(type)), value_(std::move(value)) {
        if (type_) {
            type_->setParent(this);
        }
        if (value_) {
            value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "enumerated_value_c"; }
    [[nodiscard]] Symbol* type() const noexcept { return type_.get(); }
    void set_type(std::unique_ptr<Symbol> value) {
        type_ = std::move(value);
        if (type_) {
            type_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* value() const noexcept { return value_.get(); }
    void set_value(std::unique_ptr<Symbol> value) {
        value_ = std::move(value);
        if (value_) {
            value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_;
    std::unique_ptr<Symbol> value_;
};

class array_type_declaration_c final : public Symbol {
public:
    array_type_declaration_c() = default;
    array_type_declaration_c(std::unique_ptr<Symbol> identifier,
        std::unique_ptr<Symbol> array_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), identifier_(std::move(identifier)), array_spec_init_(std::move(array_spec_init)) {
        if (identifier_) {
            identifier_->setParent(this);
        }
        if (array_spec_init_) {
            array_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_type_declaration_c"; }
    [[nodiscard]] Symbol* identifier() const noexcept { return identifier_.get(); }
    void set_identifier(std::unique_ptr<Symbol> value) {
        identifier_ = std::move(value);
        if (identifier_) {
            identifier_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* array_spec_init() const noexcept { return array_spec_init_.get(); }
    void set_array_spec_init(std::unique_ptr<Symbol> value) {
        array_spec_init_ = std::move(value);
        if (array_spec_init_) {
            array_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> identifier_;
    std::unique_ptr<Symbol> array_spec_init_;
};

class array_spec_init_c final : public Symbol {
public:
    array_spec_init_c() = default;
    array_spec_init_c(std::unique_ptr<Symbol> array_specification,
        std::unique_ptr<Symbol> array_initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), array_specification_(std::move(array_specification)), array_initialization_(std::move(array_initialization)) {
        if (array_specification_) {
            array_specification_->setParent(this);
        }
        if (array_initialization_) {
            array_initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_spec_init_c"; }
    [[nodiscard]] Symbol* array_specification() const noexcept { return array_specification_.get(); }
    void set_array_specification(std::unique_ptr<Symbol> value) {
        array_specification_ = std::move(value);
        if (array_specification_) {
            array_specification_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* array_initialization() const noexcept { return array_initialization_.get(); }
    void set_array_initialization(std::unique_ptr<Symbol> value) {
        array_initialization_ = std::move(value);
        if (array_initialization_) {
            array_initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> array_specification_;
    std::unique_ptr<Symbol> array_initialization_;
};

class array_specification_c final : public Symbol {
public:
    array_specification_c() = default;
    array_specification_c(std::unique_ptr<Symbol> array_subrange_list,
        std::unique_ptr<Symbol> non_generic_type_name = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), array_subrange_list_(std::move(array_subrange_list)), non_generic_type_name_(std::move(non_generic_type_name)) {
        if (array_subrange_list_) {
            array_subrange_list_->setParent(this);
        }
        if (non_generic_type_name_) {
            non_generic_type_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_specification_c"; }
    [[nodiscard]] Symbol* array_subrange_list() const noexcept { return array_subrange_list_.get(); }
    void set_array_subrange_list(std::unique_ptr<Symbol> value) {
        array_subrange_list_ = std::move(value);
        if (array_subrange_list_) {
            array_subrange_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* non_generic_type_name() const noexcept { return non_generic_type_name_.get(); }
    void set_non_generic_type_name(std::unique_ptr<Symbol> value) {
        non_generic_type_name_ = std::move(value);
        if (non_generic_type_name_) {
            non_generic_type_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> array_subrange_list_;
    std::unique_ptr<Symbol> non_generic_type_name_;
};

class array_subrange_list_c final : public List {
public:
    array_subrange_list_c() = default;
    explicit array_subrange_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_subrange_list_c"; }
};

class array_initial_elements_list_c final : public List {
public:
    array_initial_elements_list_c() = default;
    explicit array_initial_elements_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_initial_elements_list_c"; }
};

class array_initial_elements_c final : public Symbol {
public:
    array_initial_elements_c() = default;
    array_initial_elements_c(std::unique_ptr<Symbol> integer,
        std::unique_ptr<Symbol> array_initial_element = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), integer_(std::move(integer)), array_initial_element_(std::move(array_initial_element)) {
        if (integer_) {
            integer_->setParent(this);
        }
        if (array_initial_element_) {
            array_initial_element_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_initial_elements_c"; }
    [[nodiscard]] Symbol* integer() const noexcept { return integer_.get(); }
    void set_integer(std::unique_ptr<Symbol> value) {
        integer_ = std::move(value);
        if (integer_) {
            integer_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* array_initial_element() const noexcept { return array_initial_element_.get(); }
    void set_array_initial_element(std::unique_ptr<Symbol> value) {
        array_initial_element_ = std::move(value);
        if (array_initial_element_) {
            array_initial_element_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> integer_;
    std::unique_ptr<Symbol> array_initial_element_;
};

class structure_type_declaration_c final : public Symbol {
public:
    structure_type_declaration_c() = default;
    structure_type_declaration_c(std::unique_ptr<Symbol> structure_type_name,
        std::unique_ptr<Symbol> structure_specification = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), structure_type_name_(std::move(structure_type_name)), structure_specification_(std::move(structure_specification)) {
        if (structure_type_name_) {
            structure_type_name_->setParent(this);
        }
        if (structure_specification_) {
            structure_specification_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structure_type_declaration_c"; }
    [[nodiscard]] Symbol* structure_type_name() const noexcept { return structure_type_name_.get(); }
    void set_structure_type_name(std::unique_ptr<Symbol> value) {
        structure_type_name_ = std::move(value);
        if (structure_type_name_) {
            structure_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* structure_specification() const noexcept { return structure_specification_.get(); }
    void set_structure_specification(std::unique_ptr<Symbol> value) {
        structure_specification_ = std::move(value);
        if (structure_specification_) {
            structure_specification_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> structure_type_name_;
    std::unique_ptr<Symbol> structure_specification_;
};

class initialized_structure_c final : public Symbol {
public:
    initialized_structure_c() = default;
    initialized_structure_c(std::unique_ptr<Symbol> structure_type_name,
        std::unique_ptr<Symbol> structure_initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), structure_type_name_(std::move(structure_type_name)), structure_initialization_(std::move(structure_initialization)) {
        if (structure_type_name_) {
            structure_type_name_->setParent(this);
        }
        if (structure_initialization_) {
            structure_initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "initialized_structure_c"; }
    [[nodiscard]] Symbol* structure_type_name() const noexcept { return structure_type_name_.get(); }
    void set_structure_type_name(std::unique_ptr<Symbol> value) {
        structure_type_name_ = std::move(value);
        if (structure_type_name_) {
            structure_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* structure_initialization() const noexcept { return structure_initialization_.get(); }
    void set_structure_initialization(std::unique_ptr<Symbol> value) {
        structure_initialization_ = std::move(value);
        if (structure_initialization_) {
            structure_initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> structure_type_name_;
    std::unique_ptr<Symbol> structure_initialization_;
};

class structure_element_declaration_list_c final : public List {
public:
    structure_element_declaration_list_c() = default;
    explicit structure_element_declaration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structure_element_declaration_list_c"; }
};

class structure_element_declaration_c final : public Symbol {
public:
    structure_element_declaration_c() = default;
    structure_element_declaration_c(std::unique_ptr<Symbol> structure_element_name,
        std::unique_ptr<Symbol> spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), structure_element_name_(std::move(structure_element_name)), spec_init_(std::move(spec_init)) {
        if (structure_element_name_) {
            structure_element_name_->setParent(this);
        }
        if (spec_init_) {
            spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structure_element_declaration_c"; }
    [[nodiscard]] Symbol* structure_element_name() const noexcept { return structure_element_name_.get(); }
    void set_structure_element_name(std::unique_ptr<Symbol> value) {
        structure_element_name_ = std::move(value);
        if (structure_element_name_) {
            structure_element_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* spec_init() const noexcept { return spec_init_.get(); }
    void set_spec_init(std::unique_ptr<Symbol> value) {
        spec_init_ = std::move(value);
        if (spec_init_) {
            spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> structure_element_name_;
    std::unique_ptr<Symbol> spec_init_;
};

class structure_element_initialization_list_c final : public List {
public:
    structure_element_initialization_list_c() = default;
    explicit structure_element_initialization_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structure_element_initialization_list_c"; }
};

class structure_element_initialization_c final : public Symbol {
public:
    structure_element_initialization_c() = default;
    structure_element_initialization_c(std::unique_ptr<Symbol> structure_element_name,
        std::unique_ptr<Symbol> value = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), structure_element_name_(std::move(structure_element_name)), value_(std::move(value)) {
        if (structure_element_name_) {
            structure_element_name_->setParent(this);
        }
        if (value_) {
            value_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structure_element_initialization_c"; }
    [[nodiscard]] Symbol* structure_element_name() const noexcept { return structure_element_name_.get(); }
    void set_structure_element_name(std::unique_ptr<Symbol> value) {
        structure_element_name_ = std::move(value);
        if (structure_element_name_) {
            structure_element_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* value() const noexcept { return value_.get(); }
    void set_value(std::unique_ptr<Symbol> value) {
        value_ = std::move(value);
        if (value_) {
            value_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> structure_element_name_;
    std::unique_ptr<Symbol> value_;
};

class string_type_declaration_c final : public Symbol {
public:
    string_type_declaration_c() = default;
    string_type_declaration_c(std::unique_ptr<Symbol> string_type_name,
        std::unique_ptr<Symbol> elementary_string_type_name,
        std::unique_ptr<Symbol> string_type_declaration_size,
        std::unique_ptr<Symbol> string_type_declaration_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), string_type_name_(std::move(string_type_name)), elementary_string_type_name_(std::move(elementary_string_type_name)), string_type_declaration_size_(std::move(string_type_declaration_size)), string_type_declaration_init_(std::move(string_type_declaration_init)) {
        if (string_type_name_) {
            string_type_name_->setParent(this);
        }
        if (elementary_string_type_name_) {
            elementary_string_type_name_->setParent(this);
        }
        if (string_type_declaration_size_) {
            string_type_declaration_size_->setParent(this);
        }
        if (string_type_declaration_init_) {
            string_type_declaration_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "string_type_declaration_c"; }
    [[nodiscard]] Symbol* string_type_name() const noexcept { return string_type_name_.get(); }
    void set_string_type_name(std::unique_ptr<Symbol> value) {
        string_type_name_ = std::move(value);
        if (string_type_name_) {
            string_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* elementary_string_type_name() const noexcept { return elementary_string_type_name_.get(); }
    void set_elementary_string_type_name(std::unique_ptr<Symbol> value) {
        elementary_string_type_name_ = std::move(value);
        if (elementary_string_type_name_) {
            elementary_string_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* string_type_declaration_size() const noexcept { return string_type_declaration_size_.get(); }
    void set_string_type_declaration_size(std::unique_ptr<Symbol> value) {
        string_type_declaration_size_ = std::move(value);
        if (string_type_declaration_size_) {
            string_type_declaration_size_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* string_type_declaration_init() const noexcept { return string_type_declaration_init_.get(); }
    void set_string_type_declaration_init(std::unique_ptr<Symbol> value) {
        string_type_declaration_init_ = std::move(value);
        if (string_type_declaration_init_) {
            string_type_declaration_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> string_type_name_;
    std::unique_ptr<Symbol> elementary_string_type_name_;
    std::unique_ptr<Symbol> string_type_declaration_size_;
    std::unique_ptr<Symbol> string_type_declaration_init_;
};

class fb_spec_init_c final : public Symbol {
public:
    fb_spec_init_c() = default;
    fb_spec_init_c(std::unique_ptr<Symbol> function_block_type_name,
        std::unique_ptr<Symbol> structure_initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), function_block_type_name_(std::move(function_block_type_name)), structure_initialization_(std::move(structure_initialization)) {
        if (function_block_type_name_) {
            function_block_type_name_->setParent(this);
        }
        if (structure_initialization_) {
            structure_initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fb_spec_init_c"; }
    [[nodiscard]] Symbol* function_block_type_name() const noexcept { return function_block_type_name_.get(); }
    void set_function_block_type_name(std::unique_ptr<Symbol> value) {
        function_block_type_name_ = std::move(value);
        if (function_block_type_name_) {
            function_block_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* structure_initialization() const noexcept { return structure_initialization_.get(); }
    void set_structure_initialization(std::unique_ptr<Symbol> value) {
        structure_initialization_ = std::move(value);
        if (structure_initialization_) {
            structure_initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> function_block_type_name_;
    std::unique_ptr<Symbol> structure_initialization_;
};

class ref_spec_c final : public Symbol {
public:
    ref_spec_c() = default;
    ref_spec_c(std::unique_ptr<Symbol> type_name,
        SourceRange range = {})
        : Symbol(std::move(range)), type_name_(std::move(type_name)) {
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ref_spec_c"; }
    [[nodiscard]] Symbol* type_name() const noexcept { return type_name_.get(); }
    void set_type_name(std::unique_ptr<Symbol> value) {
        type_name_ = std::move(value);
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> type_name_;
};

class ref_spec_init_c final : public Symbol {
public:
    ref_spec_init_c() = default;
    ref_spec_init_c(std::unique_ptr<Symbol> ref_spec,
        std::unique_ptr<Symbol> ref_initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), ref_spec_(std::move(ref_spec)), ref_initialization_(std::move(ref_initialization)) {
        if (ref_spec_) {
            ref_spec_->setParent(this);
        }
        if (ref_initialization_) {
            ref_initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ref_spec_init_c"; }
    [[nodiscard]] Symbol* ref_spec() const noexcept { return ref_spec_.get(); }
    void set_ref_spec(std::unique_ptr<Symbol> value) {
        ref_spec_ = std::move(value);
        if (ref_spec_) {
            ref_spec_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* ref_initialization() const noexcept { return ref_initialization_.get(); }
    void set_ref_initialization(std::unique_ptr<Symbol> value) {
        ref_initialization_ = std::move(value);
        if (ref_initialization_) {
            ref_initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> ref_spec_;
    std::unique_ptr<Symbol> ref_initialization_;
};

class ref_type_decl_c final : public Symbol {
public:
    ref_type_decl_c() = default;
    ref_type_decl_c(std::unique_ptr<Symbol> ref_type_name,
        std::unique_ptr<Symbol> ref_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), ref_type_name_(std::move(ref_type_name)), ref_spec_init_(std::move(ref_spec_init)) {
        if (ref_type_name_) {
            ref_type_name_->setParent(this);
        }
        if (ref_spec_init_) {
            ref_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ref_type_decl_c"; }
    [[nodiscard]] Symbol* ref_type_name() const noexcept { return ref_type_name_.get(); }
    void set_ref_type_name(std::unique_ptr<Symbol> value) {
        ref_type_name_ = std::move(value);
        if (ref_type_name_) {
            ref_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* ref_spec_init() const noexcept { return ref_spec_init_.get(); }
    void set_ref_spec_init(std::unique_ptr<Symbol> value) {
        ref_spec_init_ = std::move(value);
        if (ref_spec_init_) {
            ref_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> ref_type_name_;
    std::unique_ptr<Symbol> ref_spec_init_;
};

class symbolic_variable_c final : public Symbol {
public:
    symbolic_variable_c() = default;
    symbolic_variable_c(std::unique_ptr<Symbol> var_name,
        SourceRange range = {})
        : Symbol(std::move(range)), var_name_(std::move(var_name)) {
        if (var_name_) {
            var_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "symbolic_variable_c"; }
    [[nodiscard]] Symbol* var_name() const noexcept { return var_name_.get(); }
    void set_var_name(std::unique_ptr<Symbol> value) {
        var_name_ = std::move(value);
        if (var_name_) {
            var_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_name_;
};

class symbolic_constant_c final : public Symbol {
public:
    symbolic_constant_c() = default;
    symbolic_constant_c(std::unique_ptr<Symbol> var_name,
        SourceRange range = {})
        : Symbol(std::move(range)), var_name_(std::move(var_name)) {
        if (var_name_) {
            var_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "symbolic_constant_c"; }
    [[nodiscard]] Symbol* var_name() const noexcept { return var_name_.get(); }
    void set_var_name(std::unique_ptr<Symbol> value) {
        var_name_ = std::move(value);
        if (var_name_) {
            var_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_name_;
};

class direct_variable_c final : public Token {
public:
    direct_variable_c() = default;
    explicit direct_variable_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "direct_variable_c"; }
};

class array_variable_c final : public Symbol {
public:
    array_variable_c() = default;
    array_variable_c(std::unique_ptr<Symbol> subscripted_variable,
        std::unique_ptr<Symbol> subscript_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), subscripted_variable_(std::move(subscripted_variable)), subscript_list_(std::move(subscript_list)) {
        if (subscripted_variable_) {
            subscripted_variable_->setParent(this);
        }
        if (subscript_list_) {
            subscript_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_variable_c"; }
    [[nodiscard]] Symbol* subscripted_variable() const noexcept { return subscripted_variable_.get(); }
    void set_subscripted_variable(std::unique_ptr<Symbol> value) {
        subscripted_variable_ = std::move(value);
        if (subscripted_variable_) {
            subscripted_variable_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* subscript_list() const noexcept { return subscript_list_.get(); }
    void set_subscript_list(std::unique_ptr<Symbol> value) {
        subscript_list_ = std::move(value);
        if (subscript_list_) {
            subscript_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> subscripted_variable_;
    std::unique_ptr<Symbol> subscript_list_;
};

class subscript_list_c final : public List {
public:
    subscript_list_c() = default;
    explicit subscript_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "subscript_list_c"; }
};

class structured_variable_c final : public Symbol {
public:
    structured_variable_c() = default;
    structured_variable_c(std::unique_ptr<Symbol> record_variable,
        std::unique_ptr<Symbol> field_selector = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), record_variable_(std::move(record_variable)), field_selector_(std::move(field_selector)) {
        if (record_variable_) {
            record_variable_->setParent(this);
        }
        if (field_selector_) {
            field_selector_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structured_variable_c"; }
    [[nodiscard]] Symbol* record_variable() const noexcept { return record_variable_.get(); }
    void set_record_variable(std::unique_ptr<Symbol> value) {
        record_variable_ = std::move(value);
        if (record_variable_) {
            record_variable_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* field_selector() const noexcept { return field_selector_.get(); }
    void set_field_selector(std::unique_ptr<Symbol> value) {
        field_selector_ = std::move(value);
        if (field_selector_) {
            field_selector_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> record_variable_;
    std::unique_ptr<Symbol> field_selector_;
};

class constant_option_c final : public Symbol {
public:
    constant_option_c() = default;
    explicit constant_option_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "constant_option_c"; }
private:
};

class retain_option_c final : public Symbol {
public:
    retain_option_c() = default;
    explicit retain_option_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "retain_option_c"; }
private:
};

class non_retain_option_c final : public Symbol {
public:
    non_retain_option_c() = default;
    explicit non_retain_option_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "non_retain_option_c"; }
private:
};

class input_declarations_c final : public Symbol {
public:
    input_declarations_c() = default;
    input_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> input_declaration_list,
        std::unique_ptr<Symbol> method,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), input_declaration_list_(std::move(input_declaration_list)), method_(std::move(method)) {
        if (option_) {
            option_->setParent(this);
        }
        if (input_declaration_list_) {
            input_declaration_list_->setParent(this);
        }
        if (method_) {
            method_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "input_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* input_declaration_list() const noexcept { return input_declaration_list_.get(); }
    void set_input_declaration_list(std::unique_ptr<Symbol> value) {
        input_declaration_list_ = std::move(value);
        if (input_declaration_list_) {
            input_declaration_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* method() const noexcept { return method_.get(); }
    void set_method(std::unique_ptr<Symbol> value) {
        method_ = std::move(value);
        if (method_) {
            method_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> input_declaration_list_;
    std::unique_ptr<Symbol> method_;
};

class input_declaration_list_c final : public List {
public:
    input_declaration_list_c() = default;
    explicit input_declaration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "input_declaration_list_c"; }
};

class implicit_definition_c final : public Symbol {
public:
    implicit_definition_c() = default;
    explicit implicit_definition_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "implicit_definition_c"; }
private:
};

class explicit_definition_c final : public Symbol {
public:
    explicit_definition_c() = default;
    explicit explicit_definition_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "explicit_definition_c"; }
private:
};

class en_param_declaration_c final : public Symbol {
public:
    en_param_declaration_c() = default;
    en_param_declaration_c(std::unique_ptr<Symbol> name,
        std::unique_ptr<Symbol> type_decl,
        std::unique_ptr<Symbol> method,
        SourceRange range = {})
        : Symbol(std::move(range)), name_(std::move(name)), type_decl_(std::move(type_decl)), method_(std::move(method)) {
        if (name_) {
            name_->setParent(this);
        }
        if (type_decl_) {
            type_decl_->setParent(this);
        }
        if (method_) {
            method_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "en_param_declaration_c"; }
    [[nodiscard]] Symbol* name() const noexcept { return name_.get(); }
    void set_name(std::unique_ptr<Symbol> value) {
        name_ = std::move(value);
        if (name_) {
            name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* type_decl() const noexcept { return type_decl_.get(); }
    void set_type_decl(std::unique_ptr<Symbol> value) {
        type_decl_ = std::move(value);
        if (type_decl_) {
            type_decl_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* method() const noexcept { return method_.get(); }
    void set_method(std::unique_ptr<Symbol> value) {
        method_ = std::move(value);
        if (method_) {
            method_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> name_;
    std::unique_ptr<Symbol> type_decl_;
    std::unique_ptr<Symbol> method_;
};

class eno_param_declaration_c final : public Symbol {
public:
    eno_param_declaration_c() = default;
    eno_param_declaration_c(std::unique_ptr<Symbol> name,
        std::unique_ptr<Symbol> type,
        std::unique_ptr<Symbol> method,
        SourceRange range = {})
        : Symbol(std::move(range)), name_(std::move(name)), type_(std::move(type)), method_(std::move(method)) {
        if (name_) {
            name_->setParent(this);
        }
        if (type_) {
            type_->setParent(this);
        }
        if (method_) {
            method_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "eno_param_declaration_c"; }
    [[nodiscard]] Symbol* name() const noexcept { return name_.get(); }
    void set_name(std::unique_ptr<Symbol> value) {
        name_ = std::move(value);
        if (name_) {
            name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* type() const noexcept { return type_.get(); }
    void set_type(std::unique_ptr<Symbol> value) {
        type_ = std::move(value);
        if (type_) {
            type_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* method() const noexcept { return method_.get(); }
    void set_method(std::unique_ptr<Symbol> value) {
        method_ = std::move(value);
        if (method_) {
            method_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> name_;
    std::unique_ptr<Symbol> type_;
    std::unique_ptr<Symbol> method_;
};

class edge_declaration_c final : public Symbol {
public:
    edge_declaration_c() = default;
    edge_declaration_c(std::unique_ptr<Symbol> edge,
        std::unique_ptr<Symbol> var1_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), edge_(std::move(edge)), var1_list_(std::move(var1_list)) {
        if (edge_) {
            edge_->setParent(this);
        }
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "edge_declaration_c"; }
    [[nodiscard]] Symbol* edge() const noexcept { return edge_.get(); }
    void set_edge(std::unique_ptr<Symbol> value) {
        edge_ = std::move(value);
        if (edge_) {
            edge_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> edge_;
    std::unique_ptr<Symbol> var1_list_;
};

class raising_edge_option_c final : public Symbol {
public:
    raising_edge_option_c() = default;
    explicit raising_edge_option_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "raising_edge_option_c"; }
private:
};

class falling_edge_option_c final : public Symbol {
public:
    falling_edge_option_c() = default;
    explicit falling_edge_option_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "falling_edge_option_c"; }
private:
};

class var1_init_decl_c final : public Symbol {
public:
    var1_init_decl_c() = default;
    var1_init_decl_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), spec_init_(std::move(spec_init)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (spec_init_) {
            spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var1_init_decl_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* spec_init() const noexcept { return spec_init_.get(); }
    void set_spec_init(std::unique_ptr<Symbol> value) {
        spec_init_ = std::move(value);
        if (spec_init_) {
            spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> spec_init_;
};

class var1_list_c final : public List {
public:
    var1_list_c() = default;
    explicit var1_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var1_list_c"; }
};

class extensible_input_parameter_c final : public Symbol {
public:
    extensible_input_parameter_c() = default;
    extensible_input_parameter_c(std::unique_ptr<Symbol> var_name,
        std::unique_ptr<Symbol> first_index = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var_name_(std::move(var_name)), first_index_(std::move(first_index)) {
        if (var_name_) {
            var_name_->setParent(this);
        }
        if (first_index_) {
            first_index_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "extensible_input_parameter_c"; }
    [[nodiscard]] Symbol* var_name() const noexcept { return var_name_.get(); }
    void set_var_name(std::unique_ptr<Symbol> value) {
        var_name_ = std::move(value);
        if (var_name_) {
            var_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* first_index() const noexcept { return first_index_.get(); }
    void set_first_index(std::unique_ptr<Symbol> value) {
        first_index_ = std::move(value);
        if (first_index_) {
            first_index_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_name_;
    std::unique_ptr<Symbol> first_index_;
};

class array_var_init_decl_c final : public Symbol {
public:
    array_var_init_decl_c() = default;
    array_var_init_decl_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> array_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), array_spec_init_(std::move(array_spec_init)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (array_spec_init_) {
            array_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_var_init_decl_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* array_spec_init() const noexcept { return array_spec_init_.get(); }
    void set_array_spec_init(std::unique_ptr<Symbol> value) {
        array_spec_init_ = std::move(value);
        if (array_spec_init_) {
            array_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> array_spec_init_;
};

class structured_var_init_decl_c final : public Symbol {
public:
    structured_var_init_decl_c() = default;
    structured_var_init_decl_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> initialized_structure = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), initialized_structure_(std::move(initialized_structure)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (initialized_structure_) {
            initialized_structure_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structured_var_init_decl_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* initialized_structure() const noexcept { return initialized_structure_.get(); }
    void set_initialized_structure(std::unique_ptr<Symbol> value) {
        initialized_structure_ = std::move(value);
        if (initialized_structure_) {
            initialized_structure_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> initialized_structure_;
};

class fb_name_decl_c final : public Symbol {
public:
    fb_name_decl_c() = default;
    fb_name_decl_c(std::unique_ptr<Symbol> fb_name_list,
        std::unique_ptr<Symbol> fb_spec_init = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), fb_name_list_(std::move(fb_name_list)), fb_spec_init_(std::move(fb_spec_init)) {
        if (fb_name_list_) {
            fb_name_list_->setParent(this);
        }
        if (fb_spec_init_) {
            fb_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fb_name_decl_c"; }
    [[nodiscard]] Symbol* fb_name_list() const noexcept { return fb_name_list_.get(); }
    void set_fb_name_list(std::unique_ptr<Symbol> value) {
        fb_name_list_ = std::move(value);
        if (fb_name_list_) {
            fb_name_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* fb_spec_init() const noexcept { return fb_spec_init_.get(); }
    void set_fb_spec_init(std::unique_ptr<Symbol> value) {
        fb_spec_init_ = std::move(value);
        if (fb_spec_init_) {
            fb_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> fb_name_list_;
    std::unique_ptr<Symbol> fb_spec_init_;
};

class fb_name_list_c final : public List {
public:
    fb_name_list_c() = default;
    explicit fb_name_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fb_name_list_c"; }
};

class output_declarations_c final : public Symbol {
public:
    output_declarations_c() = default;
    output_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> var_init_decl_list,
        std::unique_ptr<Symbol> method,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), var_init_decl_list_(std::move(var_init_decl_list)), method_(std::move(method)) {
        if (option_) {
            option_->setParent(this);
        }
        if (var_init_decl_list_) {
            var_init_decl_list_->setParent(this);
        }
        if (method_) {
            method_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "output_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var_init_decl_list() const noexcept { return var_init_decl_list_.get(); }
    void set_var_init_decl_list(std::unique_ptr<Symbol> value) {
        var_init_decl_list_ = std::move(value);
        if (var_init_decl_list_) {
            var_init_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* method() const noexcept { return method_.get(); }
    void set_method(std::unique_ptr<Symbol> value) {
        method_ = std::move(value);
        if (method_) {
            method_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> var_init_decl_list_;
    std::unique_ptr<Symbol> method_;
};

class input_output_declarations_c final : public Symbol {
public:
    input_output_declarations_c() = default;
    input_output_declarations_c(std::unique_ptr<Symbol> var_declaration_list,
        SourceRange range = {})
        : Symbol(std::move(range)), var_declaration_list_(std::move(var_declaration_list)) {
        if (var_declaration_list_) {
            var_declaration_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "input_output_declarations_c"; }
    [[nodiscard]] Symbol* var_declaration_list() const noexcept { return var_declaration_list_.get(); }
    void set_var_declaration_list(std::unique_ptr<Symbol> value) {
        var_declaration_list_ = std::move(value);
        if (var_declaration_list_) {
            var_declaration_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_declaration_list_;
};

class var_declaration_list_c final : public List {
public:
    var_declaration_list_c() = default;
    explicit var_declaration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var_declaration_list_c"; }
};

class array_var_declaration_c final : public Symbol {
public:
    array_var_declaration_c() = default;
    array_var_declaration_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> array_specification = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), array_specification_(std::move(array_specification)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (array_specification_) {
            array_specification_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "array_var_declaration_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* array_specification() const noexcept { return array_specification_.get(); }
    void set_array_specification(std::unique_ptr<Symbol> value) {
        array_specification_ = std::move(value);
        if (array_specification_) {
            array_specification_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> array_specification_;
};

class structured_var_declaration_c final : public Symbol {
public:
    structured_var_declaration_c() = default;
    structured_var_declaration_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> structure_type_name = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), structure_type_name_(std::move(structure_type_name)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (structure_type_name_) {
            structure_type_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "structured_var_declaration_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* structure_type_name() const noexcept { return structure_type_name_.get(); }
    void set_structure_type_name(std::unique_ptr<Symbol> value) {
        structure_type_name_ = std::move(value);
        if (structure_type_name_) {
            structure_type_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> structure_type_name_;
};

class var_declarations_c final : public Symbol {
public:
    var_declarations_c() = default;
    var_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> var_init_decl_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), var_init_decl_list_(std::move(var_init_decl_list)) {
        if (option_) {
            option_->setParent(this);
        }
        if (var_init_decl_list_) {
            var_init_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var_init_decl_list() const noexcept { return var_init_decl_list_.get(); }
    void set_var_init_decl_list(std::unique_ptr<Symbol> value) {
        var_init_decl_list_ = std::move(value);
        if (var_init_decl_list_) {
            var_init_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> var_init_decl_list_;
};

class retentive_var_declarations_c final : public Symbol {
public:
    retentive_var_declarations_c() = default;
    retentive_var_declarations_c(std::unique_ptr<Symbol> var_init_decl_list,
        SourceRange range = {})
        : Symbol(std::move(range)), var_init_decl_list_(std::move(var_init_decl_list)) {
        if (var_init_decl_list_) {
            var_init_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "retentive_var_declarations_c"; }
    [[nodiscard]] Symbol* var_init_decl_list() const noexcept { return var_init_decl_list_.get(); }
    void set_var_init_decl_list(std::unique_ptr<Symbol> value) {
        var_init_decl_list_ = std::move(value);
        if (var_init_decl_list_) {
            var_init_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_init_decl_list_;
};

class located_var_declarations_c final : public Symbol {
public:
    located_var_declarations_c() = default;
    located_var_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> located_var_decl_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), located_var_decl_list_(std::move(located_var_decl_list)) {
        if (option_) {
            option_->setParent(this);
        }
        if (located_var_decl_list_) {
            located_var_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "located_var_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* located_var_decl_list() const noexcept { return located_var_decl_list_.get(); }
    void set_located_var_decl_list(std::unique_ptr<Symbol> value) {
        located_var_decl_list_ = std::move(value);
        if (located_var_decl_list_) {
            located_var_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> located_var_decl_list_;
};

class located_var_decl_list_c final : public List {
public:
    located_var_decl_list_c() = default;
    explicit located_var_decl_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "located_var_decl_list_c"; }
};

class located_var_decl_c final : public Symbol {
public:
    located_var_decl_c() = default;
    located_var_decl_c(std::unique_ptr<Symbol> variable_name,
        std::unique_ptr<Symbol> location,
        std::unique_ptr<Symbol> located_var_spec_init,
        SourceRange range = {})
        : Symbol(std::move(range)), variable_name_(std::move(variable_name)), location_(std::move(location)), located_var_spec_init_(std::move(located_var_spec_init)) {
        if (variable_name_) {
            variable_name_->setParent(this);
        }
        if (location_) {
            location_->setParent(this);
        }
        if (located_var_spec_init_) {
            located_var_spec_init_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "located_var_decl_c"; }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* location() const noexcept { return location_.get(); }
    void set_location(std::unique_ptr<Symbol> value) {
        location_ = std::move(value);
        if (location_) {
            location_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* located_var_spec_init() const noexcept { return located_var_spec_init_.get(); }
    void set_located_var_spec_init(std::unique_ptr<Symbol> value) {
        located_var_spec_init_ = std::move(value);
        if (located_var_spec_init_) {
            located_var_spec_init_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> variable_name_;
    std::unique_ptr<Symbol> location_;
    std::unique_ptr<Symbol> located_var_spec_init_;
};

class external_var_declarations_c final : public Symbol {
public:
    external_var_declarations_c() = default;
    external_var_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> external_declaration_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), external_declaration_list_(std::move(external_declaration_list)) {
        if (option_) {
            option_->setParent(this);
        }
        if (external_declaration_list_) {
            external_declaration_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "external_var_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* external_declaration_list() const noexcept { return external_declaration_list_.get(); }
    void set_external_declaration_list(std::unique_ptr<Symbol> value) {
        external_declaration_list_ = std::move(value);
        if (external_declaration_list_) {
            external_declaration_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> external_declaration_list_;
};

class external_declaration_list_c final : public List {
public:
    external_declaration_list_c() = default;
    explicit external_declaration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "external_declaration_list_c"; }
};

class external_declaration_c final : public Symbol {
public:
    external_declaration_c() = default;
    external_declaration_c(std::unique_ptr<Symbol> global_var_name,
        std::unique_ptr<Symbol> specification = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), global_var_name_(std::move(global_var_name)), specification_(std::move(specification)) {
        if (global_var_name_) {
            global_var_name_->setParent(this);
        }
        if (specification_) {
            specification_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "external_declaration_c"; }
    [[nodiscard]] Symbol* global_var_name() const noexcept { return global_var_name_.get(); }
    void set_global_var_name(std::unique_ptr<Symbol> value) {
        global_var_name_ = std::move(value);
        if (global_var_name_) {
            global_var_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* specification() const noexcept { return specification_.get(); }
    void set_specification(std::unique_ptr<Symbol> value) {
        specification_ = std::move(value);
        if (specification_) {
            specification_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> global_var_name_;
    std::unique_ptr<Symbol> specification_;
};

class global_var_declarations_c final : public Symbol {
public:
    global_var_declarations_c() = default;
    global_var_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> global_var_decl_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), global_var_decl_list_(std::move(global_var_decl_list)) {
        if (option_) {
            option_->setParent(this);
        }
        if (global_var_decl_list_) {
            global_var_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* global_var_decl_list() const noexcept { return global_var_decl_list_.get(); }
    void set_global_var_decl_list(std::unique_ptr<Symbol> value) {
        global_var_decl_list_ = std::move(value);
        if (global_var_decl_list_) {
            global_var_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> global_var_decl_list_;
};

class global_var_decl_list_c final : public List {
public:
    global_var_decl_list_c() = default;
    explicit global_var_decl_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_decl_list_c"; }
};

class global_var_decl_c final : public Symbol {
public:
    global_var_decl_c() = default;
    global_var_decl_c(std::unique_ptr<Symbol> global_var_spec,
        std::unique_ptr<Symbol> type_specification = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), global_var_spec_(std::move(global_var_spec)), type_specification_(std::move(type_specification)) {
        if (global_var_spec_) {
            global_var_spec_->setParent(this);
        }
        if (type_specification_) {
            type_specification_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_decl_c"; }
    [[nodiscard]] Symbol* global_var_spec() const noexcept { return global_var_spec_.get(); }
    void set_global_var_spec(std::unique_ptr<Symbol> value) {
        global_var_spec_ = std::move(value);
        if (global_var_spec_) {
            global_var_spec_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* type_specification() const noexcept { return type_specification_.get(); }
    void set_type_specification(std::unique_ptr<Symbol> value) {
        type_specification_ = std::move(value);
        if (type_specification_) {
            type_specification_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> global_var_spec_;
    std::unique_ptr<Symbol> type_specification_;
};

class global_var_spec_c final : public Symbol {
public:
    global_var_spec_c() = default;
    global_var_spec_c(std::unique_ptr<Symbol> global_var_name,
        std::unique_ptr<Symbol> location = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), global_var_name_(std::move(global_var_name)), location_(std::move(location)) {
        if (global_var_name_) {
            global_var_name_->setParent(this);
        }
        if (location_) {
            location_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_spec_c"; }
    [[nodiscard]] Symbol* global_var_name() const noexcept { return global_var_name_.get(); }
    void set_global_var_name(std::unique_ptr<Symbol> value) {
        global_var_name_ = std::move(value);
        if (global_var_name_) {
            global_var_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* location() const noexcept { return location_.get(); }
    void set_location(std::unique_ptr<Symbol> value) {
        location_ = std::move(value);
        if (location_) {
            location_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> global_var_name_;
    std::unique_ptr<Symbol> location_;
};

class location_c final : public Symbol {
public:
    location_c() = default;
    location_c(std::unique_ptr<Symbol> direct_variable,
        SourceRange range = {})
        : Symbol(std::move(range)), direct_variable_(std::move(direct_variable)) {
        if (direct_variable_) {
            direct_variable_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "location_c"; }
    [[nodiscard]] Symbol* direct_variable() const noexcept { return direct_variable_.get(); }
    void set_direct_variable(std::unique_ptr<Symbol> value) {
        direct_variable_ = std::move(value);
        if (direct_variable_) {
            direct_variable_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> direct_variable_;
};

class global_var_list_c final : public List {
public:
    global_var_list_c() = default;
    explicit global_var_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_list_c"; }
};

class single_byte_string_var_declaration_c final : public Symbol {
public:
    single_byte_string_var_declaration_c() = default;
    single_byte_string_var_declaration_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> single_byte_string_spec = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), single_byte_string_spec_(std::move(single_byte_string_spec)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (single_byte_string_spec_) {
            single_byte_string_spec_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "single_byte_string_var_declaration_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* single_byte_string_spec() const noexcept { return single_byte_string_spec_.get(); }
    void set_single_byte_string_spec(std::unique_ptr<Symbol> value) {
        single_byte_string_spec_ = std::move(value);
        if (single_byte_string_spec_) {
            single_byte_string_spec_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> single_byte_string_spec_;
};

class single_byte_string_spec_c final : public Symbol {
public:
    single_byte_string_spec_c() = default;
    single_byte_string_spec_c(std::unique_ptr<Symbol> string_spec,
        std::unique_ptr<Symbol> single_byte_character_string = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), string_spec_(std::move(string_spec)), single_byte_character_string_(std::move(single_byte_character_string)) {
        if (string_spec_) {
            string_spec_->setParent(this);
        }
        if (single_byte_character_string_) {
            single_byte_character_string_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "single_byte_string_spec_c"; }
    [[nodiscard]] Symbol* string_spec() const noexcept { return string_spec_.get(); }
    void set_string_spec(std::unique_ptr<Symbol> value) {
        string_spec_ = std::move(value);
        if (string_spec_) {
            string_spec_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* single_byte_character_string() const noexcept { return single_byte_character_string_.get(); }
    void set_single_byte_character_string(std::unique_ptr<Symbol> value) {
        single_byte_character_string_ = std::move(value);
        if (single_byte_character_string_) {
            single_byte_character_string_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> string_spec_;
    std::unique_ptr<Symbol> single_byte_character_string_;
};

class single_byte_limited_len_string_spec_c final : public Symbol {
public:
    single_byte_limited_len_string_spec_c() = default;
    single_byte_limited_len_string_spec_c(std::unique_ptr<Symbol> string_type_name,
        std::unique_ptr<Symbol> character_string_len = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), string_type_name_(std::move(string_type_name)), character_string_len_(std::move(character_string_len)) {
        if (string_type_name_) {
            string_type_name_->setParent(this);
        }
        if (character_string_len_) {
            character_string_len_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "single_byte_limited_len_string_spec_c"; }
    [[nodiscard]] Symbol* string_type_name() const noexcept { return string_type_name_.get(); }
    void set_string_type_name(std::unique_ptr<Symbol> value) {
        string_type_name_ = std::move(value);
        if (string_type_name_) {
            string_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* character_string_len() const noexcept { return character_string_len_.get(); }
    void set_character_string_len(std::unique_ptr<Symbol> value) {
        character_string_len_ = std::move(value);
        if (character_string_len_) {
            character_string_len_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> string_type_name_;
    std::unique_ptr<Symbol> character_string_len_;
};

class double_byte_limited_len_string_spec_c final : public Symbol {
public:
    double_byte_limited_len_string_spec_c() = default;
    double_byte_limited_len_string_spec_c(std::unique_ptr<Symbol> string_type_name,
        std::unique_ptr<Symbol> character_string_len = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), string_type_name_(std::move(string_type_name)), character_string_len_(std::move(character_string_len)) {
        if (string_type_name_) {
            string_type_name_->setParent(this);
        }
        if (character_string_len_) {
            character_string_len_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "double_byte_limited_len_string_spec_c"; }
    [[nodiscard]] Symbol* string_type_name() const noexcept { return string_type_name_.get(); }
    void set_string_type_name(std::unique_ptr<Symbol> value) {
        string_type_name_ = std::move(value);
        if (string_type_name_) {
            string_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* character_string_len() const noexcept { return character_string_len_.get(); }
    void set_character_string_len(std::unique_ptr<Symbol> value) {
        character_string_len_ = std::move(value);
        if (character_string_len_) {
            character_string_len_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> string_type_name_;
    std::unique_ptr<Symbol> character_string_len_;
};

class double_byte_string_var_declaration_c final : public Symbol {
public:
    double_byte_string_var_declaration_c() = default;
    double_byte_string_var_declaration_c(std::unique_ptr<Symbol> var1_list,
        std::unique_ptr<Symbol> double_byte_string_spec = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), var1_list_(std::move(var1_list)), double_byte_string_spec_(std::move(double_byte_string_spec)) {
        if (var1_list_) {
            var1_list_->setParent(this);
        }
        if (double_byte_string_spec_) {
            double_byte_string_spec_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "double_byte_string_var_declaration_c"; }
    [[nodiscard]] Symbol* var1_list() const noexcept { return var1_list_.get(); }
    void set_var1_list(std::unique_ptr<Symbol> value) {
        var1_list_ = std::move(value);
        if (var1_list_) {
            var1_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* double_byte_string_spec() const noexcept { return double_byte_string_spec_.get(); }
    void set_double_byte_string_spec(std::unique_ptr<Symbol> value) {
        double_byte_string_spec_ = std::move(value);
        if (double_byte_string_spec_) {
            double_byte_string_spec_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var1_list_;
    std::unique_ptr<Symbol> double_byte_string_spec_;
};

class double_byte_string_spec_c final : public Symbol {
public:
    double_byte_string_spec_c() = default;
    double_byte_string_spec_c(std::unique_ptr<Symbol> string_spec,
        std::unique_ptr<Symbol> double_byte_character_string = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), string_spec_(std::move(string_spec)), double_byte_character_string_(std::move(double_byte_character_string)) {
        if (string_spec_) {
            string_spec_->setParent(this);
        }
        if (double_byte_character_string_) {
            double_byte_character_string_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "double_byte_string_spec_c"; }
    [[nodiscard]] Symbol* string_spec() const noexcept { return string_spec_.get(); }
    void set_string_spec(std::unique_ptr<Symbol> value) {
        string_spec_ = std::move(value);
        if (string_spec_) {
            string_spec_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* double_byte_character_string() const noexcept { return double_byte_character_string_.get(); }
    void set_double_byte_character_string(std::unique_ptr<Symbol> value) {
        double_byte_character_string_ = std::move(value);
        if (double_byte_character_string_) {
            double_byte_character_string_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> string_spec_;
    std::unique_ptr<Symbol> double_byte_character_string_;
};

class incompl_located_var_declarations_c final : public Symbol {
public:
    incompl_located_var_declarations_c() = default;
    incompl_located_var_declarations_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> incompl_located_var_decl_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), incompl_located_var_decl_list_(std::move(incompl_located_var_decl_list)) {
        if (option_) {
            option_->setParent(this);
        }
        if (incompl_located_var_decl_list_) {
            incompl_located_var_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "incompl_located_var_declarations_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* incompl_located_var_decl_list() const noexcept { return incompl_located_var_decl_list_.get(); }
    void set_incompl_located_var_decl_list(std::unique_ptr<Symbol> value) {
        incompl_located_var_decl_list_ = std::move(value);
        if (incompl_located_var_decl_list_) {
            incompl_located_var_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> incompl_located_var_decl_list_;
};

class incompl_located_var_decl_list_c final : public List {
public:
    incompl_located_var_decl_list_c() = default;
    explicit incompl_located_var_decl_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "incompl_located_var_decl_list_c"; }
};

class incompl_located_var_decl_c final : public Symbol {
public:
    incompl_located_var_decl_c() = default;
    incompl_located_var_decl_c(std::unique_ptr<Symbol> variable_name,
        std::unique_ptr<Symbol> incompl_location,
        std::unique_ptr<Symbol> var_spec,
        SourceRange range = {})
        : Symbol(std::move(range)), variable_name_(std::move(variable_name)), incompl_location_(std::move(incompl_location)), var_spec_(std::move(var_spec)) {
        if (variable_name_) {
            variable_name_->setParent(this);
        }
        if (incompl_location_) {
            incompl_location_->setParent(this);
        }
        if (var_spec_) {
            var_spec_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "incompl_located_var_decl_c"; }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* incompl_location() const noexcept { return incompl_location_.get(); }
    void set_incompl_location(std::unique_ptr<Symbol> value) {
        incompl_location_ = std::move(value);
        if (incompl_location_) {
            incompl_location_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var_spec() const noexcept { return var_spec_.get(); }
    void set_var_spec(std::unique_ptr<Symbol> value) {
        var_spec_ = std::move(value);
        if (var_spec_) {
            var_spec_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> variable_name_;
    std::unique_ptr<Symbol> incompl_location_;
    std::unique_ptr<Symbol> var_spec_;
};

class incompl_location_c final : public Token {
public:
    incompl_location_c() = default;
    explicit incompl_location_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "incompl_location_c"; }
};

class var_init_decl_list_c final : public List {
public:
    var_init_decl_list_c() = default;
    explicit var_init_decl_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var_init_decl_list_c"; }
};

class function_declaration_c final : public Symbol {
public:
    function_declaration_c() = default;
    function_declaration_c(std::unique_ptr<Symbol> derived_function_name,
        std::unique_ptr<Symbol> type_name,
        std::unique_ptr<Symbol> var_declarations_list,
        std::unique_ptr<Symbol> function_body = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), derived_function_name_(std::move(derived_function_name)), type_name_(std::move(type_name)), var_declarations_list_(std::move(var_declarations_list)), function_body_(std::move(function_body)) {
        if (derived_function_name_) {
            derived_function_name_->setParent(this);
        }
        if (type_name_) {
            type_name_->setParent(this);
        }
        if (var_declarations_list_) {
            var_declarations_list_->setParent(this);
        }
        if (function_body_) {
            function_body_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "function_declaration_c"; }
    [[nodiscard]] Symbol* derived_function_name() const noexcept { return derived_function_name_.get(); }
    void set_derived_function_name(std::unique_ptr<Symbol> value) {
        derived_function_name_ = std::move(value);
        if (derived_function_name_) {
            derived_function_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* type_name() const noexcept { return type_name_.get(); }
    void set_type_name(std::unique_ptr<Symbol> value) {
        type_name_ = std::move(value);
        if (type_name_) {
            type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var_declarations_list() const noexcept { return var_declarations_list_.get(); }
    void set_var_declarations_list(std::unique_ptr<Symbol> value) {
        var_declarations_list_ = std::move(value);
        if (var_declarations_list_) {
            var_declarations_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* function_body() const noexcept { return function_body_.get(); }
    void set_function_body(std::unique_ptr<Symbol> value) {
        function_body_ = std::move(value);
        if (function_body_) {
            function_body_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> derived_function_name_;
    std::unique_ptr<Symbol> type_name_;
    std::unique_ptr<Symbol> var_declarations_list_;
    std::unique_ptr<Symbol> function_body_;
};

class var_declarations_list_c final : public List {
public:
    var_declarations_list_c() = default;
    explicit var_declarations_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var_declarations_list_c"; }
};

class function_var_decls_c final : public Symbol {
public:
    function_var_decls_c() = default;
    function_var_decls_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> decl_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), decl_list_(std::move(decl_list)) {
        if (option_) {
            option_->setParent(this);
        }
        if (decl_list_) {
            decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "function_var_decls_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* decl_list() const noexcept { return decl_list_.get(); }
    void set_decl_list(std::unique_ptr<Symbol> value) {
        decl_list_ = std::move(value);
        if (decl_list_) {
            decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> decl_list_;
};

class var2_init_decl_list_c final : public List {
public:
    var2_init_decl_list_c() = default;
    explicit var2_init_decl_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "var2_init_decl_list_c"; }
};

class function_block_declaration_c final : public Symbol {
public:
    function_block_declaration_c() = default;
    function_block_declaration_c(std::unique_ptr<Symbol> fblock_name,
        std::unique_ptr<Symbol> var_declarations,
        std::unique_ptr<Symbol> fblock_body,
        SourceRange range = {})
        : Symbol(std::move(range)), fblock_name_(std::move(fblock_name)), var_declarations_(std::move(var_declarations)), fblock_body_(std::move(fblock_body)) {
        if (fblock_name_) {
            fblock_name_->setParent(this);
        }
        if (var_declarations_) {
            var_declarations_->setParent(this);
        }
        if (fblock_body_) {
            fblock_body_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "function_block_declaration_c"; }
    [[nodiscard]] Symbol* fblock_name() const noexcept { return fblock_name_.get(); }
    void set_fblock_name(std::unique_ptr<Symbol> value) {
        fblock_name_ = std::move(value);
        if (fblock_name_) {
            fblock_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var_declarations() const noexcept { return var_declarations_.get(); }
    void set_var_declarations(std::unique_ptr<Symbol> value) {
        var_declarations_ = std::move(value);
        if (var_declarations_) {
            var_declarations_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* fblock_body() const noexcept { return fblock_body_.get(); }
    void set_fblock_body(std::unique_ptr<Symbol> value) {
        fblock_body_ = std::move(value);
        if (fblock_body_) {
            fblock_body_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> fblock_name_;
    std::unique_ptr<Symbol> var_declarations_;
    std::unique_ptr<Symbol> fblock_body_;
};

class temp_var_decls_c final : public Symbol {
public:
    temp_var_decls_c() = default;
    temp_var_decls_c(std::unique_ptr<Symbol> var_decl_list,
        SourceRange range = {})
        : Symbol(std::move(range)), var_decl_list_(std::move(var_decl_list)) {
        if (var_decl_list_) {
            var_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "temp_var_decls_c"; }
    [[nodiscard]] Symbol* var_decl_list() const noexcept { return var_decl_list_.get(); }
    void set_var_decl_list(std::unique_ptr<Symbol> value) {
        var_decl_list_ = std::move(value);
        if (var_decl_list_) {
            var_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_decl_list_;
};

class temp_var_decls_list_c final : public List {
public:
    temp_var_decls_list_c() = default;
    explicit temp_var_decls_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "temp_var_decls_list_c"; }
};

class non_retentive_var_decls_c final : public Symbol {
public:
    non_retentive_var_decls_c() = default;
    non_retentive_var_decls_c(std::unique_ptr<Symbol> var_decl_list,
        SourceRange range = {})
        : Symbol(std::move(range)), var_decl_list_(std::move(var_decl_list)) {
        if (var_decl_list_) {
            var_decl_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "non_retentive_var_decls_c"; }
    [[nodiscard]] Symbol* var_decl_list() const noexcept { return var_decl_list_.get(); }
    void set_var_decl_list(std::unique_ptr<Symbol> value) {
        var_decl_list_ = std::move(value);
        if (var_decl_list_) {
            var_decl_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> var_decl_list_;
};

class program_declaration_c final : public Symbol {
public:
    program_declaration_c() = default;
    program_declaration_c(std::unique_ptr<Symbol> program_type_name,
        std::unique_ptr<Symbol> var_declarations,
        std::unique_ptr<Symbol> function_block_body,
        SourceRange range = {})
        : Symbol(std::move(range)), program_type_name_(std::move(program_type_name)), var_declarations_(std::move(var_declarations)), function_block_body_(std::move(function_block_body)) {
        if (program_type_name_) {
            program_type_name_->setParent(this);
        }
        if (var_declarations_) {
            var_declarations_->setParent(this);
        }
        if (function_block_body_) {
            function_block_body_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "program_declaration_c"; }
    [[nodiscard]] Symbol* program_type_name() const noexcept { return program_type_name_.get(); }
    void set_program_type_name(std::unique_ptr<Symbol> value) {
        program_type_name_ = std::move(value);
        if (program_type_name_) {
            program_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* var_declarations() const noexcept { return var_declarations_.get(); }
    void set_var_declarations(std::unique_ptr<Symbol> value) {
        var_declarations_ = std::move(value);
        if (var_declarations_) {
            var_declarations_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* function_block_body() const noexcept { return function_block_body_.get(); }
    void set_function_block_body(std::unique_ptr<Symbol> value) {
        function_block_body_ = std::move(value);
        if (function_block_body_) {
            function_block_body_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> program_type_name_;
    std::unique_ptr<Symbol> var_declarations_;
    std::unique_ptr<Symbol> function_block_body_;
};

class sequential_function_chart_c final : public List {
public:
    sequential_function_chart_c() = default;
    explicit sequential_function_chart_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "sequential_function_chart_c"; }
};

class sfc_network_c final : public List {
public:
    sfc_network_c() = default;
    explicit sfc_network_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "sfc_network_c"; }
};

class initial_step_c final : public Symbol {
public:
    initial_step_c() = default;
    initial_step_c(std::unique_ptr<Symbol> step_name,
        std::unique_ptr<Symbol> action_association_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), step_name_(std::move(step_name)), action_association_list_(std::move(action_association_list)) {
        if (step_name_) {
            step_name_->setParent(this);
        }
        if (action_association_list_) {
            action_association_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "initial_step_c"; }
    [[nodiscard]] Symbol* step_name() const noexcept { return step_name_.get(); }
    void set_step_name(std::unique_ptr<Symbol> value) {
        step_name_ = std::move(value);
        if (step_name_) {
            step_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* action_association_list() const noexcept { return action_association_list_.get(); }
    void set_action_association_list(std::unique_ptr<Symbol> value) {
        action_association_list_ = std::move(value);
        if (action_association_list_) {
            action_association_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> step_name_;
    std::unique_ptr<Symbol> action_association_list_;
};

class action_association_list_c final : public List {
public:
    action_association_list_c() = default;
    explicit action_association_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "action_association_list_c"; }
};

class step_c final : public Symbol {
public:
    step_c() = default;
    step_c(std::unique_ptr<Symbol> step_name,
        std::unique_ptr<Symbol> action_association_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), step_name_(std::move(step_name)), action_association_list_(std::move(action_association_list)) {
        if (step_name_) {
            step_name_->setParent(this);
        }
        if (action_association_list_) {
            action_association_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "step_c"; }
    [[nodiscard]] Symbol* step_name() const noexcept { return step_name_.get(); }
    void set_step_name(std::unique_ptr<Symbol> value) {
        step_name_ = std::move(value);
        if (step_name_) {
            step_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* action_association_list() const noexcept { return action_association_list_.get(); }
    void set_action_association_list(std::unique_ptr<Symbol> value) {
        action_association_list_ = std::move(value);
        if (action_association_list_) {
            action_association_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> step_name_;
    std::unique_ptr<Symbol> action_association_list_;
};

class action_association_c final : public Symbol {
public:
    action_association_c() = default;
    action_association_c(std::unique_ptr<Symbol> action_name,
        std::unique_ptr<Symbol> action_qualifier,
        std::unique_ptr<Symbol> indicator_name_list,
        SourceRange range = {})
        : Symbol(std::move(range)), action_name_(std::move(action_name)), action_qualifier_(std::move(action_qualifier)), indicator_name_list_(std::move(indicator_name_list)) {
        if (action_name_) {
            action_name_->setParent(this);
        }
        if (action_qualifier_) {
            action_qualifier_->setParent(this);
        }
        if (indicator_name_list_) {
            indicator_name_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "action_association_c"; }
    [[nodiscard]] Symbol* action_name() const noexcept { return action_name_.get(); }
    void set_action_name(std::unique_ptr<Symbol> value) {
        action_name_ = std::move(value);
        if (action_name_) {
            action_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* action_qualifier() const noexcept { return action_qualifier_.get(); }
    void set_action_qualifier(std::unique_ptr<Symbol> value) {
        action_qualifier_ = std::move(value);
        if (action_qualifier_) {
            action_qualifier_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* indicator_name_list() const noexcept { return indicator_name_list_.get(); }
    void set_indicator_name_list(std::unique_ptr<Symbol> value) {
        indicator_name_list_ = std::move(value);
        if (indicator_name_list_) {
            indicator_name_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> action_name_;
    std::unique_ptr<Symbol> action_qualifier_;
    std::unique_ptr<Symbol> indicator_name_list_;
};

class qualifier_c final : public Token {
public:
    qualifier_c() = default;
    explicit qualifier_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "qualifier_c"; }
};

class timed_qualifier_c final : public Token {
public:
    timed_qualifier_c() = default;
    explicit timed_qualifier_c(std::string value, SourceRange range = {})
        : Token(std::move(value), std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "timed_qualifier_c"; }
};

class indicator_name_list_c final : public List {
public:
    indicator_name_list_c() = default;
    explicit indicator_name_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "indicator_name_list_c"; }
};

class action_qualifier_c final : public Symbol {
public:
    action_qualifier_c() = default;
    action_qualifier_c(std::unique_ptr<Symbol> action_qualifier,
        std::unique_ptr<Symbol> action_time = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), action_qualifier_(std::move(action_qualifier)), action_time_(std::move(action_time)) {
        if (action_qualifier_) {
            action_qualifier_->setParent(this);
        }
        if (action_time_) {
            action_time_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "action_qualifier_c"; }
    [[nodiscard]] Symbol* action_qualifier() const noexcept { return action_qualifier_.get(); }
    void set_action_qualifier(std::unique_ptr<Symbol> value) {
        action_qualifier_ = std::move(value);
        if (action_qualifier_) {
            action_qualifier_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* action_time() const noexcept { return action_time_.get(); }
    void set_action_time(std::unique_ptr<Symbol> value) {
        action_time_ = std::move(value);
        if (action_time_) {
            action_time_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> action_qualifier_;
    std::unique_ptr<Symbol> action_time_;
};

class transition_c final : public Symbol {
public:
    transition_c() = default;
    transition_c(std::unique_ptr<Symbol> transition_name,
        std::unique_ptr<Symbol> integer,
        std::unique_ptr<Symbol> from_steps,
        std::unique_ptr<Symbol> to_steps,
        std::unique_ptr<Symbol> transition_condition,
        SourceRange range = {})
        : Symbol(std::move(range)), transition_name_(std::move(transition_name)), integer_(std::move(integer)), from_steps_(std::move(from_steps)), to_steps_(std::move(to_steps)), transition_condition_(std::move(transition_condition)) {
        if (transition_name_) {
            transition_name_->setParent(this);
        }
        if (integer_) {
            integer_->setParent(this);
        }
        if (from_steps_) {
            from_steps_->setParent(this);
        }
        if (to_steps_) {
            to_steps_->setParent(this);
        }
        if (transition_condition_) {
            transition_condition_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "transition_c"; }
    [[nodiscard]] Symbol* transition_name() const noexcept { return transition_name_.get(); }
    void set_transition_name(std::unique_ptr<Symbol> value) {
        transition_name_ = std::move(value);
        if (transition_name_) {
            transition_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* integer() const noexcept { return integer_.get(); }
    void set_integer(std::unique_ptr<Symbol> value) {
        integer_ = std::move(value);
        if (integer_) {
            integer_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* from_steps() const noexcept { return from_steps_.get(); }
    void set_from_steps(std::unique_ptr<Symbol> value) {
        from_steps_ = std::move(value);
        if (from_steps_) {
            from_steps_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* to_steps() const noexcept { return to_steps_.get(); }
    void set_to_steps(std::unique_ptr<Symbol> value) {
        to_steps_ = std::move(value);
        if (to_steps_) {
            to_steps_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* transition_condition() const noexcept { return transition_condition_.get(); }
    void set_transition_condition(std::unique_ptr<Symbol> value) {
        transition_condition_ = std::move(value);
        if (transition_condition_) {
            transition_condition_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> transition_name_;
    std::unique_ptr<Symbol> integer_;
    std::unique_ptr<Symbol> from_steps_;
    std::unique_ptr<Symbol> to_steps_;
    std::unique_ptr<Symbol> transition_condition_;
};

class transition_condition_c final : public Symbol {
public:
    transition_condition_c() = default;
    transition_condition_c(std::unique_ptr<Symbol> transition_condition_il,
        std::unique_ptr<Symbol> transition_condition_st = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), transition_condition_il_(std::move(transition_condition_il)), transition_condition_st_(std::move(transition_condition_st)) {
        if (transition_condition_il_) {
            transition_condition_il_->setParent(this);
        }
        if (transition_condition_st_) {
            transition_condition_st_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "transition_condition_c"; }
    [[nodiscard]] Symbol* transition_condition_il() const noexcept { return transition_condition_il_.get(); }
    void set_transition_condition_il(std::unique_ptr<Symbol> value) {
        transition_condition_il_ = std::move(value);
        if (transition_condition_il_) {
            transition_condition_il_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* transition_condition_st() const noexcept { return transition_condition_st_.get(); }
    void set_transition_condition_st(std::unique_ptr<Symbol> value) {
        transition_condition_st_ = std::move(value);
        if (transition_condition_st_) {
            transition_condition_st_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> transition_condition_il_;
    std::unique_ptr<Symbol> transition_condition_st_;
};

class steps_c final : public Symbol {
public:
    steps_c() = default;
    steps_c(std::unique_ptr<Symbol> step_name,
        std::unique_ptr<Symbol> step_name_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), step_name_(std::move(step_name)), step_name_list_(std::move(step_name_list)) {
        if (step_name_) {
            step_name_->setParent(this);
        }
        if (step_name_list_) {
            step_name_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "steps_c"; }
    [[nodiscard]] Symbol* step_name() const noexcept { return step_name_.get(); }
    void set_step_name(std::unique_ptr<Symbol> value) {
        step_name_ = std::move(value);
        if (step_name_) {
            step_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* step_name_list() const noexcept { return step_name_list_.get(); }
    void set_step_name_list(std::unique_ptr<Symbol> value) {
        step_name_list_ = std::move(value);
        if (step_name_list_) {
            step_name_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> step_name_;
    std::unique_ptr<Symbol> step_name_list_;
};

class step_name_list_c final : public List {
public:
    step_name_list_c() = default;
    explicit step_name_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "step_name_list_c"; }
};

class action_c final : public Symbol {
public:
    action_c() = default;
    action_c(std::unique_ptr<Symbol> action_name,
        std::unique_ptr<Symbol> function_block_body = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), action_name_(std::move(action_name)), function_block_body_(std::move(function_block_body)) {
        if (action_name_) {
            action_name_->setParent(this);
        }
        if (function_block_body_) {
            function_block_body_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "action_c"; }
    [[nodiscard]] Symbol* action_name() const noexcept { return action_name_.get(); }
    void set_action_name(std::unique_ptr<Symbol> value) {
        action_name_ = std::move(value);
        if (action_name_) {
            action_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* function_block_body() const noexcept { return function_block_body_.get(); }
    void set_function_block_body(std::unique_ptr<Symbol> value) {
        function_block_body_ = std::move(value);
        if (function_block_body_) {
            function_block_body_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> action_name_;
    std::unique_ptr<Symbol> function_block_body_;
};

class configuration_declaration_c final : public Symbol {
public:
    configuration_declaration_c() = default;
    configuration_declaration_c(std::unique_ptr<Symbol> configuration_name,
        std::unique_ptr<Symbol> global_var_declarations,
        std::unique_ptr<Symbol> resource_declarations,
        std::unique_ptr<Symbol> access_declarations,
        std::unique_ptr<Symbol> instance_specific_initializations,
        SourceRange range = {})
        : Symbol(std::move(range)), configuration_name_(std::move(configuration_name)), global_var_declarations_(std::move(global_var_declarations)), resource_declarations_(std::move(resource_declarations)), access_declarations_(std::move(access_declarations)), instance_specific_initializations_(std::move(instance_specific_initializations)) {
        if (configuration_name_) {
            configuration_name_->setParent(this);
        }
        if (global_var_declarations_) {
            global_var_declarations_->setParent(this);
        }
        if (resource_declarations_) {
            resource_declarations_->setParent(this);
        }
        if (access_declarations_) {
            access_declarations_->setParent(this);
        }
        if (instance_specific_initializations_) {
            instance_specific_initializations_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "configuration_declaration_c"; }
    [[nodiscard]] Symbol* configuration_name() const noexcept { return configuration_name_.get(); }
    void set_configuration_name(std::unique_ptr<Symbol> value) {
        configuration_name_ = std::move(value);
        if (configuration_name_) {
            configuration_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* global_var_declarations() const noexcept { return global_var_declarations_.get(); }
    void set_global_var_declarations(std::unique_ptr<Symbol> value) {
        global_var_declarations_ = std::move(value);
        if (global_var_declarations_) {
            global_var_declarations_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* resource_declarations() const noexcept { return resource_declarations_.get(); }
    void set_resource_declarations(std::unique_ptr<Symbol> value) {
        resource_declarations_ = std::move(value);
        if (resource_declarations_) {
            resource_declarations_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* access_declarations() const noexcept { return access_declarations_.get(); }
    void set_access_declarations(std::unique_ptr<Symbol> value) {
        access_declarations_ = std::move(value);
        if (access_declarations_) {
            access_declarations_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* instance_specific_initializations() const noexcept { return instance_specific_initializations_.get(); }
    void set_instance_specific_initializations(std::unique_ptr<Symbol> value) {
        instance_specific_initializations_ = std::move(value);
        if (instance_specific_initializations_) {
            instance_specific_initializations_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> configuration_name_;
    std::unique_ptr<Symbol> global_var_declarations_;
    std::unique_ptr<Symbol> resource_declarations_;
    std::unique_ptr<Symbol> access_declarations_;
    std::unique_ptr<Symbol> instance_specific_initializations_;
};

class global_var_declarations_list_c final : public List {
public:
    global_var_declarations_list_c() = default;
    explicit global_var_declarations_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_declarations_list_c"; }
};

class resource_declaration_list_c final : public List {
public:
    resource_declaration_list_c() = default;
    explicit resource_declaration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "resource_declaration_list_c"; }
};

class resource_declaration_c final : public Symbol {
public:
    resource_declaration_c() = default;
    resource_declaration_c(std::unique_ptr<Symbol> resource_name,
        std::unique_ptr<Symbol> resource_type_name,
        std::unique_ptr<Symbol> global_var_declarations,
        std::unique_ptr<Symbol> resource_declaration = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), resource_name_(std::move(resource_name)), resource_type_name_(std::move(resource_type_name)), global_var_declarations_(std::move(global_var_declarations)), resource_declaration_(std::move(resource_declaration)) {
        if (resource_name_) {
            resource_name_->setParent(this);
        }
        if (resource_type_name_) {
            resource_type_name_->setParent(this);
        }
        if (global_var_declarations_) {
            global_var_declarations_->setParent(this);
        }
        if (resource_declaration_) {
            resource_declaration_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "resource_declaration_c"; }
    [[nodiscard]] Symbol* resource_name() const noexcept { return resource_name_.get(); }
    void set_resource_name(std::unique_ptr<Symbol> value) {
        resource_name_ = std::move(value);
        if (resource_name_) {
            resource_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* resource_type_name() const noexcept { return resource_type_name_.get(); }
    void set_resource_type_name(std::unique_ptr<Symbol> value) {
        resource_type_name_ = std::move(value);
        if (resource_type_name_) {
            resource_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* global_var_declarations() const noexcept { return global_var_declarations_.get(); }
    void set_global_var_declarations(std::unique_ptr<Symbol> value) {
        global_var_declarations_ = std::move(value);
        if (global_var_declarations_) {
            global_var_declarations_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* resource_declaration() const noexcept { return resource_declaration_.get(); }
    void set_resource_declaration(std::unique_ptr<Symbol> value) {
        resource_declaration_ = std::move(value);
        if (resource_declaration_) {
            resource_declaration_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> resource_name_;
    std::unique_ptr<Symbol> resource_type_name_;
    std::unique_ptr<Symbol> global_var_declarations_;
    std::unique_ptr<Symbol> resource_declaration_;
};

class single_resource_declaration_c final : public Symbol {
public:
    single_resource_declaration_c() = default;
    single_resource_declaration_c(std::unique_ptr<Symbol> task_configuration_list,
        std::unique_ptr<Symbol> program_configuration_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), task_configuration_list_(std::move(task_configuration_list)), program_configuration_list_(std::move(program_configuration_list)) {
        if (task_configuration_list_) {
            task_configuration_list_->setParent(this);
        }
        if (program_configuration_list_) {
            program_configuration_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "single_resource_declaration_c"; }
    [[nodiscard]] Symbol* task_configuration_list() const noexcept { return task_configuration_list_.get(); }
    void set_task_configuration_list(std::unique_ptr<Symbol> value) {
        task_configuration_list_ = std::move(value);
        if (task_configuration_list_) {
            task_configuration_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* program_configuration_list() const noexcept { return program_configuration_list_.get(); }
    void set_program_configuration_list(std::unique_ptr<Symbol> value) {
        program_configuration_list_ = std::move(value);
        if (program_configuration_list_) {
            program_configuration_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> task_configuration_list_;
    std::unique_ptr<Symbol> program_configuration_list_;
};

class task_configuration_list_c final : public List {
public:
    task_configuration_list_c() = default;
    explicit task_configuration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "task_configuration_list_c"; }
};

class program_configuration_list_c final : public List {
public:
    program_configuration_list_c() = default;
    explicit program_configuration_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "program_configuration_list_c"; }
};

class any_fb_name_list_c final : public List {
public:
    any_fb_name_list_c() = default;
    explicit any_fb_name_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "any_fb_name_list_c"; }
};

class global_var_reference_c final : public Symbol {
public:
    global_var_reference_c() = default;
    global_var_reference_c(std::unique_ptr<Symbol> resource_name,
        std::unique_ptr<Symbol> global_var_name,
        std::unique_ptr<Symbol> structure_element_name,
        SourceRange range = {})
        : Symbol(std::move(range)), resource_name_(std::move(resource_name)), global_var_name_(std::move(global_var_name)), structure_element_name_(std::move(structure_element_name)) {
        if (resource_name_) {
            resource_name_->setParent(this);
        }
        if (global_var_name_) {
            global_var_name_->setParent(this);
        }
        if (structure_element_name_) {
            structure_element_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "global_var_reference_c"; }
    [[nodiscard]] Symbol* resource_name() const noexcept { return resource_name_.get(); }
    void set_resource_name(std::unique_ptr<Symbol> value) {
        resource_name_ = std::move(value);
        if (resource_name_) {
            resource_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* global_var_name() const noexcept { return global_var_name_.get(); }
    void set_global_var_name(std::unique_ptr<Symbol> value) {
        global_var_name_ = std::move(value);
        if (global_var_name_) {
            global_var_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* structure_element_name() const noexcept { return structure_element_name_.get(); }
    void set_structure_element_name(std::unique_ptr<Symbol> value) {
        structure_element_name_ = std::move(value);
        if (structure_element_name_) {
            structure_element_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> resource_name_;
    std::unique_ptr<Symbol> global_var_name_;
    std::unique_ptr<Symbol> structure_element_name_;
};

class program_output_reference_c final : public Symbol {
public:
    program_output_reference_c() = default;
    program_output_reference_c(std::unique_ptr<Symbol> program_name,
        std::unique_ptr<Symbol> symbolic_variable = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), program_name_(std::move(program_name)), symbolic_variable_(std::move(symbolic_variable)) {
        if (program_name_) {
            program_name_->setParent(this);
        }
        if (symbolic_variable_) {
            symbolic_variable_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "program_output_reference_c"; }
    [[nodiscard]] Symbol* program_name() const noexcept { return program_name_.get(); }
    void set_program_name(std::unique_ptr<Symbol> value) {
        program_name_ = std::move(value);
        if (program_name_) {
            program_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* symbolic_variable() const noexcept { return symbolic_variable_.get(); }
    void set_symbolic_variable(std::unique_ptr<Symbol> value) {
        symbolic_variable_ = std::move(value);
        if (symbolic_variable_) {
            symbolic_variable_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> program_name_;
    std::unique_ptr<Symbol> symbolic_variable_;
};

class task_configuration_c final : public Symbol {
public:
    task_configuration_c() = default;
    task_configuration_c(std::unique_ptr<Symbol> task_name,
        std::unique_ptr<Symbol> task_initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), task_name_(std::move(task_name)), task_initialization_(std::move(task_initialization)) {
        if (task_name_) {
            task_name_->setParent(this);
        }
        if (task_initialization_) {
            task_initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "task_configuration_c"; }
    [[nodiscard]] Symbol* task_name() const noexcept { return task_name_.get(); }
    void set_task_name(std::unique_ptr<Symbol> value) {
        task_name_ = std::move(value);
        if (task_name_) {
            task_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* task_initialization() const noexcept { return task_initialization_.get(); }
    void set_task_initialization(std::unique_ptr<Symbol> value) {
        task_initialization_ = std::move(value);
        if (task_initialization_) {
            task_initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> task_name_;
    std::unique_ptr<Symbol> task_initialization_;
};

class task_initialization_c final : public Symbol {
public:
    task_initialization_c() = default;
    task_initialization_c(std::unique_ptr<Symbol> single_data_source,
        std::unique_ptr<Symbol> interval_data_source,
        std::unique_ptr<Symbol> priority_data_source,
        SourceRange range = {})
        : Symbol(std::move(range)), single_data_source_(std::move(single_data_source)), interval_data_source_(std::move(interval_data_source)), priority_data_source_(std::move(priority_data_source)) {
        if (single_data_source_) {
            single_data_source_->setParent(this);
        }
        if (interval_data_source_) {
            interval_data_source_->setParent(this);
        }
        if (priority_data_source_) {
            priority_data_source_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "task_initialization_c"; }
    [[nodiscard]] Symbol* single_data_source() const noexcept { return single_data_source_.get(); }
    void set_single_data_source(std::unique_ptr<Symbol> value) {
        single_data_source_ = std::move(value);
        if (single_data_source_) {
            single_data_source_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* interval_data_source() const noexcept { return interval_data_source_.get(); }
    void set_interval_data_source(std::unique_ptr<Symbol> value) {
        interval_data_source_ = std::move(value);
        if (interval_data_source_) {
            interval_data_source_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* priority_data_source() const noexcept { return priority_data_source_.get(); }
    void set_priority_data_source(std::unique_ptr<Symbol> value) {
        priority_data_source_ = std::move(value);
        if (priority_data_source_) {
            priority_data_source_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> single_data_source_;
    std::unique_ptr<Symbol> interval_data_source_;
    std::unique_ptr<Symbol> priority_data_source_;
};

class program_configuration_c final : public Symbol {
public:
    program_configuration_c() = default;
    program_configuration_c(std::unique_ptr<Symbol> retain_option,
        std::unique_ptr<Symbol> program_name,
        std::unique_ptr<Symbol> task_name,
        std::unique_ptr<Symbol> program_type_name,
        std::unique_ptr<Symbol> prog_conf_elements,
        SourceRange range = {})
        : Symbol(std::move(range)), retain_option_(std::move(retain_option)), program_name_(std::move(program_name)), task_name_(std::move(task_name)), program_type_name_(std::move(program_type_name)), prog_conf_elements_(std::move(prog_conf_elements)) {
        if (retain_option_) {
            retain_option_->setParent(this);
        }
        if (program_name_) {
            program_name_->setParent(this);
        }
        if (task_name_) {
            task_name_->setParent(this);
        }
        if (program_type_name_) {
            program_type_name_->setParent(this);
        }
        if (prog_conf_elements_) {
            prog_conf_elements_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "program_configuration_c"; }
    [[nodiscard]] Symbol* retain_option() const noexcept { return retain_option_.get(); }
    void set_retain_option(std::unique_ptr<Symbol> value) {
        retain_option_ = std::move(value);
        if (retain_option_) {
            retain_option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* program_name() const noexcept { return program_name_.get(); }
    void set_program_name(std::unique_ptr<Symbol> value) {
        program_name_ = std::move(value);
        if (program_name_) {
            program_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* task_name() const noexcept { return task_name_.get(); }
    void set_task_name(std::unique_ptr<Symbol> value) {
        task_name_ = std::move(value);
        if (task_name_) {
            task_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* program_type_name() const noexcept { return program_type_name_.get(); }
    void set_program_type_name(std::unique_ptr<Symbol> value) {
        program_type_name_ = std::move(value);
        if (program_type_name_) {
            program_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* prog_conf_elements() const noexcept { return prog_conf_elements_.get(); }
    void set_prog_conf_elements(std::unique_ptr<Symbol> value) {
        prog_conf_elements_ = std::move(value);
        if (prog_conf_elements_) {
            prog_conf_elements_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> retain_option_;
    std::unique_ptr<Symbol> program_name_;
    std::unique_ptr<Symbol> task_name_;
    std::unique_ptr<Symbol> program_type_name_;
    std::unique_ptr<Symbol> prog_conf_elements_;
};

class prog_conf_elements_c final : public List {
public:
    prog_conf_elements_c() = default;
    explicit prog_conf_elements_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "prog_conf_elements_c"; }
};

class fb_task_c final : public Symbol {
public:
    fb_task_c() = default;
    fb_task_c(std::unique_ptr<Symbol> fb_name,
        std::unique_ptr<Symbol> task_name = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), fb_name_(std::move(fb_name)), task_name_(std::move(task_name)) {
        if (fb_name_) {
            fb_name_->setParent(this);
        }
        if (task_name_) {
            task_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fb_task_c"; }
    [[nodiscard]] Symbol* fb_name() const noexcept { return fb_name_.get(); }
    void set_fb_name(std::unique_ptr<Symbol> value) {
        fb_name_ = std::move(value);
        if (fb_name_) {
            fb_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* task_name() const noexcept { return task_name_.get(); }
    void set_task_name(std::unique_ptr<Symbol> value) {
        task_name_ = std::move(value);
        if (task_name_) {
            task_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> fb_name_;
    std::unique_ptr<Symbol> task_name_;
};

class prog_cnxn_assign_c final : public Symbol {
public:
    prog_cnxn_assign_c() = default;
    prog_cnxn_assign_c(std::unique_ptr<Symbol> symbolic_variable,
        std::unique_ptr<Symbol> prog_data_source = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), symbolic_variable_(std::move(symbolic_variable)), prog_data_source_(std::move(prog_data_source)) {
        if (symbolic_variable_) {
            symbolic_variable_->setParent(this);
        }
        if (prog_data_source_) {
            prog_data_source_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "prog_cnxn_assign_c"; }
    [[nodiscard]] Symbol* symbolic_variable() const noexcept { return symbolic_variable_.get(); }
    void set_symbolic_variable(std::unique_ptr<Symbol> value) {
        symbolic_variable_ = std::move(value);
        if (symbolic_variable_) {
            symbolic_variable_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* prog_data_source() const noexcept { return prog_data_source_.get(); }
    void set_prog_data_source(std::unique_ptr<Symbol> value) {
        prog_data_source_ = std::move(value);
        if (prog_data_source_) {
            prog_data_source_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> symbolic_variable_;
    std::unique_ptr<Symbol> prog_data_source_;
};

class prog_cnxn_sendto_c final : public Symbol {
public:
    prog_cnxn_sendto_c() = default;
    prog_cnxn_sendto_c(std::unique_ptr<Symbol> symbolic_variable,
        std::unique_ptr<Symbol> data_sink = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), symbolic_variable_(std::move(symbolic_variable)), data_sink_(std::move(data_sink)) {
        if (symbolic_variable_) {
            symbolic_variable_->setParent(this);
        }
        if (data_sink_) {
            data_sink_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "prog_cnxn_sendto_c"; }
    [[nodiscard]] Symbol* symbolic_variable() const noexcept { return symbolic_variable_.get(); }
    void set_symbolic_variable(std::unique_ptr<Symbol> value) {
        symbolic_variable_ = std::move(value);
        if (symbolic_variable_) {
            symbolic_variable_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* data_sink() const noexcept { return data_sink_.get(); }
    void set_data_sink(std::unique_ptr<Symbol> value) {
        data_sink_ = std::move(value);
        if (data_sink_) {
            data_sink_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> symbolic_variable_;
    std::unique_ptr<Symbol> data_sink_;
};

class instance_specific_initializations_c final : public Symbol {
public:
    instance_specific_initializations_c() = default;
    instance_specific_initializations_c(std::unique_ptr<Symbol> instance_specific_init_list,
        SourceRange range = {})
        : Symbol(std::move(range)), instance_specific_init_list_(std::move(instance_specific_init_list)) {
        if (instance_specific_init_list_) {
            instance_specific_init_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "instance_specific_initializations_c"; }
    [[nodiscard]] Symbol* instance_specific_init_list() const noexcept { return instance_specific_init_list_.get(); }
    void set_instance_specific_init_list(std::unique_ptr<Symbol> value) {
        instance_specific_init_list_ = std::move(value);
        if (instance_specific_init_list_) {
            instance_specific_init_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> instance_specific_init_list_;
};

class instance_specific_init_list_c final : public List {
public:
    instance_specific_init_list_c() = default;
    explicit instance_specific_init_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "instance_specific_init_list_c"; }
};

class instance_specific_init_c final : public Symbol {
public:
    instance_specific_init_c() = default;
    instance_specific_init_c(std::unique_ptr<Symbol> resource_name,
        std::unique_ptr<Symbol> program_name,
        std::unique_ptr<Symbol> any_fb_name_list,
        std::unique_ptr<Symbol> variable_name,
        std::unique_ptr<Symbol> location,
        std::unique_ptr<Symbol> initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), resource_name_(std::move(resource_name)), program_name_(std::move(program_name)), any_fb_name_list_(std::move(any_fb_name_list)), variable_name_(std::move(variable_name)), location_(std::move(location)), initialization_(std::move(initialization)) {
        if (resource_name_) {
            resource_name_->setParent(this);
        }
        if (program_name_) {
            program_name_->setParent(this);
        }
        if (any_fb_name_list_) {
            any_fb_name_list_->setParent(this);
        }
        if (variable_name_) {
            variable_name_->setParent(this);
        }
        if (location_) {
            location_->setParent(this);
        }
        if (initialization_) {
            initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "instance_specific_init_c"; }
    [[nodiscard]] Symbol* resource_name() const noexcept { return resource_name_.get(); }
    void set_resource_name(std::unique_ptr<Symbol> value) {
        resource_name_ = std::move(value);
        if (resource_name_) {
            resource_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* program_name() const noexcept { return program_name_.get(); }
    void set_program_name(std::unique_ptr<Symbol> value) {
        program_name_ = std::move(value);
        if (program_name_) {
            program_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* any_fb_name_list() const noexcept { return any_fb_name_list_.get(); }
    void set_any_fb_name_list(std::unique_ptr<Symbol> value) {
        any_fb_name_list_ = std::move(value);
        if (any_fb_name_list_) {
            any_fb_name_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* location() const noexcept { return location_.get(); }
    void set_location(std::unique_ptr<Symbol> value) {
        location_ = std::move(value);
        if (location_) {
            location_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* initialization() const noexcept { return initialization_.get(); }
    void set_initialization(std::unique_ptr<Symbol> value) {
        initialization_ = std::move(value);
        if (initialization_) {
            initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> resource_name_;
    std::unique_ptr<Symbol> program_name_;
    std::unique_ptr<Symbol> any_fb_name_list_;
    std::unique_ptr<Symbol> variable_name_;
    std::unique_ptr<Symbol> location_;
    std::unique_ptr<Symbol> initialization_;
};

class fb_initialization_c final : public Symbol {
public:
    fb_initialization_c() = default;
    fb_initialization_c(std::unique_ptr<Symbol> function_block_type_name,
        std::unique_ptr<Symbol> structure_initialization = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), function_block_type_name_(std::move(function_block_type_name)), structure_initialization_(std::move(structure_initialization)) {
        if (function_block_type_name_) {
            function_block_type_name_->setParent(this);
        }
        if (structure_initialization_) {
            structure_initialization_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fb_initialization_c"; }
    [[nodiscard]] Symbol* function_block_type_name() const noexcept { return function_block_type_name_.get(); }
    void set_function_block_type_name(std::unique_ptr<Symbol> value) {
        function_block_type_name_ = std::move(value);
        if (function_block_type_name_) {
            function_block_type_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* structure_initialization() const noexcept { return structure_initialization_.get(); }
    void set_structure_initialization(std::unique_ptr<Symbol> value) {
        structure_initialization_ = std::move(value);
        if (structure_initialization_) {
            structure_initialization_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> function_block_type_name_;
    std::unique_ptr<Symbol> structure_initialization_;
};

class instruction_list_c final : public List {
public:
    instruction_list_c() = default;
    explicit instruction_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "instruction_list_c"; }
};

class il_instruction_c final : public Symbol {
public:
    il_instruction_c() = default;
    il_instruction_c(std::unique_ptr<Symbol> label,
        std::unique_ptr<Symbol> il_instruction = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), label_(std::move(label)), il_instruction_(std::move(il_instruction)) {
        if (label_) {
            label_->setParent(this);
        }
        if (il_instruction_) {
            il_instruction_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_instruction_c"; }
    [[nodiscard]] Symbol* label() const noexcept { return label_.get(); }
    void set_label(std::unique_ptr<Symbol> value) {
        label_ = std::move(value);
        if (label_) {
            label_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_instruction() const noexcept { return il_instruction_.get(); }
    void set_il_instruction(std::unique_ptr<Symbol> value) {
        il_instruction_ = std::move(value);
        if (il_instruction_) {
            il_instruction_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> label_;
    std::unique_ptr<Symbol> il_instruction_;
};

class il_simple_operation_c final : public Symbol {
public:
    il_simple_operation_c() = default;
    il_simple_operation_c(std::unique_ptr<Symbol> il_simple_operator,
        std::unique_ptr<Symbol> il_operand = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), il_simple_operator_(std::move(il_simple_operator)), il_operand_(std::move(il_operand)) {
        if (il_simple_operator_) {
            il_simple_operator_->setParent(this);
        }
        if (il_operand_) {
            il_operand_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_simple_operation_c"; }
    [[nodiscard]] Symbol* il_simple_operator() const noexcept { return il_simple_operator_.get(); }
    void set_il_simple_operator(std::unique_ptr<Symbol> value) {
        il_simple_operator_ = std::move(value);
        if (il_simple_operator_) {
            il_simple_operator_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_operand() const noexcept { return il_operand_.get(); }
    void set_il_operand(std::unique_ptr<Symbol> value) {
        il_operand_ = std::move(value);
        if (il_operand_) {
            il_operand_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_simple_operator_;
    std::unique_ptr<Symbol> il_operand_;
};

class il_function_call_c final : public Symbol {
public:
    il_function_call_c() = default;
    il_function_call_c(std::unique_ptr<Symbol> function_name,
        std::unique_ptr<Symbol> il_operand_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), function_name_(std::move(function_name)), il_operand_list_(std::move(il_operand_list)) {
        if (function_name_) {
            function_name_->setParent(this);
        }
        if (il_operand_list_) {
            il_operand_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_function_call_c"; }
    [[nodiscard]] Symbol* function_name() const noexcept { return function_name_.get(); }
    void set_function_name(std::unique_ptr<Symbol> value) {
        function_name_ = std::move(value);
        if (function_name_) {
            function_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_operand_list() const noexcept { return il_operand_list_.get(); }
    void set_il_operand_list(std::unique_ptr<Symbol> value) {
        il_operand_list_ = std::move(value);
        if (il_operand_list_) {
            il_operand_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> function_name_;
    std::unique_ptr<Symbol> il_operand_list_;
};

class il_expression_c final : public Symbol {
public:
    il_expression_c() = default;
    il_expression_c(std::unique_ptr<Symbol> il_expr_operator,
        std::unique_ptr<Symbol> il_operand,
        std::unique_ptr<Symbol> simple_instr_list,
        SourceRange range = {})
        : Symbol(std::move(range)), il_expr_operator_(std::move(il_expr_operator)), il_operand_(std::move(il_operand)), simple_instr_list_(std::move(simple_instr_list)) {
        if (il_expr_operator_) {
            il_expr_operator_->setParent(this);
        }
        if (il_operand_) {
            il_operand_->setParent(this);
        }
        if (simple_instr_list_) {
            simple_instr_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_expression_c"; }
    [[nodiscard]] Symbol* il_expr_operator() const noexcept { return il_expr_operator_.get(); }
    void set_il_expr_operator(std::unique_ptr<Symbol> value) {
        il_expr_operator_ = std::move(value);
        if (il_expr_operator_) {
            il_expr_operator_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_operand() const noexcept { return il_operand_.get(); }
    void set_il_operand(std::unique_ptr<Symbol> value) {
        il_operand_ = std::move(value);
        if (il_operand_) {
            il_operand_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* simple_instr_list() const noexcept { return simple_instr_list_.get(); }
    void set_simple_instr_list(std::unique_ptr<Symbol> value) {
        simple_instr_list_ = std::move(value);
        if (simple_instr_list_) {
            simple_instr_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_expr_operator_;
    std::unique_ptr<Symbol> il_operand_;
    std::unique_ptr<Symbol> simple_instr_list_;
};

class il_jump_operation_c final : public Symbol {
public:
    il_jump_operation_c() = default;
    il_jump_operation_c(std::unique_ptr<Symbol> il_jump_operator,
        std::unique_ptr<Symbol> label = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), il_jump_operator_(std::move(il_jump_operator)), label_(std::move(label)) {
        if (il_jump_operator_) {
            il_jump_operator_->setParent(this);
        }
        if (label_) {
            label_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_jump_operation_c"; }
    [[nodiscard]] Symbol* il_jump_operator() const noexcept { return il_jump_operator_.get(); }
    void set_il_jump_operator(std::unique_ptr<Symbol> value) {
        il_jump_operator_ = std::move(value);
        if (il_jump_operator_) {
            il_jump_operator_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* label() const noexcept { return label_.get(); }
    void set_label(std::unique_ptr<Symbol> value) {
        label_ = std::move(value);
        if (label_) {
            label_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_jump_operator_;
    std::unique_ptr<Symbol> label_;
};

class il_fb_call_c final : public Symbol {
public:
    il_fb_call_c() = default;
    il_fb_call_c(std::unique_ptr<Symbol> il_call_operator,
        std::unique_ptr<Symbol> fb_name,
        std::unique_ptr<Symbol> il_operand_list,
        std::unique_ptr<Symbol> il_param_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), il_call_operator_(std::move(il_call_operator)), fb_name_(std::move(fb_name)), il_operand_list_(std::move(il_operand_list)), il_param_list_(std::move(il_param_list)) {
        if (il_call_operator_) {
            il_call_operator_->setParent(this);
        }
        if (fb_name_) {
            fb_name_->setParent(this);
        }
        if (il_operand_list_) {
            il_operand_list_->setParent(this);
        }
        if (il_param_list_) {
            il_param_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_fb_call_c"; }
    [[nodiscard]] Symbol* il_call_operator() const noexcept { return il_call_operator_.get(); }
    void set_il_call_operator(std::unique_ptr<Symbol> value) {
        il_call_operator_ = std::move(value);
        if (il_call_operator_) {
            il_call_operator_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* fb_name() const noexcept { return fb_name_.get(); }
    void set_fb_name(std::unique_ptr<Symbol> value) {
        fb_name_ = std::move(value);
        if (fb_name_) {
            fb_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_operand_list() const noexcept { return il_operand_list_.get(); }
    void set_il_operand_list(std::unique_ptr<Symbol> value) {
        il_operand_list_ = std::move(value);
        if (il_operand_list_) {
            il_operand_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_param_list() const noexcept { return il_param_list_.get(); }
    void set_il_param_list(std::unique_ptr<Symbol> value) {
        il_param_list_ = std::move(value);
        if (il_param_list_) {
            il_param_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_call_operator_;
    std::unique_ptr<Symbol> fb_name_;
    std::unique_ptr<Symbol> il_operand_list_;
    std::unique_ptr<Symbol> il_param_list_;
};

class il_formal_funct_call_c final : public Symbol {
public:
    il_formal_funct_call_c() = default;
    il_formal_funct_call_c(std::unique_ptr<Symbol> function_name,
        std::unique_ptr<Symbol> il_param_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), function_name_(std::move(function_name)), il_param_list_(std::move(il_param_list)) {
        if (function_name_) {
            function_name_->setParent(this);
        }
        if (il_param_list_) {
            il_param_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_formal_funct_call_c"; }
    [[nodiscard]] Symbol* function_name() const noexcept { return function_name_.get(); }
    void set_function_name(std::unique_ptr<Symbol> value) {
        function_name_ = std::move(value);
        if (function_name_) {
            function_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_param_list() const noexcept { return il_param_list_.get(); }
    void set_il_param_list(std::unique_ptr<Symbol> value) {
        il_param_list_ = std::move(value);
        if (il_param_list_) {
            il_param_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> function_name_;
    std::unique_ptr<Symbol> il_param_list_;
};

class il_operand_list_c final : public List {
public:
    il_operand_list_c() = default;
    explicit il_operand_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_operand_list_c"; }
};

class simple_instr_list_c final : public List {
public:
    simple_instr_list_c() = default;
    explicit simple_instr_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "simple_instr_list_c"; }
};

class il_simple_instruction_c final : public Symbol {
public:
    il_simple_instruction_c() = default;
    il_simple_instruction_c(std::unique_ptr<Symbol> il_simple_instruction,
        SourceRange range = {})
        : Symbol(std::move(range)), il_simple_instruction_(std::move(il_simple_instruction)) {
        if (il_simple_instruction_) {
            il_simple_instruction_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_simple_instruction_c"; }
    [[nodiscard]] Symbol* il_simple_instruction() const noexcept { return il_simple_instruction_.get(); }
    void set_il_simple_instruction(std::unique_ptr<Symbol> value) {
        il_simple_instruction_ = std::move(value);
        if (il_simple_instruction_) {
            il_simple_instruction_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_simple_instruction_;
};

class il_param_list_c final : public List {
public:
    il_param_list_c() = default;
    explicit il_param_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_param_list_c"; }
};

class il_param_assignment_c final : public Symbol {
public:
    il_param_assignment_c() = default;
    il_param_assignment_c(std::unique_ptr<Symbol> il_assign_operator,
        std::unique_ptr<Symbol> il_operand,
        std::unique_ptr<Symbol> simple_instr_list,
        SourceRange range = {})
        : Symbol(std::move(range)), il_assign_operator_(std::move(il_assign_operator)), il_operand_(std::move(il_operand)), simple_instr_list_(std::move(simple_instr_list)) {
        if (il_assign_operator_) {
            il_assign_operator_->setParent(this);
        }
        if (il_operand_) {
            il_operand_->setParent(this);
        }
        if (simple_instr_list_) {
            simple_instr_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_param_assignment_c"; }
    [[nodiscard]] Symbol* il_assign_operator() const noexcept { return il_assign_operator_.get(); }
    void set_il_assign_operator(std::unique_ptr<Symbol> value) {
        il_assign_operator_ = std::move(value);
        if (il_assign_operator_) {
            il_assign_operator_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* il_operand() const noexcept { return il_operand_.get(); }
    void set_il_operand(std::unique_ptr<Symbol> value) {
        il_operand_ = std::move(value);
        if (il_operand_) {
            il_operand_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* simple_instr_list() const noexcept { return simple_instr_list_.get(); }
    void set_simple_instr_list(std::unique_ptr<Symbol> value) {
        simple_instr_list_ = std::move(value);
        if (simple_instr_list_) {
            simple_instr_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_assign_operator_;
    std::unique_ptr<Symbol> il_operand_;
    std::unique_ptr<Symbol> simple_instr_list_;
};

class il_param_out_assignment_c final : public Symbol {
public:
    il_param_out_assignment_c() = default;
    il_param_out_assignment_c(std::unique_ptr<Symbol> il_assign_out_operator,
        std::unique_ptr<Symbol> variable = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), il_assign_out_operator_(std::move(il_assign_out_operator)), variable_(std::move(variable)) {
        if (il_assign_out_operator_) {
            il_assign_out_operator_->setParent(this);
        }
        if (variable_) {
            variable_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_param_out_assignment_c"; }
    [[nodiscard]] Symbol* il_assign_out_operator() const noexcept { return il_assign_out_operator_.get(); }
    void set_il_assign_out_operator(std::unique_ptr<Symbol> value) {
        il_assign_out_operator_ = std::move(value);
        if (il_assign_out_operator_) {
            il_assign_out_operator_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* variable() const noexcept { return variable_.get(); }
    void set_variable(std::unique_ptr<Symbol> value) {
        variable_ = std::move(value);
        if (variable_) {
            variable_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> il_assign_out_operator_;
    std::unique_ptr<Symbol> variable_;
};

class LD_operator_c final : public Symbol {
public:
    LD_operator_c() = default;
    explicit LD_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "LD_operator_c"; }
private:
};

class LDN_operator_c final : public Symbol {
public:
    LDN_operator_c() = default;
    explicit LDN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "LDN_operator_c"; }
private:
};

class ST_operator_c final : public Symbol {
public:
    ST_operator_c() = default;
    explicit ST_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ST_operator_c"; }
private:
};

class STN_operator_c final : public Symbol {
public:
    STN_operator_c() = default;
    explicit STN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "STN_operator_c"; }
private:
};

class NOT_operator_c final : public Symbol {
public:
    NOT_operator_c() = default;
    explicit NOT_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "NOT_operator_c"; }
private:
};

class S_operator_c final : public Symbol {
public:
    S_operator_c() = default;
    explicit S_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "S_operator_c"; }
private:
};

class R_operator_c final : public Symbol {
public:
    R_operator_c() = default;
    explicit R_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "R_operator_c"; }
private:
};

class S1_operator_c final : public Symbol {
public:
    S1_operator_c() = default;
    explicit S1_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "S1_operator_c"; }
private:
};

class R1_operator_c final : public Symbol {
public:
    R1_operator_c() = default;
    explicit R1_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "R1_operator_c"; }
private:
};

class CLK_operator_c final : public Symbol {
public:
    CLK_operator_c() = default;
    explicit CLK_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "CLK_operator_c"; }
private:
};

class CU_operator_c final : public Symbol {
public:
    CU_operator_c() = default;
    explicit CU_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "CU_operator_c"; }
private:
};

class CD_operator_c final : public Symbol {
public:
    CD_operator_c() = default;
    explicit CD_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "CD_operator_c"; }
private:
};

class PV_operator_c final : public Symbol {
public:
    PV_operator_c() = default;
    explicit PV_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "PV_operator_c"; }
private:
};

class IN_operator_c final : public Symbol {
public:
    IN_operator_c() = default;
    explicit IN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "IN_operator_c"; }
private:
};

class PT_operator_c final : public Symbol {
public:
    PT_operator_c() = default;
    explicit PT_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "PT_operator_c"; }
private:
};

class AND_operator_c final : public Symbol {
public:
    AND_operator_c() = default;
    explicit AND_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "AND_operator_c"; }
private:
};

class OR_operator_c final : public Symbol {
public:
    OR_operator_c() = default;
    explicit OR_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "OR_operator_c"; }
private:
};

class XOR_operator_c final : public Symbol {
public:
    XOR_operator_c() = default;
    explicit XOR_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "XOR_operator_c"; }
private:
};

class ANDN_operator_c final : public Symbol {
public:
    ANDN_operator_c() = default;
    explicit ANDN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ANDN_operator_c"; }
private:
};

class ORN_operator_c final : public Symbol {
public:
    ORN_operator_c() = default;
    explicit ORN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ORN_operator_c"; }
private:
};

class XORN_operator_c final : public Symbol {
public:
    XORN_operator_c() = default;
    explicit XORN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "XORN_operator_c"; }
private:
};

class ADD_operator_c final : public Symbol {
public:
    ADD_operator_c() = default;
    explicit ADD_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ADD_operator_c"; }
private:
};

class SUB_operator_c final : public Symbol {
public:
    SUB_operator_c() = default;
    explicit SUB_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "SUB_operator_c"; }
private:
};

class MUL_operator_c final : public Symbol {
public:
    MUL_operator_c() = default;
    explicit MUL_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "MUL_operator_c"; }
private:
};

class DIV_operator_c final : public Symbol {
public:
    DIV_operator_c() = default;
    explicit DIV_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "DIV_operator_c"; }
private:
};

class MOD_operator_c final : public Symbol {
public:
    MOD_operator_c() = default;
    explicit MOD_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "MOD_operator_c"; }
private:
};

class GT_operator_c final : public Symbol {
public:
    GT_operator_c() = default;
    explicit GT_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "GT_operator_c"; }
private:
};

class GE_operator_c final : public Symbol {
public:
    GE_operator_c() = default;
    explicit GE_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "GE_operator_c"; }
private:
};

class EQ_operator_c final : public Symbol {
public:
    EQ_operator_c() = default;
    explicit EQ_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "EQ_operator_c"; }
private:
};

class LT_operator_c final : public Symbol {
public:
    LT_operator_c() = default;
    explicit LT_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "LT_operator_c"; }
private:
};

class LE_operator_c final : public Symbol {
public:
    LE_operator_c() = default;
    explicit LE_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "LE_operator_c"; }
private:
};

class NE_operator_c final : public Symbol {
public:
    NE_operator_c() = default;
    explicit NE_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "NE_operator_c"; }
private:
};

class CAL_operator_c final : public Symbol {
public:
    CAL_operator_c() = default;
    explicit CAL_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "CAL_operator_c"; }
private:
};

class CALC_operator_c final : public Symbol {
public:
    CALC_operator_c() = default;
    explicit CALC_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "CALC_operator_c"; }
private:
};

class CALCN_operator_c final : public Symbol {
public:
    CALCN_operator_c() = default;
    explicit CALCN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "CALCN_operator_c"; }
private:
};

class RET_operator_c final : public Symbol {
public:
    RET_operator_c() = default;
    explicit RET_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "RET_operator_c"; }
private:
};

class RETC_operator_c final : public Symbol {
public:
    RETC_operator_c() = default;
    explicit RETC_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "RETC_operator_c"; }
private:
};

class RETCN_operator_c final : public Symbol {
public:
    RETCN_operator_c() = default;
    explicit RETCN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "RETCN_operator_c"; }
private:
};

class JMP_operator_c final : public Symbol {
public:
    JMP_operator_c() = default;
    explicit JMP_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "JMP_operator_c"; }
private:
};

class JMPC_operator_c final : public Symbol {
public:
    JMPC_operator_c() = default;
    explicit JMPC_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "JMPC_operator_c"; }
private:
};

class JMPCN_operator_c final : public Symbol {
public:
    JMPCN_operator_c() = default;
    explicit JMPCN_operator_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "JMPCN_operator_c"; }
private:
};

class il_assign_operator_c final : public Symbol {
public:
    il_assign_operator_c() = default;
    il_assign_operator_c(std::unique_ptr<Symbol> variable_name,
        SourceRange range = {})
        : Symbol(std::move(range)), variable_name_(std::move(variable_name)) {
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_assign_operator_c"; }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> variable_name_;
};

class il_assign_out_operator_c final : public Symbol {
public:
    il_assign_out_operator_c() = default;
    il_assign_out_operator_c(std::unique_ptr<Symbol> option,
        std::unique_ptr<Symbol> variable_name = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), option_(std::move(option)), variable_name_(std::move(variable_name)) {
        if (option_) {
            option_->setParent(this);
        }
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "il_assign_out_operator_c"; }
    [[nodiscard]] Symbol* option() const noexcept { return option_.get(); }
    void set_option(std::unique_ptr<Symbol> value) {
        option_ = std::move(value);
        if (option_) {
            option_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> option_;
    std::unique_ptr<Symbol> variable_name_;
};

class ref_expression_c final : public Symbol {
public:
    ref_expression_c() = default;
    ref_expression_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ref_expression_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class deref_expression_c final : public Symbol {
public:
    deref_expression_c() = default;
    deref_expression_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "deref_expression_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class deref_operator_c final : public Symbol {
public:
    deref_operator_c() = default;
    deref_operator_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "deref_operator_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class or_expression_c final : public Symbol {
public:
    or_expression_c() = default;
    or_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "or_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class xor_expression_c final : public Symbol {
public:
    xor_expression_c() = default;
    xor_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "xor_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class and_expression_c final : public Symbol {
public:
    and_expression_c() = default;
    and_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "and_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class equ_expression_c final : public Symbol {
public:
    equ_expression_c() = default;
    equ_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "equ_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class notequ_expression_c final : public Symbol {
public:
    notequ_expression_c() = default;
    notequ_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "notequ_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class lt_expression_c final : public Symbol {
public:
    lt_expression_c() = default;
    lt_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "lt_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class gt_expression_c final : public Symbol {
public:
    gt_expression_c() = default;
    gt_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "gt_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class le_expression_c final : public Symbol {
public:
    le_expression_c() = default;
    le_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "le_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class ge_expression_c final : public Symbol {
public:
    ge_expression_c() = default;
    ge_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "ge_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class add_expression_c final : public Symbol {
public:
    add_expression_c() = default;
    add_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "add_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class sub_expression_c final : public Symbol {
public:
    sub_expression_c() = default;
    sub_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "sub_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class mul_expression_c final : public Symbol {
public:
    mul_expression_c() = default;
    mul_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "mul_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class div_expression_c final : public Symbol {
public:
    div_expression_c() = default;
    div_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "div_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class mod_expression_c final : public Symbol {
public:
    mod_expression_c() = default;
    mod_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "mod_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class power_expression_c final : public Symbol {
public:
    power_expression_c() = default;
    power_expression_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "power_expression_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class neg_expression_c final : public Symbol {
public:
    neg_expression_c() = default;
    neg_expression_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "neg_expression_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class not_expression_c final : public Symbol {
public:
    not_expression_c() = default;
    not_expression_c(std::unique_ptr<Symbol> exp,
        SourceRange range = {})
        : Symbol(std::move(range)), exp_(std::move(exp)) {
        if (exp_) {
            exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "not_expression_c"; }
    [[nodiscard]] Symbol* exp() const noexcept { return exp_.get(); }
    void set_exp(std::unique_ptr<Symbol> value) {
        exp_ = std::move(value);
        if (exp_) {
            exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> exp_;
};

class function_invocation_c final : public Symbol {
public:
    function_invocation_c() = default;
    function_invocation_c(std::unique_ptr<Symbol> function_name,
        std::unique_ptr<Symbol> formal_param_list,
        std::unique_ptr<Symbol> nonformal_param_list,
        SourceRange range = {})
        : Symbol(std::move(range)), function_name_(std::move(function_name)), formal_param_list_(std::move(formal_param_list)), nonformal_param_list_(std::move(nonformal_param_list)) {
        if (function_name_) {
            function_name_->setParent(this);
        }
        if (formal_param_list_) {
            formal_param_list_->setParent(this);
        }
        if (nonformal_param_list_) {
            nonformal_param_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "function_invocation_c"; }
    [[nodiscard]] Symbol* function_name() const noexcept { return function_name_.get(); }
    void set_function_name(std::unique_ptr<Symbol> value) {
        function_name_ = std::move(value);
        if (function_name_) {
            function_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* formal_param_list() const noexcept { return formal_param_list_.get(); }
    void set_formal_param_list(std::unique_ptr<Symbol> value) {
        formal_param_list_ = std::move(value);
        if (formal_param_list_) {
            formal_param_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* nonformal_param_list() const noexcept { return nonformal_param_list_.get(); }
    void set_nonformal_param_list(std::unique_ptr<Symbol> value) {
        nonformal_param_list_ = std::move(value);
        if (nonformal_param_list_) {
            nonformal_param_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> function_name_;
    std::unique_ptr<Symbol> formal_param_list_;
    std::unique_ptr<Symbol> nonformal_param_list_;
};

class statement_list_c final : public List {
public:
    statement_list_c() = default;
    explicit statement_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "statement_list_c"; }
};

class assignment_statement_c final : public Symbol {
public:
    assignment_statement_c() = default;
    assignment_statement_c(std::unique_ptr<Symbol> l_exp,
        std::unique_ptr<Symbol> r_exp = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), l_exp_(std::move(l_exp)), r_exp_(std::move(r_exp)) {
        if (l_exp_) {
            l_exp_->setParent(this);
        }
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "assignment_statement_c"; }
    [[nodiscard]] Symbol* l_exp() const noexcept { return l_exp_.get(); }
    void set_l_exp(std::unique_ptr<Symbol> value) {
        l_exp_ = std::move(value);
        if (l_exp_) {
            l_exp_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* r_exp() const noexcept { return r_exp_.get(); }
    void set_r_exp(std::unique_ptr<Symbol> value) {
        r_exp_ = std::move(value);
        if (r_exp_) {
            r_exp_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> l_exp_;
    std::unique_ptr<Symbol> r_exp_;
};

class return_statement_c final : public Symbol {
public:
    return_statement_c() = default;
    explicit return_statement_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "return_statement_c"; }
private:
};

class fb_invocation_c final : public Symbol {
public:
    fb_invocation_c() = default;
    fb_invocation_c(std::unique_ptr<Symbol> fb_name,
        std::unique_ptr<Symbol> formal_param_list,
        std::unique_ptr<Symbol> nonformal_param_list,
        SourceRange range = {})
        : Symbol(std::move(range)), fb_name_(std::move(fb_name)), formal_param_list_(std::move(formal_param_list)), nonformal_param_list_(std::move(nonformal_param_list)) {
        if (fb_name_) {
            fb_name_->setParent(this);
        }
        if (formal_param_list_) {
            formal_param_list_->setParent(this);
        }
        if (nonformal_param_list_) {
            nonformal_param_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "fb_invocation_c"; }
    [[nodiscard]] Symbol* fb_name() const noexcept { return fb_name_.get(); }
    void set_fb_name(std::unique_ptr<Symbol> value) {
        fb_name_ = std::move(value);
        if (fb_name_) {
            fb_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* formal_param_list() const noexcept { return formal_param_list_.get(); }
    void set_formal_param_list(std::unique_ptr<Symbol> value) {
        formal_param_list_ = std::move(value);
        if (formal_param_list_) {
            formal_param_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* nonformal_param_list() const noexcept { return nonformal_param_list_.get(); }
    void set_nonformal_param_list(std::unique_ptr<Symbol> value) {
        nonformal_param_list_ = std::move(value);
        if (nonformal_param_list_) {
            nonformal_param_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> fb_name_;
    std::unique_ptr<Symbol> formal_param_list_;
    std::unique_ptr<Symbol> nonformal_param_list_;
};

class param_assignment_list_c final : public List {
public:
    param_assignment_list_c() = default;
    explicit param_assignment_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "param_assignment_list_c"; }
};

class input_variable_param_assignment_c final : public Symbol {
public:
    input_variable_param_assignment_c() = default;
    input_variable_param_assignment_c(std::unique_ptr<Symbol> variable_name,
        std::unique_ptr<Symbol> expression = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), variable_name_(std::move(variable_name)), expression_(std::move(expression)) {
        if (variable_name_) {
            variable_name_->setParent(this);
        }
        if (expression_) {
            expression_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "input_variable_param_assignment_c"; }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* expression() const noexcept { return expression_.get(); }
    void set_expression(std::unique_ptr<Symbol> value) {
        expression_ = std::move(value);
        if (expression_) {
            expression_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> variable_name_;
    std::unique_ptr<Symbol> expression_;
};

class output_variable_param_assignment_c final : public Symbol {
public:
    output_variable_param_assignment_c() = default;
    output_variable_param_assignment_c(std::unique_ptr<Symbol> not_param,
        std::unique_ptr<Symbol> variable_name,
        std::unique_ptr<Symbol> variable,
        SourceRange range = {})
        : Symbol(std::move(range)), not_param_(std::move(not_param)), variable_name_(std::move(variable_name)), variable_(std::move(variable)) {
        if (not_param_) {
            not_param_->setParent(this);
        }
        if (variable_name_) {
            variable_name_->setParent(this);
        }
        if (variable_) {
            variable_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "output_variable_param_assignment_c"; }
    [[nodiscard]] Symbol* not_param() const noexcept { return not_param_.get(); }
    void set_not_param(std::unique_ptr<Symbol> value) {
        not_param_ = std::move(value);
        if (not_param_) {
            not_param_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* variable_name() const noexcept { return variable_name_.get(); }
    void set_variable_name(std::unique_ptr<Symbol> value) {
        variable_name_ = std::move(value);
        if (variable_name_) {
            variable_name_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* variable() const noexcept { return variable_.get(); }
    void set_variable(std::unique_ptr<Symbol> value) {
        variable_ = std::move(value);
        if (variable_) {
            variable_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> not_param_;
    std::unique_ptr<Symbol> variable_name_;
    std::unique_ptr<Symbol> variable_;
};

class not_paramassign_c final : public Symbol {
public:
    not_paramassign_c() = default;
    explicit not_paramassign_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "not_paramassign_c"; }
private:
};

class if_statement_c final : public Symbol {
public:
    if_statement_c() = default;
    if_statement_c(std::unique_ptr<Symbol> expression,
        std::unique_ptr<Symbol> statement_list,
        std::unique_ptr<Symbol> elseif_statement_list,
        std::unique_ptr<Symbol> else_statement_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), expression_(std::move(expression)), statement_list_(std::move(statement_list)), elseif_statement_list_(std::move(elseif_statement_list)), else_statement_list_(std::move(else_statement_list)) {
        if (expression_) {
            expression_->setParent(this);
        }
        if (statement_list_) {
            statement_list_->setParent(this);
        }
        if (elseif_statement_list_) {
            elseif_statement_list_->setParent(this);
        }
        if (else_statement_list_) {
            else_statement_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "if_statement_c"; }
    [[nodiscard]] Symbol* expression() const noexcept { return expression_.get(); }
    void set_expression(std::unique_ptr<Symbol> value) {
        expression_ = std::move(value);
        if (expression_) {
            expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* elseif_statement_list() const noexcept { return elseif_statement_list_.get(); }
    void set_elseif_statement_list(std::unique_ptr<Symbol> value) {
        elseif_statement_list_ = std::move(value);
        if (elseif_statement_list_) {
            elseif_statement_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* else_statement_list() const noexcept { return else_statement_list_.get(); }
    void set_else_statement_list(std::unique_ptr<Symbol> value) {
        else_statement_list_ = std::move(value);
        if (else_statement_list_) {
            else_statement_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> expression_;
    std::unique_ptr<Symbol> statement_list_;
    std::unique_ptr<Symbol> elseif_statement_list_;
    std::unique_ptr<Symbol> else_statement_list_;
};

class elseif_statement_list_c final : public List {
public:
    elseif_statement_list_c() = default;
    explicit elseif_statement_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "elseif_statement_list_c"; }
};

class elseif_statement_c final : public Symbol {
public:
    elseif_statement_c() = default;
    elseif_statement_c(std::unique_ptr<Symbol> expression,
        std::unique_ptr<Symbol> statement_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), expression_(std::move(expression)), statement_list_(std::move(statement_list)) {
        if (expression_) {
            expression_->setParent(this);
        }
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "elseif_statement_c"; }
    [[nodiscard]] Symbol* expression() const noexcept { return expression_.get(); }
    void set_expression(std::unique_ptr<Symbol> value) {
        expression_ = std::move(value);
        if (expression_) {
            expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> expression_;
    std::unique_ptr<Symbol> statement_list_;
};

class case_statement_c final : public Symbol {
public:
    case_statement_c() = default;
    case_statement_c(std::unique_ptr<Symbol> expression,
        std::unique_ptr<Symbol> case_element_list,
        std::unique_ptr<Symbol> statement_list,
        SourceRange range = {})
        : Symbol(std::move(range)), expression_(std::move(expression)), case_element_list_(std::move(case_element_list)), statement_list_(std::move(statement_list)) {
        if (expression_) {
            expression_->setParent(this);
        }
        if (case_element_list_) {
            case_element_list_->setParent(this);
        }
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "case_statement_c"; }
    [[nodiscard]] Symbol* expression() const noexcept { return expression_.get(); }
    void set_expression(std::unique_ptr<Symbol> value) {
        expression_ = std::move(value);
        if (expression_) {
            expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* case_element_list() const noexcept { return case_element_list_.get(); }
    void set_case_element_list(std::unique_ptr<Symbol> value) {
        case_element_list_ = std::move(value);
        if (case_element_list_) {
            case_element_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> expression_;
    std::unique_ptr<Symbol> case_element_list_;
    std::unique_ptr<Symbol> statement_list_;
};

class case_element_list_c final : public List {
public:
    case_element_list_c() = default;
    explicit case_element_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "case_element_list_c"; }
};

class case_element_c final : public Symbol {
public:
    case_element_c() = default;
    case_element_c(std::unique_ptr<Symbol> case_list,
        std::unique_ptr<Symbol> statement_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), case_list_(std::move(case_list)), statement_list_(std::move(statement_list)) {
        if (case_list_) {
            case_list_->setParent(this);
        }
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "case_element_c"; }
    [[nodiscard]] Symbol* case_list() const noexcept { return case_list_.get(); }
    void set_case_list(std::unique_ptr<Symbol> value) {
        case_list_ = std::move(value);
        if (case_list_) {
            case_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> case_list_;
    std::unique_ptr<Symbol> statement_list_;
};

class case_list_c final : public List {
public:
    case_list_c() = default;
    explicit case_list_c(SourceRange range) : List(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "case_list_c"; }
};

class for_statement_c final : public Symbol {
public:
    for_statement_c() = default;
    for_statement_c(std::unique_ptr<Symbol> control_variable,
        std::unique_ptr<Symbol> beg_expression,
        std::unique_ptr<Symbol> end_expression,
        std::unique_ptr<Symbol> by_expression,
        std::unique_ptr<Symbol> statement_list,
        SourceRange range = {})
        : Symbol(std::move(range)), control_variable_(std::move(control_variable)), beg_expression_(std::move(beg_expression)), end_expression_(std::move(end_expression)), by_expression_(std::move(by_expression)), statement_list_(std::move(statement_list)) {
        if (control_variable_) {
            control_variable_->setParent(this);
        }
        if (beg_expression_) {
            beg_expression_->setParent(this);
        }
        if (end_expression_) {
            end_expression_->setParent(this);
        }
        if (by_expression_) {
            by_expression_->setParent(this);
        }
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "for_statement_c"; }
    [[nodiscard]] Symbol* control_variable() const noexcept { return control_variable_.get(); }
    void set_control_variable(std::unique_ptr<Symbol> value) {
        control_variable_ = std::move(value);
        if (control_variable_) {
            control_variable_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* beg_expression() const noexcept { return beg_expression_.get(); }
    void set_beg_expression(std::unique_ptr<Symbol> value) {
        beg_expression_ = std::move(value);
        if (beg_expression_) {
            beg_expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* end_expression() const noexcept { return end_expression_.get(); }
    void set_end_expression(std::unique_ptr<Symbol> value) {
        end_expression_ = std::move(value);
        if (end_expression_) {
            end_expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* by_expression() const noexcept { return by_expression_.get(); }
    void set_by_expression(std::unique_ptr<Symbol> value) {
        by_expression_ = std::move(value);
        if (by_expression_) {
            by_expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> control_variable_;
    std::unique_ptr<Symbol> beg_expression_;
    std::unique_ptr<Symbol> end_expression_;
    std::unique_ptr<Symbol> by_expression_;
    std::unique_ptr<Symbol> statement_list_;
};

class while_statement_c final : public Symbol {
public:
    while_statement_c() = default;
    while_statement_c(std::unique_ptr<Symbol> expression,
        std::unique_ptr<Symbol> statement_list = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), expression_(std::move(expression)), statement_list_(std::move(statement_list)) {
        if (expression_) {
            expression_->setParent(this);
        }
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "while_statement_c"; }
    [[nodiscard]] Symbol* expression() const noexcept { return expression_.get(); }
    void set_expression(std::unique_ptr<Symbol> value) {
        expression_ = std::move(value);
        if (expression_) {
            expression_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> expression_;
    std::unique_ptr<Symbol> statement_list_;
};

class repeat_statement_c final : public Symbol {
public:
    repeat_statement_c() = default;
    repeat_statement_c(std::unique_ptr<Symbol> statement_list,
        std::unique_ptr<Symbol> expression = nullptr,
        SourceRange range = {})
        : Symbol(std::move(range)), statement_list_(std::move(statement_list)), expression_(std::move(expression)) {
        if (statement_list_) {
            statement_list_->setParent(this);
        }
        if (expression_) {
            expression_->setParent(this);
        }
    }
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "repeat_statement_c"; }
    [[nodiscard]] Symbol* statement_list() const noexcept { return statement_list_.get(); }
    void set_statement_list(std::unique_ptr<Symbol> value) {
        statement_list_ = std::move(value);
        if (statement_list_) {
            statement_list_->setParent(this);
        }
    }
    [[nodiscard]] Symbol* expression() const noexcept { return expression_.get(); }
    void set_expression(std::unique_ptr<Symbol> value) {
        expression_ = std::move(value);
        if (expression_) {
            expression_->setParent(this);
        }
    }
private:
    std::unique_ptr<Symbol> statement_list_;
    std::unique_ptr<Symbol> expression_;
};

class exit_statement_c final : public Symbol {
public:
    exit_statement_c() = default;
    explicit exit_statement_c(SourceRange range) : Symbol(std::move(range)) {}
    [[nodiscard]] VisitorResult accept(Visitor& visitor) override {
        return visitor.visit(*this);
    }
    [[nodiscard]] std::string_view typeName() const noexcept override { return "exit_statement_c"; }
private:
};

} // namespace matiec::ast
