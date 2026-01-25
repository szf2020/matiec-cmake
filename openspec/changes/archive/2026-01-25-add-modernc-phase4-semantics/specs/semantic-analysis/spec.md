## ADDED Requirements
### Requirement: Candidate datatype collection uses new type system
The system SHALL collect and narrow candidate datatypes using the new type
registry and compatibility helpers.

#### Scenario: Narrowing removes incompatible types
- **WHEN** an expression has candidate types that are not assignable to the
  target type
- **THEN** incompatible candidates are removed from the candidate list

### Requirement: Constant folding remains behavior-compatible
The system SHALL fold constant expressions using type-aware ConstValue results
without changing the observed constant values.

#### Scenario: Constant folding preserves results
- **WHEN** a constant expression is analyzed
- **THEN** the folded value matches the previous behavior for the same input

### Requirement: Diagnostics remain stable
The system SHALL preserve existing semantic error codes and severity levels
when reporting errors through ErrorReporter.

#### Scenario: Semantic error reporting
- **WHEN** a type mismatch is detected during semantic analysis
- **THEN** the same error code and severity are reported as before
