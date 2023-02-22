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
#line 1 "parser.y"

#include <iostream> // cerr, cout
#include "globals.h"

/* Note: C and C++ zero-initialize global variables. */
double variables[256];

/* Prototype for a function defined by flex. */
void yylex_destroy();

/* Report error messages */
void yyerror(const char *msg)
{
	std::cerr << msg << " at line " << CurrLine << ", column "
	          << CurrColumn << "\n";
}

#line 89 "parser.cc"

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

#include "parser.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_ID = 10,                        /* ID  */
  YYSYMBOL_INT_LIT = 11,                   /* INT_LIT  */
  YYSYMBOL_FP_LIT = 12,                    /* FP_LIT  */
  YYSYMBOL_CHAR_LIT = 13,                  /* CHAR_LIT  */
  YYSYMBOL_STRING_LIT = 14,                /* STRING_LIT  */
  YYSYMBOL_EQUAL = 15,                     /* EQUAL  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_STAR = 18,                      /* STAR  */
  YYSYMBOL_FORWARD_SLASH = 19,             /* FORWARD_SLASH  */
  YYSYMBOL_EQUAL_EQUAL = 20,               /* EQUAL_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 21,                 /* NOT_EQUAL  */
  YYSYMBOL_LESS_THAN = 22,                 /* LESS_THAN  */
  YYSYMBOL_LESS_THAN_OR_EQUAL = 23,        /* LESS_THAN_OR_EQUAL  */
  YYSYMBOL_GREATER_THAN = 24,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_THAN_OR_EQUAL = 25,     /* GREATER_THAN_OR_EQUAL  */
  YYSYMBOL_AND = 26,                       /* AND  */
  YYSYMBOL_OR = 27,                        /* OR  */
  YYSYMBOL_COMMA = 28,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_OPEN_PARANTHESIS = 30,          /* OPEN_PARANTHESIS  */
  YYSYMBOL_CLOSE_PARANTHESIS = 31,         /* CLOSE_PARANTHESIS  */
  YYSYMBOL_OPEN_BRACE = 32,                /* OPEN_BRACE  */
  YYSYMBOL_CLOSE_BRACE = 33,               /* CLOSE_BRACE  */
  YYSYMBOL_EMPTY_STRING = 34,              /* EMPTY_STRING  */
  YYSYMBOL_35_n_ = 35,                     /* '\n'  */
  YYSYMBOL_NO_MATCH = 36,                  /* NO_MATCH  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_program = 38,                   /* program  */
  YYSYMBOL_statementList = 39,             /* statementList  */
  YYSYMBOL_statement = 40,                 /* statement  */
  YYSYMBOL_type = 41,                      /* type  */
  YYSYMBOL_expression = 42,                /* expression  */
  YYSYMBOL_function_call = 43,             /* function_call  */
  YYSYMBOL_function_args = 44              /* function_args  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  87

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


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
      35,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    50,    50,    55,    62,    64,    68,    70,    72,    74,
      76,    78,    80,    82,    84,    89,    91,    93,    97,    99,
     101,   103,   105,   107,   109,   111,   113,   115,   117,   119,
     121,   123,   125,   127,   129,   131,   133,   135,   139,   141,
     145,   147
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
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "INT", "FLOAT", "CHAR", "ID", "INT_LIT", "FP_LIT", "CHAR_LIT",
  "STRING_LIT", "EQUAL", "PLUS", "MINUS", "STAR", "FORWARD_SLASH",
  "EQUAL_EQUAL", "NOT_EQUAL", "LESS_THAN", "LESS_THAN_OR_EQUAL",
  "GREATER_THAN", "GREATER_THAN_OR_EQUAL", "AND", "OR", "COMMA",
  "SEMICOLON", "OPEN_PARANTHESIS", "CLOSE_PARANTHESIS", "OPEN_BRACE",
  "CLOSE_BRACE", "EMPTY_STRING", "'\\n'", "NO_MATCH", "$accept", "program",
  "statementList", "statement", "type", "expression", "function_call",
  "function_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-19)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -19,     2,    34,   -19,    67,   -16,     6,    28,    29,   -19,
     -19,   -19,    30,   -19,   -19,   -19,   -19,   119,   -19,   -19,
     -19,     4,   203,   -19,   -19,   -19,   119,   119,   119,    19,
     135,    81,   -14,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   -19,   152,   169,   218,
     -19,   263,    26,   -19,   -19,   119,   -19,   263,   -11,   -11,
     -19,   -19,   286,   286,   -13,   -13,   -13,   -13,   118,   275,
     114,   114,   119,   119,   -19,   233,    57,   -19,   248,   263,
     -19,   114,   119,   -19,   186,   114,   -19
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     5,     0,     1,     0,     0,     0,     0,     0,    15,
      16,    17,    32,    33,    34,    35,    36,     0,     5,     2,
       4,     0,     0,    37,     3,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,     0,     0,     0,
      38,    40,     0,    18,     6,     0,     8,    23,    19,    20,
      21,    22,    30,    31,    26,    27,    28,    29,    24,    25,
       0,     0,     0,     0,    39,     0,    11,    10,     0,    41,
       7,     0,     0,    12,     0,     0,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,    33,   -18,   -19,   -17,   -19,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    20,    21,    22,    23,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      30,    55,     3,    34,    35,    36,    37,    36,    37,    47,
      48,    49,    51,    25,    32,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    12,
      13,    14,    15,    16,     4,     5,    26,     6,    75,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      50,    31,    76,    77,    73,    78,    79,    74,    27,    28,
      29,    81,     0,    83,    17,    84,    18,    86,     5,    19,
       6,     0,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     5,     0,     6,     0,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,    17,     0,    18,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,    17,     0,    18,    54,     5,     0,     6,     0,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    12,
      13,    14,    15,    16,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    17,     0,    18,     0,     0,    17,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,     0,     0,     0,    53,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
       0,     0,     0,    70,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,     0,     0,     0,
      71,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,     0,     0,     0,    85,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     0,    46,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    72,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,     0,    80,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    82,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    34,    35,    36,    37,     0,     0,    40,    41,
      42,    43
};

static const yytype_int8 yycheck[] =
{
      17,    15,     0,    16,    17,    18,    19,    18,    19,    26,
      27,    28,    29,    29,    10,    29,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    10,
      11,    12,    13,    14,     1,     1,    30,     3,    55,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    30,
      31,    18,    70,    71,    28,    72,    73,    31,    30,    30,
      30,     4,    -1,    81,    30,    82,    32,    85,     1,    35,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    -1,    30,    -1,    32,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    -1,    32,    33,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    10,
      11,    12,    13,    14,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    30,    -1,    32,    -1,    -1,    30,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    -1,    -1,    -1,    31,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      -1,    -1,    -1,    31,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    -1,    -1,    -1,
      31,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    -1,    -1,    -1,    31,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    29,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,    29,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    16,    17,    18,    19,    -1,    -1,    22,    23,
      24,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,    39,     1,     3,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    30,    32,    35,
      40,    41,    42,    43,    35,    29,    30,    30,    30,    30,
      42,    39,    10,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    29,    42,    42,    42,
      31,    42,    44,    31,    33,    15,    29,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      31,    31,    29,    28,    31,    42,    40,    40,    42,    42,
      29,     4,    29,    40,    42,    31,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      40,    40,    40,    40,    40,    41,    41,    41,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    43,    43,
      44,    44
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     0,     3,     5,     3,     2,
       5,     5,     7,     9,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     3,     4,
       1,     3
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
  switch (yykind)
    {
    case YYSYMBOL_IF: /* IF  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 955 "parser.cc"
        break;

    case YYSYMBOL_ELSE: /* ELSE  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 961 "parser.cc"
        break;

    case YYSYMBOL_WHILE: /* WHILE  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 967 "parser.cc"
        break;

    case YYSYMBOL_FOR: /* FOR  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 973 "parser.cc"
        break;

    case YYSYMBOL_INT: /* INT  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 979 "parser.cc"
        break;

    case YYSYMBOL_FLOAT: /* FLOAT  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 985 "parser.cc"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 991 "parser.cc"
        break;

    case YYSYMBOL_ID: /* ID  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 997 "parser.cc"
        break;

    case YYSYMBOL_INT_LIT: /* INT_LIT  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1003 "parser.cc"
        break;

    case YYSYMBOL_FP_LIT: /* FP_LIT  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1009 "parser.cc"
        break;

    case YYSYMBOL_CHAR_LIT: /* CHAR_LIT  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1015 "parser.cc"
        break;

    case YYSYMBOL_STRING_LIT: /* STRING_LIT  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1021 "parser.cc"
        break;

    case YYSYMBOL_EQUAL: /* EQUAL  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1027 "parser.cc"
        break;

    case YYSYMBOL_PLUS: /* PLUS  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1033 "parser.cc"
        break;

    case YYSYMBOL_MINUS: /* MINUS  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1039 "parser.cc"
        break;

    case YYSYMBOL_STAR: /* STAR  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1045 "parser.cc"
        break;

    case YYSYMBOL_FORWARD_SLASH: /* FORWARD_SLASH  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1051 "parser.cc"
        break;

    case YYSYMBOL_EQUAL_EQUAL: /* EQUAL_EQUAL  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1057 "parser.cc"
        break;

    case YYSYMBOL_NOT_EQUAL: /* NOT_EQUAL  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1063 "parser.cc"
        break;

    case YYSYMBOL_LESS_THAN: /* LESS_THAN  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1069 "parser.cc"
        break;

    case YYSYMBOL_LESS_THAN_OR_EQUAL: /* LESS_THAN_OR_EQUAL  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1075 "parser.cc"
        break;

    case YYSYMBOL_GREATER_THAN: /* GREATER_THAN  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1081 "parser.cc"
        break;

    case YYSYMBOL_GREATER_THAN_OR_EQUAL: /* GREATER_THAN_OR_EQUAL  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1087 "parser.cc"
        break;

    case YYSYMBOL_AND: /* AND  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1093 "parser.cc"
        break;

    case YYSYMBOL_OR: /* OR  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1099 "parser.cc"
        break;

    case YYSYMBOL_COMMA: /* COMMA  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1105 "parser.cc"
        break;

    case YYSYMBOL_SEMICOLON: /* SEMICOLON  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1111 "parser.cc"
        break;

    case YYSYMBOL_OPEN_PARANTHESIS: /* OPEN_PARANTHESIS  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1117 "parser.cc"
        break;

    case YYSYMBOL_CLOSE_PARANTHESIS: /* CLOSE_PARANTHESIS  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1123 "parser.cc"
        break;

    case YYSYMBOL_OPEN_BRACE: /* OPEN_BRACE  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1129 "parser.cc"
        break;

    case YYSYMBOL_CLOSE_BRACE: /* CLOSE_BRACE  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1135 "parser.cc"
        break;

    case YYSYMBOL_EMPTY_STRING: /* EMPTY_STRING  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1141 "parser.cc"
        break;

    case YYSYMBOL_35_n_: /* '\n'  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1147 "parser.cc"
        break;

    case YYSYMBOL_NO_MATCH: /* NO_MATCH  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1153 "parser.cc"
        break;

    case YYSYMBOL_program: /* program  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1159 "parser.cc"
        break;

    case YYSYMBOL_statementList: /* statementList  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1165 "parser.cc"
        break;

    case YYSYMBOL_statement: /* statement  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1171 "parser.cc"
        break;

    case YYSYMBOL_type: /* type  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1177 "parser.cc"
        break;

    case YYSYMBOL_expression: /* expression  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1183 "parser.cc"
        break;

    case YYSYMBOL_function_call: /* function_call  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1189 "parser.cc"
        break;

    case YYSYMBOL_function_args: /* function_args  */
