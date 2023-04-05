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
#include "types.h"
using namespace clukcs;

/* Prototype for a function defined by flex. */
void yylex_destroy();

void yyerror(const char *msg)
{
	std::cerr << msg << '\n';
}

// The unique global symbol table.
symbol_table symtab;

// Does type checking for expression operations and sets code, addr, and type
void operation_type_checking(parser_val &E0, parser_val &E1, parser_val &E2, std::string op){
	E0.code = E1.code + E2.code;
	
	// Types of LHS and RHS
	Type E1_type;
	Type E2_type;

	// If LHS is a literal
	if(symtab.get(E1.addr->name()) == nullptr){
		E1_type = E1.type;
	}
	else{
		E1_type = symtab.get(E1.addr->name())->type;	
	}
	
	// If RHS is a literal
	if(symtab.get(E2.addr->name()) == nullptr){
		E2_type = E2.type;
	}
	else{
		E2_type = symtab.get(E2.addr->name())->type;	
	}


	if(E1_type == E2_type){
		E0.type = E1_type;
		E0.addr = symtab.make_temp(E1_type);
		E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + E2.addr->name() + "\n";
	}
	else{
		if(E1_type == Type::Float){
			if(E2_type == Type::Int){
				Address* temp = symtab.make_temp(E1_type);
				E0.code += temp->name() + " = int2float " + E2.addr->name() + "\n";
				
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);

				E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp->name() + "\n";
			}
			if(E2_type == Type::Char){
				Address* temp = symtab.make_temp(Type::Int);
				E0.code += temp->name() + " = char2int " + E2.addr->name() + "\n";
					
				Address* temp2 = symtab.make_temp(E1_type);
				E0.code += temp2->name() + " = int2float " + temp->name() + "\n";

				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);

				E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp2->name() + "\n";
			}
		}
		else if(E2_type == Type::Float){
			if(E1_type == Type::Int){
				Address* temp = symtab.make_temp(E2_type);
				E0.code += temp->name() + " = int2float " + E1.addr->name() + "\n";

				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);

				E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
			}
			if(E1_type == Type::Char){
				Address* temp = symtab.make_temp(Type::Int);
				E0.code += temp->name() + " = char2int " + E1.addr->name() + "\n";
					
				Address* temp2 = symtab.make_temp(E2_type);
				E0.code += temp2->name() + " = int2float " + temp->name() + "\n";

				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);

				E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
			}
		}
		else if(E1_type == Type::Int){
			Address* temp = symtab.make_temp(E1_type);
			E0.code += temp->name() + " = char2int " + E2.addr->name() + "\n";
			
			E0.type = E1_type;
			E0.addr = symtab.make_temp(E1_type);

			E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp->name() + "\n";
		}		
		else if(E2_type == Type::Int){
			Address* temp = symtab.make_temp(E2_type);
			E0.code += temp->name() + " = char2int " + E1.addr->name() + "\n";
			
			E0.type = E2_type;
			E0.addr = symtab.make_temp(E2_type);

			E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
		}	
	}
}



