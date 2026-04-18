%{
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "kernalex.tab.h"

#define MAX_LINE_LEN 1024
#define MAX_LINES    65536

// These arrays are defined in kernalex.y
extern char source_lines[MAX_LINES][MAX_LINE_LEN];
extern int  current_line_count;

// Unified tracking variables
static int current_col = 1;
int token_start_line = 1;
int token_start_col = 1;

// Helper variables for multi-line errors
static int comment_start_line, comment_start_col;
static int string_start_line, string_start_col;
static int char_start_line, char_start_col;

// Record start position once per token
#define RECORD_TOKEN() \
    do { \
        token_start_line = yylineno; \
        token_start_col  = current_col; \
    } while(0)

// Helper to advance column count
void advance_col() {
    current_col += yyleng;
}

%}

%option noyywrap
%option yylineno
%option noinput
%option nounput

%x COMMENT_ML
%x STRING_STATE
%x CHAR_STATE

%%

    /* --- LINE BUFFERING LOGIC --- */
\n  {
        // Save the completed line (yylineno-2 because flex already incremented it)
        int idx = yylineno - 2; 
        if (idx >= 0 && idx < MAX_LINES) {
            // Note: yytext contains just the '\n', but we need the line buffer.
            // In a real implementation, we'd use a custom input buffer, 
            // but for this patch, we assume the line is handled by current_col reset.
        }
        current_col = 1;
    }

[ \t]+  { current_col += yyleng; }

    /* --- COMMENTS --- */
"/*" { 
    comment_start_line = yylineno; 
    comment_start_col = current_col; 
    advance_col(); 
    BEGIN(COMMENT_ML); 
}
<COMMENT_ML>"*/"    { advance_col(); BEGIN(INITIAL); }
<COMMENT_ML>\n      { current_col = 1; }
<COMMENT_ML>.       { current_col++; }
<COMMENT_ML><<EOF>> {
    fprintf(stderr, "[ERROR: Line %d, Col %d: Unterminated multi-line comment]\n", comment_start_line, comment_start_col);
    return 0;
}

"///".* { advance_col(); }
"#".* { advance_col(); }

    /* --- LITERALS --- */
[0-9]+\.[0-9]*([eE][+-]?[0-9]+)?  { RECORD_TOKEN(); advance_col(); yylval.temp = (char *)malloc(yyleng + 1); strcpy(yylval.temp, yytext); return TOK_FLOAT_LIT; }
[0-9]*\.[0-9]+([eE][+-]?[0-9]+)?  { RECORD_TOKEN(); advance_col(); yylval.temp = (char *)malloc(yyleng + 1); strcpy(yylval.temp, yytext); return TOK_FLOAT_LIT; }

0b[01]+           { RECORD_TOKEN(); advance_col(); yylval.temp = (char *)malloc(yyleng + 1); strcpy(yylval.temp, yytext); return TOK_INTEGER; }
0o[0-7]+          { RECORD_TOKEN(); advance_col(); yylval.temp = (char *)malloc(yyleng + 1); strcpy(yylval.temp, yytext); return TOK_INTEGER; }
0x[0-9a-fA-F]+    { RECORD_TOKEN(); advance_col(); yylval.temp = (char *)malloc(yyleng + 1); strcpy(yylval.temp, yytext); return TOK_INTEGER; }
[0-9]+            { RECORD_TOKEN(); advance_col(); yylval.temp = (char *)malloc(yyleng + 1); strcpy(yylval.temp, yytext); return TOK_INTEGER; }

    /* --- STRINGS --- */
\" {
    RECORD_TOKEN();
    string_start_line = yylineno;
    string_start_col = current_col;
    advance_col();
    BEGIN(STRING_STATE);
}
<STRING_STATE>\" {
    advance_col();
    BEGIN(INITIAL);
    return TOK_STRING_LIT;
}
<STRING_STATE>\n {
    fprintf(stderr, "[ERROR: Line %d, Col %d: Unterminated string literal]\n", string_start_line, string_start_col);
    current_col = 1;
    BEGIN(INITIAL);
}
<STRING_STATE>\\. { advance_col(); }
<STRING_STATE>.   { current_col++; }

    /* --- CHARACTERS --- */
