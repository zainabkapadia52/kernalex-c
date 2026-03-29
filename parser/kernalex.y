%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

void yyerror(const char *s);

int syntax_error_count = 0;
%}

/* Token declarations - matching tokens.h */
%token TOK_INT8 TOK_INT16 TOK_INT32 TOK_INT64
%token TOK_INT TOK_SHORT TOK_FLOAT TOK_CHAR TOK_VOID
%token TOK_BOOL TOK_BOOLEAN TOK_STRUCT
%token TOK_SIGNED TOK_UNSIGNED TOK_EXTERN TOK_STATIC
%token TOK_IF TOK_ELSE TOK_FOR TOK_WHILE TOK_REPEAT TOK_UNTIL
%token TOK_SWITCH TOK_CASE TOK_DEFAULT
%token TOK_BREAK TOK_CONTINUE TOK_RETURN
%token TOK_SIZEOF TOK_TRUE TOK_FALSE
%token TOK_BEGIN TOK_END

%token TOK_IDENTIFIER TOK_INTEGER TOK_FLOAT_LIT TOK_CHAR_LIT TOK_STRING_LIT

/* Operators */
%token TOK_PLUS TOK_MINUS TOK_MULT TOK_DIV TOK_MOD
%token TOK_ASSIGN TOK_EQ TOK_NE TOK_LT TOK_LE TOK_GT TOK_GE
%token TOK_SPACESHIP
%token TOK_AND TOK_OR TOK_NOT TOK_BITAND TOK_BITOR TOK_XOR TOK_BITNOT
%token TOK_LSHIFT TOK_RSHIFT
%token TOK_INC TOK_DEC
%token TOK_PLUSEQ TOK_MINUSEQ TOK_MULTEQ TOK_DIVEQ TOK_MODEQ
%token TOK_ARROW TOK_AMP TOK_STAR

/* Punctuation */
%token TOK_LPAREN TOK_RPAREN
%token TOK_LBRACE TOK_RBRACE
%token TOK_LBRACKET TOK_RBRACKET
%token TOK_SEMICOLON TOK_COMMA TOK_DOT TOK_COLON

/* Operator precedence and associativity (lowest to highest) */
%right TOK_ASSIGN TOK_PLUSEQ TOK_MINUSEQ TOK_MULTEQ TOK_DIVEQ TOK_MODEQ
%left TOK_OR
%left TOK_AND
%left TOK_BITOR
%left TOK_XOR
%left TOK_BITAND
%left TOK_EQ TOK_NE
%left TOK_LT TOK_LE TOK_GT TOK_GE TOK_SPACESHIP
%left TOK_LSHIFT TOK_RSHIFT
%left TOK_PLUS TOK_MINUS
%left TOK_MULT TOK_DIV TOK_MOD
%right TOK_NOT TOK_BITNOT UNARY_MINUS ADDR_OF DEREF
%left TOK_INC TOK_DEC TOK_ARROW TOK_DOT TOK_LBRACKET

%%

/* Grammar Rules */

program:
      /* empty */
    | declaration_list
    ;

declaration_list:
      declaration
    | declaration_list declaration
    ;

declaration:
      function_declaration
    | variable_declaration TOK_SEMICOLON
    | struct_declaration TOK_SEMICOLON
    ;

/* Type Specifiers */
type_specifier:
      TOK_INT
    | TOK_INT8
    | TOK_INT16
    | TOK_INT32
    | TOK_INT64
    | TOK_SHORT
    | TOK_FLOAT
    | TOK_CHAR
    | TOK_VOID
    | TOK_BOOL
    | TOK_BOOLEAN
    | TOK_SIGNED type_specifier
    | TOK_UNSIGNED type_specifier
    | TOK_STRUCT TOK_IDENTIFIER
    ;

storage_class:
      TOK_EXTERN
    | TOK_STATIC
    ;