#line 188 "parser.cc"

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
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 4,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 5,              /* FLOAT_LITERAL  */
  YYSYMBOL_CHAR_LITERAL = 6,               /* CHAR_LITERAL  */
  YYSYMBOL_7_ = 7,                         /* '+'  */
  YYSYMBOL_8_ = 8,                         /* '-'  */
  YYSYMBOL_9_ = 9,                         /* '*'  */
  YYSYMBOL_10_ = 10,                       /* '/'  */
  YYSYMBOL_11_ = 11,                       /* '%'  */
  YYSYMBOL_12_ = 12,                       /* '='  */
  YYSYMBOL_13_ = 13,                       /* '('  */
  YYSYMBOL_14_ = 14,                       /* ')'  */
  YYSYMBOL_15_ = 15,                       /* '{'  */
  YYSYMBOL_16_ = 16,                       /* '}'  */
  YYSYMBOL_17_ = 17,                       /* ';'  */
  YYSYMBOL_INT = 18,                       /* INT  */
  YYSYMBOL_FLOAT = 19,                     /* FLOAT  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_UMINUS = 21,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 22,                  /* $accept  */
  YYSYMBOL_program = 23,                   /* program  */
  YYSYMBOL_statement_list = 24,            /* statement_list  */
  YYSYMBOL_statement = 25,                 /* statement  */
  YYSYMBOL_26_1 = 26,                      /* $@1  */
  YYSYMBOL_type = 27,                      /* type  */
  YYSYMBOL_expression = 28                 /* expression  */
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
#define YYLAST   92

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  22
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  7
/* YYNRULES -- Number of rules.  */
#define YYNRULES  25
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  43

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   265


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
       2,     2,     2,     2,     2,     2,     2,    11,     2,     2,
      13,    14,     9,     7,     2,     8,     2,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    17,
       2,    12,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    15,     2,    16,     2,     2,     2,     2,
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
       5,     6,    18,    19,    20,    21
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   142,   142,   146,   148,   152,   155,   155,   158,   237,
     241,   245,   247,   249,   253,   255,   257,   259,   261,   299,
     380,   385,   390,   396,   402,   424
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
  "INT_LITERAL", "FLOAT_LITERAL", "CHAR_LITERAL", "'+'", "'-'", "'*'",
  "'/'", "'%'", "'='", "'('", "')'", "'{'", "'}'", "';'", "INT", "FLOAT",
  "CHAR", "UMINUS", "$accept", "program", "statement_list", "statement",
  "$@1", "type", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-10)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-3)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -10,    20,    21,   -10,    11,   -10,   -10,   -10,   -10,    65,
      65,   -10,   -10,   -10,   -10,   -10,    27,    -5,   -10,   -10,
      72,   -10,    -4,    65,    65,    65,    65,    65,    65,   -10,
     -10,    41,    65,   -10,     0,     0,   -10,   -10,   -10,    80,
     -10,    55,   -10
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     0,    25,    22,    23,    24,     0,
       0,     6,    11,    12,    13,     3,     0,     0,    10,    20,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     5,
      21,     0,     0,     9,    14,    15,    16,    17,    18,    19,
       7,     0,     8
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -10,   -10,    10,   -10,   -10,   -10,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,    15,    21,    16,    17
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      19,    20,    23,    24,    25,    26,    27,    28,    32,    25,
      26,    27,    29,    33,    34,    35,    36,    37,    38,    39,
       3,    -2,     4,    41,     5,     6,     7,     8,    18,     9,
      22,    31,     0,     0,    10,     0,    11,     0,     0,    12,
      13,    14,     4,     0,     5,     6,     7,     8,     0,     9,
       0,     0,     0,     0,    10,     0,    11,    40,     0,    12,
      13,    14,    23,    24,    25,    26,    27,    28,     5,     6,
       7,     8,    42,     9,     0,     0,     0,     0,    10,    23,
      24,    25,    26,    27,    28,     0,    30,    23,    24,    25,
      26,    27,    28
};

