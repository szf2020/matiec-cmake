## ADDED Requirements
### Requirement: Modern AST base and ownership
The system SHALL provide modern AST base classes under include/matiec/ast/
that use std::unique_ptr for child ownership and maintain non-owning parent
pointers.

#### Scenario: Parent pointer set on insertion
- **WHEN** a child node is added to a list or assigned as a field
- **THEN** the child's parent pointer references the owning node

### Requirement: Visitor interface returns VisitorResult
The system SHALL provide a visitor base interface with visit overloads returning
VisitorResult, and AST nodes SHALL dispatch to isitor.visit(*this).

#### Scenario: Visitor dispatch returns typed result
- **WHEN** a visitor returns a std::string for a node
- **THEN** the node's ccept returns a VisitorResult holding that string

### Requirement: Legacy compatibility adapter
The system SHALL provide a compatibility header that allows legacy symbol_c
and isitor_c code to interoperate with the modern AST and visitor interface.

#### Scenario: Legacy visitor path preserves result
- **WHEN** a legacy visitor processes a modern AST node via the adapter
- **THEN** the adapter returns a oid* derived from VisitorResult without
  unsafe reinterpret casts
