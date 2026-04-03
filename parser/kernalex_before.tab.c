/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "parser/kernalex_before.y"

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

#line 90 "kernalex_before.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_INT = 1,                   /* TOK_INT  */
    TOK_SHORT = 2,                 /* TOK_SHORT  */
    TOK_FLOAT = 3,                 /* TOK_FLOAT  */
    TOK_CHAR = 4,                  /* TOK_CHAR  */
    TOK_VOID = 5,                  /* TOK_VOID  */
    TOK_BOOL = 6,                  /* TOK_BOOL  */
    TOK_BOOLEAN = 7,               /* TOK_BOOLEAN  */
    TOK_STRUCT = 8,                /* TOK_STRUCT  */
    TOK_INT8_T = 9,                /* TOK_INT8_T  */
    TOK_INT16_T = 10,              /* TOK_INT16_T  */
    TOK_INT32_T = 11,              /* TOK_INT32_T  */
    TOK_INT64_T = 12,              /* TOK_INT64_T  */
    TOK_SIGNED = 13,               /* TOK_SIGNED  */
    TOK_UNSIGNED = 14,             /* TOK_UNSIGNED  */
    TOK_EXTERN = 15,               /* TOK_EXTERN  */
    TOK_STATIC = 16,               /* TOK_STATIC  */
    TOK_IF = 17,                   /* TOK_IF  */
    TOK_ELSE = 18,                 /* TOK_ELSE  */
    TOK_FOR = 19,                  /* TOK_FOR  */
    TOK_WHILE = 20,                /* TOK_WHILE  */
    TOK_REPEAT = 21,               /* TOK_REPEAT  */
    TOK_UNTIL = 22,                /* TOK_UNTIL  */
    TOK_SWITCH = 23,               /* TOK_SWITCH  */
    TOK_CASE = 24,                 /* TOK_CASE  */
    TOK_DEFAULT = 25,              /* TOK_DEFAULT  */
    TOK_BREAK = 26,                /* TOK_BREAK  */
    TOK_CONTINUE = 27,             /* TOK_CONTINUE  */
    TOK_RETURN = 28,               /* TOK_RETURN  */
    TOK_SIZEOF = 29,               /* TOK_SIZEOF  */
    TOK_BEGIN = 30,                /* TOK_BEGIN  */
    TOK_END = 31,                  /* TOK_END  */
    TOK_TRUE = 32,                 /* TOK_TRUE  */
    TOK_FALSE = 33,                /* TOK_FALSE  */
    TOK_IDENTIFIER = 34,           /* TOK_IDENTIFIER  */
    TOK_INTEGER = 35,              /* TOK_INTEGER  */
    TOK_FLOAT_LIT = 36,            /* TOK_FLOAT_LIT  */
    TOK_CHAR_LIT = 37,             /* TOK_CHAR_LIT  */
    TOK_STRING_LIT = 38,           /* TOK_STRING_LIT  */
    TOK_PLUS = 39,                 /* TOK_PLUS  */
    TOK_MINUS = 40,                /* TOK_MINUS  */
    TOK_MULT = 41,                 /* TOK_MULT  */
    TOK_DIV = 42,                  /* TOK_DIV  */
    TOK_MOD = 43,                  /* TOK_MOD  */
    TOK_ASSIGN = 44,               /* TOK_ASSIGN  */
    TOK_EQ = 45,                   /* TOK_EQ  */
    TOK_NE = 46,                   /* TOK_NE  */
    TOK_LT = 47,                   /* TOK_LT  */
    TOK_LE = 48,                   /* TOK_LE  */
    TOK_GT = 49,                   /* TOK_GT  */
    TOK_GE = 50,                   /* TOK_GE  */
    TOK_SPACESHIP = 51,            /* TOK_SPACESHIP  */
    TOK_AND = 52,                  /* TOK_AND  */
    TOK_OR = 53,                   /* TOK_OR  */
    TOK_NOT = 54,                  /* TOK_NOT  */
    TOK_BITOR = 56,                /* TOK_BITOR  */
    TOK_XOR = 57,                  /* TOK_XOR  */
    TOK_BITNOT = 58,               /* TOK_BITNOT  */
    TOK_LSHIFT = 59,               /* TOK_LSHIFT  */
    TOK_RSHIFT = 60,               /* TOK_RSHIFT  */
    TOK_INC = 61,                  /* TOK_INC  */
    TOK_DEC = 62,                  /* TOK_DEC  */
    TOK_PLUSEQ = 63,               /* TOK_PLUSEQ  */
    TOK_MINUSEQ = 64,              /* TOK_MINUSEQ  */
    TOK_MULTEQ = 65,               /* TOK_MULTEQ  */
    TOK_DIVEQ = 66,                /* TOK_DIVEQ  */
    TOK_MODEQ = 67,                /* TOK_MODEQ  */
    TOK_ARROW = 68,                /* TOK_ARROW  */
    TOK_AMP = 69,                  /* TOK_AMP  */
    TOK_STAR = 70,                 /* TOK_STAR  */
    TOK_LPAREN = 71,               /* TOK_LPAREN  */
    TOK_RPAREN = 72,               /* TOK_RPAREN  */
    TOK_LBRACKET = 75,             /* TOK_LBRACKET  */
    TOK_RBRACKET = 76,             /* TOK_RBRACKET  */
    TOK_SEMICOLON = 77,            /* TOK_SEMICOLON  */
    TOK_COMMA = 78,                /* TOK_COMMA  */
    TOK_DOT = 79,                  /* TOK_DOT  */
    TOK_COLON = 80                 /* TOK_COLON  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 103 "parser/kernalex_before.y"

	int val;
	struct symtab *symp;

#line 221 "kernalex_before.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_INT = 3,                    /* TOK_INT  */
  YYSYMBOL_TOK_SHORT = 4,                  /* TOK_SHORT  */
  YYSYMBOL_TOK_FLOAT = 5,                  /* TOK_FLOAT  */
  YYSYMBOL_TOK_CHAR = 6,                   /* TOK_CHAR  */
  YYSYMBOL_TOK_VOID = 7,                   /* TOK_VOID  */
  YYSYMBOL_TOK_BOOL = 8,                   /* TOK_BOOL  */
  YYSYMBOL_TOK_BOOLEAN = 9,                /* TOK_BOOLEAN  */
  YYSYMBOL_TOK_STRUCT = 10,                /* TOK_STRUCT  */
  YYSYMBOL_TOK_INT8_T = 11,                /* TOK_INT8_T  */
  YYSYMBOL_TOK_INT16_T = 12,               /* TOK_INT16_T  */
  YYSYMBOL_TOK_INT32_T = 13,               /* TOK_INT32_T  */
  YYSYMBOL_TOK_INT64_T = 14,               /* TOK_INT64_T  */
  YYSYMBOL_TOK_SIGNED = 15,                /* TOK_SIGNED  */
  YYSYMBOL_TOK_UNSIGNED = 16,              /* TOK_UNSIGNED  */
  YYSYMBOL_TOK_EXTERN = 17,                /* TOK_EXTERN  */
  YYSYMBOL_TOK_STATIC = 18,                /* TOK_STATIC  */
  YYSYMBOL_TOK_IF = 19,                    /* TOK_IF  */
  YYSYMBOL_TOK_ELSE = 20,                  /* TOK_ELSE  */
  YYSYMBOL_TOK_FOR = 21,                   /* TOK_FOR  */
  YYSYMBOL_TOK_WHILE = 22,                 /* TOK_WHILE  */
  YYSYMBOL_TOK_REPEAT = 23,                /* TOK_REPEAT  */
  YYSYMBOL_TOK_UNTIL = 24,                 /* TOK_UNTIL  */
  YYSYMBOL_TOK_SWITCH = 25,                /* TOK_SWITCH  */
  YYSYMBOL_TOK_CASE = 26,                  /* TOK_CASE  */
  YYSYMBOL_TOK_DEFAULT = 27,               /* TOK_DEFAULT  */
  YYSYMBOL_TOK_BREAK = 28,                 /* TOK_BREAK  */
  YYSYMBOL_TOK_CONTINUE = 29,              /* TOK_CONTINUE  */
  YYSYMBOL_TOK_RETURN = 30,                /* TOK_RETURN  */
  YYSYMBOL_TOK_SIZEOF = 31,                /* TOK_SIZEOF  */
  YYSYMBOL_TOK_BEGIN = 32,                 /* TOK_BEGIN  */
  YYSYMBOL_TOK_END = 33,                   /* TOK_END  */
  YYSYMBOL_TOK_TRUE = 34,                  /* TOK_TRUE  */
  YYSYMBOL_TOK_FALSE = 35,                 /* TOK_FALSE  */
  YYSYMBOL_TOK_IDENTIFIER = 36,            /* TOK_IDENTIFIER  */
  YYSYMBOL_TOK_INTEGER = 37,               /* TOK_INTEGER  */
  YYSYMBOL_TOK_FLOAT_LIT = 38,             /* TOK_FLOAT_LIT  */
  YYSYMBOL_TOK_CHAR_LIT = 39,              /* TOK_CHAR_LIT  */
  YYSYMBOL_TOK_STRING_LIT = 40,            /* TOK_STRING_LIT  */
  YYSYMBOL_TOK_PLUS = 41,                  /* TOK_PLUS  */
  YYSYMBOL_TOK_MINUS = 42,                 /* TOK_MINUS  */
  YYSYMBOL_TOK_MULT = 43,                  /* TOK_MULT  */
  YYSYMBOL_TOK_DIV = 44,                   /* TOK_DIV  */
  YYSYMBOL_TOK_MOD = 45,                   /* TOK_MOD  */
  YYSYMBOL_TOK_ASSIGN = 46,                /* TOK_ASSIGN  */
  YYSYMBOL_TOK_EQ = 47,                    /* TOK_EQ  */
  YYSYMBOL_TOK_NE = 48,                    /* TOK_NE  */
  YYSYMBOL_TOK_LT = 49,                    /* TOK_LT  */
  YYSYMBOL_TOK_LE = 50,                    /* TOK_LE  */
  YYSYMBOL_TOK_GT = 51,                    /* TOK_GT  */
  YYSYMBOL_TOK_GE = 52,                    /* TOK_GE  */
  YYSYMBOL_TOK_SPACESHIP = 53,             /* TOK_SPACESHIP  */
  YYSYMBOL_TOK_AND = 54,                   /* TOK_AND  */
  YYSYMBOL_TOK_OR = 55,                    /* TOK_OR  */
  YYSYMBOL_TOK_NOT = 56,                   /* TOK_NOT  */
  YYSYMBOL_TOK_BITOR = 57,                 /* TOK_BITOR  */
  YYSYMBOL_TOK_XOR = 58,                   /* TOK_XOR  */
  YYSYMBOL_TOK_BITNOT = 59,                /* TOK_BITNOT  */
  YYSYMBOL_TOK_LSHIFT = 60,                /* TOK_LSHIFT  */
  YYSYMBOL_TOK_RSHIFT = 61,                /* TOK_RSHIFT  */
  YYSYMBOL_TOK_INC = 62,                   /* TOK_INC  */
  YYSYMBOL_TOK_DEC = 63,                   /* TOK_DEC  */
  YYSYMBOL_TOK_PLUSEQ = 64,                /* TOK_PLUSEQ  */
  YYSYMBOL_TOK_MINUSEQ = 65,               /* TOK_MINUSEQ  */
  YYSYMBOL_TOK_MULTEQ = 66,                /* TOK_MULTEQ  */
  YYSYMBOL_TOK_DIVEQ = 67,                 /* TOK_DIVEQ  */
  YYSYMBOL_TOK_MODEQ = 68,                 /* TOK_MODEQ  */
  YYSYMBOL_TOK_ARROW = 69,                 /* TOK_ARROW  */
  YYSYMBOL_TOK_AMP = 70,                   /* TOK_AMP  */
  YYSYMBOL_TOK_STAR = 71,                  /* TOK_STAR  */
  YYSYMBOL_TOK_LPAREN = 72,                /* TOK_LPAREN  */
  YYSYMBOL_TOK_RPAREN = 73,                /* TOK_RPAREN  */
  YYSYMBOL_TOK_LBRACKET = 74,              /* TOK_LBRACKET  */
  YYSYMBOL_TOK_RBRACKET = 75,              /* TOK_RBRACKET  */
  YYSYMBOL_TOK_SEMICOLON = 76,             /* TOK_SEMICOLON  */
  YYSYMBOL_TOK_COMMA = 77,                 /* TOK_COMMA  */
  YYSYMBOL_TOK_DOT = 78,                   /* TOK_DOT  */
  YYSYMBOL_TOK_COLON = 79,                 /* TOK_COLON  */
  YYSYMBOL_YYACCEPT = 80,                  /* $accept  */
  YYSYMBOL_primary_expression = 81,        /* primary_expression  */
  YYSYMBOL_constant = 82,                  /* constant  */
  YYSYMBOL_string = 83,                    /* string  */
  YYSYMBOL_postfix_expression = 84,        /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 85,  /* argument_expression_list  */
  YYSYMBOL_unary_expression = 86,          /* unary_expression  */
  YYSYMBOL_unary_operator = 87,            /* unary_operator  */
  YYSYMBOL_cast_expression = 88,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 89, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 90,       /* additive_expression  */
  YYSYMBOL_shift_expression = 91,          /* shift_expression  */
  YYSYMBOL_relational_expression = 92,     /* relational_expression  */
  YYSYMBOL_equality_expression = 93,       /* equality_expression  */
  YYSYMBOL_and_expression = 94,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 95,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 96,   /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 97,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 98,     /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 99,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 100,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 101,      /* assignment_operator  */
  YYSYMBOL_expression = 102,               /* expression  */
  YYSYMBOL_constant_expression = 103,      /* constant_expression  */
  YYSYMBOL_declaration = 104,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 105,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 106,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 107,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 108,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 109,           /* type_specifier  */
  YYSYMBOL_struct_specifier = 110,         /* struct_specifier  */
  YYSYMBOL_struct_declaration_list = 111,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 112,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 113, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 114,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 115,        /* struct_declarator  */
  YYSYMBOL_declarator = 116,               /* declarator  */
  YYSYMBOL_117_1 = 117,                    /* $@1  */
  YYSYMBOL_direct_declarator = 118,        /* direct_declarator  */
  YYSYMBOL_pointer = 119,                  /* pointer  */
  YYSYMBOL_parameter_type_list = 120,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 121,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 122,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 123,          /* identifier_list  */
  YYSYMBOL_type_name = 124,                /* type_name  */
  YYSYMBOL_abstract_declarator = 125,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 126, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 127,              /* initializer  */
  YYSYMBOL_initializer_list = 128,         /* initializer_list  */
  YYSYMBOL_designation = 129,              /* designation  */
  YYSYMBOL_designator_list = 130,          /* designator_list  */
  YYSYMBOL_designator = 131,               /* designator  */
  YYSYMBOL_statement = 132,                /* statement  */
  YYSYMBOL_labeled_statement = 133,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 134,       /* compound_statement  */
  YYSYMBOL_block_item_list = 135,          /* block_item_list  */
  YYSYMBOL_block_item = 136,               /* block_item  */
  YYSYMBOL_expression_statement = 137,     /* expression_statement  */
  YYSYMBOL_selection_statement = 138,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 139,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 140,           /* jump_statement  */
  YYSYMBOL_translation_unit = 141,         /* translation_unit  */
  YYSYMBOL_external_declaration = 142,     /* external_declaration  */
  YYSYMBOL_function_definition = 143,      /* function_definition  */
  YYSYMBOL_declaration_list = 144          /* declaration_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  37
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1575

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  65
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  338

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   257


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,     2,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     2,     2,    74,    75,    76,    77,    78,
      79,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   112,   113,   114,   115,   116,   120,   121,
     122,   126,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   144,   145,   149,   150,   151,   152,   153,   154,
     158,   159,   160,   161,   162,   163,   167,   168,   172,   173,
     174,   175,   179,   180,   181,   185,   186,   187,   191,   192,
     193,   194,   195,   196,   200,   201,   202,   206,   207,   211,
     212,   216,   217,   221,   222,   226,   227,   231,   235,   236,
     240,   241,   242,   243,   244,   245,   249,   250,   254,   258,
     259,   263,   264,   265,   266,   270,   271,   275,   276,   280,
     281,   285,   286,   287,   288,   289,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   302,   303,   307,   308,   312,
     313,   317,   318,   322,   323,   327,   328,   329,   334,   334,
     335,   339,   340,   341,   342,   343,   344,   345,   349,   350,
     356,   360,   361,   365,   366,   367,   371,   372,   376,   377,
     381,   382,   383,   387,   388,   389,   390,   391,   392,   393,
     394,   395,   399,   400,   401,   405,   406,   407,   408,   412,
     416,   417,   421,   422,   426,   427,   428,   429,   430,   431,
     435,   436,   437,   441,   442,   446,   447,   451,   452,   456,
     457,   461,   462,   463,   467,   468,   469,   470,   471,   472,
     476,   477,   478,   479,   483,   484,   488,   489,   493,   494,
     498,   499
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOK_INT", "TOK_SHORT",
  "TOK_FLOAT", "TOK_CHAR", "TOK_VOID", "TOK_BOOL", "TOK_BOOLEAN",
  "TOK_STRUCT", "TOK_INT8_T", "TOK_INT16_T", "TOK_INT32_T", "TOK_INT64_T",
  "TOK_SIGNED", "TOK_UNSIGNED", "TOK_EXTERN", "TOK_STATIC", "TOK_IF",
  "TOK_ELSE", "TOK_FOR", "TOK_WHILE", "TOK_REPEAT", "TOK_UNTIL",
  "TOK_SWITCH", "TOK_CASE", "TOK_DEFAULT", "TOK_BREAK", "TOK_CONTINUE",
  "TOK_RETURN", "TOK_SIZEOF", "TOK_BEGIN", "TOK_END", "TOK_TRUE",
  "TOK_FALSE", "TOK_IDENTIFIER", "TOK_INTEGER", "TOK_FLOAT_LIT",
  "TOK_CHAR_LIT", "TOK_STRING_LIT", "TOK_PLUS", "TOK_MINUS", "TOK_MULT",
  "TOK_DIV", "TOK_MOD", "TOK_ASSIGN", "TOK_EQ", "TOK_NE", "TOK_LT",
  "TOK_LE", "TOK_GT", "TOK_GE", "TOK_SPACESHIP", "TOK_AND", "TOK_OR",
  "TOK_NOT", "TOK_BITOR", "TOK_XOR", "TOK_BITNOT", "TOK_LSHIFT",
  "TOK_RSHIFT", "TOK_INC", "TOK_DEC", "TOK_PLUSEQ", "TOK_MINUSEQ",
  "TOK_MULTEQ", "TOK_DIVEQ", "TOK_MODEQ", "TOK_ARROW", "TOK_AMP",
  "TOK_STAR", "TOK_LPAREN", "TOK_RPAREN", "TOK_LBRACKET", "TOK_RBRACKET",
  "TOK_SEMICOLON", "TOK_COMMA", "TOK_DOT", "TOK_COLON", "$accept",
  "primary_expression", "constant", "string", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_specifier",
  "struct_declaration_list", "struct_declaration",
  "specifier_qualifier_list", "struct_declarator_list",
  "struct_declarator", "declarator", "$@1", "direct_declarator", "pointer",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "designation", "designator_list", "designator", "statement",
  "labeled_statement", "compound_statement", "block_item_list",
  "block_item", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-260)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-119)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1543,  -260,  -260,  -260,  -260,  -260,  -260,  -260,    18,  -260,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,  -260,    -5,  1543,
    1543,  -260,  1527,  -260,  -260,    36,  -260,   -54,     7,  -260,
     101,  -260,  1142,    39,  -260,  -260,  -260,  -260,  -260,  1559,
    -260,   -27,  -260,     7,   349,  1259,  -260,    -5,  -260,  1497,
     605,   985,    -2,  1559,   311,  -260,    -7,  -260,  -260,    35,
      12,    16,    34,   715,    48,  1343,    50,    68,    75,   899,
    1385,  -260,  -260,  -260,    85,  -260,  -260,  -260,  -260,  -260,
    -260,  -260,  -260,  1427,  1427,  -260,  -260,   661,  -260,  -260,
    -260,  -260,    47,    69,  1343,  -260,   130,    20,   119,    89,
     135,   118,   140,   142,   148,   149,  -260,  -260,   108,  -260,
    -260,  -260,  -260,   423,  -260,  -260,  -260,  -260,  -260,   854,
    -260,  -260,  -260,  -260,  -260,  -260,  -260,   -21,   133,   126,
    -260,   -35,  -260,   134,    39,  -260,  -260,  -260,  -260,  1343,
     110,  -260,   129,  1343,   497,  1343,   186,  1343,  -260,  -260,
     136,   715,  -260,  -260,  -260,   114,   661,  -260,   715,   661,
    -260,  -260,    10,    96,   139,  -260,  -260,   177,  1130,  1343,
     178,  -260,  -260,  -260,  -260,  -260,  -260,  1343,  -260,  1343,
    1343,  1343,  1343,  1343,  1343,  1343,  1343,  1343,  1343,  1343,
    1343,  1343,  1343,  1343,  1343,  1343,  1343,  1343,  -260,  1343,
    -260,  -260,  1343,   180,  -260,   -19,  1259,    11,  -260,   571,
    1027,  -260,     3,  -260,    52,  -260,  1543,  -260,   183,  -260,
    -260,  -260,   -16,  1343,    13,   942,   942,    25,   150,    31,
     715,  -260,  -260,   147,  -260,   151,  -260,   587,    97,  -260,
    1301,  -260,  -260,    45,  -260,    83,  -260,  -260,  -260,  -260,
    -260,   130,   130,    20,    20,   119,   119,   119,   119,   119,
      89,    89,   135,   118,   140,   142,   148,  -260,   146,  -260,
    -260,   761,  -260,  -260,  -260,  -260,   152,   155,  -260,   156,
      52,   621,  1069,  -260,  -260,  -260,  -260,   715,  1173,  1216,
     715,  1343,   715,  -260,   191,   191,   854,  -260,  -260,  1343,
    -260,  -260,  -260,  -260,  1259,  -260,  -260,  -260,  -260,   157,
    -260,   158,   216,   715,    79,   715,    80,  -260,    86,  -260,
     -17,  -260,  -260,  -260,  -260,   715,  -260,   715,  -260,   715,
     162,  -260,   809,  -260,  -260,  -260,  -260,  -260
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    94,    93,    95,    92,    91,    96,    97,     0,    98,
      99,   100,   101,   102,   103,    89,    90,   197,     0,    82,
      84,   104,     0,   194,   196,   106,   121,   129,     0,    79,
       0,    85,    88,   120,   118,    81,    83,     1,   195,     0,
     128,     0,    80,     0,     0,     0,   200,     0,   199,     0,
       0,     0,     0,   112,     0,   107,     0,   122,    86,    88,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,     5,     6,     2,     8,     9,    10,    11,    32,
      33,    35,    34,     0,     0,    30,    31,     0,   179,    12,
       3,     4,    24,    36,     0,    38,    42,    45,    48,    54,
      57,    59,    61,    63,    65,    67,    68,    76,     0,   177,
     178,   164,   165,     0,   175,   166,   167,   168,   169,     0,
       2,   154,    87,   201,   198,   136,   126,   135,     0,   130,
     131,     0,   123,     0,   119,   111,   105,   108,   109,     0,
       0,   113,   117,     0,     0,     0,     0,     0,    36,    78,
       0,     0,   191,   190,   192,     0,     0,    28,     0,     0,
      25,    26,     0,   139,     0,    18,    19,     0,     0,     0,
       0,    70,    74,    75,    71,    72,    73,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   180,     0,
     174,   176,     0,     0,   156,     0,     0,     0,   160,     0,
       0,   133,   141,   134,   142,   125,     0,   127,     0,   124,
     115,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,   193,     0,   170,     0,     7,     0,   141,   138,
       0,    17,    14,     0,    22,     0,    16,    69,    39,    40,
      41,    43,    44,    46,    47,    49,    51,    50,    52,    53,
      55,    56,    58,    60,    62,    64,    66,    77,     0,   163,
     152,     0,   155,   159,   161,   148,     0,     0,   144,     0,
     140,     0,     0,   132,   137,   114,   116,     0,     0,     0,
       0,     0,     0,   171,    29,     0,     0,    37,    15,     0,
      13,   162,   153,   158,     0,   149,   143,   145,   150,     0,
     146,     0,   182,     0,     0,     0,     0,   184,     0,   183,
       0,    23,   157,   151,   147,     0,   188,     0,   186,     0,
       0,    20,     0,   181,   189,   187,   185,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -260,  -260,  -260,  -260,  -260,  -260,   111,  -260,   -85,    14,
       8,   -40,     9,    49,    46,    53,    56,    44,  -260,   -57,
     -45,  -260,   -42,  -126,   -14,     2,  -260,   200,  -260,   -28,
    -260,  -260,   190,    -6,  -260,    23,   -15,  -260,   201,   -20,
     -46,  -260,    40,  -260,  -119,   -83,  -189,   -44,   -38,  -259,
    -260,    54,   -58,  -260,   -13,  -260,   153,  -134,  -260,  -260,
    -260,  -260,   240,  -260,  -260
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    89,    90,    91,    92,   243,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   177,   108,   150,    17,    47,    30,    31,    19,    20,
      21,    54,    55,   163,   140,   141,    41,    52,    33,    34,
     276,   129,   130,   131,   164,   277,   214,   204,   205,   206,
     207,   208,   110,   111,   112,   113,   114,   115,   116,   117,
     118,    22,    23,    24,    49
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     121,   122,    18,    32,   128,   146,   133,    40,   149,   178,
     226,    53,   304,   220,   270,    26,   331,    27,    46,    48,
      26,    35,    36,   280,    18,    53,    53,   155,    59,    26,
     109,    26,    59,    56,    26,   123,   124,   233,   217,  -118,
     235,   142,   218,    26,   213,   162,    57,   135,    56,   280,
      27,   209,   127,   210,    25,    27,    28,   273,   271,    53,
     332,   182,   183,   139,    27,    28,    27,    28,    39,   138,
      28,    29,   139,   304,   121,   237,   268,   210,    27,    28,
     239,    45,   149,   236,   143,   202,   287,   199,   144,   203,
     199,   288,   289,   231,   248,   249,   250,   286,   290,   109,
     234,   224,   199,   227,   292,   229,   145,   212,   199,   165,
     166,    50,   211,    51,   162,   171,   167,   162,   298,   168,
     147,   169,   299,   244,   281,   170,   282,   245,    53,   151,
     225,    53,   247,   172,   173,   174,   175,   176,   186,   187,
     188,   189,   190,   238,   152,   149,   255,   256,   257,   258,
     259,   153,   327,   329,   267,   297,   199,   199,   300,   330,
     199,   121,   272,   199,   158,   279,   149,    27,   237,   237,
     210,   210,   293,   179,   180,   181,   148,    42,    43,   184,
     185,   157,   191,   192,   198,   199,   221,   222,   193,   212,
     232,   199,   253,   254,   160,   161,   251,   252,   194,   195,
     260,   261,   196,   216,   197,   148,   215,   142,   223,   219,
     228,   127,   240,   241,   246,   230,   269,   238,   127,   284,
     294,   301,   291,   296,   295,   305,   121,   303,   306,   312,
     323,   307,   317,   324,   319,   309,   325,   311,   336,   127,
     263,   266,   262,    58,   137,   285,   314,   316,   264,   318,
     148,   121,   265,   134,   321,   326,   283,   328,   320,   121,
     322,   274,    38,     0,     0,     0,   201,   333,     0,   334,
       0,   335,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   121,   303,     0,
     148,   148,   148,   148,   148,   148,   148,   148,   148,   148,
     148,   148,   148,   148,   148,   148,   148,   148,   148,     0,
       0,     0,     0,   148,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,     0,     0,
       0,     0,     0,     0,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   136,     0,     0,     0,     0,     0,
       0,   148,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    60,     0,
      61,    62,    63,     0,    64,    65,    66,    67,    68,    69,
      70,    44,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    82,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,     0,     0,    88,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    60,     0,    61,    62,    63,     0,    64,    65,
      66,    67,    68,    69,    70,    44,   200,    72,    73,    74,
      75,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    82,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,    85,    86,    87,     0,     0,     0,    88,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,    72,    73,   120,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,    82,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,    85,    86,    87,
       0,     0,     0,    88,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,    26,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,   125,    27,   209,   275,   210,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,   237,
     275,   210,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,   308,    72,    73,   120,    75,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      82,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    60,     0,    61,    62,    63,     0,
      64,    65,    66,    67,    68,    69,    70,    44,     0,    72,
      73,    74,    75,    76,    77,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    82,     0,     0,    83,    84,     0,
       0,     0,     0,     0,     0,    85,    86,    87,     0,     0,
       0,    88,    70,   119,   302,    72,    73,   120,    75,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      82,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,    85,    86,    87,     0,   202,     0,     0,     0,   203,
      70,   119,   337,    72,    73,   120,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    82,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,   202,     0,    70,   119,   203,    72,    73,
     120,    75,    76,    77,    78,    79,    80,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,     0,     0,    82,     0,     0,    83,    84,     0,     0,
       0,     0,     0,     0,    85,    86,    87,     0,   202,     0,
      70,     0,   203,    72,    73,   120,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    82,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,    70,     0,   154,    72,    73,   120,    75,
      76,    77,    78,    79,    80,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    81,     0,
       0,    82,     0,     0,    83,    84,     0,     0,     0,     0,
       0,     0,    85,    86,    87,     0,    70,     0,    88,    72,
      73,   120,    75,    76,    77,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    82,     0,     0,    83,    84,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    70,     0,
     132,    72,    73,   120,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,    82,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      70,     0,   278,    72,    73,   120,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    82,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,     0,     0,   310,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    70,     0,     0,    72,    73,   120,    75,    76,    77,
      78,    79,    80,     0,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    81,     0,    45,    82,
       0,     0,    83,    84,     0,     0,     0,     0,     0,     0,
      85,    86,    87,   242,    70,     0,     0,    72,    73,   120,
      75,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    82,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,    85,    86,    87,   313,    70,     0,     0,
      72,    73,   120,    75,    76,    77,    78,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    81,     0,     0,    82,     0,     0,    83,    84,
       0,     0,     0,     0,     0,     0,    85,    86,    87,   315,
      70,   119,     0,    72,    73,   120,    75,    76,    77,    78,
      79,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    81,     0,     0,    82,     0,
       0,    83,    84,     0,     0,     0,     0,     0,     0,    85,
      86,    87,    70,   296,     0,    72,    73,   120,    75,    76,
      77,    78,    79,    80,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    81,     0,     0,
      82,     0,     0,    83,    84,     0,     0,     0,     0,     0,
       0,    85,    86,    87,    70,     0,     0,    72,    73,   120,
      75,    76,    77,    78,    79,    80,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    81,
       0,     0,    82,     0,     0,    83,    84,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    70,     0,     0,    72,
      73,   120,    75,    76,    77,    78,    79,    80,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    81,     0,     0,    82,     0,     0,    83,    84,     0,
       0,     0,     0,     0,     0,    85,    86,   156,    70,     0,
       0,    72,    73,   120,    75,    76,    77,    78,    79,    80,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,    82,     0,     0,    83,
      84,     0,     0,     0,     0,     0,     0,    85,    86,   159,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    37,     0,    44,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14
};

static const yytype_int16 yycheck[] =
{
      45,    45,     0,    18,    50,    63,    51,    27,    65,    94,
     144,    39,   271,   139,    33,    36,    33,    71,    32,    32,
      36,    19,    20,   212,    22,    53,    54,    69,    43,    36,
      44,    36,    47,    39,    36,    49,    49,   156,    73,    36,
     159,    56,    77,    36,   127,    87,    73,    53,    54,   238,
      71,    72,    50,    74,    36,    71,    72,    46,    77,    87,
      77,    41,    42,    79,    71,    72,    71,    72,    32,    76,
      72,    76,    79,   332,   119,    72,   202,    74,    71,    72,
     163,    46,   139,    73,    72,    74,    73,    77,    72,    78,
      77,   225,   226,   151,   179,   180,   181,   223,    73,   113,
     158,   143,    77,   145,    73,   147,    72,   127,    77,    62,
      63,    72,   127,    74,   156,    46,    69,   159,    73,    72,
      72,    74,    77,   168,    72,    78,    74,   169,   156,    79,
     144,   159,   177,    64,    65,    66,    67,    68,    49,    50,
      51,    52,    53,   163,    76,   202,   186,   187,   188,   189,
     190,    76,    73,    73,   199,   240,    77,    77,    75,    73,
      77,   206,   206,    77,    79,   210,   223,    71,    72,    72,
      74,    74,   230,    43,    44,    45,    65,    76,    77,    60,
      61,    70,    47,    48,    76,    77,    76,    77,    70,   209,
      76,    77,   184,   185,    83,    84,   182,   183,    58,    57,
     191,   192,    54,    77,    55,    94,    73,   222,    79,    75,
      24,   209,    73,    36,    36,    79,    36,   237,   216,    36,
      73,    75,    72,    32,    73,    73,   271,   271,    73,   287,
      73,    75,   290,    75,   292,   281,    20,   282,    76,   237,
     194,   197,   193,    43,    54,   222,   288,   289,   195,   291,
     139,   296,   196,    52,   299,   313,   216,   315,   296,   304,
     304,   207,    22,    -1,    -1,    -1,   113,   325,    -1,   327,
      -1,   329,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   281,    -1,    -1,    -1,   332,   332,    -1,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,    -1,   202,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      -1,    -1,    -1,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,   240,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    -1,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    -1,    21,    22,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    36,    71,    72,    73,    74,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,    74,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    73,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    73,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    19,    -1,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    74,    -1,    -1,    -1,    78,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    74,    -1,    31,    32,    78,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    74,    -1,
      31,    -1,    78,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    31,    -1,    76,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    31,    -1,    76,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    31,    -1,
      75,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      31,    -1,    75,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    75,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    31,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    46,    59,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,    73,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    31,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,    63,
      -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,    73,
      31,    32,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    31,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    31,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    31,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    31,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,    32,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   104,   105,   108,
     109,   110,   141,   142,   143,    36,    36,    71,    72,    76,
     106,   107,   116,   118,   119,   105,   105,     0,   142,    32,
     119,   116,    76,    77,    32,    46,   104,   105,   134,   144,
      72,    74,   117,   109,   111,   112,   113,    73,   107,   116,
      19,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      31,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    56,    59,    62,    63,    70,    71,    72,    76,    81,
      82,    83,    84,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   102,   104,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    32,
      36,   100,   127,   104,   134,    36,    73,   105,   120,   121,
     122,   123,    75,   100,   118,   113,    33,   112,    76,    79,
     114,   115,   116,    72,    72,    72,   132,    72,    86,    99,
     103,    79,    76,    76,    76,   102,    72,    86,    79,    72,
      86,    86,   102,   113,   124,    62,    63,    69,    72,    74,
      78,    46,    64,    65,    66,    67,    68,   101,    88,    43,
      44,    45,    41,    42,    60,    61,    49,    50,    51,    52,
      53,    47,    48,    70,    58,    57,    54,    55,    76,    77,
      33,   136,    74,    78,   127,   128,   129,   130,   131,    72,
      74,   116,   119,   125,   126,    73,    77,    73,    77,    75,
     103,    76,    77,    79,   102,   104,   137,   102,    24,   102,
      79,   132,    76,   124,   132,   124,    73,    72,   119,   125,
      73,    36,    73,    85,   100,   102,    36,   100,    88,    88,
      88,    89,    89,    90,    90,    91,    91,    91,    91,    91,
      92,    92,    93,    94,    95,    96,    97,   100,   103,    36,
      33,    77,   127,    46,   131,    73,   120,   125,    75,   100,
     126,    72,    74,   122,    36,   115,   103,    73,   137,   137,
      73,    72,    73,   132,    73,    73,    32,    88,    73,    77,
      75,    75,    33,   127,   129,    73,    73,    75,    73,   120,
      75,   100,   132,    73,   102,    73,   102,   132,   102,   132,
     128,   100,   127,    73,    75,    20,   132,    73,   132,    73,
      73,    33,    77,   132,   132,   132,    76,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    90,    90,    90,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    98,    98,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   104,
     104,   105,   105,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   114,   114,   115,   115,   115,   117,   116,
     116,   118,   118,   118,   118,   118,   118,   118,   119,   119,
     120,   121,   121,   122,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   127,   127,   127,   128,   128,   128,   128,   129,
     130,   130,   131,   131,   132,   132,   132,   132,   132,   132,
     133,   133,   133,   134,   134,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   139,   139,   139,   139,   139,   139,
     140,   140,   140,   140,   141,   141,   142,   142,   143,   143,
     144,   144
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     2,
       3,     2,     1,     2,     1,     1,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     2,     1,     2,     2,
       3,     2,     1,     1,     3,     2,     3,     1,     0,     3,
       1,     1,     3,     3,     4,     4,     3,     4,     2,     1,
       1,     1,     3,     2,     2,     1,     1,     3,     2,     1,
       2,     1,     1,     3,     2,     3,     3,     4,     2,     3,
       3,     4,     3,     4,     1,     2,     1,     4,     3,     2,
       1,     2,     3,     2,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     1,     2,     1,     1,     1,
       2,     7,     5,     5,     5,     7,     6,     7,     6,     7,
       2,     2,     2,     3,     1,     2,     1,     1,     4,     3,
       1,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 8: /* constant: TOK_INTEGER  */
