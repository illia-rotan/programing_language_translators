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
     IDENTIFIER_TOKEN = 258,
     INT_LITERAL_TOKEN = 259,
     IF_TOKEN = 260,
     FUNCTION_TOKEN = 261,
     ELSE_TOKEN = 262,
     FOR_TOKEN = 263,
     RETURN_TOKEN = 264,
     TRUE_TOKEN = 265,
     FALSE_TOKEN = 266,
     PLUS_TOKEN = 267,
     MINUS_TOKEN = 268,
     MULTIPLY_TOKEN = 269,
     DIVIDE_TOKEN = 270,
     MODULO_TOKEN = 271,
     INCREMENT_TOKEN = 272,
     DECREMENT_TOKEN = 273,
     ASSIGN_TOKEN = 274,
     EQUAL_TOKEN = 275,
     NOT_EQUAL_TOKEN = 276,
     LESS_TOKEN = 277,
     LESS_EQUAL_TOKEN = 278,
     GREATER_TOKEN = 279,
     GREATER_EQUAL_TOKEN = 280,
     AND_TOKEN = 281,
     OR_TOKEN = 282,
     LEFT_PAREN_TOKEN = 283,
     RIGHT_PAREN_TOKEN = 284,
     LEFT_BRACE_TOKEN = 285,
     RIGHT_BRACE_TOKEN = 286,
     SEMICOLON_TOKEN = 287,
     COMMA_TOKEN = 288,
     UMINUS = 289
   };
#endif
/* Tokens.  */
#define IDENTIFIER_TOKEN 258
#define INT_LITERAL_TOKEN 259
#define IF_TOKEN 260
#define FUNCTION_TOKEN 261
#define ELSE_TOKEN 262
#define FOR_TOKEN 263
#define RETURN_TOKEN 264
#define TRUE_TOKEN 265
#define FALSE_TOKEN 266
#define PLUS_TOKEN 267
#define MINUS_TOKEN 268
#define MULTIPLY_TOKEN 269
#define DIVIDE_TOKEN 270
#define MODULO_TOKEN 271
#define INCREMENT_TOKEN 272
#define DECREMENT_TOKEN 273
#define ASSIGN_TOKEN 274
#define EQUAL_TOKEN 275
#define NOT_EQUAL_TOKEN 276
#define LESS_TOKEN 277
#define LESS_EQUAL_TOKEN 278
#define GREATER_TOKEN 279
#define GREATER_EQUAL_TOKEN 280
#define AND_TOKEN 281
#define OR_TOKEN 282
#define LEFT_PAREN_TOKEN 283
#define RIGHT_PAREN_TOKEN 284
#define LEFT_BRACE_TOKEN 285
#define RIGHT_BRACE_TOKEN 286
#define SEMICOLON_TOKEN 287
#define COMMA_TOKEN 288
#define UMINUS 289




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

/* Function implementations for node creation and manipulation */

#include <stdarg.h>

/* Function to create a new node */
Node* create_node(NodeType type, int n_children, ...) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->strval = NULL;
    node->intval = 0;
    node->n_children = n_children;
    node->children = malloc(sizeof(Node*) * n_children);

    va_list args;
    va_start(args, n_children);
    for (int i = 0; i < n_children; i++) {
        node->children[i] = va_arg(args, Node*);
    }
    va_end(args);

    return node;
}

/* Function to create a leaf node */
Node* create_leaf_node(NodeType type, const char* strval, int intval) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->strval = strval ? strdup(strval) : NULL;
    node->intval = intval;
    node->n_children = 0;
    node->children = NULL;
    return node;
}

