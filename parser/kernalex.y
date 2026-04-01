
%{
#include<stdio.h>
extern char *yytext;

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
	: pointer direct_declarator
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
    : matched_statement
    | unmatched_statement
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

matched_statement
	: compound_statement
    | expression_statement
    | iteration_statement
    | jump_statement
	| TOK_IDENTIFIER TOK_COLON matched_statement
	| TOK_CASE constant_expression TOK_COLON matched_statement
	| TOK_DEFAULT TOK_COLON matched_statement
    | TOK_SWITCH TOK_LPAREN expression TOK_RPAREN matched_statement
	| TOK_IF TOK_LPAREN expression TOK_RPAREN matched_statement TOK_ELSE matched_statement {ladder_len++; if(ladder_len>=max){max=ladder_len;} ladder_len--;}
    ;

unmatched_statement
	: TOK_IDENTIFIER TOK_COLON unmatched_statement
	| TOK_CASE constant_expression TOK_COLON unmatched_statement
	| TOK_DEFAULT TOK_COLON unmatched_statement
    | unmatched_iteration_statement
	| TOK_IF TOK_LPAREN expression TOK_RPAREN statement {ifs_wo_else++;}
	| TOK_IF TOK_LPAREN expression TOK_RPAREN matched_statement TOK_ELSE unmatched_statement {ladder_len++; if(ladder_len>=max){max=ladder_len;} ladder_len--;}
    ;

iteration_statement
	: TOK_WHILE TOK_LPAREN expression TOK_RPAREN matched_statement
	| TOK_REPEAT matched_statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON
	| TOK_FOR TOK_LPAREN expression_statement expression_statement TOK_RPAREN matched_statement
	| TOK_FOR TOK_LPAREN expression_statement expression_statement expression TOK_RPAREN matched_statement
	| TOK_FOR TOK_LPAREN declaration expression_statement TOK_RPAREN matched_statement
	| TOK_FOR TOK_LPAREN declaration expression_statement expression TOK_RPAREN matched_statement
    ;

unmatched_iteration_statement
	: TOK_WHILE TOK_LPAREN expression TOK_RPAREN unmatched_statement
	| TOK_REPEAT unmatched_statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON
	| TOK_FOR TOK_LPAREN expression_statement expression_statement TOK_RPAREN unmatched_statement
	| TOK_FOR TOK_LPAREN expression_statement expression_statement expression TOK_RPAREN unmatched_statement
	| TOK_FOR TOK_LPAREN declaration expression_statement TOK_RPAREN unmatched_statement
	| TOK_FOR TOK_LPAREN declaration expression_statement expression TOK_RPAREN unmatched_statement
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
#include <unistd.h>

extern int fileno(FILE *stream);

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
	if(copy == NULL)
	{
		return NULL;
	}
	memcpy(copy, text, length + 1);
	return copy;
}

static DerivationNode *create_node(const char *label, DerivationNode **children, size_t child_count)
{
	DerivationNode *node = malloc(sizeof(*node));
	if(node == NULL)
	{
		return NULL;
	}

	node->label = copy_string(label);
	if(node->label == NULL)
	{
		free(node);
		return NULL;
	}

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
		for(size_t index = 0; index < child_count; index++)
		{
			node->children[index] = children[index];
		}
	}

	return node;
}

static void free_tree(DerivationNode *node)
{
	if(node == NULL)
	{
		return;
	}

	for(size_t index = 0; index < node->child_count; index++)
	{
		free_tree(node->children[index]);
	}

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
		size_t next_capacity = (stack->capacity == 0) ? 64 : stack->capacity * 2;
		DerivationNode **next_items = realloc(stack->items, next_capacity * sizeof(*next_items));
		if(next_items == NULL)
		{
			return 0;
		}
		stack->items = next_items;
		stack->capacity = next_capacity;
	}

	stack->items[stack->count++] = node;
	return 1;
}

static DerivationNode *stack_pop(NodeStack *stack)
{
	if(stack->count == 0)
	{
		return NULL;
	}

	return stack->items[--stack->count];
}

