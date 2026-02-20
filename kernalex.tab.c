/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "kernalex.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yylineno;
extern char *yytext;
extern FILE *yyin;

void yyerror(const char *s);

int syntax_error_count = 0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 291 "kernalex.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   771

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNRULES -- Number of states.  */
#define YYNSTATES  256

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   340

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    13,    16,    19,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    44,    47,    50,    51,    53,    55,    59,    65,    67,
      70,    74,    79,    86,    92,    94,    98,   101,   107,   109,
     112,   116,   118,   120,   122,   124,   126,   129,   132,   136,
     140,   142,   145,   147,   150,   156,   164,   172,   174,   177,
     182,   186,   192,   202,   212,   220,   221,   223,   226,   229,
     232,   236,   238,   242,   244,   248,   252,   256,   260,   264,
     268,   270,   274,   276,   280,   282,   286,   288,   292,   294,
     298,   300,   304,   308,   310,   314,   318,   322,   326,   330,
     332,   336,   340,   342,   346,   350,   352,   356,   360,   364,
     366,   369,   372,   375,   378,   381,   384,   387,   390,   395,
     397,   402,   407,   411,   415,   419,   422,   425,   427,   429,
     431,   433,   435,   437,   439,   443,   445
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      87,     0,    -1,    -1,    88,    -1,    89,    -1,    88,    89,
      -1,    94,    -1,    92,    79,    -1,    97,    79,    -1,     7,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,     8,
      -1,     9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,
      -1,    15,    90,    -1,    16,    90,    -1,    14,    36,    -1,
      -1,    17,    -1,    18,    -1,    91,    90,    93,    -1,    91,
      90,    93,    46,   110,    -1,    36,    -1,    72,    93,    -1,
      93,    77,    78,    -1,    93,    77,    37,    78,    -1,    90,
      36,    73,    95,    74,   101,    -1,    90,    36,    73,    74,
     101,    -1,    96,    -1,    95,    80,    96,    -1,    90,    93,
      -1,    14,    36,    75,    98,    76,    -1,    99,    -1,    98,
      99,    -1,    90,    93,    79,    -1,   103,    -1,   101,    -1,
     104,    -1,   107,    -1,   109,    -1,    92,    79,    -1,    75,
      76,    -1,    75,   102,    76,    -1,    34,   102,    35,    -1,
     100,    -1,   102,   100,    -1,    79,    -1,   110,    79,    -1,
      19,    73,   110,    74,   100,    -1,    19,    73,   110,    74,
     100,    20,   100,    -1,    25,    73,   110,    74,    75,   105,
      76,    -1,   106,    -1,   105,   106,    -1,    26,   110,    82,
     102,    -1,    27,    82,   102,    -1,    22,    73,   110,    74,
     100,    -1,    21,    73,   108,    79,   108,    79,   108,    74,
     100,    -1,    21,    73,    92,    79,   108,    79,   108,    74,
     100,    -1,    23,   100,    24,    73,   110,    74,    79,    -1,
      -1,   110,    -1,    28,    79,    -1,    29,    79,    -1,    30,
      79,    -1,    30,   110,    79,    -1,   111,    -1,   110,    80,
     111,    -1,   112,    -1,   112,    46,   111,    -1,   112,    65,
     111,    -1,   112,    66,   111,    -1,   112,    67,   111,    -1,
     112,    68,   111,    -1,   112,    69,   111,    -1,   113,    -1,
     112,    55,   113,    -1,   114,    -1,   113,    54,   114,    -1,
     115,    -1,   114,    58,   115,    -1,   116,    -1,   115,    59,
     116,    -1,   117,    -1,   116,    57,   117,    -1,   118,    -1,
     117,    47,   118,    -1,   117,    48,   118,    -1,   119,    -1,
     118,    49,   119,    -1,   118,    50,   119,    -1,   118,    51,
     119,    -1,   118,    52,   119,    -1,   118,    53,   119,    -1,
     120,    -1,   119,    61,   120,    -1,   119,    62,   120,    -1,
     121,    -1,   120,    41,   121,    -1,   120,    42,   121,    -1,
     122,    -1,   121,    43,   122,    -1,   121,    44,   122,    -1,
     121,    45,   122,    -1,   123,    -1,    63,   122,    -1,    64,
     122,    -1,    41,   122,    -1,    42,   122,    -1,    56,   122,
      -1,    60,   122,    -1,    71,   122,    -1,    72,   122,    -1,
      31,    73,    90,    74,    -1,   124,    -1,   123,    77,   110,
      78,    -1,   123,    73,   125,    74,    -1,   123,    73,    74,
      -1,   123,    81,    36,    -1,   123,    70,    36,    -1,   123,
      63,    -1,   123,    64,    -1,    36,    -1,    37,    -1,    38,
      -1,    39,    -1,    40,    -1,    32,    -1,    33,    -1,    73,
     110,    74,    -1,   111,    -1,   125,    80,   111,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    64,    64,    66,    70,    71,    75,    76,    77,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    98,   100,   101,   106,   107,   111,   112,
     113,   114,   119,   120,   124,   125,   129,   134,   138,   139,
     143,   148,   149,   150,   151,   152,   153,   157,   158,   159,
     163,   164,   168,   169,   174,   175,   176,   180,   181,   185,
     186,   191,   192,   193,   194,   197,   199,   204,   205,   206,
     207,   212,   213,   217,   218,   219,   220,   221,   222,   223,
     227,   228,   232,   233,   237,   238,   242,   243,   247,   248,
     252,   253,   254,   258,   259,   260,   261,   262,   263,   267,
     268,   269,   273,   274,   275,   279,   280,   281,   282,   286,
     287,   288,   289,   290,   291,   292,   293,   294,   295,   299,
     300,   301,   302,   303,   304,   305,   306,   310,   311,   312,
     313,   314,   315,   316,   317,   321,   322
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_INT8", "TOK_INT16", "TOK_INT32",
  "TOK_INT64", "TOK_INT", "TOK_SHORT", "TOK_FLOAT", "TOK_CHAR", "TOK_VOID",
  "TOK_BOOL", "TOK_BOOLEAN", "TOK_STRUCT", "TOK_SIGNED", "TOK_UNSIGNED",
  "TOK_EXTERN", "TOK_STATIC", "TOK_IF", "TOK_ELSE", "TOK_FOR", "TOK_WHILE",
  "TOK_REPEAT", "TOK_UNTIL", "TOK_SWITCH", "TOK_CASE", "TOK_DEFAULT",
  "TOK_BREAK", "TOK_CONTINUE", "TOK_RETURN", "TOK_SIZEOF", "TOK_TRUE",
  "TOK_FALSE", "TOK_BEGIN", "TOK_END", "TOK_IDENTIFIER", "TOK_INTEGER",
  "TOK_FLOAT_LIT", "TOK_CHAR_LIT", "TOK_STRING_LIT", "TOK_PLUS",
  "TOK_MINUS", "TOK_MULT", "TOK_DIV", "TOK_MOD", "TOK_ASSIGN", "TOK_EQ",
  "TOK_NE", "TOK_LT", "TOK_LE", "TOK_GT", "TOK_GE", "TOK_SPACESHIP",
  "TOK_AND", "TOK_OR", "TOK_NOT", "TOK_BITAND", "TOK_BITOR", "TOK_XOR",
  "TOK_BITNOT", "TOK_LSHIFT", "TOK_RSHIFT", "TOK_INC", "TOK_DEC",
  "TOK_PLUSEQ", "TOK_MINUSEQ", "TOK_MULTEQ", "TOK_DIVEQ", "TOK_MODEQ",
  "TOK_ARROW", "TOK_AMP", "TOK_STAR", "TOK_LPAREN", "TOK_RPAREN",
  "TOK_LBRACE", "TOK_RBRACE", "TOK_LBRACKET", "TOK_RBRACKET",
  "TOK_SEMICOLON", "TOK_COMMA", "TOK_DOT", "TOK_COLON", "DEREF", "ADDR_OF",
  "UNARY_MINUS", "$accept", "program", "declaration_list", "declaration",
  "type_specifier", "storage_class", "variable_declaration", "declarator",
  "function_declaration", "parameter_list", "parameter",
  "struct_declaration", "struct_member_list", "struct_member", "statement",
  "compound_statement", "statement_list", "expression_statement",
  "selection_statement", "case_list", "case_item", "iteration_statement",
  "expression_opt", "jump_statement", "expression",
  "assignment_expression", "logical_or_expression",
  "logical_and_expression", "bitwise_or_expression",
  "bitwise_xor_expression", "bitwise_and_expression",
  "equality_expression", "relational_expression", "shift_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", "argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    87,    88,    88,    89,    89,    89,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    91,    92,    92,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    97,    98,    98,
      99,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     102,   102,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   107,   107,   107,   107,   108,   108,   109,   109,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     112,   112,   113,   113,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   118,   118,   118,   118,   118,   118,   119,
     119,   119,   120,   120,   120,   121,   121,   121,   121,   122,
     122,   122,   122,   122,   122,   122,   122,   122,   122,   123,
     123,   123,   123,   123,   123,   123,   123,   124,   124,   124,
     124,   124,   124,   124,   124,   125,   125
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     0,     1,     1,     3,     5,     1,     2,
       3,     4,     6,     5,     1,     3,     2,     5,     1,     2,
       3,     1,     1,     1,     1,     1,     2,     2,     3,     3,
       1,     2,     1,     2,     5,     7,     7,     1,     2,     4,
       3,     5,     9,     9,     7,     0,     1,     2,     2,     2,
       3,     1,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     4,     1,
       4,     4,     3,     3,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,    10,    11,    12,    13,     9,    14,    15,    16,    17,
      18,    19,     0,     0,     0,    24,    25,     0,     3,     4,
       0,     0,     0,     6,     0,    22,     0,    20,    21,     1,
       5,     0,     0,     7,     8,     0,    22,     0,    28,     0,
      26,     0,     0,    38,     0,     0,     0,    34,    29,     0,
       0,     0,    37,    39,    23,    23,    33,    36,     0,     0,
       0,   132,   133,   127,   128,   129,   130,   131,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    27,    71,    73,
      80,    82,    84,    86,    88,    90,    93,    99,   102,   105,
     109,   119,     0,    30,    40,     0,     0,     0,    23,     0,
       0,     0,     0,    52,     0,    50,    42,    23,    41,    43,
      44,    45,     0,    47,    23,    32,    35,     0,   112,   113,
     114,   115,   110,   111,   116,   117,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,   126,     0,     0,     0,     0,    31,
       0,    23,     0,     0,     0,    67,    68,    69,     0,    46,
      49,    51,    53,    48,     0,   134,    72,    74,    81,    75,
      76,    77,    78,    79,    83,    85,    87,    89,    91,    92,
      94,    95,    96,    97,    98,   100,   101,   103,   104,   106,
     107,   108,   124,   122,   135,     0,     0,   123,     0,     0,
       0,    66,     0,     0,     0,    70,   118,   121,     0,   120,
      23,    65,    65,    23,     0,     0,   136,    54,     0,     0,
      61,     0,     0,    23,    65,    65,     0,     0,     0,     0,
      57,    55,     0,     0,    64,     0,    23,    56,    58,    23,
      23,    23,    23,    63,    62,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    17,    18,    19,    20,    21,   104,    40,    23,    46,
      47,    24,    42,    43,   105,   106,   107,   108,   109,   239,
     240,   110,   210,   111,   112,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,   205
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -209
static const yytype_int16 yypact[] =
{
     739,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,  -209,
    -209,  -209,     1,   755,   755,  -209,  -209,    49,   739,  -209,
      20,   755,   -14,  -209,    36,    56,   101,  -209,  -209,  -209,
    -209,    29,   -32,  -209,  -209,   755,  -209,    82,  -209,   -32,
     -30,   -32,    66,  -209,   -25,   -32,   -57,  -209,    76,   668,
     -27,   -47,  -209,  -209,   487,   302,  -209,    76,   -25,   755,
      86,  -209,  -209,  -209,  -209,  -209,  -209,  -209,   668,   668,
     668,   668,   668,   668,   668,   668,   668,    63,  -209,    53,
     108,   106,   109,   115,   -26,    83,    22,    85,   -10,  -209,
      88,  -209,    97,  -209,  -209,   111,   112,   117,   487,   119,
     102,   121,   580,  -209,   132,  -209,  -209,   365,  -209,  -209,
    -209,  -209,    70,  -209,   424,  -209,  -209,   755,  -209,  -209,
    -209,  -209,  -209,  -209,  -209,  -209,   -56,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,   668,   668,   668,   668,   668,   668,   668,
     668,   668,   668,  -209,  -209,   152,   624,   668,   183,  -209,
     668,   536,   668,   196,   668,  -209,  -209,  -209,    87,  -209,
    -209,  -209,  -209,  -209,   147,  -209,  -209,  -209,   108,  -209,
    -209,  -209,  -209,  -209,   106,   109,   115,   -26,    83,    83,
      22,    22,    22,    22,    22,    85,    85,   -10,   -10,  -209,
    -209,  -209,  -209,  -209,  -209,    26,   -12,  -209,    27,   143,
     145,    63,    30,   150,    43,  -209,  -209,  -209,   668,  -209,
     487,   668,   668,   487,   668,   151,  -209,   205,   148,   149,
    -209,    50,   144,   487,   668,   668,   154,   668,   153,   -21,
    -209,  -209,   155,   156,  -209,    23,   487,  -209,  -209,   487,
     487,   487,   176,  -209,  -209,   239
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -209,  -209,  -209,   213,    -6,  -209,     2,     7,  -209,  -209,
     175,  -209,  -209,   195,   -95,   -33,   -55,  -209,  -209,  -209,
      -1,  -209,  -208,  -209,   -48,   -89,  -209,   113,   110,   105,
     107,   116,    38,     3,    33,    34,   -11,  -209,  -209,  -209
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -66
static const yytype_int16 yytable[] =
{
     114,    77,    22,   163,    38,   237,   238,    27,    28,    54,
      92,    56,   171,   228,   229,    32,    49,    58,   175,   171,
      22,   139,   140,    59,   127,   115,   242,   243,   126,    41,
      50,    45,    94,   150,   151,   152,    41,    25,   176,   177,
      39,   179,   180,   181,   182,   183,    48,    50,    51,    29,
      55,    93,    57,    45,   168,   247,    31,   118,   119,   120,
     121,   122,   123,   124,   125,    33,   219,   204,   127,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      26,    13,    14,   146,   147,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    26,    13,    14,   128,
     217,   220,    37,   127,   223,   251,   218,   127,   129,   206,
     127,   174,   208,   211,   212,    34,   214,   225,   130,   131,
     132,   133,   134,   127,   236,   227,   148,   149,   230,   226,
     127,    35,   141,   142,   143,   144,   145,    36,   241,   199,
     200,   201,    52,   127,   190,   191,   192,   193,   194,   172,
     127,   153,   154,    50,   253,   254,    44,   171,   155,   117,
     171,   156,   135,   209,   136,   157,   215,   127,   137,   158,
     237,   238,   138,   211,   211,   159,   231,   188,   189,   195,
     196,   165,   197,   198,   160,   161,   211,   211,   202,   245,
     162,   252,   164,    15,    16,    95,   255,    96,    97,    98,
     166,    99,   -60,   -60,   100,   101,   102,    60,    61,    62,
      54,   169,    63,    64,    65,    66,    67,    68,    69,   207,
     213,   216,   221,   224,   222,   233,   232,   234,   235,   249,
     250,    30,    70,   244,   116,   246,    71,    53,   248,    72,
      73,   185,   178,     0,   186,   184,     0,    74,    75,    76,
       0,    55,   -60,     0,   187,   103,    15,    16,    95,     0,
      96,    97,    98,     0,    99,   -59,   -59,   100,   101,   102,
      60,    61,    62,    54,     0,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    70,     0,     0,     0,    71,
       0,     0,    72,    73,     0,     0,     0,     0,     0,     0,
      74,    75,    76,     0,    55,   -59,     0,     0,   103,    15,
      16,    95,     0,    96,    97,    98,     0,    99,     0,     0,
     100,   101,   102,    60,    61,    62,    54,     0,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,     0,
       0,     0,    71,     0,     0,    72,    73,     0,     0,     0,
       0,     0,     0,    74,    75,    76,     0,    55,   113,     0,
       0,   103,    15,    16,    95,     0,    96,    97,    98,     0,
      99,     0,     0,   100,   101,   102,    60,    61,    62,    54,
     170,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    70,     0,     0,     0,    71,     0,     0,    72,    73,
       0,     0,     0,     0,     0,     0,    74,    75,    76,     0,
      55,    15,    16,    95,   103,    96,    97,    98,     0,    99,
       0,     0,   100,   101,   102,    60,    61,    62,    54,     0,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    71,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,    74,    75,    76,     0,    55,
     173,     0,     0,   103,    15,    16,    95,     0,    96,    97,
      98,     0,    99,     0,     0,   100,   101,   102,    60,    61,
      62,    54,     0,    63,    64,    65,    66,    67,    68,    69,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    70,     0,     0,     0,    71,     0,     0,
      72,    73,     0,    15,    16,     0,     0,     0,    74,    75,
      76,     0,    55,     0,     0,     0,   103,    60,    61,    62,
       0,     0,    63,    64,    65,    66,    67,    68,    69,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    70,     0,     0,     0,    71,     0,     0,    72,
      73,     0,     0,     0,     0,     0,     0,    74,    75,    76,
       0,    60,    61,    62,     0,   -65,    63,    64,    65,    66,
      67,    68,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    70,     0,     0,     0,
      71,     0,     0,    72,    73,     0,     0,     0,     0,     0,
       0,    74,    75,    76,     0,    60,    61,    62,     0,   167,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      70,     0,     0,     0,    71,     0,     0,    72,    73,     0,
       0,     0,     0,     0,     0,    74,    75,    76,   203,    60,
      61,    62,     0,     0,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    70,     0,     0,     0,    71,     0,
       0,    72,    73,     0,     0,     0,     0,     0,     0,    74,
      75,    76,     1,     2,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    26,
      13,    14
};

static const yytype_int16 yycheck[] =
{
      55,    49,     0,    98,    36,    26,    27,    13,    14,    34,
      37,    44,   107,   221,   222,    21,    46,    74,    74,   114,
      18,    47,    48,    80,    80,    58,   234,   235,    76,    35,
      77,    37,    79,    43,    44,    45,    42,    36,   127,   128,
      72,   130,   131,   132,   133,   134,    39,    77,    41,     0,
      75,    78,    45,    59,   102,    76,    36,    68,    69,    70,
      71,    72,    73,    74,    75,    79,    78,   156,    80,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    61,    62,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    46,
      74,    74,    73,    80,    74,    82,    80,    80,    55,   157,
      80,   117,   160,   161,   162,    79,   164,    74,    65,    66,
      67,    68,    69,    80,    74,   220,    41,    42,   223,   218,
      80,    75,    49,    50,    51,    52,    53,    36,   233,   150,
     151,   152,    76,    80,   141,   142,   143,   144,   145,    79,
      80,    63,    64,    77,   249,   250,    74,   252,    70,    73,
     255,    73,    54,   161,    58,    77,    79,    80,    59,    81,
      26,    27,    57,   221,   222,    78,   224,   139,   140,   146,
     147,    79,   148,   149,    73,    73,   234,   235,    36,   237,
      73,   246,    73,    17,    18,    19,   251,    21,    22,    23,
      79,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    79,    36,    37,    38,    39,    40,    41,    42,    36,
      24,    74,    79,    73,    79,    20,    75,    79,    79,    74,
      74,    18,    56,    79,    59,    82,    60,    42,   239,    63,
      64,   136,   129,    -1,   137,   135,    -1,    71,    72,    73,
      -1,    75,    76,    -1,   138,    79,    17,    18,    19,    -1,
      21,    22,    23,    -1,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,
      -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    73,    -1,    75,    76,    -1,    -1,    79,    17,
      18,    19,    -1,    21,    22,    23,    -1,    25,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,
      -1,    -1,    60,    -1,    -1,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    71,    72,    73,    -1,    75,    76,    -1,
      -1,    79,    17,    18,    19,    -1,    21,    22,    23,    -1,
      25,    -1,    -1,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56,    -1,    -1,    -1,    60,    -1,    -1,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,
      75,    17,    18,    19,    79,    21,    22,    23,    -1,    25,
      -1,    -1,    28,    29,    30,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    -1,    75,
      76,    -1,    -1,    79,    17,    18,    19,    -1,    21,    22,
      23,    -1,    25,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    -1,    -1,
      63,    64,    -1,    17,    18,    -1,    -1,    -1,    71,    72,
      73,    -1,    75,    -1,    -1,    -1,    79,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    -1,    -1,    -1,    60,    -1,    -1,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,    73,
      -1,    31,    32,    33,    -1,    79,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,
      60,    -1,    -1,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    71,    72,    73,    -1,    31,    32,    33,    -1,    79,
      36,    37,    38,    39,    40,    41,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      56,    -1,    -1,    -1,    60,    -1,    -1,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    71,    72,    73,    74,    31,
      32,    33,    -1,    -1,    36,    37,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    -1,    60,    -1,
      -1,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    87,    88,    89,
      90,    91,    92,    94,    97,    36,    14,    90,    90,     0,
      89,    36,    90,    79,    79,    75,    36,    73,    36,    72,
      93,    90,    98,    99,    74,    90,    95,    96,    93,    46,
      77,    93,    76,    99,    34,    75,   101,    93,    74,    80,
      31,    32,    33,    36,    37,    38,    39,    40,    41,    42,
      56,    60,    63,    64,    71,    72,    73,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    37,    78,    79,    19,    21,    22,    23,    25,
      28,    29,    30,    79,    92,   100,   101,   102,   103,   104,
     107,   109,   110,    76,   102,   101,    96,    73,   122,   122,
     122,   122,   122,   122,   122,   122,   110,    80,    46,    55,
      65,    66,    67,    68,    69,    54,    58,    59,    57,    47,
      48,    49,    50,    51,    52,    53,    61,    62,    41,    42,
      43,    44,    45,    63,    64,    70,    73,    77,    81,    78,
      73,    73,    73,   100,    73,    79,    79,    79,   110,    79,
      35,   100,    79,    76,    90,    74,   111,   111,   113,   111,
     111,   111,   111,   111,   114,   115,   116,   117,   118,   118,
     119,   119,   119,   119,   119,   120,   120,   121,   121,   122,
     122,   122,    36,    74,   111,   125,   110,    36,   110,    92,
     108,   110,   110,    24,   110,    79,    74,    74,    80,    78,
      74,    79,    79,    74,    73,    74,   111,   100,   108,   108,
     100,   110,    75,    20,    79,    79,    74,    26,    27,   105,
     106,   100,   108,   108,    79,   110,    82,    76,   106,    74,
      74,    82,   102,   100,   100,   102
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
      
/* Line 1267 of yacc.c.  */
#line 1845 "kernalex.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 325 "kernalex.y"


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

