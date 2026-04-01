
%{
#include<stdio.h>
extern char *yytext;

int yylex(void);
void yyerror(const char *s);

int global_declarations=0;
int func_definitions=0;
int int_consts=0;
int pointer_decls=0;
int ifs_wo_else=0;
int ladder_len=0,hold=0;
int max=-1;
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
%token TOK_IDENTIFIER 34
%token TOK_INTEGER 35
%token TOK_FLOAT_LIT 36
%token TOK_CHAR_LIT 37
%token TOK_STRING_LIT 38
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


%union
{
	int val;
	struct symtab *symp;
}

%%

primary_expression
	: TOK_IDENTIFIER
    | constant
    | string
	| TOK_TRUE
	| TOK_FALSE
	| TOK_LPAREN expression TOK_RPAREN
    ;

constant
	: TOK_INTEGER {int_consts++;}
	| TOK_FLOAT_LIT
	| TOK_CHAR_LIT
	;

string
	: TOK_STRING_LIT
	;


postfix_expression
	: primary_expression
	| postfix_expression TOK_LBRACKET expression TOK_RBRACKET
	| postfix_expression TOK_LPAREN TOK_RPAREN
	| postfix_expression TOK_LPAREN argument_expression_list TOK_RPAREN
	| postfix_expression TOK_DOT TOK_IDENTIFIER
	| postfix_expression TOK_ARROW TOK_IDENTIFIER
	| postfix_expression TOK_INC
	| postfix_expression TOK_DEC
	| TOK_LPAREN type_name TOK_RPAREN TOK_BEGIN initializer_list TOK_END
	| TOK_LPAREN type_name TOK_RPAREN TOK_BEGIN initializer_list TOK_COMMA TOK_END
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list TOK_COMMA assignment_expression
	;

unary_expression
	: postfix_expression
	| TOK_INC unary_expression
	| TOK_DEC unary_expression
	| unary_operator cast_expression
	| TOK_SIZEOF unary_expression
	| TOK_SIZEOF TOK_LPAREN type_name TOK_RPAREN
	;

unary_operator
	: TOK_AMP
	| TOK_STAR
	| TOK_PLUS
	| TOK_MINUS
	| TOK_BITNOT
	| TOK_NOT
	;

cast_expression
	: unary_expression
	| TOK_LPAREN type_name TOK_RPAREN cast_expression
	;

multiplicative_expression
    : cast_expression
	| multiplicative_expression TOK_MULT cast_expression
	| multiplicative_expression TOK_DIV cast_expression
	| multiplicative_expression TOK_MOD cast_expression
    ;

additive_expression
	: multiplicative_expression
	| additive_expression TOK_PLUS multiplicative_expression
	| additive_expression TOK_MINUS multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression TOK_LSHIFT additive_expression
	| shift_expression TOK_RSHIFT additive_expression
	;

relational_expression
    : shift_expression
	| relational_expression TOK_LT shift_expression
	| relational_expression TOK_GT shift_expression
	| relational_expression TOK_LE shift_expression
	| relational_expression TOK_GE shift_expression
	| relational_expression TOK_SPACESHIP shift_expression
    ;

equality_expression
	: relational_expression
	| equality_expression TOK_EQ relational_expression
	| equality_expression TOK_NE relational_expression
	;

and_expression
	: equality_expression
	| and_expression TOK_AMP equality_expression
	;

exclusive_or_expression
    : and_expression
	| exclusive_or_expression TOK_XOR and_expression
    ;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression TOK_BITOR exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression TOK_AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression TOK_OR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: TOK_ASSIGN
	| TOK_MULTEQ
	| TOK_DIVEQ
	| TOK_MODEQ
	| TOK_PLUSEQ
	| TOK_MINUSEQ
	;

expression
	: assignment_expression
	| expression TOK_COMMA assignment_expression
	;

constant_expression
	: conditional_expression	/* with constraints */
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
	: pointer {pointer_decls++;} direct_declarator
	| direct_declarator
	;

direct_declarator
	: TOK_IDENTIFIER
	| TOK_LPAREN declarator TOK_RPAREN
	| direct_declarator TOK_LBRACKET TOK_RBRACKET
	| direct_declarator TOK_LBRACKET assignment_expression TOK_RBRACKET
	| direct_declarator TOK_LPAREN parameter_type_list TOK_RPAREN
	| direct_declarator TOK_LPAREN TOK_RPAREN
	| direct_declarator TOK_LPAREN identifier_list TOK_RPAREN
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
	: TOK_BEGIN initializer_list TOK_END
	| TOK_BEGIN initializer_list TOK_COMMA TOK_END
	| assignment_expression
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
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: TOK_IDENTIFIER TOK_COLON statement
	| TOK_CASE constant_expression TOK_COLON statement
	| TOK_DEFAULT TOK_COLON statement
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
	: TOK_SEMICOLON
	| expression TOK_SEMICOLON
	;

selection_statement
	: TOK_IF TOK_LPAREN expression TOK_RPAREN statement TOK_ELSE {ladder_len++;$6=(ladder_len-1);} statement {if(ladder_len>=max){max=ladder_len;} ladder_len=$6;}
	| TOK_IF TOK_LPAREN expression TOK_RPAREN statement {ifs_wo_else++;}
	| TOK_SWITCH TOK_LPAREN expression TOK_RPAREN statement
	;

iteration_statement
	: TOK_WHILE TOK_LPAREN expression TOK_RPAREN statement
	| TOK_REPEAT statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON
	| TOK_FOR TOK_LPAREN expression_statement expression_statement TOK_RPAREN statement
	| TOK_FOR TOK_LPAREN expression_statement expression_statement expression TOK_RPAREN statement
	| TOK_FOR TOK_LPAREN declaration expression_statement TOK_RPAREN statement
	| TOK_FOR TOK_LPAREN declaration expression_statement expression TOK_RPAREN statement
    ;

jump_statement
	: TOK_CONTINUE TOK_SEMICOLON
	| TOK_BREAK TOK_SEMICOLON
	| TOK_RETURN TOK_SEMICOLON
	| TOK_RETURN expression TOK_SEMICOLON
	;

translation_unit
	: external_declaration {global_declarations++;}
	| translation_unit external_declaration {global_declarations++;}
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

char buff[2048];

int yylex(void);
int mode=-1;

void yyerror(const char *s)
{
	fflush(stdout);
	
	if(mode==-1)
		printf("***parsing terminated*** [syntax error]\n");
	else if(mode==0 || mode==1)
		printf("%s\n",s);
		
	exit(-1);
}

int main(int argc, char **argv)
{
    extern FILE *yyin;

	if(argc<2)
	{
		sprintf(buff,"***process terminated*** [input error]: invalid number of command-line arguments");
		mode=1;
		yyerror(buff);
		exit(1);
	}

	yyin=fopen(argv[1],"r");

	if(yyin==NULL)
	{
		sprintf(buff,"***process terminated*** [input error]: no such file \"%s\" exists",argv[1]);
		mode=1;
		yyerror(buff);
		exit(1);
	}
	else
	{
		do
		{
			yyparse();
		}
		while(!feof(yyin));
	}

	printf("***parsing successful***\n");
	printf("#global_declarations = %d\n",global_declarations);
	printf("#function_definitions = %d\n",func_definitions);
	printf("#integer_constants = %d\n",int_consts);
	printf("#pointers_declarations = %d\n",pointer_decls);
	printf("#ifs_without_else = %d\n",ifs_wo_else);
	printf("if-else max-depth = %d\n",((max<0)?0:max));

	return(0);
}
