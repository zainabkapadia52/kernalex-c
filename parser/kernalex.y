%{
#define _POSIX_C_SOURCE 200809L
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "ir.h"

extern char *yytext;
extern int token_start_line;
extern int token_start_col;

/* ─── source-line buffer (populated by the lexer) ─────────────────────── */
#define MAX_LINE_LEN 1024
#define MAX_LINES    65536
char source_lines[MAX_LINES][MAX_LINE_LEN];
int  current_line_count = 0;   /* how many lines have been stored so far   */

int yylex(void);
void yyerror(const char *s);
#if YYDEBUG
extern int yydebug;
#endif

int global_declarations=0;
int func_definitions=0;
int int_consts=0;
int pointer_decls=0;
int ifs_wo_else=0;
int ladder_len=0,hold=0;
int max=-1;

/* ─── forward declarations for diagnostic helpers ─────────────────────── */
static char *humanise(const char *raw_msg);
static void  emit_hint(const char *msg, const char *tok,
                       int line, int col);
static void  load_source_lines(FILE *fp);
static int   is_decl_starter(const char *tok);
static int   find_call_arg_start_col(const char *line, int before_col);
static int   is_control_paren_context(const char *line, int paren_col);
static int   find_prev_word_before_col(const char *line, int before_col,
									   char *out, size_t out_sz,
									   int *start_col, int *word_len);
static void  codegen_unsupported(const char *construct);
%}

%token TOK_INT 1
%token TOK_SHORT 2
%token TOK_FLOAT 3
%token TOK_CHAR 4
%token TOK_VOID 5
%token TOK_BOOL 6
%token TOK_BOOLEAN 7
%token TOK_STRUCT 8
%token TOK_INT8_T 9
%token TOK_INT16_T 10
%token TOK_INT32_T 11
%token TOK_INT64_T 12
%token TOK_SIGNED 13
%token TOK_UNSIGNED 14
%token TOK_EXTERN 15
%token TOK_STATIC 16
%token <val> TOK_IF 17
%token <val> TOK_ELSE 18
%token TOK_FOR 19
%token TOK_WHILE 20
%token TOK_REPEAT 21
%token TOK_UNTIL 22
%token TOK_SWITCH 23
%token TOK_CASE 24
%token TOK_DEFAULT 25
%token TOK_BREAK 26
%token TOK_CONTINUE 27
%token TOK_RETURN 28
%token TOK_SIZEOF 29
%token TOK_BEGIN 30
%token TOK_END 31
%token TOK_TRUE 32
%token TOK_FALSE 33
%token <temp> TOK_IDENTIFIER 34
%token <temp> TOK_INTEGER 35
%token <temp> TOK_FLOAT_LIT 36
%token <temp> TOK_CHAR_LIT 37
%token <temp> TOK_STRING_LIT 38
%token TOK_PLUS 39
%token TOK_MINUS 40
%token TOK_MULT 41
%token TOK_DIV 42
%token TOK_MOD 43
%token TOK_ASSIGN 44
%token TOK_EQ 45
%token TOK_NE 46
%token TOK_LT 47
%token TOK_LE 48
%token TOK_GT 49
%token TOK_GE 50
%token TOK_SPACESHIP 51
%token TOK_AND 52
%token TOK_OR 53
%token TOK_NOT 54
%token TOK_BITOR 56
%token TOK_XOR 57
%token TOK_BITNOT 58
%token TOK_LSHIFT 59
%token TOK_RSHIFT 60
%token TOK_INC 61
%token TOK_DEC 62
%token TOK_PLUSEQ 63
%token TOK_MINUSEQ 64
%token TOK_MULTEQ 65
%token TOK_DIVEQ 66
%token TOK_MODEQ 67
%token TOK_ARROW 68
%token TOK_AMP 69
%token TOK_STAR 70
%token TOK_LPAREN 71
%token TOK_RPAREN 72
%token TOK_LBRACKET 75
%token TOK_RBRACKET 76
%token TOK_SEMICOLON 77
%token TOK_COMMA 78
%token TOK_DOT 79
%token TOK_COLON 80

%start translation_unit
%define parse.error detailed
%define parse.lac full


%union
{
    int val;
    struct symtab *symp;
    char *temp;  /* temporary variable or result name from expression */
}

/* Type declarations for non-terminals that return values */
%type <temp> primary_expression
%type <temp> constant
%type <temp> string
%type <temp> postfix_expression
%type <temp> unary_expression
%type <temp> cast_expression
%type <temp> multiplicative_expression
%type <temp> additive_expression
%type <temp> shift_expression
%type <temp> relational_expression
%type <temp> equality_expression
%type <temp> and_expression
%type <temp> exclusive_or_expression
%type <temp> inclusive_or_expression
%type <temp> logical_and_expression
%type <temp> logical_or_expression
%type <temp> conditional_expression
%type <temp> assignment_expression
%type <temp> expression
%type <temp> constant_expression
%type <temp> argument_expression_list
%type <temp> initializer
%type <temp> declarator
%type <temp> direct_declarator
%type <temp> expression_statement L_mark M_mark_stmt M_mark_expr if_head if_else_head
%type <val> M_quad_count


%%

primary_expression
    : TOK_IDENTIFIER { $$ = $1; }
    | constant { $$ = $1; }
    | string { $$ = $1; }
    | TOK_TRUE { $$ = (char *)malloc(5); strcpy($$, "true"); }
    | TOK_FALSE { $$ = (char *)malloc(6); strcpy($$, "false"); }
    | TOK_LPAREN expression TOK_RPAREN { $$ = $2; }
    ;

constant
    : TOK_INTEGER
    {
        int_consts++;
        $$ = $1;
    }
    | TOK_FLOAT_LIT { $$ = $1; }
    | TOK_CHAR_LIT  { $$ = $1; }
    ;

string
    : TOK_STRING_LIT { $$ = $1; }
    ;


postfix_expression
    : primary_expression { $$ = $1; }
    | postfix_expression TOK_LBRACKET expression TOK_RBRACKET { $$ = $1; }
    | postfix_expression TOK_LPAREN TOK_RPAREN { $$ = $1; }
    | postfix_expression TOK_LPAREN argument_expression_list TOK_RPAREN { $$ = $1; }
    | postfix_expression TOK_DOT TOK_IDENTIFIER { $$ = $1; }
    | postfix_expression TOK_ARROW TOK_IDENTIFIER { $$ = $1; }
	| postfix_expression TOK_INC { codegen_unsupported("postfix increment (x++)"); $$ = $1; }
	| postfix_expression TOK_DEC { codegen_unsupported("postfix decrement (x--)"); $$ = $1; }
    | TOK_LPAREN type_name TOK_RPAREN TOK_BEGIN initializer_list TOK_END { $$ = (char *)malloc(20); strcpy($$, "init_result"); }
    | TOK_LPAREN type_name TOK_RPAREN TOK_BEGIN initializer_list TOK_COMMA TOK_END { $$ = (char *)malloc(20); strcpy($$, "init_result"); }
    ;

