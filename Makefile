CC = gcc
FLEX = flex
BISON = bison
CFLAGS = -Wall -Wextra -std=c99

# Output files
LEXER = kernalex
PARSER = kernalex_parser
LEXER_SRC = lex.yy.c
PARSER_LEX_SRC = lex_parser.yy.c
PARSER_TAB_C = kernalex.tab.c
PARSER_TAB_H = kernalex.tab.h

.PHONY: all clean lexer parser

all: lexer parser

# Lexer build 
lexer: $(LEXER)

$(LEXER_SRC): kernalex.l tokens.h
	$(FLEX) -o $(LEXER_SRC) kernalex.l

$(LEXER): $(LEXER_SRC)
	$(CC) $(CFLAGS) -o $(LEXER) $(LEXER_SRC) $(LDFLAGS)

# Parser build 
parser: $(PARSER)

$(PARSER_TAB_C) $(PARSER_TAB_H): kernalex.y
	$(BISON) -d -o $(PARSER_TAB_C) kernalex.y

$(PARSER_LEX_SRC): kernalex_parser.l $(PARSER_TAB_H)
	$(FLEX) -o $(PARSER_LEX_SRC) kernalex_parser.l

$(PARSER): $(PARSER_TAB_C) $(PARSER_LEX_SRC)
	$(CC) $(CFLAGS) -o $(PARSER) $(PARSER_TAB_C) $(PARSER_LEX_SRC)

clean:
	rm -f $(LEXER) $(PARSER) $(LEXER_SRC) $(PARSER_LEX_SRC) $(PARSER_TAB_C) $(PARSER_TAB_H) *.gch