static const yytype_int8 yycheck[] =
{
       9,    10,     7,     8,     9,    10,    11,    12,    12,     9,
      10,    11,    17,    17,    23,    24,    25,    26,    27,    28,
       0,     0,     1,    32,     3,     4,     5,     6,    17,     8,
       3,    21,    -1,    -1,    13,    -1,    15,    -1,    -1,    18,
      19,    20,     1,    -1,     3,     4,     5,     6,    -1,     8,
      -1,    -1,    -1,    -1,    13,    -1,    15,    16,    -1,    18,
      19,    20,     7,     8,     9,    10,    11,    12,     3,     4,
       5,     6,    17,     8,    -1,    -1,    -1,    -1,    13,     7,
       8,     9,    10,    11,    12,    -1,    14,     7,     8,     9,
      10,    11,    12
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    24,     0,     1,     3,     4,     5,     6,     8,
      13,    15,    18,    19,    20,    25,    27,    28,    17,    28,
      28,    26,     3,     7,     8,     9,    10,    11,    12,    17,
      14,    24,    12,    17,    28,    28,    28,    28,    28,    28,
      16,    28,    17
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    22,    23,    24,    24,    25,    26,    25,    25,    25,
      25,    27,    27,    27,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     0,     4,     5,     3,
       2,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       2,     3,     1,     1,     1,     1
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
  case 2: /* program: statement_list  */
#line 142 "parser.y"
                        {
	std::cout << "Code:\n" << yyvsp[0].code << "\n";
}
#line 1231 "parser.cc"
    break;

  case 3: /* statement_list: statement_list statement  */
#line 146 "parser.y"
                                         {
	yyval.code = yyvsp[-1].code + yyvsp[0].code;
}
#line 1239 "parser.cc"
    break;

  case 4: /* statement_list: %empty  */
#line 148 "parser.y"
           {
	yyval.code = "";
}
#line 1247 "parser.cc"
    break;

  case 5: /* statement: expression ';'  */
#line 152 "parser.y"
                          {
	yyval.code = yyvsp[-1].code;

}
#line 1256 "parser.cc"
    break;

  case 6: /* $@1: %empty  */
#line 155 "parser.y"
        { symtab.push(); }
#line 1262 "parser.cc"
    break;

  case 7: /* statement: '{' $@1 statement_list '}'  */
#line 155 "parser.y"
                                               {
	symtab.pop();

}
#line 1271 "parser.cc"
    break;

  case 8: /* statement: type IDENTIFIER '=' expression ';'  */
#line 158 "parser.y"
                                       {
	yyval.code = yyvsp[-1].code;

	// If type conversion is needed, store temp name for code output
	std::string RHS_label = "";

	Type LHS_type = yyvsp[-4].type;
	Type RHS_type;
	
	// If RHS is a literal
	if(symtab.get(yyvsp[-1].addr->name()) == nullptr){
		RHS_type = yyvsp[-1].type;
	}
	else{
		RHS_type = symtab.get(yyvsp[-1].addr->name())->type;	
	}

	// Type checking
	if(LHS_type != RHS_type){
		switch(LHS_type){
			case Type::Int:
				if(RHS_type == Type::Float){
					Address* temp = symtab.make_temp(LHS_type);
					yyval.code += temp->name() + " = float2int " + yyvsp[-1].addr->name() + "\n";
					RHS_label = temp->name();
				}
				else if(RHS_type == Type::Char){
					Address* temp = symtab.make_temp(LHS_type);
					yyval.code += temp->name() + " = char2int " + yyvsp[-1].addr->name() + "\n";
					RHS_label = temp->name();
				}
				break;		
			case Type::Float:
				if(RHS_type == Type::Int){
					Address* temp = symtab.make_temp(LHS_type);
					yyval.code += temp->name() + " = int2float " + yyvsp[-1].addr->name() + "\n";
					RHS_label = temp->name();
				}
				else if(RHS_type == Type::Char){
					Address* temp = symtab.make_temp(Type::Int);
					yyval.code += temp->name() + " = char2int " + yyvsp[-1].addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(LHS_type);
					yyval.code += temp2->name() + " = int2float " + temp->name() + "\n";
					RHS_label = temp->name();
				}
				break;
			case Type::Char:
				if(RHS_type == Type::Int){
					Address* temp = symtab.make_temp(LHS_type);
					yyval.code += temp->name() + " = int2char " + yyvsp[-1].addr->name() + "\n";
					RHS_label = temp->name();
				}
				else if(RHS_type == Type::Float){
					Address* temp = symtab.make_temp(Type::Int);
					yyval.code += temp->name() + " = float2int " + yyvsp[-1].addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(LHS_type);
					yyval.code += temp2->name() + " = int2char " + temp->name() + "\n";
					RHS_label = temp->name();
				}
				break;
			default:
				break;
		}
	}
	
	if(RHS_label == ""){
		Address* temp3 = symtab.make_temp(yyvsp[-4].type);
		// t0 = num
		yyval.code += temp3->name() + " = " + yyvsp[-1].addr->name() + "\n";
		// id = t0
		yyval.code += yyvsp[-3].code + " = " + temp3->name() + "\n";
	}
	else{
		yyval.code += yyvsp[-3].code + " = " + RHS_label + "\n";
	}
	symtab.put(yyvsp[-3].code, yyvsp[-4].type);

}
#line 1356 "parser.cc"
    break;

  case 9: /* statement: type IDENTIFIER ';'  */
#line 237 "parser.y"
                        {
	yyval.code = "";
	symtab.put(yyvsp[-1].code, yyvsp[-2].type);

}
#line 1366 "parser.cc"
    break;

  case 10: /* statement: error ';'  */
#line 241 "parser.y"
              { // error is a special token defined by bison
	yyerrok;
}
#line 1374 "parser.cc"
    break;

  case 11: /* type: INT  */
#line 245 "parser.y"
          {
	yyval.type = Type::Int;
}
#line 1382 "parser.cc"
    break;

  case 12: /* type: FLOAT  */
#line 247 "parser.y"
          {
	yyval.type = Type::Float;
}
#line 1390 "parser.cc"
    break;

  case 13: /* type: CHAR  */
#line 249 "parser.y"
         {
	yyval.type = Type::Char;
}
#line 1398 "parser.cc"
    break;

  case 14: /* expression: expression '+' expression  */
#line 253 "parser.y"
                                      {
	operation_type_checking(yyval, yyvsp[-2], yyvsp[0], "+");
}
#line 1406 "parser.cc"
    break;

  case 15: /* expression: expression '-' expression  */
#line 255 "parser.y"
                              {
	operation_type_checking(yyval, yyvsp[-2], yyvsp[0], "-");
}
#line 1414 "parser.cc"
    break;

  case 16: /* expression: expression '*' expression  */
#line 257 "parser.y"
                              {
	operation_type_checking(yyval, yyvsp[-2], yyvsp[0], "*");
}
#line 1422 "parser.cc"
    break;

  case 17: /* expression: expression '/' expression  */
#line 259 "parser.y"
                              {
	operation_type_checking(yyval, yyvsp[-2], yyvsp[0], "/");
}
#line 1430 "parser.cc"
    break;

  case 18: /* expression: expression '%' expression  */
#line 261 "parser.y"
                              {
	yyval.code = yyvsp[-2].code + yyvsp[0].code;

	// Getting types of LHS and RHS
	Type E1_type = symtab.get(yyvsp[-2].addr->name())->type;
	Type E2_type = symtab.get(yyvsp[0].addr->name())->type;

	if(E1_type == Type::Float || E2_type == Type::Float){
		std::cerr << "" << std::endl;
	}

	if(E1_type == E2_type){
		yyval.type = E1_type;
		yyval.addr = symtab.make_temp(E1_type);
		yyval.code += yyval.addr->name() + " = " + yyvsp[-2].addr->name() + " " + '%' + " " + yyvsp[0].addr->name() + "\n";

	}
	else{
		if(E1_type == Type::Int){
			Address* temp = symtab.make_temp(E1_type);
			yyval.code += temp->name() + " = char2int " + yyvsp[0].addr->name() + "\n";
			
			yyval.type = E1_type;
			yyval.addr = symtab.make_temp(E1_type);

			yyval.code += yyval.addr->name() + " = " + yyvsp[-2].addr->name() + " " + '%' + " " + temp->name() + "\n";
		}		
		else if(E2_type == Type::Int){
			Address* temp = symtab.make_temp(E2_type);
			yyval.code += temp->name() + " = char2int " + yyvsp[-2].addr->name() + "\n";
			
			yyval.type = E2_type;
			yyval.addr = symtab.make_temp(E2_type);

			yyval.code += yyval.addr->name() + " = " + temp->name() + " " + '%' + " " + yyvsp[0].addr->name() + "\n";
		}
	}

}
#line 1474 "parser.cc"
    break;

  case 19: /* expression: expression '=' expression  */
#line 299 "parser.y"
                              {
	// Getting types of LHS and RHS
	Type E1_type;
	Type E2_type;

	// If E1 is a literal
	if(symtab.get(yyvsp[-2].addr->name()) == nullptr){
		E1_type = yyvsp[-2].type;
	}
	else{
		E1_type = symtab.get(yyvsp[-2].addr->name())->type;	
	}
	
	// If E2 is a literal
	if(symtab.get(yyvsp[0].addr->name()) == nullptr){
		E2_type = yyvsp[0].type;
	}
	else{
		E2_type = symtab.get(yyvsp[0].addr->name())->type;	
	}
	
	// Type is same as LHS
	yyval.type = E1_type;
	yyval.addr = yyvsp[-2].addr;
	yyval.code = yyvsp[-2].code + yyvsp[0].code;
	
	if(E1_type == E2_type){
		Address* temp = symtab.make_temp(E1_type);
		yyval.code += temp->name() + " = " + yyvsp[0].addr->name() + "\n";
		yyval.code += yyvsp[-2].addr->name() + " = " + temp->name() + "\n";
	}
	// If RHS is a different type, do type conversion
	else{
		switch(E1_type){
			case Type::Int:
				if(E2_type == Type::Float){
					Address* temp = symtab.make_temp(E1_type);
					yyval.code += temp->name() + " = float2int " + yyvsp[0].addr->name() + "\n";
					yyval.code += yyvsp[-2].addr->name() + " = " + temp->name() + "\n";
				}
				else if(E2_type == Type::Char){
					Address* temp = symtab.make_temp(E1_type);
					yyval.code += temp->name() + " = char2int " + yyvsp[0].addr->name() + "\n";
					yyval.code += yyvsp[-2].addr->name() + " = " + temp->name() + "\n";
				}
				break;		
			case Type::Float:
				if(E2_type == Type::Int){
					Address* temp = symtab.make_temp(E1_type);
					yyval.code += temp->name() + " = int2float " + yyvsp[0].addr->name() + "\n";
					yyval.code += yyvsp[-2].addr->name() + " = " + temp->name() + "\n";
				}
				else if(E2_type == Type::Char){
					Address* temp = symtab.make_temp(Type::Int);
					yyval.code += temp->name() + " = char2int " + yyvsp[0].addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(E1_type);
					yyval.code += temp2->name() + " = int2float " + temp->name() + "\n";
					yyval.code += yyvsp[-2].addr->name() + " = " + temp2->name() + "\n";
				}
				break;
			case Type::Char:
				if(E2_type == Type::Int){
					Address* temp = symtab.make_temp(E1_type);
					yyval.code += temp->name() + " = int2char " + yyvsp[0].addr->name() + "\n";
					yyval.code += yyvsp[-2].addr->name() + " = " + temp->name() + "\n";
				}
				else if(E2_type == Type::Float){
					Address* temp = symtab.make_temp(Type::Int);
					yyval.code += temp->name() + " = float2int " + yyvsp[0].addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(E1_type);
					yyval.code += temp2->name() + " = int2char " + temp->name() + "\n";
					yyval.code += yyvsp[-2].addr->name() + " = " + temp2->name() + "\n";
				}
				break;
			default:
				break;
		}
	}

}
#line 1561 "parser.cc"
    break;

  case 20: /* expression: '-' expression  */
#line 380 "parser.y"
                                {
	yyval.addr = symtab.make_temp(yyvsp[0].type);
	yyval.code = yyval.addr->name() + " = -" + yyvsp[0].addr->name() + "\n";
	yyval.type = yyvsp[0].type;

}
#line 1572 "parser.cc"
    break;

  case 21: /* expression: '(' expression ')'  */
#line 385 "parser.y"
                       {
	yyval.code = yyvsp[-1].code;
	yyval.addr = yyvsp[-1].addr;
	yyval.type = yyvsp[-1].type;

}
#line 1583 "parser.cc"
    break;

  case 22: /* expression: INT_LITERAL  */
#line 390 "parser.y"
                {
	yyval.code = "";
	int val = std::stoi(yyvsp[0].code);
	yyval.addr = symtab.make_int_const(val);
	yyval.type = Type::Int;

}
#line 1595 "parser.cc"
    break;

  case 23: /* expression: FLOAT_LITERAL  */
#line 396 "parser.y"
                  {
	yyval.code = "";
	float val = std::stof(yyvsp[0].code);
	yyval.addr = symtab.make_float_const(val);
	yyval.type = Type::Float;

}
#line 1607 "parser.cc"
    break;

  case 24: /* expression: CHAR_LITERAL  */
#line 402 "parser.y"
                 {
	yyval.code = "";
	
	// Removing single quotes
	std::string val = yyvsp[0].code.substr(1, yyvsp[0].code.size()-2);
	
	char char_val;
	if(val == "\\n"){
		char_val = '\n';
	}
	else if(val == "\\\\"){
		char_val = '\\';
	}
	else if(val == "\\'"){
		char_val = '\'';
	}
	else
		char_val = val[0];

	yyval.addr = symtab.make_char_const(char_val);
	yyval.type = Type::Char;

}
#line 1635 "parser.cc"
    break;

  case 25: /* expression: IDENTIFIER  */
#line 424 "parser.y"
               {
	yyval.code = "";
	yyval.addr = symtab.make_variable(yyvsp[0].code);
	yyval.type = yyvsp[0].type;
}
#line 1645 "parser.cc"
    break;


#line 1649 "parser.cc"

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

#line 431 "parser.y"


int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
