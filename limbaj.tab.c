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
#line 1 "limbaj.y"

#include "symbol_table.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <list>
using namespace std;
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
extern int yydebug;
extern int yylex();
void yyerror(const char * s);
std::vector<struct Variable*> params;
char scope[100];
char prev_scope[100];

#line 89 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_FUNC_DECL = 3,                  /* FUNC_DECL  */
  YYSYMBOL_MAIN = 4,                       /* MAIN  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_CONSTRUCTOR = 6,                /* CONSTRUCTOR  */
  YYSYMBOL_ACC_MOD = 7,                    /* ACC_MOD  */
  YYSYMBOL_EVAL = 8,                       /* EVAL  */
  YYSYMBOL_TYPEOF = 9,                     /* TYPEOF  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_RETURN = 14,                    /* RETURN  */
  YYSYMBOL_ASSIGN = 15,                    /* ASSIGN  */
  YYSYMBOL_PLUS = 16,                      /* PLUS  */
  YYSYMBOL_MINUS = 17,                     /* MINUS  */
  YYSYMBOL_TIMES = 18,                     /* TIMES  */
  YYSYMBOL_DIVIDE = 19,                    /* DIVIDE  */
  YYSYMBOL_MOD = 20,                       /* MOD  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_AND = 22,                       /* AND  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_STRING_VALUE = 24,              /* STRING_VALUE  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_TYPE = 26,                      /* TYPE  */
  YYSYMBOL_VAR_MOD = 27,                   /* VAR_MOD  */
  YYSYMBOL_REL_OP = 28,                    /* REL_OP  */
  YYSYMBOL_CHAR_VALUE = 29,                /* CHAR_VALUE  */
  YYSYMBOL_INT_VALUE = 30,                 /* INT_VALUE  */
  YYSYMBOL_FLOAT_VALUE = 31,               /* FLOAT_VALUE  */
  YYSYMBOL_BOOL_VALUE = 32,                /* BOOL_VALUE  */
  YYSYMBOL_CONCAT = 33,                    /* CONCAT  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* ','  */
  YYSYMBOL_37_ = 37,                       /* ':'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '['  */
  YYSYMBOL_42_ = 42,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 43,                  /* $accept  */
  YYSYMBOL_initial = 44,                   /* initial  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_eval_func = 46,                 /* eval_func  */
  YYSYMBOL_typeof_func = 47,               /* typeof_func  */
  YYSYMBOL_globalVar_section = 48,         /* globalVar_section  */
  YYSYMBOL_func_section = 49,              /* func_section  */
  YYSYMBOL_function = 50,                  /* function  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_52_3 = 52,                      /* $@3  */
  YYSYMBOL_param_list_opt = 53,            /* param_list_opt  */
  YYSYMBOL_param_list = 54,                /* param_list  */
  YYSYMBOL_param = 55,                     /* param  */
  YYSYMBOL_func_body = 56,                 /* func_body  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_assign_variable = 58,           /* assign_variable  */
  YYSYMBOL_update_variable = 59,           /* update_variable  */
  YYSYMBOL_create_global_variable = 60,    /* create_global_variable  */
  YYSYMBOL_if_statement = 61,              /* if_statement  */
  YYSYMBOL_while_statement = 62,           /* while_statement  */
  YYSYMBOL_for_statement = 63,             /* for_statement  */
  YYSYMBOL_return_statement = 64,          /* return_statement  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_number_expression = 66,         /* number_expression  */
  YYSYMBOL_string_expression = 67,         /* string_expression  */
  YYSYMBOL_bool_expression = 68,           /* bool_expression  */
  YYSYMBOL_func_call = 69,                 /* func_call  */
  YYSYMBOL_param_call_list = 70,           /* param_call_list  */
  YYSYMBOL_main_section = 71,              /* main_section  */
  YYSYMBOL_72_4 = 72,                      /* $@4  */
  YYSYMBOL_class_section = 73,             /* class_section  */
  YYSYMBOL_class = 74,                     /* class  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_class_body = 76,                /* class_body  */
  YYSYMBOL_attribute_section = 77,         /* attribute_section  */
  YYSYMBOL_attribute = 78,                 /* attribute  */
  YYSYMBOL_method_section = 79,            /* method_section  */
  YYSYMBOL_constructor = 80,               /* constructor  */
  YYSYMBOL_methods = 81,                   /* methods  */
  YYSYMBOL_method = 82,                    /* method  */
  YYSYMBOL_83_6 = 83,                      /* $@6  */
  YYSYMBOL_84_7 = 84,                      /* $@7  */
  YYSYMBOL_param_list_method_opt = 85,     /* param_list_method_opt  */
  YYSYMBOL_param_list_method = 86          /* param_list_method  */
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
typedef yytype_int16 yy_state_t;

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
#define YYLAST   416

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  290

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
      34,    35,     2,     2,    36,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    37,    40,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    41,     2,    42,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
