# KernaLex Compiler

Lexical and syntax analyzer for the KernaLex programming language using Flex and Bison.

## Requirements

- GCC compiler
- Flex
- Bison
- make

## Project Structure

```
lexer/              Lexer component
  kernalex.l        Flex source
  kernalex          Executable
  tests/            Test files
  test_results.txt  Test output

parser/             Parser component
  kernalex.y        Bison grammar
  kernalex_parser.l Lexer for parser
  kernalex_parser   Executable
  tests/            Test files
  test_results.txt  Test output

transition_diagrams/ State transition diagrams (dot, png, svg)
tokens.h            Shared token definitions
```

## Lexer Features

**Keywords:** int, short, float, char, void, bool, struct, signed, unsigned, extern, static, if, else, for, while, repeat, until, switch, case, default, break, continue, return, sizeof, begin, end, true, false

**Numeric Literals:**
- Decimal: 42
- Binary: 0b1010
- Octal: 0o777
- Hexadecimal: 0xDEAD
- Float: 3.14, .5, 5., 1.5e10, 3.14e-2

**Operators:** +, -, ^, /, %, =, +=, -=, ^=, /=, %=, ++, --, ==, !=, <, <=, >, >=, <=>, &&, ||, !, &, |, ^^, ~, <<, >>, ->, *, &

**Comments:** # single-line, /// doc comments, /** multi-line **/

**Escape Sequences:** \n, \t, \r, \\, \', \", \b, \f, \v, \0

**Error Detection:** Position tracking, unterminated strings/chars/comments, invalid escape sequences

## Build

```bash
make all       # Build both lexer and parser
make lexer     # Build lexer only
make parser    # Build parser only
make clean     # Clean generated files
```

## Usage

**Lexer:**
```bash
./lexer/kernalex lexer/tests/test_input.kl
```

**Parser:**
```bash
./parser/kernalex_parser parser/tests/test_simple_all_features.kl
```
