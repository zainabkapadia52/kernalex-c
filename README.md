# KernaLex Compiler

Lexical and syntax analyzer for the KernaLex programming language using Flex and Bison.

## Requirements

- GCC compiler
- Flex
- Bison
- make

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
./kernalex <file.kl>
```

**Parser:**
```bash
./kernalex_parser <file.kl>
```