static const yytype_int16 yyrline[] =
{
       0,    56,    56,    56,    59,    60,    63,    66,    67,    70,
      71,    74,    74,    74,    77,    78,    81,    82,    85,    88,
      89,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     103,   104,   105,   108,   109,   110,   113,   114,   115,   118,
     119,   122,   125,   127,   128,   131,   132,   133,   134,   135,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     171,   172,   173,   176,   177,   178,   179,   180,   181,   182,
     183,   186,   187,   188,   189,   191,   192,   193,   194,   196,
     197,   198,   199,   200,   201,   202,   205,   206,   209,   210,
     213,   213,   216,   217,   220,   220,   223,   224,   225,   228,
     229,   232,   233,   234,   237,   238,   239,   242,   245,   246,
     249,   249,   249,   252,   253,   256,   257
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
  "\"end of file\"", "error", "\"invalid token\"", "FUNC_DECL", "MAIN",
  "CLASS", "CONSTRUCTOR", "ACC_MOD", "EVAL", "TYPEOF", "IF", "ELSE",
  "WHILE", "FOR", "RETURN", "ASSIGN", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "MOD", "NOT", "AND", "OR", "STRING_VALUE", "ID", "TYPE", "VAR_MOD",
  "REL_OP", "CHAR_VALUE", "INT_VALUE", "FLOAT_VALUE", "BOOL_VALUE",
  "CONCAT", "'('", "')'", "','", "':'", "'{'", "'}'", "';'", "'['", "']'",
  "$accept", "initial", "$@1", "eval_func", "typeof_func",
  "globalVar_section", "func_section", "function", "$@2", "$@3",
  "param_list_opt", "param_list", "param", "func_body", "statement",
  "assign_variable", "update_variable", "create_global_variable",
  "if_statement", "while_statement", "for_statement", "return_statement",
  "expression", "number_expression", "string_expression",
  "bool_expression", "func_call", "param_call_list", "main_section", "$@4",
  "class_section", "class", "$@5", "class_body", "attribute_section",
  "attribute", "method_section", "constructor", "methods", "method", "$@6",
  "$@7", "param_list_method_opt", "param_list_method", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-190)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -190,    28,    11,  -190,    40,     9,  -190,  -190,    41,     4,
    -190,  -190,    30,   145,    49,    72,  -190,  -190,    14,    64,
      61,  -190,  -190,  -190,   114,    77,    87,    92,    14,  -190,
    -190,   129,   129,  -190,    -7,    97,   115,   117,   136,   151,
    -190,  -190,  -190,   139,   129,  -190,   212,  -190,   135,   136,
     144,   143,  -190,   152,   168,   183,   177,   176,  -190,    85,
     178,   107,   179,   158,   358,    16,   224,   174,   191,  -190,
    -190,  -190,   196,   192,   190,  -190,   201,   202,   209,   136,
      -6,   198,   136,   275,   191,  -190,   108,    47,    67,   113,
     271,   279,   232,   240,   281,   121,   200,   128,   289,   291,
     299,   301,   309,   311,   319,   321,   329,   331,   248,   256,
     275,   -18,   203,  -190,   339,   208,   213,   136,   188,  -190,
     188,  -190,   212,  -190,   214,   217,   226,  -190,   363,   339,
    -190,   363,  -190,   363,  -190,   363,  -190,   363,  -190,   275,
    -190,   275,  -190,   363,  -190,   226,  -190,  -190,  -190,    13,
     226,  -190,   363,  -190,   363,  -190,   363,  -190,   363,  -190,
     363,  -190,   363,  -190,   363,  -190,   363,  -190,   363,  -190,
     363,  -190,   275,  -190,   275,  -190,  -190,  -190,   363,  -190,
    -190,   234,  -190,   233,   241,   242,   249,   250,   212,   -12,
     243,   245,   259,    75,  -190,   260,   267,  -190,  -190,  -190,
     268,   277,    95,   278,   263,   290,   293,  -190,   212,  -190,
     224,   312,   224,   224,   320,  -190,   212,    69,   162,  -190,
    -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,   298,
     322,  -190,   328,   -10,   323,   332,   333,   336,   317,  -190,
     330,   342,   359,   356,  -190,  -190,   188,  -190,  -190,  -190,
     349,   350,   224,   374,   375,   376,   351,   354,   146,   188,
     188,   355,   212,   212,   212,   357,   188,  -190,   360,   361,
     371,  -190,  -190,  -190,   372,   181,   386,  -190,    -9,   366,
    -190,  -190,   364,   365,   188,   188,   367,   368,  -190,  -190
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,   113,   114,     0,     0,
       8,   112,     0,     0,     0,   110,    10,     7,     0,     0,
       0,    11,     9,     3,     0,     0,     0,     0,   116,   120,
     117,   125,   126,   129,     0,     0,     0,     0,   133,   130,
     115,   119,   118,     0,   124,   128,     0,    36,     0,    14,
       0,     0,   136,     0,   134,     0,     0,     0,   130,     0,
      89,    49,    90,    81,    82,   105,     0,     0,    45,    46,
      47,    48,     0,     0,    15,    17,     0,     0,     0,     0,
       0,     0,   133,   101,     0,   100,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,    18,
       0,   135,     0,   121,     0,     0,    86,    85,    51,     0,
      50,    53,    52,    55,    54,    57,    56,    59,    58,    92,
      91,    94,    93,   104,   103,    84,    83,   107,   109,     0,
      88,    87,    61,    60,    63,    62,    65,    64,    67,    66,
      69,    68,    71,    70,    73,    72,    75,    74,    77,    76,
      79,    78,    96,    95,    98,    97,    80,    99,     0,   102,
      38,     0,    16,     0,     0,     0,     0,     0,    44,     0,
       0,     0,     0,     0,    20,     0,     0,    23,    24,    25,
       0,     0,     0,     0,     0,     0,     0,   106,     0,    12,
       0,     0,     0,     0,     0,    43,     0,     0,     0,    28,
      29,   111,    19,    21,    22,    27,    26,   127,   122,     0,
       0,   108,     0,     0,     0,     0,     0,     0,     0,    33,
       0,     0,     0,     0,   123,   131,     0,     4,     5,     6,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,     0,     0,
       0,    35,    34,    32,     0,     0,    40,    41,     0,     0,
      31,   132,     0,     0,     0,     0,     0,     0,    39,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -190,  -190,  -190,  -190,  -190,  -190,  -190,   389,  -190,  -190,
    -190,  -190,   -44,  -118,  -189,   194,   140,   396,  -190,  -190,
    -190,  -190,   -95,   -47,   -71,   -29,   -46,  -190,  -190,  -190,
    -190,   404,  -190,  -190,  -190,   383,   384,  -190,   382,   -21,
    -190,  -190,   334,  -190
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,   191,   192,     9,    15,    16,    36,   232,
      73,    74,    52,   193,   194,   195,   196,    10,   197,   198,
     199,   200,    67,    68,    69,    70,   201,   149,    23,    24,
       5,     6,    12,    27,    28,    29,    30,    31,    32,    33,
      57,   257,    53,    54
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      71,   148,   202,   216,   222,    75,   216,    14,    46,   122,
     114,    45,    84,   222,     4,   127,     4,   176,   114,   111,
      25,    26,    96,    45,   146,   247,   151,   203,     3,   217,
      85,     8,   217,    47,   123,   121,     8,   112,   108,   109,
     130,   132,   134,   136,   138,    84,    84,   144,   207,   208,
      71,   153,   155,   157,   159,   161,   163,   165,   167,   169,
     171,    84,    84,   140,   142,     7,    13,   179,    18,   222,
     268,   269,   128,   182,    21,    14,    71,    63,    64,   173,
     175,   129,   206,   183,   184,   185,   222,   186,   187,   188,
      34,    35,   131,   215,   240,   286,   287,    63,    64,   241,
     189,   129,   190,   183,   184,   185,    59,   186,   187,   188,
      83,    38,    39,   231,   221,    63,    64,    65,    37,    66,
     189,   239,   190,    87,    88,    89,    90,    91,   258,    92,
      93,    40,    60,   126,   227,    94,    43,    62,   133,    48,
      95,    96,    71,    63,    64,    60,   145,   129,   275,    49,
      62,    50,    60,   150,   183,   184,   185,    62,   186,   187,
     188,    51,    71,   233,    58,    84,    84,   271,   272,   273,
      71,   189,    72,   190,    98,    99,   100,   101,   102,    76,
      77,   234,    19,   236,   237,   267,    20,    78,    55,   183,
     184,   185,    56,   186,   187,   188,   183,   184,   185,   242,
     186,   187,   188,   243,    79,    84,   189,    81,   190,    80,
      82,    86,    97,   189,   113,   190,    71,    71,    71,   114,
     281,    59,   115,   261,    60,    61,   117,   116,   119,    62,
      63,    64,    65,    59,    66,   147,    60,    61,   177,   118,
     124,    62,    63,    64,    65,    59,    66,   120,   180,   110,
     181,   204,   205,    59,    63,    64,    65,   139,    66,    95,
     209,    59,    63,    64,    65,   141,    66,   210,   218,    59,
      63,    64,    65,   172,    66,   211,   212,    59,    63,    64,
      65,   174,    66,   213,   214,   219,    63,    64,    65,   229,
      66,    87,    88,    89,    90,    91,   135,    92,    93,   220,
     223,    63,    64,    94,   137,   129,   143,   224,   225,    63,
      64,    63,    64,   129,   152,   129,   154,   226,   228,    63,
      64,    63,    64,   129,   156,   129,   158,   230,   176,    63,
      64,    63,    64,   129,   160,   129,   162,   235,   244,    63,
      64,    63,    64,   129,   164,   129,   166,   190,   245,    63,
      64,    63,    64,   129,   168,   129,   170,   252,   248,    63,
      64,    63,    64,   129,   178,   129,   246,   249,   250,    63,
      64,   251,   253,   129,   103,   104,   105,   106,   107,    87,
      88,    89,    90,    91,   254,   255,   256,   259,   260,   262,
     263,   264,   266,   265,   274,   270,   278,   282,   280,   276,
     277,   283,   284,   285,    22,    17,   288,   289,   238,    11,
     279,    41,    42,    44,     0,     0,   125
};

