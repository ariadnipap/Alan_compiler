/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

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

#include <cstdio>
#include "ast.hpp"
#include "lexer.hpp"

#define YYLTYPE_IS_TRIVIAL 1
#define YYERROR_VERBOSE 1

// Global symbol/context tables renamed in ast.hpp:
SymbolsManager symbolTable;
RuntimeContext contextTracker;
std::string indentationSpaces;

#line 84 "parser.cpp"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    T_byte = 258,
    T_int = 259,
    T_if = 260,
    T_else = 261,
    T_true = 262,
    T_false = 263,
    T_proc = 264,
    T_reference = 265,
    T_return = 266,
    T_while = 267,
    T_id = 268,
    T_const = 269,
    T_char = 270,
    T_string = 271,
    T_equal = 272,
    T_notEq = 273,
    T_lessEq = 274,
    T_moreEq = 275
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "parser.y"

    ExpressionSequence *expressions;
    ExpressionNode     *expression;
    StatementNode      *statement;
    CompoundStatement  *compoundNode;
    LocalDefinition    *localDef;
    DefinitionList     *defList;
    ParameterList      *fparList;
    FunctionParameter  *singleFpar;
    FunctionCall       *funcInvocation;
    LeftValue          *lval;
    ConditionNode      *condition;

    RType               rtype;
    std::string        *var;
    int                 num;
    char                character;
    char                op;

#line 177 "parser.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */



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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYLAST   202

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