/* Function to print the parse tree */
void print_tree(Node* node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++)
        printf("  ");
    switch (node->type) {
        case NODE_PROGRAM:
            printf("Program\n");
            break;
        case NODE_FUNCTION_DEFINITION:
            printf("FunctionDefinition (%s)\n", node->children[0]->strval);
            break;
        case NODE_FUNCTION_LIST:
            printf("FunctionList\n");
            break;
        case NODE_PARAM_LIST:
            printf("ParamList\n");
            break;
        case NODE_STATEMENT_LIST:
            printf("StatementList\n");
            break;
        case NODE_STATEMENT:
            printf("Statement\n");
            break;
        case NODE_EXPRESSION_STATEMENT:
            printf("ExpressionStatement\n");
            break;
        case NODE_IF_STATEMENT:
            printf("IfStatement\n");
            break;
        case NODE_ELSE_STATEMENT:
            printf("ElseStatement\n");
            break;
        case NODE_FOR_STATEMENT:
            printf("ForStatement\n");
            break;
        case NODE_RETURN_STATEMENT:
            printf("ReturnStatement\n");
            break;
        case NODE_EXPRESSION:
            printf("Expression\n");
            break;
        case NODE_ASSIGNMENT:
            printf("AssignmentExpression\n");
            break;
        case NODE_BINARY_OP:
            printf("BinaryOp (%s)\n", node->strval);
            break;
        case NODE_UNARY_OP:
            printf("UnaryOp (%s)\n", node->strval);
            break;
        case NODE_POSTFIX_EXPRESSION:
            printf("PostfixExpression\n");
            break;
        case NODE_PRIMARY_EXPRESSION:
            printf("PrimaryExpression\n");
            break;
        case NODE_IDENTIFIER:
            printf("Identifier (%s)\n", node->strval);
            break;
        case NODE_INT_LITERAL:
            printf("IntLiteral (%d)\n", node->intval);
            break;
        case NODE_BOOL_LITERAL:
            printf("BoolLiteral (%s)\n", node->intval ? "true" : "false");
            break;
        default:
            printf("Unknown Node\n");
            break;
    }
    for (int i = 0; i < node->n_children; i++) {
        print_tree(node->children[i], indent + 1);
    }
}

/* Function to free the parse tree */
void free_tree(Node* node) {
    if (!node) return;
    for (int i = 0; i < node->n_children; i++) {
        free_tree(node->children[i]);
    }
    if (node->strval) free(node->strval);
    if (node->children) free(node->children);
    free(node);
}

int yylex(void);
void yyerror(const char *s);

