/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

/**********************************************************************************************************************************************************************************************
                                                                                        PARSER
**********************************************************************************************************************************************************************************************/

/*=============================================================================================================================================================================================
                                                C++ Libraries, Symbol Map, Code Generator, Logic Operations, Math Operations & other C++ code
=============================================================================================================================================================================================*/

#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
#include <iostream>
#include <deque>
using namespace std;

extern FILE *yyin;
long long yylex(void);

struct Value {
    bool isArray;
    bool isVariableIterator;
    bool isConstantIterator;
    bool isNumber;
    bool isVariable;
    string number;
    string variable;
    string arrayName;
    string variableIterator;
    long long constantIterator;
};

#include "SymbolMap.h"
#include "CodeGenerator.h"
#include "LogicOperations.h"
#include "MathOperations.h"

#line 105 "Parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "Parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    PIDENTIFIER = 259,
    SEMICOLON = 260,
    ASSIGN = 261,
    LEFT_SQUARE_BRACKET = 262,
    RIGHT_SQUARE_BRACKET = 263,
    VAR = 264,
    BEGIN_PROGRAM = 265,
    END = 266,
    READ = 267,
    WRITE = 268,
    ADD = 269,
    SUB = 270,
    EQUAL = 271,
    NOT_EQUAL = 272,
    LESS = 273,
    LESS_EQUAL = 274,
    GREATER = 275,
    GREATER_EQUAL = 276,
    IF = 277,
    THEN = 278,
    ELSE = 279,
    ENDIF = 280,
    WHILE = 281,
    DO = 282,
    ENDWHILE = 283,
    FOR = 284,
    FROM = 285,
    TO = 286,
    DOWNTO = 287,
    ENDFOR = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "Parser.y" /* yacc.c:355  */

    struct Value* value;
    char* string;

#line 184 "Parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "Parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   148

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  40
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  91

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    41,     2,     2,
       2,     2,    39,    37,     2,    38,     2,    40,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,    35,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    74,    75,    81,    83,    84,    86,    86,
     105,   105,   110,   111,   110,   122,   122,   182,   182,   242,
     256,   271,   271,   284,   290,   307,   308,   309,   310,   311,
     313,   314,   315,   316,   317,   318,   320,   328,   330,   347,
     374
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUM", "PIDENTIFIER", "SEMICOLON",
  "ASSIGN", "LEFT_SQUARE_BRACKET", "RIGHT_SQUARE_BRACKET", "VAR",
  "BEGIN_PROGRAM", "END", "READ", "WRITE", "ADD", "SUB", "EQUAL",
  "NOT_EQUAL", "LESS", "LESS_EQUAL", "GREATER", "GREATER_EQUAL", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "FOR", "FROM", "TO",
  "DOWNTO", "ENDFOR", "'['", "']'", "';'", "'+'", "'-'", "'*'", "'/'",
  "'%'", "$accept", "program", "vdeclarations", "commands", "command",
  "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "innerIf", "$@7", "expression",
  "condition", "value", "identifier", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,    91,    93,    59,    43,    45,    42,
      47,    37
};
# endif

