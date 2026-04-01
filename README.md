# KernaLex Compiler

KernaLex is a Flex/Bison-based lexical and syntax analyzer for the KernaLex programming language.

## Requirements

- GCC compiler
- Flex
- Bison
- `make`

## Project Structure

```
lexer/                Lexer component
  kernalex.l          Flex source
  kernalex            Lexer executable
  tests/              Lexer test inputs
  README.md           Lexer documentation

parser/               Parser component
  kernalex.y          Bison grammar
  kernalex_parser      Parser executable
  tests/               Parser test inputs
  error_diagnostics/   Parser error examples and saved outputs
  parsing_table/       Generated LALR(1) tables
  reverse_derivation_tree/  Reverse derivation tree outputs
  comparison_outputs/  Conflict comparison artifacts
  README.md           Parser documentation

transition_diagrams/   Lexer DFA/state diagrams
tokens.h               Shared token definitions
```

## Build

```bash
make all            # Build lexer and parser
make lexer          # Build lexer only
make parser         # Build parser only
make lalr-table     # Generate parser table CSV outputs
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
