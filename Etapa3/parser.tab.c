/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 2 "parser.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
	#include "ast.c"
    #include "hash.h"
	//#include "main.c"
    void yyerror(char *msg);
	extern AST *astCreate(int type, hash* symbol, AST *son0, AST *son1, AST *son2, AST *son3);
extern void printAST_NODE(AST *node);

/* Line 371 of yacc.c  */
#line 80 "parser.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     KW_CHAR = 258,
     KW_INT = 259,
     KW_FLOAT = 260,
     KW_IF = 261,
     KW_THEN = 262,
     KW_ELSE = 263,
     KW_WHILE = 264,
     KW_FOR = 265,
     KW_TO = 266,
     KW_READ = 267,
     KW_RETURN = 268,
     KW_PRINT = 269,
     OPERATOR_LE = 270,
     OPERATOR_GE = 271,
     OPERATOR_EQ = 272,
     OPERATOR_NE = 273,
     OPERATOR_AND = 274,
     OPERATOR_OR = 275,
     TK_IDENTIFIER = 276,
     LIT_INTEGER = 277,
     LIT_REAL = 278,
     LIT_CHAR = 279,
     LIT_STRING = 280,
     TOKEN_ERROR = 281,
     IDENTF = 282,
     IFELSE = 283
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "parser.y"

	AST *ast;
	hash * symbol;
	int value;
	char *string;