#define YYPACT_NINF -38

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-38)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -38,     4,     5,   -38,   -27,   119,    21,    -3,    34,
       8,     8,   -38,    45,    96,   -38,   -38,    15,    25,    30,
     -38,    33,   -38,    28,     0,     8,    50,   -38,   -38,    66,
     -38,    48,    51,   -38,   -38,   -38,     8,     8,     8,     8,
       8,     8,    60,     8,     8,   -38,   -38,   119,   -38,   -38,
     -38,   -38,   -38,   -38,   -38,    12,    59,    52,     1,   119,
       8,     8,   -38,     8,     8,     8,     8,     8,   -38,   -38,
     -38,   107,    75,    76,   -38,   -38,   -38,   -38,   -38,   119,
     -38,   -38,   -38,    42,   119,   119,   -38,    72,    84,   -38,
     -38
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     1,     3,     0,     0,    38,     0,
       0,     0,    12,     0,     0,     7,     8,     0,     0,     0,
      36,     0,    37,     0,     0,     0,     0,     2,     6,     0,
       4,     0,     0,    19,    20,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    40,    39,     0,    30,    31,
      32,    34,    33,    35,    13,     0,     0,    24,     0,     0,
       0,     0,     9,     0,     0,     0,     0,     0,    21,    23,
      11,     0,     0,     0,    25,    26,    27,    28,    29,     0,
      14,    15,    17,     0,     0,     0,    22,     0,     0,    16,
      18
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -38,   -38,   -38,   -37,   -13,   -38,   -38,   -38,   -38,   -38,
     -38,   -38,   -38,   -38,    74,    -4,    -6
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    14,    15,    29,    47,    25,    59,    84,
      85,    70,    79,    56,    23,    24,    22
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    28,     1,    19,     4,     8,    21,     7,    16,     5,
      58,    20,     8,     9,    10,     6,    36,    37,    38,    39,
      40,    41,    71,    11,    17,    68,    69,    12,    31,    32,
      13,    18,    48,    49,    50,    51,    52,    53,     8,    55,
      57,    16,    83,    60,    61,    28,     8,    87,    88,    26,
      30,    35,    16,    16,     9,    10,    72,    73,    28,    74,
      75,    76,    77,    78,    11,    16,    33,    86,    12,    34,
      28,    13,    44,    16,    28,    28,     8,    16,    16,    16,
      43,    16,    16,    45,     9,    10,    46,    54,     8,    63,
      64,    65,    66,    67,    11,    62,     9,    10,    12,    42,
       8,    13,    81,    82,     0,    89,    11,    27,     9,    10,
      12,     8,     0,    13,     0,     0,     0,    90,    11,     9,
      10,     0,    12,     8,     0,    13,     0,     0,     0,    11,
       0,     9,    10,    12,     0,    80,    13,     0,     0,     0,
       0,    11,     0,     0,     0,    12,     0,     0,    13
};

static const yytype_int8 yycheck[] =
{
       6,    14,     9,     9,     0,     4,    10,    34,    14,     4,
      47,     3,     4,    12,    13,    10,    16,    17,    18,    19,
      20,    21,    59,    22,     3,    24,    25,    26,     3,     4,
      29,    34,    36,    37,    38,    39,    40,    41,     4,    43,
      44,    47,    79,    31,    32,    58,     4,    84,    85,     4,
      35,    23,    58,    59,    12,    13,    60,    61,    71,    63,
      64,    65,    66,    67,    22,    71,    36,    25,    26,    36,
      83,    29,     6,    79,    87,    88,     4,    83,    84,    85,
      30,    87,    88,    35,    12,    13,    35,    27,     4,    37,
      38,    39,    40,    41,    22,    36,    12,    13,    26,    25,
       4,    29,    27,    27,    -1,    33,    22,    11,    12,    13,
      26,     4,    -1,    29,    -1,    -1,    -1,    33,    22,    12,
      13,    -1,    26,     4,    -1,    29,    -1,    -1,    -1,    22,
      -1,    12,    13,    26,    -1,    28,    29,    -1,    -1,    -1,
      -1,    22,    -1,    -1,    -1,    26,    -1,    -1,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    43,    44,     0,     4,    10,    34,     4,    12,
      13,    22,    26,    29,    45,    46,    58,     3,    34,    58,
       3,    57,    58,    56,    57,    49,     4,    11,    46,    47,
      35,     3,     4,    36,    36,    23,    16,    17,    18,    19,
      20,    21,    56,    30,     6,    35,    35,    48,    57,    57,
      57,    57,    57,    57,    27,    57,    55,    57,    45,    50,
      31,    32,    36,    37,    38,    39,    40,    41,    24,    25,
      53,    45,    57,    57,    57,    57,    57,    57,    57,    54,
      28,    27,    27,    45,    51,    52,    25,    45,    45,    33,
      33
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    44,    44,    44,    45,    45,    47,    46,
      48,    46,    49,    50,    46,    51,    46,    52,    46,    46,
      46,    54,    53,    53,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    57,    57,    58,    58,
      58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     2,     5,     0,     2,     1,     0,     5,
       0,     6,     0,     0,     7,     0,    10,     0,    10,     3,
       3,     0,     4,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     4,
       4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
        case 2:
#line 69 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                                            generateCode("HALT"); 
                                                                                                            printCode(); 
                                                                                                        }