/* The root of the parse tree */
Node* root_node;



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
typedef union YYSTYPE
#line 140 "parser.y"
{
    int intval;
    char* strval;
    Node* nodeptr;
}
/* Line 193 of yacc.c.  */
#line 305 "parser.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 318 "parser.tab.c"

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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNRULES -- Number of states.  */
#define YYNSTATES  113

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    19,    20,    22,    24,
      28,    29,    32,    34,    36,    38,    40,    42,    46,    49,
      51,    58,    59,    62,    70,    72,    74,    75,    77,    81,
      82,    84,    86,    90,    92,    96,    98,   102,   104,   108,
     112,   114,   118,   122,   126,   130,   132,   136,   140,   142,
     146,   150,   154,   156,   159,   162,   165,   167,   169,   172,
     175,   180,   181,   183,   185,   189,   191,   193,   195,   197
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    37,    -1,    37,    38,    -1,    38,    -1,
       6,     3,    28,    39,    29,    30,    41,    31,    -1,    -1,
      40,    -1,     3,    -1,    40,    33,     3,    -1,    -1,    41,
      42,    -1,    44,    -1,    45,    -1,    47,    -1,    51,    -1,
      43,    -1,    30,    41,    31,    -1,    53,    32,    -1,    32,
      -1,     5,    28,    53,    29,    42,    46,    -1,    -1,     7,
      42,    -1,     8,    28,    48,    49,    50,    29,    42,    -1,
      44,    -1,    44,    -1,    -1,    53,    -1,     9,    52,    32,
      -1,    -1,    53,    -1,    54,    -1,     3,    19,    53,    -1,
      55,    -1,    55,    27,    56,    -1,    56,    -1,    56,    26,
      57,    -1,    57,    -1,    57,    20,    58,    -1,    57,    21,
      58,    -1,    58,    -1,    58,    22,    59,    -1,    58,    23,
      59,    -1,    58,    24,    59,    -1,    58,    25,    59,    -1,
      59,    -1,    59,    12,    60,    -1,    59,    13,    60,    -1,
      60,    -1,    60,    14,    61,    -1,    60,    15,    61,    -1,
      60,    16,    61,    -1,    61,    -1,    13,    61,    -1,    17,
      61,    -1,    18,    61,    -1,    62,    -1,    65,    -1,    62,
      17,    -1,    62,    18,    -1,    62,    28,    63,    29,    -1,
      -1,    64,    -1,    53,    -1,    64,    33,    53,    -1,     3,
      -1,     4,    -1,    10,    -1,    11,    -1,    28,    53,    29,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   201,   201,   208,   212,   220,   233,   236,   243,   247,
     264,   267,   283,   287,   291,   295,   299,   307,   314,   318,
     325,   336,   339,   347,   354,   361,   369,   372,   380,   391,
     394,   402,   410,   416,   424,   429,   437,   442,   450,   455,
     460,   468,   473,   478,   483,   488,   496,   501,   506,   514,
     519,   524,   529,   537,   542,   547,   552,   560,   564,   569,
     574,   583,   586,   593,   597,   612,   616,   620,   624,   628
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER_TOKEN", "INT_LITERAL_TOKEN",
  "IF_TOKEN", "FUNCTION_TOKEN", "ELSE_TOKEN", "FOR_TOKEN", "RETURN_TOKEN",
  "TRUE_TOKEN", "FALSE_TOKEN", "PLUS_TOKEN", "MINUS_TOKEN",
  "MULTIPLY_TOKEN", "DIVIDE_TOKEN", "MODULO_TOKEN", "INCREMENT_TOKEN",
  "DECREMENT_TOKEN", "ASSIGN_TOKEN", "EQUAL_TOKEN", "NOT_EQUAL_TOKEN",
  "LESS_TOKEN", "LESS_EQUAL_TOKEN", "GREATER_TOKEN", "GREATER_EQUAL_TOKEN",
  "AND_TOKEN", "OR_TOKEN", "LEFT_PAREN_TOKEN", "RIGHT_PAREN_TOKEN",
  "LEFT_BRACE_TOKEN", "RIGHT_BRACE_TOKEN", "SEMICOLON_TOKEN",
  "COMMA_TOKEN", "UMINUS", "$accept", "Program", "FunctionDefinitionList",
  "FunctionDefinition", "ParamListOpt", "ParamList", "StatementList",
  "Statement", "Block", "ExpressionStatement", "IfStatement", "ElseOpt",
  "ForStatement", "ForInit", "ForCondition", "ForStep", "ReturnStatement",
  "ExpressionOpt", "Expression", "AssignmentExpression",
  "LogicalOrExpression", "LogicalAndExpression", "EqualityExpression",
  "RelationalExpression", "AdditiveExpression", "MultiplicativeExpression",
  "UnaryExpression", "PostfixExpression", "ArgumentListOpt",
  "ArgumentList", "PrimaryExpression", 0
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
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    36,    37,    37,    38,    39,    39,    40,    40,
      41,    41,    42,    42,    42,    42,    42,    43,    44,    44,
      45,    46,    46,    47,    48,    49,    50,    50,    51,    52,
      52,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      57,    58,    58,    58,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    61,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    65
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     8,     0,     1,     1,     3,
       0,     2,     1,     1,     1,     1,     1,     3,     2,     1,
       6,     0,     2,     7,     1,     1,     0,     1,     3,     0,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     1,     1,     2,     2,
       4,     0,     1,     1,     3,     1,     1,     1,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     1,     3,     6,     8,
       0,     7,     0,     0,    10,     9,     0,    65,    66,     0,
       0,    29,    67,    68,     0,     0,     0,     0,    10,     5,
      19,    11,    16,    12,    13,    14,    15,     0,    31,    33,
      35,    37,    40,    45,    48,    52,    56,    57,     0,     0,
       0,     0,    30,    65,    53,    54,    55,     0,     0,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,    59,    61,    32,     0,    24,     0,
      28,    69,    17,    34,    36,    38,    39,    41,    42,    43,
      44,    46,    47,    49,    50,    51,    63,     0,    62,     0,
      25,    26,    60,     0,    21,     0,    27,    64,     0,    20,
       0,    22,    23
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    10,    11,    16,    31,    32,    33,
      34,   109,    35,    79,   101,   105,    36,    51,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    97,    98,
      47
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -70
static const yytype_int16 yypact[] =
{
      10,    17,     5,    10,   -70,     3,   -70,   -70,    37,   -70,
      24,    13,    29,    60,   -70,   -70,     4,    50,   -70,    44,
      45,   112,   -70,   -70,   128,   128,   128,   112,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,    42,   -70,    49,
      55,   -10,    20,    25,    52,   -70,     1,   -70,   112,   112,
      96,    54,   -70,   -70,   -70,   -70,   -70,    58,    47,   -70,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   -70,   -70,   112,   -70,    63,   -70,    96,
     -70,   -70,   -70,    55,   -10,    20,    20,    25,    25,    25,
      25,    52,    52,   -70,   -70,   -70,   -70,    65,    62,    80,
     -70,   112,   -70,   112,    89,    72,   -70,   -70,    80,   -70,
      80,   -70,   -70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -70,    99,   -70,   -70,    75,   -69,   -70,   -46,
     -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -21,   -70,
     -70,    51,    43,    -1,   -41,     2,   -23,   -70,   -70,   -70,
     -70
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      52,    54,    55,    56,    78,     6,    57,    17,    18,    19,
      62,    63,    20,    21,    22,    23,     1,    24,    73,    74,
       5,    25,    26,    87,    88,    89,    90,    76,    77,    75,
     104,     8,    27,   100,    28,    29,    30,    68,    69,   111,
       9,   112,    64,    65,    66,    67,    13,    93,    94,    95,
      17,    18,    19,    12,    96,    20,    21,    22,    23,    14,
      24,    85,    86,    15,    25,    26,    70,    71,    72,    48,
      91,    92,    49,    50,    59,    27,    60,    28,    82,    30,
     106,    61,   107,    17,    18,    19,    80,    81,    20,    21,
      22,    23,    99,    24,   102,   103,   108,    25,    26,    17,
      18,   110,     7,    58,    84,     0,    22,    23,    27,    24,
      28,    83,    30,    25,    26,    17,    18,     0,     0,     0,
       0,     0,    22,    23,    27,    24,     0,     0,    30,    25,
      26,    53,    18,     0,     0,     0,     0,     0,    22,    23,
      27,    24,     0,     0,     0,    25,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27
};

