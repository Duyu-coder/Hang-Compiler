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
#line 1 "syntax.y"

#include "common.h"
#include "optimize.h"
// 声明词法分析器函数
extern int yylex(void);
extern int yyparse(void);
extern FILE* yyin;

// 错误处理函数声明
void yyerror(const char* s);

// 语法树根节点声明
extern ASTNode* ast_root;

#line 86 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOK_ID = 3,                     /* TOK_ID  */
  YYSYMBOL_TOK_INT = 4,                    /* TOK_INT  */
  YYSYMBOL_TOK_FLOAT = 5,                  /* TOK_FLOAT  */
  YYSYMBOL_TOK_TRUE = 6,                   /* TOK_TRUE  */
  YYSYMBOL_TOK_FALSE = 7,                  /* TOK_FALSE  */
  YYSYMBOL_TOK_INT_TYPE = 8,               /* TOK_INT_TYPE  */
  YYSYMBOL_TOK_FLOAT_TYPE = 9,             /* TOK_FLOAT_TYPE  */
  YYSYMBOL_TOK_BOOL_TYPE = 10,             /* TOK_BOOL_TYPE  */
  YYSYMBOL_TOK_HANG = 11,                  /* TOK_HANG  */
  YYSYMBOL_TOK_IN = 12,                    /* TOK_IN  */
  YYSYMBOL_TOK_OUT = 13,                   /* TOK_OUT  */
  YYSYMBOL_TOK_WHEN = 14,                  /* TOK_WHEN  */
  YYSYMBOL_TOK_ADD = 15,                   /* TOK_ADD  */
  YYSYMBOL_TOK_SUB = 16,                   /* TOK_SUB  */
  YYSYMBOL_TOK_MUL = 17,                   /* TOK_MUL  */
  YYSYMBOL_TOK_DIV = 18,                   /* TOK_DIV  */
  YYSYMBOL_TOK_ASSIGN = 19,                /* TOK_ASSIGN  */
  YYSYMBOL_TOK_FEN = 20,                   /* TOK_FEN  */
  YYSYMBOL_TOK_DOU = 21,                   /* TOK_DOU  */
  YYSYMBOL_TOK_LY = 22,                    /* TOK_LY  */
  YYSYMBOL_TOK_RY = 23,                    /* TOK_RY  */
  YYSYMBOL_TOK_LH = 24,                    /* TOK_LH  */
  YYSYMBOL_TOK_RH = 25,                    /* TOK_RH  */
  YYSYMBOL_TOK_ERROR = 26,                 /* TOK_ERROR  */
  YYSYMBOL_TOK_GT = 27,                    /* TOK_GT  */
  YYSYMBOL_TOK_LT = 28,                    /* TOK_LT  */
  YYSYMBOL_TOK_GE = 29,                    /* TOK_GE  */
  YYSYMBOL_TOK_LE = 30,                    /* TOK_LE  */
  YYSYMBOL_TOK_EQ = 31,                    /* TOK_EQ  */
  YYSYMBOL_TOK_NE = 32,                    /* TOK_NE  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_statements = 35,                /* statements  */
  YYSYMBOL_statement = 36,                 /* statement  */
  YYSYMBOL_declaration_statement = 37,     /* declaration_statement  */
  YYSYMBOL_type_specifier = 38,            /* type_specifier  */
  YYSYMBOL_identifiers = 39,               /* identifiers  */
  YYSYMBOL_assignment_statement = 40,      /* assignment_statement  */
  YYSYMBOL_input_statement = 41,           /* input_statement  */
  YYSYMBOL_output_statement = 42,          /* output_statement  */
  YYSYMBOL_when_statement = 43,            /* when_statement  */
  YYSYMBOL_condition = 44,                 /* condition  */
  YYSYMBOL_expression = 45                 /* expression  */
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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  38
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  78

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    66,    70,    80,    84,    88,    92,    96,
     100,   108,   114,   126,   130,   134,   142,   146,   156,   166,
     175,   184,   194,   198,   204,   210,   216,   222,   228,   238,
     242,   246,   250,   254,   258,   262,   268,   274,   280
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
  "\"end of file\"", "error", "\"invalid token\"", "TOK_ID", "TOK_INT",
  "TOK_FLOAT", "TOK_TRUE", "TOK_FALSE", "TOK_INT_TYPE", "TOK_FLOAT_TYPE",
  "TOK_BOOL_TYPE", "TOK_HANG", "TOK_IN", "TOK_OUT", "TOK_WHEN", "TOK_ADD",
  "TOK_SUB", "TOK_MUL", "TOK_DIV", "TOK_ASSIGN", "TOK_FEN", "TOK_DOU",
  "TOK_LY", "TOK_RY", "TOK_LH", "TOK_RH", "TOK_ERROR", "TOK_GT", "TOK_LT",
  "TOK_GE", "TOK_LE", "TOK_EQ", "TOK_NE", "$accept", "program",
  "statements", "statement", "declaration_statement", "type_specifier",
  "identifiers", "assignment_statement", "input_statement",
  "output_statement", "when_statement", "condition", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-18)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       1,    -5,    33,    94,   -18,    30,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,    17,    28,    41,     3,    48,   -18,   -18,
      65,   -18,   -18,   -18,   -18,     0,     3,    66,     3,     3,
     -18,    11,   -18,   -18,    52,    10,     3,     3,     3,     3,
     -18,    20,    59,    49,    63,    95,   -18,     3,   -18,    88,
      24,    24,   -18,   -18,   -18,    74,    75,    81,     3,     3,
       3,     3,     3,     3,    72,   -18,   -18,   -18,    94,   -13,
     -13,   -13,   -13,   -13,   -13,   -18,    71,   -18
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,    29,    30,    31,    32,    33,
      13,    14,    15,     0,     0,     0,     0,     0,     3,     5,
       0,     6,     7,     8,     9,     0,     0,     0,     0,     0,
      29,     0,     2,     4,    16,     0,     0,     0,     0,     0,
      10,     0,     0,     0,     0,    22,    34,     0,    11,     0,
      35,    36,    37,    38,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    19,    20,     0,    23,
      24,    25,    26,    27,    28,    12,     0,    21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -18,   -18,    46,   -17,   -18,   -18,   -18,   -18,   -18,   -18,
     -18,   -18,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    17,    18,    19,    20,    35,    21,    22,    23,
      24,    44,    25
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    31,    36,    37,    38,    39,    30,     6,     7,     8,
       9,    41,     1,    43,    45,    36,    37,    38,    39,     3,
      40,    50,    51,    52,    53,    16,    36,    37,    38,    39,
      48,    49,    64,     4,    46,    36,    37,    38,    39,    27,
      54,    38,    39,    69,    70,    71,    72,    73,    74,    26,
      28,     5,     6,     7,     8,     9,    10,    11,    12,    33,
      13,    14,    15,    29,    36,    37,    38,    39,    34,    42,
      16,    47,    56,    32,     5,     6,     7,     8,     9,    10,
      11,    12,    55,    13,    14,    15,    57,    36,    37,    38,
      39,    65,    75,    16,    66,    67,    77,     5,     6,     7,
       8,     9,    10,    11,    12,    68,    13,    14,    15,     0,
      36,    37,    38,    39,    76,     0,    16,     0,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63
};

