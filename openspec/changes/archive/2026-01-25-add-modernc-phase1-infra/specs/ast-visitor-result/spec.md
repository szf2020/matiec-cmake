## ADDED Requirements
### Requirement: VisitorResult type and helpers
The system SHALL provide a C++17 header include/matiec/ast/visitor_result.hpp
that defines a VisitorResult variant type and helper functions to query and
extract typed results without unsafe casts.

#### Scenario: Extract typed result
- **WHEN** a VisitorResult holds a std::string
- **THEN** get_result<std::string> returns the stored string

#### Scenario: Empty result detection
- **WHEN** a VisitorResult holds std::monostate
- **THEN** is_empty returns true
