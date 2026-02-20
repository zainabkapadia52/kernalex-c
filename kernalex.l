%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"

int line_num = 1;
int column_num = 1;
int string_start_col = 0;
int string_start_line = 0;
int char_start_col = 0;
int char_start_line = 0;
int comment_start_col = 0;
int comment_start_line = 0;

// Track position: count newlines for line numbers, position in line for columns
int token_start_col = 0;

// Process position tracking for a token
// Saves starting position, then updates for next token
void process_token(const char *text, int save_start) {
    if (save_start) {
        token_start_col = column_num;
    }
    
    // Update position based on text
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            line_num++;
            column_num = 1;
        } else {
            column_num++;
        }
    }
}

// Validate escape sequences in strings and characters
int is_valid_escape(char c) {
    return (c == 'n' || c == 't' || c == 'r' || c == '\\' || 
            c == '"' || c == '\'' || c == 'b' || c == 'f' || 
            c == 'v' || c == '0' || c == 'x' || c == 'u');
}
%}

%option noyywrap
%option yylineno

%x COMMENT_ML
%x STRING_STATE
%x CHAR_STATE

%%

"/**"               { 
    token_start_col = column_num;
    column_num++;  // '/**' is 3 chars
    column_num++;
    column_num++;
    comment_start_line = line_num;
    comment_start_col = token_start_col;
    BEGIN(COMMENT_ML); 
}
<COMMENT_ML>"*/"    { process_token(yytext, 0); BEGIN(INITIAL); }
<COMMENT_ML>\n      { line_num++; column_num = 1; }
<COMMENT_ML>.       { column_num++; }
<COMMENT_ML><<EOF>> {
    printf("[ERROR: Line %d, Col %d: Unterminated multi-line comment]\n", 
           comment_start_line, comment_start_col);
    return 0;
}

"///".*             { process_token(yytext, 1); printf("[DOC_COMMENT: %s]\n", yytext); }

"#".*               { process_token(yytext, 1); printf("[COMMENT: %s]\n", yytext); }

[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?  { process_token(yytext, 1); printf("[FLOAT_LIT: %s] (Token #%d)\n", yytext, TOK_FLOAT_LIT); }
[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?  { process_token(yytext, 1); printf("[FLOAT_LIT: %s] (Token #%d)\n", yytext, TOK_FLOAT_LIT); }

0b[01]+                          { process_token(yytext, 1); printf("[INTEGER: %s] (Token #%d)\n", yytext, TOK_INTEGER); }
0o[0-7]+                          { process_token(yytext, 1); printf("[INTEGER: %s] (Token #%d)\n", yytext, TOK_INTEGER); }
0x[0-9a-fA-F]+                    { process_token(yytext, 1); printf("[INTEGER: %s] (Token #%d)\n", yytext, TOK_INTEGER); }
[0-9]+                            { process_token(yytext, 1); printf("[INTEGER: %s] (Token #%d)\n", yytext, TOK_INTEGER); }

\"([^\\"\n]|\\.)*\"                { 
    process_token(yytext, 1); 
    printf("[STRING_LIT: %s] (Token #%d)\n", yytext, TOK_STRING_LIT); 
}

\"([^\\"\n]|\\.)*\n|\"([^\\"\n]|\\.)*$  {
    string_start_line = line_num;
    string_start_col = column_num;  // Position of the opening quote
    if (yytext[yyleng-1] == '\n') {
        line_num++;
        column_num = 1;
    } else {
        process_token(yytext, 0);
    }
    printf("[ERROR: Line %d, Col %d: Unterminated string literal]\n", 
           string_start_line, string_start_col);
}

\"                                  {
    token_start_col = column_num;
    string_start_line = line_num;
    string_start_col = token_start_col;
    column_num++;  // Consume the quote
    BEGIN(STRING_STATE);
}

<STRING_STATE>[^"\\\n]*\"           {
    process_token(yytext, 0);
    printf("[STRING_LIT: \"%s] (Token #%d)\n", yytext, TOK_STRING_LIT);
    BEGIN(INITIAL);
}

<STRING_STATE>[^"\\\n]+             {
    for (int i = 0; yytext[i] != '\0'; i++) {
        column_num++;
    }
}

<STRING_STATE>\\\n                  {
    line_num++;
    column_num = 1;
}

<STRING_STATE>\\[^"\n]              {
    column_num += 2;  // '\' + next char
}

<STRING_STATE>\n                    {
    line_num++;
    column_num = 1;
    printf("[ERROR: Line %d, Col %d: Unterminated string literal]\n", 
           string_start_line, string_start_col);
    BEGIN(INITIAL);
}

<STRING_STATE><<EOF>>               {
    printf("[ERROR: Line %d, Col %d: Unterminated string literal at EOF]\n", 
           string_start_line, string_start_col);
    return 0;
}

\'\'                                {
    token_start_col = column_num;
    column_num += 2;  // Two quotes
    printf("[ERROR: Line %d, Col %d: Empty character literal]\n", line_num, token_start_col);
}

\'([^\\'\n]|\\.)?\'                 {
    token_start_col = column_num;
    char_start_col = token_start_col;
    process_token(yytext, 0);
    
    if (yyleng == 4 && yytext[1] == '\\') {
        // Escape sequence - allowed
        printf("[CHAR_LIT: %s] (Token #%d)\n", yytext, TOK_CHAR_LIT);
    } else if (yyleng == 3) {
        // Single character - allowed
        printf("[CHAR_LIT: %s] (Token #%d)\n", yytext, TOK_CHAR_LIT);
    } else if (yyleng > 4) {
        // Multiple characters in single quotes
        printf("[ERROR: Line %d, Col %d: Multiple characters in character literal]\n", 
               line_num, char_start_col);
    }
}

