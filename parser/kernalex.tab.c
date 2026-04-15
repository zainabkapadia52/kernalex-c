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
#line 1 "parser/kernalex.y"

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

#line 116 "parser/kernalex.tab.c"

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

#include "kernalex.tab.h"
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
  YYSYMBOL_cast_expression = 87,           /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 88, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 89,       /* additive_expression  */
  YYSYMBOL_shift_expression = 90,          /* shift_expression  */
  YYSYMBOL_relational_expression = 91,     /* relational_expression  */
  YYSYMBOL_equality_expression = 92,       /* equality_expression  */
  YYSYMBOL_and_expression = 93,            /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 94,   /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 95,   /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 96,    /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 97,     /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 98,    /* conditional_expression  */
  YYSYMBOL_assignment_expression = 99,     /* assignment_expression  */
  YYSYMBOL_expression = 100,               /* expression  */
  YYSYMBOL_constant_expression = 101,      /* constant_expression  */
  YYSYMBOL_declaration = 102,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 103,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 104,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 105,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 106,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 107,           /* type_specifier  */
  YYSYMBOL_struct_specifier = 108,         /* struct_specifier  */
  YYSYMBOL_struct_declaration_list = 109,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 110,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 111, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 112,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 113,        /* struct_declarator  */
  YYSYMBOL_declarator = 114,               /* declarator  */
  YYSYMBOL_direct_declarator = 115,        /* direct_declarator  */
  YYSYMBOL_pointer = 116,                  /* pointer  */
  YYSYMBOL_parameter_type_list = 117,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 118,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 119,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 120,          /* identifier_list  */
  YYSYMBOL_type_name = 121,                /* type_name  */
  YYSYMBOL_abstract_declarator = 122,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 123, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 124,              /* initializer  */
  YYSYMBOL_initializer_list = 125,         /* initializer_list  */
  YYSYMBOL_designation = 126,              /* designation  */
  YYSYMBOL_designator_list = 127,          /* designator_list  */
  YYSYMBOL_designator = 128,               /* designator  */
  YYSYMBOL_statement = 129,                /* statement  */
  YYSYMBOL_compound_statement = 130,       /* compound_statement  */
  YYSYMBOL_block_item_list = 131,          /* block_item_list  */
  YYSYMBOL_block_item = 132,               /* block_item  */
  YYSYMBOL_expression_statement = 133,     /* expression_statement  */
  YYSYMBOL_L_mark = 134,                   /* L_mark  */
  YYSYMBOL_M_mark_stmt = 135,              /* M_mark_stmt  */
  YYSYMBOL_M_mark_expr = 136,              /* M_mark_expr  */
  YYSYMBOL_if_head = 137,                  /* if_head  */
  YYSYMBOL_if_else_head = 138,             /* if_else_head  */
  YYSYMBOL_M_for_body = 139,               /* M_for_body  */
  YYSYMBOL_M_for_update = 140,             /* M_for_update  */
  YYSYMBOL_M_for_post_empty = 141,         /* M_for_post_empty  */
  YYSYMBOL_M_for_post_expr = 142,          /* M_for_post_expr  */
  YYSYMBOL_matched_statement = 143,        /* matched_statement  */
  YYSYMBOL_unmatched_statement = 144,      /* unmatched_statement  */
  YYSYMBOL_iteration_statement = 145,      /* iteration_statement  */
  YYSYMBOL_unmatched_iteration_statement = 146, /* unmatched_iteration_statement  */
  YYSYMBOL_jump_statement = 147,           /* jump_statement  */
  YYSYMBOL_translation_unit = 148,         /* translation_unit  */
  YYSYMBOL_function_definition = 149,      /* function_definition  */
  YYSYMBOL_declaration_list = 150          /* declaration_list  */
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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

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
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1502

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  80
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  214
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  410

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
       0,   167,   167,   168,   169,   170,   171,   172,   176,   181,
     182,   186,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   204,   205,   209,   210,   211,   212,   219,   220,
     221,   222,   223,   227,   228,   232,   233,   240,   247,   257,
     258,   265,   275,   276,   277,   281,   282,   283,   284,   285,
     286,   290,   291,   292,   296,   297,   301,   302,   306,   307,
     311,   312,   316,   317,   321,   325,   326,   332,   338,   344,
     350,   356,   365,   366,   370,   374,   375,   379,   380,   381,
     382,   386,   387,   391,   397,   401,   402,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416,   417,   418,
     419,   423,   424,   428,   429,   433,   434,   438,   439,   443,
     444,   448,   449,   450,   455,   456,   460,   461,   462,   463,
     464,   465,   466,   470,   471,   477,   481,   482,   486,   487,
     488,   492,   493,   497,   498,   502,   503,   504,   508,   509,
     510,   511,   512,   513,   514,   515,   516,   520,   521,   522,
     529,   530,   531,   532,   536,   540,   541,   545,   546,   550,
     551,   555,   556,   560,   561,   565,   566,   570,   571,   575,
     576,   577,   578,   579,   581,   582,   583,   584,   587,   588,
     589,   590,   591,   592,   593,   594,   595,   599,   600,   601,
     602,   603,   604,   608,   609,   610,   611,   612,   613,   617,
     618,   619,   620,   621,   622,   626,   627,   628,   629,   633,
     634,   638,   639,   643,   644
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "end of file", "error", "invalid token", "TOK_INT", "TOK_SHORT",
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
  "argument_expression_list", "unary_expression", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "expression",
  "constant_expression", "declaration", "declaration_specifiers",
  "init_declarator_list", "init_declarator", "storage_class_specifier",
  "type_specifier", "struct_specifier", "struct_declaration_list",
  "struct_declaration", "specifier_qualifier_list",
  "struct_declarator_list", "struct_declarator", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "designation", "designator_list", "designator",
  "statement", "compound_statement", "block_item_list", "block_item",
  "expression_statement", "L_mark", "M_mark_stmt", "M_mark_expr",
  "if_head", "if_else_head", "M_for_body", "M_for_update",
  "M_for_post_empty", "M_for_post_expr", "matched_statement",
  "unmatched_statement", "iteration_statement",
  "unmatched_iteration_statement", "jump_statement", "translation_unit",
  "function_definition", "declaration_list", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-357)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     445,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    22,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,    67,   445,
     445,  -357,    76,  -357,    60,  -357,    26,    17,  -357,   -44,
    -357,   752,   -29,    -2,  -357,  -357,  -357,   699,  -357,    58,
    -357,    17,   371,  1241,  -357,    67,  -357,  1470,   681,  1115,
     -29,   699,   607,  -357,    51,  -357,  -357,   103,    52,    84,
    -357,  -357,   100,  1361,    87,   112,   118,  1029,  -357,  -357,
    -357,   122,  -357,  -357,  -357,  -357,  1361,  1361,  1361,  1361,
    1400,  1400,  1361,  1361,   737,  -357,  -357,  -357,  -357,   117,
      95,  -357,    38,   140,    55,   147,   174,   141,   155,   162,
     176,   178,  -357,  -357,   161,  -357,  -357,  -357,   515,  -357,
    -357,   791,   791,  -357,  -357,  -357,  -357,  -357,   984,  -357,
    -357,  -357,  -357,  -357,  -357,  -357,    36,   183,   164,  -357,
     -35,  -357,   196,  -357,  -357,  -357,  -357,  1361,   163,  -357,
     170,  1361,   591,   186,   791,  1361,  -357,  -357,   194,   791,
    -357,  -357,  -357,   168,   791,  -357,  -357,  -357,  -357,   737,
    -357,  -357,  -357,  -357,   -33,    54,   201,  -357,  -357,   239,
    1321,  1361,   240,  1361,  1361,  1361,  1361,  1361,  1361,  1361,
    1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,
    1361,  1361,  1361,  1361,  1361,  1361,  1361,  1361,  -357,  1361,
    -357,  -357,  -357,   263,  -357,  -357,  1361,   249,  -357,   -13,
    1241,    73,  -357,   665,  1157,  -357,   -11,  -357,    28,  -357,
     445,  -357,   250,  -357,  -357,  -357,    19,  1361,     1,  -357,
    -357,  1361,   264,   267,    77,   791,  -357,  -357,  -357,  -357,
    -357,   214,  -357,   493,    74,  -357,  1282,  -357,  -357,    91,
    -357,    80,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,    38,    38,   140,   140,    55,    55,    55,    55,
      55,   147,   147,   174,   141,   155,   162,   176,  -357,  -357,
     217,  -357,  -357,   892,  -357,  -357,  -357,  -357,   226,   228,
    -357,   227,    28,   715,  1199,  -357,  -357,  -357,  -357,  -357,
    1072,  1072,   229,   230,   232,   236,   847,  -357,  -357,   280,
     984,  -357,  -357,  1361,  -357,  -357,  -357,  -357,  1241,  -357,
    -357,  -357,  -357,   244,  -357,   251,  -357,   246,   252,   791,
    1361,  1361,   256,  -357,  -357,  1361,   245,   253,   847,   847,
    -357,   -12,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
    -357,  -357,    94,   110,   591,   257,   847,   254,   847,   847,
     263,  -357,   939,   791,  1361,   791,  1361,   255,   258,  -357,
    -357,  1361,   847,  -357,  -357,  -357,   130,  -357,  -357,   133,
    -357,  -357,  1072,  1072,   265,  -357,  -357,   266,   268,   847,
     791,   791,  -357,  -357,  -357,  -357,  -357,  -357,  -357,  -357,
     847,  1361,   847,  1361,   135,   159,  -357,  -357,   847,   847
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    90,    89,    91,    88,    87,    92,    93,     0,    94,
      95,    96,    97,    98,    99,    85,    86,   210,     0,    78,
      80,   100,     0,   209,   102,   116,   124,     0,    75,     0,
      81,    84,   115,     0,    77,    79,     1,     0,   123,     0,
      76,     0,     0,     0,   213,     0,   212,     0,     0,     0,
     114,   108,     0,   103,     0,   117,    82,    84,     0,     0,
     169,   169,     0,     0,     0,     0,     0,     0,   161,     5,
       6,     2,     8,     9,    10,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   167,    12,     3,     4,    24,
      33,    35,    39,    42,    45,    51,    54,    56,    58,    60,
      62,    64,    65,    72,     0,   165,   166,   178,     0,   163,
     179,     0,     0,   159,   160,   180,   190,   181,     0,     2,
     149,    83,   214,   211,   131,   121,   130,     0,   125,   126,
       0,   118,     0,   107,   101,   104,   105,     0,     0,   109,
     113,     0,     0,     0,     0,     0,    33,    74,     0,     0,
     206,   205,   207,     0,     0,    28,    27,    29,    30,     0,
      25,    26,    31,    32,     0,   134,     0,    18,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   168,     0,
     162,   164,   191,   159,   186,   192,     0,     0,   151,     0,
       0,     0,   155,     0,     0,   128,   136,   129,   137,   120,
       0,   122,     0,   119,   111,   106,     0,     0,     0,   169,
     169,     0,     0,     0,     0,     0,   184,   189,   208,   182,
     187,     0,     7,     0,   136,   133,     0,    17,    14,     0,
      22,     0,    16,    66,    67,    68,    69,    70,    71,    36,
      37,    38,    40,    41,    43,    44,    46,    48,    47,    49,
      50,    52,    53,    55,    57,    59,    61,    63,    73,   173,
       0,   158,   147,     0,   150,   154,   156,   143,     0,     0,
     139,     0,   135,     0,     0,   127,   132,   110,   112,   172,
       0,     0,   171,     0,     0,     0,     0,   183,   188,     0,
       0,    34,    15,     0,    13,   157,   148,   153,     0,   144,
     138,   140,   145,     0,   141,     0,   170,   174,   174,     0,
       0,     0,     0,   169,   169,     0,     0,     2,     0,     0,
     185,     0,    23,   152,   146,   142,   176,   175,   176,   175,
     193,   199,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,     0,     0,   169,
     169,     0,     0,    21,   197,   203,     0,   195,   201,     0,
     194,   200,     0,     0,     0,   177,   177,   174,   174,     0,
       0,     0,   176,   175,   176,   175,   198,   204,   196,   202,
       0,     0,     0,     0,     0,     0,   177,   177,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -357,  -357,  -357,  -357,  -357,  -357,   289,    35,    69,    78,
      39,    75,   137,   142,   148,   146,   150,  -357,   -53,   -41,
     -66,  -126,     0,     4,  -357,   307,  -357,   -15,  -357,  -357,
     297,   -38,  -357,   124,    -6,   -24,   -20,   -43,  -357,   136,
    -357,   199,   -97,  -188,   -40,    63,  -268,  -357,   151,   284,
      10,  -357,   283,  -123,   -54,  -287,   -10,  -154,   -49,  -302,
    -333,  -321,  -356,   -45,   -95,  -357,  -357,  -357,  -357,  -357,
    -357
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    86,    87,    88,    89,   249,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   148,   105,    45,    29,    30,    19,    20,    21,    52,
      53,    54,   138,   139,    39,    32,    33,   288,   128,   129,
     130,   166,   289,   218,   208,   209,   210,   211,   212,   106,
     107,   108,   109,   110,   143,   327,   303,   111,   112,   347,
     364,   363,   390,   113,   114,   115,   116,   117,    22,    23,
      47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   153,   120,   121,    18,   127,    38,   144,   132,    50,
     147,   224,    31,   133,   328,   318,   366,   205,   164,   230,
     282,   361,    51,    34,    35,    25,   349,   365,   292,   217,
     391,    44,    40,    41,    25,    57,    51,    51,   221,    57,
     242,    46,   222,    48,   199,    49,   165,   122,   140,   233,
     408,   409,   126,    25,   237,    25,   292,   123,    24,   240,
     401,   213,   403,   214,   283,   362,   203,   204,   245,    51,
      27,   400,    25,   402,   299,   228,    36,   120,   199,   234,
     280,   179,   180,   181,   147,   393,   395,    25,    26,    27,
      26,    27,    37,   164,   318,   387,   388,    26,   137,   232,
     293,   298,   294,    25,   236,   251,   216,    26,   213,   239,
     214,   155,   156,   157,   158,   184,   185,   162,   163,   285,
     215,   165,    26,    27,   141,    26,   243,   136,   214,   250,
     137,    55,   253,   254,   255,   256,   257,   258,    26,    27,
     308,   173,   229,    28,    51,   244,   243,   206,   214,    43,
     306,   207,   338,   147,   199,   314,   142,   199,   278,   174,
     175,   176,   177,   178,   312,   302,   149,   367,   313,   120,
     284,   199,   145,   291,   147,   300,   301,   326,   326,   167,
     168,   182,   183,   368,   338,   338,   169,   199,   150,   170,
     307,   171,    50,   216,   151,   172,   186,   187,   188,   189,
     190,   154,   338,   385,   338,   338,   386,   199,   406,   357,
     199,   193,   199,   194,   259,   260,   261,   126,   338,   195,
     140,   191,   192,   244,   126,   266,   267,   268,   269,   270,
     196,   370,   407,   197,   351,   338,   199,   198,   199,   225,
     226,   220,   120,   317,   238,   199,   338,   126,   338,   227,
     323,   262,   263,   325,   338,   338,   219,   339,   231,   326,
     326,   340,   264,   265,   352,   353,   271,   272,   375,   120,
     378,   223,   342,   235,   246,   247,   252,   120,   343,   355,
     356,   311,   147,   279,   350,   281,   296,   309,   304,   339,
     339,   305,   315,   360,   204,   397,   399,   126,   376,   319,
     379,   320,   321,   329,   330,   302,   199,   339,   331,   339,
     339,   232,   310,   236,   239,   382,   383,   344,   374,   346,
     377,   120,   317,   339,   358,   348,   345,   307,   354,   371,
     273,   380,   359,   372,   381,   404,   274,   405,   389,   392,
     339,   394,   276,   275,   350,   396,   398,   277,    56,   135,
     297,   339,   146,   339,   369,   374,   295,   377,   241,   339,
     339,   384,   286,   396,   398,   146,   146,   146,   146,   160,
     161,   146,   146,   341,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      58,   201,    59,    60,    61,   202,    62,    63,    64,    65,
      66,    67,     0,    42,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   146,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,     0,     0,    85,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,     0,     0,     0,
       0,     0,     0,     0,     0,   146,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,   146,     0,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    58,   146,    59,    60,    61,     0,
      62,    63,    64,    65,    66,    67,     0,    42,   200,    69,
      70,    71,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,    26,   243,   287,   214,     0,     0,
       0,    78,     0,     0,    79,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,     0,
       0,    85,     0,     0,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   146,    69,    70,   119,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
     134,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,     0,     0,    85,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    25,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     0,   124,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,    26,   213,   287,   214,
       1,     2,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,   125,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    69,    70,   119,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,    42,     0,     0,     0,   322,     0,
       0,     0,     0,    78,     0,     0,    79,     0,    43,    80,
      81,     0,     0,     0,     0,     0,     0,    82,    83,    84,
      58,     0,    59,    60,    61,     0,    62,    63,    64,    65,
      66,    67,     0,    42,     0,    69,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,     0,     0,    58,    85,   332,   333,
     334,     0,    62,   335,   336,    65,    66,    67,     0,    42,
       0,    69,    70,   337,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    79,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,     0,     0,    85,   118,   316,    69,    70,   119,    72,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,     0,   206,     0,     0,     0,
     207,   118,   373,    69,    70,   119,    72,    73,    74,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,   206,     0,     0,   118,   207,    69,    70,
     119,    72,    73,    74,    75,    76,    77,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      78,     0,     0,    79,     0,     0,    80,    81,     0,     0,
       0,     0,     0,     0,    82,    83,    84,     0,   206,     0,
       0,     0,   207,    69,    70,   119,    72,    73,    74,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,     0,     0,   152,    69,    70,   119,    72,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,     0,     0,     0,    85,    69,
      70,   119,    72,    73,    74,    75,    76,    77,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    79,     0,     0,    80,    81,     0,
       0,     0,     0,     0,     0,    82,    83,    84,     0,     0,
     131,    69,    70,   119,    72,    73,    74,    75,    76,    77,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    78,     0,     0,    79,     0,     0,    80,
      81,     0,     0,     0,     0,     0,     0,    82,    83,    84,
       0,     0,   290,    69,    70,   119,    72,    73,    74,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,    79,     0,
       0,    80,    81,     0,     0,     0,     0,     0,     0,    82,
      83,    84,     0,   118,   324,    69,    70,   119,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,   310,     0,    69,    70,   119,    72,
      73,    74,    75,    76,    77,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    78,     0,
       0,    79,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,    82,    83,    84,    69,    70,   119,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,   248,    69,    70,   119,    72,    73,
      74,    75,    76,    77,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
      79,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    69,    70,   119,    72,    73,    74,
      75,    76,    77,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,    79,
       0,     0,    80,    81,     0,     0,     0,     0,     0,     0,
      82,    83,   159,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42
};

