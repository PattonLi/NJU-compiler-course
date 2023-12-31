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
#line 1 "./syntax.y"

#include "lex.yy.c"
#include <stdio.h>
#include <stdarg.h>
//#define debug_2

extern int yylineno;
extern struct AST_Node* root;
int emptyflag=0,mrk_empty=0,synErr=0;

struct AST_Node *bison_init(char* tok,int liner){
    struct AST_Node * my_node=(struct AST_Node *)malloc(sizeof(struct AST_Node));
    my_node->child=my_node->next_sib=NULL;
    strcpy(my_node->name,tok);
    my_node->height=1;
    my_node->type=LEX_OTHERS;
    if(emptyflag||strcmp(tok,"Program")!=0) my_node->lineno=liner;
    else my_node->lineno=mrk_empty;
    return my_node;
}
//插节点，关于va_list: https://blog.csdn.net/ZKR_HN/article/details/99558135
void bison_insert(struct AST_Node *top_node,int num_args,...){
    va_list tmp;
    va_start(tmp,num_args);
    top_node->child=va_arg(tmp,struct AST_Node*);
    struct AST_Node* new_node=top_node->child;
    for(int i=1;i<num_args;i++){
        new_node->next_sib=va_arg(tmp,struct AST_Node*);
        if(new_node->next_sib!=NULL) new_node=new_node->next_sib;
    }
}
//打印树

void func(struct AST_Node* s_node,int h){
    if(s_node==NULL) return;
    for(int i=1;i<=h;i++) printf("  ");
    printf("%s",s_node->name);
    if(!s_node->height){
        switch(s_node->type){
            case(LEX_INT):{
                printf(": %lld",s_node->is_int);
                break;
            }
            case(LEX_FLOAT):{
                printf(": %f",s_node->is_float);
                break;
            }
            case(LEX_ID):{
                printf(": %s",s_node->is_string);
                break;
            }
            case(KEYWORD_TYPE):{
                printf(": %s",s_node->is_string);
                break;
            }
            default:{}
        }
    }else if(s_node->height==1) printf(" (%d)",s_node->lineno);
    printf("\n");
    func(s_node->child,h+1);
    func(s_node->next_sib,h);
}


int yyerror(char*msg){
    synErr+=1;
    printf("Error type B at Line %d: %s near %s.\n",yylineno,msg,yytext);
}


