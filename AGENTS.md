<!-- OPENSPEC:START -->
# OpenSpec Instructions

These instructions are for AI assistants working in this project.

Always open `@/openspec/AGENTS.md` when the request:
- Mentions planning or proposals (words like proposal, spec, change, plan)
- Introduces new capabilities, breaking changes, architecture shifts, or big performance/security work
- Sounds ambiguous and you need the authoritative spec before coding

Use `@/openspec/AGENTS.md` to learn:
- How to create and apply change proposals
- Spec format and conventions
- Project structure and guidelines

Keep this managed block so 'openspec update' can refresh the instructions.

<!-- OPENSPEC:END -->

# AGENTS

用中文回复



> Purpose: consistent, reliable Codex execution for complex tasks.

## Priorities
1. Correctness and safety over speed.
2. Clear scope and acceptance criteria before changes.
3. Automated verification whenever possible.
4. Small, reviewable commits and recoverable state.

## Commit policy
- 使用 Angular commit-log 格式：`type(scope): subject`。
- 按功能粒度拆分提交，避免把无关变更混在同一提交中。
- Issue CSV/TODO 的更新与对应功能改动放在同一提交内。

## E2E loop
E2E loop = plan → issues → implement → test → review → commit → regression.

## Safety
- Avoid destructive commands unless explicitly requested.
- Preserve backward compatibility unless asked to break it.
- Never expose secrets; redact if encountered.

## Output style
- Keep responses concise and structured.
- Provide file references with line numbers when editing.
- Always include risks and suggested next steps for non-trivial changes.