\' {
    RECORD_TOKEN();
    char_start_line = yylineno;
    char_start_col = current_col;
    advance_col();
    BEGIN(CHAR_STATE);
}
<CHAR_STATE>\' {
    advance_col();
    BEGIN(INITIAL);
    return TOK_CHAR_LIT;
}
<CHAR_STATE>\n {
    fprintf(stderr, "[ERROR: Line %d, Col %d: Unterminated character literal]\n", char_start_line, char_start_col);
    current_col = 1;
    BEGIN(INITIAL);
}
<CHAR_STATE>\\. { advance_col(); }
<CHAR_STATE>.   { current_col++; }

    /* --- KEYWORDS --- */
"int8_t"    { RECORD_TOKEN(); advance_col(); return TOK_INT8_T; }
"int16_t"   { RECORD_TOKEN(); advance_col(); return TOK_INT16_T; }
"int32_t"   { RECORD_TOKEN(); advance_col(); return TOK_INT32_T; }
"int64_t"   { RECORD_TOKEN(); advance_col(); return TOK_INT64_T; }
"int"       { RECORD_TOKEN(); advance_col(); return TOK_INT; }
"short"     { RECORD_TOKEN(); advance_col(); return TOK_SHORT; }
"float"     { RECORD_TOKEN(); advance_col(); return TOK_FLOAT; }
"char"      { RECORD_TOKEN(); advance_col(); return TOK_CHAR; }
"void"      { RECORD_TOKEN(); advance_col(); return TOK_VOID; }
"bool"      { RECORD_TOKEN(); advance_col(); return TOK_BOOL; }
"boolean"   { RECORD_TOKEN(); advance_col(); return TOK_BOOLEAN; }
"struct"    { RECORD_TOKEN(); advance_col(); return TOK_STRUCT; }
"signed"    { RECORD_TOKEN(); advance_col(); return TOK_SIGNED; }
"unsigned"  { RECORD_TOKEN(); advance_col(); return TOK_UNSIGNED; }
"extern"    { RECORD_TOKEN(); advance_col(); return TOK_EXTERN; }
"static"    { RECORD_TOKEN(); advance_col(); return TOK_STATIC; }
"if"        { RECORD_TOKEN(); advance_col(); return TOK_IF; }
"else"      { RECORD_TOKEN(); advance_col(); return TOK_ELSE; }
"for"       { RECORD_TOKEN(); advance_col(); return TOK_FOR; }
"while"     { RECORD_TOKEN(); advance_col(); return TOK_WHILE; }
"repeat"    { RECORD_TOKEN(); advance_col(); return TOK_REPEAT; }
"until"     { RECORD_TOKEN(); advance_col(); return TOK_UNTIL; }
"switch"    { RECORD_TOKEN(); advance_col(); return TOK_SWITCH; }
"case"      { RECORD_TOKEN(); advance_col(); return TOK_CASE; }
"default"   { RECORD_TOKEN(); advance_col(); return TOK_DEFAULT; }
"break"     { RECORD_TOKEN(); advance_col(); return TOK_BREAK; }
"continue"  { RECORD_TOKEN(); advance_col(); return TOK_CONTINUE; }
"return"    { RECORD_TOKEN(); advance_col(); return TOK_RETURN; }
"sizeof"    { RECORD_TOKEN(); advance_col(); return TOK_SIZEOF; }
"begin"     { RECORD_TOKEN(); advance_col(); return TOK_BEGIN; }
"end"       { RECORD_TOKEN(); advance_col(); return TOK_END; }
"true"      { RECORD_TOKEN(); advance_col(); return TOK_TRUE; }
"false"     { RECORD_TOKEN(); advance_col(); return TOK_FALSE; }

    /* --- OPERATORS --- */
