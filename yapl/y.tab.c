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
#line 2 "yapl.y"

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

#line 87 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    I_CONSTANT = 259,              /* I_CONSTANT  */
    F_CONSTANT = 260,              /* F_CONSTANT  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    FUNC_NAME = 262,               /* FUNC_NAME  */
    SIZEOF = 263,                  /* SIZEOF  */
    PTR_OP = 264,                  /* PTR_OP  */
    INC_OP = 265,                  /* INC_OP  */
    DEC_OP = 266,                  /* DEC_OP  */
    LEFT_OP = 267,                 /* LEFT_OP  */
    RIGHT_OP = 268,                /* RIGHT_OP  */
    LE_OP = 269,                   /* LE_OP  */
    GE_OP = 270,                   /* GE_OP  */
    EQ_OP = 271,                   /* EQ_OP  */
    NE_OP = 272,                   /* NE_OP  */
    TH_OP = 273,                   /* TH_OP  */
    AND_OP = 274,                  /* AND_OP  */
    OR_OP = 275,                   /* OR_OP  */
    MUL_ASSIGN = 276,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 277,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 278,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 279,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 280,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 281,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 282,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 283,              /* AND_ASSIGN  */
    XOR_ASSIGN = 284,              /* XOR_ASSIGN  */
    OR_ASSIGN = 285,               /* OR_ASSIGN  */
    TK_BEGIN = 286,                /* TK_BEGIN  */
    TK_END = 287,                  /* TK_END  */
    BOOL = 288,                    /* BOOL  */
    BOOLEAN = 289,                 /* BOOLEAN  */
    INT8_T = 290,                  /* INT8_T  */
    INT16_T = 291,                 /* INT16_T  */
    INT32_T = 292,                 /* INT32_T  */
    INT64_T = 293,                 /* INT64_T  */
    TRUE_KW = 294,                 /* TRUE_KW  */
    FALSE_KW = 295,                /* FALSE_KW  */
    REPEAT = 296,                  /* REPEAT  */
    UNTIL = 297,                   /* UNTIL  */
    THREE_WAY_OP = 298,            /* THREE_WAY_OP  */
    XOR_XOR_OP = 299,              /* XOR_XOR_OP  */
    EXTERN = 300,                  /* EXTERN  */
    STATIC = 301,                  /* STATIC  */
    CONST = 302,                   /* CONST  */
    CHAR = 303,                    /* CHAR  */
    SHORT = 304,                   /* SHORT  */
    INT = 305,                     /* INT  */
    SIGNED = 306,                  /* SIGNED  */
    UNSIGNED = 307,                /* UNSIGNED  */
    FLOAT = 308,                   /* FLOAT  */
    VOID = 309,                    /* VOID  */
    STRUCT = 310,                  /* STRUCT  */
    ELLIPSIS = 311,                /* ELLIPSIS  */
    CASE = 312,                    /* CASE  */
    DEFAULT = 313,                 /* DEFAULT  */
    SWITCH = 314,                  /* SWITCH  */
    WHILE = 315,                   /* WHILE  */
    DO = 316,                      /* DO  */
    FOR = 317,                     /* FOR  */
    GOTO = 318,                    /* GOTO  */
    CONTINUE = 319,                /* CONTINUE  */
    BREAK = 320,                   /* BREAK  */
    RETURN = 321,                  /* RETURN  */
    IF = 322,                      /* IF  */
    ELSE = 323,                    /* ELSE  */
    ALIGNAS = 324,                 /* ALIGNAS  */
    ALIGNOF = 325,                 /* ALIGNOF  */
    ATOMIC = 326,                  /* ATOMIC  */
    GENERIC = 327,                 /* GENERIC  */
    NORETURN = 328,                /* NORETURN  */
    STATIC_ASSERT = 329,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 330             /* THREAD_LOCAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define I_CONSTANT 259
#define F_CONSTANT 260
#define STRING_LITERAL 261
#define FUNC_NAME 262
#define SIZEOF 263
#define PTR_OP 264
#define INC_OP 265
#define DEC_OP 266
#define LEFT_OP 267
#define RIGHT_OP 268
#define LE_OP 269
#define GE_OP 270
#define EQ_OP 271
#define NE_OP 272
#define TH_OP 273
#define AND_OP 274
#define OR_OP 275
#define MUL_ASSIGN 276
#define DIV_ASSIGN 277
#define MOD_ASSIGN 278
#define ADD_ASSIGN 279
#define SUB_ASSIGN 280
#define LEFT_ASSIGN 281
#define RIGHT_ASSIGN 282
#define AND_ASSIGN 283
#define XOR_ASSIGN 284
#define OR_ASSIGN 285
#define TK_BEGIN 286
#define TK_END 287
#define BOOL 288
#define BOOLEAN 289
#define INT8_T 290
#define INT16_T 291
#define INT32_T 292
#define INT64_T 293
#define TRUE_KW 294
#define FALSE_KW 295
#define REPEAT 296
#define UNTIL 297
#define THREE_WAY_OP 298
#define XOR_XOR_OP 299
#define EXTERN 300
#define STATIC 301
#define CONST 302
#define CHAR 303
#define SHORT 304
#define INT 305
#define SIGNED 306
#define UNSIGNED 307
#define FLOAT 308
#define VOID 309
#define STRUCT 310
#define ELLIPSIS 311
#define CASE 312
#define DEFAULT 313
#define SWITCH 314
#define WHILE 315
#define DO 316
#define FOR 317
#define GOTO 318
#define CONTINUE 319
#define BREAK 320
#define RETURN 321
#define IF 322
#define ELSE 323
#define ALIGNAS 324
#define ALIGNOF 325
#define ATOMIC 326
#define GENERIC 327
#define NORETURN 328
#define STATIC_ASSERT 329
#define THREAD_LOCAL 330

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "yapl.y"

	int val;
	struct symtab *symp;

#line 295 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_I_CONSTANT = 4,                 /* I_CONSTANT  */
  YYSYMBOL_F_CONSTANT = 5,                 /* F_CONSTANT  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_FUNC_NAME = 7,                  /* FUNC_NAME  */
  YYSYMBOL_SIZEOF = 8,                     /* SIZEOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_TH_OP = 18,                     /* TH_OP  */
  YYSYMBOL_AND_OP = 19,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 20,                     /* OR_OP  */
  YYSYMBOL_MUL_ASSIGN = 21,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 22,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 23,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 24,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 25,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 26,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 27,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 28,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 29,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 30,                 /* OR_ASSIGN  */
  YYSYMBOL_TK_BEGIN = 31,                  /* TK_BEGIN  */
  YYSYMBOL_TK_END = 32,                    /* TK_END  */
  YYSYMBOL_BOOL = 33,                      /* BOOL  */
  YYSYMBOL_BOOLEAN = 34,                   /* BOOLEAN  */
  YYSYMBOL_INT8_T = 35,                    /* INT8_T  */
  YYSYMBOL_INT16_T = 36,                   /* INT16_T  */
  YYSYMBOL_INT32_T = 37,                   /* INT32_T  */
  YYSYMBOL_INT64_T = 38,                   /* INT64_T  */
  YYSYMBOL_TRUE_KW = 39,                   /* TRUE_KW  */
  YYSYMBOL_FALSE_KW = 40,                  /* FALSE_KW  */
  YYSYMBOL_REPEAT = 41,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 42,                     /* UNTIL  */
  YYSYMBOL_THREE_WAY_OP = 43,              /* THREE_WAY_OP  */
  YYSYMBOL_XOR_XOR_OP = 44,                /* XOR_XOR_OP  */
  YYSYMBOL_EXTERN = 45,                    /* EXTERN  */
  YYSYMBOL_STATIC = 46,                    /* STATIC  */
  YYSYMBOL_CONST = 47,                     /* CONST  */
  YYSYMBOL_CHAR = 48,                      /* CHAR  */
  YYSYMBOL_SHORT = 49,                     /* SHORT  */
  YYSYMBOL_INT = 50,                       /* INT  */
  YYSYMBOL_SIGNED = 51,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 52,                  /* UNSIGNED  */
  YYSYMBOL_FLOAT = 53,                     /* FLOAT  */
  YYSYMBOL_VOID = 54,                      /* VOID  */
  YYSYMBOL_STRUCT = 55,                    /* STRUCT  */
  YYSYMBOL_ELLIPSIS = 56,                  /* ELLIPSIS  */
  YYSYMBOL_CASE = 57,                      /* CASE  */
  YYSYMBOL_DEFAULT = 58,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 59,                    /* SWITCH  */
  YYSYMBOL_WHILE = 60,                     /* WHILE  */
  YYSYMBOL_DO = 61,                        /* DO  */
  YYSYMBOL_FOR = 62,                       /* FOR  */
  YYSYMBOL_GOTO = 63,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 64,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 65,                     /* BREAK  */
  YYSYMBOL_RETURN = 66,                    /* RETURN  */
  YYSYMBOL_IF = 67,                        /* IF  */
  YYSYMBOL_ELSE = 68,                      /* ELSE  */
  YYSYMBOL_ALIGNAS = 69,                   /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 70,                   /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 71,                    /* ATOMIC  */
  YYSYMBOL_GENERIC = 72,                   /* GENERIC  */
  YYSYMBOL_NORETURN = 73,                  /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 74,             /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 75,              /* THREAD_LOCAL  */
  YYSYMBOL_76_ = 76,                       /* '('  */
  YYSYMBOL_77_ = 77,                       /* ')'  */
  YYSYMBOL_78_ = 78,                       /* '['  */
  YYSYMBOL_79_ = 79,                       /* ']'  */
  YYSYMBOL_80_ = 80,                       /* '.'  */
  YYSYMBOL_81_ = 81,                       /* '{'  */
  YYSYMBOL_82_ = 82,                       /* '}'  */
  YYSYMBOL_83_ = 83,                       /* ','  */
  YYSYMBOL_84_ = 84,                       /* '&'  */
  YYSYMBOL_85_ = 85,                       /* '*'  */
  YYSYMBOL_86_ = 86,                       /* '+'  */
  YYSYMBOL_87_ = 87,                       /* '-'  */
  YYSYMBOL_88_ = 88,                       /* '~'  */
  YYSYMBOL_89_ = 89,                       /* '!'  */
  YYSYMBOL_90_ = 90,                       /* '^'  */
  YYSYMBOL_91_ = 91,                       /* '/'  */
  YYSYMBOL_92_ = 92,                       /* '%'  */
  YYSYMBOL_93_ = 93,                       /* '<'  */
  YYSYMBOL_94_ = 94,                       /* '>'  */
  YYSYMBOL_95_ = 95,                       /* '|'  */
  YYSYMBOL_96_ = 96,                       /* '='  */
  YYSYMBOL_97_ = 97,                       /* ';'  */
  YYSYMBOL_98_ = 98,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 99,                  /* $accept  */
  YYSYMBOL_primary_expression = 100,       /* primary_expression  */
  YYSYMBOL_constant = 101,                 /* constant  */
  YYSYMBOL_string = 102,                   /* string  */
  YYSYMBOL_postfix_expression = 103,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 104, /* argument_expression_list  */
  YYSYMBOL_unary_expression = 105,         /* unary_expression  */
  YYSYMBOL_unary_operator = 106,           /* unary_operator  */
  YYSYMBOL_cast_expression = 107,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 108, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 109,      /* additive_expression  */
  YYSYMBOL_shift_expression = 110,         /* shift_expression  */
  YYSYMBOL_relational_expression = 111,    /* relational_expression  */
  YYSYMBOL_equality_expression = 112,      /* equality_expression  */
  YYSYMBOL_and_expression = 113,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 114,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 115,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expression = 116,   /* logical_and_expression  */
  YYSYMBOL_logical_or_expression = 117,    /* logical_or_expression  */
  YYSYMBOL_conditional_expression = 118,   /* conditional_expression  */
  YYSYMBOL_assignment_expression = 119,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 120,      /* assignment_operator  */
  YYSYMBOL_expression = 121,               /* expression  */
  YYSYMBOL_constant_expression = 122,      /* constant_expression  */
  YYSYMBOL_declaration = 123,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 124,   /* declaration_specifiers  */
  YYSYMBOL_init_declarator_list = 125,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 126,          /* init_declarator  */
  YYSYMBOL_storage_class_specifier = 127,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 128,           /* type_specifier  */
  YYSYMBOL_struct_specifier = 129,         /* struct_specifier  */
  YYSYMBOL_struct_declaration_list = 130,  /* struct_declaration_list  */
  YYSYMBOL_struct_declaration = 131,       /* struct_declaration  */
  YYSYMBOL_specifier_qualifier_list = 132, /* specifier_qualifier_list  */
  YYSYMBOL_struct_declarator_list = 133,   /* struct_declarator_list  */
  YYSYMBOL_struct_declarator = 134,        /* struct_declarator  */
  YYSYMBOL_declarator = 135,               /* declarator  */
  YYSYMBOL_136_1 = 136,                    /* $@1  */
  YYSYMBOL_direct_declarator = 137,        /* direct_declarator  */
  YYSYMBOL_pointer = 138,                  /* pointer  */
  YYSYMBOL_parameter_type_list = 139,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 140,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 141,    /* parameter_declaration  */
  YYSYMBOL_identifier_list = 142,          /* identifier_list  */
  YYSYMBOL_type_name = 143,                /* type_name  */
  YYSYMBOL_abstract_declarator = 144,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 145, /* direct_abstract_declarator  */
  YYSYMBOL_initializer = 146,              /* initializer  */
  YYSYMBOL_initializer_list = 147,         /* initializer_list  */
  YYSYMBOL_designation = 148,              /* designation  */
  YYSYMBOL_designator_list = 149,          /* designator_list  */
  YYSYMBOL_designator = 150,               /* designator  */
  YYSYMBOL_statement = 151,                /* statement  */
  YYSYMBOL_labeled_statement = 152,        /* labeled_statement  */
  YYSYMBOL_compound_statement = 153,       /* compound_statement  */
  YYSYMBOL_block_item_list = 154,          /* block_item_list  */
  YYSYMBOL_block_item = 155,               /* block_item  */
  YYSYMBOL_expression_statement = 156,     /* expression_statement  */
  YYSYMBOL_selection_statement = 157,      /* selection_statement  */
  YYSYMBOL_158_2 = 158,                    /* $@2  */
  YYSYMBOL_iteration_statement = 159,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 160,           /* jump_statement  */
  YYSYMBOL_translation_unit = 161,         /* translation_unit  */
  YYSYMBOL_external_declaration = 162,     /* external_declaration  */
  YYSYMBOL_function_definition = 163,      /* function_definition  */
  YYSYMBOL_declaration_list = 164          /* declaration_list  */
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
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1662

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  99
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  211
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   330


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
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    89,     2,     2,     2,    92,    84,     2,
      76,    77,    85,    86,    83,    87,    80,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    98,    97,
      93,    96,    94,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    78,     2,    79,    90,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    81,    95,    82,    88,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    58,    58,    59,    60,    61,    62,    63,    67,    68,
      72,    73,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    91,    92,    96,    97,    98,    99,   100,   101,
     102,   106,   107,   108,   109,   110,   111,   115,   116,   120,
     121,   122,   123,   127,   128,   129,   133,   134,   135,   139,
     140,   141,   142,   143,   144,   148,   149,   150,   154,   155,
     159,   160,   164,   165,   169,   170,   174,   175,   179,   183,
     184,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   202,   203,   207,   211,   212,   216,   217,   218,
     219,   223,   224,   228,   229,   233,   234,   235,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   256,   257,   261,   262,   266,   267,   271,   272,
     276,   277,   281,   282,   283,   288,   288,   289,   293,   294,
     295,   296,   297,   298,   299,   303,   304,   310,   311,   315,
     316,   320,   321,   322,   326,   327,   331,   332,   336,   337,
     338,   342,   343,   344,   345,   346,   347,   348,   349,   350,
     354,   355,   356,   360,   361,   362,   363,   367,   371,   372,
     376,   377,   381,   382,   383,   384,   385,   386,   390,   391,
     392,   396,   397,   401,   402,   406,   407,   411,   412,   416,
     416,   417,   418,   422,   423,   424,   425,   426,   427,   431,
     432,   433,   434,   435,   439,   440,   444,   445,   449,   450,
     454,   455
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "I_CONSTANT", "F_CONSTANT", "STRING_LITERAL", "FUNC_NAME", "SIZEOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "TH_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TK_BEGIN", "TK_END", "BOOL",
  "BOOLEAN", "INT8_T", "INT16_T", "INT32_T", "INT64_T", "TRUE_KW",
  "FALSE_KW", "REPEAT", "UNTIL", "THREE_WAY_OP", "XOR_XOR_OP", "EXTERN",
  "STATIC", "CONST", "CHAR", "SHORT", "INT", "SIGNED", "UNSIGNED", "FLOAT",
  "VOID", "STRUCT", "ELLIPSIS", "CASE", "DEFAULT", "SWITCH", "WHILE", "DO",
  "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "IF", "ELSE", "ALIGNAS",
  "ALIGNOF", "ATOMIC", "GENERIC", "NORETURN", "STATIC_ASSERT",
  "THREAD_LOCAL", "'('", "')'", "'['", "']'", "'.'", "'{'", "'}'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'^'", "'/'", "'%'", "'<'",
  "'>'", "'|'", "'='", "';'", "':'", "$accept", "primary_expression",
  "constant", "string", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
  "block_item", "expression_statement", "selection_statement", "$@2",
  "iteration_statement", "jump_statement", "translation_unit",
  "external_declaration", "function_definition", "declaration_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-263)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-126)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1579,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,    29,  -263,  -263,    16,
    1579,  1579,  -263,   154,  -263,  -263,     9,  -263,    27,   -30,
    -263,   -11,  -263,  1409,   135,  -263,  -263,  -263,  -263,  -263,
     744,    -1,  -263,    27,  -263,   323,   933,  -263,    16,  -263,
    1490,  1376,   984,    15,   744,  1607,  -263,    11,  -263,  -263,
     -18,     1,  -263,  -263,  -263,  -263,  1230,  1281,  1281,  -263,
    -263,  -263,   560,  1319,     4,    80,   109,   125,   213,   121,
     123,   519,   146,   151,   736,  -263,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,    59,    36,  1319,  -263,    92,
      42,   152,    32,   132,   150,   191,   141,   220,   223,  -263,
    -263,    37,  -263,  -263,  -263,  -263,   411,  -263,  -263,  -263,
    -263,  -263,  -263,   891,  -263,  -263,  -263,  -263,  -263,  -263,
      38,   163,   161,  -263,   -39,  -263,   168,   135,  -263,  -263,
    -263,  -263,  1319,    50,  -263,   155,   560,   736,  -263,   736,
    -263,  -263,   207,  -263,  -263,   156,   560,  1319,  1319,   499,
     153,  -263,  -263,  -263,    53,  1319,   744,    -3,    46,   175,
     253,  -263,  -263,  1022,  1319,   254,  -263,  -263,  -263,  -263,
    -263,  -263,  -263,  -263,  -263,  -263,  -263,  1319,  -263,  1319,
    1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,
    1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,  1319,  -263,
    -263,  -263,  1319,   255,  -263,    -4,   933,   -29,  -263,   628,
    1042,  -263,    39,  -263,   136,  -263,  1551,  -263,   256,  -263,
    -263,    12,  -263,  1319,  -263,   183,   184,   186,   560,  -263,
      63,    74,   648,   648,  -263,  -263,    75,   188,  -263,  1437,
     139,  -263,  1080,  -263,  -263,    76,  -263,   -40,  -263,  -263,
    -263,  -263,  -263,    92,    92,    42,    42,   152,   152,   152,
     152,   152,    32,    32,   132,   150,   191,   141,   220,  -263,
     190,  -263,  -263,   797,  -263,  -263,  -263,  -263,   193,   194,
    -263,   195,   136,  1518,  1131,  -263,  -263,  -263,  -263,  -263,
     182,   182,  1319,  -263,   560,   560,  1169,  1189,   560,  -263,
     891,  -263,  -263,  1319,  -263,  -263,  -263,  -263,   933,  -263,
    -263,  -263,  -263,   198,  -263,   197,    83,  -263,  -263,   560,
      84,   560,    86,   209,    95,  -263,  -263,  -263,  -263,   185,
    -263,   560,  -263,   560,  -263,  -263,   839,  -263,  -263,  -263,
     560,  -263,  -263
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   103,   104,   105,   106,   107,   108,    95,    96,    99,
     100,   101,   109,   110,   102,    98,     0,    97,   207,     0,
      88,    90,   111,     0,   204,   206,   113,   128,     0,   136,
      85,     0,    91,    94,   127,   125,    87,    89,     1,   205,
       0,     0,   135,     0,    86,     0,     0,   210,     0,   209,
       0,     0,     0,     0,   119,     0,   114,     0,   129,    92,
      94,     2,     8,     9,    10,    11,     0,     0,     0,   181,
       5,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,    35,
      36,   187,    12,     3,     4,    24,    37,     0,    39,    43,
      46,    49,    55,    58,    60,    62,    64,    66,    68,    69,
      82,     0,   185,   186,   172,   173,     0,   183,   174,   175,
     176,   177,     2,     0,   162,    93,   211,   208,   144,   133,
     143,     0,   138,   139,     0,   130,     0,   126,   118,   112,
     115,   116,     0,     0,   120,   124,     0,     0,    28,     0,
      25,    26,     0,    37,    84,     0,     0,     0,     0,     0,
       0,   200,   201,   202,     0,     0,     0,     0,   147,     0,
       0,    18,    19,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    71,     0,    27,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   188,
     182,   184,     0,     0,   164,     0,     0,     0,   168,     0,
       0,   141,   149,   142,   150,   132,     0,   134,     0,   131,
     122,     0,   117,     0,   178,     0,     0,     0,     0,   180,
       0,     0,     0,     0,   199,   203,     0,     0,     7,     0,
     149,   146,     0,    17,    14,     0,    22,     0,    16,    70,
      40,    41,    42,    44,    45,    47,    48,    52,    53,    54,
      50,    51,    56,    57,    59,    61,    63,    65,    67,    83,
       0,   171,   160,     0,   163,   167,   169,   156,     0,     0,
     152,     0,   148,     0,     0,   137,   140,   145,   121,   123,
      29,     0,     0,   179,     0,     0,     0,     0,     0,    30,
       0,    38,    15,     0,    13,   170,   161,   166,     0,   157,
     151,   153,   158,     0,   154,     0,     0,   192,   193,     0,
       0,     0,     0,   191,     0,    23,   165,   159,   155,     0,
     197,     0,   195,     0,   189,    20,     0,   194,   198,   196,
       0,    21,   190
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -263,  -263,  -263,  -263,  -263,  -263,   113,  -263,   -84,   -20,
      30,    -2,    31,    78,    79,    81,    73,    77,  -263,   -57,
     -46,  -263,   -76,  -122,   -16,     2,  -263,   242,  -263,   -28,
    -263,  -263,   233,    90,  -263,    58,   -12,  -263,   237,   -26,
     -47,  -263,    65,  -263,  -112,  -120,  -198,   -45,   -17,  -262,
    -263,    82,   -63,  -263,     0,  -263,   176,  -148,  -263,  -263,
    -263,  -263,  -263,   271,  -263,  -263
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    92,    93,    94,    95,   255,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   187,   111,   155,    18,    48,    31,    32,    20,    21,
      22,    55,    56,   168,   143,   144,    41,    53,    34,    35,
     288,   132,   133,   134,   169,   289,   224,   214,   215,   216,
     217,   218,   113,   114,   115,   116,   117,   118,   119,   350,
     120,   121,    23,    24,    25,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     124,   125,    19,    42,   131,   164,   136,    33,   167,   152,
     223,   243,    54,   188,    27,    27,   154,    47,    27,    27,
     230,   318,    36,    37,   292,    19,    54,    54,   282,   112,
      27,    60,    26,    49,   126,   235,    60,   236,   227,   314,
      40,    27,  -125,   208,   228,   145,   196,   197,   251,   212,
     127,   213,   292,   130,   247,    29,    54,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   285,   170,   171,
     172,   167,    43,   167,   248,   198,    58,   124,    46,   283,
     208,   240,   241,   234,   318,   154,    44,    28,    28,   246,
     280,    28,    28,   239,   306,   307,    29,    29,   257,   146,
     112,    29,   156,    28,   222,   260,   261,   262,   141,   142,
     142,   299,    29,    30,   219,   249,   220,   220,   221,    54,
     208,    54,   249,    29,   220,   199,   200,   256,   192,   193,
      57,    29,   186,   231,   209,   173,   208,   174,    54,   175,
     304,   259,   250,   242,   138,    57,   208,   232,   201,   202,
     245,   305,   308,   312,    38,   154,   157,   208,   208,   313,
     339,   341,   279,   343,   194,   195,   208,   208,   311,   208,
     124,   284,   263,   264,   291,   303,   154,   345,   346,   148,
     150,   151,   189,   190,   191,   158,   153,     1,     2,     3,
       4,     5,     6,   222,   267,   268,   269,   270,   271,     7,
       8,   159,     9,    10,    11,    12,    13,    14,    15,    16,
     153,    51,   293,    52,   294,   249,   160,   220,   161,   145,
     162,   130,   165,   250,   265,   266,   326,   166,   130,    17,
     330,   332,   272,   273,   203,   204,   205,   124,   317,   206,
     225,   327,   328,   207,   226,   333,   323,   229,   325,   237,
     244,   130,   252,   233,   238,   153,   253,   258,   281,   297,
     300,   301,   302,   310,   124,   309,   340,   335,   342,   315,
     319,   320,   124,   336,   321,   337,   338,   344,   348,   277,
     349,   274,   347,   275,   278,    59,   276,   352,   140,   298,
     137,   296,   211,   334,    39,   130,     0,     0,     0,   286,
     124,   317,   153,   153,   153,   153,   153,   153,   153,   153,
     153,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     153,     0,     0,     0,     0,   153,    61,    62,    63,    64,
      65,    66,     0,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   153,     0,     0,     0,
       0,     0,     0,     0,    45,    69,     1,     2,     3,     4,
       5,     6,    70,    71,    72,   153,     0,     0,     7,     8,
       0,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      73,    74,    75,    76,     0,    77,    78,    79,    80,    81,
      82,     0,     0,    83,     0,     0,     0,     0,    17,    84,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,     0,    61,    62,    63,    64,    65,    66,
      91,    67,    68,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,   210,     1,     2,     3,     4,     5,     6,
      70,    71,    72,     0,     0,     0,     7,     8,     0,     9,
      10,    11,    12,    13,    14,    15,    16,     0,    73,    74,
      75,    76,     0,    77,    78,    79,    80,    81,    82,     0,
       0,    83,     0,     0,     0,     0,    17,    84,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,     0,   122,    62,    63,    64,    65,    66,    91,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,    62,    63,    64,    65,    66,     0,    67,
      68,     0,     1,     2,     3,     4,     5,     6,    70,    71,
       0,     0,     0,     0,     7,     8,     0,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,    70,    71,
       0,     0,     0,    61,    62,    63,    64,    65,    66,    83,
      67,    68,     0,     0,    17,    84,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    83,
       0,    45,     0,     0,     0,    84,    91,     0,     0,    70,
      71,    72,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,     0,     0,   163,    73,    74,    75,
      76,     0,    77,    78,    79,    80,    81,    82,     0,     0,
      83,    27,     0,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
       0,   122,    62,    63,    64,    65,    66,    91,    67,    68,
       0,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     7,     8,     0,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,    70,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,   219,   287,   220,     0,     0,     0,
       0,     0,     0,    29,     0,     0,     0,     0,    83,     0,
       0,     0,     0,     0,    84,     0,     0,     0,     0,     0,
       0,     0,    85,    86,    87,    88,    89,    90,     0,   122,
      62,    63,    64,    65,    66,    91,    67,    68,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     1,
       2,     3,     4,     5,     6,    70,    71,     1,     2,     3,
       4,     5,     6,     0,     9,    10,    11,    12,    13,    14,
      15,    16,     9,    10,    11,    12,    13,    14,    15,    16,
     122,    62,    63,    64,    65,    66,    83,    67,    68,     0,
       0,     0,    84,     0,     0,     0,     0,     0,     0,     0,
      85,    86,    87,    88,    89,    90,     0,     0,   123,   316,
       0,     0,     0,     0,     0,     0,    70,    71,     0,     0,
       0,     0,   122,    62,    63,    64,    65,    66,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
     123,     0,     0,    84,     0,   212,     0,   213,    70,    71,
       0,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,     0,     0,     0,   122,    62,    63,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,    84,     0,   212,     0,   213,
       0,   351,   123,    85,    86,    87,    88,    89,    90,     0,
      70,    71,     0,     0,     0,     0,   122,    62,    63,    64,
      65,    66,     0,    67,    68,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,   123,     0,     0,    84,     0,   212,
       0,   213,    70,    71,     0,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,   122,    62,    63,
      64,    65,    66,     0,    67,    68,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,     0,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    70,    71,   122,    62,    63,    64,    65,
      66,     0,    67,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   122,    62,    63,    64,    65,
      66,     0,    67,    68,    83,     0,     0,     0,     0,     0,
      84,    70,    71,   135,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,    70,    71,   122,    62,    63,    64,    65,    66,     0,
      67,    68,    83,     0,     0,     0,     0,     0,    84,   254,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    83,     0,     0,     0,     0,     0,    84,    70,
      71,   290,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,     0,     0,   122,    62,    63,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,    84,     0,     0,     0,
       0,   310,     0,     0,    85,    86,    87,    88,    89,    90,
      70,    71,   122,    62,    63,    64,    65,    66,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,    62,    63,    64,    65,    66,     0,    67,
      68,    83,     0,     0,     0,     0,     0,    84,    70,    71,
     324,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,    70,    71,
       0,     0,     0,   122,    62,    63,    64,    65,    66,    83,
      67,    68,     0,     0,     0,    84,   329,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    83,
       0,     0,     0,     0,     0,    84,   331,     0,     0,    70,
      71,     0,     0,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,     0,   122,    62,    63,    64,    65,    66,
       0,    67,    68,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,     0,     0,   147,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      70,    71,   122,    62,    63,    64,    65,    66,     0,    67,
      68,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,     0,     0,   149,    70,    71,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     0,     0,
       0,     7,     8,     0,     9,    10,    11,    12,    13,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
      45,     0,     1,     2,     3,     4,     5,     6,     0,     0,
       0,    17,     0,   129,     7,     8,     0,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,     0,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     7,     8,    17,     9,    10,    11,    12,    13,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,    17,   249,   287,   220,     0,     0,     0,     0,
       0,    45,    29,     1,     2,     3,     4,     5,     6,     0,
       0,     0,     0,     0,     0,     7,     8,     0,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     1,     2,     3,     4,     5,     6,     0,     0,     0,
       0,     0,     0,     7,     8,    17,     9,    10,    11,    12,
      13,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       0,     0,     0,    17,     0,   322,     7,     8,     0,     9,
      10,    11,    12,    13,    14,    15,    16,   295,     0,     0,
       0,     0,     1,     2,     3,     4,     5,     6,     0,     0,
       0,     0,     0,     0,     7,     8,    17,     9,    10,    11,
      12,    13,    14,    15,    16,     0,     0,     0,     0,   139,
       1,     2,     3,     4,     5,     6,     0,     0,     0,     0,
       0,     0,     0,     0,    17,     9,    10,    11,    12,    13,
      14,    15,    16
};

