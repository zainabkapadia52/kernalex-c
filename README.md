# KernaLex Lexical Analyzer

A lexical analyzer for the KernaLex programming language specification, built using Flex (Fast Lexical Analyzer Generator).

## Project Structure

```
kernalex-c/
├── kernalex.l # Lexer specification file (Flex source)
├── tokens.h # Token type definitions
├── Makefile # Build configuration
├── test_input.kl # Sample KernaLex source code for testing
└── lex.yy.c # Generated lexer (created by make)
```

## Implemented Features

### 1. Comments
- **Single-line comment**: `# comment text`
- **Documentation comment**: `/// documentation`
- **Multi-line documentation**: `/** multi-line content */`
- **NOT supported**: C-style `/* */` comments

### 2. Keywords

#### Type Keywords
- `int`, `short`, `float`, `char`, `void`, `bool`, `boolean`, `struct`
- `int8_t`, `int16_t`, `int32_t`, `int64_t`

#### Type Modifiers/Storage 
- `signed`, `unsigned`, `extern`, `static`

#### Control Flow
- `if`, `else`, `for`, `while`, `repeat`, `until`, `switch`, `case`, `default`, `break`, `continue`, `return`

#### Other Keywords 
- `sizeof`, `begin`, `end`, `true`, `false`

### 3. Identifiers
- Pattern: `[a-zA-Z_][a-zA-Z0-9_]*`
- Maximum length: 255 characters
- Properly distinguished from keywords

### 4. Additional Features
The lexer also recognizes and tokenizes:
- **Integer literals**: decimal, binary (0b), octal (0o), hexadecimal (0x)
- **Float literals**: standard and scientific notation
- **Character literals**: single characters with escape sequences
- **String literals**: double-quoted strings with escape sequences
- **Operators**: arithmetic, relational, logical, bitwise, compound assignment, etc.
- **Punctuation**: semicolons, commas, parentheses, brackets, arrows, etc.

## Building the Lexer

### Prerequisites
- **Flex** (Fast Lexical Analyzer Generator)
- **GCC** (GNU C Compiler)
- **Make**

### Build Instructions

On macOS:
```bash
# Install Flex if needed
brew install flex

# Build the lexer
make all
```

On Linux:
```bash
# Install Flex if needed
sudo apt-get install flex

# Build the lexer
make all
```

The build process:
1. Runs `flex` to generate `lex.yy.c` from `kernalex.l`
2. Compiles the generated C code with `gcc`
3. Creates the executable `kernalex`

## Running the Lexer

### Analyze a file:
```bash
./kernalex test_input.kl
```

### Read from stdin:
```bash
./kernalex
# Then type or paste KernaLex code
# Press Ctrl+D (Unix/Mac) or Ctrl+Z (Windows) to end input
```

### Run test suite:
```bash
make test
```

This will analyze the included `test_input.kl` and save output to `test_output.txt`.

## Output Format

The lexer prints tokens in the format:
```
[TOKEN_TYPE: value]
```

Examples:
```
[KEYWORD: int]
[IDENTIFIER: myVariable]
[INTEGER: 42]
[FLOAT_LIT: 3.14]
[OPERATOR: +=]
[COMMENT: # This is a comment]
[DOC_COMMENT: /// Documentation]
[PUNCTUATION: ;]
```

## Token Types

See [tokens.h](tokens.h) for the complete enumeration of token types including:
- Keywords (all 33 types)
- Identifiers
- Integer/Float/String/Character literals
- Various operators and punctuation
- Unknown tokens and errors

## Lexer Features

- **Line/Column tracking**: Tracks current position in source code
- **Error handling**: Reports unknown characters with location information
- **Multi-line comment support**: Uses Flex start conditions to handle `/** */` comments
- **Comprehensive pattern matching**: Handles all token types specified in KernaLex language specification
- **Case sensitivity**: Keywords are case-sensitive (proper identifier keywords distinguished)

## Testing

The `test_input.kl` file demonstrates:
- All comment types (including invalid C-style comments for testing)
- All keywords
- Various identifier patterns
- Integer and float literals in different formats
- Operators and operators compounds
- Punctuation and special characters

## Cleaning Up

To remove generated files:
```bash
make clean
```

This removes:
- The `kernalex` executable
- The generated `lex.yy.c` file
- Test output file

## Notes

- The lexer outputs all recognized tokens to stdout
- Comments are printed as `[COMMENT: ...]` or `[DOC_COMMENT: ...]` for reference but don't produce regular tokens
- Whitespace is skipped but line/column numbers are tracked
- The implementation uses Flex's `%option noyywrap` for standalone operation without requiring a library wrapper
- Maximum identifier length is validated against the 255-character limit

## Future Extensions

Possible enhancements:
- Symbol table for identifier management
- Token position tracking for error reporting
- Semantic analysis integration
- Parser integration (grammar rules)
- Code generation backend