/* Variable Declarations */
variable_declaration:
      type_specifier declarator
    | type_specifier declarator TOK_ASSIGN expression
    | storage_class type_specifier declarator
    | storage_class type_specifier declarator TOK_ASSIGN expression
    ;

declarator:
declarator:
     pointer direct_declarator
   | direct_declarator
;

pointer:
     TOK_STAR
   | TOK_STAR pointer
;

direct_declarator:
     TOK_IDENTIFIER
   | direct_declarator TOK_LBRACKET TOK_RBRACKET
   | direct_declarator TOK_LBRACKET TOK_INTEGER TOK_RBRACKET
;

/* Function Declarations */
function_declaration:
      type_specifier TOK_IDENTIFIER TOK_LPAREN parameter_list TOK_RPAREN compound_statement
    | type_specifier TOK_IDENTIFIER TOK_LPAREN TOK_RPAREN compound_statement
    ;

parameter_list:
      parameter
    | parameter_list TOK_COMMA parameter
    ;

parameter:
      type_specifier declarator
    ;

/* Struct Declarations */
struct_declaration:
      TOK_STRUCT TOK_IDENTIFIER TOK_LBRACE struct_member_list TOK_RBRACE
    ;

struct_member_list:
      struct_member
    | struct_member_list struct_member
    ;

struct_member:
      type_specifier declarator TOK_SEMICOLON
    ;

/* Statements */
statement:
      expression_statement
    | compound_statement
    | selection_statement
    | iteration_statement
    | jump_statement
    | variable_declaration TOK_SEMICOLON
    ;

compound_statement:
      TOK_LBRACE TOK_RBRACE
    | TOK_LBRACE statement_list TOK_RBRACE
    | TOK_BEGIN statement_list TOK_END
    ;

statement_list:
      statement
    | statement_list statement
    ;

expression_statement:
      TOK_SEMICOLON
    | expression TOK_SEMICOLON
    ;

/* Selection Statements (if/else, switch) */
selection_statement:
  TOK_IF TOK_LPAREN expression TOK_RPAREN statement
    | TOK_IF TOK_LPAREN expression TOK_RPAREN statement TOK_ELSE statement
    | TOK_SWITCH TOK_LPAREN expression TOK_RPAREN TOK_LBRACE case_list TOK_RBRACE
    ;

case_list:
      case_item
    | case_list case_item
    ;

case_item:
      TOK_CASE expression TOK_COLON statement_list
    | TOK_DEFAULT TOK_COLON statement_list
    ;

/* Iteration Statements */
iteration_statement:
      TOK_WHILE TOK_LPAREN expression TOK_RPAREN statement
    | TOK_FOR TOK_LPAREN expression_opt TOK_SEMICOLON expression_opt TOK_SEMICOLON expression_opt TOK_RPAREN statement
    | TOK_FOR TOK_LPAREN variable_declaration TOK_SEMICOLON expression_opt TOK_SEMICOLON expression_opt TOK_RPAREN statement
    | TOK_REPEAT statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON
    ;

expression_opt:
      /* empty */
    | expression
    ;

/* Jump Statements */
jump_statement:
      TOK_BREAK TOK_SEMICOLON
    | TOK_CONTINUE TOK_SEMICOLON
    | TOK_RETURN TOK_SEMICOLON
    | TOK_RETURN expression TOK_SEMICOLON
    ;

/* Expressions */
expression:
      assignment_expression
    | expression TOK_COMMA assignment_expression
    ;

assignment_expression:
      logical_or_expression
    | logical_or_expression TOK_ASSIGN assignment_expression
    | logical_or_expression TOK_PLUSEQ assignment_expression
    | logical_or_expression TOK_MINUSEQ assignment_expression
    | logical_or_expression TOK_MULTEQ assignment_expression
    | logical_or_expression TOK_DIVEQ assignment_expression
    | logical_or_expression TOK_MODEQ assignment_expression
    ;

