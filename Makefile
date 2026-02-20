CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -Wextra -std=c99

# Directory structure
LEXER_DIR = lexer
PARSER_DIR = parser

# Output files
LEXER = $(LEXER_DIR)/kernalex
PARSER = $(PARSER_DIR)/kernalex_parser
LEXER_SRC = $(LEXER_DIR)/lex.yy.c
PARSER_LEX_SRC = $(PARSER_DIR)/lex_parser.yy.c
PARSER_TAB_C = $(PARSER_DIR)/kernalex.tab.c
PARSER_TAB_H = $(PARSER_DIR)/kernalex.tab.h

.PHONY: all clean lexer parser

all: lexer parser

# Lexer build 
lexer: $(LEXER)

$(LEXER_SRC): $(LEXER_DIR)/kernalex.l tokens.h
	$(FLEX) -o $(LEXER_SRC) $(LEXER_DIR)/kernalex.l

$(LEXER): $(LEXER_SRC)
	$(CC) $(CFLAGS) -I. -o $(LEXER) $(LEXER_SRC) $(LDFLAGS)

# Parser build 
parser: $(PARSER)

$(PARSER_TAB_C) $(PARSER_TAB_H): $(PARSER_DIR)/kernalex.y
	$(BISON) -d -o $(PARSER_TAB_C) $(PARSER_DIR)/kernalex.y

$(PARSER_LEX_SRC): $(PARSER_DIR)/kernalex_parser.l $(PARSER_TAB_H)
	$(FLEX) -o $(PARSER_LEX_SRC) $(PARSER_DIR)/kernalex_parser.l

$(PARSER): $(PARSER_TAB_C) $(PARSER_LEX_SRC)
	$(CC) $(CFLAGS) -I. -o $(PARSER) $(PARSER_TAB_C) $(PARSER_LEX_SRC)

clean:
	rm -f $(LEXER) $(PARSER) $(LEXER_SRC) $(PARSER_LEX_SRC) $(PARSER_TAB_C) $(PARSER_TAB_H) *.gch