#line 1352 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 3:
#line 74 "Parser.y" /* yacc.c:1661  */
    {   installIdentifier((yyvsp[0].string));          }
#line 1358 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 4:
#line 75 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                                            string arrayName = strcat(strdup("ARRAY"),(yyvsp[-3].string));
                                                                                                            installArray(arrayName, stoll((yyvsp[-1].string)));    
                                                                                                            loadNumber(getSymbol(arrayName) + 1);
                                                                                                            generateCodeAtAddress("STORE", getSymbol(arrayName));
                                                                                                        }
#line 1369 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 8:
#line 86 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        if ((yyvsp[0].value)->isArray == true){
                                                                                            if(arrayExists((yyvsp[0].value)->arrayName)){
                                                                                                loadArray((yyvsp[0].value));
                                                                                                generateCodeAtAddress("STORE",0);
                                                                                            }
                                                                                        }
                                                                                    }
#line 1382 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 9:
#line 94 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        if ((yyvsp[-4].value)->isArray == true){
                                                                                            if (arrayExists((yyvsp[-4].value)->arrayName))
                                                                                                generateCodeAtAddress("STOREI",0);
                                                                                        }
                                                                                        else if ((yyvsp[-4].value)->isVariable == true){
                                                                                            checkContext("STORE", (yyvsp[-4].value)->variable);
                                                                                            if (symbolExists((yyvsp[-4].value)->variable))
                                                                                                assignSymbol((yyvsp[-4].value)->variable);
                                                                                        }
                                                                                    }
#line 1398 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 10:
#line 105 "Parser.y" /* yacc.c:1661  */
    { 
                                                                                        pushOnIntStack();
                                                                                        generateCode("JZERO ?");
                                                                                    }
#line 1407 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 12:
#line 110 "Parser.y" /* yacc.c:1661  */
    {   pushOnWhileStack(); }
#line 1413 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 13:
#line 111 "Parser.y" /* yacc.c:1661  */
    { 
                                                                                        pushOnWhileStack();
                                                                                        generateCode("JZERO ?");
                                                                                    }
#line 1422 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 14:
#line 115 "Parser.y" /* yacc.c:1661  */
    { 
                                                                                        int index  = popFromWhileStack();
                                                                                        int endLine = getNumberOfAsmInstructions()+1;
                                                                                        changeCodeAtLine("JZERO " + to_string(endLine), index);
                                                                                        int conditionLine = popFromWhileStack();
                                                                                        generateCodeAtAddress("JUMP", conditionLine);
                                                                                    }
