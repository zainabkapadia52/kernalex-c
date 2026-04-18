# Parser Component

This folder contains the KernaLex Bison grammar, parser test cases, and the generated artifacts used in the report.

## Contents

```text
kernalex.y                  Bison grammar
kernalex_before.y           Original Bison grammar before conflict resolution
ir.h, ir.c                  IR structures and functions
kernalex_parser             Parser executable
run_*.sh                    Scripts to run tests for different parts
compare_conflicts.sh        Script to compare grammar conflicts
save_reverse_derivation.sh  Script to save AST/derivation trees
tests/                      Valid parser basic test inputs
part[1-4]_tests/            Tests segmented by assignment parts
overall_tests/              Comprehensive integration tests
error_diagnostics/          Malformed inputs and saved error outputs
reverse_derivation_tree/    Reverse derivation tree outputs
parsing_table/              Generated LALR(1) table and generator script
comparison_outputs/         Conflict comparison artifacts
```

## Build

The parser is built from the repository root with:

```bash
make parser
```

This generates the Bison parser, the lexer used by the parser, and the `parser/kernalex_parser` executable.

## Usage

```bash
./parser/kernalex_parser parser/tests/test_simple_all_features.kl
```

## Report Artifacts

### Conflict Resolution

The files in `comparison_outputs/` capture the before/after behavior for the grammar conflict fixes.

### Reverse Derivation Tree

The files in `reverse_derivation_tree/` show the stored reverse derivation tree output for selected inputs.

### Parsing Table

The files in `parsing_table/` contain the CSV export of the LALR(1) parsing table generated from `kernalex.output`.

### Error Diagnostics

The files in `error_diagnostics/` demonstrate detailed syntax errors with line, column, and offending token information.

### Test Suites

Comprehensive test suites are divided into specific assignment parts and an overall integration suite:
- [Part 1 Tests](part1_tests/README.md): Focuses on parsing expressions, operator precedence, and variable assignments.
- [Part 2 Tests](part2_tests/README.md): Covers control flow structures like `if-else` and loops (`while`, `for`, `repeat-until`).
- [Part 3 Tests](part3_tests/README.md): Handles combined combinations of mixed control flows and expressions.
- [Part 4 Tests](part4_tests/README.md): Validates syntax error handling, diagnostics, and unsupported language features.
- [Overall Tests](overall_tests/README.md): A comprehensive integration test suite validating all language features together.