static const yytype_int8 yycheck[] =
{
      17,    16,    15,    16,    17,    18,     3,     4,     5,     6,
       7,    26,    11,    28,    29,    15,    16,    17,    18,    24,
      20,    36,    37,    38,    39,    22,    15,    16,    17,    18,
      20,    21,    47,     0,    23,    15,    16,    17,    18,    22,
      20,    17,    18,    58,    59,    60,    61,    62,    63,    19,
      22,     3,     4,     5,     6,     7,     8,     9,    10,    76,
      12,    13,    14,    22,    15,    16,    17,    18,     3,     3,
      22,    19,    23,    25,     3,     4,     5,     6,     7,     8,
       9,    10,    23,    12,    13,    14,    23,    15,    16,    17,
      18,     3,    20,    22,    20,    20,    25,     3,     4,     5,
       6,     7,     8,     9,    10,    24,    12,    13,    14,    -1,
      15,    16,    17,    18,    68,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    34,    24,     0,     3,     4,     5,     6,     7,
       8,     9,    10,    12,    13,    14,    22,    35,    36,    37,
      38,    40,    41,    42,    43,    45,    19,    22,    22,    22,
       3,    45,    25,    36,     3,    39,    15,    16,    17,    18,
      20,    45,     3,    45,    44,    45,    23,    19,    20,    21,
      45,    45,    45,    45,    20,    23,    23,    23,    27,    28,
      29,    30,    31,    32,    45,     3,    20,    20,    24,    45,
      45,    45,    45,    45,    45,    20,    35,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    36,    36,    36,
      36,    37,    37,    38,    38,    38,    39,    39,    40,    41,
      42,    43,    44,    44,    44,    44,    44,    44,    44,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     1,     1,     1,     1,     1,
       2,     3,     5,     1,     1,     1,     1,     3,     4,     5,
       5,     7,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3
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
  case 2: /* program: TOK_HANG TOK_LH statements TOK_RH  */
#line 48 "syntax.y"
    {
        (yyval.node) = createNode(NODE_PROGRAM, "hang_program");
        // 将语句链表的所有节点添加为子节点
        ASTNode* current = (yyvsp[-1].node);
        while (current != NULL) 
        {
            ASTNode* next = current->next_sibling;
            current->next_sibling = NULL; // 清除兄弟指针，转换为父子关系
            addChild((yyval.node), current);
            current = next;
        }
        ast_root = (yyval.node);
        printf("语法分析: 识别到hang程序块\n");
    }
#line 1183 "syntax.tab.c"
    break;

  case 3: /* statements: statement  */
#line 67 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1191 "syntax.tab.c"
    break;

  case 4: /* statements: statements statement  */
#line 71 "syntax.y"
    {
        // 将新语句添加为兄弟节点
        addSibling((yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1201 "syntax.tab.c"
    break;

  case 5: /* statement: declaration_statement  */
#line 81 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1209 "syntax.tab.c"
    break;

  case 6: /* statement: assignment_statement  */
#line 85 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1217 "syntax.tab.c"
    break;

  case 7: /* statement: input_statement  */
#line 89 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1225 "syntax.tab.c"
    break;

  case 8: /* statement: output_statement  */
#line 93 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1233 "syntax.tab.c"
    break;

  case 9: /* statement: when_statement  */
#line 97 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1241 "syntax.tab.c"
    break;

  case 10: /* statement: expression TOK_FEN  */
#line 101 "syntax.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1249 "syntax.tab.c"
    break;

  case 11: /* declaration_statement: type_specifier identifiers TOK_FEN  */
#line 109 "syntax.y"
    {
        (yyval.node) = createNode(NODE_DECLARATION, "decl");
        addChild((yyval.node), (yyvsp[-2].node));  // 类型
        addChild((yyval.node), (yyvsp[-1].node));  // 标识符列表
    }
#line 1259 "syntax.tab.c"
    break;

  case 12: /* declaration_statement: type_specifier TOK_ID TOK_ASSIGN expression TOK_FEN  */
#line 115 "syntax.y"
    {
        (yyval.node) = createNode(NODE_DECLARATION, "decl_init");
        addChild((yyval.node), (yyvsp[-4].node));  // 类型
        ASTNode* id_node = createNode(NODE_IDENTIFIER, (yyvsp[-3].string_value));
        addChild((yyval.node), id_node);
        addChild((yyval.node), (yyvsp[-1].node));  // 初始值表达式
    }
#line 1271 "syntax.tab.c"
    break;

  case 13: /* type_specifier: TOK_INT_TYPE  */
#line 127 "syntax.y"
    {
        (yyval.node) = createNode(NODE_TYPE, "int");
    }
#line 1279 "syntax.tab.c"
    break;

  case 14: /* type_specifier: TOK_FLOAT_TYPE  */
#line 131 "syntax.y"
    {
        (yyval.node) = createNode(NODE_TYPE, "float");
    }
#line 1287 "syntax.tab.c"
    break;

  case 15: /* type_specifier: TOK_BOOL_TYPE  */
#line 135 "syntax.y"
    {
        (yyval.node) = createNode(NODE_TYPE, "bool");
    }
#line 1295 "syntax.tab.c"
    break;

  case 16: /* identifiers: TOK_ID  */
#line 143 "syntax.y"
    {
        (yyval.node) = createNode(NODE_IDENTIFIER, (yyvsp[0].string_value));
    }
#line 1303 "syntax.tab.c"
    break;

  case 17: /* identifiers: identifiers TOK_DOU TOK_ID  */
#line 147 "syntax.y"
    {
        // 将新标识符添加为兄弟节点
        addSibling((yyvsp[-2].node), createNode(NODE_IDENTIFIER, (yyvsp[0].string_value)));
        (yyval.node) = (yyvsp[-2].node);
    }
#line 1313 "syntax.tab.c"
    break;

  case 18: /* assignment_statement: TOK_ID TOK_ASSIGN expression TOK_FEN  */
#line 157 "syntax.y"
    {
        (yyval.node) = createNode(NODE_ASSIGNMENT, "=");
        addChild((yyval.node), createNode(NODE_IDENTIFIER, (yyvsp[-3].string_value)));
        addChild((yyval.node), (yyvsp[-1].node));
    }
#line 1323 "syntax.tab.c"
    break;

  case 19: /* input_statement: TOK_IN TOK_LY TOK_ID TOK_RY TOK_FEN  */
#line 167 "syntax.y"
    {
        (yyval.node) = createNode(NODE_INPUT, "in");
        addChild((yyval.node), createNode(NODE_IDENTIFIER, (yyvsp[-2].string_value)));
    }
#line 1332 "syntax.tab.c"
    break;

  case 20: /* output_statement: TOK_OUT TOK_LY expression TOK_RY TOK_FEN  */
#line 176 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OUTPUT, "out");
        addChild((yyval.node), (yyvsp[-2].node));
    }
#line 1341 "syntax.tab.c"
    break;

  case 21: /* when_statement: TOK_WHEN TOK_LY condition TOK_RY TOK_LH statements TOK_RH  */
#line 185 "syntax.y"
    {
        (yyval.node) = createNode(NODE_WHEN, "when");
        addChild((yyval.node), (yyvsp[-4].node));  // 条件
        addChild((yyval.node), (yyvsp[-1].node));  // 语句块
    }
#line 1351 "syntax.tab.c"
    break;

  case 22: /* condition: expression  */
#line 195 "syntax.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1359 "syntax.tab.c"
    break;

  case 23: /* condition: expression TOK_GT expression  */
#line 199 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, ">");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1369 "syntax.tab.c"
    break;

  case 24: /* condition: expression TOK_LT expression  */
#line 205 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "<");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1379 "syntax.tab.c"
    break;

  case 25: /* condition: expression TOK_GE expression  */
#line 211 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, ">=");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1389 "syntax.tab.c"
    break;

  case 26: /* condition: expression TOK_LE expression  */
#line 217 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "<=");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1399 "syntax.tab.c"
    break;

  case 27: /* condition: expression TOK_EQ expression  */
#line 223 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "==");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1409 "syntax.tab.c"
    break;

  case 28: /* condition: expression TOK_NE expression  */
#line 229 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "!=");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1419 "syntax.tab.c"
    break;

  case 29: /* expression: TOK_ID  */
#line 239 "syntax.y"
    {
        (yyval.node) = createNode(NODE_IDENTIFIER, (yyvsp[0].string_value));
    }
#line 1427 "syntax.tab.c"
    break;

  case 30: /* expression: TOK_INT  */
#line 243 "syntax.y"
    {
        (yyval.node) = createNode(NODE_CONSTANT, (yyvsp[0].string_value));
    }
#line 1435 "syntax.tab.c"
    break;

  case 31: /* expression: TOK_FLOAT  */
#line 247 "syntax.y"
    {
        (yyval.node) = createNode(NODE_CONSTANT, (yyvsp[0].string_value));
    }
#line 1443 "syntax.tab.c"
    break;

  case 32: /* expression: TOK_TRUE  */
#line 251 "syntax.y"
    {
        (yyval.node) = createNode(NODE_CONSTANT, "true");
    }
#line 1451 "syntax.tab.c"
    break;

  case 33: /* expression: TOK_FALSE  */
#line 255 "syntax.y"
    {
        (yyval.node) = createNode(NODE_CONSTANT, "false");
    }
#line 1459 "syntax.tab.c"
    break;

  case 34: /* expression: TOK_LY expression TOK_RY  */
#line 259 "syntax.y"
    {
        (yyval.node) = (yyvsp[-1].node);  // 括号表达式：直接返回内部表达式
    }
#line 1467 "syntax.tab.c"
    break;

  case 35: /* expression: expression TOK_ADD expression  */
#line 263 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "+");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1477 "syntax.tab.c"
    break;

  case 36: /* expression: expression TOK_SUB expression  */
#line 269 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "-");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1487 "syntax.tab.c"
    break;

  case 37: /* expression: expression TOK_MUL expression  */
#line 275 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "*");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1497 "syntax.tab.c"
    break;

  case 38: /* expression: expression TOK_DIV expression  */
#line 281 "syntax.y"
    {
        (yyval.node) = createNode(NODE_OPERATOR, "/");
        addChild((yyval.node), (yyvsp[-2].node));
        addChild((yyval.node), (yyvsp[0].node));
    }
#line 1507 "syntax.tab.c"
    break;


#line 1511 "syntax.tab.c"

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

#line 288 "syntax.y"


// 全局语法树根节点
ASTNode* ast_root = NULL;

// 错误处理函数
void yyerror(const char* s) 
{
    extern int yylineno;
    fprintf(stderr, "语法错误 (行%d): %s\n", yylineno, s);
}

int main(int argc, char* argv[]) 
{
    // 设置输入文件
    if (argc > 1) 
    {
        yyin = fopen(argv[1], "r");
        if (!yyin) 
        {
            fprintf(stderr, "无法打开文件: %s\n", argv[1]);
            return 1;
        }
    } 
    else 
    {
        printf("未检测到输入文件，请输入文件后重试\n");
        return 1;
    }
    
    printf("开始语法分析...\n");
    printf("=================================\n");
    
    // 记录总编译开始时间（用于统计）
    clock_t total_start = clock();
    
    // 记录词法分析开始时间（在yyparse之前）
    start_timer(&compile_timing.lex_start);
    
    // 记录语法分析开始时间
    start_timer(&compile_timing.parse_start);
    
    // 调用语法分析器（内部会调用词法分析器）
    int result = yyparse();
    
    // 记录语法分析结束时间
    record_parse_time();
    
    // 记录词法分析结束时间（在yyparse之后）
    record_lex_time();
    
    if (result == 0) 
    {
        printf("=================================\n");
        printf("语法分析成功完成!\n");
        
        // 记录语义分析开始时间
        start_timer(&compile_timing.sem_start);
        
        // 打印语法树（语义分析的一部分）
        printf("\n======= 抽象语法树(AST) =======\n");
        if (ast_root) 
        {
            printAST(ast_root, 0);
        } 
        else 
        {
            printf("语法树为空\n");
        }
        printf("======= AST结束 =======\n");
        
        // 记录语义分析结束时间
        record_sem_time();
        
        // 记录代码生成开始时间
        start_timer(&compile_timing.codegen_start);
        
        // 生成四元式
        if (ast_root) 
        {
            generateQuadruples(ast_root);
            printQuadruples();
            
	    // 执行优化
	    printf("\n=== 中间代码优化 ===\n");
	    optimize_quadruples();

	    printQuadruples();  // 显示优化后的四元式

            // 生成汇编代码到文件
            printf("\n=== 生成汇编代码 ===\n");    

            // 确定输出文件名
            char asmFilename[256];
            strcpy(asmFilename, argv[1]);
            char* dot = strrchr(asmFilename, '.');
            if (dot) *dot = '\0';
            strcat(asmFilename, ".asm");
            
            // 生成汇编文件
            generateAssemblyToFile(asmFilename);
            
            // 同时在屏幕上显示汇编代码（可选）
            printf("\n======= 生成的汇编代码 =======\n");
            generateAssembly();
            printf("======= 汇编代码结束 =======\n");
        }
        
        // 记录代码生成结束时间
        record_codegen_time();
        
    } 
    else 
    {
        printf("=================================\n");
        printf("语法分析失败!\n");
    }
    
    // 初始化符号表
    init_symbol_table();
    
    // 记录语义分析开始时间
    start_timer(&compile_timing.sem_start);
    
    // 执行语义分析
    if (result == 0 && ast_root) {
        printf("\n=== 开始语义分析 ===\n");
        semantic_check(ast_root);
        printf("语义分析完成\n");
    }
    
    // 记录语义分析结束时间
    record_sem_time();
    
    // 打印符号表
    print_symbol_table();
 
    // 打印符号表
    //printSymbolTable();
    
    // 计算总编译时间
    compile_timing.total_time = ((double)(clock() - total_start)) / CLOCKS_PER_SEC * 1000.0;
    
    // 打印编译性能分析
    printCompileTiming();
    
    // 释放语法树内存
    if (ast_root) 
    {
        freeAST(ast_root);
        ast_root = NULL;
    }
    
    if (argc > 1) 
    {
        fclose(yyin);
    }
    
    return result;
}