#line 33 "parser.y"
            { delete (*yyvaluep); }
#line 1195 "parser.cc"
        break;

      default:
        break;
    }
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
  case 2: /* program: statementList '\n'  */
#line 50 "parser.y"
                            {
	yyval = new tree_node("program", yyvsp[-1]->CurrColumn, CurrLine, yyvsp[-1], yyvsp[0]);
	print_tree(yyvsp[-1]);
	delete yyvsp[-1];
	yyval = nullptr;
}
#line 1470 "parser.cc"
    break;

  case 3: /* program: program statementList '\n'  */
#line 55 "parser.y"
                               {
	yyval = new tree_node("program", yyvsp[-1]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
	print_tree(yyvsp[-1]);
	delete yyvsp[-1];
	yyval = yyvsp[-2];
}
#line 1481 "parser.cc"
    break;

  case 4: /* statementList: statementList statement  */
#line 62 "parser.y"
                                       {
	yyval = new tree_node("statementList", yyvsp[-1]->CurrColumn, CurrLine, yyvsp[-1], yyvsp[0]);
}
#line 1489 "parser.cc"
    break;

  case 5: /* statementList: %empty  */
#line 64 "parser.y"
    {
	yyval = new tree_node("statementList (EMPTY STRING)", CurrColumn, CurrLine);
}
#line 1497 "parser.cc"
    break;

  case 6: /* statement: OPEN_BRACE statementList CLOSE_BRACE  */
#line 68 "parser.y"
                                                {
	yyval = new tree_node("statement", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1505 "parser.cc"
    break;

  case 7: /* statement: type ID EQUAL expression SEMICOLON  */
#line 70 "parser.y"
                                       {
	yyval = new tree_node("statement", yyvsp[-4]->CurrColumn, CurrLine, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1513 "parser.cc"
    break;

  case 8: /* statement: type ID SEMICOLON  */
#line 72 "parser.y"
                      {
	yyval = new tree_node("statement", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1521 "parser.cc"
    break;

  case 9: /* statement: expression SEMICOLON  */
#line 74 "parser.y"
                         {
	yyval = new tree_node("statement", yyvsp[-1]->CurrColumn, CurrLine, yyvsp[-1], yyvsp[0]);
}
#line 1529 "parser.cc"
    break;

  case 10: /* statement: WHILE OPEN_PARANTHESIS expression CLOSE_PARANTHESIS statement  */
#line 76 "parser.y"
                                                                  {
	yyval = new tree_node("statement", yyvsp[-4]->CurrColumn, CurrLine, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1537 "parser.cc"
    break;

  case 11: /* statement: IF OPEN_PARANTHESIS expression CLOSE_PARANTHESIS statement  */
#line 78 "parser.y"
                                                               {
	yyval = new tree_node("statement", yyvsp[-4]->CurrColumn, CurrLine, yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1545 "parser.cc"
    break;

  case 12: /* statement: IF OPEN_PARANTHESIS expression CLOSE_PARANTHESIS statement ELSE statement  */
#line 80 "parser.y"
                                                                                        {
	yyval = new tree_node("statement", yyvsp[-6]->CurrColumn, CurrLine, yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1553 "parser.cc"
    break;

  case 13: /* statement: FOR OPEN_PARANTHESIS expression SEMICOLON expression SEMICOLON expression CLOSE_PARANTHESIS statement  */
#line 82 "parser.y"
                                                                                                          {
	yyval = new tree_node("statement", yyvsp[-8]->CurrColumn, CurrLine, yyvsp[-8], yyvsp[-7], yyvsp[-6], yyvsp[-5], yyvsp[-4], yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1561 "parser.cc"
    break;

  case 14: /* statement: error SEMICOLON  */
#line 84 "parser.y"
                    { 	
	yyval = new tree_node("statement (ERROR)", yyvsp[-1]->CurrColumn, CurrLine, yyvsp[0]);
	yyerrok; 
}
#line 1570 "parser.cc"
    break;

  case 15: /* type: INT  */
#line 89 "parser.y"
          {
	yyval = new tree_node("type", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1578 "parser.cc"
    break;

  case 16: /* type: FLOAT  */
#line 91 "parser.y"
          {
	yyval = new tree_node("type", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1586 "parser.cc"
    break;

  case 17: /* type: CHAR  */
#line 93 "parser.y"
         {
	yyval = new tree_node("type", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1594 "parser.cc"
    break;

  case 18: /* expression: OPEN_PARANTHESIS expression CLOSE_PARANTHESIS  */
#line 97 "parser.y"
                                                          {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1602 "parser.cc"
    break;

  case 19: /* expression: expression PLUS expression  */
#line 99 "parser.y"
                               {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1610 "parser.cc"
    break;

  case 20: /* expression: expression MINUS expression  */
#line 101 "parser.y"
                                {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1618 "parser.cc"
    break;

  case 21: /* expression: expression STAR expression  */
#line 103 "parser.y"
                               {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1626 "parser.cc"
    break;

  case 22: /* expression: expression FORWARD_SLASH expression  */
#line 105 "parser.y"
                                        {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1634 "parser.cc"
    break;

  case 23: /* expression: expression EQUAL expression  */
#line 107 "parser.y"
                                {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1642 "parser.cc"
    break;

  case 24: /* expression: expression AND expression  */
#line 109 "parser.y"
                              {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1650 "parser.cc"
    break;

  case 25: /* expression: expression OR expression  */
#line 111 "parser.y"
                             {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1658 "parser.cc"
    break;

  case 26: /* expression: expression LESS_THAN expression  */
#line 113 "parser.y"
                                    {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1666 "parser.cc"
    break;

  case 27: /* expression: expression LESS_THAN_OR_EQUAL expression  */
#line 115 "parser.y"
                                             {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1674 "parser.cc"
    break;

  case 28: /* expression: expression GREATER_THAN expression  */
#line 117 "parser.y"
                                       {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1682 "parser.cc"
    break;

  case 29: /* expression: expression GREATER_THAN_OR_EQUAL expression  */
#line 119 "parser.y"
                                                {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1690 "parser.cc"
    break;

  case 30: /* expression: expression EQUAL_EQUAL expression  */
#line 121 "parser.y"
                                      {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1698 "parser.cc"
    break;

  case 31: /* expression: expression NOT_EQUAL expression  */
#line 123 "parser.y"
                                    {
	yyval = new tree_node("expression", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1706 "parser.cc"
    break;

  case 32: /* expression: ID  */
#line 125 "parser.y"
       {
	yyval = new tree_node("expression", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1714 "parser.cc"
    break;

  case 33: /* expression: INT_LIT  */
#line 127 "parser.y"
            {
	yyval = new tree_node("expression", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1722 "parser.cc"
    break;

  case 34: /* expression: FP_LIT  */
#line 129 "parser.y"
           {
	yyval = new tree_node("expression", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1730 "parser.cc"
    break;

  case 35: /* expression: CHAR_LIT  */
#line 131 "parser.y"
             {
	yyval = new tree_node("expression", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1738 "parser.cc"
    break;

  case 36: /* expression: STRING_LIT  */
#line 133 "parser.y"
               {
	yyval = new tree_node("expression", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1746 "parser.cc"
    break;

  case 37: /* expression: function_call  */
#line 135 "parser.y"
                  {
	yyval = new tree_node("expression", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1754 "parser.cc"
    break;

  case 38: /* function_call: ID OPEN_PARANTHESIS CLOSE_PARANTHESIS  */
#line 139 "parser.y"
                                                     {
	yyval = new tree_node("function_call", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1762 "parser.cc"
    break;

  case 39: /* function_call: ID OPEN_PARANTHESIS function_args CLOSE_PARANTHESIS  */
#line 141 "parser.y"
                                                        {
	yyval = new tree_node("function_call", yyvsp[-3]->CurrColumn, CurrLine, yyvsp[-3], yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1770 "parser.cc"
    break;

  case 40: /* function_args: expression  */
#line 145 "parser.y"
                          {
	yyval = new tree_node("function_args", yyvsp[0]->CurrColumn, CurrLine, yyvsp[0]);
}
#line 1778 "parser.cc"
    break;

  case 41: /* function_args: function_args COMMA expression  */
#line 147 "parser.y"
                                   {
	yyval = new tree_node("function_args", yyvsp[-2]->CurrColumn, CurrLine, yyvsp[-2], yyvsp[-1], yyvsp[0]);
}
#line 1786 "parser.cc"
    break;


#line 1790 "parser.cc"

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

#line 153 "parser.y"


int main() {
	int result = yyparse();
	yylex_destroy();

	return result;
}