logical_or_expression:
      logical_and_expression
    | logical_or_expression TOK_OR logical_and_expression
    ;

logical_and_expression:
      bitwise_or_expression
    | logical_and_expression TOK_AND bitwise_or_expression
    ;

bitwise_or_expression:
      bitwise_xor_expression
    | bitwise_or_expression TOK_BITOR bitwise_xor_expression
    ;

bitwise_xor_expression:
      bitwise_and_expression
    | bitwise_xor_expression TOK_XOR bitwise_and_expression
    ;

bitwise_and_expression:
      equality_expression
    | bitwise_and_expression TOK_BITAND equality_expression
    ;

equality_expression:
      relational_expression
    | equality_expression TOK_EQ relational_expression
    | equality_expression TOK_NE relational_expression
    ;

relational_expression:
      shift_expression
    | relational_expression TOK_LT shift_expression
    | relational_expression TOK_LE shift_expression
    | relational_expression TOK_GT shift_expression
    | relational_expression TOK_GE shift_expression
    | relational_expression TOK_SPACESHIP shift_expression
    ;

shift_expression:
      additive_expression
    | shift_expression TOK_LSHIFT additive_expression
    | shift_expression TOK_RSHIFT additive_expression
    ;

additive_expression:
      multiplicative_expression
    | additive_expression TOK_PLUS multiplicative_expression
    | additive_expression TOK_MINUS multiplicative_expression
    ;

multiplicative_expression:
      unary_expression
    | multiplicative_expression TOK_MULT unary_expression
    | multiplicative_expression TOK_DIV unary_expression
    | multiplicative_expression TOK_MOD unary_expression
    ;

unary_expression:
      postfix_expression
    | TOK_INC unary_expression
    | TOK_DEC unary_expression
    | TOK_PLUS unary_expression
    | TOK_MINUS unary_expression %prec UNARY_MINUS
    | TOK_NOT unary_expression
    | TOK_BITNOT unary_expression
    | TOK_AMP unary_expression %prec ADDR_OF
    | TOK_STAR unary_expression %prec DEREF
    | TOK_SIZEOF TOK_LPAREN type_specifier TOK_RPAREN
    ;

postfix_expression:
      primary_expression
    | postfix_expression TOK_LBRACKET expression TOK_RBRACKET
    | postfix_expression TOK_LPAREN argument_list TOK_RPAREN
    | postfix_expression TOK_LPAREN TOK_RPAREN
    | postfix_expression TOK_DOT TOK_IDENTIFIER
    | postfix_expression TOK_ARROW TOK_IDENTIFIER
    | postfix_expression TOK_INC
    | postfix_expression TOK_DEC
    ;

primary_expression:
      TOK_IDENTIFIER
    | TOK_INTEGER
    | TOK_FLOAT_LIT
    | TOK_CHAR_LIT
    | TOK_STRING_LIT
    | TOK_TRUE
    | TOK_FALSE
    | TOK_LPAREN expression TOK_RPAREN
    ;

argument_list:
      assignment_expression
    | argument_list TOK_COMMA assignment_expression
    ;

%%

void yyerror(const char *s) {
    syntax_error_count++;
    fprintf(stderr, "[SYNTAX ERROR: Line %d: %s near '%s']\n", yylineno, s, yytext);
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
            return 1;
        }
    }
    
    printf("KernaLex Parser\n");
    if (argc > 1) {
        printf("Input file: %s\n", argv[1]);
    } else {
        printf("Reading from stdin\n");
    }
    printf("\n");
    
    int result = yyparse();
    
    if (argc > 1) {
        fclose(yyin);
    }
    
    printf("\n");
    if (result == 0 && syntax_error_count == 0) {
        printf("Parsing completed successfully\n");
        printf("No syntax errors detected\n");
    } else {
        printf("Parsing failed with %d syntax error(s)\n", syntax_error_count);
    }
    
    return (result == 0 && syntax_error_count == 0) ? 0 : 1;
}