#line 120 "parser/kernalex_before.y"
                      {int_consts++;}
#line 1850 "kernalex_before.tab.c"
    break;

  case 118: /* $@1: %empty  */
#line 334 "parser/kernalex_before.y"
                  {pointer_decls++;}
#line 1856 "kernalex_before.tab.c"
    break;

  case 128: /* pointer: TOK_STAR pointer  */
#line 349 "parser/kernalex_before.y"
                           {pointer_decls++;}
#line 1862 "kernalex_before.tab.c"
    break;

  case 129: /* pointer: TOK_STAR  */
#line 350 "parser/kernalex_before.y"
                   {pointer_decls++;}
#line 1868 "kernalex_before.tab.c"
    break;

  case 194: /* translation_unit: external_declaration  */
#line 483 "parser/kernalex_before.y"
                               {global_declarations++;}
#line 1874 "kernalex_before.tab.c"
    break;

  case 195: /* translation_unit: translation_unit external_declaration  */
#line 484 "parser/kernalex_before.y"
                                                {global_declarations++;}
#line 1880 "kernalex_before.tab.c"
    break;

  case 196: /* external_declaration: function_definition  */
#line 488 "parser/kernalex_before.y"
                              {func_definitions++;}
#line 1886 "kernalex_before.tab.c"
    break;


#line 1890 "kernalex_before.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 502 "parser/kernalex_before.y"

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

#if YYDEBUG
	yydebug = 1;
#endif

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