static const yytype_int16 yycheck[] =
{
      46,    46,     0,    29,    51,    81,    52,    19,    84,    72,
     130,   159,    40,    97,     3,     3,    73,    33,     3,     3,
     142,   283,    20,    21,   222,    23,    54,    55,    32,    45,
       3,    43,     3,    33,    50,   147,    48,   149,    77,    79,
      31,     3,     3,    83,    83,    57,    14,    15,   168,    78,
      50,    80,   250,    51,   166,    85,    84,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    96,     9,    10,
      11,   147,    83,   149,    77,    43,    77,   123,    96,    83,
      83,   157,   158,   146,   346,   142,    97,    76,    76,   165,
     212,    76,    76,   156,   242,   243,    85,    85,   174,    98,
     116,    85,    98,    76,   130,   189,   190,   191,    97,    98,
      98,   233,    85,    97,    76,    76,    78,    78,   130,   147,
      83,   149,    76,    85,    78,    93,    94,   173,    86,    87,
      40,    85,    96,    83,    97,    76,    83,    78,   166,    80,
      77,   187,   168,   159,    54,    55,    83,    97,    16,    17,
      97,    77,    77,    77,     0,   212,    76,    83,    83,    83,
      77,    77,   208,    77,    12,    13,    83,    83,   252,    83,
     216,   216,   192,   193,   220,   238,   233,    82,    83,    66,
      67,    68,    90,    91,    92,    76,    73,    33,    34,    35,
      36,    37,    38,   219,   196,   197,   198,   199,   200,    45,
      46,    76,    48,    49,    50,    51,    52,    53,    54,    55,
      97,    76,    76,    78,    78,    76,     3,    78,    97,   231,
      97,   219,    76,   249,   194,   195,   302,    76,   226,    75,
     306,   307,   201,   202,    84,    44,    95,   283,   283,    19,
      77,   304,   305,    20,    83,   308,   293,    79,   294,    42,
      97,   249,    77,    98,    98,   142,     3,     3,     3,     3,
      77,    77,    76,    81,   310,    77,   329,   313,   331,    79,
      77,    77,   318,   318,    79,    77,    79,    68,   341,   206,
     343,   203,    97,   204,   207,    43,   205,   350,    55,   231,
      53,   226,   116,   310,    23,   293,    -1,    -1,    -1,   217,
     346,   346,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,    -1,    -1,    -1,    -1,   212,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,   252,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    -1,
      57,    58,    59,    60,    -1,    62,    63,    64,    65,    66,
      67,    -1,    -1,    70,    -1,    -1,    -1,    -1,    75,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    -1,     3,     4,     5,     6,     7,     8,
      97,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    -1,    57,    58,
      59,    60,    -1,    62,    63,    64,    65,    66,    67,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    -1,     3,     4,     5,     6,     7,     8,    97,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    70,
      10,    11,    -1,    -1,    75,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    70,
      -1,    31,    -1,    -1,    -1,    76,    97,    -1,    -1,    39,
      40,    41,    -1,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    97,    57,    58,    59,
      60,    -1,    62,    63,    64,    65,    66,    67,    -1,    -1,
      70,     3,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      -1,     3,     4,     5,     6,     7,     8,    97,    10,    11,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    77,    78,    -1,    -1,    -1,
      -1,    -1,    -1,    85,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    84,    85,    86,    87,    88,    89,    -1,     3,
       4,     5,     6,     7,     8,    97,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    33,    34,    35,
      36,    37,    38,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    48,    49,    50,    51,    52,    53,    54,    55,
       3,     4,     5,     6,     7,     8,    70,    10,    11,    -1,
      -1,    -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      84,    85,    86,    87,    88,    89,    -1,    -1,    31,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      31,    -1,    -1,    76,    -1,    78,    -1,    80,    39,    40,
      -1,    84,    85,    86,    87,    88,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    78,    -1,    80,
      -1,    82,    31,    84,    85,    86,    87,    88,    89,    -1,
      39,    40,    -1,    -1,    -1,    -1,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    31,    -1,    -1,    76,    -1,    78,
      -1,    80,    39,    40,    -1,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
       6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,
      87,    88,    89,    39,    40,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,
       8,    -1,    10,    11,    70,    -1,    -1,    -1,    -1,    -1,
      76,    39,    40,    79,    -1,    -1,    -1,    -1,    84,    85,
      86,    87,    88,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,     3,     4,     5,     6,     7,     8,    -1,
      10,    11,    70,    -1,    -1,    -1,    -1,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    70,    -1,    -1,    -1,    -1,    -1,    76,    39,
      40,    79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,
      88,    89,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    81,    -1,    -1,    84,    85,    86,    87,    88,    89,
      39,    40,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    70,    -1,    -1,    -1,    -1,    -1,    76,    39,    40,
      79,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,    70,
      10,    11,    -1,    -1,    -1,    76,    77,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    70,
      -1,    -1,    -1,    -1,    -1,    76,    77,    -1,    -1,    39,
      40,    -1,    -1,    84,    85,    86,    87,    88,    89,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,    89,
      39,    40,     3,     4,     5,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    -1,    -1,    76,    39,    40,
      -1,    -1,    -1,    -1,    -1,    84,    85,    86,    87,    88,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    -1,    -1,    76,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    84,    85,    86,    87,    88,    89,    33,
      34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    48,    49,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    75,    -1,    77,    45,    46,    -1,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    75,    48,    49,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    77,    78,    -1,    -1,    -1,    -1,
      -1,    31,    85,    33,    34,    35,    36,    37,    38,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    48,    49,
      50,    51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    36,    37,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    75,    48,    49,    50,    51,
      52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,    35,    36,    37,    38,
      -1,    -1,    -1,    75,    -1,    77,    45,    46,    -1,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    33,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    46,    75,    48,    49,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    48,    49,    50,    51,    52,
      53,    54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    33,    34,    35,    36,    37,    38,    45,    46,    48,
      49,    50,    51,    52,    53,    54,    55,    75,   123,   124,
     127,   128,   129,   161,   162,   163,     3,     3,    76,    85,
      97,   125,   126,   135,   137,   138,   124,   124,     0,   162,
      31,   135,   138,    83,    97,    31,    96,   123,   124,   153,
     164,    76,    78,   136,   128,   130,   131,   132,    77,   126,
     135,     3,     4,     5,     6,     7,     8,    10,    11,    32,
      39,    40,    41,    57,    58,    59,    60,    62,    63,    64,
      65,    66,    67,    70,    76,    84,    85,    86,    87,    88,
      89,    97,   100,   101,   102,   103,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   121,   123,   151,   152,   153,   154,   155,   156,   157,
     159,   160,     3,    31,   119,   146,   123,   153,     3,    77,
     124,   139,   140,   141,   142,    79,   119,   137,   132,    32,
     131,    97,    98,   133,   134,   135,    98,    76,   105,    76,
     105,   105,   151,   105,   118,   122,    98,    76,    76,    76,
       3,    97,    97,    97,   121,    76,    76,   121,   132,   143,
       9,    10,    11,    76,    78,    80,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    96,   120,   107,    90,
      91,    92,    86,    87,    12,    13,    14,    15,    43,    93,
      94,    16,    17,    84,    44,    95,    19,    20,    83,    97,
      32,   155,    78,    80,   146,   147,   148,   149,   150,    76,
      78,   135,   138,   144,   145,    77,    83,    77,    83,    79,
     122,    83,    97,    98,   151,   143,   143,    42,    98,   151,
     121,   121,   123,   156,    97,    97,   121,   143,    77,    76,
     138,   144,    77,     3,    77,   104,   119,   121,     3,   119,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   110,
     110,   110,   111,   111,   112,   113,   114,   115,   116,   119,
     122,     3,    32,    83,   146,    96,   150,    77,   139,   144,
      79,   119,   145,    76,    78,    56,   141,     3,   134,   122,
      77,    77,    76,   151,    77,    77,   156,   156,    77,    77,
      81,   107,    77,    83,    79,    79,    32,   146,   148,    77,
      77,    79,    77,   139,    79,   119,   121,   151,   151,    77,
     121,    77,   121,   151,   147,   119,   146,    77,    79,    77,
     151,    77,   151,    77,    68,    82,    83,    97,   151,   151,
     158,    82,   151
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    99,   100,   100,   100,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   107,   107,   108,
     108,   108,   108,   109,   109,   109,   110,   110,   110,   111,
     111,   111,   111,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   119,
     119,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   121,   121,   122,   123,   123,   124,   124,   124,
     124,   125,   125,   126,   126,   127,   127,   127,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   136,   135,   135,   137,   137,
     137,   137,   137,   137,   137,   138,   138,   139,   139,   140,
     140,   141,   141,   141,   142,   142,   143,   143,   144,   144,
     144,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     146,   146,   146,   147,   147,   147,   147,   148,   149,   149,
     150,   150,   151,   151,   151,   151,   151,   151,   152,   152,
     152,   153,   153,   154,   154,   155,   155,   156,   156,   158,
     157,   157,   157,   159,   159,   159,   159,   159,   159,   160,
     160,   160,   160,   160,   161,   161,   162,   162,   163,   163,
     164,   164
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     4,     3,     4,     3,     3,     2,     2,
       6,     7,     1,     3,     1,     2,     2,     2,     2,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     2,     1,     2,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     2,     1,     2,     2,     3,     2,     1,
       1,     3,     2,     3,     1,     0,     3,     1,     1,     3,
       3,     4,     4,     3,     4,     2,     1,     3,     1,     1,
       3,     2,     2,     1,     1,     3,     2,     1,     2,     1,
       1,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       3,     4,     1,     2,     1,     4,     3,     2,     1,     2,
       3,     2,     1,     1,     1,     1,     1,     1,     3,     4,
       3,     2,     3,     1,     2,     1,     1,     1,     2,     0,
       8,     5,     5,     5,     7,     6,     7,     6,     7,     3,
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
  case 8: /* constant: I_CONSTANT  */
#line 67 "yapl.y"
                     {int_consts++;}
#line 1978 "y.tab.c"
    break;

  case 125: /* $@1: %empty  */
#line 288 "yapl.y"
                  {pointer_decls++;}
#line 1984 "y.tab.c"
    break;

  case 135: /* pointer: '*' pointer  */
#line 303 "yapl.y"
                      {pointer_decls++;}
#line 1990 "y.tab.c"
    break;

  case 136: /* pointer: '*'  */
#line 304 "yapl.y"
              {pointer_decls++;}
#line 1996 "y.tab.c"
    break;

  case 189: /* $@2: %empty  */
#line 416 "yapl.y"
                                               {ladder_len++;(yyvsp[0].val)=(ladder_len-1);}
#line 2002 "y.tab.c"
    break;

  case 190: /* selection_statement: IF '(' expression ')' statement ELSE $@2 statement  */
#line 416 "yapl.y"
                                                                                           {if(ladder_len>=max){max=ladder_len;} /*printf("ladder_len=%d\n",ladder_len);*/ladder_len=(yyvsp[-2].val);}
#line 2008 "y.tab.c"
    break;

  case 191: /* selection_statement: IF '(' expression ')' statement  */
#line 417 "yapl.y"
                                          {ifs_wo_else++;}
#line 2014 "y.tab.c"
    break;

  case 204: /* translation_unit: external_declaration  */
#line 439 "yapl.y"
                               {global_declarations++;}
#line 2020 "y.tab.c"
    break;

  case 205: /* translation_unit: translation_unit external_declaration  */
#line 440 "yapl.y"
                                                {global_declarations++;}
#line 2026 "y.tab.c"
    break;

  case 206: /* external_declaration: function_definition  */
#line 444 "yapl.y"
                              {func_definitions++;}
#line 2032 "y.tab.c"
    break;


#line 2036 "y.tab.c"

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

#line 458 "yapl.y"

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