#line 1434 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 15:
#line 122 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                        installIdentifier((yyvsp[-5].string));
                                                                                        string endFor = strcat(strdup("KONIECFOR"),(yyvsp[-5].string));
                                                                                        installIdentifier(endFor);
                                                                                        
                                                                                        if((yyvsp[-3].value)->isNumber == true)
                                                                                            loadNumber(stoll((yyvsp[-3].value)->number));
                                                                                        else if((yyvsp[-3].value)->isVariable == true){
                                                                                            checkIfSymbolIsAssigned((yyvsp[-3].value)->variable);
                                                                                            if (wasAssigned((yyvsp[-3].value)->variable)){
                                                                                                checkContext("LOAD", (yyvsp[-3].value)->variable);
                                                                                            }
                                                                                        }
                                                                                        else if((yyvsp[-3].value)->isArray == true){
                                                                                            loadArray((yyvsp[-3].value));
                                                                                            generateCodeAtAddress("STORE",0);
                                                                                            generateCodeAtAddress("LOADI",0);
                                                                                        }
                                                                                        checkContext("STORE", (yyvsp[-5].string));
                                                                                        assignSymbol((yyvsp[-5].string));
                                                                                        
                                                                                        if((yyvsp[-1].value)->isNumber == true)
                                                                                            loadNumber(stoll((yyvsp[-1].value)->number));
                                                                                        else if((yyvsp[-1].value)->isVariable == true){
                                                                                            checkIfSymbolIsAssigned((yyvsp[-1].value)->variable);
                                                                                            if (wasAssigned((yyvsp[-1].value)->variable)){
                                                                                                checkContext("LOAD", (yyvsp[-1].value)->variable);
                                                                                            }
                                                                                        }
                                                                                        else if((yyvsp[-1].value)->isArray == true){
                                                                                            loadArray((yyvsp[-1].value));
                                                                                            generateCodeAtAddress("STORE",0);
                                                                                            generateCodeAtAddress("LOADI",0);
                                                                                        }
                                                                                        generateCode("INC");
                                                                                        checkContext("SUB", (yyvsp[-5].string));
                                                                                        checkContext("STORE", endFor);
                                                                                        
                                                                                        pushOnForStack();
                                                                                        checkContext("LOAD", endFor);
                                                                                        pushOnForStack();
                                                                                        generateCode("JZERO ?");
                                                                                    }
#line 1482 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 16:
#line 165 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                        
                                                                                        checkContext("LOAD", strcat(strdup("KONIECFOR"),(yyvsp[-8].string)));
                                                                                        generateCode("DEC");
                                                                                        checkContext("STORE", strcat(strdup("KONIECFOR"),(yyvsp[-8].string)));
                                                                                        checkContext("LOAD", (yyvsp[-8].string));
                                                                                        generateCode("INC");
                                                                                        checkContext("STORE", (yyvsp[-8].string));
                                                                                        
                                                                                        int index  = popFromForStack();
                                                                                        int endLine = getNumberOfAsmInstructions()+1;
                                                                                        changeCodeAtLine("JZERO " + to_string(endLine), index);
                                                                                        int conditionLine = popFromForStack();
                                                                                        generateCodeAtAddress("JUMP", conditionLine);
                                                                                        deleteSymbol((yyvsp[-8].string));
                                                                                        deleteSymbol(strcat(strdup("KONIECFOR"),(yyvsp[-8].string)));
                                                                                    }
