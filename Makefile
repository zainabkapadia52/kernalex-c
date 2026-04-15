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
PARSER_LEX_FILE = $(LEXER_DIR)/kernalex.l
PARSER_TAB_C = $(PARSER_DIR)/kernalex.tab.c
PARSER_TAB_H = $(PARSER_DIR)/kernalex.tab.h

.PHONY: all clean lexer parser part3-tests part4-tests lalr-table lalr-table-full lalr-table-important

all: parser lexer

# Lexer build 
lexer: $(LEXER)

$(LEXER_SRC): $(LEXER_DIR)/kernalex.l tokens.h
	$(FLEX) -o $(LEXER_SRC) $(LEXER_DIR)/kernalex.l

$(LEXER): $(LEXER_SRC)
	$(CC) $(CFLAGS) -I$(PARSER_DIR) -I. -o $(LEXER) $(LEXER_SRC) $(LDFLAGS)

# Parser build 
parser: $(PARSER)

part3-tests: parser
	bash parser/run_part3_tests.sh

part4-tests: parser
	bash parser/run_part4_tests.sh

lalr-table: lalr-table-full lalr-table-important

lalr-table-full: $(PARSER_DIR)/parsing_table/lalr1_table_full.csv

lalr-table-important: $(PARSER_DIR)/parsing_table/lalr1_table_important.csv

$(PARSER_TAB_C) $(PARSER_TAB_H) $(PARSER_OUTPUT): $(PARSER_DIR)/kernalex.y
	$(BISON) -v --graph=$(PARSER_DIR)/lalr1_automaton.vcg --report=states,lookaheads,solved -d -o $(PARSER_TAB_C) $(PARSER_DIR)/kernalex.y

$(PARSER_LEX_SRC): $(PARSER_LEX_FILE) $(PARSER_TAB_H)
	$(FLEX) -o $(PARSER_LEX_SRC) $(PARSER_LEX_FILE)

# $(PARSER): $(PARSER_TAB_C) $(PARSER_LEX_SRC)
# 	$(CC) $(CFLAGS) -DYYDEBUG=1 -DPARSER_MODE -I$(PARSER_DIR) -o $(PARSER) $(PARSER_TAB_C) $(PARSER_LEX_SRC)

$(PARSER): $(PARSER_TAB_C) $(PARSER_LEX_SRC) $(PARSER_DIR)/ir.c $(PARSER_DIR)/ir.h
	$(CC) $(CFLAGS) -DYYDEBUG=1 -DPARSER_MODE -I$(PARSER_DIR) -o $(PARSER) $(PARSER_TAB_C) $(PARSER_LEX_SRC) $(PARSER_DIR)/ir.c

$(PARSER_DIR)/parsing_table/lalr1_table_full.csv: $(PARSER_DIR)/kernalex.output $(PARSER_DIR)/parsing_table/generate_lalr_table.py
	python3 $(PARSER_DIR)/parsing_table/generate_lalr_table.py $(PARSER_DIR)/kernalex.output $(PARSER_DIR)/parsing_table/lalr1_table_full

$(PARSER_DIR)/parsing_table/lalr1_table_important.csv: $(PARSER_DIR)/kernalex.output $(PARSER_DIR)/parsing_table/generate_lalr_table.py $(PARSER_DIR)/parsing_table/important_states.txt
	python3 $(PARSER_DIR)/parsing_table/generate_lalr_table.py $(PARSER_DIR)/kernalex.output $(PARSER_DIR)/parsing_table/lalr1_table_important --states-file $(PARSER_DIR)/parsing_table/important_states.txt

clean:
	rm -f $(LEXER) $(PARSER) $(LEXER_SRC) $(PARSER_LEX_SRC) $(PARSER_TAB_C) $(PARSER_TAB_H) *.gch \
	$(PARSER_DIR)/parsing_table/lalr1_table_full.csv \
	$(PARSER_DIR)/parsing_table/lalr1_table_important.csv