/* Line 387 of yacc.c  */
#line 159 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 187 "parser.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   330

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  71
/* YYNRULES -- Number of states.  */
#define YYNSTATES  146

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    45,     2,     2,    46,     2,
      36,    37,    32,    31,    38,    30,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    41,
      27,    42,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      25,    26,    34,    35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,     9,    11,    13,    20,    23,
      24,    28,    29,    32,    36,    39,    43,    44,    48,    55,
      57,    60,    63,    66,    68,    72,    73,    76,    79,    80,
      82,    84,    91,   100,   106,   116,   120,   122,   127,   132,
     134,   136,   138,   142,   146,   150,   154,   158,   162,   165,
     169,   173,   177,   181,   185,   189,   192,   195,   198,   202,
     203,   209,   216,   225,   232,   234,   236,   238,   240,   242,
     244,   247
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    50,    -1,    51,    50,    -1,    -1,    67,
      -1,    52,    -1,    68,    21,    36,    53,    37,    56,    -1,
      55,    54,    -1,    -1,    38,    55,    54,    -1,    -1,    68,
      21,    -1,    39,    57,    40,    -1,    59,    58,    -1,    41,
      59,    58,    -1,    -1,    21,    42,    64,    -1,    21,    43,
      64,    44,    42,    64,    -1,    63,    -1,    12,    21,    -1,
      14,    60,    -1,    13,    64,    -1,    56,    -1,    21,    17,
      64,    -1,    -1,    62,    61,    -1,    62,    61,    -1,    -1,
      25,    -1,    64,    -1,     6,    36,    64,    37,     7,    59,
      -1,     6,    36,    64,    37,     7,    59,     8,    59,    -1,
       9,    36,    64,    37,    59,    -1,    10,    36,    21,    42,
      64,    11,    64,    37,    59,    -1,    36,    64,    37,    -1,
      21,    -1,    21,    43,    64,    44,    -1,    21,    36,    65,
      37,    -1,    22,    -1,    24,    -1,    23,    -1,    64,    32,
      64,    -1,    64,    31,    64,    -1,    64,    30,    64,    -1,
      64,    33,    64,    -1,    64,    27,    64,    -1,    64,    28,
      64,    -1,    29,    64,    -1,    64,    15,    64,    -1,    64,
      16,    64,    -1,    64,    17,    64,    -1,    64,    18,    64,
      -1,    64,    19,    64,    -1,    64,    20,    64,    -1,    45,
      21,    -1,    46,    21,    -1,    64,    66,    -1,    38,    64,
      66,    -1,    -1,    68,    21,    42,    69,    41,    -1,    68,
      21,    43,    64,    44,    41,    -1,    68,    21,    43,    64,
      44,    47,    70,    41,    -1,    68,    45,    21,    42,    69,
      41,    -1,     3,    -1,     5,    -1,     4,    -1,    24,    -1,
      22,    -1,    23,    -1,    69,    70,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    99,   100,   103,   104,   110,   113,   114,
     117,   118,   121,   127,   130,   133,   134,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   150,   152,   153,   156,
     157,   162,   163,   164,   165,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   193,   196,   197,
     204,   205,   206,   207,   210,   211,   212,   215,   216,   217,
     220,   221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "KW_CHAR", "KW_INT", "KW_FLOAT", "KW_IF",
  "KW_THEN", "KW_ELSE", "KW_WHILE", "KW_FOR", "KW_TO", "KW_READ",
  "KW_RETURN", "KW_PRINT", "OPERATOR_LE", "OPERATOR_GE", "OPERATOR_EQ",
  "OPERATOR_NE", "OPERATOR_AND", "OPERATOR_OR", "TK_IDENTIFIER",
  "LIT_INTEGER", "LIT_REAL", "LIT_CHAR", "LIT_STRING", "TOKEN_ERROR",
  "'<'", "'>'", "'!'", "'-'", "'+'", "'*'", "'/'", "IDENTF", "IFELSE",
  "'('", "')'", "','", "'{'", "'}'", "';'", "'='", "'['", "']'", "'#'",
  "'&'", "':'", "$accept", "program", "declist", "dec", "FUNCT",
  "LISTPARAM", "RESTPARAM", "PARAM", "BODY", "BLCCOMAND", "RESTCOMAND",
  "COMAND", "LISTPRINT", "RESTELEMENT", "ELEMENT", "CONTROLFL", "EXPRES",
  "LSTARG", "RESTARG", "DECL", "TYPE", "INILIT", "RESTINILIT", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,    60,    62,    33,
      45,    43,    42,    47,   282,   283,    40,    41,    44,   123,
     125,    59,    61,    91,    93,    35,    38,    58
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    53,    53,
      54,    54,    55,    56,    57,    58,    58,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    66,    66,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    69,
      70,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     1,     1,     6,     2,     0,
       3,     0,     2,     3,     2,     3,     0,     3,     6,     1,
       2,     2,     2,     1,     3,     0,     2,     2,     0,     1,
       1,     6,     8,     5,     9,     3,     1,     4,     4,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     2,     2,     2,     3,     0,
       5,     6,     8,     6,     1,     1,     1,     1,     1,     1,
       2,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    64,    66,    65,     0,     2,     4,     6,     5,     0,
       1,     3,     0,     0,     9,     0,     0,     0,     0,    11,
       0,    68,    69,    67,     0,    36,    39,    41,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     8,    12,    60,
       0,     0,    48,     0,    55,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     7,    11,    59,     0,     0,    35,    49,    50,    51,
      52,    53,    54,    46,    47,    44,    43,    42,    45,    61,
      71,    63,     0,     0,     0,     0,     0,     0,     0,    23,
       0,    16,    19,    10,     0,    57,    38,    37,    71,     0,
       0,     0,     0,    20,    22,    29,    21,    28,    30,     0,
       0,     0,    13,    25,    14,    59,    70,    62,     0,     0,
       0,    26,    28,    24,    17,     0,    16,    58,     0,    25,
       0,    27,     0,    15,    25,    33,     0,     0,    31,     0,
      18,    25,     0,    32,    25,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,    18,    37,    19,    89,    90,
     114,    91,   106,   121,   122,    92,   108,    64,    95,     8,
       9,    98,    99
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
       2,   -88,   -88,   -88,    10,   -88,     2,   -88,   -88,     1,
     -88,   -88,   -34,    -4,     2,    87,   133,   -21,     7,    20,
      38,   -88,   -88,   -88,    26,   -32,   -88,   -88,   -88,   133,
     133,    55,    58,    33,    87,    43,     2,   -88,   -88,   -88,
     133,   133,    75,   179,   -88,   -88,   133,   133,   133,   133,
     133,   133,   133,   133,   133,   133,   133,   133,    34,    39,
       6,   -88,    20,   155,    46,    71,   -88,    41,    41,    41,
      41,   297,   297,    75,    75,    23,    23,   -88,   -88,   -88,
      87,   -88,    56,    60,    61,    79,   133,   122,   -14,   -88,
      72,    76,   -88,   -88,   133,   -88,   -88,   -88,    87,    77,
     133,   133,    92,   -88,   290,   -88,   -88,   122,   290,   133,
     133,   133,   -88,     6,   -88,   155,   -88,   -88,   202,   225,
      74,   -88,   122,   290,   290,   109,    76,   -88,   112,     6,
     133,   -88,    78,   -88,     6,   -88,   248,   133,   114,   133,
     290,     6,   267,   -88,     6,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   124,   -88,   -88,   -88,    69,    96,    98,   -88,
       8,   -87,   -88,    13,    51,   -88,   -16,   -88,    35,   -88,
     -13,    28,    50
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      33,    20,    14,   109,    40,     1,     2,     3,    15,    16,
      10,    41,    82,    42,    43,    83,    84,    17,    85,    86,
      87,    34,    12,    20,    63,    65,   126,    88,   110,   111,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,   135,    24,    35,    60,    13,   138,    46,    47,
      48,    49,    50,    51,   143,    56,    57,   145,    36,    38,
      52,    53,    59,    54,    55,    56,    57,    39,    52,    53,
     104,    54,    55,    56,    57,    79,    44,    58,   115,    45,
      81,    80,    60,    96,   118,   119,    46,    47,    48,    49,
      50,    51,   100,   123,   124,   125,   101,   102,    52,    53,
     103,    54,    55,    56,    57,    54,    55,    56,    57,    21,
      22,    23,   112,   120,   136,    97,   130,   113,   117,   134,
     137,   140,   141,   142,    46,    47,    48,    49,    50,    51,
      11,    93,    62,    61,   133,   131,    52,    53,   107,    54,
      55,    56,    57,    25,    26,    27,    28,   105,   116,     0,
     127,    29,     0,   132,    25,    26,    27,    28,    30,     0,
       0,     0,    29,     0,     0,     0,     0,    31,    32,    30,
      46,    47,    48,    49,    50,    51,     0,     0,    31,    32,
       0,     0,    52,    53,     0,    54,    55,    56,    57,     0,
       0,     0,     0,    94,    46,    47,    48,    49,    50,    51,
       0,     0,     0,     0,     0,     0,    52,    53,     0,    54,
      55,    56,    57,     0,     0,     0,    66,    46,    47,    48,
      49,    50,    51,     0,     0,     0,     0,     0,     0,    52,
      53,     0,    54,    55,    56,    57,     0,     0,     0,   128,
      46,    47,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,    52,    53,     0,    54,    55,    56,    57,   139,
       0,     0,   129,    46,    47,    48,    49,    50,    51,     0,
       0,     0,     0,     0,     0,    52,    53,     0,    54,    55,
      56,    57,    46,    47,    48,    49,    50,    51,     0,     0,
       0,     0,     0,     0,    52,    53,     0,    54,    55,    56,
      57,     0,     0,     0,   144,    46,    47,    48,    49,    50,
      51,     0,    46,    47,    48,    49,     0,    52,    53,     0,
      54,    55,    56,    57,    52,    53,     0,    54,    55,    56,
      57
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      16,    14,    36,    17,    36,     3,     4,     5,    42,    43,
       0,    43,     6,    29,    30,     9,    10,    21,    12,    13,
      14,    42,    21,    36,    40,    41,   113,    21,    42,    43,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,   129,    15,    37,    39,    45,   134,    15,    16,
      17,    18,    19,    20,   141,    32,    33,   144,    38,    21,
      27,    28,    34,    30,    31,    32,    33,    41,    27,    28,
      86,    30,    31,    32,    33,    41,    21,    44,    94,    21,
      41,    47,    39,    37,   100,   101,    15,    16,    17,    18,
      19,    20,    36,   109,   110,   111,    36,    36,    27,    28,
      21,    30,    31,    32,    33,    30,    31,    32,    33,    22,
      23,    24,    40,    21,   130,    44,    42,    41,    41,     7,
      42,   137,     8,   139,    15,    16,    17,    18,    19,    20,
       6,    62,    36,    35,   126,   122,    27,    28,    87,    30,
      31,    32,    33,    21,    22,    23,    24,    25,    98,    -1,
     115,    29,    -1,    44,    21,    22,    23,    24,    36,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    45,    46,    36,
      15,    16,    17,    18,    19,    20,    -1,    -1,    45,    46,
      -1,    -1,    27,    28,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    -1,    38,    15,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,
      31,    32,    33,    -1,    -1,    -1,    37,    15,    16,    17,
      18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    27,
      28,    -1,    30,    31,    32,    33,    -1,    -1,    -1,    37,
      15,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    30,    31,    32,    33,    11,
      -1,    -1,    37,    15,    16,    17,    18,    19,    20,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,
      32,    33,    15,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    -1,    30,    31,    32,
      33,    -1,    -1,    -1,    37,    15,    16,    17,    18,    19,
      20,    -1,    15,    16,    17,    18,    -1,    27,    28,    -1,
      30,    31,    32,    33,    27,    28,    -1,    30,    31,    32,
      33
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    49,    50,    51,    52,    67,    68,
       0,    50,    21,    45,    36,    42,    43,    21,    53,    55,
      68,    22,    23,    24,    69,    21,    22,    23,    24,    29,
      36,    45,    46,    64,    42,    37,    38,    54,    21,    41,
      36,    43,    64,    64,    21,    21,    15,    16,    17,    18,
      19,    20,    27,    28,    30,    31,    32,    33,    44,    69,
      39,    56,    55,    64,    65,    64,    37,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    41,
      47,    41,     6,     9,    10,    12,    13,    14,    21,    56,
      57,    59,    63,    54,    38,    66,    37,    44,    69,    70,
      36,    36,    36,    21,    64,    25,    60,    62,    64,    17,
      42,    43,    40,    41,    58,    64,    70,    41,    64,    64,
      21,    61,    62,    64,    64,    64,    59,    66,    37,    37,
      42,    61,    44,    58,     7,    59,    64,    42,    59,    11,
      64,     8,    64,    59,    37,    59
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
/* Line 1792 of yacc.c  */
#line 96 "parser.y"
    {printAST_NODE((yyvsp[(1) - (1)].ast));}
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 99 "parser.y"
    {(yyval.ast) = astCreate(AST_LISTLINE,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 100 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 110 "parser.y"
    {(yyval.ast) = astCreate(AST_FUND,(yyvsp[(2) - (6)].symbol),(yyvsp[(1) - (6)].ast),(yyvsp[(4) - (6)].ast),(yyvsp[(6) - (6)].ast),0);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 113 "parser.y"
    {(yyval.ast) = astCreate(AST_LIST,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 114 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 117 "parser.y"
    {(yyval.ast) = astCreate(AST_REST,0,(yyvsp[(2) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 118 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 121 "parser.y"
    {(yyval.ast) = astCreate(AST_PARAM,(yyvsp[(2) - (2)].symbol),(yyvsp[(1) - (2)].ast),0,0,0);}
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 127 "parser.y"
    {(yyval.ast) = astCreate(AST_BLCOM,0,(yyvsp[(2) - (3)].ast),0,0,0);}
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 130 "parser.y"
    {(yyval.ast) = astCreate(AST_LISTLINE,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 133 "parser.y"
    {(yyval.ast) = astCreate(AST_RESTLINE,0,(yyvsp[(2) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 134 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 139 "parser.y"
    {(yyval.ast) = astCreate(AST_ATR,(yyvsp[(1) - (3)].symbol),(yyvsp[(3) - (3)].ast),0,0,0);}
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 140 "parser.y"
    {(yyval.ast) = astCreate(AST_ATRVEC,(yyvsp[(1) - (6)].symbol),(yyvsp[(3) - (6)].ast),(yyvsp[(6) - (6)].ast),0,0);}
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 141 "parser.y"
    {}
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 142 "parser.y"
    {(yyval.ast) = astCreate(AST_READ,(yyvsp[(2) - (2)].symbol),0,0,0,0);}
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 143 "parser.y"
    {(yyval.ast) = astCreate(AST_PRI,0,(yyvsp[(2) - (2)].ast),0,0,0);}
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 144 "parser.y"
    {(yyval.ast) = astCreate(AST_RET,0,(yyvsp[(2) - (2)].ast),0,0,0);}
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 146 "parser.y"
    {(yyval.ast) = astCreate(AST_COMPARE,(yyvsp[(1) - (3)].symbol),(yyvsp[(3) - (3)].ast),0,0,0);}
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 147 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 150 "parser.y"
    {(yyval.ast) = astCreate(AST_LIST,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 152 "parser.y"
    {(yyval.ast) = astCreate(AST_LIST,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 153 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 156 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 162 "parser.y"
    {(yyval.ast) = astCreate(AST_IF,0,(yyvsp[(3) - (6)].ast),(yyvsp[(6) - (6)].ast),0,0);}
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 163 "parser.y"
    {(yyval.ast) = astCreate(AST_IFE,0,(yyvsp[(3) - (8)].ast),(yyvsp[(6) - (8)].ast),(yyvsp[(8) - (8)].ast),0);}
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 164 "parser.y"
    {(yyval.ast) = astCreate(AST_WHI,0,(yyvsp[(3) - (5)].ast),(yyvsp[(5) - (5)].ast),0,0);}
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 165 "parser.y"
    {(yyval.ast) = astCreate(AST_FOR,(yyvsp[(3) - (9)].symbol),(yyvsp[(5) - (9)].ast),(yyvsp[(7) - (9)].ast),(yyvsp[(9) - (9)].ast),0);}
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 169 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOLPAR,0,(yyvsp[(2) - (3)].ast),0,0,0);}
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 170 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 171 "parser.y"
    {(yyval.ast) = astCreate(AST_VEC,(yyvsp[(1) - (4)].symbol),(yyvsp[(3) - (4)].ast),0,0,0);}
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 172 "parser.y"
    {(yyval.ast) = astCreate(AST_FUN,(yyvsp[(1) - (4)].symbol),(yyvsp[(3) - (4)].ast),0,0,0);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 173 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 174 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 175 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 176 "parser.y"
    {(yyval.ast) = astCreate(AST_MUL,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 177 "parser.y"
    {(yyval.ast) = astCreate(AST_ADD,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 178 "parser.y"
    {(yyval.ast) = astCreate(AST_SUB,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 179 "parser.y"
    {(yyval.ast) = astCreate(AST_DIV,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 180 "parser.y"
    {(yyval.ast) = astCreate(AST_LES,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 181 "parser.y"
    {(yyval.ast) = astCreate(AST_GRE,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 182 "parser.y"
    {(yyval.ast) = astCreate(AST_NOT,0,(yyvsp[(2) - (2)].ast),0,0,0);}
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 183 "parser.y"
    {(yyval.ast) = astCreate(AST_LEQ,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 184 "parser.y"
    {(yyval.ast) = astCreate(AST_GEQ,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 185 "parser.y"
    {(yyval.ast) = astCreate(AST_EQU,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 186 "parser.y"
    {(yyval.ast) = astCreate(AST_NEQ,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 187 "parser.y"
    {(yyval.ast) = astCreate(AST_AND,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 188 "parser.y"
    {(yyval.ast) = astCreate(AST_OR,0,(yyvsp[(1) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 189 "parser.y"
    {(yyval.ast) = astCreate(AST_POI,(yyvsp[(2) - (2)].symbol),0,0,0,0);}
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 190 "parser.y"
    {(yyval.ast) = astCreate(AST_ADR,(yyvsp[(2) - (2)].symbol),0,0,0,0);}
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 193 "parser.y"
    {(yyval.ast) = astCreate(AST_LIST,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 196 "parser.y"
    {(yyval.ast) = astCreate(AST_REST,0,(yyvsp[(2) - (3)].ast),(yyvsp[(3) - (3)].ast),0,0);}
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 197 "parser.y"
    {(yyval.ast) = 0;}
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 204 "parser.y"
    {(yyval.ast) = astCreate(AST_DECINIT,(yyvsp[(2) - (5)].symbol),(yyvsp[(1) - (5)].ast),(yyvsp[(4) - (5)].ast),0,0);}
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 205 "parser.y"
    {(yyval.ast) = astCreate(AST_DECVEC,(yyvsp[(2) - (6)].symbol),(yyvsp[(1) - (6)].ast),(yyvsp[(4) - (6)].ast),0,0);}
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 206 "parser.y"
    {(yyval.ast) = astCreate(AST_DECVECLI,(yyvsp[(2) - (8)].symbol),(yyvsp[(1) - (8)].ast),(yyvsp[(4) - (8)].ast),(yyvsp[(7) - (8)].ast),0);}
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 207 "parser.y"
    {(yyval.ast) = astCreate(AST_DECPOIT,(yyvsp[(3) - (6)].symbol),(yyvsp[(1) - (6)].ast),(yyvsp[(5) - (6)].ast),0,0);}
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 210 "parser.y"
    {(yyval.ast) = astCreate(AST_KCHAR,0,0,0,0,0);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 211 "parser.y"
    {(yyval.ast) = astCreate(AST_KFLOAT,0,0,0,0,0);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 212 "parser.y"
    {(yyval.ast) = astCreate(AST_KINT,0,0,0,0,0);}
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 215 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 216 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 217 "parser.y"
    {(yyval.ast) = astCreate(AST_SYMBOL,(yyvsp[(1) - (1)].symbol),0,0,0,0);}
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 220 "parser.y"
    {(yyval.ast) = astCreate(AST_LINILIT,0,(yyvsp[(1) - (2)].ast),(yyvsp[(2) - (2)].ast),0,0);}
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 221 "parser.y"
    {(yyval.ast) = 0;}
    break;


/* Line 1792 of yacc.c  */
#line 1938 "parser.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 244 "parser.y"

void yyerror(char *msg)
{
    int lineNum = getLineNumber();
    fprintf(stderr, "ERRO!\n%s na linha: %i\n", msg, lineNum);
    
    exit(3);
}