static const yytype_int16 yycheck[] =
{
       0,    67,    43,    43,     0,    48,    26,    61,    49,    33,
      63,   137,    18,    51,   301,   283,   349,   112,    84,   142,
      33,    33,    37,    19,    20,    36,   328,   348,   216,   126,
     386,    31,    76,    77,    36,    41,    51,    52,    73,    45,
      73,    31,    77,    72,    77,    74,    84,    47,    54,   144,
     406,   407,    48,    36,   149,    36,   244,    47,    36,   154,
     393,    72,   395,    74,    77,    77,   111,   112,   165,    84,
      72,   392,    36,   394,    73,   141,     0,   118,    77,   145,
     206,    43,    44,    45,   137,   387,   388,    36,    71,    72,
      71,    72,    32,   159,   362,   382,   383,    71,    79,   144,
      72,   227,    74,    36,   149,   171,   126,    71,    72,   154,
      74,    76,    77,    78,    79,    60,    61,    82,    83,    46,
     126,   159,    71,    72,    72,    71,    72,    76,    74,   170,
      79,    73,   173,   174,   175,   176,   177,   178,    71,    72,
     235,    46,   142,    76,   159,   165,    72,    74,    74,    46,
      73,    78,   306,   206,    77,    75,    72,    77,   199,    64,
      65,    66,    67,    68,    73,   231,    79,    73,    77,   210,
     210,    77,    72,   214,   227,   229,   230,   300,   301,    62,
      63,    41,    42,    73,   338,   339,    69,    77,    76,    72,
     235,    74,   216,   213,    76,    78,    49,    50,    51,    52,
      53,    79,   356,    73,   358,   359,    73,    77,    73,   335,
      77,    70,    77,    58,   179,   180,   181,   213,   372,    57,
     226,    47,    48,   243,   220,   186,   187,   188,   189,   190,
      54,   354,    73,    55,   329,   389,    77,    76,    77,    76,
      77,    77,   283,   283,    76,    77,   400,   243,   402,    79,
     293,   182,   183,   294,   408,   409,    73,   306,    72,   382,
     383,   306,   184,   185,   330,   331,   191,   192,   363,   310,
     365,    75,   313,    79,    73,    36,    36,   318,   318,   333,
     334,   246,   335,    20,   329,    36,    36,    73,    24,   338,
     339,    24,    75,   338,   339,   390,   391,   293,   364,    73,
     366,    73,    75,    73,    72,   371,    77,   356,    72,   358,
     359,   356,    32,   358,   359,   369,   370,    73,   363,    73,
     365,   362,   362,   372,    79,    73,    75,   372,    72,    72,
     193,    76,    79,    79,    76,   401,   194,   403,    73,    73,
     389,    73,   196,   195,   389,   390,   391,   197,    41,    52,
     226,   400,    63,   402,   354,   400,   220,   402,   159,   408,
     409,   371,   211,   408,   409,    76,    77,    78,    79,    80,
      81,    82,    83,   310,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,   108,    21,    22,    23,   111,    25,    26,    27,    28,
      29,    30,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    -1,    -1,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   206,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    -1,    -1,    -1,    -1,   227,    -1,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,   246,    21,    22,    23,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    71,    72,    73,    74,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      -1,    76,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   335,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    -1,    76,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      -1,    36,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    36,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    -1,    -1,    71,    72,    73,    74,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    73,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    46,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      19,    -1,    21,    22,    23,    -1,    25,    26,    27,    28,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    -1,    -1,    19,    76,    21,    22,
      23,    -1,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    -1,    76,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    74,    -1,    -1,    -1,
      78,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    74,    -1,    -1,    32,    78,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    -1,    74,    -1,
      -1,    -1,    78,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    -1,    -1,    76,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    -1,    -1,    -1,    76,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    59,    -1,    -1,    62,    63,    -1,
      -1,    -1,    -1,    -1,    -1,    70,    71,    72,    -1,    -1,
      75,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    -1,    62,
      63,    -1,    -1,    -1,    -1,    -1,    -1,    70,    71,    72,
      -1,    -1,    75,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    -1,
      -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      71,    72,    -1,    32,    75,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    32,    -1,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,
      -1,    -1,    70,    71,    72,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,
      59,    -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    59,
      -1,    -1,    62,    63,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    71,    72,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,   102,   103,   106,
     107,   108,   148,   149,    36,    36,    71,    72,    76,   104,
     105,   114,   115,   116,   103,   103,     0,    32,   116,   114,
      76,    77,    32,    46,   102,   103,   130,   150,    72,    74,
     115,   107,   109,   110,   111,    73,   105,   114,    19,    21,
      22,    23,    25,    26,    27,    28,    29,    30,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    56,    59,
      62,    63,    70,    71,    72,    76,    81,    82,    83,    84,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   102,   129,   130,   131,   132,
     133,   137,   138,   143,   144,   145,   146,   147,    32,    36,
      99,   124,   102,   130,    36,    73,   103,   117,   118,   119,
     120,    75,    99,   111,    33,   110,    76,    79,   112,   113,
     114,    72,    72,   134,   134,    72,    86,    98,   101,    79,
      76,    76,    76,   100,    79,    87,    87,    87,    87,    72,
      86,    86,    87,    87,   100,   111,   121,    62,    63,    69,
      72,    74,    78,    46,    64,    65,    66,    67,    68,    43,
      44,    45,    41,    42,    60,    61,    49,    50,    51,    52,
      53,    47,    48,    70,    58,    57,    54,    55,    76,    77,
      33,   132,   129,   143,   143,   144,    74,    78,   124,   125,
     126,   127,   128,    72,    74,   114,   116,   122,   123,    73,
      77,    73,    77,    75,   101,    76,    77,    79,   100,   102,
     133,    72,   143,   144,   100,    79,   143,   144,    76,   143,
     144,   121,    73,    72,   116,   122,    73,    36,    73,    85,
      99,   100,    36,    99,    99,    99,    99,    99,    99,    87,
      87,    87,    88,    88,    89,    89,    90,    90,    90,    90,
      90,    91,    91,    92,    93,    94,    95,    96,    99,    20,
     101,    36,    33,    77,   124,    46,   128,    73,   117,   122,
      75,    99,   123,    72,    74,   119,    36,   113,   101,    73,
     134,   134,   100,   136,    24,    24,    73,   143,   144,    73,
      32,    87,    73,    77,    75,    75,    33,   124,   126,    73,
      73,    75,    73,   117,    75,    99,   133,   135,   135,    73,
      72,    72,    21,    22,    23,    26,    27,    36,   137,   138,
     143,   125,    99,   124,    73,    75,    73,   139,    73,   139,
     143,   144,   100,   100,    72,   134,   134,   101,    79,    79,
     143,    33,    77,   141,   140,   141,   140,    73,    73,   102,
     133,    72,    79,    33,   143,   144,   100,   143,   144,   100,
      76,    76,   134,   134,   136,    73,    73,   135,   135,    73,
     142,   142,    73,   139,    73,   139,   143,   144,   143,   144,
     141,   140,   141,   140,   100,   100,    73,    73,   142,   142
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    80,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    83,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    85,    85,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    88,    88,    89,
      89,    89,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    92,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   102,   102,   103,   103,   103,
     103,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   111,   111,   112,
     112,   113,   113,   113,   114,   114,   115,   115,   115,   115,
     115,   115,   115,   116,   116,   117,   118,   118,   119,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     125,   125,   125,   125,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   143,
     143,   143,   143,   143,   143,   143,   143,   144,   144,   144,
     144,   144,   144,   145,   145,   145,   145,   145,   145,   146,
     146,   146,   146,   146,   146,   147,   147,   147,   147,   148,
     148,   149,   149,   150,   150
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     1,     2,     3,     2,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     2,     1,     2,     2,     3,     2,     1,     1,
       3,     2,     3,     1,     2,     1,     1,     3,     3,     4,
       4,     3,     4,     2,     1,     1,     1,     3,     2,     2,
       1,     1,     3,     2,     1,     2,     1,     1,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     3,     4,     1,
       2,     1,     4,     3,     2,     1,     2,     3,     2,     1,
       1,     2,     3,     1,     2,     1,     1,     1,     2,     0,
       1,     1,     4,     3,     0,     0,     0,     0,     1,     1,
       1,     1,     3,     4,     3,     5,     2,     3,     4,     3,
       1,     2,     2,     6,     8,     8,    11,     8,    11,     6,
       8,     8,    11,     8,    11,     2,     2,     2,     3,     1,
       1,     4,     3,     1,     2
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
        YY_LAC_DISCARD ("YYBACKUP");                              \
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* primary_expression: TOK_IDENTIFIER  */
#line 167 "parser/kernalex.y"
                     { (yyval.temp) = (yyvsp[0].temp); }
#line 2228 "parser/kernalex.tab.c"
    break;

  case 3: /* primary_expression: constant  */
#line 168 "parser/kernalex.y"
               { (yyval.temp) = (yyvsp[0].temp); }
#line 2234 "parser/kernalex.tab.c"
    break;

  case 4: /* primary_expression: string  */
#line 169 "parser/kernalex.y"
             { (yyval.temp) = (yyvsp[0].temp); }
#line 2240 "parser/kernalex.tab.c"
    break;

  case 5: /* primary_expression: TOK_TRUE  */
#line 170 "parser/kernalex.y"
               { (yyval.temp) = (char *)malloc(5); strcpy((yyval.temp), "true"); }
#line 2246 "parser/kernalex.tab.c"
    break;

  case 6: /* primary_expression: TOK_FALSE  */
#line 171 "parser/kernalex.y"
                { (yyval.temp) = (char *)malloc(6); strcpy((yyval.temp), "false"); }
#line 2252 "parser/kernalex.tab.c"
    break;

  case 7: /* primary_expression: TOK_LPAREN expression TOK_RPAREN  */
#line 172 "parser/kernalex.y"
                                       { (yyval.temp) = (yyvsp[-1].temp); }
#line 2258 "parser/kernalex.tab.c"
    break;

  case 8: /* constant: TOK_INTEGER  */
#line 177 "parser/kernalex.y"
    {
        int_consts++;
        (yyval.temp) = (yyvsp[0].temp);
    }
#line 2267 "parser/kernalex.tab.c"
    break;

  case 9: /* constant: TOK_FLOAT_LIT  */
#line 181 "parser/kernalex.y"
                    { (yyval.temp) = (yyvsp[0].temp); }
#line 2273 "parser/kernalex.tab.c"
    break;

  case 10: /* constant: TOK_CHAR_LIT  */
#line 182 "parser/kernalex.y"
                    { (yyval.temp) = (yyvsp[0].temp); }
#line 2279 "parser/kernalex.tab.c"
    break;

  case 11: /* string: TOK_STRING_LIT  */
#line 186 "parser/kernalex.y"
                     { (yyval.temp) = (yyvsp[0].temp); }
#line 2285 "parser/kernalex.tab.c"
    break;

  case 12: /* postfix_expression: primary_expression  */
#line 191 "parser/kernalex.y"
                         { (yyval.temp) = (yyvsp[0].temp); }
#line 2291 "parser/kernalex.tab.c"
    break;

  case 13: /* postfix_expression: postfix_expression TOK_LBRACKET expression TOK_RBRACKET  */
#line 192 "parser/kernalex.y"
                                                              { (yyval.temp) = (yyvsp[-3].temp); }
#line 2297 "parser/kernalex.tab.c"
    break;

  case 14: /* postfix_expression: postfix_expression TOK_LPAREN TOK_RPAREN  */
#line 193 "parser/kernalex.y"
                                               { (yyval.temp) = (yyvsp[-2].temp); }
#line 2303 "parser/kernalex.tab.c"
    break;

  case 15: /* postfix_expression: postfix_expression TOK_LPAREN argument_expression_list TOK_RPAREN  */
#line 194 "parser/kernalex.y"
                                                                        { (yyval.temp) = (yyvsp[-3].temp); }
#line 2309 "parser/kernalex.tab.c"
    break;

  case 16: /* postfix_expression: postfix_expression TOK_DOT TOK_IDENTIFIER  */
#line 195 "parser/kernalex.y"
                                                { (yyval.temp) = (yyvsp[-2].temp); }
#line 2315 "parser/kernalex.tab.c"
    break;

  case 17: /* postfix_expression: postfix_expression TOK_ARROW TOK_IDENTIFIER  */
#line 196 "parser/kernalex.y"
                                                  { (yyval.temp) = (yyvsp[-2].temp); }
#line 2321 "parser/kernalex.tab.c"
    break;

  case 18: /* postfix_expression: postfix_expression TOK_INC  */
#line 197 "parser/kernalex.y"
                                     { codegen_unsupported("postfix increment (x++)"); (yyval.temp) = (yyvsp[-1].temp); }
#line 2327 "parser/kernalex.tab.c"
    break;

  case 19: /* postfix_expression: postfix_expression TOK_DEC  */
#line 198 "parser/kernalex.y"
                                     { codegen_unsupported("postfix decrement (x--)"); (yyval.temp) = (yyvsp[-1].temp); }
#line 2333 "parser/kernalex.tab.c"
    break;

  case 20: /* postfix_expression: TOK_LPAREN type_name TOK_RPAREN TOK_BEGIN initializer_list TOK_END  */
#line 199 "parser/kernalex.y"
                                                                         { (yyval.temp) = (char *)malloc(20); strcpy((yyval.temp), "init_result"); }
#line 2339 "parser/kernalex.tab.c"
    break;

  case 21: /* postfix_expression: TOK_LPAREN type_name TOK_RPAREN TOK_BEGIN initializer_list TOK_COMMA TOK_END  */
#line 200 "parser/kernalex.y"
                                                                                   { (yyval.temp) = (char *)malloc(20); strcpy((yyval.temp), "init_result"); }
#line 2345 "parser/kernalex.tab.c"
    break;

  case 22: /* argument_expression_list: assignment_expression  */
#line 204 "parser/kernalex.y"
                            { (yyval.temp) = (yyvsp[0].temp); }
#line 2351 "parser/kernalex.tab.c"
    break;

  case 23: /* argument_expression_list: argument_expression_list TOK_COMMA assignment_expression  */
#line 205 "parser/kernalex.y"
                                                               { (yyval.temp) = (yyvsp[0].temp); }
#line 2357 "parser/kernalex.tab.c"
    break;

  case 24: /* unary_expression: postfix_expression  */
#line 209 "parser/kernalex.y"
                         { (yyval.temp) = (yyvsp[0].temp); }
#line 2363 "parser/kernalex.tab.c"
    break;

  case 25: /* unary_expression: TOK_INC unary_expression  */
#line 210 "parser/kernalex.y"
                                   { codegen_unsupported("prefix increment (++x)"); (yyval.temp) = (yyvsp[0].temp); }
#line 2369 "parser/kernalex.tab.c"
    break;

  case 26: /* unary_expression: TOK_DEC unary_expression  */
#line 211 "parser/kernalex.y"
                                   { codegen_unsupported("prefix decrement (--x)"); (yyval.temp) = (yyvsp[0].temp); }
#line 2375 "parser/kernalex.tab.c"
    break;

  case 27: /* unary_expression: TOK_MINUS cast_expression  */
#line 213 "parser/kernalex.y"
    {
        char *temp = new_temp();
        emit_quad("minus", (yyvsp[0].temp), NULL, temp);
        (yyval.temp) = (char *)malloc(strlen(temp) + 1);
        strcpy((yyval.temp), temp);
    }
#line 2386 "parser/kernalex.tab.c"
    break;

  case 28: /* unary_expression: TOK_PLUS cast_expression  */
#line 219 "parser/kernalex.y"
                               { (yyval.temp) = (yyvsp[0].temp); }
#line 2392 "parser/kernalex.tab.c"
    break;

  case 29: /* unary_expression: TOK_NOT cast_expression  */
#line 220 "parser/kernalex.y"
                              { (yyval.temp) = (yyvsp[0].temp); }
#line 2398 "parser/kernalex.tab.c"
    break;

  case 30: /* unary_expression: TOK_BITNOT cast_expression  */
#line 221 "parser/kernalex.y"
                                 { (yyval.temp) = (yyvsp[0].temp); }
#line 2404 "parser/kernalex.tab.c"
    break;

  case 31: /* unary_expression: TOK_AMP cast_expression  */
#line 222 "parser/kernalex.y"
                              { (yyval.temp) = (yyvsp[0].temp); }
#line 2410 "parser/kernalex.tab.c"
    break;

  case 32: /* unary_expression: TOK_STAR cast_expression  */
#line 223 "parser/kernalex.y"
                               { (yyval.temp) = (yyvsp[0].temp); }
#line 2416 "parser/kernalex.tab.c"
    break;

  case 33: /* cast_expression: unary_expression  */
#line 227 "parser/kernalex.y"
                       { (yyval.temp) = (yyvsp[0].temp); }
#line 2422 "parser/kernalex.tab.c"
    break;

  case 34: /* cast_expression: TOK_LPAREN type_name TOK_RPAREN cast_expression  */
#line 228 "parser/kernalex.y"
                                                      { (yyval.temp) = (yyvsp[0].temp); }
#line 2428 "parser/kernalex.tab.c"
    break;

  case 35: /* multiplicative_expression: cast_expression  */
#line 232 "parser/kernalex.y"
                      { (yyval.temp) = (yyvsp[0].temp); }
#line 2434 "parser/kernalex.tab.c"
    break;

  case 36: /* multiplicative_expression: multiplicative_expression TOK_MULT cast_expression  */
#line 234 "parser/kernalex.y"
    {
        char *temp = new_temp();
        emit_quad("*", (yyvsp[-2].temp), (yyvsp[0].temp), temp);
        (yyval.temp) = (char *)malloc(strlen(temp) + 1);
        strcpy((yyval.temp), temp);
    }
#line 2445 "parser/kernalex.tab.c"
    break;

  case 37: /* multiplicative_expression: multiplicative_expression TOK_DIV cast_expression  */
#line 241 "parser/kernalex.y"
    {
        char *temp = new_temp();
        emit_quad("/", (yyvsp[-2].temp), (yyvsp[0].temp), temp);
        (yyval.temp) = (char *)malloc(strlen(temp) + 1);
        strcpy((yyval.temp), temp);
    }
#line 2456 "parser/kernalex.tab.c"
    break;

  case 38: /* multiplicative_expression: multiplicative_expression TOK_MOD cast_expression  */
#line 248 "parser/kernalex.y"
    {
        char *temp = new_temp();
        emit_quad("%", (yyvsp[-2].temp), (yyvsp[0].temp), temp);
        (yyval.temp) = (char *)malloc(strlen(temp) + 1);
        strcpy((yyval.temp), temp);
    }
#line 2467 "parser/kernalex.tab.c"
    break;

  case 39: /* additive_expression: multiplicative_expression  */
#line 257 "parser/kernalex.y"
                                { (yyval.temp) = (yyvsp[0].temp); }
#line 2473 "parser/kernalex.tab.c"
    break;

  case 40: /* additive_expression: additive_expression TOK_PLUS multiplicative_expression  */
#line 259 "parser/kernalex.y"
    {
        char *temp = new_temp();
        emit_quad("+", (yyvsp[-2].temp), (yyvsp[0].temp), temp);
        (yyval.temp) = (char *)malloc(strlen(temp) + 1);
        strcpy((yyval.temp), temp);
    }
#line 2484 "parser/kernalex.tab.c"
    break;

  case 41: /* additive_expression: additive_expression TOK_MINUS multiplicative_expression  */
#line 266 "parser/kernalex.y"
    {
        char *temp = new_temp();
        emit_quad("-", (yyvsp[-2].temp), (yyvsp[0].temp), temp);
        (yyval.temp) = (char *)malloc(strlen(temp) + 1);
        strcpy((yyval.temp), temp);
    }
#line 2495 "parser/kernalex.tab.c"
    break;

  case 42: /* shift_expression: additive_expression  */
#line 275 "parser/kernalex.y"
                              { (yyval.temp) = (yyvsp[0].temp); }
#line 2501 "parser/kernalex.tab.c"
    break;

  case 43: /* shift_expression: shift_expression TOK_LSHIFT additive_expression  */
#line 276 "parser/kernalex.y"
                                                          { (yyval.temp) = (yyvsp[0].temp); }
#line 2507 "parser/kernalex.tab.c"
    break;

  case 44: /* shift_expression: shift_expression TOK_RSHIFT additive_expression  */
#line 277 "parser/kernalex.y"
                                                          { (yyval.temp) = (yyvsp[0].temp); }
#line 2513 "parser/kernalex.tab.c"
    break;

  case 45: /* relational_expression: shift_expression  */
#line 281 "parser/kernalex.y"
                       { (yyval.temp) = (yyvsp[0].temp); }
#line 2519 "parser/kernalex.tab.c"
    break;

  case 46: /* relational_expression: relational_expression TOK_LT shift_expression  */
#line 282 "parser/kernalex.y"
                                                        { char *t=new_temp(); emit_quad("<", (yyvsp[-2].temp), (yyvsp[0].temp), t); (yyval.temp) = strdup(t); }
#line 2525 "parser/kernalex.tab.c"
    break;

  case 47: /* relational_expression: relational_expression TOK_GT shift_expression  */
#line 283 "parser/kernalex.y"
                                                        { char *t=new_temp(); emit_quad(">", (yyvsp[-2].temp), (yyvsp[0].temp), t); (yyval.temp) = strdup(t); }
#line 2531 "parser/kernalex.tab.c"
    break;

  case 48: /* relational_expression: relational_expression TOK_LE shift_expression  */
#line 284 "parser/kernalex.y"
                                                        { char *t=new_temp(); emit_quad("<=", (yyvsp[-2].temp), (yyvsp[0].temp), t); (yyval.temp) = strdup(t); }
#line 2537 "parser/kernalex.tab.c"
    break;

  case 49: /* relational_expression: relational_expression TOK_GE shift_expression  */
#line 285 "parser/kernalex.y"
                                                        { char *t=new_temp(); emit_quad(">=", (yyvsp[-2].temp), (yyvsp[0].temp), t); (yyval.temp) = strdup(t); }
#line 2543 "parser/kernalex.tab.c"
    break;

  case 50: /* relational_expression: relational_expression TOK_SPACESHIP shift_expression  */
#line 286 "parser/kernalex.y"
                                                               { (yyval.temp) = (yyvsp[0].temp); }
#line 2549 "parser/kernalex.tab.c"
    break;

  case 51: /* equality_expression: relational_expression  */
#line 290 "parser/kernalex.y"
                                { (yyval.temp) = (yyvsp[0].temp); }
#line 2555 "parser/kernalex.tab.c"
    break;

  case 52: /* equality_expression: equality_expression TOK_EQ relational_expression  */
#line 291 "parser/kernalex.y"
                                                           { char *t=new_temp(); emit_quad("==", (yyvsp[-2].temp), (yyvsp[0].temp), t); (yyval.temp) = strdup(t); }
#line 2561 "parser/kernalex.tab.c"
    break;

  case 53: /* equality_expression: equality_expression TOK_NE relational_expression  */
#line 292 "parser/kernalex.y"
                                                           { char *t=new_temp(); emit_quad("!=", (yyvsp[-2].temp), (yyvsp[0].temp), t); (yyval.temp) = strdup(t); }
#line 2567 "parser/kernalex.tab.c"
    break;

  case 54: /* and_expression: equality_expression  */
#line 296 "parser/kernalex.y"
                              { (yyval.temp) = (yyvsp[0].temp); }
#line 2573 "parser/kernalex.tab.c"
    break;

  case 55: /* and_expression: and_expression TOK_AMP equality_expression  */
#line 297 "parser/kernalex.y"
                                                     { (yyval.temp) = (yyvsp[0].temp); }
#line 2579 "parser/kernalex.tab.c"
    break;

  case 56: /* exclusive_or_expression: and_expression  */
#line 301 "parser/kernalex.y"
                     { (yyval.temp) = (yyvsp[0].temp); }
#line 2585 "parser/kernalex.tab.c"
    break;

  case 57: /* exclusive_or_expression: exclusive_or_expression TOK_XOR and_expression  */
#line 302 "parser/kernalex.y"
                                                         { (yyval.temp) = (yyvsp[0].temp); }
#line 2591 "parser/kernalex.tab.c"
    break;

  case 58: /* inclusive_or_expression: exclusive_or_expression  */
#line 306 "parser/kernalex.y"
                                  { (yyval.temp) = (yyvsp[0].temp); }
#line 2597 "parser/kernalex.tab.c"
    break;

  case 59: /* inclusive_or_expression: inclusive_or_expression TOK_BITOR exclusive_or_expression  */
#line 307 "parser/kernalex.y"
                                                                    { (yyval.temp) = (yyvsp[0].temp); }
#line 2603 "parser/kernalex.tab.c"
    break;

  case 60: /* logical_and_expression: inclusive_or_expression  */
#line 311 "parser/kernalex.y"
                                  { (yyval.temp) = (yyvsp[0].temp); }
#line 2609 "parser/kernalex.tab.c"
    break;

  case 61: /* logical_and_expression: logical_and_expression TOK_AND inclusive_or_expression  */
#line 312 "parser/kernalex.y"
                                                                 { (yyval.temp) = (yyvsp[0].temp); }
#line 2615 "parser/kernalex.tab.c"
    break;

  case 62: /* logical_or_expression: logical_and_expression  */
#line 316 "parser/kernalex.y"
                                 { (yyval.temp) = (yyvsp[0].temp); }
#line 2621 "parser/kernalex.tab.c"
    break;

  case 63: /* logical_or_expression: logical_or_expression TOK_OR logical_and_expression  */
#line 317 "parser/kernalex.y"
                                                              { (yyval.temp) = (yyvsp[0].temp); }
#line 2627 "parser/kernalex.tab.c"
    break;

  case 64: /* conditional_expression: logical_or_expression  */
#line 321 "parser/kernalex.y"
                                { (yyval.temp) = (yyvsp[0].temp); }
#line 2633 "parser/kernalex.tab.c"
    break;

  case 65: /* assignment_expression: conditional_expression  */
#line 325 "parser/kernalex.y"
                             { (yyval.temp) = (yyvsp[0].temp); }
#line 2639 "parser/kernalex.tab.c"
    break;

  case 66: /* assignment_expression: unary_expression TOK_ASSIGN assignment_expression  */
#line 327 "parser/kernalex.y"
    {
        emit_quad("=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
        (yyval.temp) = (char *)malloc(strlen((yyvsp[-2].temp)) + 1);
        strcpy((yyval.temp), (yyvsp[-2].temp));
    }
#line 2649 "parser/kernalex.tab.c"
    break;

  case 67: /* assignment_expression: unary_expression TOK_PLUSEQ assignment_expression  */
#line 333 "parser/kernalex.y"
    {
        emit_quad("+=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
        (yyval.temp) = (char *)malloc(strlen((yyvsp[-2].temp)) + 1);
        strcpy((yyval.temp), (yyvsp[-2].temp));
    }
#line 2659 "parser/kernalex.tab.c"
    break;

  case 68: /* assignment_expression: unary_expression TOK_MINUSEQ assignment_expression  */
#line 339 "parser/kernalex.y"
    {
        emit_quad("-=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
        (yyval.temp) = (char *)malloc(strlen((yyvsp[-2].temp)) + 1);
        strcpy((yyval.temp), (yyvsp[-2].temp));
    }
#line 2669 "parser/kernalex.tab.c"
    break;

  case 69: /* assignment_expression: unary_expression TOK_MULTEQ assignment_expression  */
#line 345 "parser/kernalex.y"
    {
        emit_quad("*=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
        (yyval.temp) = (char *)malloc(strlen((yyvsp[-2].temp)) + 1);
        strcpy((yyval.temp), (yyvsp[-2].temp));
    }
#line 2679 "parser/kernalex.tab.c"
    break;

  case 70: /* assignment_expression: unary_expression TOK_DIVEQ assignment_expression  */
#line 351 "parser/kernalex.y"
    {
        emit_quad("/=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
        (yyval.temp) = (char *)malloc(strlen((yyvsp[-2].temp)) + 1);
        strcpy((yyval.temp), (yyvsp[-2].temp));
    }
#line 2689 "parser/kernalex.tab.c"
    break;

  case 71: /* assignment_expression: unary_expression TOK_MODEQ assignment_expression  */
#line 357 "parser/kernalex.y"
    {
        emit_quad("%=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
        (yyval.temp) = (char *)malloc(strlen((yyvsp[-2].temp)) + 1);
        strcpy((yyval.temp), (yyvsp[-2].temp));
    }
#line 2699 "parser/kernalex.tab.c"
    break;

  case 72: /* expression: assignment_expression  */
#line 365 "parser/kernalex.y"
                            { (yyval.temp) = (yyvsp[0].temp); }
#line 2705 "parser/kernalex.tab.c"
    break;

  case 73: /* expression: expression TOK_COMMA assignment_expression  */
#line 366 "parser/kernalex.y"
                                                 { (yyval.temp) = (yyvsp[0].temp); }
#line 2711 "parser/kernalex.tab.c"
    break;

  case 74: /* constant_expression: conditional_expression  */
#line 370 "parser/kernalex.y"
                             { (yyval.temp) = (yyvsp[0].temp); }
#line 2717 "parser/kernalex.tab.c"
    break;

  case 83: /* init_declarator: declarator TOK_ASSIGN initializer  */
#line 392 "parser/kernalex.y"
        {
	    if ((yyvsp[-2].temp) && (yyvsp[0].temp)) {
	        emit_quad("=", (yyvsp[0].temp), NULL, (yyvsp[-2].temp));
	    }
	}
#line 2727 "parser/kernalex.tab.c"
    break;

  case 114: /* declarator: pointer direct_declarator  */
#line 455 "parser/kernalex.y"
                                    { (yyval.temp) = (yyvsp[0].temp); }
#line 2733 "parser/kernalex.tab.c"
    break;

  case 115: /* declarator: direct_declarator  */
#line 456 "parser/kernalex.y"
                                    { (yyval.temp) = (yyvsp[0].temp); }
#line 2739 "parser/kernalex.tab.c"
    break;

  case 116: /* direct_declarator: TOK_IDENTIFIER  */
#line 460 "parser/kernalex.y"
                                                                            { (yyval.temp) = (yyvsp[0].temp); }
#line 2745 "parser/kernalex.tab.c"
    break;

  case 117: /* direct_declarator: TOK_LPAREN declarator TOK_RPAREN  */
#line 461 "parser/kernalex.y"
                                                                            { (yyval.temp) = (yyvsp[-1].temp); }
#line 2751 "parser/kernalex.tab.c"
    break;

  case 118: /* direct_declarator: direct_declarator TOK_LBRACKET TOK_RBRACKET  */
#line 462 "parser/kernalex.y"
                                                                            { (yyval.temp) = (yyvsp[-2].temp); }
#line 2757 "parser/kernalex.tab.c"
    break;

  case 119: /* direct_declarator: direct_declarator TOK_LBRACKET assignment_expression TOK_RBRACKET  */
#line 463 "parser/kernalex.y"
                                                                            { (yyval.temp) = (yyvsp[-3].temp); }
#line 2763 "parser/kernalex.tab.c"
    break;

  case 120: /* direct_declarator: direct_declarator TOK_LPAREN parameter_type_list TOK_RPAREN  */
#line 464 "parser/kernalex.y"
                                                                            { (yyval.temp) = (yyvsp[-3].temp); }
#line 2769 "parser/kernalex.tab.c"
    break;

  case 121: /* direct_declarator: direct_declarator TOK_LPAREN TOK_RPAREN  */
#line 465 "parser/kernalex.y"
                                                                            { (yyval.temp) = (yyvsp[-2].temp); }
#line 2775 "parser/kernalex.tab.c"
    break;

  case 122: /* direct_declarator: direct_declarator TOK_LPAREN identifier_list TOK_RPAREN  */
#line 466 "parser/kernalex.y"
                                                                           { (yyval.temp) = (yyvsp[-3].temp); }
#line 2781 "parser/kernalex.tab.c"
    break;

  case 123: /* pointer: TOK_STAR pointer  */
#line 470 "parser/kernalex.y"
                           {pointer_decls++;}
#line 2787 "parser/kernalex.tab.c"
    break;

  case 124: /* pointer: TOK_STAR  */
#line 471 "parser/kernalex.y"
                   {pointer_decls++;}
#line 2793 "parser/kernalex.tab.c"
    break;

  case 147: /* initializer: TOK_BEGIN initializer_list TOK_END  */
#line 520 "parser/kernalex.y"
                                         { (yyval.temp) = (char *)malloc(20); strcpy((yyval.temp), "init"); }
#line 2799 "parser/kernalex.tab.c"
    break;

  case 148: /* initializer: TOK_BEGIN initializer_list TOK_COMMA TOK_END  */
#line 521 "parser/kernalex.y"
                                                   { (yyval.temp) = (char *)malloc(20); strcpy((yyval.temp), "init"); }
#line 2805 "parser/kernalex.tab.c"
    break;

  case 149: /* initializer: assignment_expression  */
#line 523 "parser/kernalex.y"
    {
        (yyval.temp) = (yyvsp[0].temp);
    }
#line 2813 "parser/kernalex.tab.c"
    break;

  case 167: /* expression_statement: TOK_SEMICOLON  */
#line 570 "parser/kernalex.y"
                        { (yyval.temp) = NULL; }
#line 2819 "parser/kernalex.tab.c"
    break;

  case 168: /* expression_statement: expression TOK_SEMICOLON  */
#line 571 "parser/kernalex.y"
                                   { (yyval.temp) = (yyvsp[-1].temp); }
#line 2825 "parser/kernalex.tab.c"
    break;

  case 169: /* L_mark: %empty  */
#line 575 "parser/kernalex.y"
                    { (yyval.temp) = strdup(new_label()); emit_quad("label", NULL, NULL, (yyval.temp)); }
#line 2831 "parser/kernalex.tab.c"
    break;

  case 170: /* M_mark_stmt: expression_statement  */
#line 576 "parser/kernalex.y"
                                  { (yyval.temp) = strdup(new_label()); emit_quad("ifFalse", (yyvsp[0].temp), NULL, (yyval.temp)); }
#line 2837 "parser/kernalex.tab.c"
    break;

  case 171: /* M_mark_expr: expression  */
#line 577 "parser/kernalex.y"
                        { (yyval.temp) = strdup(new_label()); emit_quad("ifFalse", (yyvsp[0].temp), NULL, (yyval.temp)); }
#line 2843 "parser/kernalex.tab.c"
    break;

  case 172: /* if_head: TOK_IF TOK_LPAREN expression TOK_RPAREN  */
#line 578 "parser/kernalex.y"
                                                 { (yyval.temp) = strdup(new_label()); emit_quad("ifFalse", (yyvsp[-1].temp), NULL, (yyval.temp)); }
#line 2849 "parser/kernalex.tab.c"
    break;

  case 173: /* if_else_head: if_head matched_statement TOK_ELSE  */
#line 579 "parser/kernalex.y"
                                                 { (yyval.temp) = strdup(new_label()); emit_quad("goto", NULL, NULL, (yyval.temp)); emit_quad("label", NULL, NULL, (yyvsp[-2].temp)); }
#line 2855 "parser/kernalex.tab.c"
    break;

  case 174: /* M_for_body: %empty  */
#line 581 "parser/kernalex.y"
                        { (yyval.temp) = strdup(new_label()); emit_quad("goto", NULL, NULL, (yyval.temp)); }
#line 2861 "parser/kernalex.tab.c"
    break;

  case 175: /* M_for_update: %empty  */
#line 582 "parser/kernalex.y"
                          { (yyval.temp) = strdup(new_label()); emit_quad("label", NULL, NULL, (yyval.temp)); }
#line 2867 "parser/kernalex.tab.c"
    break;

  case 176: /* M_for_post_empty: %empty  */
#line 583 "parser/kernalex.y"
                              { emit_quad("goto", NULL, NULL, (yyvsp[(-2) - (0)].temp)); emit_quad("label", NULL, NULL, (yyvsp[(-1) - (0)].temp)); }
#line 2873 "parser/kernalex.tab.c"
    break;

  case 177: /* M_for_post_expr: %empty  */
#line 584 "parser/kernalex.y"
                             { emit_quad("goto", NULL, NULL, (yyvsp[(-5) - (0)].temp)); emit_quad("label", NULL, NULL, (yyvsp[(-3) - (0)].temp)); }
#line 2879 "parser/kernalex.tab.c"
    break;

  case 183: /* matched_statement: TOK_CASE constant_expression TOK_COLON matched_statement  */
#line 592 "parser/kernalex.y"
                                                                   { codegen_unsupported("case label"); }
#line 2885 "parser/kernalex.tab.c"
    break;

  case 184: /* matched_statement: TOK_DEFAULT TOK_COLON matched_statement  */
#line 593 "parser/kernalex.y"
                                                  { codegen_unsupported("default label"); }
#line 2891 "parser/kernalex.tab.c"
    break;

  case 185: /* matched_statement: TOK_SWITCH TOK_LPAREN expression TOK_RPAREN matched_statement  */
#line 594 "parser/kernalex.y"
                                                                    { codegen_unsupported("switch statement"); }
#line 2897 "parser/kernalex.tab.c"
    break;

  case 186: /* matched_statement: if_else_head matched_statement  */
#line 595 "parser/kernalex.y"
                                         { emit_quad("label", NULL, NULL, (yyvsp[-1].temp)); ladder_len++; if(ladder_len>=max){max=ladder_len;} ladder_len--; }
#line 2903 "parser/kernalex.tab.c"
    break;

  case 188: /* unmatched_statement: TOK_CASE constant_expression TOK_COLON unmatched_statement  */
#line 600 "parser/kernalex.y"
                                                                     { codegen_unsupported("case label"); }
#line 2909 "parser/kernalex.tab.c"
    break;

  case 189: /* unmatched_statement: TOK_DEFAULT TOK_COLON unmatched_statement  */
#line 601 "parser/kernalex.y"
                                                    { codegen_unsupported("default label"); }
#line 2915 "parser/kernalex.tab.c"
    break;

  case 191: /* unmatched_statement: if_head statement  */
#line 603 "parser/kernalex.y"
                            { emit_quad("label", NULL, NULL, (yyvsp[-1].temp)); ifs_wo_else++; }
#line 2921 "parser/kernalex.tab.c"
    break;

  case 192: /* unmatched_statement: if_else_head unmatched_statement  */
#line 604 "parser/kernalex.y"
                                           { emit_quad("label", NULL, NULL, (yyvsp[-1].temp)); ladder_len++; if(ladder_len>=max){max=ladder_len;} ladder_len--; }
#line 2927 "parser/kernalex.tab.c"
    break;

  case 193: /* iteration_statement: TOK_WHILE L_mark TOK_LPAREN M_mark_expr TOK_RPAREN matched_statement  */
#line 608 "parser/kernalex.y"
                                                                               { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-2].temp)); }
#line 2933 "parser/kernalex.tab.c"
    break;

  case 194: /* iteration_statement: TOK_REPEAT L_mark matched_statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON  */
#line 609 "parser/kernalex.y"
                                                                                                       { emit_quad("ifFalse", (yyvsp[-2].temp), NULL, (yyvsp[-6].temp)); }
#line 2939 "parser/kernalex.tab.c"
    break;

  case 195: /* iteration_statement: TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt TOK_RPAREN M_for_post_empty matched_statement  */
#line 610 "parser/kernalex.y"
                                                                                                                   { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-3].temp)); }
#line 2945 "parser/kernalex.tab.c"
    break;

  case 196: /* iteration_statement: TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt M_for_body M_for_update expression TOK_RPAREN M_for_post_expr matched_statement  */
#line 611 "parser/kernalex.y"
                                                                                                                                                     { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-6].temp)); }