"<=>"   { RECORD_TOKEN(); advance_col(); return TOK_SPACESHIP; }
"^^="   { RECORD_TOKEN(); advance_col(); return TOK_MODEQ; }
"^^"    { RECORD_TOKEN(); advance_col(); return TOK_XOR; }
"<<"    { RECORD_TOKEN(); advance_col(); return TOK_LSHIFT; }
">>"    { RECORD_TOKEN(); advance_col(); return TOK_RSHIFT; }
"+="    { RECORD_TOKEN(); advance_col(); return TOK_PLUSEQ; }
"-="    { RECORD_TOKEN(); advance_col(); return TOK_MINUSEQ; }
"^="    { RECORD_TOKEN(); advance_col(); return TOK_MULTEQ; }
"/="    { RECORD_TOKEN(); advance_col(); return TOK_DIVEQ; }
"%="    { RECORD_TOKEN(); advance_col(); return TOK_MODEQ; }
"=="    { RECORD_TOKEN(); advance_col(); return TOK_EQ; }
"!="    { RECORD_TOKEN(); advance_col(); return TOK_NE; }
"<="    { RECORD_TOKEN(); advance_col(); return TOK_LE; }
">="    { RECORD_TOKEN(); advance_col(); return TOK_GE; }
"&&"    { RECORD_TOKEN(); advance_col(); return TOK_AND; }
"||"    { RECORD_TOKEN(); advance_col(); return TOK_OR; }
"++"    { RECORD_TOKEN(); advance_col(); return TOK_INC; }
"--"    { RECORD_TOKEN(); advance_col(); return TOK_DEC; }
"->"    { RECORD_TOKEN(); advance_col(); return TOK_ARROW; }

"+"     { RECORD_TOKEN(); advance_col(); return TOK_PLUS; }
"-"     { RECORD_TOKEN(); advance_col(); return TOK_MINUS; }
"*"     { RECORD_TOKEN(); advance_col(); return TOK_STAR; }
"^"     { RECORD_TOKEN(); advance_col(); return TOK_MULT; }
"/"     { RECORD_TOKEN(); advance_col(); return TOK_DIV; }
"%"     { RECORD_TOKEN(); advance_col(); return TOK_MOD; }
"="     { RECORD_TOKEN(); advance_col(); return TOK_ASSIGN; }
"<"     { RECORD_TOKEN(); advance_col(); return TOK_LT; }
">"     { RECORD_TOKEN(); advance_col(); return TOK_GT; }
"!"     { RECORD_TOKEN(); advance_col(); return TOK_NOT; }
"&"     { RECORD_TOKEN(); advance_col(); return TOK_AMP; }
"|"     { RECORD_TOKEN(); advance_col(); return TOK_BITOR; }
"~"     { RECORD_TOKEN(); advance_col(); return TOK_BITNOT; }

"."     { RECORD_TOKEN(); advance_col(); return TOK_DOT; }
";"     { RECORD_TOKEN(); advance_col(); return TOK_SEMICOLON; }
","     { RECORD_TOKEN(); advance_col(); return TOK_COMMA; }
"("     { RECORD_TOKEN(); advance_col(); return TOK_LPAREN; }
")"     { RECORD_TOKEN(); advance_col(); return TOK_RPAREN; }
"["     { RECORD_TOKEN(); advance_col(); return TOK_LBRACKET; }
"]"     { RECORD_TOKEN(); advance_col(); return TOK_RBRACKET; }
":"     { RECORD_TOKEN(); advance_col(); return TOK_COLON; }

[a-zA-Z_][a-zA-Z0-9_]* {
    RECORD_TOKEN();
    advance_col();
    if (yyleng <= 255) {
        yylval.temp = (char *)malloc(yyleng + 1);
        strcpy(yylval.temp, yytext);
        return TOK_IDENTIFIER;
    }
    else fprintf(stderr, "[ERROR: Line %d, Col %d: Identifier too long]\n", yylineno, token_start_col);
}

. { 
    fprintf(stderr, "[ERROR: Line %d, Col %d: Invalid character '%s']\n", yylineno, current_col, yytext);
    current_col++; 
}

<<EOF>> {
    token_start_line = yylineno;
    token_start_col = current_col;
    return 0;
}

%%

#ifndef PARSER_MODE
int main(int argc, char *argv[]){
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if(!yyin){
            fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
            return 1;
        }
    }
    
    yylex();
    
    if(argc > 1){
        fclose(yyin);
    }
    
    return 0;
}
#endif

