## ADDED Requirements
### Requirement: Modernization Program MUST Define Stage Gates
The project MUST execute L2-L5 modernization through named milestones with explicit stage gates.

#### Scenario: Gate checks before advancing milestones
- **GIVEN** a milestone has implementation changes
- **WHEN** the team wants to move to the next milestone
- **THEN** build/test/regression/sanitizer/documentation checks MUST pass
- **AND** rollback instructions for the milestone MUST exist

### Requirement: Build Configuration MUST Be Target-Scoped
Core build settings MUST be applied at target scope instead of relying on global include/compile directives.

#### Scenario: Core targets receive shared options via explicit application
- **GIVEN** core matiec targets are created
- **WHEN** shared warnings/definitions/sanitizer flags are applied
- **THEN** each target MUST receive options through a reusable target-level mechanism
- **AND** global `include_directories(...)` MUST NOT be used for project-wide injection

### Requirement: Breaking Changes MUST Ship with Migration Artifacts
Any breaking modernization release MUST include a migration mapping for CLI/C API/C++ API consumers.

#### Scenario: Release candidate checks migration completeness
- **GIVEN** a breaking release candidate
- **WHEN** release validation is executed
- **THEN** migration guide and old-to-new mapping tables MUST be present
- **AND** at least one consumer-facing example MUST build with the new interfaces
