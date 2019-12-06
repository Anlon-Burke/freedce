/* A Bison parser, made by GNU Bison 1.875c.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* If NAME_PREFIX is specified substitute the variables and functions
   names.  */
#define yyparse acf_yyparse
#define yylex   acf_yylex
#define yyerror acf_yyerror
#define yylval  acf_yylval
#define yychar  acf_yychar
#define yydebug acf_yydebug
#define yynerrs acf_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     AUTO_HANDLE_KW = 258,
     BINDING_CALLOUT_KW = 259,
     CODE_KW = 260,
     COMM_STATUS_KW = 261,
     CS_CHAR_KW = 262,
     CS_TAG_RTN_KW = 263,
     ENABLE_ALLOCATE_KW = 264,
     EXPLICIT_HANDLE_KW = 265,
     EXTERN_EXCEPS_KW = 266,
     FAULT_STATUS_KW = 267,
     HANDLE_T_KW = 268,
     HEAP_KW = 269,
     IMPLICIT_HANDLE_KW = 270,
     INCLUDE_KW = 271,
     INTERFACE_KW = 272,
     IN_LINE_KW = 273,
     NOCODE_KW = 274,
     OUT_OF_LINE_KW = 275,
     REPRESENT_AS_KW = 276,
     TYPEDEF_KW = 277,
     COMMA = 278,
     LBRACE = 279,
     LBRACKET = 280,
     LPAREN = 281,
     RBRACE = 282,
     RBRACKET = 283,
     RPAREN = 284,
     SEMI = 285,
     TILDE = 286,
     UNKNOWN = 287,
     IDENTIFIER = 288,
     STRING = 289
   };
#endif
#define AUTO_HANDLE_KW 258
#define BINDING_CALLOUT_KW 259
#define CODE_KW 260
#define COMM_STATUS_KW 261
#define CS_CHAR_KW 262
#define CS_TAG_RTN_KW 263
#define ENABLE_ALLOCATE_KW 264
#define EXPLICIT_HANDLE_KW 265
#define EXTERN_EXCEPS_KW 266
#define FAULT_STATUS_KW 267
#define HANDLE_T_KW 268
#define HEAP_KW 269
#define IMPLICIT_HANDLE_KW 270
#define INCLUDE_KW 271
#define INTERFACE_KW 272
#define IN_LINE_KW 273
#define NOCODE_KW 274
#define OUT_OF_LINE_KW 275
#define REPRESENT_AS_KW 276
#define TYPEDEF_KW 277
#define COMMA 278
#define LBRACE 279
#define LBRACKET 280
#define LPAREN 281
#define RBRACE 282
#define RBRACKET 283
#define RPAREN 284
#define SEMI 285
#define TILDE 286
#define UNKNOWN 287
#define IDENTIFIER 288
#define STRING 289




/* Copy the first part of user declarations.  */
#line 44 "acf_y.y"


  /* Tank Trap to stop older yacc parsers */
  /* Bison defines the macro YYBISON      */

#ifndef YYBISON
This grammar file needs to be built with GNU Bison V1.25 or later.
  GNU Bison can be be obtained from ftp://prep.ai.mit.edu:/pub/gnu
#endif

/* Declarations in this section are copied from yacc source to y_tab.c. */

#include <nidl.h>               /* IDL compiler-wide defs */
#include <acf.h>                /* ACF include file - keep first! */

#include <ast.h>                /* Abstract Syntax Tree defs */
#include <astp.h>               /* Import AST processing routine defs */
#include <command.h>            /* Command line defs */
#include <message.h>            /* Error message defs */
#include <nidlmsg.h>            /* Error message IDs */
#include <files.h>
#include <propagat.h>
#include <checker.h>
#include <flex_bison_support.h>

#include <stdarg.h>   /* va_list */

extern AST_interface_n_t *the_interface;    /* Ptr to AST interface node */
extern boolean ASTP_parsing_main_idl;       /* True when parsing main IDL */
extern int acf_yylineno;
extern int acf_yylex(void);

typedef union                   /* Attributes bitmask */
{
    struct
    {
        unsigned auto_handle    : 1;
        unsigned binding_callout: 1;
        unsigned code           : 1;
        unsigned comm_status    : 1;
        unsigned cs_char        : 1;
        unsigned cs_drtag       : 1;
        unsigned cs_rtag        : 1;
        unsigned cs_stag        : 1;
        unsigned cs_tag_rtn     : 1;
        unsigned decode         : 1;
        unsigned enable_allocate: 1;
        unsigned encode         : 1;
        unsigned explicit_handle: 1;
        unsigned extern_exceps  : 1;
        unsigned fault_status   : 1;
        unsigned heap           : 1;
        unsigned implicit_handle: 1;
        unsigned in_line        : 1;
        unsigned nocode         : 1;
        unsigned out_of_line    : 1;
        unsigned represent_as   : 1;
    }   bit;
    long    mask;
}   acf_attrib_t;

typedef struct acf_param_t      /* ACF parameter info structure */
{
    struct acf_param_t *next;                   /* Forward link */
    acf_attrib_t    parameter_attr;             /* Parameter attributes */
    NAMETABLE_id_t  param_id;                   /* Parameter name */
}   acf_param_t;


static acf_attrib_t interface_attr,     /* Interface attributes */
                    type_attr,          /* Type attributes */
                    operation_attr,     /* Operation attributes */
                    parameter_attr;     /* Parameter attributes */

static char const *interface_name;        /* Interface name */
static char const *impl_name;             /* Implicit handle name */
static char const *type_name;             /* Current type name */
static char const *repr_type_name;        /* Current represent_as type */
static char const *cs_char_type_name;     /* Current cs_char type */
static char const *operation_name;        /* Current operation name */
static char const *cs_tag_rtn_name;       /* Current cs_tag_rtn name */
static char const *binding_callout_name;  /* Current binding_callout name */

static boolean  named_type;             /* True if parsed type is named type */

static AST_include_n_t  *include_list,  /* List of AST include nodes */
                        *include_p;     /* Ptr to a created include node */

static acf_param_t  *parameter_list,        /* Param list for curr. operation */
                    *parameter_free_list;   /* List of available acf_param_t */
static boolean      parameter_attr_list;    /* True if param attrs specified */

static boolean      *cmd_opt;       /* Array of command option flags */
static void         **cmd_val;      /* Array of command option values */

/*
 * Forward declarations to shut up the compiler
 */

void acf_init(boolean *, void **, char *);
void acf_cleanup();
static boolean lookup_exception(NAMETABLE_id_t, boolean, AST_exception_n_t **);
static boolean lookup_type(char const *, boolean, NAMETABLE_id_t *, AST_type_n_t **);
static boolean lookup_operation(char const *, boolean, NAMETABLE_id_t *, AST_operation_n_t **);
static boolean lookup_parameter(AST_operation_n_t *, char const *, boolean, NAMETABLE_id_t *, AST_parameter_n_t **);
static boolean lookup_rep_as_name(AST_type_p_n_t *, NAMETABLE_id_t, AST_type_n_t **, char const **);
static boolean lookup_cs_char_name(AST_type_p_n_t *, NAMETABLE_id_t, AST_type_n_t **, char const * *);
static acf_param_t * alloc_param();
static void free_param(acf_param_t *);
static void free_param_list(acf_param_t **);
void add_param_to_list(acf_param_t *, acf_param_t **);
static void append_parameter(AST_operation_n_t *, char const *, acf_attrib_t *);
static void process_rep_as_type(AST_interface_n_t *, AST_type_n_t *, char const *);
static void process_cs_char_type(AST_interface_n_t *, AST_type_n_t *, char const *);
#ifdef DUMPERS
static void dump_attributes(char *, char const *, acf_attrib_t *);
#endif
/*
 * Warning and Error stuff
 */

/*
**  a c f _ e r r o r
**
**  Issues an error message, and bumps the error count.
**
*/

void acf_error(long msgid,/* [in] Message id */
                        ...)
{
    va_list ap;
    va_start(ap, msgid);
    log_error(acf_yylineno, msgid, ap);
    va_end(ap);
}

/*
**  a c f _ w a r n i n g
**
**  Issues a warning message.
**
*/

void acf_warning(long msgid,/* [in] Message id */
                        ...)
{
    va_list ap;
    va_start(ap, msgid);
    log_warning(acf_yylineno, msgid, ap);
    va_end(ap);
}



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

