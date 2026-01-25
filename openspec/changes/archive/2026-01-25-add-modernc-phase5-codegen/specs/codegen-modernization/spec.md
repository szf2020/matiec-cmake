## ADDED Requirements
### Requirement: CodeEmitter utility
The system SHALL provide a CodeEmitter utility for indentation, line output,
and block helpers used by code generators.

#### Scenario: Indentation for nested blocks
- **WHEN** a nested block is emitted
- **THEN** lines inside the block are indented by 4 spaces per level

### Requirement: Codegen uses structured emitter
The system SHALL use CodeEmitter for C and IEC code generation to produce
stable, deterministic output.

#### Scenario: Output stability
- **WHEN** code is generated for a fixed fixture
- **THEN** the output matches the stored baseline for that fixture
