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

[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?  { process_token(yytext, 1); printf("[FLOAT_LIT: %s]\n", yytext); }
[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?  { process_token(yytext, 1); printf("[FLOAT_LIT: %s]\n", yytext); }

0b[01]+                          { process_token(yytext, 1); printf("[INTEGER: %s]\n", yytext); }
0o[0-7]+                          { process_token(yytext, 1); printf("[INTEGER: %s]\n", yytext); }
0x[0-9a-fA-F]+                    { process_token(yytext, 1); printf("[INTEGER: %s]\n", yytext); }
[0-9]+                            { process_token(yytext, 1); printf("[INTEGER: %s]\n", yytext); }

\"([^\\"\n]|\\.)*\"                { 
    process_token(yytext, 1); 
    printf("[STRING_LIT: %s]\n", yytext); 
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
    printf("[STRING_LIT: \"%s]\n", yytext);
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
        printf("[CHAR_LIT: %s]\n", yytext);
    } else if (yyleng == 3) {
        // Single character - allowed
        printf("[CHAR_LIT: %s]\n", yytext);
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
    printf("[CHAR_LIT: \'%s]\n", yytext);
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

"int8_t"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"int16_t"   { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"int32_t"   { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"int64_t"   { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"int"       { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"short"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"float"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"char"      { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"void"      { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"bool"      { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"boolean"   { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"struct"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"signed"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"unsigned"  { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"extern"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"static"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"if"        { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"else"      { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"for"       { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"while"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"repeat"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"until"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"switch"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"case"      { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"default"   { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"break"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"continue"  { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"return"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"sizeof"    { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"begin"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"end"       { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"true"      { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }
"false"     { process_token(yytext, 1); printf("[KEYWORD: %s]\n", yytext); }

"<=>"   { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"^^"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"<<"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
">>"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"+="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"-="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"^="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"/="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"%="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"=="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"!="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"<="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
">="    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"&&"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"||"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"++"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"--"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"->"    { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }

"+"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"-"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"*"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"^"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"/"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"%"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"="     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"<"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
">"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"!"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"&"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"|"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }
"~"     { process_token(yytext, 1); printf("[OPERATOR: %s]\n", yytext); }

"."     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
";"     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
","     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
"("     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
")"     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
"{"     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
"}"     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
"["     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
"]"     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }
":"     { process_token(yytext, 1); printf("[PUNCTUATION: %s]\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {
    token_start_col = column_num;
    process_token(yytext, 0);
    if (yyleng <= 255) {
        printf("[IDENTIFIER: %s]\n", yytext);
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
