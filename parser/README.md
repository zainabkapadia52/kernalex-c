# Parser Component

This folder contains the KernaLex Bison grammar, parser test cases, and the generated artifacts used in the report.

## Contents

```
kernalex.y                Bison grammar
kernalex_parser           Parser executable
tests/                    Valid parser test inputs
error_diagnostics/        Malformed inputs and saved error outputs
reverse_derivation_tree/   Reverse derivation tree outputs
parsing_table/             Generated LALR(1) table CSV files and generator script
comparison_outputs/       Conflict comparison outputs
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