#line 142 "./syntax.tab.c"

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
  YYSYMBOL_INT = 3,                        /* INT  */
  YYSYMBOL_FLOAT = 4,                      /* FLOAT  */
  YYSYMBOL_ID = 5,                         /* ID  */
  YYSYMBOL_SEMI = 6,                       /* SEMI  */
  YYSYMBOL_COMMA = 7,                      /* COMMA  */
  YYSYMBOL_ASSIGNOP = 8,                   /* ASSIGNOP  */
  YYSYMBOL_RELOP = 9,                      /* RELOP  */
  YYSYMBOL_PLUS = 10,                      /* PLUS  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_STAR = 12,                      /* STAR  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_DOT = 17,                       /* DOT  */
  YYSYMBOL_TYPE = 18,                      /* TYPE  */
  YYSYMBOL_LP = 19,                        /* LP  */
  YYSYMBOL_RP = 20,                        /* RP  */
  YYSYMBOL_LB = 21,                        /* LB  */
  YYSYMBOL_RB = 22,                        /* RB  */
  YYSYMBOL_LC = 23,                        /* LC  */
  YYSYMBOL_RC = 24,                        /* RC  */
  YYSYMBOL_STRUCT = 25,                    /* STRUCT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_WHILE = 29,                     /* WHILE  */
  YYSYMBOL_UMINUS = 30,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 31,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_ExtDefList = 34,                /* ExtDefList  */
  YYSYMBOL_ExtDef = 35,                    /* ExtDef  */
  YYSYMBOL_ExtDecList = 36,                /* ExtDecList  */
  YYSYMBOL_Specifier = 37,                 /* Specifier  */
  YYSYMBOL_StructSpecifier = 38,           /* StructSpecifier  */
  YYSYMBOL_OptTag = 39,                    /* OptTag  */
  YYSYMBOL_Tag = 40,                       /* Tag  */
  YYSYMBOL_VarDec = 41,                    /* VarDec  */
  YYSYMBOL_FunDec = 42,                    /* FunDec  */
  YYSYMBOL_VarList = 43,                   /* VarList  */
  YYSYMBOL_ParamDec = 44,                  /* ParamDec  */
  YYSYMBOL_CompSt = 45,                    /* CompSt  */
  YYSYMBOL_StmtList = 46,                  /* StmtList  */
  YYSYMBOL_Stmt = 47,                      /* Stmt  */
  YYSYMBOL_DefList = 48,                   /* DefList  */
  YYSYMBOL_Def = 49,                       /* Def  */
  YYSYMBOL_DecList = 50,                   /* DecList  */
  YYSYMBOL_Dec = 51,                       /* Dec  */
  YYSYMBOL_Exp = 52,                       /* Exp  */
  YYSYMBOL_Args = 53                       /* Args  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   466

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   117,   117,   124,   129,   134,   139,   144,   149,   155,
     158,   161,   164,   167,   170,   174,   179,   185,   189,   194,
     200,   205,   220,   225,   230,   236,   241,   247,   251,   256,
     262,   265,   275,   280,   286,   292,   297,   302,   307,   312,
     317,   322,   327,   332,   337,   343,   346,   349,   352,   355,
     358,   361,   365,   370,   375,   381,   384,   394,   399,   405,
     410,   416,   421,   426,   431,   436,   441,   446,   451,   456,
     462,   467,   472,   477,   482,   487,   492,   497,   502,   508,
     511,   514,   517,   520,   523,   526,   529,   532,   535,   538,
     541,   544,   547,   551,   556
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
  "\"end of file\"", "error", "\"invalid token\"", "INT", "FLOAT", "ID",
  "SEMI", "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV",
  "AND", "OR", "NOT", "DOT", "TYPE", "LP", "RP", "LB", "RB", "LC", "RC",
  "STRUCT", "RETURN", "IF", "ELSE", "WHILE", "UMINUS", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-39)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    85,  -110,    11,    13,  -110,    93,   176,  -110,  -110,
    -110,  -110,    61,    35,    54,  -110,  -110,  -110,     6,    71,
    -110,   107,   148,     9,    30,  -110,    -4,  -110,    -4,     8,
    -110,    96,   112,    21,   126,  -110,    -4,  -110,  -110,    99,
     129,    -4,   112,   116,   150,   145,  -110,   147,  -110,  -110,
    -110,   168,   170,  -110,    60,   164,    48,   100,   166,  -110,
    -110,    98,  -110,    -4,  -110,  -110,  -110,  -110,    44,  -110,
    -110,   174,   175,   184,   201,   210,    56,    59,  -110,   172,
      60,   114,  -110,   335,  -110,  -110,   112,  -110,  -110,   155,
    -110,   113,  -110,   113,   177,   377,   192,   131,   171,   335,
     127,   335,  -110,  -110,   195,  -110,   227,   236,   253,   262,
     279,   288,   305,   314,   202,   331,   419,  -110,    46,  -110,
     348,   188,  -110,  -110,  -110,  -110,  -110,    69,   391,  -110,
    -110,   405,  -110,  -110,   419,  -110,   151,  -110,    95,  -110,
      95,  -110,   113,  -110,   113,  -110,   445,  -110,   432,  -110,
     187,   362,  -110,  -110,   335,  -110,  -110,    69,    69,  -110,
    -110,  -110,   182,  -110,    69,  -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    18,    23,     0,     2,     0,     0,    19,     9,
      12,    13,     0,    24,     0,    21,     1,     3,     0,    25,
       6,     0,     0,     0,     0,    11,    53,    10,     0,     0,
       5,     0,     0,     0,     0,     8,    53,     7,    14,     0,
       0,    53,     0,     0,    33,     0,    29,     0,    17,    25,
      16,     0,     0,    36,     0,     0,    59,     0,    57,    20,
      52,    34,    31,     0,    30,    28,    27,    26,     0,    77,
      78,    76,     0,     0,     0,     0,     0,     0,    40,     0,
       0,     0,    55,     0,    56,    54,     0,    32,    45,     0,
      88,    70,    89,    71,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    37,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    60,    58,     0,    73,
      94,     0,    87,    69,    48,    47,    41,     0,     0,    50,
      51,     0,    46,    79,    61,    82,    64,    83,    65,    84,
      66,    85,    67,    86,    68,    80,    62,    81,    63,    75,
       0,     0,    91,    90,     0,    72,    49,     0,     0,    92,
      74,    93,    42,    44,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,    14,  -110,   186,    18,  -110,  -110,  -110,   -35,
    -110,   -21,  -110,   160,   136,  -109,    97,  -110,   133,  -110,
     -72,    68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,    21,     7,     8,    14,    15,    22,
      23,    43,    44,    78,    79,    80,    40,    41,    57,    58,
      81,   121
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      91,    93,    95,    97,    56,    -4,     1,    61,    47,    45,
      34,   116,    27,    16,     2,    35,    13,   120,   156,    12,
      17,     3,    51,     2,    52,    28,     2,   128,    46,   131,
       3,    34,    36,     3,   134,   136,   138,   140,   142,   144,
     146,   148,    87,   151,    39,    48,    42,    42,   162,   163,
      88,    56,   152,    36,    39,   165,    83,    98,   -22,    39,
     100,    68,    24,    69,    70,    71,   153,    25,    53,    33,
      68,    72,    69,    70,    71,    99,    73,    26,   101,    74,
      72,    42,   120,    36,   -38,    73,    75,    76,    74,    77,
      29,     9,    36,    -4,     1,    75,    76,     1,    77,    -4,
      55,    84,    -4,     2,    49,    10,    85,   110,   111,    11,
       3,     2,   114,    30,     2,   104,   115,    49,     3,    33,
     105,     3,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   114,   125,    54,   115,   115,    62,   126,    60,   106,
     107,   108,   109,   110,   111,   112,   113,   129,   114,    31,
      53,   130,   115,    59,   -15,    32,   118,    63,    69,    70,
      71,   108,   109,   110,   111,    64,    72,    65,   114,    33,
      82,    73,   115,    86,    74,   119,    90,    18,    69,    70,
      71,    19,    20,    37,    38,    92,    72,    69,    70,    71,
      66,    73,    67,    89,    74,    72,   102,   122,   124,   127,
      73,   132,    94,    74,    69,    70,    71,   149,   155,   159,
     164,    96,    72,    69,    70,    71,   103,    73,    50,   117,
      74,    72,   161,     0,     0,     0,    73,     0,   133,    74,
      69,    70,    71,     0,     0,     0,     0,   135,    72,    69,
      70,    71,     0,    73,     0,     0,    74,    72,     0,     0,
       0,     0,    73,     0,   137,    74,    69,    70,    71,     0,
       0,     0,     0,   139,    72,    69,    70,    71,     0,    73,
       0,     0,    74,    72,     0,     0,     0,     0,    73,     0,
     141,    74,    69,    70,    71,     0,     0,     0,     0,   143,
      72,    69,    70,    71,     0,    73,     0,     0,    74,    72,
       0,     0,     0,     0,    73,     0,   145,    74,    69,    70,
      71,     0,     0,     0,     0,   147,    72,    69,    70,    71,
       0,    73,     0,     0,    74,    72,     0,     0,     0,     0,
      73,     0,   150,    74,    69,    70,    71,     0,    69,    70,
      71,     0,    72,     0,     0,     0,    72,    73,     0,     0,
      74,    73,     0,     0,    74,   154,   106,   107,   108,   109,
     110,   111,   112,   113,     0,   114,     0,     0,     0,   115,
     106,   107,   108,   109,   110,   111,   112,   113,     0,   114,
       0,     0,     0,   115,   160,   106,   107,   108,   109,   110,
     111,   112,   113,     0,   114,     0,     0,   123,   115,   106,
     107,   108,   109,   110,   111,   112,   113,     0,   114,     0,
       0,   157,   115,   106,   107,   108,   109,   110,   111,   112,
     113,     0,   114,     0,     0,   158,   115,   106,   107,   108,
     109,   110,   111,   112,   113,     0,   114,     0,     0,     0,
     115,   107,   108,   109,   110,   111,   112,     0,     0,   114,
       0,     0,     0,   115,   107,   108,   109,   110,   111,     0,
       0,     0,   114,     0,     0,     0,   115
};

static const yytype_int16 yycheck[] =
{
      72,    73,    74,    75,    39,     0,     1,    42,    29,     1,
       1,    83,     6,     0,    18,     6,     5,    89,   127,     1,
       6,    25,     1,    18,     3,    19,    18,    99,    20,   101,
      25,     1,    23,    25,   106,   107,   108,   109,   110,   111,
     112,   113,    63,   115,    26,    31,    28,    29,   157,   158,
       6,    86,     6,    23,    36,   164,     8,     1,    23,    41,
       1,     1,     1,     3,     4,     5,    20,     6,    24,    21,
       1,    11,     3,     4,     5,    19,    16,    23,    19,    19,
      11,    63,   154,    23,    24,    16,    26,    27,    19,    29,
      19,     6,    23,     0,     1,    26,    27,     1,    29,     6,
       1,     1,     6,    18,     5,    20,     6,    12,    13,    24,
      25,    18,    17,     6,    18,     1,    21,     5,    25,    21,
       6,    25,     8,     9,    10,    11,    12,    13,    14,    15,
      17,    17,     1,    36,    21,    21,    20,     6,    41,     8,
       9,    10,    11,    12,    13,    14,    15,    20,    17,     1,
      24,    24,    21,    24,     6,     7,     1,     7,     3,     4,
       5,    10,    11,    12,    13,    20,    11,    20,    17,    21,
       6,    16,    21,     7,    19,    20,     1,     1,     3,     4,
       5,     5,     6,    23,    24,     1,    11,     3,     4,     5,
      22,    16,    22,    19,    19,    11,    24,    20,     6,    28,
      16,     6,     1,    19,     3,     4,     5,     5,    20,    22,
      28,     1,    11,     3,     4,     5,    80,    16,    32,    86,
      19,    11,   154,    -1,    -1,    -1,    16,    -1,     1,    19,
       3,     4,     5,    -1,    -1,    -1,    -1,     1,    11,     3,
       4,     5,    -1,    16,    -1,    -1,    19,    11,    -1,    -1,
      -1,    -1,    16,    -1,     1,    19,     3,     4,     5,    -1,
      -1,    -1,    -1,     1,    11,     3,     4,     5,    -1,    16,
      -1,    -1,    19,    11,    -1,    -1,    -1,    -1,    16,    -1,
       1,    19,     3,     4,     5,    -1,    -1,    -1,    -1,     1,
      11,     3,     4,     5,    -1,    16,    -1,    -1,    19,    11,
      -1,    -1,    -1,    -1,    16,    -1,     1,    19,     3,     4,
       5,    -1,    -1,    -1,    -1,     1,    11,     3,     4,     5,
      -1,    16,    -1,    -1,    19,    11,    -1,    -1,    -1,    -1,
      16,    -1,     1,    19,     3,     4,     5,    -1,     3,     4,
       5,    -1,    11,    -1,    -1,    -1,    11,    16,    -1,    -1,
      19,    16,    -1,    -1,    19,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,    21,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    -1,    21,    22,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    21,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    21,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      21,     9,    10,    11,    12,    13,    14,    -1,    -1,    17,
      -1,    -1,    -1,    21,     9,    10,    11,    12,    13,    -1,
      -1,    -1,    17,    -1,    -1,    -1,    21
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    18,    25,    33,    34,    35,    37,    38,     6,
      20,    24,    37,     5,    39,    40,     0,    34,     1,     5,
       6,    36,    41,    42,     1,     6,    23,     6,    19,    19,
       6,     1,     7,    21,     1,     6,    23,    45,    45,    37,
      48,    49,    37,    43,    44,     1,    20,    43,    34,     5,
      36,     1,     3,    24,    48,     1,    41,    50,    51,    24,
      48,    41,    20,     7,    20,    20,    22,    22,     1,     3,
       4,     5,    11,    16,    19,    26,    27,    29,    45,    46,
      47,    52,     6,     8,     1,     6,     7,    43,     6,    19,
       1,    52,     1,    52,     1,    52,     1,    52,     1,    19,
       1,    19,    24,    46,     1,     6,     8,     9,    10,    11,
      12,    13,    14,    15,    17,    21,    52,    50,     1,    20,
      52,    53,    20,    20,     6,     1,     6,    28,    52,    20,
      24,    52,     6,     1,    52,     1,    52,     1,    52,     1,
      52,     1,    52,     1,    52,     1,    52,     1,    52,     5,
       1,    52,     6,    20,     7,    20,    47,    20,    20,    22,
      22,    53,    47,    47,    28,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    35,    35,    35,    36,    36,    36,    37,    37,
      38,    38,    39,    39,    40,    41,    41,    41,    42,    42,
      42,    42,    43,    43,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    53,    53
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     3,     2,     3,     3,     2,
       3,     3,     2,     2,     4,     1,     3,     3,     1,     1,
       5,     2,     1,     0,     1,     1,     4,     4,     4,     3,
       4,     4,     3,     1,     2,     4,     2,     2,     0,     2,
       1,     3,     5,     7,     5,     2,     3,     3,     3,     4,
       3,     3,     2,     0,     3,     3,     3,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     4,     3,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     4,     4,     3,     1
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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
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
      yyerror_range[1] = yylloc;
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
  case 2: /* Program: ExtDefList  */