#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 209 "acf_y.y"
typedef union YYSTYPE {
    NAMETABLE_id_t  y_id;       /* Identifier */
    STRTAB_str_t    y_string;   /* Text string */
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 313 "acf_y.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */
#line 325 "acf_y.c"

#if ! defined (yyoverflow) || YYERROR_VERBOSE

# ifndef YYFREE
#  define YYFREE free
# endif
# ifndef YYMALLOC
#  define YYMALLOC malloc
# endif

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   define YYSTACK_ALLOC alloca
#  endif
# else
#  if defined (alloca) || defined (_ALLOCA_H)
#   define YYSTACK_ALLOC alloca
#  else
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define YYSIZE_T size_t
#  endif
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
# endif
#endif /* ! defined (yyoverflow) || YYERROR_VERBOSE */


#if (! defined (yyoverflow) \
     && (! defined (__cplusplus) \
	 || (defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  short yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined (__GNUC__) && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register YYSIZE_T yyi;		\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (0)
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
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char yysigned_char;
#else
   typedef short yysigned_char;
#endif

/* YYFINAL -- State number of the termination state. */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  58
/* YYNRULES -- Number of rules. */
#define YYNRULES  111
/* YYNRULES -- Number of states. */
#define YYNSTATES  161

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX) 						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const unsigned char yytranslate[] =
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
static const unsigned short yyprhs[] =
{
       0,     0,     3,     6,    10,    14,    15,    17,    21,    23,
      25,    27,    29,    31,    33,    35,    37,    39,    41,    43,
      48,    51,    53,    55,    57,    59,    64,    66,    68,    72,
      74,    76,    80,    83,    85,    88,    90,    93,    96,    99,
     102,   105,   108,   111,   113,   117,   119,   122,   126,   128,
     132,   134,   137,   138,   141,   144,   147,   149,   153,   155,
     157,   159,   161,   163,   168,   170,   175,   177,   180,   182,
     186,   191,   195,   196,   198,   202,   204,   206,   208,   210,
     212,   214,   216,   218,   223,   225,   230,   232,   234,   235,
     237,   241,   244,   248,   249,   251,   255,   257,   259,   261,
     263,   265,   267,   269,   271,   273,   275,   277,   279,   281,
     283,   285
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const yysigned_char yyrhs[] =
{
      36,     0,    -1,    37,    50,    -1,    38,    17,    49,    -1,
      25,    39,    28,    -1,    -1,    40,    -1,    39,    23,    40,
      -1,    84,    -1,    85,    -1,    73,    -1,    75,    -1,    87,
      -1,    89,    -1,    90,    -1,    41,    -1,    83,    -1,    46,
      -1,    33,    -1,    15,    26,    42,    29,    -1,    43,    45,
      -1,    44,    -1,    33,    -1,    13,    -1,    33,    -1,    11,
      26,    47,    29,    -1,    11,    -1,    48,    -1,    47,    23,
      48,    -1,    33,    -1,    33,    -1,    24,    51,    27,    -1,
      24,    27,    -1,     1,    -1,     1,    27,    -1,    52,    -1,
      51,    52,    -1,    53,    30,    -1,    56,    30,    -1,    67,
      30,    -1,     1,    30,    -1,    16,    54,    -1,    16,     1,
      -1,    55,    -1,    54,    23,    55,    -1,    34,    -1,    22,
       1,    -1,    22,    59,    57,    -1,    58,    -1,    57,    23,
      58,    -1,    33,    -1,    25,    60,    -1,    -1,    61,    28,
      -1,     1,    30,    -1,     1,    28,    -1,    62,    -1,    61,
      23,    62,    -1,    63,    -1,    65,    -1,    88,    -1,    89,
      -1,    90,    -1,    21,    26,    64,    29,    -1,    33,    -1,
       7,    26,    66,    29,    -1,    33,    -1,    70,    68,    -1,
      69,    -1,    68,    23,    69,    -1,    33,    26,    77,    29,
      -1,    25,    71,    28,    -1,    -1,    72,    -1,    71,    23,
      72,    -1,    91,    -1,    84,    -1,    85,    -1,    75,    -1,
      86,    -1,    87,    -1,    92,    -1,    33,    -1,     4,    26,
      74,    29,    -1,    33,    -1,     8,    26,    76,    29,    -1,
      33,    -1,    78,    -1,    -1,    79,    -1,    78,    23,    79,
      -1,    80,    33,    -1,    25,    81,    28,    -1,    -1,    82,
      -1,    81,    23,    82,    -1,    91,    -1,    92,    -1,    88,
      -1,    89,    -1,    90,    -1,    33,    -1,     3,    -1,     5,
      -1,    19,    -1,     9,    -1,    10,    -1,    14,    -1,    18,
      -1,    20,    -1,     6,    -1,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   272,   272,   276,   368,   369,   373,   374,   378,   384,
     390,   396,   402,   408,   414,   420,   426,   432,   438,   458,
     462,   466,   470,   478,   482,   489,   490,   506,   507,   511,
     521,   528,   529,   530,   532,   537,   538,   542,   543,   544,
     545,   557,   565,   570,   571,   575,   618,   620,   629,   633,
     640,   690,   691,   695,   696,   700,   707,   708,   712,   718,
     724,   730,   736,   745,   749,   756,   760,   767,   775,   776,
     780,   935,   936,   940,   941,   945,   951,   957,   963,   969,
     975,   981,   987,  1007,  1011,  1018,  1022,  1029,  1030,  1034,
    1035,  1039,  1072,  1077,  1083,  1084,  1088,  1094,  1100,  1106,
    1112,  1118,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,
    1151,  1152
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "AUTO_HANDLE_KW", "BINDING_CALLOUT_KW",
  "CODE_KW", "COMM_STATUS_KW", "CS_CHAR_KW", "CS_TAG_RTN_KW",
  "ENABLE_ALLOCATE_KW", "EXPLICIT_HANDLE_KW", "EXTERN_EXCEPS_KW",
  "FAULT_STATUS_KW", "HANDLE_T_KW", "HEAP_KW", "IMPLICIT_HANDLE_KW",
  "INCLUDE_KW", "INTERFACE_KW", "IN_LINE_KW", "NOCODE_KW",
  "OUT_OF_LINE_KW", "REPRESENT_AS_KW", "TYPEDEF_KW", "COMMA", "LBRACE",
  "LBRACKET", "LPAREN", "RBRACE", "RBRACKET", "RPAREN", "SEMI", "TILDE",
  "UNKNOWN", "IDENTIFIER", "STRING", "$accept", "acf_interface",
  "acf_interface_header", "acf_interface_attr_list", "acf_interface_attrs",
  "acf_interface_attr", "acf_implicit_handle_attr", "acf_implicit_handle",
  "acf_impl_type", "acf_handle_type", "acf_impl_name",
  "acf_extern_exceps_attr", "acf_ext_excep_list", "acf_ext_excep",
  "acf_interface_name", "acf_interface_body", "acf_body_elements",
  "acf_body_element", "acf_include", "acf_include_list",
  "acf_include_name", "acf_type_declaration", "acf_named_type_list",
  "acf_named_type", "acf_type_attr_list", "acf_rest_of_attr_list",
  "acf_type_attrs", "acf_type_attr", "acf_represent_attr", "acf_repr_type",
  "acf_cs_char_attr", "acf_cs_char_type", "acf_operation_declaration",
  "acf_operations", "acf_operation", "acf_op_attr_list", "acf_op_attrs",
  "acf_op_attr", "acf_binding_callout_attr", "acf_binding_callout_name",
  "acf_cs_tag_rtn_attr", "acf_cs_tag_rtn_name", "acf_parameter_list",
  "acf_parameters", "acf_parameter", "acf_param_attr_list",
  "acf_param_attrs", "acf_param_attr", "acf_auto_handle_attr",
  "acf_code_attr", "acf_nocode_attr", "acf_enable_allocate_attr",
  "acf_explicit_handle_attr", "acf_heap_attr", "acf_inline_attr",
  "acf_outofline_attr", "acf_commstat_attr", "acf_faultstat_attr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const unsigned short yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,    35,    36,    37,    38,    38,    39,    39,    40,    40,
      40,    40,    40,    40,    40,    40,    40,    40,    40,    41,
      42,    43,    43,    44,    45,    46,    46,    47,    47,    48,
      49,    50,    50,    50,    50,    51,    51,    52,    52,    52,
      52,    53,    53,    54,    54,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    63,    64,    65,    66,    67,    68,    68,
      69,    70,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    73,    74,    75,    76,    77,    77,    78,
      78,    79,    80,    80,    81,    81,    82,    82,    82,    82,
      82,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     2,     3,     3,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       2,     1,     1,     1,     1,     4,     1,     1,     3,     1,
       1,     3,     2,     1,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     1,     3,     1,     2,     3,     1,     3,
       1,     2,     0,     2,     2,     2,     1,     3,     1,     1,
       1,     1,     1,     4,     1,     4,     1,     2,     1,     3,
       4,     3,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     1,     4,     1,     1,     0,     1,
       3,     2,     3,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char yydefact[] =
{
       5,     0,     0,     0,     0,   102,     0,   103,     0,   106,
      26,     0,   108,   104,   109,    18,     0,     6,    15,    17,
      10,    11,    16,     8,     9,    12,    13,    14,     1,    33,
       0,     2,     0,     0,     0,     0,     0,     0,     4,    34,
       0,     0,     0,     0,    32,     0,    35,     0,     0,     0,
       0,    30,     3,    84,     0,    86,     0,    29,     0,    27,
      23,    22,     0,     0,    21,     7,    40,    42,    45,    41,
      43,    46,     0,     0,   110,   105,   111,    82,     0,    73,
      78,    76,    77,    79,    80,    75,    81,    31,    36,    37,
      38,    39,     0,    67,    68,    83,    85,     0,    25,    19,
      24,    20,     0,     0,     0,   107,     0,    51,     0,    56,
      58,    59,    60,    61,    62,    50,    47,    48,     0,    71,
      88,     0,    28,    44,    55,    54,     0,     0,     0,    53,
       0,    74,     0,     0,    87,    89,     0,    69,    66,     0,
      64,     0,    57,    49,   101,     0,    94,    98,    99,   100,
      96,    97,    70,    93,    91,    65,    63,     0,    92,    90,
      95
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,     4,    16,    17,    18,    62,    63,    64,
     101,    19,    58,    59,    52,    31,    45,    46,    47,    69,
      70,    48,   116,   117,    73,   107,   108,   109,   110,   141,
     111,   139,    49,    93,    94,    50,    78,    79,    20,    54,
      21,    56,   133,   134,   135,   136,   145,   146,    22,    23,
      24,    83,    25,   112,    26,    27,    85,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -120
static const yysigned_char yypact[] =
{
     -14,    79,    20,    30,    38,  -120,     0,  -120,    32,  -120,
      48,    65,  -120,  -120,  -120,  -120,    25,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,    54,
       7,  -120,    59,    60,    69,    70,    -6,    79,  -120,  -120,
      41,     5,    11,     9,  -120,     8,  -120,    74,    75,    77,
      76,  -120,  -120,  -120,    81,  -120,    82,  -120,   -13,  -120,
    -120,  -120,    84,    83,  -120,  -120,  -120,  -120,  -120,    85,
    -120,  -120,    45,    86,  -120,  -120,  -120,  -120,    44,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,    88,    92,  -120,  -120,  -120,    70,  -120,  -120,
    -120,  -120,    87,    40,    91,  -120,    94,  -120,    72,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,    95,  -120,     9,  -120,
      63,    76,  -120,  -120,  -120,  -120,    89,    90,    55,  -120,
      86,  -120,    31,    96,   101,  -120,    93,  -120,  -120,    98,
    -120,    99,  -120,  -120,  -120,    78,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,   104,  -120,  -120,  -120,    31,  -120,  -120,
    -120
};

/* YYPGOTO[NTERM-NUM].  */
static const yysigned_char yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,    97,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,    33,  -120,  -120,  -120,   100,  -120,  -120,
      29,  -120,  -120,     2,  -120,  -120,  -120,    10,  -120,  -120,
    -120,  -120,  -120,  -120,    12,  -120,  -120,    17,  -120,  -120,
     -41,  -120,  -120,  -120,   -17,  -120,  -120,   -20,  -120,   -40,
     -39,  -120,   -38,  -119,   -72,   -71,  -110,  -107
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -94
static const short yytable[] =
{
     113,   114,    80,    81,    82,    84,    67,    60,    40,    40,
      97,     1,    71,   147,     7,    74,    98,     8,    75,     9,
      28,    76,   150,    41,    41,   151,    33,    61,    13,    42,
      42,    29,    43,    43,    44,    87,    72,    74,   147,    68,
     -72,   -72,    77,    76,   -52,   105,   103,   150,    37,    12,
     151,    14,   104,    38,    30,    32,   113,   114,    34,   105,
     148,   149,   104,    12,   144,    14,   106,   118,   124,   105,
     125,    66,   119,    12,    35,    14,   106,    80,    81,    82,
      84,    39,     5,     6,     7,   148,   149,     8,   132,     9,
      10,    36,    51,    53,    11,   128,   -93,    12,    13,    14,
     129,   157,    55,    57,    89,    90,   158,    91,   102,    92,
      95,    96,    15,    99,   120,   121,   100,   126,   130,   115,
     127,    68,   138,   140,   153,   152,   154,   155,   156,   132,
     122,   123,   143,   137,    65,   131,   159,   160,   142,     0,
       0,     0,     0,     0,     0,    88
};

static const short yycheck[] =
{
      72,    72,    43,    43,    43,    43,     1,    13,     1,     1,
      23,    25,     1,   132,     5,     6,    29,     8,     9,    10,
       0,    12,   132,    16,    16,   132,    26,    33,    19,    22,
      22,     1,    25,    25,    27,    27,    25,     6,   157,    34,
      33,    33,    33,    12,    33,    14,     1,   157,    23,    18,
     157,    20,     7,    28,    24,    17,   128,   128,    26,    14,
     132,   132,     7,    18,    33,    20,    21,    23,    28,    14,
      30,    30,    28,    18,    26,    20,    21,   118,   118,   118,
     118,    27,     3,     4,     5,   157,   157,     8,    25,    10,
      11,    26,    33,    33,    15,    23,    33,    18,    19,    20,
      28,    23,    33,    33,    30,    30,    28,    30,    23,    33,
      29,    29,    33,    29,    26,    23,    33,    26,    23,    33,
      26,    34,    33,    33,    23,    29,    33,    29,    29,    25,
      97,   102,   130,   121,    37,   118,   153,   157,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    45
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    25,    36,    37,    38,     3,     4,     5,     8,    10,
      11,    15,    18,    19,    20,    33,    39,    40,    41,    46,
      73,    75,    83,    84,    85,    87,    89,    90,     0,     1,
      24,    50,    17,    26,    26,    26,    26,    23,    28,    27,
       1,    16,    22,    25,    27,    51,    52,    53,    56,    67,
      70,    33,    49,    33,    74,    33,    76,    33,    47,    48,
      13,    33,    42,    43,    44,    40,    30,     1,    34,    54,
      55,     1,    25,    59,     6,     9,    12,    33,    71,    72,
      75,    84,    85,    86,    87,    91,    92,    27,    52,    30,
      30,    30,    33,    68,    69,    29,    29,    23,    29,    29,
      33,    45,    23,     1,     7,    14,    21,    60,    61,    62,
      63,    65,    88,    89,    90,    33,    57,    58,    23,    28,
      26,    23,    48,    55,    28,    30,    26,    26,    23,    28,
      23,    72,    25,    77,    78,    79,    80,    69,    33,    66,
      33,    64,    62,    58,    33,    81,    82,    88,    89,    90,
      91,    92,    29,    23,    33,    29,    29,    23,    28,    79,
      82
};

#if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
# define YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (YYSIZE_T) && defined (size_t)
# define YYSIZE_T size_t
#endif
#if ! defined (YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# endif
#endif
#if ! defined (YYSIZE_T)
# define YYSIZE_T unsigned int
#endif

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
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { 								\
      yyerror ("syntax error: cannot back up");\
      YYERROR;							\
    }								\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

/* YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)		\
   ((Current).first_line   = (Rhs)[1].first_line,	\
    (Current).first_column = (Rhs)[1].first_column,	\
    (Current).last_line    = (Rhs)[N].last_line,	\
    (Current).last_column  = (Rhs)[N].last_column)
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
} while (0)

# define YYDSYMPRINT(Args)			\
do {						\
  if (yydebug)					\
    yysymprint Args;				\
} while (0)

# define YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (yydebug)							\
    {								\
      YYFPRINTF (stderr, "%s ", Title);				\
      yysymprint (stderr, 					\
                  Token, Value);	\
      YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_stack_print (short *bottom, short *top)
#else
static void
yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yy_reduce_print (int yyrule)
#else
static void
yy_reduce_print (yyrule)
    int yyrule;
#endif
{
  int yyi;
  unsigned int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             yyrule - 1, yylno);
  /* Print the symbols being reduced, and their result.  */
  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YYDSYMPRINT(Args)
# define YYDSYMPRINTF(Title, Token, Value, Location)
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
   SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
# undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
yystrlen (const char *yystr)
#   else
yystrlen (yystr)
     const char *yystr;
#   endif
{
  register const char *yys = yystr;

  while (*yys++ != '\0')
    continue;

  return yys - yystr - 1;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
yystpcpy (char *yydest, const char *yysrc)
#   else
yystpcpy (yydest, yysrc)
     char *yydest;
     const char *yysrc;
#   endif
{
  register char *yyd = yydest;
  register const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

#endif /* !YYERROR_VERBOSE */



#if YYDEBUG
/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep)
#else
static void
yysymprint (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  if (yytype < YYNTOKENS)
    {
      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
# ifdef YYPRINT
      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
    }
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  switch (yytype)
    {
      default:
        break;
    }
  YYFPRINTF (yyoutput, ")");
}

#endif /* ! YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
yydestruct (int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yytype, yyvaluep)
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) yyvaluep;

  switch (yytype)
    {

      default:
        break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM);
# else
int yyparse ();
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int yyparse (void *YYPARSE_PARAM)
# else
int yyparse (YYPARSE_PARAM)
  void *YYPARSE_PARAM;
# endif
#else /* ! YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  register int yystate;
  register int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short	yyssa[YYINITDEPTH];
  short *yyss = yyssa;
  register short *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  register YYSTYPE *yyvsp;



#define YYPOPSTACK   (yyvsp--, yyssp--)

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int yylen;

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
     have just been pushed. so pushing a state here evens the stacks.
     */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	short *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow ("parser stack overflow",
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyoverflowlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	short *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyoverflowlab;
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

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
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
      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
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

  /* Shift the lookahead token.  */
  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  yystate = yyn;
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
        case 3:
#line 277 "acf_y.y"
    {
        char const      *ast_int_name;  /* Interface name in AST node */
        NAMETABLE_id_t  impl_name_id;   /* Nametable id of impl_handle var */

#ifdef DUMPERS
        if (cmd_opt[opt_dump_acf])
            dump_attributes("ACF interface", interface_name, &interface_attr);
#endif

        /* Store source information. */
        if (the_interface->fe_info != NULL)
        {
            the_interface->fe_info->acf_file = error_file_name_id;
            the_interface->fe_info->acf_source_line = acf_yylineno;
        }

        /*
         *  Interface attributes are saved for main and imported interfaces.
         *  the_interface = pointer to main or imported interface node
         *
         *  Make sure that the interface name in the ACF agrees with the
         *  interface name in the main IDL file.  Then set the parsed
         *  attributes in the interface node.
         *
         *  interface_attr = bitmask of interface attributes parsed.
         *  interface_name = ACF interface name parsed.
         */

        NAMETABLE_id_to_string(the_interface->name, &ast_int_name);

        if (strcmp(interface_name, ast_int_name) != 0)
        {
            char const *acf_int_name;   /* Ptr to permanent copy */
            NAMETABLE_id_t name_id;     /* Handle on permanent copy */
            char const *file_name;      /* Related file name */

            name_id = NAMETABLE_add_id(interface_name);
            NAMETABLE_id_to_string(name_id, &acf_int_name);

            STRTAB_str_to_string(the_interface->fe_info->file, &file_name);

            acf_error(NIDL_INTNAMDIF, acf_int_name, ast_int_name);
            acf_error(NIDL_NAMEDECLAT, ast_int_name, file_name,
                      the_interface->fe_info->source_line);
        }
        else
        {
            if (interface_attr.bit.code)
                AST_SET_CODE(the_interface);
            if (interface_attr.bit.nocode)
                AST_SET_NO_CODE(the_interface);
            if (interface_attr.bit.decode)
                AST_SET_DECODE(the_interface);
            if (interface_attr.bit.encode)
                AST_SET_ENCODE(the_interface);
            if (interface_attr.bit.explicit_handle)
                AST_SET_EXPLICIT_HANDLE(the_interface);
            if (interface_attr.bit.in_line)
                AST_SET_IN_LINE(the_interface);
            if (interface_attr.bit.out_of_line)
                AST_SET_OUT_OF_LINE(the_interface);
            if (interface_attr.bit.auto_handle)
                AST_SET_AUTO_HANDLE(the_interface);

            if (interface_attr.bit.cs_tag_rtn)
                the_interface->cs_tag_rtn_name = NAMETABLE_add_id(cs_tag_rtn_name);
            if (interface_attr.bit.binding_callout)
                the_interface->binding_callout_name = NAMETABLE_add_id(binding_callout_name);

            if (interface_attr.bit.implicit_handle)
            {
                /* Store the [implicit_handle] variable name in nametbl. */
                impl_name_id = NAMETABLE_add_id(impl_name);
		
					 ASTP_set_implicit_handle(the_interface,
					 	named_type ? NAMETABLE_add_id(type_name) : NAMETABLE_NIL_ID,
						impl_name_id);

            }
        }

        interface_name = NULL;
        type_name = NULL;
        impl_name = NULL;
        binding_callout_name = NULL;
        cs_tag_rtn_name = NULL;
        interface_attr.mask = 0;        /* Reset attribute mask */
    }
    break;

  case 8:
#line 379 "acf_y.y"
    {
        if (interface_attr.bit.code)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.code = TRUE;
    }
    break;

  case 9:
#line 385 "acf_y.y"
    {
        if (interface_attr.bit.nocode)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.nocode = TRUE;
    }
    break;

  case 10:
#line 391 "acf_y.y"
    {
        if (interface_attr.bit.binding_callout)
            acf_error(acf_yylineno, NIDL_ATTRUSEMULT, NULL);
        interface_attr.bit.binding_callout = TRUE;
    }
    break;

  case 11:
#line 397 "acf_y.y"
    {
        if (interface_attr.bit.cs_tag_rtn)
            acf_error(acf_yylineno, NIDL_ATTRUSEMULT, NULL);
        interface_attr.bit.cs_tag_rtn = TRUE;
    }
    break;

  case 12:
#line 403 "acf_y.y"
    {
        if (interface_attr.bit.explicit_handle)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.explicit_handle = TRUE;
    }
    break;

  case 13:
#line 409 "acf_y.y"
    {
        if (interface_attr.bit.in_line)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.in_line = TRUE;
    }
    break;

  case 14:
#line 415 "acf_y.y"
    {
        if (interface_attr.bit.out_of_line)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.out_of_line = TRUE;
    }
    break;

  case 15:
#line 421 "acf_y.y"
    {
        if (interface_attr.bit.implicit_handle)
            acf_error(acf_yylineno, NIDL_ATTRUSEMULT, NULL);
        interface_attr.bit.implicit_handle = TRUE;
    }
    break;

  case 16:
#line 427 "acf_y.y"
    {
        if (interface_attr.bit.auto_handle)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.auto_handle = TRUE;
    }
    break;

  case 17:
#line 433 "acf_y.y"
    {
        if (interface_attr.bit.extern_exceps)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        interface_attr.bit.extern_exceps = TRUE;
    }
    break;

  case 18:
#line 439 "acf_y.y"
    {
        if (NAMETABLE_add_id("decode") == yyvsp[0].y_id)
        {
            if (interface_attr.bit.decode)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            interface_attr.bit.decode = TRUE;
        }
        else if (NAMETABLE_add_id("encode") == yyvsp[0].y_id)
        {
            if (interface_attr.bit.encode)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            interface_attr.bit.encode = TRUE;
        }
        else
            acf_error(acf_yylineno, NIDL_ERRINATTR, NULL);
    }
    break;

  case 21:
#line 467 "acf_y.y"
    {
        named_type = FALSE;
    }
    break;

  case 22:
#line 471 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &type_name);
        named_type = TRUE;
    }
    break;

  case 24:
#line 483 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &impl_name);
    }
    break;

  case 26:
#line 491 "acf_y.y"
    {
        if (ASTP_parsing_main_idl)
        {
            AST_exception_n_t *excep_p;
            for (excep_p = the_interface->exceptions;
                 excep_p != NULL;
                 excep_p = excep_p->next)
            {
                AST_SET_EXTERN(excep_p);
            }
        }
    }
    break;

  case 29:
#line 512 "acf_y.y"
    {
        AST_exception_n_t *excep_p;
        if (ASTP_parsing_main_idl)
            if (lookup_exception(yyvsp[0].y_id, TRUE, &excep_p))
                AST_SET_EXTERN(excep_p);
    }
    break;

  case 30:
#line 522 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &interface_name);
    }
    break;

  case 33:
#line 531 "acf_y.y"
    { acf_error(acf_yylineno, NIDL_SYNTAXERR, NULL); }
    break;

  case 34:
#line 533 "acf_y.y"
    { acf_error(acf_yylineno, NIDL_SYNTAXERR, NULL); }
    break;

  case 40:
#line 546 "acf_y.y"
    {
            acf_error(acf_yylineno, NIDL_SYNTAXERR, NULL);
            /* Re-initialize attr masks to avoid sticky attributes */
            interface_attr.mask = 0;
            type_attr.mask      = 0;
            operation_attr.mask = 0;
            parameter_attr.mask = 0;
        }
    break;

  case 41:
#line 558 "acf_y.y"
    {
        if (ASTP_parsing_main_idl)
            the_interface->includes = (AST_include_n_t *)
                AST_concat_element((ASTP_node_t *)the_interface->includes,
                                   (ASTP_node_t *)include_list);
        include_list = NULL;
        }
    break;

  case 42:
#line 566 "acf_y.y"
    { acf_error(acf_yylineno, NIDL_SYNTAXERR, NULL); }
    break;

  case 45:
#line 576 "acf_y.y"
    {
        if (ASTP_parsing_main_idl)
        {
            char const      *parsed_include_file;
            char            include_type[PATH_MAX];
            char            include_file[PATH_MAX];
            STRTAB_str_t    include_file_id;

            STRTAB_str_to_string(yyvsp[0].y_string, &parsed_include_file);

            /*
             * Log warning if include name contains a file extension.
             * Tack on the correct extension based on the -lang option.
             */
            FILE_parse(parsed_include_file, (char *)NULL, (char *)NULL,
                       include_type);
            if (include_type[0] != '\0')
                acf_warning(NIDL_INCLUDEXT);

            FILE_form_filespec(parsed_include_file, (char *)NULL,
			       ".h",
                               (char *)NULL, include_file);

            /* Create an include node. */
            include_file_id = STRTAB_add_string(include_file);
            include_p = AST_include_node(include_file_id, yyvsp[0].y_string);

            /* Store source information. */
            if (include_p->fe_info != NULL)
            {
                include_p->fe_info->acf_file = error_file_name_id;
                include_p->fe_info->acf_source_line = acf_yylineno;
            }

            include_list = (AST_include_n_t *)
                AST_concat_element((ASTP_node_t *)include_list,
                                   (ASTP_node_t *)include_p);
        }
    }
    break;

  case 46:
#line 619 "acf_y.y"
    { acf_error(acf_yylineno, NIDL_SYNTAXERR, NULL); }
    break;

  case 47:
#line 621 "acf_y.y"
    {
        type_attr.mask = 0;             /* Reset attribute mask */
        repr_type_name = NULL;          /* Reset represent_as type name */
        cs_char_type_name = NULL;       /* Reset cs_char type name */
    }
    break;

  case 48:
#line 630 "acf_y.y"
    {
        type_name = NULL;               /* Reset type name */
    }
    break;

  case 49:
#line 634 "acf_y.y"
    {
        type_name = NULL;               /* Reset type name */
    }
    break;

  case 50:
#line 641 "acf_y.y"
    {
        NAMETABLE_id_t  type_id;        /* Nametable id of type name */
        AST_type_n_t    *type_p;        /* Ptr to AST type node */

        NAMETABLE_id_to_string(yyvsp[0].y_id, &type_name);

#ifdef DUMPERS
        if (cmd_opt[opt_dump_acf])
            dump_attributes("ACF type", type_name, &type_attr);
#endif

        /*
         *  Lookup the type_name parsed and verify that it is a valid type
         *  node.  Then set the parsed attributes in the type node.
         *
         *  type_attr = bitmask of type attributes parsed.
         *  type_name = name of type_t node to look up.
         *  [repr_type_name] = name of represent_as type.
         *  [cs_char_type_name] = name of cs_char type.
         */

        if (lookup_type(type_name, TRUE, &type_id, &type_p))
        {
            /* Store source information. */
            if (type_p->fe_info != NULL)
            {
                type_p->fe_info->acf_file = error_file_name_id;
                type_p->fe_info->acf_source_line = acf_yylineno;
            }

            if (type_attr.bit.heap
                && type_p->kind != AST_pipe_k
                && !AST_CONTEXT_RD_SET(type_p))
                PROP_set_type_attr(type_p,AST_HEAP);
            if (type_attr.bit.in_line)
                PROP_set_type_attr(type_p,AST_IN_LINE);
            if ((type_attr.bit.out_of_line) &&
                (type_p->kind != AST_pointer_k) &&
                (type_p->xmit_as_type == NULL))
                PROP_set_type_attr(type_p,AST_OUT_OF_LINE);
            if (type_attr.bit.represent_as)
                process_rep_as_type(the_interface, type_p, repr_type_name);
            if (type_attr.bit.cs_char)
                process_cs_char_type(the_interface, type_p, cs_char_type_name);
        }
    }
    break;

  case 54:
#line 697 "acf_y.y"
    {
        acf_error(acf_yylineno, NIDL_MISSONATTR, NULL);
        }
    break;

  case 55:
#line 701 "acf_y.y"
    {
        acf_error(acf_yylineno, NIDL_ERRINATTR, NULL);
        }
    break;

  case 58:
#line 713 "acf_y.y"
    {
        if (type_attr.bit.represent_as)
            acf_error(acf_yylineno, NIDL_ATTRUSEMULT, NULL);
        type_attr.bit.represent_as = TRUE;
    }
    break;

  case 59:
#line 719 "acf_y.y"
    {
        if (type_attr.bit.cs_char)
            acf_error(acf_yylineno, NIDL_ATTRUSEMULT, NULL);
        type_attr.bit.cs_char = TRUE;
    }
    break;

  case 60:
#line 725 "acf_y.y"
    {
        if (type_attr.bit.heap)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        type_attr.bit.heap = TRUE;
    }
    break;

  case 61:
#line 731 "acf_y.y"
    {
        if (type_attr.bit.in_line)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        type_attr.bit.in_line = TRUE;
    }
    break;

  case 62:
#line 737 "acf_y.y"
    {
        if (type_attr.bit.out_of_line)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        type_attr.bit.out_of_line = TRUE;
    }
    break;

  case 64:
#line 750 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &repr_type_name);
    }
    break;

  case 66:
#line 761 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &cs_char_type_name);
    }
    break;

  case 67:
#line 768 "acf_y.y"
    {
        operation_attr.mask = 0;        /* Reset attribute mask */
        cs_tag_rtn_name     = NULL;     /* Reset cs_tag_rtn name */
    }
    break;

  case 70:
#line 781 "acf_y.y"
    {
        acf_param_t         *p;         /* Ptr to local parameter structure */
        NAMETABLE_id_t      op_id;      /* Nametable id of operation name */
        NAMETABLE_id_t      param_id;   /* Nametable id of parameter name */
        AST_operation_n_t   *op_p;      /* Ptr to AST operation node */
        AST_parameter_n_t   *param_p;   /* Ptr to AST parameter node */
        boolean             log_error;  /* TRUE => error if name not found */
        char const          *param_name;/* character string of param id */

        NAMETABLE_id_to_string(yyvsp[-3].y_id, &operation_name);
#ifdef DUMPERS
        if (cmd_opt[opt_dump_acf])
            dump_attributes("ACF operation", operation_name, &operation_attr);
#endif

        /*
         *  Operation and parameter attributes are ignored for imported
         *  interfaces.  Operations and parameters within imported interfaces
         *  are not put in the AST.
         */
        if (ASTP_parsing_main_idl)
        {
            /*
             *  Lookup the operation_name parsed and verify that it is a valid
             *  operation node.  Then set the parsed attributes in the operation
             *  node.  For each parameter_name that was parsed for this
             *  operation, chase the parameter list off the AST operation node
             *  to verify that it is a valid parameter for that operation.
             *  Then set the parsed attributes for that parameter into the
             *  relevant parameter node.
             *
             *  operation_attr = bitmask of operation attributes parsed.
             *  operation_name = name of routine_t node to look up.
             *  [cs_tag_rtn_name] = cs_tag_rtn name.
             *  parameter_list = linked list of parameter information.
             */

            if (lookup_operation(operation_name, TRUE, &op_id, &op_p))
            {
                /* Store source information. */
                if (op_p->fe_info != NULL)
                {
                    op_p->fe_info->acf_file = error_file_name_id;
                    op_p->fe_info->acf_source_line = acf_yylineno;
                }

                if (operation_attr.bit.comm_status)
                {
                    /*
                     * Assume the AST Builder always builds a result param,
                     * even for void operations.
                     */
                    AST_SET_COMM_STATUS(op_p->result);
                }
                if (operation_attr.bit.fault_status)
                    AST_SET_FAULT_STATUS(op_p->result);

                if (operation_attr.bit.code)
                    AST_SET_CODE(op_p);
                if (operation_attr.bit.nocode)
                    AST_SET_NO_CODE(op_p);
                if (operation_attr.bit.decode)
                    AST_SET_DECODE(op_p);
                if (operation_attr.bit.encode)
                    AST_SET_ENCODE(op_p);
                if (operation_attr.bit.enable_allocate)
                    AST_SET_ENABLE_ALLOCATE(op_p);
                if (operation_attr.bit.explicit_handle)
                    AST_SET_EXPLICIT_HANDLE(op_p);
                if (operation_attr.bit.cs_tag_rtn)
                    op_p->cs_tag_rtn_name = NAMETABLE_add_id(cs_tag_rtn_name);

                for (p = parameter_list ; p != NULL ; p = p->next)
                {
                    /*
                     * Most parameter attributes, if present, require that the
                     * referenced parameter be defined in the IDL.  If only
                     * [comm_status] and/or [fault_status] is present, the
                     * parameter  needn't be IDL-defined.
                     */
                    if (!p->parameter_attr.bit.heap
                        &&  !p->parameter_attr.bit.in_line
                        &&  !p->parameter_attr.bit.out_of_line
                        &&  !p->parameter_attr.bit.cs_stag
                        &&  !p->parameter_attr.bit.cs_drtag
                        &&  !p->parameter_attr.bit.cs_rtag
                        &&  (p->parameter_attr.bit.comm_status
                             || p->parameter_attr.bit.fault_status))
                        log_error = FALSE;
                    else
                        log_error = TRUE;

                    NAMETABLE_id_to_string(p->param_id, &param_name);
                    if (lookup_parameter(op_p, param_name, log_error,
                                         &param_id, &param_p))
                    {
                        /* Store source information. */
                        if (param_p->fe_info != NULL)
                        {
                            param_p->fe_info->acf_file = error_file_name_id;
                            param_p->fe_info->acf_source_line = acf_yylineno;
                        }

                        if (p->parameter_attr.bit.comm_status)
                            AST_SET_COMM_STATUS(param_p);
                        if (p->parameter_attr.bit.fault_status)
                            AST_SET_FAULT_STATUS(param_p);
                        if (p->parameter_attr.bit.heap)
                        {
                            AST_type_n_t *ref_type_p;
                            ref_type_p = param_follow_ref_ptr(param_p,
                                                              CHK_follow_ref);
                            if (ref_type_p->kind != AST_pipe_k
                                && !AST_CONTEXT_SET(param_p)
                                && !AST_CONTEXT_RD_SET(ref_type_p)
                                && !type_is_scalar(ref_type_p))
                                AST_SET_HEAP(param_p);
                        }
                        if (p->parameter_attr.bit.in_line)
                            AST_SET_IN_LINE(param_p);
                        /*
                         * We parse the [out_of_line] parameter attribute,
                         * but disallow it.
                         */
                        if (p->parameter_attr.bit.out_of_line)
                            acf_error(NIDL_INVOOLPRM);
                        if (p->parameter_attr.bit.cs_stag)
                            AST_SET_CS_STAG(param_p);
                        if (p->parameter_attr.bit.cs_drtag)
                            AST_SET_CS_DRTAG(param_p);
                        if (p->parameter_attr.bit.cs_rtag)
                            AST_SET_CS_RTAG(param_p);
                    }
                    else if (log_error == FALSE)
                    {
                        /*
                         * Lookup failed, but OK since the parameter only has
                         * attribute(s) that specify an additional parameter.
                         * Append a parameter to the operation parameter list.
                         */
                        NAMETABLE_id_to_string(p->param_id, &param_name);
                        append_parameter(op_p, param_name, &p->parameter_attr);
                    }
                }
            }
        }

        free_param_list(&parameter_list);       /* Free parameter list */

        operation_name = NULL;
    }
    break;

  case 75:
#line 946 "acf_y.y"
    {
        if (operation_attr.bit.comm_status)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        operation_attr.bit.comm_status = TRUE;
    }
    break;

  case 76:
#line 952 "acf_y.y"
    {
        if (operation_attr.bit.code)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        operation_attr.bit.code = TRUE;
    }
    break;

  case 77:
#line 958 "acf_y.y"
    {
        if (operation_attr.bit.nocode)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        operation_attr.bit.nocode = TRUE;
    }
    break;

  case 78:
#line 964 "acf_y.y"
    {
        if (operation_attr.bit.cs_tag_rtn)
            acf_error(acf_yylineno, NIDL_ATTRUSEMULT, NULL);
        operation_attr.bit.cs_tag_rtn = TRUE;
    }
    break;

  case 79:
#line 970 "acf_y.y"
    {
        if (operation_attr.bit.enable_allocate)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        operation_attr.bit.enable_allocate = TRUE;
    }
    break;

  case 80:
#line 976 "acf_y.y"
    {
        if (operation_attr.bit.explicit_handle)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        operation_attr.bit.explicit_handle = TRUE;
    }
    break;

  case 81:
#line 982 "acf_y.y"
    {
        if (operation_attr.bit.fault_status)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        operation_attr.bit.fault_status = TRUE;
    }
    break;

  case 82:
#line 988 "acf_y.y"
    {
        if (NAMETABLE_add_id("decode") == yyvsp[0].y_id)
        {
            if (operation_attr.bit.decode)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            operation_attr.bit.decode = TRUE;
        }
        else if (NAMETABLE_add_id("encode") == yyvsp[0].y_id)
        {
            if (operation_attr.bit.encode)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            operation_attr.bit.encode = TRUE;
        }
        else
            acf_error(acf_yylineno, NIDL_ERRINATTR, NULL);
    }
    break;

  case 84:
#line 1012 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &binding_callout_name);
    }
    break;

  case 86:
#line 1023 "acf_y.y"
    {
        NAMETABLE_id_to_string(yyvsp[0].y_id, &cs_tag_rtn_name);
    }
    break;

  case 91:
#line 1040 "acf_y.y"
    {
#ifdef DUMPERS
        if (cmd_opt[opt_dump_acf])
        {
            char const *param_name;
            NAMETABLE_id_to_string(yyvsp[0].y_id, &param_name);
            dump_attributes("ACF parameter", param_name, &parameter_attr);
        }
#endif

        if (parameter_attr_list)        /* If there were param attributes: */
        {
            acf_param_t *p;             /* Pointer to parameter record */

            /*
             * Allocate and initialize a parameter record.
             */
            p = alloc_param();
            p->parameter_attr = parameter_attr;
            p->param_id = yyvsp[0].y_id;

            /*
             * Add to end of parameter list.
             */
            add_param_to_list(p, &parameter_list);

            parameter_attr.mask = 0;
        }
    }
    break;

  case 92:
#line 1073 "acf_y.y"
    {
        parameter_attr_list = TRUE;     /* Flag that we have param attributes */
    }
    break;

  case 93:
#line 1077 "acf_y.y"
    {
        parameter_attr_list = FALSE;
    }
    break;

  case 96:
#line 1089 "acf_y.y"
    {
        if (parameter_attr.bit.comm_status)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        parameter_attr.bit.comm_status = TRUE;
    }
    break;

  case 97:
#line 1095 "acf_y.y"
    {
        if (parameter_attr.bit.fault_status)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        parameter_attr.bit.fault_status = TRUE;
    }
    break;

  case 98:
#line 1101 "acf_y.y"
    {
        if (parameter_attr.bit.heap)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        parameter_attr.bit.heap = TRUE;
    }
    break;

  case 99:
#line 1107 "acf_y.y"
    {
        if (parameter_attr.bit.in_line)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        parameter_attr.bit.in_line = TRUE;
    }
    break;

  case 100:
#line 1113 "acf_y.y"
    {
        if (parameter_attr.bit.out_of_line)
            log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
        parameter_attr.bit.out_of_line = TRUE;
    }
    break;

  case 101:
#line 1119 "acf_y.y"
    {
        if (NAMETABLE_add_id("cs_stag") == yyvsp[0].y_id)
        {
            if (parameter_attr.bit.cs_stag)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            parameter_attr.bit.cs_stag = TRUE;
        }
        else if (NAMETABLE_add_id("cs_drtag") == yyvsp[0].y_id)
        {
            if (parameter_attr.bit.cs_drtag)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            parameter_attr.bit.cs_drtag = TRUE;
        }
        else if (NAMETABLE_add_id("cs_rtag") == yyvsp[0].y_id)
        {
            if (parameter_attr.bit.cs_rtag)
                log_warning(acf_yylineno, NIDL_MULATTRDEF, NULL);
            parameter_attr.bit.cs_rtag = TRUE;
        }
        else
            acf_error(acf_yylineno, NIDL_ERRINATTR, NULL);
    }
    break;


    }

