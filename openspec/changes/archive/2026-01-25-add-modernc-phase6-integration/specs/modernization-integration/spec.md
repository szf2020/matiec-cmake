## ADDED Requirements
### Requirement: Modernization documentation
The system SHALL document the modern AST, type system, and codegen APIs in the
project documentation, including migration notes for removed legacy APIs.

#### Scenario: Migration guidance
- **WHEN** a user reads the modernization documentation
- **THEN** they can identify which legacy headers were removed and how to migrate

### Requirement: Performance regression checklist
The system SHALL provide a lightweight performance checklist or script to track
compiler performance regressions across releases.

#### Scenario: Performance check
- **WHEN** the performance checklist is executed
- **THEN** it reports baseline timing or size metrics for comparison

## REMOVED Requirements
### Requirement: Legacy compatibility adapter
**Reason**: The modern AST and visitor interfaces are fully adopted and no
longer require legacy oid*-based adapters.
**Migration**: Replace usage of legacy isitor_c and symbol_c adapters with
modern visitor interfaces and VisitorResult.