#line 2951 "parser/kernalex.tab.c"
    break;

  case 197: /* iteration_statement: TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt TOK_RPAREN M_for_post_empty matched_statement  */
#line 612 "parser/kernalex.y"
                                                                                                          { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-3].temp)); }
#line 2957 "parser/kernalex.tab.c"
    break;

  case 198: /* iteration_statement: TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt M_for_body M_for_update expression TOK_RPAREN M_for_post_expr matched_statement  */
#line 613 "parser/kernalex.y"
                                                                                                                                            { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-6].temp)); }
#line 2963 "parser/kernalex.tab.c"
    break;

  case 199: /* unmatched_iteration_statement: TOK_WHILE L_mark TOK_LPAREN M_mark_expr TOK_RPAREN unmatched_statement  */
#line 617 "parser/kernalex.y"
                                                                                 { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-2].temp)); }
#line 2969 "parser/kernalex.tab.c"
    break;

  case 200: /* unmatched_iteration_statement: TOK_REPEAT L_mark unmatched_statement TOK_UNTIL TOK_LPAREN expression TOK_RPAREN TOK_SEMICOLON  */
#line 618 "parser/kernalex.y"
                                                                                                         { emit_quad("ifFalse", (yyvsp[-2].temp), NULL, (yyvsp[-6].temp)); }