/* Line 1000 of yacc.c.  */
#line 2248 "acf_y.c"

  yyvsp -= yylen;
  yyssp -= yylen;


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
#if YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (YYPACT_NINF < yyn && yyn < YYLAST)
	{
	  YYSIZE_T yysize = 0;
	  int yytype = YYTRANSLATE (yychar);
	  const char* yyprefix;
	  char *yymsg;
	  int yyx;

	  /* Start YYX at -YYN if negative to avoid negative indexes in
	     YYCHECK.  */
	  int yyxbegin = yyn < 0 ? -yyn : 0;

	  /* Stay within bounds of both yycheck and yytname.  */
	  int yychecklim = YYLAST - yyn;
	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
	  int yycount = 0;

	  yyprefix = ", expecting ";
	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	      {
		yysize += yystrlen (yyprefix) + yystrlen (yytname [yyx]);
		yycount += 1;
		if (yycount == 5)
		  {
		    yysize = 0;
		    break;
		  }
	      }
	  yysize += (sizeof ("syntax error, unexpected ")
		     + yystrlen (yytname[yytype]));
	  yymsg = (char *) YYSTACK_ALLOC (yysize);
	  if (yymsg != 0)
	    {
	      char *yyp = yystpcpy (yymsg, "syntax error, unexpected ");
	      yyp = yystpcpy (yyp, yytname[yytype]);

	      if (yycount < 5)
		{
		  yyprefix = ", expecting ";
		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
		      {
			yyp = yystpcpy (yyp, yyprefix);
			yyp = yystpcpy (yyp, yytname[yyx]);
			yyprefix = " or ";
		      }
		}
	      yyerror (yymsg);
	      YYSTACK_FREE (yymsg);
	    }
	  else
	    yyerror ("syntax error; also virtual memory exhausted");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror ("syntax error");
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* If at end of input, pop the error token,
	     then the rest of the stack, then return failure.  */
	  if (yychar == YYEOF)
	     for (;;)
	       {
		 YYPOPSTACK;
		 if (yyssp == yyss)
		   YYABORT;
		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
		 yydestruct (yystos[*yyssp], yyvsp);
	       }
        }
      else
	{
	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
	  yydestruct (yytoken, &yylval);
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

#ifdef __GNUC__
  /* Pacify GCC when the user code never invokes YYERROR and the label
     yyerrorlab therefore never appears in user code.  */
  if (0)
     goto yyerrorlab;
#endif

  yyvsp -= yylen;
  yyssp -= yylen;
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

      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
      yydestruct (yystos[yystate], yyvsp);
      YYPOPSTACK;
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  YYDPRINTF ((stderr, "Shifting error token, "));

  *++yyvsp = yylval;


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
/*----------------------------------------------.
| yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
yyoverflowlab:
  yyerror ("parser stack overflow");
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  return yyresult;
}


#line 1154 "acf_y.y"


/***************************
 *  yacc programs section  *
 ***************************/

/*
 *  a c f _ i n i t
 *
 *  Function:   Called before ACF parsing to initialize variables.
 *
 */

void acf_init
#ifdef PROTO
(
    boolean     *cmd_opt_arr,   /* [in] Array of command option flags */
    void        **cmd_val_arr,  /* [in] Array of command option values */
    char        *acf_file       /* [in] ACF file name */
)
#else
(cmd_opt_arr, cmd_val_arr, acf_file)
    boolean     *cmd_opt_arr;   /* [in] Array of command option flags */
    void        **cmd_val_arr;  /* [in] Array of command option values */
    char        *acf_file;      /* [in] ACF file name */
#endif

{
    /* Save passed command array and interface node addrs in static storage. */
    cmd_opt = cmd_opt_arr;
    cmd_val = cmd_val_arr;

    /* Set global (STRTAB_str_t error_file_name_id) for error processing. */
    set_name_for_errors(acf_file);

    interface_attr.mask = 0;
    type_attr.mask      = 0;
    operation_attr.mask = 0;
    parameter_attr.mask = 0;

    interface_name      = NULL;
    type_name           = NULL;
    repr_type_name      = NULL;
    cs_char_type_name   = NULL;
    operation_name      = NULL;
    binding_callout_name= NULL;
    cs_tag_rtn_name     = NULL;

    include_list        = NULL;

    parameter_list      = NULL;
    parameter_free_list = NULL;
}

/*
 *  a c f _ c l e a n u p
 *
 *  Function:   Called after ACF parsing to free allocated memory.
 *
 */

#ifdef PROTO
void acf_cleanup(void)
#else
void acf_cleanup()
#endif

{
    acf_param_t *p, *q;     /* Ptrs to parameter record */

    p = parameter_free_list;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        FREE(q);
    }
}




