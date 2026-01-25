## ADDED Requirements
### Requirement: Type model and registry
The system SHALL provide a type model and registry under `include/matiec/types/`
that exposes built-in IEC 61131-3 types and supports registering user-defined
array/struct/enum types.

#### Scenario: Registry lookup
- **WHEN** a user-defined type is registered with name `MyType`
- **THEN** `findType('MyType')` returns the registered type

### Requirement: Type compatibility checks
The system SHALL expose compatibility helpers to determine assignment and
conversion rules between types.

#### Scenario: Integer compatibility
- **WHEN** an expression type is `INT` and the target is `DINT`
- **THEN** compatibility checks indicate the assignment is allowed

### Requirement: Type inference for literals
The system SHALL provide a type inferrer that assigns types to literal nodes
and basic expressions.

#### Scenario: Integer literal inference
- **WHEN** an integer literal node is analyzed
- **THEN** the inferred type is `INT` by default