#define YYUNDEFTOK  2
#define YYMAXUTOK   275


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,     2,     2,    29,    22,     2,
      31,    32,    27,    25,    34,    26,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    33,    37,
      24,    38,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    21,    40,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    99,   118,   121,   132,   137,   145,   150,
     161,   162,   166,   170,   178,   182,   192,   196,   206,   211,
     222,   227,   232,   236,   241,   246,   251,   256,   261,   272,
     280,   283,   294,   299,   310,   315,   326,   331,   336,   340,
     344,   348,   353,   358,   363,   368,   373,   378,   389,   394,
     399,   410,   415,   420,   424,   429,   434,   439,   444,   449,
     454,   459,   464
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"byte\"", "\"int\"", "\"if\"",
  "\"else\"", "\"true\"", "\"false\"", "\"proc\"", "\"reference\"",
  "\"return\"", "\"while\"", "T_id", "T_const", "T_char", "T_string",
  "\"==\"", "\"!=\"", "\"<=\"", "\">=\"", "'|'", "'&'", "'>'", "'<'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "'('", "')'", "':'", "','",
  "'['", "']'", "';'", "'='", "'{'", "'}'", "$accept",
  "functionDefinition", "local_definition_list", "fpar_list", "fpar_def",
  "data_type", "typeSpec", "r_type", "local_definition",
  "variableDefinition", "stmt", "compound_stmt", "compound_stmt_helper",
  "func_call", "expr_list", "expr", "l_value", "cond", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   124,    38,    62,    60,    43,    45,    42,    47,    37,
      33,    40,    41,    58,    44,    91,    93,    59,    61,   123,
     125
};
# endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,   -16,    18,     4,   -93,   -14,     2,    17,   -93,    71,
      83,     9,    12,   -93,   -93,   105,    13,   -93,   -93,   -93,
     -93,    83,   -93,   -93,    22,    -6,   -93,   -93,   151,   -93,
     -93,   -93,   -93,   -93,    -6,   105,    15,   -93,   164,    37,
     100,    62,   -23,   -93,   -93,   -93,   -93,   -93,    67,    89,
      39,   -93,    81,   -93,   -93,   108,   108,   108,   -93,   -93,
      73,   -93,    81,   104,   108,   -93,   108,    92,   -93,   -93,
      81,    81,   139,   -18,    56,    56,   161,   108,   108,   108,
     108,   108,   -93,    35,   -93,   168,   169,   149,   144,    95,
     -93,   123,    48,   108,   108,   108,   108,   108,   108,    81,
      81,    66,   -93,    56,    56,   -93,   -93,   -93,    66,   -93,
     108,   -93,   -93,   -93,   -93,   169,   169,   169,   169,   169,
     169,   116,   -93,   138,   -93,   169,    66,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     6,     0,
       0,     0,     0,    11,    10,     0,    12,     9,    15,    14,
       4,     0,     7,     8,     0,     0,     4,    13,     0,    30,
      16,     5,    17,     3,     0,     0,     0,     2,     0,     0,
       0,     0,    48,    50,    20,    29,    31,    22,     0,     0,
       0,    18,     0,    36,    37,     0,     0,     0,    27,    40,
       0,    38,     0,     0,     0,    23,     0,     0,    51,    52,
       0,     0,     0,     0,    41,    42,     0,     0,     0,     0,
       0,     0,    28,     0,    32,     0,    34,     0,     0,     0,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    43,    44,    45,    46,    47,     0,    33,
       0,    49,    21,    19,    53,    55,    56,    59,    60,    58,
      57,    62,    61,    24,    26,    35,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   145,   127,   -93,   142,     3,   146,   158,   -93,   -93,
     -92,    16,   -93,   -36,   -93,   -34,   -35,   -60
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    30,    25,     7,     8,    16,    17,    20,    31,    32,
      46,    47,    36,    59,    85,    72,    61,    73
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    49,    83,    99,   100,     1,    60,    28,    63,   123,
      90,    92,    64,    19,   101,     3,   124,     5,     4,     9,
      39,    74,    75,    76,    19,     5,    40,    41,    42,    86,
      87,    43,    88,    29,   127,    10,     6,    91,    38,   121,
     122,    33,    21,   103,   104,   105,   106,   107,    24,    11,
      37,    12,    44,    67,    29,    45,    99,   100,    27,   115,
     116,   117,   118,   119,   120,    48,    49,   108,    52,    99,
     100,    39,    48,    49,    13,    14,   125,    40,    41,    42,
     114,    15,    43,    79,    80,    81,    13,    14,    68,    69,
      48,    49,    18,    62,    42,    53,    54,    43,    77,    78,
      79,    80,    81,    44,    65,    29,    55,    56,    13,    14,
      82,    70,    71,    42,    53,    54,    43,    42,    53,    54,
      43,    42,    53,    54,    43,    55,    56,    66,    89,    55,
      56,    57,   113,    55,    56,    57,    84,    58,   100,    57,
      93,    94,    95,    96,   126,     2,    97,    98,    77,    78,
      79,    80,    81,    34,    22,   102,    93,    94,    95,    96,
       0,    23,    97,    98,    77,    78,    79,    80,    81,    77,
      78,    79,    80,    81,    77,    78,    79,    80,    81,    26,
       0,   112,     3,     0,    35,   111,    77,    78,    79,    80,
      81,     0,     0,   102,    77,    78,    79,    80,    81,    50,
     109,    51,   110
};