/*
**  l o o k u p _ e x c e p t i o n
**
**  Looks up a name in the nametable, and if it is bound to a valid exception
**  node, returns the address of the exception node.
**
**  Returns:    TRUE if lookup succeeds, FALSE otherwise.
*/

static boolean lookup_exception
(
    NAMETABLE_id_t  excep_id,     /* [in] Nametable id of exception name */
    boolean         log_error,    /* [in] TRUE => log error if name not found */
    AST_exception_n_t **excep_ptr /*[out] Ptr to AST exception node */
)
{
    AST_exception_n_t *excep_p;     /* Ptr to node bound to looked up name */
    char const      *perm_excep_name;   /* Ptr to permanent copy */
    NAMETABLE_id_t  name_id __attribute__((__unused__));            /* Handle on permanent copy */

    if (excep_id != NAMETABLE_NIL_ID)
    {
        excep_p = (AST_exception_n_t *)NAMETABLE_lookup_binding(excep_id);

        if (excep_p != NULL && excep_p->fe_info->node_kind == fe_exception_n_k)
        {
            *excep_ptr = excep_p;
            return TRUE;
        }
    }

    if (log_error)
    {
        NAMETABLE_id_to_string(excep_id, &perm_excep_name);
        acf_error(NIDL_EXCNOTDEF, perm_excep_name);
    }

    *excep_ptr = NULL;
    return FALSE;
}

/*
**  l o o k u p _ t y p e
**
**  Looks up a name in the nametable, and if it is bound to a valid type
**  node, returns the address of the type node.
**
**  Returns:    TRUE if lookup succeeds, FALSE otherwise.
*/

static boolean lookup_type
(
    char const      *type_name, /* [in] Name to look up */
    boolean         log_error,  /* [in] TRUE => log error if name not found */
    NAMETABLE_id_t  *type_id,   /*[out] Nametable id of type name */
    AST_type_n_t    **type_ptr  /*[out] Ptr to AST type node */
)
{
    AST_type_n_t    *type_p;    /* Ptr to node bound to looked up name */
    char const      *perm_type_name;    /* Ptr to permanent copy */
    NAMETABLE_id_t  name_id;            /* Handle on permanent copy */

    *type_id = NAMETABLE_lookup_id(type_name);

    if (*type_id != NAMETABLE_NIL_ID)
    {
        type_p = (AST_type_n_t *)NAMETABLE_lookup_binding(*type_id);

        if (type_p != NULL && type_p->fe_info->node_kind == fe_type_n_k)
        {
            *type_ptr = type_p;
            return TRUE;
        }
    }

    if (log_error)
    {
        name_id = NAMETABLE_add_id(type_name);
        NAMETABLE_id_to_string(name_id, &perm_type_name);
        acf_error(NIDL_TYPNOTDEF, perm_type_name);
    }

    *type_ptr = NULL;
    return FALSE;
}

/*
**  l o o k u p _ o p e r a t i o n
**
**  Looks up a name in the nametable, and if it is bound to a valid operation
**  node, returns the address of the operation node.
**
**  Returns:    TRUE if lookup succeeds, FALSE otherwise.
*/

static boolean lookup_operation
(
    char const      *op_name,   /* [in] Name to look up */
    boolean         log_error,  /* [in] TRUE => log error if name not found */
    NAMETABLE_id_t  *op_id,     /*[out] Nametable id of operation name */
    AST_operation_n_t **op_ptr  /*[out] Ptr to AST operation node */
)
{
    AST_operation_n_t   *op_p;  /* Ptr to node bound to looked up name */
    char const      *perm_op_name;      /* Ptr to permanent copy */
    NAMETABLE_id_t  name_id;            /* Handle on permanent copy */

    *op_id = NAMETABLE_lookup_id(op_name);

    if (*op_id != NAMETABLE_NIL_ID)
    {
        op_p = (AST_operation_n_t *)NAMETABLE_lookup_binding(*op_id);

        if (op_p != NULL && op_p->fe_info->node_kind == fe_operation_n_k)
        {
            *op_ptr = op_p;
            return TRUE;
        }
    }

    if (log_error)
    {
        name_id = NAMETABLE_add_id(op_name);
        NAMETABLE_id_to_string(name_id, &perm_op_name);
        acf_error(NIDL_OPNOTDEF, perm_op_name);
    }

    *op_ptr = NULL;
    return FALSE;
}

/*
**  l o o k u p _ p a r a m e t e r
**
**  Searches an operation node's parameter list for the parameter name passed.
**  If found, returns the address of the parameter node.
**
**  Returns:    TRUE if lookup succeeds, FALSE otherwise.
*/

static boolean lookup_parameter
(
    AST_operation_n_t   *op_p,          /* [in] Ptr to AST operation node */
    char const          *param_name,    /* [in] Parameter name to look up */
    boolean             log_error,      /* [in] TRUE=> log error if not found */
    NAMETABLE_id_t      *param_id,      /*[out] Nametable id of param name */
    AST_parameter_n_t   **param_ptr     /*[out] Ptr to AST parameter node */
)
{
    AST_parameter_n_t   *param_p;       /* Ptr to operation parameter node */
    char const          *op_param_name; /* Name of an operation parameter */
    char const          *op_name;       /* Operation name */
    char const      *perm_param_name;   /* Ptr to permanent copy */
    NAMETABLE_id_t  name_id;            /* Handle on permanent copy */

    for (param_p = op_p->parameters ; param_p != NULL ; param_p = param_p->next)
    {
        NAMETABLE_id_to_string(param_p->name, &op_param_name);

        if (strcmp(param_name, op_param_name) == 0)
        {
            *param_id   = param_p->name;
            *param_ptr  = param_p;
            return TRUE;
        }
    }

    if (log_error)
    {
        char const *file_name;     /* Related file name */

        NAMETABLE_id_to_string(op_p->name, &op_name);
        name_id = NAMETABLE_add_id(param_name);
        NAMETABLE_id_to_string(name_id, &perm_param_name);

        STRTAB_str_to_string(op_p->fe_info->file, &file_name);

        acf_error(NIDL_PRMNOTDEF, perm_param_name, op_name);
        acf_error(NIDL_NAMEDECLAT, op_name, file_name,
                  op_p->fe_info->source_line);
    }

    return FALSE;
}

/*
**  l o o k u p _ r e p _ a s _ n a m e
**
**  Scans a list of type nodes that have represent_as types for a match with
**  the type name given by the parameter repr_name_id.  If so, returns the
**  address of the found type node and a pointer to the associated
**  represent_as type name.
**
**  Returns:    TRUE if lookup succeeds, FALSE otherwise.
*/

static boolean lookup_rep_as_name
(
    AST_type_p_n_t  *typep_p,           /* [in] Listhead of type ptr nodes */
    NAMETABLE_id_t  repr_name_id,       /* [in] represent_as name to look up */
    AST_type_n_t    **ret_type_p,       /*[out] Type node if found */
    char const      **ret_type_name     /*[out] Type name if found */
)
{
    AST_type_n_t    *type_p;            /* Ptr to a type node */

    for ( ; typep_p != NULL ; typep_p = typep_p->next )
    {
        type_p = typep_p->type;
        if (type_p->name == repr_name_id)
        {
            *ret_type_p = type_p;
            NAMETABLE_id_to_string(type_p->rep_as_type->type_name,
                                   ret_type_name);
            return TRUE;
        }
    }

    return FALSE;
}

/*
**  l o o k u p _ c s _ c h a r _ n a m e
**
**  Scans a list of type nodes that have cs_char types for a match with
**  the type name given by the parameter cs_char_name_id.  If so, returns the
**  address of the found type node and a pointer to the associated
**  cs_char type name.
**
**  Returns:    TRUE if lookup succeeds, FALSE otherwise.
*/