static void stack_free(NodeStack *stack)
{
	free(stack->items);
	stack->items = NULL;
	stack->count = 0;
	stack->capacity = 0;
}

static void print_tree(const DerivationNode *node, size_t depth)
{
	if(node == NULL)
	{
		return;
	}

	for(size_t index = 0; index < depth; index++)
	{
		printf("  ");
	}
	printf("%s\n", node->label);

	for(size_t index = 0; index < node->child_count; index++)
	{
		print_tree(node->children[index], depth + 1);
	}
}

static void extract_symbol_name(const char *line, char *buffer, size_t buffer_size)
{
	const char *start = strstr(line, "nterm ");
	if(start != NULL)
	{
		start += 6;
	}
	else
	{
		start = strstr(line, "token ");
		if(start != NULL)
		{
			start += 6;
		}
		else
		{
			buffer[0] = '\0';
			return;
		}
	}

	const char *end = strstr(start, " (");
	if(end == NULL)
	{
		end = start + strlen(start);
	}

	size_t length = (size_t)(end - start);
	if(length >= buffer_size)
	{
		length = buffer_size - 1;
	}

	memcpy(buffer, start, length);
	buffer[length] = '\0';
}

static DerivationNode *build_tree_from_trace(FILE *trace)
{
	NodeStack stack;
	stack_init(&stack);

	char line[4096];
	int in_reduction = 0;
	size_t rhs_count = 0;

	rewind(trace);
	while(fgets(line, sizeof(line), trace) != NULL)
	{
		if(strncmp(line, "Shifting token ", 15) == 0)
		{
			char token_name[256];
			extract_symbol_name(line, token_name, sizeof(token_name));
			if(token_name[0] != '\0' && strstr(token_name, "end of file") == NULL && strcmp(token_name, "$end") != 0)
			{
				DerivationNode *leaf = create_node(token_name, NULL, 0);
				if(leaf != NULL)
				{
					stack_push(&stack, leaf);
				}
			}
			continue;
		}

		if(strncmp(line, "Reducing stack by rule", 22) == 0)
		{
			in_reduction = 1;
			rhs_count = 0;
			continue;
		}

		if(in_reduction && strncmp(line, "   $", 4) == 0)
		{
			rhs_count++;
			continue;
		}

		if(in_reduction && strncmp(line, "-> $$ =", 7) == 0)
		{
			char lhs_name[256];
			extract_symbol_name(line, lhs_name, sizeof(lhs_name));

			DerivationNode **children = NULL;
			if(rhs_count > 0)
			{
				children = malloc(rhs_count * sizeof(*children));
				if(children != NULL)
				{
					for(size_t index = 0; index < rhs_count; index++)
					{
						children[rhs_count - 1 - index] = stack_pop(&stack);
					}
				}
			}

			if(lhs_name[0] != '\0')
			{
				DerivationNode *parent = create_node(lhs_name, children, rhs_count);
				if(parent != NULL)
				{
					stack_push(&stack, parent);
				}
			}

			free(children);
			in_reduction = 0;
			rhs_count = 0;
		}
	}

	DerivationNode *root = NULL;
	if(stack.count > 0)
	{
		root = stack.items[stack.count - 1];
	}
	stack_free(&stack);
	return root;
}

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
	FILE *trace_capture = NULL;
	int stderr_copy = -1;

#if YYDEBUG
	yydebug = 1;
#endif

	trace_capture = tmpfile();
	if(trace_capture != NULL)
	{
		stderr_copy = dup(fileno(stderr));
		if(stderr_copy != -1)
		{
			fflush(stderr);
			dup2(fileno(trace_capture), fileno(stderr));
		}
	}

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

	if(trace_capture != NULL && stderr_copy != -1)
	{
		fflush(stderr);
		dup2(stderr_copy, fileno(stderr));
		close(stderr_copy);
		DerivationNode *root = build_tree_from_trace(trace_capture);
		if(root != NULL)
		{
			printf("=== reverse derivation tree ===\n");
			print_tree(root, 0);
			free_tree(root);
		}
		fclose(trace_capture);
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
