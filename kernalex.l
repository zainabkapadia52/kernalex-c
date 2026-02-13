%{
#include <stdio.h>
#include <string.h>
#include "tokens.h"

int line_num = 1;
int column_num = 1;

void update_column(const char *text) {
    for (int i = 0; text[i]; i++) {
        if (text[i] == '\n') {
            line_num++;
            column_num = 1;
        } else {
            column_num++;
        }
    }
}
%}

%option noyywrap
%option yylineno

%x COMMENT_ML

%%

"/**"               { update_column(yytext); BEGIN(COMMENT_ML); }
<COMMENT_ML>"*/"    { update_column(yytext); BEGIN(INITIAL); }
<COMMENT_ML>\n      { line_num++; column_num = 1; }
<COMMENT_ML>.       { update_column(yytext); }

"///".*             { update_column(yytext); printf("[DOC_COMMENT: %s]\n", yytext); }

"#".*               { update_column(yytext); printf("[COMMENT: %s]\n", yytext); }

[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?  { update_column(yytext); printf("[FLOAT_LIT: %s]\n", yytext); }
[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?  { update_column(yytext); printf("[FLOAT_LIT: %s]\n", yytext); }

0b[01]+                          { update_column(yytext); printf("[INTEGER: %s]\n", yytext); }
0o[0-7]+                          { update_column(yytext); printf("[INTEGER: %s]\n", yytext); }
0x[0-9a-fA-F]+                    { update_column(yytext); printf("[INTEGER: %s]\n", yytext); }
[0-9]+                            { update_column(yytext); printf("[INTEGER: %s]\n", yytext); }

\"([^\\"]|\\.)*\"                  { update_column(yytext); printf("[STRING_LIT: %s]\n", yytext); }

'([^\\']|\\.)'                     { update_column(yytext); printf("[CHAR_LIT: %s]\n", yytext); }

"int8_t"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"int16_t"   { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"int32_t"   { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"int64_t"   { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"int"       { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"short"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"float"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"char"      { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"void"      { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"bool"      { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"boolean"   { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"struct"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"signed"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"unsigned"  { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"extern"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"static"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"if"        { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"else"      { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"for"       { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"while"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"repeat"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"until"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"switch"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"case"      { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"default"   { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"break"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"continue"  { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"return"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"sizeof"    { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"begin"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"end"       { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"true"      { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }
"false"     { update_column(yytext); printf("[KEYWORD: %s]\n", yytext); }

"<=>"   { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"^^"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"<<"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
">>"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"+="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"-="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"^="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"/="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"%="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"=="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"!="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"<="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
">="    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"&&"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"||"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"++"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"--"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"->"    { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }

"+"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"-"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"*"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"^"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"/"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"%"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"="     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"<"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
">"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"!"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"&"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"|"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }
"~"     { update_column(yytext); printf("[OPERATOR: %s]\n", yytext); }

"."     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
";"     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
","     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
"("     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
")"     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
"["     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
"]"     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }
":"     { update_column(yytext); printf("[PUNCTUATION: %s]\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]* {
    update_column(yytext);
    if (yyleng <= 255) {
        printf("[IDENTIFIER: %s]\n", yytext);
    } else {
        printf("[ERROR: Identifier too long (max 255)]\n");
    }
}

[ \t]+  { update_column(yytext); }

\n      { line_num++; column_num = 1; }

.       { update_column(yytext); printf("[ERROR: Unknown character '%s']\n", yytext); }

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