#line 2975 "parser/kernalex.tab.c"
    break;

  case 201: /* unmatched_iteration_statement: TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt TOK_RPAREN M_for_post_empty unmatched_statement  */
#line 619 "parser/kernalex.y"
                                                                                                                     { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-3].temp)); }
#line 2981 "parser/kernalex.tab.c"
    break;

  case 202: /* unmatched_iteration_statement: TOK_FOR TOK_LPAREN expression_statement L_mark M_mark_stmt M_for_body M_for_update expression TOK_RPAREN M_for_post_expr unmatched_statement  */
#line 620 "parser/kernalex.y"
                                                                                                                                                       { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-6].temp)); }
#line 2987 "parser/kernalex.tab.c"
    break;

  case 203: /* unmatched_iteration_statement: TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt TOK_RPAREN M_for_post_empty unmatched_statement  */
#line 621 "parser/kernalex.y"
                                                                                                            { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-3].temp)); }
#line 2993 "parser/kernalex.tab.c"
    break;

  case 204: /* unmatched_iteration_statement: TOK_FOR TOK_LPAREN declaration L_mark M_mark_stmt M_for_body M_for_update expression TOK_RPAREN M_for_post_expr unmatched_statement  */
#line 622 "parser/kernalex.y"
                                                                                                                                              { emit_quad("goto", NULL, NULL, (yyvsp[-4].temp)); emit_quad("label", NULL, NULL, (yyvsp[-6].temp)); }
