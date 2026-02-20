CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

# Output files
LEXER = kernalex
PARSER = kernalex_parser
LEXER_SRC = lex.yy.c
PARSER_LEX_SRC = lex_parser.yy.c
PARSER_TAB_C = kernalex.tab.c
PARSER_TAB_H = kernalex.tab.h
TEST_INPUT = test_input.kl
TEST_OUTPUT = test_output.txt

.PHONY: all clean help test test-parser lexer parser

all: lexer parser

# Lexer-only build (original standalone lexer)
lexer: $(LEXER)

$(LEXER_SRC): kernalex.l tokens.h
	$(FLEX) -o $(LEXER_SRC) kernalex.l

$(LEXER): $(LEXER_SRC)
	$(CC) $(CFLAGS) -o $(LEXER) $(LEXER_SRC) $(LDFLAGS)

# Parser build (lexer + parser combined)
parser: $(PARSER)

$(PARSER_TAB_C) $(PARSER_TAB_H): kernalex.y
	$(BISON) -d -o $(PARSER_TAB_C) kernalex.y

$(PARSER_LEX_SRC): kernalex_parser.l $(PARSER_TAB_H)
	$(FLEX) -o $(PARSER_LEX_SRC) kernalex_parser.l

$(PARSER): $(PARSER_TAB_C) $(PARSER_LEX_SRC)
	$(CC) $(CFLAGS) -o $(PARSER) $(PARSER_TAB_C) $(PARSER_LEX_SRC) $(LDFLAGS)

test: $(LEXER) $(TEST_INPUT)
	@echo "=== Testing Lexer (Token Generation) ==="
	./$(LEXER) $(TEST_INPUT) | tee $(TEST_OUTPUT)

test-parser: $(PARSER) $(TEST_INPUT)
	@echo "=== Testing Parser (Syntax Analysis) ==="
	./$(PARSER) $(TEST_INPUT)

clean:
	rm -f $(LEXER) $(PARSER) $(LEXER_SRC) $(PARSER_LEX_SRC) $(PARSER_TAB_C) $(PARSER_TAB_H) $(TEST_OUTPUT) *.gch

help:
	@echo "KernaLex Compiler - Makefile targets:"
	@echo ""
	@echo "  make all          - Build both lexer and parser"
	@echo "  make lexer        - Build standalone lexer only"
	@echo "  make parser       - Build parser (includes lexer)"
	@echo "  make test         - Run lexer on test input file"
	@echo "  make test-parser  - Run parser on test input file"
	@echo "  make clean        - Remove all generated files"
	@echo "  make help         - Show this message"
	@echo ""
	@echo "Usage:"
	@echo "  ./$(LEXER) <input_file>   - Tokenize a file (lexer only)"
	@echo "  ./$(PARSER) <input_file>  - Parse a file (check syntax)"