static const yytype_int8 yycheck[] =
{
      21,    24,    25,    26,    50,     0,    27,     3,     4,     5,
      20,    21,     8,     9,    10,    11,     6,    13,    17,    18,
       3,    17,    18,    64,    65,    66,    67,    48,    49,    28,
      99,    28,    28,    79,    30,    31,    32,    12,    13,   108,
       3,   110,    22,    23,    24,    25,    33,    70,    71,    72,
       3,     4,     5,    29,    75,     8,     9,    10,    11,    30,
      13,    62,    63,     3,    17,    18,    14,    15,    16,    19,
      68,    69,    28,    28,    32,    28,    27,    30,    31,    32,
     101,    26,   103,     3,     4,     5,    32,    29,     8,     9,
      10,    11,    29,    13,    29,    33,     7,    17,    18,     3,
       4,    29,     3,    28,    61,    -1,    10,    11,    28,    13,
      30,    60,    32,    17,    18,     3,     4,    -1,    -1,    -1,
      -1,    -1,    10,    11,    28,    13,    -1,    -1,    32,    17,
      18,     3,     4,    -1,    -1,    -1,    -1,    -1,    10,    11,
      28,    13,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    36,    37,    38,     3,     0,    38,    28,     3,
      39,    40,    29,    33,    30,     3,    41,     3,     4,     5,
       8,     9,    10,    11,    13,    17,    18,    28,    30,    31,
      32,    42,    43,    44,    45,    47,    51,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    65,    19,    28,
      28,    52,    53,     3,    61,    61,    61,    53,    41,    32,
      27,    26,    20,    21,    22,    23,    24,    25,    12,    13,
      14,    15,    16,    17,    18,    28,    53,    53,    44,    48,
      32,    29,    31,    56,    57,    58,    58,    59,    59,    59,
      59,    60,    60,    61,    61,    61,    53,    63,    64,    29,
      44,    49,    29,    33,    42,    50,    53,    53,     7,    46,
      29,    42,    42
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
        case 2:
#line 202 "parser.y"
    {
        root_node = create_node(NODE_PROGRAM, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 3:
#line 209 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_FUNCTION_LIST, 2, (yyvsp[(1) - (2)].nodeptr), (yyvsp[(2) - (2)].nodeptr));
    ;}
    break;

  case 4:
#line 213 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_FUNCTION_LIST, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 5:
#line 221 "parser.y"
    {
        /* $2 is the function name */
        (yyval.nodeptr) = create_node(NODE_FUNCTION_DEFINITION, 3,
                         create_leaf_node(NODE_IDENTIFIER, (yyvsp[(2) - (8)].strval), 0),
                         (yyvsp[(4) - (8)].nodeptr), /* Parameters */
                         (yyvsp[(7) - (8)].nodeptr)  /* Statements */
                         );
    ;}
    break;

  case 6:
#line 233 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_PARAM_LIST, 0);
    ;}
    break;

  case 7:
#line 237 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 8:
#line 244 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_PARAM_LIST, 1, create_leaf_node(NODE_IDENTIFIER, (yyvsp[(1) - (1)].strval), 0));
    ;}
    break;

  case 9:
#line 248 "parser.y"
    {
        /* Add the new parameter to the existing list */
        Node** new_children = realloc((yyvsp[(1) - (3)].nodeptr)->children, sizeof(Node*) * ((yyvsp[(1) - (3)].nodeptr)->n_children + 1));
        if (!new_children) {
            yyerror("Out of memory");
            exit(1);
        }
        (yyvsp[(1) - (3)].nodeptr)->children = new_children;
        (yyvsp[(1) - (3)].nodeptr)->children[(yyvsp[(1) - (3)].nodeptr)->n_children++] = create_leaf_node(NODE_IDENTIFIER, (yyvsp[(3) - (3)].strval), 0);
        (yyval.nodeptr) = (yyvsp[(1) - (3)].nodeptr);
    ;}
    break;

  case 10:
#line 264 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_STATEMENT_LIST, 0);
    ;}
    break;

  case 11:
#line 268 "parser.y"
    {
        /* Add the new statement to the list */
        Node** new_children = realloc((yyvsp[(1) - (2)].nodeptr)->children, sizeof(Node*) * ((yyvsp[(1) - (2)].nodeptr)->n_children + 1));
        if (!new_children) {
            yyerror("Out of memory");
            exit(1);
        }
        (yyvsp[(1) - (2)].nodeptr)->children = new_children;
        (yyvsp[(1) - (2)].nodeptr)->children[(yyvsp[(1) - (2)].nodeptr)->n_children++] = (yyvsp[(2) - (2)].nodeptr);
        (yyval.nodeptr) = (yyvsp[(1) - (2)].nodeptr);
    ;}
    break;

  case 12:
#line 284 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_STATEMENT, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 13:
#line 288 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_STATEMENT, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 14:
#line 292 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_STATEMENT, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 15:
#line 296 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_STATEMENT, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 16:
#line 300 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_STATEMENT, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 17:
#line 308 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(2) - (3)].nodeptr);
    ;}
    break;

  case 18:
#line 315 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_EXPRESSION_STATEMENT, 1, (yyvsp[(1) - (2)].nodeptr));
    ;}
    break;

  case 19:
#line 319 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_EXPRESSION_STATEMENT, 0);
    ;}
    break;

  case 20:
#line 326 "parser.y"
    {
        if ((yyvsp[(6) - (6)].nodeptr))
            (yyval.nodeptr) = create_node(NODE_IF_STATEMENT, 3, (yyvsp[(3) - (6)].nodeptr), (yyvsp[(5) - (6)].nodeptr), (yyvsp[(6) - (6)].nodeptr));
        else
            (yyval.nodeptr) = create_node(NODE_IF_STATEMENT, 2, (yyvsp[(3) - (6)].nodeptr), (yyvsp[(5) - (6)].nodeptr));
    ;}
    break;

  case 21:
#line 336 "parser.y"
    {
        (yyval.nodeptr) = NULL;
    ;}
    break;

  case 22:
#line 340 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_ELSE_STATEMENT, 1, (yyvsp[(2) - (2)].nodeptr));
    ;}
    break;

  case 23:
#line 348 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_FOR_STATEMENT, 4, (yyvsp[(3) - (7)].nodeptr), (yyvsp[(4) - (7)].nodeptr), (yyvsp[(5) - (7)].nodeptr), (yyvsp[(7) - (7)].nodeptr));
    ;}
    break;

  case 24:
#line 355 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 25:
#line 362 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 26:
#line 369 "parser.y"
    {
        (yyval.nodeptr) = NULL;
    ;}
    break;

  case 27:
#line 373 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 28:
#line 381 "parser.y"
    {
        if ((yyvsp[(2) - (3)].nodeptr))
            (yyval.nodeptr) = create_node(NODE_RETURN_STATEMENT, 1, (yyvsp[(2) - (3)].nodeptr));
        else
            (yyval.nodeptr) = create_node(NODE_RETURN_STATEMENT, 0);
    ;}
    break;

  case 29:
#line 391 "parser.y"
    {
        (yyval.nodeptr) = NULL;
    ;}
    break;

  case 30:
#line 395 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 31:
#line 403 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 32:
#line 411 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_ASSIGNMENT, 2,
                         create_leaf_node(NODE_IDENTIFIER, (yyvsp[(1) - (3)].strval), 0),
                         (yyvsp[(3) - (3)].nodeptr));
    ;}
    break;

  case 33:
#line 417 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 34:
#line 425 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("||");
    ;}
    break;

  case 35:
#line 430 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 36:
#line 438 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("&&");
    ;}
    break;

  case 37:
#line 443 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 38:
#line 451 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("==");
    ;}
    break;

  case 39:
#line 456 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("!=");
    ;}
    break;

  case 40:
#line 461 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 41:
#line 469 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("<");
    ;}
    break;

  case 42:
#line 474 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("<=");
    ;}
    break;

  case 43:
#line 479 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup(">");
    ;}
    break;

  case 44:
#line 484 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup(">=");
    ;}
    break;

  case 45:
#line 489 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 46:
#line 497 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("+");
    ;}
    break;

  case 47:
#line 502 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("-");
    ;}
    break;

  case 48:
#line 507 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 49:
#line 515 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("*");
    ;}
    break;

  case 50:
#line 520 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("/");
    ;}
    break;

  case 51:
#line 525 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_BINARY_OP, 2, (yyvsp[(1) - (3)].nodeptr), (yyvsp[(3) - (3)].nodeptr));
        (yyval.nodeptr)->strval = strdup("%");
    ;}
    break;

  case 52:
#line 530 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 53:
#line 538 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_UNARY_OP, 1, (yyvsp[(2) - (2)].nodeptr));
        (yyval.nodeptr)->strval = strdup("-");
    ;}
    break;

  case 54:
#line 543 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_UNARY_OP, 1, (yyvsp[(2) - (2)].nodeptr));
        (yyval.nodeptr)->strval = strdup("++");
    ;}
    break;

  case 55:
#line 548 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_UNARY_OP, 1, (yyvsp[(2) - (2)].nodeptr));
        (yyval.nodeptr)->strval = strdup("--");
    ;}
    break;

  case 56:
#line 553 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 57:
#line 561 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 58:
#line 565 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_UNARY_OP, 1, (yyvsp[(1) - (2)].nodeptr));
        (yyval.nodeptr)->strval = strdup("++");
    ;}
    break;

  case 59:
#line 570 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_UNARY_OP, 1, (yyvsp[(1) - (2)].nodeptr));
        (yyval.nodeptr)->strval = strdup("--");
    ;}
    break;

  case 60:
#line 575 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_POSTFIX_EXPRESSION, 2, (yyvsp[(1) - (4)].nodeptr), (yyvsp[(3) - (4)].nodeptr));
    ;}
    break;

  case 61:
#line 583 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_EXPRESSION, 0);
    ;}
    break;

  case 62:
#line 587 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(1) - (1)].nodeptr);
    ;}
    break;

  case 63:
#line 594 "parser.y"
    {
        (yyval.nodeptr) = create_node(NODE_EXPRESSION, 1, (yyvsp[(1) - (1)].nodeptr));
    ;}
    break;

  case 64:
#line 598 "parser.y"
    {
        /* Add the new expression to the existing list */
        Node** new_children = realloc((yyvsp[(1) - (3)].nodeptr)->children, sizeof(Node*) * ((yyvsp[(1) - (3)].nodeptr)->n_children + 1));
        if (!new_children) {
            yyerror("Out of memory");
            exit(1);
        }
        (yyvsp[(1) - (3)].nodeptr)->children = new_children;
        (yyvsp[(1) - (3)].nodeptr)->children[(yyvsp[(1) - (3)].nodeptr)->n_children++] = (yyvsp[(3) - (3)].nodeptr);
        (yyval.nodeptr) = (yyvsp[(1) - (3)].nodeptr);
    ;}
    break;

  case 65:
#line 613 "parser.y"
    {
        (yyval.nodeptr) = create_leaf_node(NODE_IDENTIFIER, (yyvsp[(1) - (1)].strval), 0);
    ;}
    break;

  case 66:
#line 617 "parser.y"
    {
        (yyval.nodeptr) = create_leaf_node(NODE_INT_LITERAL, NULL, (yyvsp[(1) - (1)].intval));
    ;}
    break;

  case 67:
#line 621 "parser.y"
    {
        (yyval.nodeptr) = create_leaf_node(NODE_BOOL_LITERAL, NULL, 1);
    ;}
    break;

  case 68:
#line 625 "parser.y"
    {
        (yyval.nodeptr) = create_leaf_node(NODE_BOOL_LITERAL, NULL, 0);
    ;}
    break;

  case 69:
#line 629 "parser.y"
    {
        (yyval.nodeptr) = (yyvsp[(2) - (3)].nodeptr);
    ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2162 "parser.tab.c"
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


#line 634 "parser.y"


/* Error-handling */
void yyerror(const char *s) {
    fprintf(stderr, "Parser Error: %s\n", s);
}

/* After parsing is complete, print and free the parse tree */
int main(int argc, char **argv) {
    if (argc > 1) {
        extern FILE* yyin;
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[1]);
            return 1;
        }
    }
    if (yyparse() == 0) { /* Parsing succeeded */
        if (root_node) {
            printf("Parse Tree:\n");
            print_tree(root_node, 0);
            free_tree(root_node);
        }
    }
    return 0;
}