static const yytype_int16 yycheck[] =
{
      46,    96,   120,    15,   193,    49,    15,     3,    15,    15,
      28,    32,    59,   202,     5,    86,     5,    35,    28,    66,
       6,     7,    34,    44,    95,    35,    97,   122,     0,    41,
      59,    27,    41,    40,    40,    79,    27,    66,    22,    23,
      87,    88,    89,    90,    91,    92,    93,    94,    35,    36,
      96,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    92,    93,    25,    25,   114,    38,   258,
     259,   260,    25,   117,    25,     3,   122,    30,    31,   108,
     109,    34,   129,     8,     9,    10,   275,    12,    13,    14,
      26,    30,    25,   188,    25,   284,   285,    30,    31,    30,
      25,    34,    27,     8,     9,    10,    21,    12,    13,    14,
      25,    34,    25,   208,    39,    30,    31,    32,     4,    34,
      25,   216,    27,    16,    17,    18,    19,    20,   246,    22,
      23,    39,    24,    25,    39,    28,     7,    29,    25,    42,
      33,    34,   188,    30,    31,    24,    25,    34,   266,    34,
      29,    34,    24,    25,     8,     9,    10,    29,    12,    13,
      14,    25,   208,   210,    25,   212,   213,   262,   263,   264,
     216,    25,    37,    27,    16,    17,    18,    19,    20,    35,
      37,   210,    37,   212,   213,    39,    41,    35,    37,     8,
       9,    10,    41,    12,    13,    14,     8,     9,    10,    37,
      12,    13,    14,    41,    36,   252,    25,    30,    27,    26,
      34,    33,    33,    25,    40,    27,   262,   263,   264,    28,
      39,    21,    26,   252,    24,    25,    36,    35,    26,    29,
      30,    31,    32,    21,    34,    35,    24,    25,    35,    38,
      42,    29,    30,    31,    32,    21,    34,    38,    40,    25,
      37,    37,    35,    21,    30,    31,    32,    25,    34,    33,
      26,    21,    30,    31,    32,    25,    34,    34,    25,    21,
      30,    31,    32,    25,    34,    34,    34,    21,    30,    31,
      32,    25,    34,    34,    34,    40,    30,    31,    32,    26,
      34,    16,    17,    18,    19,    20,    25,    22,    23,    40,
      40,    30,    31,    28,    25,    34,    25,    40,    40,    30,
      31,    30,    31,    34,    25,    34,    25,    40,    40,    30,
      31,    30,    31,    34,    25,    34,    25,    37,    35,    30,
      31,    30,    31,    34,    25,    34,    25,    25,    40,    30,
      31,    30,    31,    34,    25,    34,    25,    27,    26,    30,
      31,    30,    31,    34,    25,    34,    25,    40,    35,    30,
      31,    30,    31,    34,    25,    34,    38,    35,    35,    30,
      31,    35,    42,    34,    16,    17,    18,    19,    20,    16,
      17,    18,    19,    20,    42,    26,    30,    38,    38,    15,
      15,    15,    38,    42,    37,    40,    25,    11,    26,    39,
      39,    35,    38,    38,    15,     9,    39,    39,   214,     5,
     270,    28,    28,    31,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    44,    45,     0,     5,    73,    74,    25,    27,    48,
      60,    74,    75,    25,     3,    49,    50,    60,    38,    37,
      41,    25,    50,    71,    72,     6,     7,    76,    77,    78,
      79,    80,    81,    82,    26,    30,    51,     4,    34,    25,
      39,    78,    79,     7,    81,    82,    15,    40,    42,    34,
      34,    25,    55,    85,    86,    37,    41,    83,    25,    21,
      24,    25,    29,    30,    31,    32,    34,    65,    66,    67,
      68,    69,    37,    53,    54,    55,    35,    37,    35,    36,
      26,    30,    34,    25,    66,    68,    33,    16,    17,    18,
      19,    20,    22,    23,    28,    33,    34,    33,    16,    17,
      18,    19,    20,    16,    17,    18,    19,    20,    22,    23,
      25,    66,    68,    40,    28,    26,    35,    36,    38,    26,
      38,    55,    15,    40,    42,    85,    25,    67,    25,    34,
      66,    25,    66,    25,    66,    25,    66,    25,    66,    25,
      68,    25,    68,    25,    66,    25,    67,    35,    65,    70,
      25,    67,    25,    66,    25,    66,    25,    66,    25,    66,
      25,    66,    25,    66,    25,    66,    25,    66,    25,    66,
      25,    66,    25,    68,    25,    68,    35,    35,    25,    66,
      40,    37,    55,     8,     9,    10,    12,    13,    14,    25,
      27,    46,    47,    56,    57,    58,    59,    61,    62,    63,
      64,    69,    56,    65,    37,    35,    66,    35,    36,    26,
      34,    34,    34,    34,    34,    65,    15,    41,    25,    40,
      40,    39,    57,    40,    40,    40,    40,    39,    40,    26,
      37,    65,    52,    66,    68,    25,    68,    68,    58,    65,
      25,    30,    37,    41,    40,    26,    38,    35,    35,    35,
      35,    35,    40,    42,    42,    26,    30,    84,    56,    38,
      38,    68,    15,    15,    15,    42,    38,    39,    57,    57,
      40,    65,    65,    65,    37,    56,    39,    39,    25,    59,
      26,    39,    11,    35,    38,    38,    57,    57,    39,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    43,    45,    44,    46,    46,    47,    48,    48,    49,
      49,    51,    52,    50,    53,    53,    54,    54,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    60,    60,    60,    61,
      61,    62,    63,    64,    64,    65,    65,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    69,    69,    70,    70,
      72,    71,    73,    73,    75,    74,    76,    76,    76,    77,
      77,    78,    78,    78,    79,    79,    79,    80,    81,    81,
      83,    84,    82,    85,    85,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     4,     4,     4,     2,     1,     2,
       1,     0,     0,    12,     0,     1,     3,     1,     3,     2,
       1,     2,     2,     1,     1,     1,     2,     2,     2,     2,
       4,     7,     6,     3,     6,     6,     5,     7,     8,    11,
       7,     7,    11,     2,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     3,     3,     1,     4,     3,     3,     1,
       0,     7,     2,     1,     0,     6,     1,     1,     2,     2,
       1,     5,     7,     8,     2,     1,     1,     7,     2,     1,
       0,     0,    12,     0,     1,     3,     1
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
  case 2: /* $@1: %empty  */
#line 56 "limbaj.y"
         {strcpy(scope, strdup("global"));}
#line 1378 "limbaj.tab.c"
    break;

  case 3: /* initial: $@1 class_section globalVar_section func_section main_section  */
#line 56 "limbaj.y"
                                                                                                      {printf("Correct\n");}
#line 1384 "limbaj.tab.c"
    break;

  case 4: /* eval_func: EVAL '(' number_expression ')'  */
#line 59 "limbaj.y"
                                          {printf("Eval - line %d: %d\n", yylineno, (yyvsp[-1].expr_node)->int_val);}
#line 1390 "limbaj.tab.c"
    break;

  case 5: /* eval_func: EVAL '(' bool_expression ')'  */
#line 60 "limbaj.y"
                                        {char *val; if ((yyvsp[-1].expr_node)->bool_val) { val = strdup("true"); } else { val = strdup("false"); };printf("Eval - line %d: %s\n", yylineno, val);}
#line 1396 "limbaj.tab.c"
    break;

  case 6: /* typeof_func: TYPEOF '(' ID ')'  */
#line 63 "limbaj.y"
                               {printf("Typeof - line %d: %s\n", yylineno, strdup(type_of_def((yyvsp[-1].stringVal), scope)));}
#line 1402 "limbaj.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 74 "limbaj.y"
                       {strcpy(prev_scope, scope); strcpy(scope, (yyvsp[0].stringVal));}
#line 1408 "limbaj.tab.c"
    break;

  case 12: /* $@3: %empty  */
#line 74 "limbaj.y"
                                                                                                       {add_function((yyvsp[-6].stringVal), (yyvsp[0].stringVal), prev_scope, params); params.clear();}
#line 1414 "limbaj.tab.c"
    break;

  case 13: /* function: FUNC_DECL ID $@2 '(' param_list_opt ')' ':' TYPE $@3 '{' func_body '}'  */
#line 74 "limbaj.y"
                                                                                                                                                                                     {strcpy(scope, strdup("global"));}
#line 1420 "limbaj.tab.c"
    break;

  case 18: /* param: ID ':' TYPE  */
#line 85 "limbaj.y"
                   {Variable* temp = create_param((yyvsp[-2].stringVal), (yyvsp[0].stringVal), scope); params.push_back(temp);}
#line 1426 "limbaj.tab.c"
    break;

  case 30: /* assign_variable: VAR_MOD ID ':' TYPE  */
#line 103 "limbaj.y"
                                     {bool isConst; if(strcmp((yyvsp[-3].stringVal), "nomod") == 0){isConst = true;} else {isConst = false;} expr_str *temp = create_empty_value((yyvsp[0].stringVal)); add_variable((yyvsp[-2].stringVal), (yyvsp[0].stringVal), scope, isConst, temp);}
#line 1432 "limbaj.tab.c"
    break;

  case 31: /* assign_variable: VAR_MOD ID '[' INT_VALUE ']' ':' TYPE  */
#line 104 "limbaj.y"
                                                       {bool isConst; if(strcmp((yyvsp[-6].stringVal), "nomod") == 0){isConst = true;} else {isConst = false;} add_vector((yyvsp[-5].stringVal), (yyvsp[0].stringVal), scope, (yyvsp[-3].intVal), isConst);}
#line 1438 "limbaj.tab.c"
    break;

  case 32: /* assign_variable: VAR_MOD ID ':' TYPE ASSIGN expression  */
#line 105 "limbaj.y"
                                                       {bool isConst; if(strcmp((yyvsp[-5].stringVal), "nomod") == 0){isConst = true;} else {isConst = false;} add_variable((yyvsp[-4].stringVal), (yyvsp[-2].stringVal), scope, isConst, (yyvsp[0].expr_node));}
#line 1444 "limbaj.tab.c"
    break;

  case 33: /* update_variable: ID ASSIGN expression  */
#line 108 "limbaj.y"
                                      {update_variable((yyvsp[-2].stringVal), scope, (yyvsp[0].expr_node));}
#line 1450 "limbaj.tab.c"
    break;

  case 34: /* update_variable: ID '[' INT_VALUE ']' ASSIGN expression  */
#line 109 "limbaj.y"
                                                        {expr_str* temp = convert_int((yyvsp[-3].intVal)); update_vector((yyvsp[-5].stringVal), scope, temp, (yyvsp[0].expr_node));}
#line 1456 "limbaj.tab.c"
    break;

  case 35: /* update_variable: ID '[' ID ']' ASSIGN expression  */
#line 110 "limbaj.y"
                                                 {expr_str* temp = convert_from_id((yyvsp[-3].stringVal), scope); update_vector((yyvsp[-5].stringVal), scope, temp, (yyvsp[0].expr_node));}
#line 1462 "limbaj.tab.c"
    break;

  case 36: /* create_global_variable: VAR_MOD ID ':' TYPE ';'  */
#line 113 "limbaj.y"
                                                {bool isConst; if(strcmp((yyvsp[-4].stringVal), "nomod") == 0){isConst = true;} else {isConst = false;} expr_str *temp = create_empty_value((yyvsp[-1].stringVal)); add_variable((yyvsp[-3].stringVal), (yyvsp[-1].stringVal), scope, isConst, temp);}
#line 1468 "limbaj.tab.c"
    break;

  case 37: /* create_global_variable: VAR_MOD ID ':' TYPE ASSIGN expression ';'  */
#line 114 "limbaj.y"
                                                                   {bool isConst; if(strcmp((yyvsp[-6].stringVal), "nomod") == 0){isConst = true;} else {isConst = false;} add_variable((yyvsp[-5].stringVal), (yyvsp[-3].stringVal), scope, isConst, (yyvsp[-1].expr_node));}
#line 1474 "limbaj.tab.c"
    break;

  case 38: /* create_global_variable: VAR_MOD ID '[' INT_VALUE ']' ':' TYPE ';'  */
#line 115 "limbaj.y"
                                                                  {bool isConst; if(strcmp((yyvsp[-7].stringVal), "nomod") == 0){isConst = true;} else {isConst = false;} add_vector((yyvsp[-6].stringVal), (yyvsp[-1].stringVal), scope, (yyvsp[-4].intVal), isConst);}
#line 1480 "limbaj.tab.c"
    break;

  case 45: /* expression: number_expression  */
#line 131 "limbaj.y"
                               {(yyval.expr_node) = (yyvsp[0].expr_node);}
#line 1486 "limbaj.tab.c"
    break;

  case 46: /* expression: string_expression  */
#line 132 "limbaj.y"
                               {(yyval.expr_node) = (yyvsp[0].expr_node);}
#line 1492 "limbaj.tab.c"
    break;

  case 47: /* expression: bool_expression  */
#line 133 "limbaj.y"
                               {(yyval.expr_node) = (yyvsp[0].expr_node);}
#line 1498 "limbaj.tab.c"
    break;

  case 48: /* expression: func_call  */
#line 134 "limbaj.y"
                               {(yyval.expr_node) = (yyvsp[0].expr_node);}
#line 1504 "limbaj.tab.c"
    break;

  case 49: /* expression: ID  */
#line 135 "limbaj.y"
                               {(yyval.expr_node) = convert_from_id((yyvsp[0].stringVal), scope);}
#line 1510 "limbaj.tab.c"
    break;

  case 50: /* number_expression: ID PLUS number_expression  */
#line 138 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '+');}
#line 1516 "limbaj.tab.c"
    break;

  case 51: /* number_expression: ID PLUS ID  */
#line 139 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '+');}
#line 1522 "limbaj.tab.c"
    break;

  case 52: /* number_expression: ID MINUS number_expression  */
#line 140 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '-');}
#line 1528 "limbaj.tab.c"
    break;

  case 53: /* number_expression: ID MINUS ID  */
#line 141 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '-');}
#line 1534 "limbaj.tab.c"
    break;

  case 54: /* number_expression: ID TIMES number_expression  */
#line 142 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '*');}
#line 1540 "limbaj.tab.c"
    break;

  case 55: /* number_expression: ID TIMES ID  */
#line 143 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '*');}
#line 1546 "limbaj.tab.c"
    break;

  case 56: /* number_expression: ID DIVIDE number_expression  */
#line 144 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '/');}
#line 1552 "limbaj.tab.c"
    break;

  case 57: /* number_expression: ID DIVIDE ID  */
#line 145 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '/');}
#line 1558 "limbaj.tab.c"
    break;

  case 58: /* number_expression: ID MOD number_expression  */
#line 146 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '%');}
#line 1564 "limbaj.tab.c"
    break;

  case 59: /* number_expression: ID MOD ID  */
#line 147 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '%');}
#line 1570 "limbaj.tab.c"
    break;

  case 60: /* number_expression: INT_VALUE PLUS number_expression  */
#line 149 "limbaj.y"
                                                             {expr_str* temp = convert_int((yyvsp[-2].intVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '+');}
#line 1576 "limbaj.tab.c"
    break;

  case 61: /* number_expression: INT_VALUE PLUS ID  */
#line 150 "limbaj.y"
                                                             {expr_str* temp1 = convert_int((yyvsp[-2].intVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '+');}
#line 1582 "limbaj.tab.c"
    break;

  case 62: /* number_expression: INT_VALUE MINUS number_expression  */
#line 151 "limbaj.y"
                                                             {expr_str* temp = convert_int((yyvsp[-2].intVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '-');}
#line 1588 "limbaj.tab.c"
    break;

  case 63: /* number_expression: INT_VALUE MINUS ID  */
#line 152 "limbaj.y"
                                                             {expr_str* temp1 = convert_int((yyvsp[-2].intVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '-');}
#line 1594 "limbaj.tab.c"
    break;

  case 64: /* number_expression: INT_VALUE TIMES number_expression  */
#line 153 "limbaj.y"
                                                             {expr_str* temp = convert_int((yyvsp[-2].intVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '*');}
#line 1600 "limbaj.tab.c"
    break;

  case 65: /* number_expression: INT_VALUE TIMES ID  */
#line 154 "limbaj.y"
                                                             {expr_str* temp1 = convert_int((yyvsp[-2].intVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '*');}
#line 1606 "limbaj.tab.c"
    break;

  case 66: /* number_expression: INT_VALUE DIVIDE number_expression  */
#line 155 "limbaj.y"
                                                             {expr_str* temp = convert_int((yyvsp[-2].intVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '/');}
#line 1612 "limbaj.tab.c"
    break;

  case 67: /* number_expression: INT_VALUE DIVIDE ID  */
#line 156 "limbaj.y"
                                                             {expr_str* temp1 = convert_int((yyvsp[-2].intVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '/');}
#line 1618 "limbaj.tab.c"
    break;

  case 68: /* number_expression: INT_VALUE MOD number_expression  */
#line 157 "limbaj.y"
                                                             {expr_str* temp = convert_int((yyvsp[-2].intVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '%');}
#line 1624 "limbaj.tab.c"
    break;

  case 69: /* number_expression: INT_VALUE MOD ID  */
#line 158 "limbaj.y"
                                                             {expr_str* temp1 = convert_int((yyvsp[-2].intVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '%');}
#line 1630 "limbaj.tab.c"
    break;

  case 70: /* number_expression: FLOAT_VALUE PLUS number_expression  */
#line 160 "limbaj.y"
                                                             {expr_str* temp = convert_float((yyvsp[-2].floatVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '+');}
#line 1636 "limbaj.tab.c"
    break;

  case 71: /* number_expression: FLOAT_VALUE PLUS ID  */
#line 161 "limbaj.y"
                                                             {expr_str* temp1 = convert_float((yyvsp[-2].floatVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '+');}
#line 1642 "limbaj.tab.c"
    break;

  case 72: /* number_expression: FLOAT_VALUE MINUS number_expression  */
#line 162 "limbaj.y"
                                                             {expr_str* temp = convert_float((yyvsp[-2].floatVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '-');}
#line 1648 "limbaj.tab.c"
    break;

  case 73: /* number_expression: FLOAT_VALUE MINUS ID  */
#line 163 "limbaj.y"
                                                             {expr_str* temp1 = convert_float((yyvsp[-2].floatVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '-');}
#line 1654 "limbaj.tab.c"
    break;

  case 74: /* number_expression: FLOAT_VALUE TIMES number_expression  */
#line 164 "limbaj.y"
                                                             {expr_str* temp = convert_float((yyvsp[-2].floatVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '*');}
#line 1660 "limbaj.tab.c"
    break;

  case 75: /* number_expression: FLOAT_VALUE TIMES ID  */
#line 165 "limbaj.y"
                                                             {expr_str* temp1 = convert_float((yyvsp[-2].floatVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '*');}
#line 1666 "limbaj.tab.c"
    break;

  case 76: /* number_expression: FLOAT_VALUE DIVIDE number_expression  */
#line 166 "limbaj.y"
                                                             {expr_str* temp = convert_float((yyvsp[-2].floatVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '/');}
#line 1672 "limbaj.tab.c"
    break;

  case 77: /* number_expression: FLOAT_VALUE DIVIDE ID  */
#line 167 "limbaj.y"
                                                             {expr_str* temp1 = convert_float((yyvsp[-2].floatVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '/');}
#line 1678 "limbaj.tab.c"
    break;

  case 78: /* number_expression: FLOAT_VALUE MOD number_expression  */
#line 168 "limbaj.y"
                                                             {expr_str* temp = convert_float((yyvsp[-2].floatVal)); (yyval.expr_node) = num_expresion(temp, (yyvsp[0].expr_node), '%');}
#line 1684 "limbaj.tab.c"
    break;

  case 79: /* number_expression: FLOAT_VALUE MOD ID  */
#line 169 "limbaj.y"
                                                             {expr_str* temp1 = convert_float((yyvsp[-2].floatVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = num_expresion(temp1, temp2, '%');}
#line 1690 "limbaj.tab.c"
    break;

  case 80: /* number_expression: '(' number_expression ')'  */
#line 171 "limbaj.y"
                                                             {(yyval.expr_node) = (yyvsp[-1].expr_node);}
#line 1696 "limbaj.tab.c"
    break;

  case 81: /* number_expression: INT_VALUE  */
#line 172 "limbaj.y"
                                                             {(yyval.expr_node) = convert_int((yyvsp[0].intVal));}
#line 1702 "limbaj.tab.c"
    break;

  case 82: /* number_expression: FLOAT_VALUE  */
#line 173 "limbaj.y"
                                                             {(yyval.expr_node) = convert_float((yyvsp[0].floatVal));}
#line 1708 "limbaj.tab.c"
    break;

  case 83: /* string_expression: ID CONCAT string_expression  */
#line 176 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = string_expresion(temp, (yyvsp[0].expr_node), '#');}
#line 1714 "limbaj.tab.c"
    break;

  case 84: /* string_expression: ID CONCAT ID  */
#line 177 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = string_expresion(temp1, temp2, '#');}
#line 1720 "limbaj.tab.c"
    break;

  case 85: /* string_expression: STRING_VALUE CONCAT string_expression  */
#line 178 "limbaj.y"
                                                             {expr_str* temp = convert_string((yyvsp[-2].stringVal)); (yyval.expr_node) = string_expresion(temp, (yyvsp[0].expr_node), '#');}
#line 1726 "limbaj.tab.c"
    break;

  case 86: /* string_expression: STRING_VALUE CONCAT ID  */
#line 179 "limbaj.y"
                                                             {expr_str* temp1 = convert_string((yyvsp[-2].stringVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = string_expresion(temp1, temp2, '#');}
#line 1732 "limbaj.tab.c"
    break;

  case 87: /* string_expression: CHAR_VALUE CONCAT string_expression  */
#line 180 "limbaj.y"
                                                             {expr_str* temp = convert_char((yyvsp[-2].charVal)); (yyval.expr_node) = string_expresion(temp, (yyvsp[0].expr_node), '#');}
#line 1738 "limbaj.tab.c"
    break;

  case 88: /* string_expression: CHAR_VALUE CONCAT ID  */
#line 181 "limbaj.y"
                                                             {expr_str* temp1 = convert_char((yyvsp[-2].charVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = string_expresion(temp1, temp2, '#');}
#line 1744 "limbaj.tab.c"
    break;

  case 89: /* string_expression: STRING_VALUE  */
#line 182 "limbaj.y"
                                                             {(yyval.expr_node) = convert_string((yyvsp[0].stringVal));}
#line 1750 "limbaj.tab.c"
    break;

  case 90: /* string_expression: CHAR_VALUE  */
#line 183 "limbaj.y"
                                                             {(yyval.expr_node) = convert_char((yyvsp[0].charVal));}
#line 1756 "limbaj.tab.c"
    break;

  case 91: /* bool_expression: ID AND bool_expression  */
#line 186 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = bool_expresion(temp, (yyvsp[0].expr_node), strdup("&"));}
#line 1762 "limbaj.tab.c"
    break;

  case 92: /* bool_expression: ID AND ID  */
#line 187 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = bool_expresion(temp1, temp2, strdup("&"));}
#line 1768 "limbaj.tab.c"
    break;

  case 93: /* bool_expression: ID OR bool_expression  */
#line 188 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = bool_expresion(temp, (yyvsp[0].expr_node), strdup("|"));}
#line 1774 "limbaj.tab.c"
    break;

  case 94: /* bool_expression: ID OR ID  */
#line 189 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = bool_expresion(temp1, temp2, strdup("|"));}
#line 1780 "limbaj.tab.c"
    break;

  case 95: /* bool_expression: BOOL_VALUE AND bool_expression  */
#line 191 "limbaj.y"
                                                             {expr_str* temp = convert_bool((yyvsp[-2].boolVal)); (yyval.expr_node) = bool_expresion(temp, (yyvsp[0].expr_node), strdup("&"));}
#line 1786 "limbaj.tab.c"
    break;

  case 96: /* bool_expression: BOOL_VALUE AND ID  */
#line 192 "limbaj.y"
                                                             {expr_str* temp1 = convert_bool((yyvsp[-2].boolVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = bool_expresion(temp1, temp2, strdup("&"));}
#line 1792 "limbaj.tab.c"
    break;

  case 97: /* bool_expression: BOOL_VALUE OR bool_expression  */
#line 193 "limbaj.y"
                                                             {expr_str* temp = convert_bool((yyvsp[-2].boolVal)); (yyval.expr_node) = bool_expresion(temp, (yyvsp[0].expr_node), strdup("|"));}
#line 1798 "limbaj.tab.c"
    break;

  case 98: /* bool_expression: BOOL_VALUE OR ID  */
#line 194 "limbaj.y"
                                                             {expr_str* temp1 = convert_bool((yyvsp[-2].boolVal)); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = bool_expresion(temp1, temp2, strdup("|"));}
#line 1804 "limbaj.tab.c"
    break;

  case 99: /* bool_expression: '(' bool_expression ')'  */
#line 196 "limbaj.y"
                                                             {(yyval.expr_node) = (yyvsp[-1].expr_node);}
#line 1810 "limbaj.tab.c"
    break;

  case 100: /* bool_expression: NOT bool_expression  */
#line 197 "limbaj.y"
                                                             {(yyval.expr_node) = bool_expresion((yyvsp[0].expr_node), nullptr, strdup("!"));}
#line 1816 "limbaj.tab.c"
    break;

  case 101: /* bool_expression: NOT ID  */
#line 198 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = bool_expresion(temp, nullptr, strdup("!"));}
#line 1822 "limbaj.tab.c"
    break;

  case 102: /* bool_expression: number_expression REL_OP number_expression  */
#line 199 "limbaj.y"
                                                             {(yyval.expr_node) = bool_expresion((yyvsp[-2].expr_node), (yyvsp[0].expr_node), (yyvsp[-1].stringVal));}
#line 1828 "limbaj.tab.c"
    break;

  case 103: /* bool_expression: ID REL_OP number_expression  */
#line 200 "limbaj.y"
                                                             {expr_str* temp = convert_from_id((yyvsp[-2].stringVal), scope); (yyval.expr_node) = bool_expresion(temp, (yyvsp[0].expr_node), (yyvsp[-1].stringVal));}
#line 1834 "limbaj.tab.c"
    break;

  case 104: /* bool_expression: ID REL_OP ID  */
#line 201 "limbaj.y"
                                                             {expr_str* temp1 = convert_from_id((yyvsp[-2].stringVal), scope); expr_str* temp2 = convert_from_id((yyvsp[0].stringVal), scope); (yyval.expr_node) = bool_expresion(temp1, temp2, (yyvsp[-1].stringVal));}
#line 1840 "limbaj.tab.c"
    break;

  case 105: /* bool_expression: BOOL_VALUE  */
#line 202 "limbaj.y"
                                                             {(yyval.expr_node) = convert_bool((yyvsp[0].boolVal));}
#line 1846 "limbaj.tab.c"
    break;

  case 106: /* func_call: ID '(' param_call_list ')'  */
#line 205 "limbaj.y"
                                      {convert_function((yyvsp[-3].stringVal), scope);}
#line 1852 "limbaj.tab.c"
    break;

  case 107: /* func_call: ID '(' ')'  */
#line 206 "limbaj.y"
                                      {convert_function((yyvsp[-2].stringVal), scope);}
#line 1858 "limbaj.tab.c"
    break;

  case 110: /* $@4: %empty  */
#line 213 "limbaj.y"
              {strcpy(scope, strdup("main"));}
#line 1864 "limbaj.tab.c"
    break;

  case 111: /* main_section: $@4 MAIN '(' ')' '{' func_body '}'  */
#line 213 "limbaj.y"
                                                                              {strcpy(scope, strdup("global"));}
#line 1870 "limbaj.tab.c"
    break;

  case 114: /* $@5: %empty  */
#line 220 "limbaj.y"
                {strcpy(scope, (yyvsp[0].stringVal));}
#line 1876 "limbaj.tab.c"
    break;

  case 115: /* class: CLASS ID $@5 '{' class_body '}'  */
#line 220 "limbaj.y"
                                                        {strcpy(scope, strdup("global"));}
#line 1882 "limbaj.tab.c"
    break;

  case 121: /* attribute: ACC_MOD ID ':' TYPE ';'  */
#line 232 "limbaj.y"
                                                     {expr_str *temp = create_empty_value((yyvsp[-1].stringVal)); add_variable((yyvsp[-3].stringVal), (yyvsp[-1].stringVal), scope, false, temp);}
#line 1888 "limbaj.tab.c"
    break;

  case 122: /* attribute: ACC_MOD ID ':' TYPE ASSIGN expression ';'  */
#line 233 "limbaj.y"
                                                     {add_variable((yyvsp[-5].stringVal), (yyvsp[-3].stringVal), scope, false, (yyvsp[-1].expr_node));}
#line 1894 "limbaj.tab.c"
    break;

  case 123: /* attribute: ACC_MOD ID '[' INT_VALUE ']' ':' TYPE ';'  */
#line 234 "limbaj.y"
                                                     {add_vector((yyvsp[-6].stringVal), (yyvsp[-1].stringVal), scope, (yyvsp[-4].intVal), false);}
#line 1900 "limbaj.tab.c"
    break;

  case 127: /* constructor: CONSTRUCTOR '(' param_list_method_opt ')' '{' func_body '}'  */
#line 242 "limbaj.y"
                                                                         {params.clear();}
#line 1906 "limbaj.tab.c"
    break;

  case 130: /* $@6: %empty  */
#line 249 "limbaj.y"
                   {strcpy(prev_scope, scope); strcpy(scope, (yyvsp[0].stringVal));}
#line 1912 "limbaj.tab.c"
    break;

  case 131: /* $@7: %empty  */
#line 249 "limbaj.y"
                                                                                                          {add_function((yyvsp[-6].stringVal), (yyvsp[0].stringVal), prev_scope, params); params.clear();}
#line 1918 "limbaj.tab.c"
    break;

  case 132: /* method: ACC_MOD ID $@6 '(' param_list_method_opt ')' ':' TYPE $@7 '{' func_body '}'  */
#line 249 "limbaj.y"
                                                                                                                                                                                        {strcpy(scope, prev_scope);}
#line 1924 "limbaj.tab.c"
    break;


#line 1928 "limbaj.tab.c"

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

#line 259 "limbaj.y"


void yyerror(const char * s) {
    printf("Error %d\n", yylineno);
}

int main(int argc, char **argv) {
    yydebug = 0;
    yyin = fopen(argv[1], "r");
    yyparse();
    return 0;
}