static const yytype_int8 yycheck[] =
{
      36,    36,    62,    21,    22,    13,    40,    13,    31,   101,
      70,    71,    35,    10,    32,    31,   108,    13,     0,    33,
       5,    55,    56,    57,    21,    13,    11,    12,    13,    63,
      64,    16,    66,    39,   126,    33,    32,    71,    35,    99,
     100,    25,    33,    77,    78,    79,    80,    81,    35,    32,
      34,    34,    37,    14,    39,    40,    21,    22,    36,    93,
      94,    95,    96,    97,    98,   101,   101,    32,    31,    21,
      22,     5,   108,   108,     3,     4,   110,    11,    12,    13,
      32,    10,    16,    27,    28,    29,     3,     4,     7,     8,
     126,   126,     9,    31,    13,    14,    15,    16,    25,    26,
      27,    28,    29,    37,    37,    39,    25,    26,     3,     4,
      37,    30,    31,    13,    14,    15,    16,    13,    14,    15,
      16,    13,    14,    15,    16,    25,    26,    38,    36,    25,
      26,    31,    37,    25,    26,    31,    32,    37,    22,    31,
      17,    18,    19,    20,     6,     0,    23,    24,    25,    26,
      27,    28,    29,    26,    12,    32,    17,    18,    19,    20,
      -1,    15,    23,    24,    25,    26,    27,    28,    29,    25,
      26,    27,    28,    29,    25,    26,    27,    28,    29,    21,
      -1,    37,    31,    -1,    33,    36,    25,    26,    27,    28,
      29,    -1,    -1,    32,    25,    26,    27,    28,    29,    35,
      32,    37,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    13,    42,    31,     0,    13,    32,    44,    45,    33,
      33,    32,    34,     3,     4,    10,    46,    47,     9,    46,
      48,    33,    45,    47,    35,    43,    48,    36,    13,    39,
      42,    49,    50,    52,    43,    33,    53,    52,    46,     5,
      11,    12,    13,    16,    37,    40,    51,    52,    54,    57,
      35,    37,    31,    14,    15,    25,    26,    31,    37,    54,
      56,    57,    31,    31,    35,    37,    38,    14,     7,     8,
      30,    31,    56,    58,    56,    56,    56,    25,    26,    27,
      28,    29,    37,    58,    32,    55,    56,    56,    56,    36,
      58,    56,    58,    17,    18,    19,    20,    23,    24,    21,
      22,    32,    32,    56,    56,    56,    56,    56,    32,    32,
      34,    36,    37,    37,    32,    56,    56,    56,    56,    56,
      56,    58,    58,    51,    51,    56,     6,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    47,    47,    48,    48,    49,    49,    50,    50,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    57,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     7,     0,     2,     1,     3,     4,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     4,     7,
       1,     4,     1,     2,     5,     7,     5,     2,     3,     3,
       0,     2,     3,     4,     1,     3,     1,     1,     1,     3,
       1,     2,     2,     3,     3,     3,     3,     3,     1,     4,
       1,     1,     1,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 91 "parser.y"
    {
        // With formal parameters
        (yyval.localDef) = new FunctionDefinition((yyvsp[-7].var), (yyvsp[-5].fparList), (yyvsp[-2].rtype), (yyvsp[-1].defList), (yyvsp[0].compoundNode));
        (yyval.localDef)->setLine((yylsp[-7]).first_line);
        // Perform semantic check & can execute if desired:
        (yyval.localDef)->semanticCheck();
        // $$->execute();
    }
#line 1568 "parser.cpp"
    break;

  case 3:
#line 100 "parser.y"
    {
        // No formal parameters
        (yyval.localDef) = new FunctionDefinition((yyvsp[-6].var), (yyvsp[-2].rtype), (yyvsp[-1].defList), (yyvsp[0].compoundNode));
        (yyval.localDef)->setLine((yylsp[-6]).first_line);
        (yyval.localDef)->semanticCheck();
        // $$->execute();
    }
#line 1580 "parser.cpp"
    break;

  case 4:
#line 118 "parser.y"
    {
        (yyval.defList) = new DefinitionList();
    }
#line 1588 "parser.cpp"
    break;

  case 5:
#line 122 "parser.y"
    {
        (yyvsp[-1].defList)->addDefinition((yyvsp[0].localDef));
        (yyval.defList) = (yyvsp[-1].defList);
    }
#line 1597 "parser.cpp"
    break;

  case 6:
#line 133 "parser.y"
    {
        (yyval.fparList) = new ParameterList();
        (yyval.fparList)->addParameter((yyvsp[0].singleFpar));
    }
#line 1606 "parser.cpp"
    break;

  case 7:
#line 138 "parser.y"
    {
        (yyvsp[-2].fparList)->addParameter((yyvsp[0].singleFpar));
        (yyval.fparList) = (yyvsp[-2].fparList);
    }
#line 1615 "parser.cpp"
    break;

  case 8:
#line 146 "parser.y"
    {
        (yyval.singleFpar) = new FunctionParameter((yyvsp[-3].var), true, (yyvsp[0].rtype));
        (yyval.singleFpar)->setLine((yylsp[-3]).first_line);
    }
#line 1624 "parser.cpp"
    break;

  case 9:
#line 151 "parser.y"
    {
        (yyval.singleFpar) = new FunctionParameter((yyvsp[-2].var), false, (yyvsp[0].rtype));
        (yyval.singleFpar)->setLine((yylsp[-2]).first_line);
    }
#line 1633 "parser.cpp"
    break;

  case 10:
#line 161 "parser.y"
           { (yyval.rtype) = TYPE_int; }
#line 1639 "parser.cpp"
    break;

  case 11:
#line 162 "parser.y"
           { (yyval.rtype) = TYPE_char; }
#line 1645 "parser.cpp"
    break;

  case 12:
#line 167 "parser.y"
    {
        (yyval.rtype) = (yyvsp[0].rtype);
    }
#line 1653 "parser.cpp"
    break;

  case 13:
#line 171 "parser.y"
    {
        if ((yyvsp[-2].rtype) == TYPE_int) (yyval.rtype) = TYPE_int_array;
        else                (yyval.rtype) = TYPE_char_array;
    }
#line 1662 "parser.cpp"
    break;

  case 14:
#line 179 "parser.y"
    {
        (yyval.rtype) = (yyvsp[0].rtype);
    }
#line 1670 "parser.cpp"
    break;

  case 15:
#line 183 "parser.y"
    {
        (yyval.rtype) = TYPE_void;
    }
#line 1678 "parser.cpp"
    break;

  case 16:
#line 193 "parser.y"
    {
        (yyval.localDef) = (yyvsp[0].localDef);
    }
#line 1686 "parser.cpp"
    break;

  case 17:
#line 197 "parser.y"
    {
        (yyval.localDef) = (yyvsp[0].localDef);
    }
#line 1694 "parser.cpp"
    break;

  case 18:
#line 207 "parser.y"
    {
        (yyval.localDef) = new VariableDefinition((yyvsp[-3].var), (yyvsp[-1].rtype));
        (yyval.localDef)->setLine((yylsp[-3]).first_line);
    }
#line 1703 "parser.cpp"
    break;

  case 19:
#line 212 "parser.y"
    {
        (yyval.localDef) = new VariableDefinition((yyvsp[-6].var), (yyvsp[-4].rtype), (yyvsp[-2].num));
        (yyval.localDef)->setLine((yylsp[-6]).first_line);
    }
#line 1712 "parser.cpp"
    break;

  case 20:
#line 223 "parser.y"
    {
        (yyval.statement) = new EmptyStatement();
        (yyval.statement)->setLine((yylsp[0]).first_line);
    }
#line 1721 "parser.cpp"
    break;

  case 21:
#line 228 "parser.y"
    {
        (yyval.statement) = new AssignmentStatement(dynamic_cast<LeftValueID*>((yyvsp[-3].lval)), (yyvsp[-1].expression));
        (yyval.statement)->setLine((yylsp[-3]).first_line);
    }
#line 1730 "parser.cpp"
    break;

  case 22:
#line 233 "parser.y"
    {
        (yyval.statement) = (yyvsp[0].compoundNode);
    }
#line 1738 "parser.cpp"
    break;

  case 23:
#line 237 "parser.y"
    {
        // cast to StatementNode if needed, but FunctionCall is both
        (yyval.statement) = (yyvsp[-1].funcInvocation);
    }
#line 1747 "parser.cpp"
    break;

  case 24:
#line 242 "parser.y"
    {
        (yyval.statement) = new IfStatement((yyvsp[-2].condition), (yyvsp[0].statement));
        (yyval.statement)->setLine((yylsp[-4]).first_line);
    }
#line 1756 "parser.cpp"
    break;

  case 25:
#line 247 "parser.y"
    {
        (yyval.statement) = new IfStatement((yyvsp[-4].condition), (yyvsp[-2].statement), (yyvsp[0].statement));
        (yyval.statement)->setLine((yylsp[-6]).first_line);
    }
#line 1765 "parser.cpp"
    break;

  case 26:
#line 252 "parser.y"
    {
        (yyval.statement) = new WhileLoop((yyvsp[-2].condition), (yyvsp[0].statement));
        (yyval.statement)->setLine((yylsp[-4]).first_line);
    }
#line 1774 "parser.cpp"
    break;

  case 27:
#line 257 "parser.y"
    {
        (yyval.statement) = new ReturnStatement();
        (yyval.statement)->setLine((yylsp[-1]).first_line);
    }
#line 1783 "parser.cpp"
    break;

  case 28:
#line 262 "parser.y"
    {
        (yyval.statement) = new ReturnStatement((yyvsp[-1].expression));
        (yyval.statement)->setLine((yylsp[-2]).first_line);
    }
#line 1792 "parser.cpp"
    break;

  case 29:
#line 273 "parser.y"
    {
        (yyval.compoundNode) = (yyvsp[-1].compoundNode);
    }
#line 1800 "parser.cpp"
    break;

  case 30:
#line 280 "parser.y"
    {
        (yyval.compoundNode) = new CompoundStatement();
    }
#line 1808 "parser.cpp"
    break;

  case 31:
#line 284 "parser.y"
    {
        (yyvsp[-1].compoundNode)->addStatement((yyvsp[0].statement));
        (yyval.compoundNode) = (yyvsp[-1].compoundNode);
    }
#line 1817 "parser.cpp"
    break;

  case 32:
#line 295 "parser.y"
    {
        (yyval.funcInvocation) = new FunctionCall((yyvsp[-2].var));
        (yyval.funcInvocation)->ExpressionNode::setLine((yylsp[-2]).first_line);
    }
#line 1826 "parser.cpp"
    break;

  case 33:
#line 300 "parser.y"
    {
        (yyval.funcInvocation) = new FunctionCall((yyvsp[-3].var), (yyvsp[-1].expressions));
        (yyval.funcInvocation)->ExpressionNode::setLine((yylsp[-3]).first_line);
    }
#line 1835 "parser.cpp"
    break;

  case 34:
#line 311 "parser.y"
    {
        (yyval.expressions) = new ExpressionSequence();
        (yyval.expressions)->addExpression((yyvsp[0].expression));
    }
#line 1844 "parser.cpp"
    break;

  case 35:
#line 316 "parser.y"
    {
        (yyvsp[-2].expressions)->addExpression((yyvsp[0].expression));
        (yyval.expressions) = (yyvsp[-2].expressions);
    }
#line 1853 "parser.cpp"
    break;

  case 36:
#line 327 "parser.y"
    {
        (yyval.expression) = new IntegerConstant((yyvsp[0].num));
        (yyval.expression)->setLine((yylsp[0]).first_line);
    }
#line 1862 "parser.cpp"
    break;

  case 37:
#line 332 "parser.y"
    {
        (yyval.expression) = new CharConstant((yyvsp[0].character));
        (yyval.expression)->setLine((yylsp[0]).first_line);
    }
#line 1871 "parser.cpp"
    break;

  case 38:
#line 337 "parser.y"
    {
        (yyval.expression) = (yyvsp[0].lval);
    }
#line 1879 "parser.cpp"
    break;

  case 39:
#line 341 "parser.y"
    {
        (yyval.expression) = (yyvsp[-1].expression);
    }
#line 1887 "parser.cpp"
    break;

  case 40:
#line 345 "parser.y"
    {
        (yyval.expression) = (yyvsp[0].funcInvocation);
    }
#line 1895 "parser.cpp"
    break;

  case 41:
#line 349 "parser.y"
    {
        (yyval.expression) = new UnaryOpExpression((yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1904 "parser.cpp"
    break;

  case 42:
#line 354 "parser.y"
    {
        (yyval.expression) = new UnaryOpExpression((yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1913 "parser.cpp"
    break;

  case 43:
#line 359 "parser.y"
    {
        (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1922 "parser.cpp"
    break;

  case 44:
#line 364 "parser.y"
    {
        (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1931 "parser.cpp"
    break;

  case 45:
#line 369 "parser.y"
    {
        (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1940 "parser.cpp"
    break;

  case 46:
#line 374 "parser.y"
    {
        (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1949 "parser.cpp"
    break;

  case 47:
#line 379 "parser.y"
    {
        (yyval.expression) = new BinaryOpExpression((yyvsp[-2].expression), (yyvsp[-1].op), (yyvsp[0].expression));
        (yyval.expression)->setLine((yylsp[-1]).first_line);
    }
#line 1958 "parser.cpp"
    break;

  case 48:
#line 390 "parser.y"
    {
        (yyval.lval) = new LeftValueID((yyvsp[0].var));
        (yyval.lval)->setLine((yylsp[0]).first_line);
    }
#line 1967 "parser.cpp"
    break;

  case 49:
#line 395 "parser.y"
    {
        (yyval.lval) = new LeftValueID((yyvsp[-3].var), (yyvsp[-1].expression));
        (yyval.lval)->setLine((yylsp[-3]).first_line);
    }
#line 1976 "parser.cpp"
    break;

  case 50:
#line 400 "parser.y"
    {
        (yyval.lval) = new LeftValueString((yyvsp[0].var));
        (yyval.lval)->setLine((yylsp[0]).first_line);
    }
#line 1985 "parser.cpp"
    break;

  case 51:
#line 411 "parser.y"
    {
        (yyval.condition) = new BooleanConstant(true);
        (yyval.condition)->setLine((yylsp[0]).first_line);
    }
#line 1994 "parser.cpp"
    break;

  case 52:
#line 416 "parser.y"
    {
        (yyval.condition) = new BooleanConstant(false);
        (yyval.condition)->setLine((yylsp[0]).first_line);
    }
#line 2003 "parser.cpp"
    break;

  case 53:
#line 421 "parser.y"
    {
        (yyval.condition) = (yyvsp[-1].condition);
    }
#line 2011 "parser.cpp"
    break;

  case 54:
#line 425 "parser.y"
    {
        (yyval.condition) = new ConditionalUnaryOp((yyvsp[-1].op), (yyvsp[0].condition));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2020 "parser.cpp"
    break;

  case 55:
#line 430 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].expression), 'e', (yyvsp[0].expression));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2029 "parser.cpp"
    break;

  case 56:
#line 435 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].expression), 'n', (yyvsp[0].expression));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2038 "parser.cpp"
    break;

  case 57:
#line 440 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].expression), '<', (yyvsp[0].expression));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2047 "parser.cpp"
    break;

  case 58:
#line 445 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].expression), '>', (yyvsp[0].expression));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2056 "parser.cpp"
    break;

  case 59:
#line 450 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].expression), 'l', (yyvsp[0].expression));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2065 "parser.cpp"
    break;

  case 60:
#line 455 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].expression), 'm', (yyvsp[0].expression));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2074 "parser.cpp"
    break;

  case 61:
#line 460 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].condition), '&', (yyvsp[0].condition));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2083 "parser.cpp"
    break;

  case 62:
#line 465 "parser.y"
    {
        (yyval.condition) = new ConditionalBinaryOp((yyvsp[-2].condition), '|', (yyvsp[0].condition));
        (yyval.condition)->setLine((yylsp[-1]).first_line);
    }
#line 2092 "parser.cpp"
    break;


#line 2096 "parser.cpp"

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
  *++yylsp = yyloc;

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 471 "parser.y"


//-------------------------------
// MAIN
//-------------------------------
int main() {
    int parseResult = yyparse();
    if (parseResult == 0)
        printf("Success.\n");
    return parseResult;
}