argument_expression_list
    : assignment_expression { $$ = $1; }
    | argument_expression_list TOK_COMMA assignment_expression { $$ = $3; }
    ;

unary_expression
    : postfix_expression { $$ = $1; }
	| TOK_INC unary_expression { codegen_unsupported("prefix increment (++x)"); $$ = $2; }
	| TOK_DEC unary_expression { codegen_unsupported("prefix decrement (--x)"); $$ = $2; }
    | TOK_MINUS cast_expression
    {
        char *temp = new_temp();
        emit_quad("minus", $2, NULL, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | TOK_PLUS cast_expression { $$ = $2; }
    | TOK_NOT cast_expression
    {
        char *temp = new_temp();
        emit_quad("not", $2, NULL, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | TOK_BITNOT cast_expression
    {
        char *temp = new_temp();
        emit_quad("~", $2, NULL, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | TOK_AMP cast_expression
    {
        char *temp = new_temp();
        emit_quad("&", $2, NULL, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | TOK_STAR cast_expression
    {
        char *temp = new_temp();
        emit_quad("*", $2, NULL, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    ;

cast_expression
    : unary_expression { $$ = $1; }
    | TOK_LPAREN type_name TOK_RPAREN cast_expression { $$ = $4; }
    ;

multiplicative_expression
    : cast_expression { $$ = $1; }
    | multiplicative_expression TOK_MULT cast_expression
    {
        char *temp = new_temp();
        emit_quad("*", $1, $3, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | multiplicative_expression TOK_DIV cast_expression
    {
        char *temp = new_temp();
        emit_quad("/", $1, $3, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | multiplicative_expression TOK_MOD cast_expression
    {
        char *temp = new_temp();
        emit_quad("%", $1, $3, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    ;

additive_expression
    : multiplicative_expression { $$ = $1; }
    | additive_expression TOK_PLUS multiplicative_expression
    {
        char *temp = new_temp();
        emit_quad("+", $1, $3, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    | additive_expression TOK_MINUS multiplicative_expression
    {
        char *temp = new_temp();
        emit_quad("-", $1, $3, temp);
        $$ = (char *)malloc(strlen(temp) + 1);
        strcpy($$, temp);
    }
    ;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression TOK_LSHIFT additive_expression
	{
	    char *t = new_temp();
	    emit_quad("<<", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
	| shift_expression TOK_RSHIFT additive_expression
	{
	    char *t = new_temp();
	    emit_quad(">>", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
	;

relational_expression
    : shift_expression { $$ = $1; }
	| relational_expression TOK_LT shift_expression { char *t=new_temp(); emit_quad("<", $1, $3, t); $$ = strdup(t); }
	| relational_expression TOK_GT shift_expression { char *t=new_temp(); emit_quad(">", $1, $3, t); $$ = strdup(t); }
	| relational_expression TOK_LE shift_expression { char *t=new_temp(); emit_quad("<=", $1, $3, t); $$ = strdup(t); }
	| relational_expression TOK_GE shift_expression { char *t=new_temp(); emit_quad(">=", $1, $3, t); $$ = strdup(t); }
	| relational_expression TOK_SPACESHIP shift_expression { $$ = $3; }
    ;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression TOK_EQ relational_expression { char *t=new_temp(); emit_quad("==", $1, $3, t); $$ = strdup(t); }
	| equality_expression TOK_NE relational_expression { char *t=new_temp(); emit_quad("!=", $1, $3, t); $$ = strdup(t); }
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression TOK_AMP equality_expression
	{
	    char *t = new_temp();
	    emit_quad("&", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
	;

exclusive_or_expression
    : and_expression { $$ = $1; }
	| exclusive_or_expression TOK_XOR and_expression
	{
	    char *t = new_temp();
	    emit_quad("^", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
    ;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression TOK_BITOR exclusive_or_expression
	{
	    char *t = new_temp();
	    emit_quad("|", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
	;

logical_and_expression
	: inclusive_or_expression { $$ = $1; }
	| logical_and_expression TOK_AND inclusive_or_expression
	{
	    char *t = new_temp();
	    emit_quad("&&", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression TOK_OR logical_and_expression
	{
	    char *t = new_temp();
	    emit_quad("||", $1, $3, t);
	    $$ = (char *)malloc(strlen(t) + 1);
	    strcpy($$, t);
	}
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	;

assignment_expression
    : conditional_expression { $$ = $1; }
    | unary_expression TOK_ASSIGN assignment_expression
    {
        emit_quad("=", $3, NULL, $1);
        $$ = (char *)malloc(strlen($1) + 1);
        strcpy($$, $1);
    }
    | unary_expression TOK_PLUSEQ assignment_expression
    {
        char *t = new_temp();
        emit_quad("+", $1, $3, t);
        emit_quad("=", t, NULL, $1);
        $$ = (char *)malloc(strlen($1) + 1);
        strcpy($$, $1);
    }
    | unary_expression TOK_MINUSEQ assignment_expression
    {
        char *t = new_temp();
        emit_quad("-", $1, $3, t);
        emit_quad("=", t, NULL, $1);
        $$ = (char *)malloc(strlen($1) + 1);
        strcpy($$, $1);
    }
    | unary_expression TOK_MULTEQ assignment_expression
    {
        char *t = new_temp();
        emit_quad("*", $1, $3, t);
        emit_quad("=", t, NULL, $1);
        $$ = (char *)malloc(strlen($1) + 1);
        strcpy($$, $1);
    }
    | unary_expression TOK_DIVEQ assignment_expression
    {
        char *t = new_temp();
        emit_quad("/", $1, $3, t);
        emit_quad("=", t, NULL, $1);
        $$ = (char *)malloc(strlen($1) + 1);
        strcpy($$, $1);
    }
    | unary_expression TOK_MODEQ assignment_expression
    {
        char *t = new_temp();
        emit_quad("%", $1, $3, t);
        emit_quad("=", t, NULL, $1);
        $$ = (char *)malloc(strlen($1) + 1);
        strcpy($$, $1);
    }
    ;

expression
    : assignment_expression { $$ = $1; }
    | expression TOK_COMMA assignment_expression { $$ = $3; }
    ;

constant_expression
    : conditional_expression { $$ = $1; }	/* with constraints */
    ;

declaration
	: declaration_specifiers TOK_SEMICOLON
	| declaration_specifiers init_declarator_list TOK_SEMICOLON
	;

declaration_specifiers
	: storage_class_specifier declaration_specifiers
	| storage_class_specifier
	| type_specifier declaration_specifiers
	| type_specifier
	;

init_declarator_list
	: init_declarator
	| init_declarator_list TOK_COMMA init_declarator
	;

init_declarator
	: declarator TOK_ASSIGN initializer
	{
	    if ($1 && $3) {
	        emit_quad("=", $3, NULL, $1);
	    }
	}
	| declarator
	;

storage_class_specifier
	: TOK_EXTERN
	| TOK_STATIC
	;

type_specifier
	: TOK_VOID
	| TOK_CHAR
	| TOK_SHORT
	| TOK_INT
	| TOK_FLOAT
	| TOK_BOOL
	| TOK_BOOLEAN
	| TOK_INT8_T
	| TOK_INT16_T
	| TOK_INT32_T
	| TOK_INT64_T
	| TOK_SIGNED
	| TOK_UNSIGNED
    | struct_specifier
    ;

struct_specifier
	: TOK_STRUCT TOK_IDENTIFIER TOK_BEGIN struct_declaration_list TOK_END
	| TOK_STRUCT TOK_IDENTIFIER
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list TOK_SEMICOLON
	| specifier_qualifier_list struct_declarator_list TOK_SEMICOLON
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list TOK_COMMA struct_declarator
	;

struct_declarator
	: TOK_COLON constant_expression
	| declarator TOK_COLON constant_expression
	| declarator
	;


declarator
	: pointer direct_declarator { $$ = $2; }
	| direct_declarator         { $$ = $1; }
	;

direct_declarator
	: TOK_IDENTIFIER                                                    { $$ = $1; }
	| TOK_LPAREN declarator TOK_RPAREN                                  { $$ = $2; }
	| direct_declarator TOK_LBRACKET TOK_RBRACKET                       { $$ = $1; }
	| direct_declarator TOK_LBRACKET assignment_expression TOK_RBRACKET { $$ = $1; }
	| direct_declarator TOK_LPAREN parameter_type_list TOK_RPAREN       { $$ = $1; }
	| direct_declarator TOK_LPAREN TOK_RPAREN                           { $$ = $1; }
	| direct_declarator TOK_LPAREN identifier_list TOK_RPAREN          { $$ = $1; }
	;

pointer
	: TOK_STAR pointer {pointer_decls++;}
	| TOK_STAR {pointer_decls++;}
	;



parameter_type_list
	: parameter_list
	;

parameter_list
	: parameter_declaration
	| parameter_list TOK_COMMA parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: TOK_IDENTIFIER
	| identifier_list TOK_COMMA TOK_IDENTIFIER
	;

type_name
	: specifier_qualifier_list abstract_declarator
	| specifier_qualifier_list
	;

abstract_declarator
	: pointer direct_abstract_declarator
	| pointer
	| direct_abstract_declarator
	;

direct_abstract_declarator
	: TOK_LPAREN abstract_declarator TOK_RPAREN
	| TOK_LBRACKET TOK_RBRACKET
	| TOK_LBRACKET assignment_expression TOK_RBRACKET
	| direct_abstract_declarator TOK_LBRACKET TOK_RBRACKET
	| direct_abstract_declarator TOK_LBRACKET assignment_expression TOK_RBRACKET
	| TOK_LPAREN TOK_RPAREN
	| TOK_LPAREN parameter_type_list TOK_RPAREN
	| direct_abstract_declarator TOK_LPAREN TOK_RPAREN
	| direct_abstract_declarator TOK_LPAREN parameter_type_list TOK_RPAREN
	;

initializer
    : TOK_BEGIN initializer_list TOK_END { $$ = (char *)malloc(20); strcpy($$, "init"); }
    | TOK_BEGIN initializer_list TOK_COMMA TOK_END { $$ = (char *)malloc(20); strcpy($$, "init"); }
    | assignment_expression
    {
        $$ = $1;
    }
    ;

initializer_list
	: designation initializer
	| initializer
	| initializer_list TOK_COMMA designation initializer
	| initializer_list TOK_COMMA initializer
	;

designation
	: designator_list TOK_ASSIGN
	;

designator_list
	: designator
	| designator_list designator
	;

designator
	: TOK_LBRACKET constant_expression TOK_RBRACKET
	| TOK_DOT TOK_IDENTIFIER
	;

statement
    : matched_statement
    | unmatched_statement
    | error TOK_SEMICOLON { yyerrok; }
    ;

compound_statement
	: TOK_BEGIN TOK_END
	| TOK_BEGIN block_item_list TOK_END
    ;

block_item_list
	: block_item
	| block_item_list block_item
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: TOK_SEMICOLON { $$ = NULL; }
	| expression TOK_SEMICOLON { $$ = $1; }
	;


L_mark: /* empty */ { $$ = strdup(new_label()); emit_quad("label", NULL, NULL, $$); } ;
M_mark_stmt: expression_statement { $$ = strdup(new_label()); emit_quad("ifFalse", $1, NULL, $$); } ;
M_mark_expr: expression { $$ = strdup(new_label()); emit_quad("ifFalse", $1, NULL, $$); } ;
if_head: TOK_IF TOK_LPAREN expression TOK_RPAREN { $$ = strdup(new_label()); emit_quad("ifFalse", $3, NULL, $$); } ;
if_else_head: if_head matched_statement TOK_ELSE { $$ = strdup(new_label()); emit_quad("goto", NULL, NULL, $$); emit_quad("label", NULL, NULL, $1); } ;

M_quad_count: /* empty */ { $$ = get_quad_count(); } ;

matched_statement
	: compound_statement
    | expression_statement
    | iteration_statement
    | jump_statement
	| TOK_IDENTIFIER TOK_COLON matched_statement
	| TOK_CASE constant_expression TOK_COLON matched_statement { codegen_unsupported("case label"); }
	| TOK_DEFAULT TOK_COLON matched_statement { codegen_unsupported("default label"); }
    | TOK_SWITCH TOK_LPAREN expression TOK_RPAREN matched_statement { codegen_unsupported("switch statement"); }
	| if_else_head matched_statement { emit_quad("label", NULL, NULL, $1); ladder_len++; if(ladder_len>=max){max=ladder_len;} ladder_len--; }
    ;

unmatched_statement
	: TOK_IDENTIFIER TOK_COLON unmatched_statement
	| TOK_CASE constant_expression TOK_COLON unmatched_statement { codegen_unsupported("case label"); }
	| TOK_DEFAULT TOK_COLON unmatched_statement { codegen_unsupported("default label"); }
    | unmatched_iteration_statement
	| if_head statement { emit_quad("label", NULL, NULL, $1); ifs_wo_else++; }
	| if_else_head unmatched_statement { emit_quad("label", NULL, NULL, $1); ladder_len++; if(ladder_len>=max){max=ladder_len;} ladder_len--; }
    ;

iteration_statement
	: TOK_WHILE L_mark TOK_LPAREN M_mark_expr TOK_RPAREN matched_statement { emit_quad("goto", NULL, NULL, $2); emit_quad("label", NULL, NULL, $4); }
	| TOK_REPEAT L_mark matched_statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON { emit_quad("ifFalse", $6, NULL, $2); }
        | TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt TOK_RPAREN matched_statement { emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
        | TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt M_quad_count expression M_quad_count TOK_RPAREN matched_statement { ir_defer_update($6, $8, get_quad_count()); emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
        | TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt TOK_RPAREN matched_statement { emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
        | TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt M_quad_count expression M_quad_count TOK_RPAREN matched_statement { ir_defer_update($6, $8, get_quad_count()); emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
    ;

unmatched_iteration_statement
        : TOK_WHILE L_mark TOK_LPAREN M_mark_expr TOK_RPAREN unmatched_statement { emit_quad("goto", NULL, NULL, $2); emit_quad("label", NULL, NULL, $4); }
        | TOK_REPEAT L_mark unmatched_statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON { emit_quad("ifFalse", $6, NULL, $2); }
        | TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt TOK_RPAREN unmatched_statement { emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
        | TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt M_quad_count expression M_quad_count TOK_RPAREN unmatched_statement { ir_defer_update($6, $8, get_quad_count()); emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
        | TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt TOK_RPAREN unmatched_statement { emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
        | TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt M_quad_count expression M_quad_count TOK_RPAREN unmatched_statement { ir_defer_update($6, $8, get_quad_count()); emit_quad("goto", NULL, NULL, $4); emit_quad("label", NULL, NULL, $5); }
    ;

jump_statement
	: TOK_CONTINUE TOK_SEMICOLON { codegen_unsupported("continue statement"); }
	| TOK_BREAK TOK_SEMICOLON { codegen_unsupported("break statement"); }
    | TOK_RETURN TOK_SEMICOLON { emit_quad("return", NULL, NULL, NULL); }
    | TOK_RETURN expression TOK_SEMICOLON { emit_quad("return", $2, NULL, NULL); }
    ;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition {func_definitions++;}
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

%%
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern int fileno(FILE *stream);

static void codegen_unsupported(const char *construct)
{
	fprintf(stdout,
			"[IR ERROR] Unsupported construct during code generation: %s at line %d, col %d near '%s'\n",
			construct ? construct : "unknown",
			token_start_line,
			token_start_col,
			(yytext && yytext[0] != '\0') ? yytext : "end of input");
	fflush(stdout);
	exit(1);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  SECTION 1 – Human-friendly token name translation
 * ═══════════════════════════════════════════════════════════════════════════
 *
 *  Bison's %define parse.error detailed inserts raw token names such as
 *  "TOK_SEMICOLON" into the error string.  The table below maps every
 *  internal name to its surface form so the programmer sees readable output.
 *
 *  humanise() rewrites the raw Bison message in-place (inside a static
 *  buffer) and returns a pointer to that buffer.  It is called once in
 *  yyerror before any printf.
 * ═══════════════════════════════════════════════════════════════════════════ */

static const struct { const char *internal; const char *human; }
token_names[] = {
    /* punctuation */
    { "TOK_SEMICOLON",  "';'"       },
    { "TOK_LPAREN",     "'('"       },
    { "TOK_RPAREN",     "')'"       },
    { "TOK_LBRACKET",   "'['"       },
    { "TOK_RBRACKET",   "']'"       },
    { "TOK_COMMA",      "','"       },
    { "TOK_COLON",      "':'"       },
    { "TOK_DOT",        "'.'"       },
    /* keywords */
    { "TOK_BEGIN",      "'begin'"   },
    { "TOK_END",        "'end'"     },
    { "TOK_IF",         "'if'"      },
    { "TOK_ELSE",       "'else'"    },
    { "TOK_FOR",        "'for'"     },
    { "TOK_WHILE",      "'while'"   },
    { "TOK_REPEAT",     "'repeat'"  },
    { "TOK_UNTIL",      "'until'"   },
    { "TOK_SWITCH",     "'switch'"  },
    { "TOK_CASE",       "'case'"    },
    { "TOK_DEFAULT",    "'default'" },
    { "TOK_BREAK",      "'break'"   },
    { "TOK_CONTINUE",   "'continue'"},
    { "TOK_RETURN",     "'return'"  },
    { "TOK_SIZEOF",     "'sizeof'"  },
    { "TOK_TRUE",       "'true'"    },
    { "TOK_FALSE",      "'false'"   },
    /* type keywords */
    { "TOK_INT",        "'int'"     },
    { "TOK_SHORT",      "'short'"   },
    { "TOK_FLOAT",      "'float'"   },
    { "TOK_CHAR",       "'char'"    },
    { "TOK_VOID",       "'void'"    },
    { "TOK_BOOL",       "'bool'"    },
    { "TOK_BOOLEAN",    "'boolean'" },
    { "TOK_STRUCT",     "'struct'"  },
    { "TOK_SIGNED",     "'signed'"  },
    { "TOK_UNSIGNED",   "'unsigned'"},
    { "TOK_EXTERN",     "'extern'"  },
    { "TOK_STATIC",     "'static'"  },
    { "TOK_INT8_T",     "'int8_t'"  },
    { "TOK_INT16_T",    "'int16_t'" },
    { "TOK_INT32_T",    "'int32_t'" },
    { "TOK_INT64_T",    "'int64_t'" },
    /* operators */
    { "TOK_ASSIGN",     "'='"       },
    { "TOK_EQ",         "'=='"      },
    { "TOK_NE",         "'!='"      },
    { "TOK_LT",         "'<'"       },
    { "TOK_LE",         "'<='"      },
    { "TOK_GT",         "'>'"       },
    { "TOK_GE",         "'>='"      },
    { "TOK_SPACESHIP",  "' <=>'"    },
    { "TOK_PLUS",       "'+'"       },
    { "TOK_MINUS",      "'-'"       },
    { "TOK_MULT",       "'*'"       },
    { "TOK_DIV",        "'/'"       },
    { "TOK_MOD",        "'%'"       },
    { "TOK_AND",        "'&&'"      },
    { "TOK_OR",         "'||'"      },
    { "TOK_NOT",        "'!'"       },
    { "TOK_AMP",        "'&'"       },
    { "TOK_BITOR",      "'|'"       },
    { "TOK_XOR",        "'^'"       },
    { "TOK_BITNOT",     "'~'"       },
    { "TOK_LSHIFT",     "'<<'"      },
    { "TOK_RSHIFT",     "'>>'"      },
    { "TOK_INC",        "'++'"      },
    { "TOK_DEC",        "'--'"      },
    { "TOK_PLUSEQ",     "'+='"      },
    { "TOK_MINUSEQ",    "'-='"      },
    { "TOK_MULTEQ",     "'*='"      },
    { "TOK_DIVEQ",      "'/='"      },
    { "TOK_MODEQ",      "'%='"      },
    { "TOK_ARROW",      "'->'"      },
    { "TOK_STAR",       "'*'"       },
    /* literals / identifier */
    { "TOK_IDENTIFIER", "identifier"  },
    { "TOK_INTEGER",    "integer literal" },
    { "TOK_FLOAT_LIT",  "float literal"   },
    { "TOK_CHAR_LIT",   "character literal"},
    { "TOK_STRING_LIT", "string literal"  },
    { NULL, NULL }
};

/*
 * Replace every occurrence of `needle` in `buf` (of total capacity `cap`)
 * with `replacement`.  Works in-place using memmove.
 */
static void str_replace_all(char *buf, size_t cap,
                            const char *needle,
                            const char *replacement)
{
    size_t nlen = strlen(needle);
    size_t rlen = strlen(replacement);
    char  *pos  = buf;

    while ((pos = strstr(pos, needle)) != NULL)
    {
        size_t tail = strlen(pos + nlen) + 1; /* +1 for '\0' */
        size_t used = (size_t)(pos - buf);

        /* make sure we won't overflow the buffer */
        if (used + rlen + tail > cap)
            break;

        memmove(pos + rlen, pos + nlen, tail);
        memcpy(pos, replacement, rlen);
        pos += rlen;
    }
}

/*
 * humanise() – translate all TOK_* names in raw_msg and return a pointer
 * to a static buffer containing the rewritten string.
 */
static char *humanise(const char *raw_msg)
{
    static char buf[4096];
    strncpy(buf, raw_msg, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    for (int i = 0; token_names[i].internal != NULL; i++)
        str_replace_all(buf, sizeof(buf),
                        token_names[i].internal,
                        token_names[i].human);
    return buf;
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  SECTION 2 – Contextual hint engine
 * ═══════════════════════════════════════════════════════════════════════════
 *
 *  emit_hint() receives the *humanised* error message together with the
 *  raw yytext and the error location.  It pattern-matches common mistake
 *  signatures and prints a one-line targeted suggestion.
 *
 *  Patterns are checked in priority order; only the first matching hint
 *  is printed.
 * ═══════════════════════════════════════════════════════════════════════════ */

static void emit_hint(const char *msg, const char *tok,
                      int line, int col)
{
    (void)line; (void)col;   /* not used for matching, available if needed */

    /* ── 1. Missing semicolon ──────────────────────────────────────────── */
	if (strstr(msg, "';'") &&
		strstr(msg, "expecting") &&
		strstr(msg, "expression") == NULL &&
		strstr(msg, "')'") == NULL &&
		strstr(msg, "','") == NULL)
    {
        printf("  hint: Did you forget a ';'");
        if (tok && tok[0] != '\0')
            printf(" before '%s'", tok);
        printf("?\n");
        return;
    }

    /* ── 2. Unclosed begin block ───────────────────────────────────────── */
    if (strstr(msg, "'end'") && strstr(msg, "expecting"))
    {
        printf("  hint: A 'begin' block is not closed. "
               "Did you forget 'end'?\n");
        return;
    }

    /* ── 3. Missing closing parenthesis ───────────────────────────────── */
    if (strstr(msg, "')'") && strstr(msg, "expecting"))
    {
        printf("  hint: Did you forget a closing ')'?\n");
        return;
    }

    /* ── 4. Missing 'until' in repeat loop ────────────────────────────── */
    if (strstr(msg, "'until'") && strstr(msg, "expecting"))
    {
        printf("  hint: 'repeat' loop requires 'until (condition);'\n");
        return;
    }

    /* ── 5. Missing closing bracket ───────────────────────────────────── */
    if (strstr(msg, "']'") && strstr(msg, "expecting"))
    {
        printf("  hint: Did you forget a closing ']'?\n");
        return;
    }

    /* ── 6. Reserved keyword used as identifier ────────────────────────── */
    /*
     *  This fires when the parser expected an identifier but got a keyword.
     *  We check yytext against every keyword internal name.
     */
    if (tok && tok[0] != '\0' && strstr(msg, "identifier"))
    {
        /* list of keyword surface forms to check against yytext */
        static const char *keywords[] = {
            "int","short","float","char","void","bool","boolean",
            "struct","signed","unsigned","extern","static",
            "if","else","for","while","repeat","until","switch",
            "case","default","break","continue","return","sizeof",
            "begin","end","true","false",
            "int8_t","int16_t","int32_t","int64_t",
            NULL
        };
        for (int k = 0; keywords[k] != NULL; k++)
        {
            if (strcmp(tok, keywords[k]) == 0)
            {
                printf("  hint: '%s' is a reserved keyword and cannot "
                       "be used as an identifier.\n", tok);
                return;
            }
        }
    }

    /* ── 7. Missing expression (e.g. after '=' or inside condition) ────── */
    if (strstr(msg, "expecting") &&
        tok != NULL &&
        (tok[0] == ';' || tok[0] == ')' || tok[0] == ']'))
    {
        printf("  hint: An expression is expected here.\n");
        return;
    }

    /* ── 8. Unexpected end of file ─────────────────────────────────────── */
    if (strstr(msg, "end of file") || strstr(msg, "$end") ||
        (tok != NULL && tok[0] == '\0'))
    {
        printf("  hint: Input ended unexpectedly. "
               "Check for unclosed 'begin'...'end' blocks.\n");
        return;
    }

    /* ── 9. Missing '=' in initialiser ────────────────────────────────── */
    if (strstr(msg, "'='") && strstr(msg, "expecting"))
    {
        printf("  hint: Did you forget '=' in the initializer?\n");
        return;
    }

    /* ── 10. General fallback ─────────────────────────────────────────── */
    /* No specific pattern matched – print a generic nudge so the hint
       line is never absent when a syntax error occurs.                   */
    if (tok && tok[0] != '\0')
        printf("  hint: Check the syntax around '%s'.\n", tok);
    else
        printf("  hint: Check the syntax near this location.\n");
}

/* Capture input file lines so yyerror can print source + caret diagnostics. */
static void load_source_lines(FILE *fp)
{
	current_line_count = 0;
	if (!fp) return;

	while (current_line_count < MAX_LINES &&
		   fgets(source_lines[current_line_count], MAX_LINE_LEN, fp) != NULL)
	{
		current_line_count++;
	}

	rewind(fp);
}

/* Declaration starters used to infer a likely missing semicolon before a new declaration. */
static int is_decl_starter(const char *tok)
{
	if (!tok || tok[0] == '\0') return 0;

	static const char *decl_kw[] = {
		"int", "short", "float", "char", "void", "bool", "boolean",
		"struct", "signed", "unsigned", "extern", "static",
		"int8_t", "int16_t", "int32_t", "int64_t", NULL
	};

	for (int i = 0; decl_kw[i] != NULL; i++)
		if (strcmp(tok, decl_kw[i]) == 0)
			return 1;

	return 0;
}

/*
 * Returns the 1-based column immediately after the last unmatched '(' before
 * before_col, or 0 if none is found. Used to place caret for missing ')' in
 * function-call argument lists.
 */
static int find_call_arg_start_col(const char *line, int before_col)
{
	if (!line || before_col <= 1) return 0;

	int stack[256];
	int top = -1;
	int max = before_col - 1;
	int len = (int)strlen(line);
	if (max > len) max = len;

	for (int i = 0; i < max; i++)
	{
		if (line[i] == '(')
		{
			if (top < 255) stack[++top] = i + 1; /* store 1-based column */
		}
		else if (line[i] == ')')
		{
			if (top >= 0) top--;
		}
	}

	if (top >= 0)
		return stack[top] + 1; /* first argument column */

	return 0;
}

/*
 * Returns 1 if the '(' at paren_col is part of control-flow syntax like
 * if(...), while(...), for(...), switch(...), repeat/until contexts.
 */
static int is_control_paren_context(const char *line, int paren_col)
{
	if (!line || paren_col <= 1) return 0;

	int i = paren_col - 2; /* index before '(' */
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) i--;
	if (i < 0) return 0;

	int end = i;
	while (i >= 0 && ((line[i] >= 'a' && line[i] <= 'z') ||
					  (line[i] >= 'A' && line[i] <= 'Z') ||
					  line[i] == '_'))
	{
		i--;
	}
	int start = i + 1;
	if (start > end) return 0;

	char word[32];
	int wlen = end - start + 1;
	if (wlen <= 0 || wlen >= (int)sizeof(word)) return 0;
	memcpy(word, &line[start], (size_t)wlen);
	word[wlen] = '\0';

	return (strcmp(word, "if") == 0 ||
			strcmp(word, "while") == 0 ||
			strcmp(word, "for") == 0 ||
			strcmp(word, "switch") == 0 ||
			strcmp(word, "until") == 0);
}

/*
 * Extract the previous identifier-like word before before_col (1-based).
 * Returns 1 when found and fills out/start_col/word_len; otherwise 0.
 */
static int find_prev_word_before_col(const char *line, int before_col,
                                     char *out, size_t out_sz,
                                     int *start_col, int *word_len)
{
	if (!line || !out || out_sz == 0 || before_col <= 1) return 0;

	int i = before_col - 2; /* index before target column */
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) i--;
	if (i < 0) return 0;

	if (!((line[i] >= 'a' && line[i] <= 'z') ||
	      (line[i] >= 'A' && line[i] <= 'Z') ||
	      line[i] == '_'))
	{
		return 0;
	}

	int end = i;
	while (i >= 0 && ((line[i] >= 'a' && line[i] <= 'z') ||
	                 (line[i] >= 'A' && line[i] <= 'Z') ||
	                 (line[i] >= '0' && line[i] <= '9') ||
	                 line[i] == '_'))
	{
		i--;
	}
	int start = i + 1;
	int len = end - start + 1;
	if (len <= 0 || (size_t)len >= out_sz) return 0;

	memcpy(out, &line[start], (size_t)len);
	out[len] = '\0';

	if (start_col) *start_col = start + 1; /* 1-based */
	if (word_len) *word_len = len;
	return 1;
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  SECTION 3 – yyerror  (the main diagnostic function)
 * ═══════════════════════════════════════════════════════════════════════════
 *
 *  Upgraded from the original to add:
 *    (a) humanised token names in the error message
 *    (b) caret-style source-line echo  (GCC/Clang convention)
 *    (c) contextual hint
 * ═══════════════════════════════════════════════════════════════════════════ */

int yylex(void);
int mode = -1;

void yyerror(const char *s)
{
    fflush(stdout);

    if (mode == -1)   /* normal parse: full diagnostic */
    {
        /* ── (a) Translate token names to human-readable forms ────────── */
		const char *msg = humanise(s);
		char enriched_msg[4096];
		int line_for_print = token_start_line;
		int col_for_print  = token_start_col;
		int caret_len_override = 0;
		const char *tok_for_print = yytext;
		int eof_error = ((yytext == NULL || yytext[0] == '\0') &&
		                 (strstr(msg, "end of file") != NULL || strstr(msg, "$end") != NULL));

		/*
		 * Some Bison builds may report only "unexpected X" without "expecting ...".
		 * For the common missing-semicolon pattern before a declaration starter,
		 * enrich the message so diagnostics remain actionable.
		 */
		if (eof_error)
		{
			/* Normalize EOF diagnostics to a clearer, expected-token form. */
			snprintf(enriched_msg, sizeof(enriched_msg),
			         "syntax error, unexpected end of input, expecting 'end'");
			msg = enriched_msg;
			col_for_print = 1;
		}
		else if (strstr(msg, "expecting") == NULL &&
		         yytext != NULL && strcmp(yytext, ";") == 0 &&
		         line_for_print > 0 && line_for_print <= current_line_count)
		{
			const char *line_src = source_lines[line_for_print - 1];
			int arg_col = find_call_arg_start_col(line_src, col_for_print);
			if (arg_col > 0)
			{
				int paren_col = arg_col - 1;
				if (!is_control_paren_context(line_src, paren_col))
				{
					snprintf(enriched_msg, sizeof(enriched_msg),
					         "syntax error, unexpected ';', expecting ')' or ','");
					msg = enriched_msg;
					col_for_print = arg_col;
					caret_len_override = 4;
				}
			}
		}
		else if (strstr(msg, "expecting") == NULL && is_decl_starter(yytext))
		{
			snprintf(enriched_msg, sizeof(enriched_msg), "%s, expecting ';'", msg);
			msg = enriched_msg;
		}
		else if (strstr(msg, "expecting") == NULL &&
		         yytext != NULL && strcmp(yytext, "=") == 0 &&
		         line_for_print > 0 && line_for_print <= current_line_count)
		{
			const char *line_src = source_lines[line_for_print - 1];
			char prev[64], prev2[64];
			int prev_col = 0, prev_len = 0;
			int prev2_col = 0, prev2_len = 0;

			if (find_prev_word_before_col(line_src, col_for_print, prev, sizeof(prev),
			                              &prev_col, &prev_len) &&
			    find_prev_word_before_col(line_src, prev_col, prev2, sizeof(prev2),
			                              &prev2_col, &prev2_len) &&
			    is_decl_starter(prev) && is_decl_starter(prev2))
			{
				snprintf(enriched_msg, sizeof(enriched_msg),
				         "syntax error, unexpected '%s', expecting identifier", prev);
				msg = enriched_msg;
				col_for_print = prev_col;
				caret_len_override = prev_len;
				tok_for_print = prev;
			}
		}
		else if (strstr(msg, "expecting") == NULL &&
		         yytext != NULL &&
		         (strcmp(yytext, ";") == 0 || strcmp(yytext, ")") == 0 || strcmp(yytext, "]") == 0))
		{
			snprintf(enriched_msg, sizeof(enriched_msg), "%s, expecting expression", msg);
			msg = enriched_msg;
		}

        /* ── (b) Location header + offending token ────────────────────── */
		if (!eof_error && tok_for_print != NULL && tok_for_print[0] != '\0')
        {
            printf("[SYNTAX ERROR] Line %d, Col %d: %s near '%s'\n",
			       line_for_print, col_for_print, msg, tok_for_print);
        }
        else
        {
            printf("[SYNTAX ERROR] Line %d, Col %d: %s near ''\n",
                   line_for_print, col_for_print, msg);
        }

        /* ── (c) Caret-style source-line echo ─────────────────────────── *
         *
         *  Format (mirrors GCC output):
         *
         *    <line_no> | <source text>
         *              | ^^^^
         *
         *  We print the line stored in source_lines[] that the lexer
         *  populated.  The caret(s) span exactly strlen(yytext) columns,
         *  starting at token_start_col.
         * ───────────────────────────────────────────────────────────────── */
		if (eof_error)
		{
			/* EOF diagnostics are clearer with an empty source line + caret at col 1. */
			printf("  %5d | \n", line_for_print);
			printf("        | ^\n");
		}
		else if (line_for_print > 0 &&
				 line_for_print <= current_line_count &&
				 source_lines[line_for_print - 1][0] != '\0')
        {
            /* strip trailing newline from the stored source line */
            char line_buf[MAX_LINE_LEN];
            strncpy(line_buf,
					source_lines[line_for_print - 1],
                    MAX_LINE_LEN - 1);
            line_buf[MAX_LINE_LEN - 1] = '\0';
            size_t llen = strlen(line_buf);
            while (llen > 0 &&
                   (line_buf[llen-1] == '\n' || line_buf[llen-1] == '\r'))
            {
                line_buf[--llen] = '\0';
            }

            /* line number gutter: fixed 5-char wide field */
			printf("  %5d | %s\n", line_for_print, line_buf);

            /* caret line */
            printf("        | ");

            /* spaces up to the token's start column (1-based) */
			int col = (col_for_print > 0) ? col_for_print : 1;
            for (int c = 1; c < col; c++)
                putchar(' ');

            /* carets – one per character of the offending token */
			int tlen = (tok_for_print != NULL && tok_for_print[0] != '\0')
			           ? (int)strlen(tok_for_print) : 1;
			if (caret_len_override > 0)
				tlen = caret_len_override;
            for (int c = 0; c < tlen; c++)
                putchar('^');
            putchar('\n');
        }

        /* ── (d) Contextual hint ─────────────────────────────────────── */
		emit_hint(msg, tok_for_print, line_for_print, col_for_print);
    }
    else if (mode == 0 || mode == 1)
    {
        printf("%s\n", s);
    }

    exit(1);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  Derivation-tree infrastructure  (unchanged from original)
 * ═══════════════════════════════════════════════════════════════════════════ */

typedef struct DerivationNode
{
	char *label;
	struct DerivationNode **children;
	size_t child_count;
} DerivationNode;

typedef struct NodeStack
{
	DerivationNode **items;
	size_t count;
	size_t capacity;
} NodeStack;

static char *copy_string(const char *text)
{
	size_t length = strlen(text);
	char *copy = malloc(length + 1);
	if(copy == NULL) return NULL;
	memcpy(copy, text, length + 1);
	return copy;
}

static DerivationNode *create_node(const char *label,
                                   DerivationNode **children,
                                   size_t child_count)
{
	DerivationNode *node = malloc(sizeof(*node));
	if(node == NULL) return NULL;

	node->label = copy_string(label);
	if(node->label == NULL) { free(node); return NULL; }

	node->child_count = child_count;
	node->children = NULL;
	if(child_count > 0)
	{
		node->children = malloc(child_count * sizeof(*node->children));
		if(node->children == NULL)
		{
			free(node->label);
			free(node);
			return NULL;
		}
		for(size_t i = 0; i < child_count; i++)
			node->children[i] = children[i];
	}
	return node;
}

static void free_tree(DerivationNode *node)
{
	if(node == NULL) return;
	for(size_t i = 0; i < node->child_count; i++)
		free_tree(node->children[i]);
	free(node->children);
	free(node->label);
	free(node);
}

static void stack_init(NodeStack *stack)
{
	stack->items = NULL;
	stack->count = 0;
	stack->capacity = 0;
}

static int stack_push(NodeStack *stack, DerivationNode *node)
{
	if(stack->count == stack->capacity)
	{
		size_t next = (stack->capacity == 0) ? 64 : stack->capacity * 2;
		DerivationNode **ni = realloc(stack->items, next * sizeof(*ni));
		if(ni == NULL) return 0;
		stack->items    = ni;
		stack->capacity = next;
	}
	stack->items[stack->count++] = node;
	return 1;
}

static DerivationNode *stack_pop(NodeStack *stack)
{
	if(stack->count == 0) return NULL;
	return stack->items[--stack->count];
}

static void stack_free(NodeStack *stack)
{
	free(stack->items);
	stack->items    = NULL;
	stack->count    = 0;
	stack->capacity = 0;
}

static void print_tree(const DerivationNode *node, size_t depth)
{
	if(node == NULL) return;
	for(size_t i = 0; i < depth; i++) printf("  ");
	printf("%s\n", node->label);
	for(size_t i = 0; i < node->child_count; i++)
		print_tree(node->children[i], depth + 1);
}

static void extract_symbol_name(const char *line, char *buffer,
                                size_t buffer_size)
{
	const char *start = strstr(line, "nterm ");
	if(start) { start += 6; }
	else
	{
		start = strstr(line, "token ");
		if(start) start += 6;
		else { buffer[0] = '\0'; return; }
	}
	const char *end = strstr(start, " (");
	if(!end) end = start + strlen(start);
	size_t len = (size_t)(end - start);
	if(len >= buffer_size) len = buffer_size - 1;
	memcpy(buffer, start, len);
	buffer[len] = '\0';
}

static DerivationNode *build_tree_from_trace(FILE *trace)
{
	NodeStack stack;
	stack_init(&stack);

	char   line[4096];
	int    in_reduction = 0;
	size_t rhs_count    = 0;

	rewind(trace);
	while(fgets(line, sizeof(line), trace))
	{
		if(strncmp(line, "Shifting token ", 15) == 0)
		{
			char name[256];
			extract_symbol_name(line, name, sizeof(name));
			if(name[0] && !strstr(name,"end of file") && strcmp(name,"$end"))
			{
				DerivationNode *leaf = create_node(name, NULL, 0);
				if(leaf) stack_push(&stack, leaf);
			}
			continue;
		}
		if(strncmp(line, "Reducing stack by rule", 22) == 0)
		{
			in_reduction = 1;
			rhs_count    = 0;
			continue;
		}
		if(in_reduction && strncmp(line, "   $", 4) == 0)
		{
			rhs_count++;
			continue;
		}
		if(in_reduction && strncmp(line, "-> $$ =", 7) == 0)
		{
			char lhs[256];
			extract_symbol_name(line, lhs, sizeof(lhs));

			DerivationNode **ch = NULL;
			if(rhs_count > 0)
			{
				ch = malloc(rhs_count * sizeof(*ch));
				if(ch)
					for(size_t i = 0; i < rhs_count; i++)
						ch[rhs_count-1-i] = stack_pop(&stack);
			}
			if(lhs[0])
			{
				DerivationNode *parent = create_node(lhs, ch, rhs_count);
				if(parent) stack_push(&stack, parent);
			}
			free(ch);
			in_reduction = 0;
			rhs_count    = 0;
		}
	}

	DerivationNode *root = NULL;
	if(stack.count > 0) root = stack.items[stack.count-1];
	stack_free(&stack);
	return root;
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  main()  (unchanged logic; trace capture kept as in original)
 * ═══════════════════════════════════════════════════════════════════════════ */

int main(int argc, char **argv)
{
	extern FILE *yyin;
	FILE *trace_capture = NULL;
	int   stderr_copy   = -1;

#if YYDEBUG
	yydebug = 1;
#endif

	trace_capture = tmpfile();
	if(trace_capture)
	{
		stderr_copy = dup(fileno(stderr));
		if(stderr_copy != -1)
		{
			fflush(stderr);
			dup2(fileno(trace_capture), fileno(stderr));
		}
	}

	if(argc < 2)
	{
		char buff[2048];
		sprintf(buff,
				"***process terminated*** [input error]: "
				"invalid number of command-line arguments");
		mode = 1;
		yyerror(buff);
		exit(1);
	}

	yyin = fopen(argv[1], "r");
	if(!yyin)
	{
		char buff[2048];
                sprintf(buff,
                        "***process terminated*** [input error]: "
                        "no such file \"%s\" exists", argv[1]);
                mode = 1;
                yyerror(buff);
                exit(1);
	}

	load_source_lines(yyin);
	ir_init();

	yyparse();

	if(trace_capture && stderr_copy != -1)
	{
		fflush(stderr);
		dup2(stderr_copy, fileno(stderr));
		close(stderr_copy);

		DerivationNode *root = build_tree_from_trace(trace_capture);
		if(root)
		{
			printf("=== reverse derivation tree ===\n");
			print_tree(root, 0);
			free_tree(root);
		}
		fclose(trace_capture);
	}

	printf("***parsing successful***\n");
    printf("#global_declarations = %d\n",  global_declarations);
    printf("#function_definitions = %d\n", func_definitions);
    printf("#integer_constants = %d\n",    int_consts);
    printf("#pointers_declarations = %d\n",pointer_decls);
    printf("#ifs_without_else = %d\n",     ifs_wo_else);
    printf("if-else max-depth = %d\n",     (max < 0) ? 0 : max);

    /* ── (a) Explicitly show: Input Source Program ─────────────────────── */
    printf("\n=== Input Source Program ===\n\n");
    rewind(yyin);
    {
        char src_line[MAX_LINE_LEN];
        int  lineno = 1;
        while (fgets(src_line, sizeof(src_line), yyin)) {
            /* strip trailing newline for clean display */
            size_t slen = strlen(src_line);
            while (slen > 0 && (src_line[slen-1] == '\n' || src_line[slen-1] == '\r'))
                src_line[--slen] = '\0';
            printf("  %4d | %s\n", lineno++, src_line);
        }
    }
    printf("\n");

    /* ── (b) Explicitly show: Generated Intermediate Code ──────────────── */
    if (get_quad_count() > 0) {
        print_quads_tabular(stdout);
    } else {
        printf("\n(no intermediate code generated)\n\n");
    }

    ir_cleanup();

    return 0;
}