static boolean lookup_cs_char_name
(
    AST_type_p_n_t  *typep_p,           /* [in] Listhead of type ptr nodes */
    NAMETABLE_id_t  cs_char_name_id,    /* [in] cs_char name to look up */
    AST_type_n_t    **ret_type_p,       /*[out] Type node if found */
    char const      **ret_type_name     /*[out] Type name if found */
)
{
    AST_type_n_t    *type_p;            /* Ptr to a type node */

    for ( ; typep_p != NULL ; typep_p = typep_p->next )
    {
        type_p = typep_p->type;
        if (type_p->name == cs_char_name_id)
        {
            *ret_type_p = type_p;
            NAMETABLE_id_to_string(type_p->cs_char_type->type_name,
                                   ret_type_name);
            return TRUE;
        }
    }

    return FALSE;
}

/*
 *  a c f _ a l l o c _ p a r a m
 *
 *  Function:   Allocates an acf_param_t, either from the free list or heap.
 *
 *  Returns:    Address of acf_param_t
 *
 *  Globals:    parameter_free_list - listhead for free list
 *
 *  Side Effects:   Exits program if unable to allocate memory.
 */

#ifdef PROTO
static acf_param_t *alloc_param(void)
#else
static acf_param_t *alloc_param()
#endif

{
    acf_param_t *p;     /* Ptr to parameter record */

    if (parameter_free_list != NULL)
    {
        p = parameter_free_list;
        parameter_free_list = parameter_free_list->next;
    }
    else
    {
        p = NEW (acf_param_t);
        p->next                 = NULL;
        p->parameter_attr.mask  = 0;
        p->param_id             = NAMETABLE_NIL_ID;
    }

    return p;
}

/*
 *  a c f _ f r e e _ p a r a m
 *
 *  Function:   Frees an acf_param_t by reinitilizing it and returning it to
 *              the head of the free list.
 *
 *  Input:      p - Pointer to acf_param_t record
 *
 *  Globals:    parameter_free_list - listhead for free list
 */

static void free_param
#ifdef PROTO
(
    acf_param_t *p              /* [in] Pointer to acf_param_t record */
)
#else
(p)
    acf_param_t *p;             /* [in] Pointer to acf_param_t record */
#endif

{
    p->parameter_attr.mask  = 0;
    p->param_id             = NAMETABLE_NIL_ID;

    p->next                 = parameter_free_list;
    parameter_free_list     = p;
}


/*
 *  a c f _ f r e e _ p a r a m _ l i s t
 *
 *  Function:   Frees a list of acf_param_t records.
 *
 *  Input:      list - Address of list pointer
 *
 *  Output:     list pointer = NULL
 */

static void free_param_list
#ifdef PROTO
(
    acf_param_t **list          /* [in] Address of list pointer */
)
#else
(list)
    acf_param_t **list;         /* [in] Address of list pointer */
#endif

{
    acf_param_t *p, *q;     /* Ptrs to parameter record */

    p = *list;

    while (p != NULL)
    {
        q = p;
        p = p->next;
        free_param(q);
    }

    *list = NULL;            /* List now empty */
}

/*
 *  a d d _ p a r a m _ t o _ l i s t
 *
 *  Function:   Add a acf_param_t record to the end of a list.
 *
 *  Inputs:     p - Pointer to parameter record
 *              list - Address of list pointer
 *
 *  Outputs:    List is modified.
 */

void add_param_to_list
#ifdef PROTO
(
    acf_param_t *p,             /* [in] Pointer to parameter record */
    acf_param_t **list          /* [in] Address of list pointer */
)
#else
(p, list)
    acf_param_t *p;             /* [in] Pointer to parameter record */
    acf_param_t **list;         /* [in] Address of list pointer */
#endif

{
    acf_param_t *q;         /* Ptr to parameter record */

    if (*list == NULL)      /* If list empty */
        *list = p;          /* then list now points at param */
    else
    {
        for (q = *list ; q->next != NULL ; q = q->next)
            ;
        q->next = p;        /* else last record in list now points at param */
    }

    p->next = NULL;         /* Param is now last in list */
}

/*
**  a p p e n d _ p a r a m e t e r
**
**  Appends a parameter to an operation's parameter list.
*/

static void append_parameter
(
    AST_operation_n_t   *op_p,          /* [in] Ptr to AST operation node */
    char const          *param_name,    /* [in] Parameter name */
    acf_attrib_t        *param_attr     /* [in] Parameter attributes */
)
{
    NAMETABLE_id_t      new_param_id;   /* Nametable id of new parameter name */
    AST_parameter_n_t   *new_param_p;   /* Ptr to new parameter node */
    AST_type_n_t        *new_type_p;    /* Ptr to new parameter type node */
    AST_pointer_n_t     *new_ptr_p;     /* Ptr to new pointer node */
    NAMETABLE_id_t      status_id;      /* Nametable id of status_t */
    AST_type_n_t        *status_type_p; /* Type node bound to status_t name */
    AST_parameter_n_t   *param_p;       /* Ptr to operation parameter node */

    /* Look up error_status_t type. */
    status_id = NAMETABLE_add_id("error_status_t");
    status_type_p = (AST_type_n_t *)NAMETABLE_lookup_binding(status_id);
    if (status_type_p == NULL)
    {
        acf_error(NIDL_ERRSTATDEF, "error_status_t", "nbase.idl");
        return;
    }

    /*
     * Have to create an '[out] error_status_t *param_name' parameter
     * that has the specified parameter attributes.
     */
    new_param_id = NAMETABLE_add_id(param_name);
    new_param_p = AST_parameter_node(new_param_id);
    new_type_p  = AST_type_node(AST_pointer_k);
    new_ptr_p   = AST_pointer_node(status_type_p);

    new_type_p->type_structure.pointer = new_ptr_p;
    AST_SET_REF(new_type_p);

    new_param_p->name = new_param_id;
    new_param_p->type = new_type_p;
    new_param_p->uplink = op_p;
    if (param_attr->bit.comm_status)
        AST_SET_ADD_COMM_STATUS(new_param_p);
    if (param_attr->bit.fault_status)
        AST_SET_ADD_FAULT_STATUS(new_param_p);
    AST_SET_OUT(new_param_p);
    AST_SET_REF(new_param_p);

    param_p = op_p->parameters;
    if (param_p == NULL)
    {
        /* Was null param list, now has one param. */
        op_p->parameters = new_param_p;
    }
    else if (param_p->last == NULL)
    {
        /* Was one param, now have two params. */
        param_p->next = new_param_p;
        param_p->last = new_param_p;
    }
    else
    {
        /* Was more than one param, now have one more. */
        param_p->last->next = new_param_p;
        param_p->last = new_param_p;
    }
}

/*
**  p r o c e s s _ r e p _ a s _ t y p e
**
**  Processes a [represent_as] clause applied to a type.  Validates that
**  [represent_as] types are not nested.  Adds the type to a list of types
**  that have the [represent_as] attribute.
*/

static void process_rep_as_type
(
    AST_interface_n_t   *int_p,     /* [in] Ptr to AST interface node */
    AST_type_n_t        *type_p,    /* [in] Ptr to AST type node */
    char const      *ref_type_name  /* [in] Name in represent_as() clause */
)
{
    NAMETABLE_id_t  ref_type_id;    /* Nametable id of referenced name */
    char const      *file_name;     /* Related file name */
    char const      *perm_name;     /* Permanent copy of referenced name */
    AST_type_n_t    *parent_type_p; /* Parent type with same attribute */
    char const      *parent_name;   /* Name of parent type */

    ref_type_id = NAMETABLE_add_id(ref_type_name);

    /*
     * Report error if the type name referenced in the attribute is an AST
     * type which also has the same attribute, i.e. types with this attribute
     * cannot nest.
     */
    if (lookup_rep_as_name(int_p->ra_types, ref_type_id, &parent_type_p,
                           &perm_name))
    {
        NAMETABLE_id_to_string(parent_type_p->name, &parent_name);
        STRTAB_str_to_string(parent_type_p->fe_info->acf_file, &file_name);

        acf_error(NIDL_REPASNEST);
        acf_error(NIDL_TYPEREPAS, parent_name, perm_name);
        acf_error(NIDL_NAMEDECLAT, parent_name, file_name,
                  parent_type_p->fe_info->acf_source_line);
    }

    /*
     * If the type node already has a type name for this attribute,
     * this one must duplicate that same name.
     */
    if (type_p->rep_as_type != NULL)
    {
        NAMETABLE_id_to_string(type_p->rep_as_type->type_name, &perm_name);

        if (strcmp(perm_name, ref_type_name) != 0)
        {
            char const *new_ref_type_name; /* Ptr to permanent copy */
            NAMETABLE_id_t  name_id;       /* Handle on perm copy */

            name_id = NAMETABLE_add_id(ref_type_name);
            NAMETABLE_id_to_string(name_id, &new_ref_type_name);

            STRTAB_str_to_string(
                            type_p->rep_as_type->fe_info->acf_file, &file_name);

            acf_error(NIDL_CONFREPRTYPE, new_ref_type_name, perm_name);
            acf_error(NIDL_NAMEDECLAT, perm_name, file_name,
                      type_p->rep_as_type->fe_info->acf_source_line);
        }
    }
    else
    {
        /*
         * Process valid [represent_as] clause.
         */
        AST_type_p_n_t  *typep_p;       /* Used to link type nodes */
        AST_rep_as_n_t  *repas_p;       /* Ptr to represent_as node */

        /* Add represent_as type name and build rep_as AST node. */

        repas_p = type_p->rep_as_type = AST_represent_as_node(ref_type_id);
        /* Store source information. */
        if (repas_p->fe_info != NULL)
        {
            repas_p->fe_info->acf_file = error_file_name_id;
            repas_p->fe_info->acf_source_line = acf_yylineno;
        }

        /* Check for associated def-as-tag node. */

        if (type_p->fe_info->tag_ptr != NULL)
            type_p->fe_info->tag_ptr->rep_as_type = type_p->rep_as_type;

        /* Link type node into list of represent_as types. */

        typep_p = AST_type_ptr_node();
        typep_p->type = type_p;

        int_p->ra_types = (AST_type_p_n_t *)AST_concat_element(
                                                (ASTP_node_t *)int_p->ra_types,
                                                (ASTP_node_t *)typep_p);
    }
}

/*
**  p r o c e s s _ c s _ c h a r _ t y p e
**
**  Processes a [cs_char] clause applied to a type.  Validates that
**  [cs_char] types are not nested.  Adds the type to a list of types
**  that have the [cs_char] attribute.
*/