#line 1504 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 17:
#line 182 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        installIdentifier((yyvsp[-5].string));
                                                                                        string endFor = strcat(strdup("KONIECFOR"),(yyvsp[-5].string));
                                                                                        installIdentifier(endFor);
                                                                                        
                                                                                        if((yyvsp[-3].value)->isNumber == true)
                                                                                            loadNumber(stoll((yyvsp[-3].value)->number));
                                                                                        else if((yyvsp[-3].value)->isVariable == true){
                                                                                            checkIfSymbolIsAssigned((yyvsp[-3].value)->variable);
                                                                                            if (wasAssigned((yyvsp[-3].value)->variable)){
                                                                                                checkContext("LOAD", (yyvsp[-3].value)->variable);
                                                                                            }
                                                                                        }
                                                                                        else if((yyvsp[-3].value)->isArray == true){
                                                                                            loadArray((yyvsp[-3].value));
                                                                                            generateCodeAtAddress("STORE",0);
                                                                                            generateCodeAtAddress("LOADI",0);
                                                                                        }
                                                                                        checkContext("STORE", (yyvsp[-5].string));
                                                                                        assignSymbol((yyvsp[-5].string));
                                                                                        
                                                                                        if((yyvsp[-1].value)->isNumber == true)
                                                                                            loadNumber(stoll((yyvsp[-1].value)->number));
                                                                                        else if((yyvsp[-1].value)->isVariable == true){
                                                                                            checkIfSymbolIsAssigned((yyvsp[-1].value)->variable);
                                                                                            if (wasAssigned((yyvsp[-1].value)->variable)){
                                                                                                checkContext("LOAD", (yyvsp[-1].value)->variable);
                                                                                            }
                                                                                        }
                                                                                        else if((yyvsp[-1].value)->isArray == true){
                                                                                            loadArray((yyvsp[-1].value));
                                                                                            generateCodeAtAddress("STORE",0);
                                                                                            generateCodeAtAddress("LOADI",0);
                                                                                        }
                                                                                        generateCodeAtAddress("STORE",3); //ZMIANA 3
                                                                                        checkContext("LOAD", (yyvsp[-5].string));                                                                               generateCode("INC");
                                                                                        generateCodeAtAddress("SUB", 3); //ZMIANA 3
                                                                                        checkContext("STORE", endFor);
                                                                                        
                                                                                        pushOnForStack();
                                                                                        checkContext("LOAD", endFor);
                                                                                        pushOnForStack();
                                                                                        generateCode("JZERO ?");
                                                                                    }
#line 1553 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 18:
#line 226 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                        checkContext("LOAD", strcat(strdup("KONIECFOR"),(yyvsp[-8].string)));
                                                                                        generateCode("DEC");
                                                                                        checkContext("STORE", strcat(strdup("KONIECFOR"),(yyvsp[-8].string)));
                                                                                        checkContext("LOAD", (yyvsp[-8].string));
                                                                                        generateCode("DEC");
                                                                                        checkContext("STORE", (yyvsp[-8].string));
                                                                                        
                                                                                        int index  = popFromForStack();
                                                                                        int endLine = getNumberOfAsmInstructions()+1;
                                                                                        changeCodeAtLine("JZERO " + to_string(endLine), index);
                                                                                        int conditionLine = popFromForStack();
                                                                                        generateCodeAtAddress("JUMP", conditionLine);
                                                                                        deleteSymbol((yyvsp[-8].string));
                                                                                        deleteSymbol(strcat(strdup("KONIECFOR"),(yyvsp[-8].string)));
                                                                                    }
#line 1574 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 19:
#line 242 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        if((yyvsp[-1].value)->isArray == true){
                                                                                            loadArray((yyvsp[-1].value));
                                                                                            generateCodeAtAddress("STORE", 0);
                                                                                        }
                                                                                        generateCode("GET");
                                                                                        if ((yyvsp[-1].value)->isVariable == true){
                                                                                            checkContext("STORE", (yyvsp[-1].value)->variable);
                                                                                            assignSymbol((yyvsp[-1].value)->variable);
                                                                                        }
                                                                                        else if ((yyvsp[-1].value)->isArray == true){
                                                                                            generateCodeAtAddress("STOREI",0);
                                                                                        }
                                                                                    }
#line 1593 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 20:
#line 256 "Parser.y" /* yacc.c:1661  */
    { 
                                                                                        if((yyvsp[-1].value)->isVariable == true){
                                                                                            checkIfSymbolIsAssigned((yyvsp[-1].value)->variable);
                                                                                            checkContext("LOAD", (yyvsp[-1].value)->variable);
                                                                                        }
                                                                                        else if ((yyvsp[-1].value)->isNumber == true)
                                                                                            loadNumber(stoll((yyvsp[-1].value)->number));
                                                                                        else if ((yyvsp[-1].value)->isArray == true){
                                                                                            loadArray((yyvsp[-1].value));
                                                                                            generateCodeAtAddress("STORE",0);
                                                                                            generateCodeAtAddress("LOADI",0);
                                                                                        }
                                                                                        generateCode("PUT");
                                                                                    }
