/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_KERNALEX_TAB_H_INCLUDED
# define YY_YY_PARSER_KERNALEX_TAB_H_INCLUDED
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
#line 107 "parser/kernalex.y"

	int val;
	struct symtab *symp;

#line 148 "parser/kernalex.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_KERNALEX_TAB_H_INCLUDED  */
