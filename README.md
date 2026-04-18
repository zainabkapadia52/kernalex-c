# KernaLex Compiler

KernaLex is a Flex/Bison-based lexical and syntax analyzer for the KernaLex programming language.

## Requirements

- GCC compiler
- Flex
- Bison
- `make`

## Project Structure

```text
Makefile                      Build configuration
README.md                     
tokens.h                      Shared token definitions

lexer/                        Lexer component
  kernalex.l                  Flex source
  README.md                   Lexer documentation
  tests/                      Lexer test inputs

parser/                       Parser component
  kernalex.y                  Bison grammar
  kernalex_before.y           Original Bison grammar before conflict resolution
  ir.h, ir.c                  IR structures and functions
  run_*.sh                    Various bash scripts for running tests
  compare_conflicts.sh        Script to compare grammar conflicts
  save_reverse_derivation.sh  Script to save AST/derivation trees
  README.md                   Parser documentation
  tests/                      Parser basic test inputs
  part[1-4]_tests/            Specialized tests for different project parts
  overall_tests/              Comprehensive integration tests
  error_diagnostics/          Parser error examples and saved outputs
  parsing_table/              Generated LALR(1) tables and generation scripts
  reverse_derivation_tree/    Reverse derivation tree outputs
  comparison_outputs/         Conflict comparison artifacts

transition_diagrams/          Lexer DFA/state diagrams
```

## Build

```bash
make all            # Build lexer and parser
make lexer          # Build lexer only
make parser         # Build parser only
make clean          # Remove generated files
```

## Usage

### Lexer

```bash
./lexer/kernalex lexer/tests/test_input.kl
```

### Parser

```bash
./parser/kernalex_parser parser/tests/test_simple_all_features.kl
```

## Notes

- The lexer reports detailed token positions.
- The parser supports detailed syntax diagnostics, reverse derivation output, and generated LALR(1) tables.