#line 1612 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 21:
#line 271 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        int index  = popFromIntStack();
                                                                                        pushOnIntStack();
                                                                                        generateCode("JUMP ?");
                                                                                        int actualLine = getNumberOfAsmInstructions();
                                                                                        changeCodeAtLine("JZERO " + to_string(actualLine), index);
                                                                                    }
#line 1624 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 22:
#line 279 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        int index  = popFromIntStack();
                                                                                        int actualLine = getNumberOfAsmInstructions();
                                                                                        changeCodeAtLine("JUMP " + to_string(actualLine), index);
                                                                                    }
#line 1634 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 23:
#line 284 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        int index  = popFromIntStack();
                                                                                        int actualLine = getNumberOfAsmInstructions();
                                                                                        changeCodeAtLine("JZERO " + to_string(actualLine), index);
                                                                                    }
#line 1644 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 24:
#line 290 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        if ((yyvsp[0].value)->isNumber == true)
                                                                                            loadNumber(stoll((yyvsp[0].value)->number));
                                                                                        else if ((yyvsp[0].value)->isVariable == true){
                                                                                            checkIfSymbolIsAssigned((yyvsp[0].value)->variable);
                                                                                            if (wasAssigned((yyvsp[0].value)->variable)){
                                                                                                checkContext("LOAD", (yyvsp[0].value)->variable);
                                                                                            }
                                                                                        }
                                                                                        else if ((yyvsp[0].value)->isArray == true){
                                                                                            if(arrayExists((yyvsp[0].value)->arrayName)){
                                                                                                loadArray((yyvsp[0].value));
                                                                                                generateCodeAtAddress("STORE",1);
                                                                                                generateCodeAtAddress("LOADI",1);
                                                                                            }
                                                                                        }
                                                                                    }
#line 1666 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 25:
#line 307 "Parser.y" /* yacc.c:1661  */
    {   addValues((yyvsp[-2].value), (yyvsp[0].value));      }
#line 1672 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 26:
#line 308 "Parser.y" /* yacc.c:1661  */
    {   subValues((yyvsp[-2].value), (yyvsp[0].value));      }
#line 1678 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 27:
#line 309 "Parser.y" /* yacc.c:1661  */
    {   multiplyValues((yyvsp[-2].value), (yyvsp[0].value)); }
#line 1684 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 28:
#line 310 "Parser.y" /* yacc.c:1661  */
    {   divideValues((yyvsp[-2].value), (yyvsp[0].value));   }
#line 1690 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 29:
#line 311 "Parser.y" /* yacc.c:1661  */
    {   moduloValues((yyvsp[-2].value), (yyvsp[0].value));   }
#line 1696 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 30:
#line 313 "Parser.y" /* yacc.c:1661  */
    {   equal((yyvsp[-2].value), (yyvsp[0].value));            }
#line 1702 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 31:
#line 314 "Parser.y" /* yacc.c:1661  */
    {   notEqual((yyvsp[-2].value), (yyvsp[0].value));         }
#line 1708 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 32:
#line 315 "Parser.y" /* yacc.c:1661  */
    {   lessThan((yyvsp[-2].value), (yyvsp[0].value));         }
#line 1714 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 33:
#line 316 "Parser.y" /* yacc.c:1661  */
    {   greaterThan((yyvsp[-2].value), (yyvsp[0].value));      }
#line 1720 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 34:
#line 317 "Parser.y" /* yacc.c:1661  */
    {   lessEqualThan((yyvsp[-2].value), (yyvsp[0].value));    }
#line 1726 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 35:
#line 318 "Parser.y" /* yacc.c:1661  */
    {   greaterEqualThan((yyvsp[-2].value), (yyvsp[0].value)); }
#line 1732 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 36:
#line 320 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                        Value* newValue = new Value;
                                                                                        newValue->isArray = false;
                                                                                        newValue->isVariable = false;
                                                                                        newValue->isNumber = true;
                                                                                        newValue->number = (yyvsp[0].string);
                                                                                        (yyval.value) = newValue;
                                                                                    }