#line 117 "./syntax.y"
                    {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Program",locline);
    root=(yyval.node);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1469 "./syntax.tab.c"
    break;

  case 3: /* ExtDefList: ExtDef ExtDefList  */
#line 124 "./syntax.y"
                              {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("ExtDefList",locline);
    bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1479 "./syntax.tab.c"
    break;

  case 4: /* ExtDefList: %empty  */
#line 129 "./syntax.y"
      {
        (yyval.node)=NULL;
        mrk_empty=yylineno;
    }
#line 1488 "./syntax.tab.c"
    break;

  case 5: /* ExtDef: Specifier ExtDecList SEMI  */
#line 134 "./syntax.y"
                                {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("ExtDef",locline);
    bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1498 "./syntax.tab.c"
    break;

  case 6: /* ExtDef: Specifier SEMI  */
#line 139 "./syntax.y"
                    {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("ExtDef",locline);
        bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1508 "./syntax.tab.c"
    break;

  case 7: /* ExtDef: Specifier FunDec CompSt  */
#line 144 "./syntax.y"
                             {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("ExtDef",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1518 "./syntax.tab.c"
    break;

  case 8: /* ExtDef: Specifier FunDec SEMI  */
#line 149 "./syntax.y"
                            {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("ExtDef",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1528 "./syntax.tab.c"
    break;

  case 9: /* ExtDef: error SEMI  */
#line 155 "./syntax.y"
               {
        synErr+=1;
    }
#line 1536 "./syntax.tab.c"
    break;

  case 10: /* ExtDef: Specifier error SEMI  */
#line 158 "./syntax.y"
                         {
        synErr+=1;
    }
#line 1544 "./syntax.tab.c"
    break;

  case 11: /* ExtDef: error Specifier SEMI  */
#line 161 "./syntax.y"
                          {
        synErr+=1;
    }
#line 1552 "./syntax.tab.c"
    break;

  case 12: /* ExtDef: error RP  */
#line 164 "./syntax.y"
              {
        synErr+=1;
    }
#line 1560 "./syntax.tab.c"
    break;

  case 13: /* ExtDef: error RC  */
#line 167 "./syntax.y"
              {
        synErr+=1;
    }
#line 1568 "./syntax.tab.c"
    break;

  case 14: /* ExtDef: error Specifier error CompSt  */
#line 170 "./syntax.y"
                                  {
        synErr+=1;
    }
#line 1576 "./syntax.tab.c"
    break;

  case 15: /* ExtDecList: VarDec  */
#line 174 "./syntax.y"
                  {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("ExtDecList",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1586 "./syntax.tab.c"
    break;

  case 16: /* ExtDecList: VarDec COMMA ExtDecList  */
#line 179 "./syntax.y"
                             {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("ExtDecList",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1596 "./syntax.tab.c"
    break;

  case 17: /* ExtDecList: VarDec error ExtDefList  */
#line 185 "./syntax.y"
                             {
        synErr+=1;
    }
#line 1604 "./syntax.tab.c"
    break;

  case 18: /* Specifier: TYPE  */
#line 189 "./syntax.y"
               {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Specifier",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1614 "./syntax.tab.c"
    break;

  case 19: /* Specifier: StructSpecifier  */
#line 194 "./syntax.y"
                     {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Specifier",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1624 "./syntax.tab.c"
    break;

  case 20: /* StructSpecifier: STRUCT OptTag LC DefList RC  */
#line 200 "./syntax.y"
                                            {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("StructSpecifier",locline);
    bison_insert((yyval.node),5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1634 "./syntax.tab.c"
    break;

  case 21: /* StructSpecifier: STRUCT Tag  */
#line 205 "./syntax.y"
                {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("StructSpecifier",locline);
        bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1644 "./syntax.tab.c"
    break;

  case 22: /* OptTag: ID  */
#line 220 "./syntax.y"
         {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("OptTag",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1654 "./syntax.tab.c"
    break;

  case 23: /* OptTag: %empty  */
#line 225 "./syntax.y"
      {
        (yyval.node)=NULL;
        //mrk_empty=yylineno;
    }
#line 1663 "./syntax.tab.c"
    break;

  case 24: /* Tag: ID  */
#line 230 "./syntax.y"
      {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Tag",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1673 "./syntax.tab.c"
    break;

  case 25: /* VarDec: ID  */
#line 236 "./syntax.y"
         {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("VarDec",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1683 "./syntax.tab.c"
    break;

  case 26: /* VarDec: VarDec LB INT RB  */
#line 241 "./syntax.y"
                      {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("VarDec",locline);
        bison_insert((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1693 "./syntax.tab.c"
    break;

  case 27: /* VarDec: VarDec LB error RB  */
#line 247 "./syntax.y"
                       {
        synErr+=1;
    }
#line 1701 "./syntax.tab.c"
    break;

  case 28: /* FunDec: ID LP VarList RP  */
#line 251 "./syntax.y"
                       {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("FunDec",locline);
    bison_insert((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1711 "./syntax.tab.c"
    break;

  case 29: /* FunDec: ID LP RP  */
#line 256 "./syntax.y"
              {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("FunDec",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1721 "./syntax.tab.c"
    break;

  case 30: /* FunDec: ID LP error RP  */
#line 262 "./syntax.y"
                    {
        synErr+=1;
    }
#line 1729 "./syntax.tab.c"
    break;

  case 31: /* FunDec: error LP VarList RP  */
#line 265 "./syntax.y"
                         {
        synErr+=1;
    }
#line 1737 "./syntax.tab.c"
    break;

  case 32: /* VarList: ParamDec COMMA VarList  */
#line 275 "./syntax.y"
                              {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("VarList",locline);
    bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node)); 
    }
#line 1747 "./syntax.tab.c"
    break;

  case 33: /* VarList: ParamDec  */
#line 280 "./syntax.y"
              {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("VarList",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1757 "./syntax.tab.c"
    break;

  case 34: /* ParamDec: Specifier VarDec  */
#line 286 "./syntax.y"
                           {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("ParamDec",locline);
    bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1767 "./syntax.tab.c"
    break;

  case 35: /* CompSt: LC DefList StmtList RC  */
#line 292 "./syntax.y"
                             {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("CompSt",locline);
    bison_insert((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1777 "./syntax.tab.c"
    break;

  case 36: /* CompSt: error RC  */
#line 297 "./syntax.y"
              {
        synErr+=1;
    }
#line 1785 "./syntax.tab.c"
    break;

  case 37: /* StmtList: Stmt StmtList  */
#line 302 "./syntax.y"
                      {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("StmtList",locline);
    bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1795 "./syntax.tab.c"
    break;

  case 38: /* StmtList: %empty  */
#line 307 "./syntax.y"
      {
        (yyval.node)=NULL;
        //mrk_empty=yylineno;
    }
#line 1804 "./syntax.tab.c"
    break;

  case 39: /* Stmt: Exp SEMI  */
#line 312 "./syntax.y"
             {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Stmt",locline);
    bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1814 "./syntax.tab.c"
    break;

  case 40: /* Stmt: CompSt  */
#line 317 "./syntax.y"
            {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Stmt",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1824 "./syntax.tab.c"
    break;

  case 41: /* Stmt: RETURN Exp SEMI  */
#line 322 "./syntax.y"
                     {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Stmt",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1834 "./syntax.tab.c"
    break;

  case 42: /* Stmt: IF LP Exp RP Stmt  */
#line 327 "./syntax.y"
                                             {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Stmt",locline);
        bison_insert((yyval.node),5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1844 "./syntax.tab.c"
    break;

  case 43: /* Stmt: IF LP Exp RP Stmt ELSE Stmt  */
#line 332 "./syntax.y"
                                 {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Stmt",locline);
        bison_insert((yyval.node),7,(yyvsp[-6].node),(yyvsp[-5].node),(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1854 "./syntax.tab.c"
    break;

  case 44: /* Stmt: WHILE LP Exp RP Stmt  */
#line 337 "./syntax.y"
                          {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Stmt",locline);
        bison_insert((yyval.node),5,(yyvsp[-4].node),(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1864 "./syntax.tab.c"
    break;

  case 45: /* Stmt: error SEMI  */
#line 343 "./syntax.y"
                 {
        synErr+=1;
    }
#line 1872 "./syntax.tab.c"
    break;

  case 46: /* Stmt: Exp error SEMI  */
#line 346 "./syntax.y"
                    {
        synErr+=1;
    }
#line 1880 "./syntax.tab.c"
    break;

  case 47: /* Stmt: RETURN Exp error  */
#line 349 "./syntax.y"
                     {
        synErr+=1;
    }
#line 1888 "./syntax.tab.c"
    break;

  case 48: /* Stmt: RETURN error SEMI  */
#line 352 "./syntax.y"
                      {
        synErr+=1;
    }
#line 1896 "./syntax.tab.c"
    break;

  case 49: /* Stmt: IF error ELSE Stmt  */
#line 355 "./syntax.y"
                        {
        synErr+=1;
    }
#line 1904 "./syntax.tab.c"
    break;

  case 50: /* Stmt: WHILE error RP  */
#line 358 "./syntax.y"
                    {
        synErr+=1;
    }
#line 1912 "./syntax.tab.c"
    break;

  case 51: /* Stmt: WHILE error RC  */
#line 361 "./syntax.y"
                    {
        synErr+=1;
    }
#line 1920 "./syntax.tab.c"
    break;

  case 52: /* DefList: Def DefList  */
#line 365 "./syntax.y"
                   {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("DefList",locline);
    bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1930 "./syntax.tab.c"
    break;

  case 53: /* DefList: %empty  */
#line 370 "./syntax.y"
      {
        (yyval.node)=NULL;
        //mrk_empty=yylineno;
    }
#line 1939 "./syntax.tab.c"
    break;

  case 54: /* Def: Specifier DecList SEMI  */
#line 375 "./syntax.y"
                          {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Def",locline);
    bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1949 "./syntax.tab.c"
    break;

  case 55: /* Def: Specifier error SEMI  */
#line 381 "./syntax.y"
                          {
        synErr+=1;
    }
#line 1957 "./syntax.tab.c"
    break;

  case 56: /* Def: Specifier DecList error  */
#line 384 "./syntax.y"
                             {
        synErr+=1;
    }
#line 1965 "./syntax.tab.c"
    break;

  case 57: /* DecList: Dec  */
#line 394 "./syntax.y"
           {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("DecList",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1975 "./syntax.tab.c"
    break;

  case 58: /* DecList: Dec COMMA DecList  */
#line 399 "./syntax.y"
                       {;
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("DecList",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 1985 "./syntax.tab.c"
    break;

  case 59: /* Dec: VarDec  */
#line 405 "./syntax.y"
          {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Dec",locline);
    bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 1995 "./syntax.tab.c"
    break;

  case 60: /* Dec: VarDec ASSIGNOP Exp  */
#line 410 "./syntax.y"
                         {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Dec",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2005 "./syntax.tab.c"
    break;

  case 61: /* Exp: Exp ASSIGNOP Exp  */
#line 416 "./syntax.y"
                    {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Exp",locline);
    bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2015 "./syntax.tab.c"
    break;

  case 62: /* Exp: Exp AND Exp  */
#line 421 "./syntax.y"
                 {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2025 "./syntax.tab.c"
    break;

  case 63: /* Exp: Exp OR Exp  */
#line 426 "./syntax.y"
                {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2035 "./syntax.tab.c"
    break;

  case 64: /* Exp: Exp RELOP Exp  */
#line 431 "./syntax.y"
                   {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
        }
#line 2045 "./syntax.tab.c"
    break;

  case 65: /* Exp: Exp PLUS Exp  */
#line 436 "./syntax.y"
                  {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
        }
#line 2055 "./syntax.tab.c"
    break;

  case 66: /* Exp: Exp MINUS Exp  */
#line 441 "./syntax.y"
                   {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2065 "./syntax.tab.c"
    break;

  case 67: /* Exp: Exp STAR Exp  */
#line 446 "./syntax.y"
                  {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2075 "./syntax.tab.c"
    break;

  case 68: /* Exp: Exp DIV Exp  */
#line 451 "./syntax.y"
                 {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2085 "./syntax.tab.c"
    break;

  case 69: /* Exp: LP Exp RP  */
#line 456 "./syntax.y"
               {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2095 "./syntax.tab.c"
    break;

  case 70: /* Exp: MINUS Exp  */
#line 462 "./syntax.y"
                            {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2105 "./syntax.tab.c"
    break;

  case 71: /* Exp: NOT Exp  */
#line 467 "./syntax.y"
             {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),2,(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2115 "./syntax.tab.c"
    break;

  case 72: /* Exp: ID LP Args RP  */
#line 472 "./syntax.y"
                   {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2125 "./syntax.tab.c"
    break;

  case 73: /* Exp: ID LP RP  */
#line 477 "./syntax.y"
              {
        int locline=(yyloc).first_line; 
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2135 "./syntax.tab.c"
    break;

  case 74: /* Exp: Exp LB Exp RB  */
#line 482 "./syntax.y"
                   {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),4,(yyvsp[-3].node),(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2145 "./syntax.tab.c"
    break;

  case 75: /* Exp: Exp DOT ID  */
#line 487 "./syntax.y"
                {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2155 "./syntax.tab.c"
    break;

  case 76: /* Exp: ID  */
#line 492 "./syntax.y"
        {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 2165 "./syntax.tab.c"
    break;

  case 77: /* Exp: INT  */
#line 497 "./syntax.y"
         {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 2175 "./syntax.tab.c"
    break;

  case 78: /* Exp: FLOAT  */
#line 502 "./syntax.y"
           {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Exp",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 2185 "./syntax.tab.c"
    break;

  case 79: /* Exp: Exp ASSIGNOP error  */
#line 508 "./syntax.y"
                        {
        synErr+=1;
    }
#line 2193 "./syntax.tab.c"
    break;

  case 80: /* Exp: Exp AND error  */
#line 511 "./syntax.y"
                   {
        synErr+=1;
    }
#line 2201 "./syntax.tab.c"
    break;

  case 81: /* Exp: Exp OR error  */
#line 514 "./syntax.y"
                  {
        synErr+=1;
    }
#line 2209 "./syntax.tab.c"
    break;

  case 82: /* Exp: Exp RELOP error  */
#line 517 "./syntax.y"
                     {
        synErr+=1;
    }
#line 2217 "./syntax.tab.c"
    break;

  case 83: /* Exp: Exp PLUS error  */
#line 520 "./syntax.y"
                    {
        synErr+=1;
    }
#line 2225 "./syntax.tab.c"
    break;

  case 84: /* Exp: Exp MINUS error  */
#line 523 "./syntax.y"
                     {
        synErr+=1;
    }
#line 2233 "./syntax.tab.c"
    break;

  case 85: /* Exp: Exp STAR error  */
#line 526 "./syntax.y"
                    {
        synErr+=1;
    }
#line 2241 "./syntax.tab.c"
    break;

  case 86: /* Exp: Exp DIV error  */
#line 529 "./syntax.y"
                   {
        synErr+=1;
    }
#line 2249 "./syntax.tab.c"
    break;

  case 87: /* Exp: LP error RP  */
#line 532 "./syntax.y"
                 {
        synErr+=1;
    }
#line 2257 "./syntax.tab.c"
    break;

  case 88: /* Exp: MINUS error  */
#line 535 "./syntax.y"
                 {
        synErr+=1;
    }
#line 2265 "./syntax.tab.c"
    break;

  case 89: /* Exp: NOT error  */
#line 538 "./syntax.y"
               {
        synErr+=1;
    }
#line 2273 "./syntax.tab.c"
    break;

  case 90: /* Exp: ID LP error RP  */
#line 541 "./syntax.y"
                    {
        synErr+=1;
    }
#line 2281 "./syntax.tab.c"
    break;

  case 91: /* Exp: ID LP error SEMI  */
#line 544 "./syntax.y"
                      {
        synErr+=1;
    }
#line 2289 "./syntax.tab.c"
    break;

  case 92: /* Exp: Exp LB error RB  */
#line 547 "./syntax.y"
                     {
        synErr+=1;
    }
#line 2297 "./syntax.tab.c"
    break;

  case 93: /* Args: Exp COMMA Args  */
#line 551 "./syntax.y"
                   {
    int locline=(yyloc).first_line;
    (yyval.node)=bison_init("Args",locline);
    bison_insert((yyval.node),3,(yyvsp[-2].node),(yyvsp[-1].node),(yyvsp[0].node));
    }
#line 2307 "./syntax.tab.c"
    break;

  case 94: /* Args: Exp  */
#line 556 "./syntax.y"
         {
        int locline=(yyloc).first_line;
        (yyval.node)=bison_init("Args",locline);
        bison_insert((yyval.node),1,(yyvsp[0].node));
    }
#line 2317 "./syntax.tab.c"
    break;


#line 2321 "./syntax.tab.c"

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 562 "./syntax.y"