#line 2999 "parser/kernalex.tab.c"
    break;

  case 205: /* jump_statement: TOK_CONTINUE TOK_SEMICOLON  */
#line 626 "parser/kernalex.y"
                                     { codegen_unsupported("continue statement"); }
#line 3005 "parser/kernalex.tab.c"
    break;

  case 206: /* jump_statement: TOK_BREAK TOK_SEMICOLON  */
#line 627 "parser/kernalex.y"
                                  { codegen_unsupported("break statement"); }
#line 3011 "parser/kernalex.tab.c"
    break;

  case 207: /* jump_statement: TOK_RETURN TOK_SEMICOLON  */
#line 628 "parser/kernalex.y"
                               { emit_quad("return", NULL, NULL, NULL); }
#line 3017 "parser/kernalex.tab.c"
    break;

  case 208: /* jump_statement: TOK_RETURN expression TOK_SEMICOLON  */
#line 629 "parser/kernalex.y"
                                          { emit_quad("return", (yyvsp[-1].temp), NULL, NULL); }
#line 3023 "parser/kernalex.tab.c"
    break;

  case 209: /* translation_unit: function_definition  */
#line 633 "parser/kernalex.y"
                              {func_definitions++;}
#line 3029 "parser/kernalex.tab.c"
    break;


#line 3033 "parser/kernalex.tab.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

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
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 647 "parser/kernalex.y"

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
	exit(2);
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

char buff[2048];

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

    exit(-1);
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
		sprintf(buff,
		        "***process terminated*** [input error]: "
		        "no such file \"%s\" exists", argv[1]);
		mode = 1;
		yyerror(buff);
		exit(1);
	}

	load_source_lines(yyin);
    ir_init();  /* Initialize IR subsystem */

    do { yyparse(); } while(!feof(yyin));

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