#line 1745 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 38:
#line 330 "Parser.y" /* yacc.c:1661  */
    {   
                                                                                        if (symbolExists((yyvsp[0].string))){
                                                                                            Value* newValue = new Value;
                                                                                            newValue->isArray = false;
                                                                                            newValue->isVariable = true;
                                                                                            newValue->isNumber = false;
                                                                                            newValue->variable = (yyvsp[0].string);
                                                                                            (yyval.value) = newValue;
                                                                                        } else if (arrayExists(strcat(strdup("ARRAY"),(yyvsp[0].string)))){
                                                                                            
                                                                                            string errorStr = "Nieprawidłowe użycie zmiennej tablicowej!";
                                                                                            const char* error = errorStr.c_str();
                                                                                            yyerror(error);
                                                                                        } else {
                                                                                            checkIfSymbolIsDeclared((yyvsp[0].string));
                                                                                        }
                                                                                    }
#line 1767 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 39:
#line 347 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        string arrayName = strcat(strdup("ARRAY"),(yyvsp[-3].string));
                                                                                        if (arrayExists(arrayName)){
                                                                                            checkIfSymbolIsDeclared((yyvsp[-1].string));
                                                                                            checkIfSymbolIsAssigned((yyvsp[-1].string));
                                                                                            if(symbolExists((yyvsp[-1].string)) && wasAssigned((yyvsp[-1].string))){
                                                                                                Value* newValue = new Value;
                                                                                                newValue->isArray = true;
                                                                                                newValue->isVariableIterator = true;
                                                                                                newValue->isConstantIterator = false;
                                                                                                newValue->isVariable = false;
                                                                                                newValue->isNumber = false;
                                                                                                newValue->arrayName = arrayName;
                                                                                                newValue->variableIterator = (yyvsp[-1].string);
                                                                                                (yyval.value) = newValue;
                                                                                            }
                                                                                        }
                                                                                        else if (symbolExists((yyvsp[-3].string))){
                                                                                           
                                                                                            string errorStr = "Nieprawidłowe użycie zmiennej!";
                                                                                            const char* error = errorStr.c_str();
                                                                                            yyerror(error);
                                                                                        }
                                                                                        else {
                                                                                            checkIfArrayIsDeclared(arrayName);
                                                                                        }
                                                                                    }
#line 1799 "Parser.tab.c" /* yacc.c:1661  */
    break;

  case 40:
#line 374 "Parser.y" /* yacc.c:1661  */
    {
                                                                                        string arrayName = strcat(strdup("ARRAY"),(yyvsp[-3].string));
                                                                                        if (arrayExists(arrayName)){
                                                                                            Value* newValue = new Value;
                                                                                            newValue->isArray = true;
                                                                                            newValue->isVariableIterator = false;
                                                                                            newValue->isConstantIterator = true;
                                                                                            newValue->isVariable = false;
                                                                                            newValue->isNumber = false;
                                                                                            newValue->arrayName = arrayName;
                                                                                            newValue->constantIterator = stoll((yyvsp[-1].string));
                                                                                            (yyval.value) = newValue;
                                                                                        }
                                                                                        else if (symbolExists((yyvsp[-3].string))){
                                                                                        
                                                                                            string errorStr = "Nieprawidłowe użycie zmiennej!";
                                                                                            const char* error = errorStr.c_str();
                                                                                            yyerror(error);
                                                                                        }
                                                                                        else {
                                                                                            checkIfArrayIsDeclared(arrayName);
                                                                                        }
                                                                                    }
#line 1827 "Parser.tab.c" /* yacc.c:1661  */
    break;


#line 1831 "Parser.tab.c" /* yacc.c:1661  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 398 "Parser.y" /* yacc.c:1906  */


/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                            Main function
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int main(void) {
    yyparse();
}
