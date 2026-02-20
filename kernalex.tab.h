/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOK_INT8 = 258,
     TOK_INT16 = 259,
     TOK_INT32 = 260,
     TOK_INT64 = 261,
     TOK_INT = 262,
     TOK_SHORT = 263,
     TOK_FLOAT = 264,
     TOK_CHAR = 265,
     TOK_VOID = 266,
     TOK_BOOL = 267,
     TOK_BOOLEAN = 268,
     TOK_STRUCT = 269,
     TOK_SIGNED = 270,
     TOK_UNSIGNED = 271,
     TOK_EXTERN = 272,
     TOK_STATIC = 273,
     TOK_IF = 274,
     TOK_ELSE = 275,
     TOK_FOR = 276,
     TOK_WHILE = 277,
     TOK_REPEAT = 278,
     TOK_UNTIL = 279,
     TOK_SWITCH = 280,
     TOK_CASE = 281,
     TOK_DEFAULT = 282,
     TOK_BREAK = 283,
     TOK_CONTINUE = 284,
     TOK_RETURN = 285,
     TOK_SIZEOF = 286,
     TOK_TRUE = 287,
     TOK_FALSE = 288,
     TOK_BEGIN = 289,
     TOK_END = 290,
     TOK_IDENTIFIER = 291,
     TOK_INTEGER = 292,
     TOK_FLOAT_LIT = 293,
     TOK_CHAR_LIT = 294,
     TOK_STRING_LIT = 295,
     TOK_PLUS = 296,
     TOK_MINUS = 297,
     TOK_MULT = 298,
     TOK_DIV = 299,
     TOK_MOD = 300,
     TOK_ASSIGN = 301,
     TOK_EQ = 302,
     TOK_NE = 303,
     TOK_LT = 304,
     TOK_LE = 305,
     TOK_GT = 306,
     TOK_GE = 307,
     TOK_SPACESHIP = 308,
     TOK_AND = 309,
     TOK_OR = 310,
     TOK_NOT = 311,
     TOK_BITAND = 312,
     TOK_BITOR = 313,
     TOK_XOR = 314,
     TOK_BITNOT = 315,
     TOK_LSHIFT = 316,
     TOK_RSHIFT = 317,
     TOK_INC = 318,
     TOK_DEC = 319,
     TOK_PLUSEQ = 320,
     TOK_MINUSEQ = 321,
     TOK_MULTEQ = 322,
     TOK_DIVEQ = 323,
     TOK_MODEQ = 324,
     TOK_ARROW = 325,
     TOK_AMP = 326,
     TOK_STAR = 327,
     TOK_LPAREN = 328,
     TOK_RPAREN = 329,
     TOK_LBRACE = 330,
     TOK_RBRACE = 331,
     TOK_LBRACKET = 332,
     TOK_RBRACKET = 333,
     TOK_SEMICOLON = 334,
     TOK_COMMA = 335,
     TOK_DOT = 336,
     TOK_COLON = 337,
     DEREF = 338,
     ADDR_OF = 339,
     UNARY_MINUS = 340
   };
#endif
/* Tokens.  */
#define TOK_INT8 258
#define TOK_INT16 259
#define TOK_INT32 260
#define TOK_INT64 261
#define TOK_INT 262
#define TOK_SHORT 263
#define TOK_FLOAT 264
#define TOK_CHAR 265
#define TOK_VOID 266
#define TOK_BOOL 267
#define TOK_BOOLEAN 268
#define TOK_STRUCT 269
#define TOK_SIGNED 270
#define TOK_UNSIGNED 271
#define TOK_EXTERN 272
#define TOK_STATIC 273
#define TOK_IF 274
#define TOK_ELSE 275
#define TOK_FOR 276
#define TOK_WHILE 277
#define TOK_REPEAT 278
#define TOK_UNTIL 279
#define TOK_SWITCH 280
#define TOK_CASE 281
#define TOK_DEFAULT 282
#define TOK_BREAK 283
#define TOK_CONTINUE 284
#define TOK_RETURN 285
#define TOK_SIZEOF 286
#define TOK_TRUE 287
#define TOK_FALSE 288
#define TOK_BEGIN 289
#define TOK_END 290
#define TOK_IDENTIFIER 291
#define TOK_INTEGER 292
#define TOK_FLOAT_LIT 293
#define TOK_CHAR_LIT 294
#define TOK_STRING_LIT 295
#define TOK_PLUS 296
#define TOK_MINUS 297
#define TOK_MULT 298
#define TOK_DIV 299
#define TOK_MOD 300
#define TOK_ASSIGN 301
#define TOK_EQ 302
#define TOK_NE 303
#define TOK_LT 304
#define TOK_LE 305
#define TOK_GT 306
#define TOK_GE 307
#define TOK_SPACESHIP 308
#define TOK_AND 309
#define TOK_OR 310
#define TOK_NOT 311
#define TOK_BITAND 312
#define TOK_BITOR 313
#define TOK_XOR 314
#define TOK_BITNOT 315
#define TOK_LSHIFT 316
#define TOK_RSHIFT 317
#define TOK_INC 318
#define TOK_DEC 319
#define TOK_PLUSEQ 320
#define TOK_MINUSEQ 321
#define TOK_MULTEQ 322
#define TOK_DIVEQ 323
#define TOK_MODEQ 324
#define TOK_ARROW 325
#define TOK_AMP 326
#define TOK_STAR 327
#define TOK_LPAREN 328
#define TOK_RPAREN 329
#define TOK_LBRACE 330
#define TOK_RBRACE 331
#define TOK_LBRACKET 332
#define TOK_RBRACKET 333
#define TOK_SEMICOLON 334
#define TOK_COMMA 335
#define TOK_DOT 336
#define TOK_COLON 337
#define DEREF 338
#define ADDR_OF 339
#define UNARY_MINUS 340




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

