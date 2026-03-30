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

#line 222 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