\'([^\\'\n]|\\.)*\n|\'([^\\'\n]|\\.)*$  {
    char_start_line = line_num;
    char_start_col = column_num;
    if (yytext[yyleng-1] == '\n') {
        line_num++;
        column_num = 1;
    } else {
        process_token(yytext, 0);
    }
    printf("[ERROR: Line %d, Col %d: Unterminated character literal]\n", 
           char_start_line, char_start_col);
}

\'                                  {
    token_start_col = column_num;
    char_start_line = line_num;
    char_start_col = token_start_col;
    column_num++;  // Consume the quote
    BEGIN(CHAR_STATE);
}

<CHAR_STATE>[^'\\\n]*\'             {
    process_token(yytext, 0);
    printf("[CHAR_LIT: '%s] (Token #%d)\n", yytext, TOK_CHAR_LIT);
    BEGIN(INITIAL);
}

<CHAR_STATE>[^'\\\n]+               {
    for (int i = 0; yytext[i] != '\0'; i++) {
        column_num++;
    }
}

<CHAR_STATE>\\\n                    {
    line_num++;
    column_num = 1;
}

<CHAR_STATE>\\[^'\n]                {
    column_num += 2;
}

<CHAR_STATE>\n                      {
    line_num++;
    column_num = 1;
    printf("[ERROR: Line %d, Col %d: Unterminated character literal]\n", 
           char_start_line, char_start_col);
    BEGIN(INITIAL);
}

<CHAR_STATE><<EOF>>                 {
    printf("[ERROR: Line %d, Col %d: Unterminated character literal at EOF]\n", 
           char_start_line, char_start_col);
    return 0;
}

"int8_t"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_INT8_T); }
"int16_t"   { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_INT16_T); }
"int32_t"   { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_INT32_T); }
"int64_t"   { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_INT64_T); }
"int"       { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_INT); }
"short"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_SHORT); }
"float"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_FLOAT); }
"char"      { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_CHAR); }
"void"      { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_VOID); }
"bool"      { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_BOOL); }
"boolean"   { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_BOOLEAN); }
"struct"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_STRUCT); }
"signed"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_SIGNED); }
"unsigned"  { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_UNSIGNED); }
"extern"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_EXTERN); }
"static"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_STATIC); }
"if"        { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_IF); }
"else"      { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_ELSE); }
"for"       { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_FOR); }
"while"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_WHILE); }
"repeat"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_REPEAT); }
"until"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_UNTIL); }
"switch"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_SWITCH); }
"case"      { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_CASE); }
"default"   { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_DEFAULT); }
"break"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_BREAK); }
"continue"  { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_CONTINUE); }
"return"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_RETURN); }
"sizeof"    { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_SIZEOF); }
"begin"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_BEGIN); }
"end"       { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_END); }
"true"      { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_TRUE); }
"false"     { process_token(yytext, 1); printf("[KEYWORD: %s] (Token #%d)\n", yytext, TOK_FALSE); }

"<=>"   { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_SPACESHIP); }
"^^"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_XOR); }
"<<"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_LSHIFT); }
">>"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_RSHIFT); }
"+="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_PLUSEQ); }
"-="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_MINUSEQ); }
"^="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_MULTEQ); }
"/="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_DIVEQ); }
"%="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_MODEQ); }
"=="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_EQ); }
"!="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_NE); }
"<="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_LE); }
">="    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_GE); }
"&&"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_AND); }
"||"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_OR); }
"++"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_INC); }
"--"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_DEC); }
"->"    { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_ARROW); }

"+"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_PLUS); }
"-"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_MINUS); }
"*"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_STAR); }
"^"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_MULT); }
"/"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_DIV); }
"%"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_MOD); }
"="     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_ASSIGN); }
"<"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_LT); }
">"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_GT); }
"!"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_NOT); }
"&"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_AMP); }
"|"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_BITOR); }
"~"     { process_token(yytext, 1); printf("[OPERATOR: %s] (Token #%d)\n", yytext, TOK_BITNOT); }

"."     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_DOT); }
";"     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_SEMICOLON); }
","     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_COMMA); }
"("     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_LPAREN); }
")"     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_RPAREN); }
"{"     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_LBRACE); }
"}"     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_RBRACE); }
"["     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_LBRACKET); }
"]"     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_RBRACKET); }
":"     { process_token(yytext, 1); printf("[PUNCTUATION: %s] (Token #%d)\n", yytext, TOK_COLON); }

[a-zA-Z_][a-zA-Z0-9_]* {
    token_start_col = column_num;
    process_token(yytext, 0);
    if (yyleng <= 255) {
        printf("[IDENTIFIER: %s] (Token #%d)\n", yytext, TOK_IDENTIFIER);
    } else {
        printf("[ERROR: Line %d, Col %d: Identifier too long (max 255)]\n", 
               line_num, token_start_col);
    }
}

[ \t]+  { for (int i = 0; yytext[i] != '\0'; i++) { column_num++; } }

\n      { line_num++; column_num = 1; }

.       { 
    int err_col = column_num;
    printf("[ERROR: Line %d, Col %d: Unknown/Invalid character '%c' (ASCII %d)]\n", 
           line_num, err_col, yytext[0], (unsigned char)yytext[0]); 
    column_num++;
}

<<EOF>> { return 0; }

%%

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
            return 1;
        }
    }
    
    printf("=== KernaLex Lexical Analyzer ===\n");
    if (argc > 1) {
        printf("Input file: %s\n", argv[1]);
    } else {
        printf("Reading from stdin...\n");
    }
    printf("====================================\n\n");
    
    yylex();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    printf("\n=== End of input ===\n");
    return 0;
}
