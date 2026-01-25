## ADDED Requirements
### Requirement: CompilationUnit ownership and error access
The system SHALL provide a C++17 header include/matiec/compiler/compilation_unit.hpp
that defines CompilationUnit to own an AST root (std::unique_ptr<ast::Symbol>),
expose non-owning access to the root, track source metadata, and provide access
to an ErrorReporter instance.

#### Scenario: AST ownership transfer
- **WHEN** a caller passes a std::unique_ptr<ast::Symbol> to setAstRoot
- **THEN** astRoot returns the same node and releaseAst transfers ownership

#### Scenario: Validation reflects errors
- **WHEN** errors are reported through the unit's ErrorReporter
- **THEN** isValid() returns false