static void process_cs_char_type
(
    AST_interface_n_t   *int_p,     /* [in] Ptr to AST interface node */
    AST_type_n_t        *type_p,    /* [in] Ptr to AST type node */
    char const      *ref_type_name  /* [in] Name in cs_char() clause */
)
{
    NAMETABLE_id_t  ref_type_id;    /* Nametable id of referenced name */
    char const      *file_name;     /* Related file name */
    char const      *perm_name;     /* Permanent copy of referenced name */
    AST_type_n_t    *parent_type_p; /* Parent type with same attribute */
    char const      *parent_name;   /* Name of parent type */

    ref_type_id = NAMETABLE_add_id(ref_type_name);

    /*
     * Report error if the type name referenced in the attribute is an AST
     * type which also has the same attribute, i.e. types with this attribute
     * cannot nest.
     */
    if (lookup_cs_char_name(int_p->cs_types, ref_type_id, &parent_type_p,
                            &perm_name))
    {
        NAMETABLE_id_to_string(parent_type_p->name, &parent_name);
        STRTAB_str_to_string(parent_type_p->fe_info->acf_file, &file_name);

        /*** This needs updating ***/
        acf_error(NIDL_REPASNEST);
        acf_error(NIDL_TYPEREPAS, parent_name, perm_name);
        acf_error(NIDL_NAMEDECLAT, parent_name, file_name,
                  parent_type_p->fe_info->acf_source_line);
    }

    /*
     * If the type node already has a type name for this attribute,
     * this one must duplicate that same name.
     */
    if (type_p->cs_char_type != NULL)
    {
        NAMETABLE_id_to_string(type_p->cs_char_type->type_name, &perm_name);

        if (strcmp(perm_name, ref_type_name) != 0)
        {
            char const *new_ref_type_name; /* Ptr to permanent copy */
            NAMETABLE_id_t  name_id;    /* Handle on perm copy */

            name_id = NAMETABLE_add_id(ref_type_name);
            NAMETABLE_id_to_string(name_id, &new_ref_type_name);

            STRTAB_str_to_string(
                        type_p->cs_char_type->fe_info->acf_file, &file_name);

            /*** This needs updating ***/
            acf_error(NIDL_CONFREPRTYPE, new_ref_type_name, perm_name);
            acf_error(NIDL_NAMEDECLAT, perm_name, file_name,
                      type_p->cs_char_type->fe_info->acf_source_line);
        }
    }
    else
    {
        /*
         * Process valid [cs_char] clause.
         */
        AST_type_p_n_t  *typep_p;       /* Used to link type nodes */
        AST_cs_char_n_t *cschar_p;      /* Ptr to cs_char node */

        /* Add cs_char type name and build cs_char AST node. */

        cschar_p = type_p->cs_char_type = AST_cs_char_node(ref_type_id);
        /* Store source information. */
        if (cschar_p->fe_info != NULL)
        {
            cschar_p->fe_info->acf_file = error_file_name_id;
            cschar_p->fe_info->acf_source_line = acf_yylineno;
        }

        /* Check for associated def-as-tag node. */

        if (type_p->fe_info->tag_ptr != NULL)
            type_p->fe_info->tag_ptr->cs_char_type = type_p->cs_char_type;

        /* Link type node into list of cs_char types. */

        typep_p = AST_type_ptr_node();
        typep_p->type = type_p;

        int_p->cs_types = (AST_type_p_n_t *)AST_concat_element(
                                                (ASTP_node_t *)int_p->cs_types,
                                                (ASTP_node_t *)typep_p);
    }
}

#ifdef DUMPERS
/*
 *  d u m p _ a t t r i b u t e s
 *
 *  Function:   Prints list of attributes parsed for a particular node type
 *
 *  Inputs:     header_text - Initial text before node name and attributes
 *              node_name   - Name of interface, type, operation, or parameter
 *              node_attr_p - Address of node attributes structure
 *
 *  Globals:    repr_type_name  - represent_as type name, used if bit is set
 *              cs_char_type_name - cs_char type name, used if bit is set
 *              cs_tag_rtn_name - cs_tag_rtn name, used if bit is set
 *              binding_callout_name - binding_callout name, used if bit is set
 */

static void dump_attributes
#ifdef PROTO
(
    char            *header_text,       /* [in] Initial output text */
    char const            *node_name,         /* [in] Name of tree node */
    acf_attrib_t    *node_attr_p        /* [in] Node attributes ptr */
)
#else
(header_text, node_name, node_attr_p)
    char            *header_text;       /* [in] Initial output text */
    char            *node_name;         /* [in] Name of tree node */
    acf_attrib_t    *node_attr_p;       /* [in] Node attributes ptr */
#endif

#define MAX_ATTR_TEXT   1024    /* Big enough for lots of extern_exceptions */

{
    char            attr_text[MAX_ATTR_TEXT];   /* Buf for formatting attrs */
    int             pos;                /* Position in buffer */
    acf_attrib_t    node_attr;          /* Node attributes */

    node_attr = *node_attr_p;

    printf("%s %s", header_text, node_name);

    if (node_attr.mask == 0)
        printf("\n");
    else
    {
        printf(" attributes: ");
        strcpy(attr_text, "[");

        if (node_attr.bit.auto_handle)
            strcat(attr_text, "auto_handle, ");
        if (node_attr.bit.code)
            strcat(attr_text, "code, ");
        if (node_attr.bit.nocode)
            strcat(attr_text, "nocode, ");
        if (node_attr.bit.comm_status)
            strcat(attr_text, "comm_status, ");
        if (node_attr.bit.decode)
            strcat(attr_text, "decode, ");
        if (node_attr.bit.enable_allocate)
            strcat(attr_text, "enable_allocate, ");
        if (node_attr.bit.encode)
            strcat(attr_text, "encode, ");
        if (node_attr.bit.explicit_handle)
            strcat(attr_text, "explicit_handle, ");
        if (node_attr.bit.extern_exceps && ASTP_parsing_main_idl)
        {
            AST_exception_n_t   *excep_p;
            char const               *name;
            strcat(attr_text, "extern_exceptions(");
            for (excep_p = the_interface->exceptions;
                 excep_p != NULL;
                 excep_p = excep_p->next)
            {
                if (AST_EXTERN_SET(excep_p))
                {
                    NAMETABLE_id_to_string(excep_p->name, &name);
                    strcat(attr_text, name);
                    strcat(attr_text, ",");
                }
            }
            attr_text[strlen(attr_text)-1] = '\0';  /* overwrite trailing ',' */
            strcat(attr_text, "), ");
        }
        if (node_attr.bit.fault_status)
            strcat(attr_text, "fault_status, ");
        if (node_attr.bit.heap)
            strcat(attr_text, "heap, ");
        if (node_attr.bit.implicit_handle)
            strcat(attr_text, "implicit_handle, ");
        if (node_attr.bit.in_line)
            strcat(attr_text, "in_line, ");
        if (node_attr.bit.out_of_line)
            strcat(attr_text, "out_of_line, ");
        if (node_attr.bit.cs_stag)
            strcat(attr_text, "cs_stag, ");
        if (node_attr.bit.cs_drtag)
            strcat(attr_text, "cs_drtag, ");
        if (node_attr.bit.cs_rtag)
            strcat(attr_text, "cs_rtag, ");
        if (node_attr.bit.represent_as)
        {
            strcat(attr_text, "represent_as(");
            strcat(attr_text, repr_type_name);
            strcat(attr_text, "), ");
        }
        if (node_attr.bit.cs_char)
        {
            strcat(attr_text, "cs_char(");
            strcat(attr_text, cs_char_type_name);
            strcat(attr_text, "), ");
        }
        if (node_attr.bit.cs_tag_rtn)
        {
            strcat(attr_text, "cs_tag_rtn(");
            strcat(attr_text, cs_tag_rtn_name);
            strcat(attr_text, "), ");
        }
        if (node_attr.bit.binding_callout)
        {
            strcat(attr_text, "binding_callout(");
            strcat(attr_text, binding_callout_name);
            strcat(attr_text, "), ");
        }


        /* Overwrite trailing ", " with "]" */

        pos = strlen(attr_text) - strlen(", ");
        attr_text[pos] = ']';
        attr_text[pos+1] = '\0';

        printf("%s\n", attr_text);
    }
}
#endif

/*****************************************************************
 *
 *  Helper functions for managing multiple BISON parser contexts
 *
 *  GNU Bison v1.25 support for DCE 1.2.2 idl_compiler
 *  added 07-11-97 Jim Doyle, Boston University, <jrd@bu.edu>
 *
 *  Maintainance note:
 *
 *    The set of bison-specific static and global variables
 *    managed by the following code may need to changed for versions
 *    GNU Bison earlier or newer than V1.25.
 *
 *
 *****************************************************************/
 
/*****************************************************************
 *
 * Data structure to store the state of a BISON lexxer context
 *
 *****************************************************************/

struct acf_bisonparser_state 
  {

    /*
     * BISON parser globals that need to preserved whenever
     * we switch into a new parser context (i.e. multiple,
     * nested parsers).
     */

    int yychar;
    int yynerrs;
    YYSTYPE yylval;

  };


typedef struct acf_bisonparser_state acf_bisonparser_activation_record;
 
/*****************************************************************
 *
 * Basic constructors/destructors for FLEX activation states
 *
 *****************************************************************/
 
void *
new_acf_bisonparser_activation_record()
  {
    return (malloc(sizeof(acf_bisonparser_activation_record)));
  }
 
void
delete_acf_bisonparser_activation_record(void * p)
{
 if (p)
    free((void *)p);
}

/*****************************************************************
 *
 * Get/Set/Initialize methods
 *
 *****************************************************************/

void *
get_current_acf_bisonparser_activation()
  {
    acf_bisonparser_activation_record * p;

    p = (acf_bisonparser_activation_record * )
                new_acf_bisonparser_activation_record();

    /*
     * save the statics internal to the parser
     *
     */

     p->yychar = yychar;
     p->yynerrs = yynerrs;
     p->yylval = yylval;

     return (void *)p;
  }

void
set_current_acf_bisonparser_activation(void * ptr)
  {

    acf_bisonparser_activation_record * p =
      (acf_bisonparser_activation_record *)ptr;

    /* restore the statics */


     yychar = p->yychar;
     yynerrs = p->yynerrs;
     yylval = p->yylval;


  }

void
init_new_acf_bisonparser_activation()
  {
    /* set some initial conditions for a new Bison parser state */

    yynerrs = 0;

  }

/* preserve coding style vim: set tw=78 sw=4 : */

