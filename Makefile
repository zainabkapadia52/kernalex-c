CC = gcc
FLEX = flex
CFLAGS = -Wall -Wextra -std=c99
LDFLAGS =

# Output files
LEXER = kernalex
LEXER_SRC = lex.yy.c
TEST_INPUT = test_input.kl
TEST_OUTPUT = test_output.txt

.PHONY: all clean help test

all: $(LEXER)

$(LEXER_SRC): kernalex.l tokens.h
	$(FLEX) -o $(LEXER_SRC) kernalex.l

$(LEXER): $(LEXER_SRC)
	$(CC) $(CFLAGS) -o $(LEXER) $(LEXER_SRC) $(LDFLAGS)

test: $(LEXER) $(TEST_INPUT)
	./$(LEXER) $(TEST_INPUT) | tee $(TEST_OUTPUT)

clean:
	rm -f $(LEXER) $(LEXER_SRC) $(TEST_OUTPUT) *.gch

help:
	@echo "KernaLex Lexical Analyzer - Makefile targets:"
	@echo "  make all    - Build the lexer"
	@echo "  make test   - Run lexer on test input file"
	@echo "  make clean  - Remove generated files"
	@echo "  make help   - Show this message"
	@echo ""
	@echo "Usage:"
	@echo "  ./$(LEXER) <input_file>   - Analyze a file"
	@echo "  ./$(LEXER)                - Read from stdin"
