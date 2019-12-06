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
#define yyparse nidl_yyparse
#define yylex   nidl_yylex
#define yyerror nidl_yyerror
#define yylval  nidl_yylval
#define yychar  nidl_yychar
#define yydebug nidl_yydebug
#define yynerrs nidl_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ALIGN_KW = 258,
     BYTE_KW = 259,
     CHAR_KW = 260,
     CONST_KW = 261,
     DEFAULT_KW = 262,
     ENUM_KW = 263,
     EXCEPTIONS_KW = 264,
     FLOAT_KW = 265,
     HYPER_KW = 266,
     INT_KW = 267,
     INTERFACE_KW = 268,
     IMPORT_KW = 269,
     LIBRARY_KW = 270,
     LONG_KW = 271,
     PIPE_KW = 272,
     REF_KW = 273,
     SMALL_KW = 274,
     STRUCT_KW = 275,
     TYPEDEF_KW = 276,
     UNION_KW = 277,
     UNSIGNED_KW = 278,
     SHORT_KW = 279,
     VOID_KW = 280,
     DOUBLE_KW = 281,
     BOOLEAN_KW = 282,
     CASE_KW = 283,
     SWITCH_KW = 284,
     HANDLE_T_KW = 285,
     TRUE_KW = 286,
     FALSE_KW = 287,
     NULL_KW = 288,
     BROADCAST_KW = 289,
     COMM_STATUS_KW = 290,
     CONTEXT_HANDLE_KW = 291,
     FIRST_IS_KW = 292,
     HANDLE_KW = 293,
     IDEMPOTENT_KW = 294,
     IGNORE_KW = 295,
     CALL_AS_KW = 296,
     IID_IS_KW = 297,
     IMPLICIT_HANDLE_KW = 298,
     IN_KW = 299,
     LAST_IS_KW = 300,
     LENGTH_IS_KW = 301,
     LOCAL_KW = 302,
     MAX_IS_KW = 303,
     MAYBE_KW = 304,
     MIN_IS_KW = 305,
     MUTABLE_KW = 306,
     OUT_KW = 307,
     OBJECT_KW = 308,
     POINTER_DEFAULT_KW = 309,
     ENDPOINT_KW = 310,
     PTR_KW = 311,
     REFLECT_DELETIONS_KW = 312,
     REMOTE_KW = 313,
     SECURE_KW = 314,
     SHAPE_KW = 315,
     SIZE_IS_KW = 316,
     STRING_KW = 317,
     SWITCH_IS_KW = 318,
     SWITCH_TYPE_KW = 319,
     TRANSMIT_AS_KW = 320,
     UNIQUE_KW = 321,
     UUID_KW = 322,
     VERSION_KW = 323,
     V1_ARRAY_KW = 324,
     V1_STRING_KW = 325,
     V1_ENUM_KW = 326,
     V1_STRUCT_KW = 327,
     UUID_REP = 328,
     COLON = 329,
     COMMA = 330,
     DOTDOT = 331,
     EQUAL = 332,
     LBRACE = 333,
     LBRACKET = 334,
     LPAREN = 335,
     RBRACE = 336,
     RBRACKET = 337,
     RPAREN = 338,
     SEMI = 339,
     STAR = 340,
     QUESTION = 341,
     BAR = 342,
     BARBAR = 343,
     LANGLE = 344,
     LANGLEANGLE = 345,
     RANGLE = 346,
     RANGLEANGLE = 347,
     AMP = 348,
     AMPAMP = 349,
     LESSEQUAL = 350,
     GREATEREQUAL = 351,
     EQUALEQUAL = 352,
     CARET = 353,
     PLUS = 354,
     MINUS = 355,
     NOT = 356,
     NOTEQUAL = 357,
     SLASH = 358,
     PERCENT = 359,
     TILDE = 360,
     POUND = 361,
     UNKNOWN = 362,
     IDENTIFIER = 363,
     STRING = 364,
     INTEGER_NUMERIC = 365,
     CHAR = 366,
     FLOAT_NUMERIC = 367
   };
#endif
#define ALIGN_KW 258
#define BYTE_KW 259
#define CHAR_KW 260
#define CONST_KW 261
#define DEFAULT_KW 262
#define ENUM_KW 263
#define EXCEPTIONS_KW 264
#define FLOAT_KW 265
#define HYPER_KW 266
#define INT_KW 267
#define INTERFACE_KW 268
#define IMPORT_KW 269
#define LIBRARY_KW 270
#define LONG_KW 271
#define PIPE_KW 272
#define REF_KW 273
#define SMALL_KW 274
#define STRUCT_KW 275
#define TYPEDEF_KW 276
#define UNION_KW 277
#define UNSIGNED_KW 278
#define SHORT_KW 279
#define VOID_KW 280
#define DOUBLE_KW 281
#define BOOLEAN_KW 282
#define CASE_KW 283
#define SWITCH_KW 284
#define HANDLE_T_KW 285
#define TRUE_KW 286
#define FALSE_KW 287
#define NULL_KW 288
#define BROADCAST_KW 289
#define COMM_STATUS_KW 290
#define CONTEXT_HANDLE_KW 291
#define FIRST_IS_KW 292
#define HANDLE_KW 293
#define IDEMPOTENT_KW 294
#define IGNORE_KW 295
#define CALL_AS_KW 296
#define IID_IS_KW 297
#define IMPLICIT_HANDLE_KW 298
#define IN_KW 299
#define LAST_IS_KW 300
#define LENGTH_IS_KW 301
#define LOCAL_KW 302
#define MAX_IS_KW 303
#define MAYBE_KW 304
#define MIN_IS_KW 305
#define MUTABLE_KW 306
#define OUT_KW 307
#define OBJECT_KW 308
#define POINTER_DEFAULT_KW 309
#define ENDPOINT_KW 310
#define PTR_KW 311
#define REFLECT_DELETIONS_KW 312
#define REMOTE_KW 313
#define SECURE_KW 314
#define SHAPE_KW 315
#define SIZE_IS_KW 316
#define STRING_KW 317
#define SWITCH_IS_KW 318
#define SWITCH_TYPE_KW 319
#define TRANSMIT_AS_KW 320
#define UNIQUE_KW 321
#define UUID_KW 322
#define VERSION_KW 323
#define V1_ARRAY_KW 324
#define V1_STRING_KW 325
#define V1_ENUM_KW 326
#define V1_STRUCT_KW 327
#define UUID_REP 328
#define COLON 329
#define COMMA 330
#define DOTDOT 331
#define EQUAL 332
#define LBRACE 333
#define LBRACKET 334
#define LPAREN 335
#define RBRACE 336
#define RBRACKET 337
#define RPAREN 338
#define SEMI 339
#define STAR 340
#define QUESTION 341
#define BAR 342
#define BARBAR 343
#define LANGLE 344
#define LANGLEANGLE 345
#define RANGLE 346
#define RANGLEANGLE 347
#define AMP 348
#define AMPAMP 349
#define LESSEQUAL 350
#define GREATEREQUAL 351
#define EQUALEQUAL 352
#define CARET 353
#define PLUS 354
#define MINUS 355
#define NOT 356
#define NOTEQUAL 357
#define SLASH 358
#define PERCENT 359
#define TILDE 360
#define POUND 361
#define UNKNOWN 362
#define IDENTIFIER 363
#define STRING 364
#define INTEGER_NUMERIC 365
#define CHAR 366
#define FLOAT_NUMERIC 367




/* Copy the first part of user declarations.  */
#line 1 "nidl_y.y"

/*
 *
 *  (c) Copyright 1989 OPEN SOFTWARE FOUNDATION, INC.
 *  (c) Copyright 1989 HEWLETT-PACKARD COMPANY
 *  (c) Copyright 1989 DIGITAL EQUIPMENT CORPORATION
 *  To anyone who acknowledges that this file is provided "AS IS"
 *  without any express or implied warranty:
 *                  permission to use, copy, modify, and distribute this
 *  file for any purpose is hereby granted without fee, provided that
 *  the above copyright notices and this notice appears in all source
 *  code copies, and that none of the names of Open Software
 *  Foundation, Inc., Hewlett-Packard Company, or Digital Equipment
 *  Corporation be used in advertising or publicity pertaining to
 *  distribution of the software without specific, written prior
 *  permission.  Neither Open Software Foundation, Inc., Hewlett-
 *  Packard Company, nor Digital Equipment Corporation makes any
 *  representations about the suitability of this software for any
 *  purpose.
 *
 */
/*
**
**  NAME:
**
**      IDL.Y
**
**  FACILITY:
**
**      Interface Definition Language (IDL) Compiler
**
**  ABSTRACT:
**
**      This module defines the main IDL grammar accepted
**      by the IDL compiler.
**
**  VERSION: DCE 1.0
**
*/

#ifdef vms
#  include <types.h>
#else
#  include <sys/types.h>
#endif

#include <nidl.h>
#include <nametbl.h>
#include <errors.h>
#include <ast.h>
#include <astp.h>
#include <frontend.h>
#include <flex_bison_support.h>

extern int nidl_yylineno;
extern boolean search_attributes_table ;

int yyparse(void);
int yylex(void);

/*
**  Local cells used for inter-production communication
*/
static ASTP_attr_k_t       ASTP_bound_type;    /* Array bound attribute */



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
#line 71 "nidl_y.y"
typedef union YYSTYPE {
	 NAMETABLE_id_t         y_id ;          /* Identifier           */
	 long                   y_ptrlevels;	 /* levels of * for pointers */
	 long							y_ptrclass;		 /* class of pointer */
	 STRTAB_str_t           y_string ;      /* String               */
	 STRTAB_str_t           y_float ;       /* Float constant       */
	 AST_export_n_t*        y_export ;      /* an export node       */
	 AST_import_n_t*        y_import ;      /* Import node          */
	 AST_exception_n_t*     y_exception ;   /* Exception node       */
	 AST_constant_n_t*      y_constant;     /* Constant node        */
	 AST_parameter_n_t*     y_parameter ;   /* Parameter node       */
	 AST_type_n_t*          y_type ;        /* Type node            */
	 AST_type_p_n_t*        y_type_ptr ;    /* Type pointer node    */
	 AST_field_n_t*         y_field ;       /* Field node           */
	 AST_arm_n_t*           y_arm ;         /* Union variant arm    */
	 AST_operation_n_t*     y_operation ;   /* Routine node         */
	 AST_interface_n_t*     y_interface ;   /* Interface node       */
	 AST_case_label_n_t*    y_label ;       /* Union tags           */
	 ASTP_declarator_n_t*   y_declarator ;  /* Declarator info      */
	 ASTP_array_index_n_t*  y_index ;       /* Array index info     */
	 nidl_uuid_t            y_uuid ;        /* Universal UID        */
	 char                   y_char;         /* character constant   */
	 ASTP_attributes_t      y_attributes;   /* attributes flags     */
	 struct {
		  long            int_val ;        /* Integer constant     */
		  AST_type_k_t    int_size;
		  int             int_signed;
	 }                  y_int_info;     /* int size and signedness */
	 AST_exp_n_t           * y_exp;          /* constant expression info */
} YYSTYPE;
/* Line 191 of yacc.c.  */
#line 407 "nidl_y.c"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */
#line 102 "nidl_y.y"

#if YYDEBUG
#ifdef GCC_VERSION
#define FREEDCE_UNUSED __attribute__((unused))
#else
#define FREEDCE_UNUSED 
#endif
extern char const *current_file;
static void yyprint(FILE * stream, 
                    int token FREEDCE_UNUSED, 
		    YYSTYPE lval FREEDCE_UNUSED) {
	fprintf(stream, " %s:%d", current_file, *yylineno_p);
}
#define YYPRINT yyprint
#endif




/* Line 214 of yacc.c.  */
#line 437 "nidl_y.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   653

/* YYNTOKENS -- Number of terminals. */
#define YYNTOKENS  113
/* YYNNTS -- Number of nonterminals. */
#define YYNNTS  114
/* YYNRULES -- Number of rules. */
#define YYNRULES  281
/* YYNRULES -- Number of states. */
#define YYNSTATES  466

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   367

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const unsigned short yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    17,    21,    22,
      25,    26,    30,    32,    35,    39,    41,    42,    44,    47,
      50,    54,    58,    60,    64,    66,    68,    72,    75,    78,
      81,    84,    90,    92,    95,   100,   102,   104,   106,   108,
     110,   112,   114,   116,   118,   120,   122,   124,   126,   128,
     130,   132,   134,   135,   137,   138,   140,   142,   143,   145,
     147,   149,   151,   153,   156,   159,   161,   164,   167,   170,
     172,   174,   176,   178,   180,   182,   185,   193,   197,   206,
     215,   225,   228,   232,   236,   238,   242,   244,   248,   250,
     253,   255,   259,   261,   264,   266,   270,   273,   277,   283,
     285,   290,   295,   301,   304,   306,   310,   316,   320,   322,
     323,   328,   330,   334,   337,   340,   341,   344,   346,   350,
     352,   354,   357,   359,   362,   364,   367,   371,   374,   377,
     381,   385,   391,   397,   403,   409,   414,   417,   422,   424,
     426,   428,   432,   433,   438,   442,   444,   445,   447,   449,
     451,   453,   455,   460,   464,   465,   467,   471,   472,   475,
     478,   484,   490,   495,   497,   502,   504,   506,   512,   518,
     520,   522,   524,   526,   528,   530,   534,   536,   540,   542,
     544,   549,   554,   556,   558,   560,   562,   564,   566,   568,
     572,   574,   575,   577,   579,   582,   585,   586,   590,   593,
     596,   598,   602,   604,   606,   608,   610,   612,   614,   619,
     621,   623,   628,   630,   635,   640,   646,   648,   650,   652,
     654,   656,   658,   660,   662,   664,   669,   674,   679,   684,
     686,   691,   696,   701,   703,   705,   707,   709,   715,   717,
     721,   723,   727,   729,   733,   735,   739,   741,   745,   747,
     751,   755,   757,   761,   765,   769,   773,   775,   779,   783,
     785,   789,   793,   795,   799,   803,   807,   809,   811,   814,
     817,   820,   823,   826,   830,   832,   834,   836,   838,   840,
     842,   844
};

/* YYRHS -- A `-1'-separated list of the rules' RHS. */
static const short yyrhs[] =
{
     114,     0,    -1,   115,    -1,   122,    -1,   115,   116,    -1,
     116,    -1,   119,   117,   118,   120,    -1,   192,    13,   108,
      -1,    -1,    74,   108,    -1,    -1,    78,   121,    81,    -1,
       1,    -1,     1,    81,    -1,   122,   127,   139,    -1,   123,
      -1,    -1,   124,    -1,   123,   124,    -1,    14,     1,    -1,
      14,     1,    84,    -1,    14,   125,    84,    -1,   126,    -1,
     125,    75,   126,    -1,   109,    -1,   128,    -1,   127,   139,
     128,    -1,   131,    84,    -1,   129,    84,    -1,   180,    84,
      -1,     1,    84,    -1,     6,   133,   175,    77,   130,    -1,
     212,    -1,    21,   132,    -1,   208,   133,   174,   138,    -1,
     134,    -1,   135,    -1,   137,    -1,   143,    -1,   144,    -1,
     145,    -1,   146,    -1,   147,    -1,   136,    -1,   148,    -1,
     164,    -1,   151,    -1,   167,    -1,   172,    -1,   108,    -1,
      10,    -1,    26,    -1,    -1,    75,    -1,    -1,    84,    -1,
      23,    -1,    -1,    19,    -1,    24,    -1,    16,    -1,    11,
      -1,   141,    -1,    23,   141,    -1,   141,    23,    -1,   142,
      -1,   142,    12,    -1,   140,    12,    -1,   140,     5,    -1,
      27,    -1,     4,    -1,    25,    -1,    30,    -1,    78,    -1,
      81,    -1,    22,   152,    -1,    22,    29,    80,   134,   108,
      83,   153,    -1,    22,   108,   152,    -1,    22,    29,    80,
     134,   108,    83,   108,   153,    -1,    22,   108,    29,    80,
     134,   108,    83,   153,    -1,    22,   108,    29,    80,   134,
     108,    83,   108,   153,    -1,    22,   108,    -1,   149,   154,
     150,    -1,   149,   155,   150,    -1,   156,    -1,   154,   139,
     156,    -1,   157,    -1,   155,   139,   157,    -1,   162,    -1,
     159,   163,    -1,   160,    -1,   158,    75,   160,    -1,   161,
      -1,   159,   161,    -1,   130,    -1,    28,   130,    74,    -1,
       7,    74,    -1,   187,   209,    84,    -1,   187,   209,   133,
     175,    84,    -1,    84,    -1,   208,   133,   175,    84,    -1,
      20,   149,   165,   150,    -1,    20,   108,   149,   165,   150,
      -1,    20,   108,    -1,   166,    -1,   165,   139,   166,    -1,
     208,   133,   191,   174,    84,    -1,     8,   168,   169,    -1,
     108,    -1,    -1,    78,   170,   138,    81,    -1,   171,    -1,
     170,    75,   171,    -1,   108,   173,    -1,    17,   133,    -1,
      -1,    77,   212,    -1,   175,    -1,   174,    75,   175,    -1,
     176,    -1,   178,    -1,   177,   178,    -1,    85,    -1,    85,
     177,    -1,   108,    -1,   178,   179,    -1,    80,   175,    83,
      -1,   178,   181,    -1,    79,    82,    -1,    79,    85,    82,
      -1,    79,   130,    82,    -1,    79,    85,    76,    85,    82,
      -1,    79,    85,    76,   130,    82,    -1,    79,   130,    76,
      85,    82,    -1,    79,   130,    76,   130,    82,    -1,   208,
     133,   174,   138,    -1,     1,   174,    -1,   182,   184,   138,
     183,    -1,    80,    -1,    83,    -1,   185,    -1,   184,    75,
     185,    -1,    -1,   208,   133,   191,   186,    -1,     1,   191,
     186,    -1,   175,    -1,    -1,    79,    -1,    82,    -1,    80,
      -1,    83,    -1,   208,    -1,   187,   193,   138,   188,    -1,
     187,     1,   188,    -1,    -1,   194,    -1,   193,    75,   194,
      -1,    -1,    67,     1,    -1,    67,    73,    -1,    55,    80,
     198,   138,    83,    -1,     9,    80,   199,   138,    83,    -1,
      68,    80,   197,    83,    -1,    47,    -1,    54,    80,   196,
      83,    -1,    53,    -1,   195,    -1,    43,    80,    30,   108,
      83,    -1,    43,    80,   108,   108,    83,    -1,    18,    -1,
      56,    -1,    66,    -1,   110,    -1,   112,    -1,   200,    -1,
     198,    75,   200,    -1,   201,    -1,   199,    75,   201,    -1,
     109,    -1,   108,    -1,   203,   189,   204,   190,    -1,   206,
     189,   207,   190,    -1,    37,    -1,    45,    -1,    46,    -1,
      48,    -1,    50,    -1,    61,    -1,   205,    -1,   204,    75,
     205,    -1,   212,    -1,    -1,    63,    -1,   108,    -1,    85,
     108,    -1,   187,   209,    -1,    -1,   210,   138,   188,    -1,
       1,   188,    -1,     1,    84,    -1,   211,    -1,   210,    75,
     211,    -1,   202,    -1,    34,    -1,    49,    -1,    39,    -1,
      57,    -1,    47,    -1,    41,    80,   108,    83,    -1,    56,
      -1,    44,    -1,    44,    80,    60,    83,    -1,    52,    -1,
      52,    80,    60,    83,    -1,    42,    80,   108,    83,    -1,
      42,    80,    85,   108,    83,    -1,    69,    -1,    62,    -1,
      70,    -1,    66,    -1,    18,    -1,    40,    -1,    36,    -1,
      72,    -1,    71,    -1,     3,    80,    19,    83,    -1,     3,
      80,    24,    83,    -1,     3,    80,    16,    83,    -1,     3,
      80,    11,    83,    -1,    38,    -1,    65,    80,   134,    83,
      -1,    64,    80,   134,    83,    -1,    28,    80,   158,    83,
      -1,     7,    -1,   108,    -1,   213,    -1,   214,    -1,   214,
      86,   212,    74,   213,    -1,   215,    -1,   214,    88,   215,
      -1,   216,    -1,   215,    94,   216,    -1,   217,    -1,   216,
      87,   217,    -1,   218,    -1,   217,    98,   218,    -1,   219,
      -1,   218,    93,   219,    -1,   220,    -1,   219,    97,   220,
      -1,   219,   102,   220,    -1,   221,    -1,   220,    89,   221,
      -1,   220,    91,   221,    -1,   220,    95,   221,    -1,   220,
      96,   221,    -1,   222,    -1,   221,    90,   222,    -1,   221,
      92,   222,    -1,   223,    -1,   222,    99,   223,    -1,   222,
     100,   223,    -1,   224,    -1,   223,    85,   224,    -1,   223,
     103,   224,    -1,   223,   104,   224,    -1,   225,    -1,   226,
      -1,    99,   226,    -1,   100,   226,    -1,   105,   226,    -1,
     101,   226,    -1,    85,   226,    -1,    80,   212,    83,    -1,
     110,    -1,   111,    -1,   108,    -1,   109,    -1,    33,    -1,
      31,    -1,    32,    -1,   112,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const unsigned short yyrline[] =
{
       0,   261,   261,   263,   273,   275,   279,   286,   298,   301,
     309,   325,   327,   332,   340,   353,   355,   361,   362,   371,
     375,   379,   386,   387,   398,   413,   414,   424,   428,   433,
     439,   446,   455,   466,   473,   483,   484,   488,   489,   490,
     491,   492,   493,   494,   495,   500,   501,   502,   503,   508,
     515,   519,   525,   527,   531,   533,   538,   539,   543,   548,
     553,   558,   566,   568,   573,   581,   583,   585,   593,   598,
     603,   608,   613,   618,   625,   633,   643,   652,   661,   670,
     679,   688,   695,   701,   708,   709,   717,   718,   727,   733,
     740,   741,   749,   750,   759,   765,   769,   776,   781,   789,
     793,   816,   820,   824,   831,   832,   841,   851,   858,   861,
     865,   872,   873,   882,   889,   897,   900,   908,   912,   923,
     928,   930,   939,   941,   946,   948,   954,   958,   986,   991,
     996,  1001,  1006,  1011,  1016,  1025,  1034,  1042,  1049,  1056,
    1064,  1065,  1073,  1079,  1113,  1121,  1124,  1139,  1146,  1153,
    1160,  1172,  1192,  1193,  1198,  1202,  1203,  1204,  1208,  1212,
    1221,  1227,  1233,  1242,  1250,  1257,  1263,  1270,  1278,  1289,
    1290,  1291,  1295,  1302,  1319,  1320,  1324,  1328,  1337,  1344,
    1362,  1367,  1375,  1379,  1383,  1387,  1391,  1395,  1403,  1404,
    1414,  1419,  1425,  1432,  1436,  1446,  1450,  1458,  1459,  1469,
    1483,  1486,  1505,  1508,  1510,  1512,  1514,  1516,  1518,  1521,
    1523,  1525,  1529,  1531,  1535,  1540,  1547,  1549,  1551,  1553,
    1555,  1557,  1559,  1563,  1565,  1567,  1570,  1573,  1576,  1579,
    1581,  1586,  1593,  1598,  1601,  1617,  1622,  1624,  1631,  1633,
    1640,  1642,  1649,  1651,  1658,  1660,  1667,  1669,  1676,  1678,
    1682,  1690,  1692,  1696,  1700,  1704,  1712,  1714,  1718,  1726,
    1728,  1733,  1740,  1742,  1752,  1756,  1763,  1768,  1770,  1774,
    1778,  1782,  1786,  1793,  1795,  1801,  1805,  1809,  1813,  1818,
    1823,  1827
};
#endif

#if YYDEBUG || YYERROR_VERBOSE
/* YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals. */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ALIGN_KW", "BYTE_KW", "CHAR_KW",
  "CONST_KW", "DEFAULT_KW", "ENUM_KW", "EXCEPTIONS_KW", "FLOAT_KW",
  "HYPER_KW", "INT_KW", "INTERFACE_KW", "IMPORT_KW", "LIBRARY_KW",
  "LONG_KW", "PIPE_KW", "REF_KW", "SMALL_KW", "STRUCT_KW", "TYPEDEF_KW",
  "UNION_KW", "UNSIGNED_KW", "SHORT_KW", "VOID_KW", "DOUBLE_KW",
  "BOOLEAN_KW", "CASE_KW", "SWITCH_KW", "HANDLE_T_KW", "TRUE_KW",
  "FALSE_KW", "NULL_KW", "BROADCAST_KW", "COMM_STATUS_KW",
  "CONTEXT_HANDLE_KW", "FIRST_IS_KW", "HANDLE_KW", "IDEMPOTENT_KW",
  "IGNORE_KW", "CALL_AS_KW", "IID_IS_KW", "IMPLICIT_HANDLE_KW", "IN_KW",
  "LAST_IS_KW", "LENGTH_IS_KW", "LOCAL_KW", "MAX_IS_KW", "MAYBE_KW",
  "MIN_IS_KW", "MUTABLE_KW", "OUT_KW", "OBJECT_KW", "POINTER_DEFAULT_KW",
  "ENDPOINT_KW", "PTR_KW", "REFLECT_DELETIONS_KW", "REMOTE_KW",
  "SECURE_KW", "SHAPE_KW", "SIZE_IS_KW", "STRING_KW", "SWITCH_IS_KW",
  "SWITCH_TYPE_KW", "TRANSMIT_AS_KW", "UNIQUE_KW", "UUID_KW", "VERSION_KW",
  "V1_ARRAY_KW", "V1_STRING_KW", "V1_ENUM_KW", "V1_STRUCT_KW", "UUID_REP",
  "COLON", "COMMA", "DOTDOT", "EQUAL", "LBRACE", "LBRACKET", "LPAREN",
  "RBRACE", "RBRACKET", "RPAREN", "SEMI", "STAR", "QUESTION", "BAR",
  "BARBAR", "LANGLE", "LANGLEANGLE", "RANGLE", "RANGLEANGLE", "AMP",
  "AMPAMP", "LESSEQUAL", "GREATEREQUAL", "EQUALEQUAL", "CARET", "PLUS",
  "MINUS", "NOT", "NOTEQUAL", "SLASH", "PERCENT", "TILDE", "POUND",
  "UNKNOWN", "IDENTIFIER", "STRING", "INTEGER_NUMERIC", "CHAR",
  "FLOAT_NUMERIC", "$accept", "grammar_start", "interfaces", "interface",
  "interface_start", "interface_ancestor", "interface_init",
  "interface_tail", "interface_body", "optional_imports", "imports",
  "import", "import_files", "import_file", "exports", "export",
  "const_dcl", "const_exp", "type_dcl", "type_declarator", "type_spec",
  "simple_type_spec", "constructed_type_spec", "named_type_spec",
  "floating_point_type_spec", "extraneous_comma", "extraneous_semi",
  "optional_unsigned_kw", "integer_size_spec", "integer_modifiers",
  "integer_type_spec", "char_type_spec", "boolean_type_spec",
  "byte_type_spec", "void_type_spec", "handle_type_spec",
  "push_name_space", "pop_name_space", "union_type_spec", "ne_union_body",
  "union_body", "ne_union_cases", "union_cases", "ne_union_case",
  "union_case", "ne_union_case_list", "union_case_list",
  "ne_union_case_label", "union_case_label", "ne_union_member",
  "union_member", "struct_type_spec", "member_list", "member",
  "enum_type_spec", "optional_tag", "enum_body", "enum_ids", "enum_id",
  "pipe_type_spec", "optional_value", "declarators", "declarator",
  "declarator1", "pointer", "direct_declarator", "array_bounds",
  "operation_dcl", "parameter_dcls", "param_names", "end_param_names",
  "param_list", "param_dcl", "declarator_or_null", "attribute_opener",
  "attribute_closer", "bounds_opener", "bounds_closer",
  "old_attribute_syntax", "interface_attributes", "interface_attr_list",
  "interface_attr", "acf_interface_attr", "pointer_class",
  "version_number", "port_list", "excep_list", "port_spec", "excep_spec",
  "fp_attribute", "array_bound_type", "array_bound_id_list",
  "array_bound_id", "neu_switch_type", "neu_switch_id", "attributes",
  "rest_of_attribute_list", "attribute_list", "attribute", "expression",
  "conditional_expression", "logical_OR_expression",
  "logical_AND_expression", "inclusive_OR_expression",
  "exclusive_OR_expression", "AND_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "primary_expression", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const unsigned char yyr1[] =
{
       0,   113,   114,   114,   115,   115,   116,   117,   118,   118,
     119,   120,   120,   120,   121,   122,   122,   123,   123,   124,
     124,   124,   125,   125,   126,   127,   127,   128,   128,   128,
     128,   129,   130,   131,   132,   133,   133,   134,   134,   134,
     134,   134,   134,   134,   134,   135,   135,   135,   135,   136,
     137,   137,   138,   138,   139,   139,   140,   140,   141,   141,
     141,   141,   142,   142,   142,   143,   143,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   151,   151,   151,   151,
     151,   151,   152,   153,   154,   154,   155,   155,   156,   157,
     158,   158,   159,   159,   160,   161,   161,   162,   162,   163,
     163,   164,   164,   164,   165,   165,   166,   167,   168,   168,
     169,   170,   170,   171,   172,   173,   173,   174,   174,   175,
     176,   176,   177,   177,   178,   178,   178,   178,   179,   179,
     179,   179,   179,   179,   179,   180,   180,   181,   182,   183,
     184,   184,   184,   185,   185,   186,   186,   187,   188,   189,
     190,   191,   192,   192,   192,   193,   193,   193,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   195,   195,   196,
     196,   196,   197,   197,   198,   198,   199,   199,   200,   201,
     202,   202,   203,   203,   203,   203,   203,   203,   204,   204,
     205,   205,   206,   207,   207,   208,   208,   209,   209,   209,
     210,   210,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   212,   213,   213,   214,   214,
     215,   215,   216,   216,   217,   217,   218,   218,   219,   219,
     219,   220,   220,   220,   220,   220,   221,   221,   221,   222,
     222,   222,   223,   223,   223,   223,   224,   225,   225,   225,
     225,   225,   225,   226,   226,   226,   226,   226,   226,   226,
     226,   226
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const unsigned char yyr2[] =
{
       0,     2,     1,     1,     2,     1,     4,     3,     0,     2,
       0,     3,     1,     2,     3,     1,     0,     1,     2,     2,
       3,     3,     1,     3,     1,     1,     3,     2,     2,     2,
       2,     5,     1,     2,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     1,     0,     1,     1,     0,     1,     1,
       1,     1,     1,     2,     2,     1,     2,     2,     2,     1,
       1,     1,     1,     1,     1,     2,     7,     3,     8,     8,
       9,     2,     3,     3,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     2,     1,     3,     2,     3,     5,     1,
       4,     4,     5,     2,     1,     3,     5,     3,     1,     0,
       4,     1,     3,     2,     2,     0,     2,     1,     3,     1,
       1,     2,     1,     2,     1,     2,     3,     2,     2,     3,
       3,     5,     5,     5,     5,     4,     2,     4,     1,     1,
       1,     3,     0,     4,     3,     1,     0,     1,     1,     1,
       1,     1,     4,     3,     0,     1,     3,     0,     2,     2,
       5,     5,     4,     1,     4,     1,     1,     5,     5,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     1,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     0,     1,     1,     2,     2,     0,     3,     2,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     4,     1,     4,     4,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     1,
       4,     4,     4,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     1,     2,     2,
       2,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned short yydefact[] =
{
      10,     0,     0,    10,     5,   154,     3,    15,    17,    19,
      24,     0,    22,     1,     4,   147,     8,     0,     0,    18,
      20,     0,    21,     0,     0,     0,     0,     0,   163,   165,
       0,     0,     0,     0,    52,   155,   166,     0,    23,     9,
      12,    16,     6,   148,   153,     0,     0,     0,     0,   158,
     159,     0,    53,     0,     7,    13,     0,     0,   179,    52,
     176,     0,     0,   169,   170,   171,     0,   178,    52,   174,
     172,   173,     0,   156,   152,    11,     0,    57,   196,    54,
      25,     0,     0,     0,     0,    57,    53,     0,     0,     0,
     164,    53,     0,   162,     0,    30,   122,   124,   136,   117,
     119,     0,   120,    70,   109,    50,    61,    60,    57,    58,
       0,     0,    56,    59,    71,    51,    69,    72,    49,     0,
      35,    36,    43,    37,     0,    62,    65,    38,    39,    40,
      41,    42,    44,    46,    45,    47,    48,    33,    57,    55,
       0,    28,    27,    29,     0,     0,   233,   220,     0,   203,
     222,   182,   229,   205,   221,     0,     0,   210,   183,   184,
     207,   185,   204,   186,   212,   209,   206,   187,   217,   192,
       0,     0,   219,   216,   218,   224,   223,   234,   202,     0,
       0,   195,    52,   200,     0,   177,   161,   167,   168,   175,
     160,     0,   123,     0,   121,     0,   138,   125,   127,     0,
     108,     0,   114,    73,   103,   196,     0,    81,     0,    75,
      63,     0,    68,    67,    64,    66,     0,    26,   199,   198,
       0,     0,     0,     0,     0,     0,    57,    57,   149,   191,
       0,    53,     0,    52,   126,   118,   279,   280,   278,     0,
     128,     0,     0,     0,     0,     0,   276,   277,   274,   275,
     281,     0,    32,   235,   236,   238,   240,   242,   244,   246,
     248,   251,   256,   259,   262,   266,   267,   196,    52,   140,
      57,     0,   107,   196,    54,   104,    57,    57,     0,    77,
      54,    84,    88,     0,     0,    52,     0,     0,     0,     0,
       0,    94,     0,    90,     0,     0,     0,     0,     0,     0,
       0,     0,   188,   190,     0,   193,     0,   201,   197,    53,
     135,     0,     0,   129,   272,   268,   269,   271,   270,     0,
     130,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     146,   151,     0,     0,   196,   115,    52,   111,    54,    74,
     196,   101,   196,     0,    57,     0,    82,    57,    31,    34,
     228,   227,   225,   226,     0,   232,   208,     0,   214,   211,
     213,   231,   230,   191,   150,   180,   194,   181,   273,     0,
       0,     0,     0,     0,   239,   241,   243,   245,   247,   249,
     250,   252,   253,   254,   255,   257,   258,   260,   261,   263,
     264,   265,   145,   144,   141,   139,   137,   146,     0,   113,
      53,     0,   102,   105,     0,     0,     0,    85,    97,     0,
      91,   215,   189,   131,   132,   133,   134,     0,   143,   116,
     112,   110,     0,     0,     0,     0,   237,   106,     0,     0,
      76,     0,    98,    78,     0,     0,    54,    86,   196,    92,
       0,    79,    96,     0,     0,    83,    99,    93,    89,    57,
      80,    95,    87,     0,     0,   100
};

/* YYDEFGOTO[NTERM-NUM]. */
static const short yydefgoto[] =
{
      -1,     2,     3,     4,    16,    24,     5,    42,    56,     6,
       7,     8,    11,    12,    79,    80,    81,   291,    82,   137,
     119,   120,   121,   122,   123,    53,   350,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   439,   351,   133,   209,
     440,   280,   446,   281,   447,   292,   448,   293,   449,   282,
     458,   134,   274,   275,   135,   201,   272,   346,   347,   136,
     409,    98,    99,   100,   101,   102,   197,    83,   198,   199,
     406,   268,   269,   403,    84,    44,   229,   375,   340,    18,
      34,    35,    36,    66,    72,    68,    59,    69,    60,   178,
     179,   301,   302,   180,   306,   276,   181,   182,   183,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -272
static const short yypact[] =
{
      59,     9,    76,    86,  -272,   -34,  -272,    46,  -272,   -61,
    -272,   -40,  -272,  -272,  -272,  -272,    19,   571,   150,  -272,
    -272,    63,  -272,    94,    16,   127,   135,   141,  -272,  -272,
     180,   185,    25,   192,   211,  -272,  -272,   181,  -272,  -272,
     212,    46,  -272,  -272,  -272,   186,   -11,    23,   189,  -272,
    -272,    70,   482,   127,  -272,  -272,   220,   313,  -272,   233,
    -272,   201,   203,  -272,  -272,  -272,   229,  -272,   241,  -272,
    -272,  -272,   237,  -272,  -272,  -272,    93,   479,   -34,   238,
    -272,   242,   244,   247,   205,   479,   186,   258,   259,   261,
    -272,   189,   265,  -272,    47,  -272,   264,  -272,   275,  -272,
    -272,   -60,   149,  -272,   243,  -272,  -272,  -272,   479,  -272,
     -56,    14,   165,  -272,  -272,  -272,  -272,  -272,  -272,    47,
    -272,  -272,  -272,  -272,    35,   329,   341,  -272,  -272,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   479,  -272,
      45,  -272,  -272,  -272,   121,   276,  -272,  -272,   277,  -272,
    -272,  -272,  -272,  -272,  -272,   279,   283,   286,  -272,  -272,
    -272,  -272,  -272,  -272,   292,  -272,  -272,  -272,  -272,  -272,
     298,   305,  -272,  -272,  -272,  -272,  -272,  -272,  -272,   318,
     318,  -272,   285,  -272,    47,  -272,  -272,  -272,  -272,  -272,
    -272,   272,  -272,    47,   149,    49,  -272,  -272,  -272,   357,
    -272,   321,  -272,  -272,   322,   -34,   323,    -4,   -34,  -272,
    -272,   337,  -272,  -272,  -272,  -272,    47,  -272,  -272,  -272,
     200,   453,   308,     3,   346,   358,    80,    80,  -272,   453,
      48,   410,   127,   344,  -272,  -272,  -272,  -272,  -272,   453,
    -272,    88,   314,   314,   314,   314,  -272,  -272,  -272,  -272,
    -272,   109,  -272,  -272,   146,   326,   340,   331,   338,   128,
     131,   148,   136,    62,  -272,  -272,  -272,   -34,   355,  -272,
     479,   325,  -272,   -34,    55,  -272,   479,    80,   354,  -272,
      55,  -272,  -272,   205,   453,   344,   352,   356,   359,   360,
     314,  -272,   -41,  -272,   362,   333,   370,   378,   380,   386,
     387,    68,  -272,  -272,   369,  -272,   395,  -272,  -272,    47,
    -272,   405,   489,  -272,  -272,  -272,  -272,  -272,  -272,   511,
    -272,   453,   453,   453,   453,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   453,   453,   453,   453,   453,   453,
      47,  -272,   385,   409,   -34,   417,   422,  -272,    55,  -272,
     -34,  -272,   -34,   392,    80,   -34,  -272,   280,  -272,  -272,
    -272,  -272,  -272,  -272,   453,  -272,  -272,   424,  -272,  -272,
    -272,  -272,  -272,   453,  -272,  -272,  -272,  -272,  -272,     5,
     426,   495,   428,   363,   326,   340,   331,   338,   128,   131,
     131,   148,   148,   148,   148,   136,   136,    62,    62,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,    47,   453,  -272,
     325,   430,  -272,  -272,    47,   429,   406,  -272,  -272,    47,
    -272,  -272,  -272,  -272,  -272,  -272,  -272,   453,  -272,  -272,
    -272,  -272,    60,   -50,   432,   433,  -272,  -272,   322,   118,
    -272,    30,  -272,  -272,   439,   453,    55,  -272,   134,  -272,
     322,  -272,  -272,   442,   118,  -272,  -272,  -272,  -272,   479,
    -272,  -272,  -272,    47,   435,  -272
};

/* YYPGOTO[NTERM-NUM].  */
static const short yypgoto[] =
{
    -272,  -272,  -272,   520,  -272,  -272,  -272,  -272,  -272,   483,
    -272,   523,  -272,   510,  -272,   394,  -272,  -189,  -272,  -272,
     -84,  -214,  -272,  -272,  -272,   -54,   -76,  -272,   420,  -272,
    -272,  -272,  -272,  -272,  -272,  -272,   -95,  -271,  -272,   332,
    -267,  -272,  -272,   190,    87,  -272,  -272,   176,    98,  -272,
    -272,  -272,   274,   198,  -272,  -272,  -272,  -272,   145,  -272,
    -272,  -177,   -92,  -272,   455,   456,  -272,  -272,  -272,  -272,
    -272,  -272,   214,   152,    -1,   -42,   388,   254,  -207,  -272,
    -272,   514,  -272,  -272,  -272,  -272,  -272,   476,   484,  -272,
    -272,  -272,   206,  -272,  -272,   -57,   288,  -272,   342,  -221,
     151,  -272,   260,   253,   257,   267,   269,   -69,   -51,   -70,
     -53,  -144,  -272,  -212
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -197
static const short yytable[] =
{
      85,   184,   191,   140,    17,    87,   251,   233,   303,   356,
       9,    74,   299,   300,    92,   205,   208,    40,   311,    61,
      94,   138,   203,    20,   202,   278,    49,   211,   203,   314,
     315,   316,   317,   318,   364,    21,   236,   237,   238,   285,
     212,    63,   365,   206,    22,    15,    76,   213,    97,  -196,
    -196,    77,   204,  -196,   216,  -196,  -196,  -196,   438,   -16,
       1,  -196,  -196,   353,  -196,  -196,    78,  -196,  -196,  -196,
    -196,  -196,  -196,     1,   203,  -196,    13,   412,   314,    64,
     236,   237,   238,    85,   103,   239,    -2,   423,   295,    65,
     105,   106,   203,    23,    41,   358,   107,    62,    50,   109,
     383,   235,   219,   112,   113,   114,   115,   116,   203,   273,
     117,   296,   208,   246,   247,   248,   249,   250,    10,   236,
     237,   238,   207,   380,    15,   444,   -14,    94,   232,   239,
     382,   240,    96,   304,   241,   193,   349,   407,   450,   139,
     416,   444,   270,   373,   437,   414,   445,   337,   242,   243,
     244,   374,   303,  -196,   245,    97,   305,   246,   247,   248,
     249,   250,   445,    37,   312,   338,   339,   314,   239,   314,
     313,   443,    10,    94,   451,   455,   106,    95,    96,   310,
      70,   107,    71,   460,   109,   319,   344,   429,   118,   113,
     308,   320,   352,   399,   400,   401,   246,   247,   248,   249,
     250,    97,    39,    43,   355,   218,   144,   283,   145,    43,
     341,   286,   146,    15,   343,    45,   287,   235,   456,   288,
     329,    46,   330,   147,   289,   327,   331,   332,   195,   196,
     328,   359,   321,   148,   322,   335,   336,   432,   333,   149,
     334,   150,   151,   152,   153,   154,   155,   156,   402,   157,
     158,   159,   160,   161,   162,   163,   453,   164,   389,   390,
      47,   165,   166,   395,   396,    48,   167,   168,   169,   170,
     171,   172,    51,   419,   173,   174,   175,   176,   391,   392,
     393,   394,   397,   398,   103,   270,    52,   341,   104,    54,
     105,   106,   411,    55,    58,   341,   107,   108,    67,   109,
     110,    75,   111,   112,   113,   114,   115,   116,    86,    88,
     117,    89,    90,   177,    76,   402,    91,  -196,  -196,    77,
      93,  -196,   139,  -196,  -196,  -196,   141,   435,   142,  -196,
    -196,   143,  -196,  -196,    78,  -196,  -196,  -196,  -196,  -196,
    -196,   186,   187,  -196,   188,   236,   237,   238,   190,    96,
     193,   200,   214,   215,   283,   234,   220,   221,   267,   222,
     231,  -196,  -196,   223,   418,  -196,   224,  -196,  -196,  -196,
     454,   464,   225,  -196,  -196,   463,  -196,  -196,   226,  -196,
    -196,  -196,  -196,  -196,  -196,   227,   267,  -196,   118,  -196,
    -196,   459,    15,  -196,   239,  -196,  -196,  -196,   228,   271,
     203,  -196,  -196,   277,  -196,  -196,   297,  -196,  -196,  -196,
    -196,  -196,  -196,   145,   284,  -196,   294,   146,   298,   309,
     323,  -196,   246,   247,   248,   249,   250,   324,   147,   325,
     342,   326,  -142,   345,   354,   360,    15,   427,   148,   361,
    -142,   367,   362,   363,   149,   366,   150,   151,   152,   153,
     154,   155,   156,   368,   157,   158,   159,   160,   161,   162,
     163,   369,   164,   370,    15,  -196,   165,   166,   -53,   371,
     372,   167,   168,   169,   170,   171,   172,   376,   374,   173,
     174,   175,   176,   103,   236,   237,   238,   104,   378,   105,
     106,    26,   405,  -196,   408,   107,   108,   410,   109,   110,
     415,   111,   112,   113,   114,   115,   116,   421,   424,   117,
     426,   431,   433,   452,   434,   441,   461,   442,   177,   465,
     236,   237,   238,    14,    57,    27,   236,   237,   238,    28,
      19,    38,   210,   239,   217,    29,    30,    31,   290,   279,
     420,   462,   236,   237,   238,   417,   457,   348,   413,    32,
      33,   192,   242,   243,   244,   430,   404,   194,   245,   428,
     377,   246,   247,   248,   249,   250,    73,   189,   230,   239,
     185,   357,    25,   307,   379,   239,   385,   425,   436,   422,
      26,   386,   384,     0,     0,     0,     0,   118,   242,   243,
     244,   239,   387,     0,   245,   388,   381,   246,   247,   248,
     249,   250,     0,   246,   247,   248,   249,   250,     0,     0,
     242,   243,   244,     0,    27,     0,   245,     0,    28,   246,
     247,   248,   249,   250,    29,    30,    31,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    32,    33,
       0,     0,     0,     0,     0,     0,  -157,     0,     0,     0,
       0,     0,     0,  -157
};

static const short yycheck[] =
{
      57,    85,    94,    79,     5,    59,   195,   184,   229,   280,
       1,    53,   226,   227,    68,   110,   111,     1,   239,    30,
      80,    78,    78,    84,   108,    29,     1,   119,    78,   241,
     242,   243,   244,   245,    75,    75,    31,    32,    33,   216,
       5,    18,    83,    29,    84,    79,     1,    12,   108,     4,
       5,     6,   108,     8,   138,    10,    11,    12,   108,     0,
      14,    16,    17,   277,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    14,    78,    30,     0,   348,   290,    56,
      31,    32,    33,   140,     4,    80,     0,    82,    85,    66,
      10,    11,    78,    74,    78,   284,    16,   108,    73,    19,
     321,   193,   144,    23,    24,    25,    26,    27,    78,   204,
      30,   108,   207,   108,   109,   110,   111,   112,   109,    31,
      32,    33,   108,   312,    79,     7,    81,    80,   182,    80,
     319,    82,    85,    85,    85,    75,    81,   344,   108,    84,
     354,     7,   199,    75,    84,   352,    28,    85,    99,   100,
     101,    83,   373,   108,   105,   108,   108,   108,   109,   110,
     111,   112,    28,    13,    76,   103,   104,   379,    80,   381,
      82,   438,   109,    80,   441,   446,    11,    84,    85,   233,
     110,    16,   112,   450,    19,    76,   270,   408,   108,    24,
     232,    82,   276,   337,   338,   339,   108,   109,   110,   111,
     112,   108,   108,    82,   280,    84,     1,   208,     3,    82,
     267,    11,     7,    79,   268,    80,    16,   309,    84,    19,
      89,    80,    91,    18,    24,    97,    95,    96,    79,    80,
     102,   285,    86,    28,    88,    99,   100,   414,    90,    34,
      92,    36,    37,    38,    39,    40,    41,    42,   340,    44,
      45,    46,    47,    48,    49,    50,   445,    52,   327,   328,
      80,    56,    57,   333,   334,    80,    61,    62,    63,    64,
      65,    66,    80,   357,    69,    70,    71,    72,   329,   330,
     331,   332,   335,   336,     4,   342,    75,   344,     8,   108,
      10,    11,   346,    81,   108,   352,    16,    17,   109,    19,
      20,    81,    22,    23,    24,    25,    26,    27,    75,   108,
      30,   108,    83,   108,     1,   407,    75,     4,     5,     6,
      83,     8,    84,    10,    11,    12,    84,   419,    84,    16,
      17,    84,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    83,    83,    30,    83,    31,    32,    33,    83,    85,
      75,   108,    23,    12,   355,    83,    80,    80,     1,    80,
      75,     4,     5,    80,    84,     8,    80,    10,    11,    12,
     446,   463,    80,    16,    17,   459,    19,    20,    80,    22,
      23,    24,    25,    26,    27,    80,     1,    30,   108,     4,
       5,   448,    79,     8,    80,    10,    11,    12,    80,    78,
      78,    16,    17,    80,    19,    20,    60,    22,    23,    24,
      25,    26,    27,     3,    77,    30,   108,     7,    60,    75,
      94,   108,   108,   109,   110,   111,   112,    87,    18,    98,
      75,    93,    75,   108,    80,    83,    79,    74,    28,    83,
      83,   108,    83,    83,    34,    83,    36,    37,    38,    39,
      40,    41,    42,    83,    44,    45,    46,    47,    48,    49,
      50,    83,    52,    83,    79,   108,    56,    57,    83,    83,
      83,    61,    62,    63,    64,    65,    66,   108,    83,    69,
      70,    71,    72,     4,    31,    32,    33,     8,    83,    10,
      11,     9,    83,   108,    77,    16,    17,    75,    19,    20,
     108,    22,    23,    24,    25,    26,    27,    83,    82,    30,
      82,    81,    83,    74,   108,    83,    74,    84,   108,    84,
      31,    32,    33,     3,    41,    43,    31,    32,    33,    47,
       7,    21,   112,    80,   140,    53,    54,    55,    85,   207,
     364,   454,    31,    32,    33,   355,   448,   273,   350,    67,
      68,    96,    99,   100,   101,   410,   342,   101,   105,   407,
     306,   108,   109,   110,   111,   112,    52,    91,   180,    80,
      86,   283,     1,   231,    85,    80,   323,    82,   427,   373,
       9,   324,   322,    -1,    -1,    -1,    -1,   108,    99,   100,
     101,    80,   325,    -1,   105,   326,    85,   108,   109,   110,
     111,   112,    -1,   108,   109,   110,   111,   112,    -1,    -1,
      99,   100,   101,    -1,    43,    -1,   105,    -1,    47,   108,
     109,   110,   111,   112,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    -1,
      -1,    -1,    -1,    82
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char yystos[] =
{
       0,    14,   114,   115,   116,   119,   122,   123,   124,     1,
     109,   125,   126,     0,   116,    79,   117,   187,   192,   124,
      84,    75,    84,    74,   118,     1,     9,    43,    47,    53,
      54,    55,    67,    68,   193,   194,   195,    13,   126,   108,
       1,    78,   120,    82,   188,    80,    80,    80,    80,     1,
      73,    80,    75,   138,   108,    81,   121,   122,   108,   199,
     201,    30,   108,    18,    56,    66,   196,   109,   198,   200,
     110,   112,   197,   194,   188,    81,     1,     6,    21,   127,
     128,   129,   131,   180,   187,   208,    75,   138,   108,   108,
      83,    75,   138,    83,    80,    84,    85,   108,   174,   175,
     176,   177,   178,     4,     8,    10,    11,    16,    17,    19,
      20,    22,    23,    24,    25,    26,    27,    30,   108,   133,
     134,   135,   136,   137,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   151,   164,   167,   172,   132,   208,    84,
     139,    84,    84,    84,     1,     3,     7,    18,    28,    34,
      36,    37,    38,    39,    40,    41,    42,    44,    45,    46,
      47,    48,    49,    50,    52,    56,    57,    61,    62,    63,
      64,    65,    66,    69,    70,    71,    72,   108,   202,   203,
     206,   209,   210,   211,   133,   201,    83,    83,    83,   200,
      83,   175,   177,    75,   178,    79,    80,   179,   181,   182,
     108,   168,   133,    78,   108,   149,    29,   108,   149,   152,
     141,   175,     5,    12,    23,    12,   133,   128,    84,   188,
      80,    80,    80,    80,    80,    80,    80,    80,    80,   189,
     189,    75,   138,   174,    83,   175,    31,    32,    33,    80,
      82,    85,    99,   100,   101,   105,   108,   109,   110,   111,
     112,   130,   212,   213,   214,   215,   216,   217,   218,   219,
     220,   221,   222,   223,   224,   225,   226,     1,   184,   185,
     208,    78,   169,   149,   165,   166,   208,    80,    29,   152,
     154,   156,   162,   187,    77,   174,    11,    16,    19,    24,
      85,   130,   158,   160,   108,    85,   108,    60,    60,   134,
     134,   204,   205,   212,    85,   108,   207,   211,   188,    75,
     138,   212,    76,    82,   226,   226,   226,   226,   226,    76,
      82,    86,    88,    94,    87,    98,    93,    97,   102,    89,
      91,    95,    96,    90,    92,    99,   100,    85,   103,   104,
     191,   208,    75,   138,   133,   108,   170,   171,   165,    81,
     139,   150,   133,   134,    80,   139,   150,   209,   130,   138,
      83,    83,    83,    83,    75,    83,    83,   108,    83,    83,
      83,    83,    83,    75,    83,   190,   108,   190,    83,    85,
     130,    85,   130,   212,   215,   216,   217,   218,   219,   220,
     220,   221,   221,   221,   221,   222,   222,   223,   223,   224,
     224,   224,   175,   186,   185,    83,   183,   191,    77,   173,
      75,   138,   150,   166,   191,   108,   134,   156,    84,   133,
     160,    83,   205,    82,    82,    82,    82,    74,   186,   212,
     171,    81,   174,    83,   108,   175,   213,    84,   108,   149,
     153,    83,    84,   153,     7,    28,   155,   157,   159,   161,
     108,   153,    74,   130,   139,   150,    84,   161,   163,   208,
     153,    74,   157,   133,   175,    84
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
#line 264 "nidl_y.y"
    {
#if 0
	 			global_imports = (AST_import_n_t*)AST_concat_element(
	 				 (ASTP_node_t*)global_imports, (ASTP_node_t*)yyvsp[0].y_import);
#endif
			}
    break;

  case 6:
#line 280 "nidl_y.y"
    {
            AST_finish_interface_node(the_interface);
        }
    break;

  case 7:
#line 287 "nidl_y.y"
    {
				AST_type_n_t * interface_type = AST_type_node(AST_interface_k);
				interface_type->type_structure.interface = the_interface;
				interface_type->name = yyvsp[0].y_id;
            the_interface->name = yyvsp[0].y_id;
            ASTP_add_name_binding (the_interface->name, interface_type);
        }
    break;

  case 8:
#line 298 "nidl_y.y"
    {
		 the_interface->inherited_interface_name = NAMETABLE_NIL_ID;
	}
    break;

  case 9:
#line 302 "nidl_y.y"
    {
		 the_interface->inherited_interface_name = yyvsp[0].y_id;
	}
    break;

  case 10:
#line 309 "nidl_y.y"
    {
            STRTAB_str_t nidl_idl_str;
            nidl_idl_str = STRTAB_add_string (AUTO_IMPORT_FILE);
            the_interface = AST_interface_node();
				the_interface->exports = NULL;
            the_interface->imports = AST_import_node(nidl_idl_str);
            the_interface->imports->interface = FE_parse_import (nidl_idl_str);
            if (the_interface->imports->interface != NULL)
            {
                AST_CLR_OUT_OF_LINE(the_interface->imports->interface);
                AST_SET_IN_LINE(the_interface->imports->interface);
            }
        }
    break;

  case 11:
#line 326 "nidl_y.y"
    { yyval.y_interface = yyvsp[-1].y_interface; }
    break;

  case 12:
#line 328 "nidl_y.y"
    {
            yyval.y_interface = NULL;
            acf_error(nidl_yylineno,NIDL_MISSONINTER, NULL);
        }
    break;

  case 13:
#line 333 "nidl_y.y"
    {
            yyval.y_interface = NULL;
        }
    break;

  case 14:
#line 341 "nidl_y.y"
    {
            /* May already be an import of nbase, so concat */
            the_interface->imports = (AST_import_n_t *) AST_concat_element(
                                        (ASTP_node_t *) the_interface->imports,
                                        (ASTP_node_t *) yyvsp[-2].y_import);
            the_interface->exports = (AST_export_n_t*)AST_concat_element(
													(ASTP_node_t*)the_interface->exports,
													(ASTP_node_t*)yyvsp[-1].y_export);
        }
    break;

  case 16:
#line 355 "nidl_y.y"
    {
            yyval.y_import = (AST_import_n_t *)NULL;
        }
    break;

  case 18:
#line 363 "nidl_y.y"
    {
                yyval.y_import = (AST_import_n_t *) AST_concat_element(
                                                (ASTP_node_t *) yyvsp[-1].y_import,
                                                (ASTP_node_t *) yyvsp[0].y_import);
        }
    break;

  case 19:
#line 372 "nidl_y.y"
    {
            yyval.y_import = (AST_import_n_t *)NULL;
        }
    break;

  case 20:
#line 376 "nidl_y.y"
    {
            yyval.y_import = (AST_import_n_t *)NULL;
        }
    break;

  case 21:
#line 380 "nidl_y.y"
    {
            yyval.y_import = yyvsp[-1].y_import;
        }
    break;

  case 23:
#line 388 "nidl_y.y"
    {
                yyval.y_import = (AST_import_n_t *) AST_concat_element(
                                                (ASTP_node_t *) yyvsp[-2].y_import,
                                                (ASTP_node_t *) yyvsp[0].y_import);
        }
    break;

  case 24:
#line 399 "nidl_y.y"
    {
            AST_interface_n_t  *int_p;
            int_p = FE_parse_import (yyvsp[0].y_string);
            if (int_p != (AST_interface_n_t *)NULL)
            {
                yyval.y_import = AST_import_node(yyvsp[0].y_string);
                yyval.y_import->interface = int_p;
            }
            else
                yyval.y_import = (AST_import_n_t *)NULL;
        }
    break;

  case 26:
#line 415 "nidl_y.y"
    {
                yyval.y_export = (AST_export_n_t *) AST_concat_element(
                                            (ASTP_node_t *) yyvsp[-2].y_export,
                                            (ASTP_node_t *) yyvsp[0].y_export) ;
        }
    break;

  case 27:
#line 425 "nidl_y.y"
    {
                yyval.y_export = AST_types_to_exports (yyvsp[-1].y_type_ptr);
        }
    break;

  case 28:
#line 429 "nidl_y.y"
    {
                yyval.y_export = AST_export_node (
                        (ASTP_node_t *) yyvsp[-1].y_constant, AST_constant_k);
        }
    break;

  case 29:
#line 434 "nidl_y.y"
    {
            if (ASTP_parsing_main_idl)
                yyval.y_export = AST_export_node (
                        (ASTP_node_t *) yyvsp[-1].y_operation, AST_operation_k);
        }
    break;

  case 30:
#line 440 "nidl_y.y"
    {
            yyval.y_export = (AST_export_n_t *)NULL;
        }
    break;

  case 31:
#line 448 "nidl_y.y"
    {
           yyval.y_constant = AST_finish_constant_node (yyvsp[0].y_constant,
                                        yyvsp[-2].y_declarator, yyvsp[-3].y_type);
        }
    break;

  case 32:
#line 456 "nidl_y.y"
    {
				yyval.y_constant = AST_constant_from_exp(yyvsp[0].y_exp);
				if (yyval.y_constant == NULL)	{
					 acf_error(nidl_yylineno, NIDL_EXPNOTCONST, NULL);
				}
        }
    break;

  case 33:
#line 467 "nidl_y.y"
    {
            yyval.y_type_ptr = yyvsp[0].y_type_ptr;
        }
    break;

  case 34:
#line 474 "nidl_y.y"
    {
            yyval.y_type_ptr  = AST_declarators_to_types(the_interface, yyvsp[-2].y_type,
                        yyvsp[-1].y_declarator, &yyvsp[-3].y_attributes) ;
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-3].y_attributes.bounds);
        }
    break;

  case 49:
#line 509 "nidl_y.y"
    {
            yyval.y_type = AST_lookup_named_type(yyvsp[0].y_id);
        }
    break;

  case 50:
#line 516 "nidl_y.y"
    {
            yyval.y_type = AST_lookup_type_node(AST_short_float_k);
        }
    break;

  case 51:
#line 520 "nidl_y.y"
    {
            yyval.y_type = AST_lookup_type_node(AST_long_float_k);
        }
    break;

  case 53:
#line 528 "nidl_y.y"
    { acf_warning(nidl_yylineno, NIDL_EXTRAPUNCT, ",", NULL);}
    break;

  case 55:
#line 534 "nidl_y.y"
    { acf_warning(nidl_yylineno, NIDL_EXTRAPUNCT, ";", NULL);}
    break;

  case 56:
#line 538 "nidl_y.y"
    { yyval.y_int_info.int_signed = false; }
    break;

  case 57:
#line 539 "nidl_y.y"
    { yyval.y_int_info.int_signed = true; }
    break;

  case 58:
#line 544 "nidl_y.y"
    {
            yyval.y_int_info.int_size = AST_small_integer_k;
            yyval.y_int_info.int_signed = true;
        }
    break;

  case 59:
#line 549 "nidl_y.y"
    {
            yyval.y_int_info.int_size = AST_short_integer_k;
            yyval.y_int_info.int_signed = true;
        }
    break;

  case 60:
#line 554 "nidl_y.y"
    {
            yyval.y_int_info.int_size = AST_long_integer_k;
            yyval.y_int_info.int_signed = true;
        }
    break;

  case 61:
#line 559 "nidl_y.y"
    {
            yyval.y_int_info.int_size = AST_hyper_integer_k;
            yyval.y_int_info.int_signed = true;
        }
    break;

  case 62:
#line 567 "nidl_y.y"
    { yyval.y_int_info = yyvsp[0].y_int_info; }
    break;

  case 63:
#line 569 "nidl_y.y"
    {
            yyval.y_int_info.int_size = yyvsp[0].y_int_info.int_size;
            yyval.y_int_info.int_signed = false;
        }
    break;

  case 64:
#line 574 "nidl_y.y"
    {
            yyval.y_int_info.int_size = yyvsp[-1].y_int_info.int_size;
            yyval.y_int_info.int_signed = false;
        }
    break;

  case 65:
#line 582 "nidl_y.y"
    { yyval.y_type = AST_lookup_integer_type_node(yyvsp[0].y_int_info.int_size,yyvsp[0].y_int_info.int_signed); }
    break;

  case 66:
#line 584 "nidl_y.y"
    { yyval.y_type = AST_lookup_integer_type_node(yyvsp[-1].y_int_info.int_size,yyvsp[-1].y_int_info.int_signed); }
    break;

  case 67:
#line 586 "nidl_y.y"
    {
            acf_warning(nidl_yylineno,NIDL_INTSIZEREQ, NULL);
            yyval.y_type = AST_lookup_integer_type_node(AST_long_integer_k,yyvsp[-1].y_int_info.int_signed);
        }
    break;

  case 68:
#line 594 "nidl_y.y"
    { yyval.y_type = AST_lookup_type_node(AST_character_k); }
    break;

  case 69:
#line 599 "nidl_y.y"
    { yyval.y_type = AST_lookup_type_node(AST_boolean_k); }
    break;

  case 70:
#line 604 "nidl_y.y"
    { yyval.y_type = AST_lookup_type_node(AST_byte_k); }
    break;

  case 71:
#line 609 "nidl_y.y"
    { yyval.y_type = AST_lookup_type_node(AST_void_k); }
    break;

  case 72:
#line 614 "nidl_y.y"
    { yyval.y_type = AST_lookup_type_node(AST_handle_k); }
    break;

  case 73:
#line 619 "nidl_y.y"
    {
            NAMETABLE_push_level ();
        }
    break;

  case 74:
#line 626 "nidl_y.y"
    {
            ASTP_patch_field_reference ();
            NAMETABLE_pop_level ();
        }
    break;

  case 75:
#line 634 "nidl_y.y"
    {
        yyval.y_type = AST_disc_union_node(
                         NAMETABLE_NIL_ID,      /* tag name          */
                         NAMETABLE_NIL_ID,      /* union name        */
                         NAMETABLE_NIL_ID,      /* discriminant name */
                         NULL,                  /* discriminant type */
                         yyvsp[0].y_arm );           /* the arm list      */
        }
    break;

  case 76:
#line 644 "nidl_y.y"
    {
        yyval.y_type = AST_disc_union_node(
                         NAMETABLE_NIL_ID,      /* tag name          */
                         ASTP_tagged_union_id,  /* union name        */
                         yyvsp[-2].y_id,              /* discriminant name */
                         yyvsp[-3].y_type,            /* discriminant type */
                         yyvsp[0].y_arm );           /* the arm list      */
        }
    break;

  case 77:
#line 653 "nidl_y.y"
    {
        yyval.y_type = AST_disc_union_node(
                         yyvsp[-1].y_id,              /* tag name          */
                         NAMETABLE_NIL_ID,      /* union name        */
                         NAMETABLE_NIL_ID,      /* discriminant name */
                         NULL,                  /* discriminant type */
                         yyvsp[0].y_arm );           /* the arm list      */
        }
    break;

  case 78:
#line 662 "nidl_y.y"
    {
        yyval.y_type = AST_disc_union_node(
                         NAMETABLE_NIL_ID,      /* tag name          */
                         yyvsp[-1].y_id,              /* union name        */
                         yyvsp[-3].y_id,              /* discriminant name */
                         yyvsp[-4].y_type,            /* discriminant type */
                         yyvsp[0].y_arm );           /* the arm list      */
        }
    break;

  case 79:
#line 671 "nidl_y.y"
    {
        yyval.y_type = AST_disc_union_node(
                         yyvsp[-6].y_id,              /* tag name          */
                         ASTP_tagged_union_id,  /* union name        */
                         yyvsp[-2].y_id,              /* discriminant name */
                         yyvsp[-3].y_type,            /* discriminant type */
                         yyvsp[0].y_arm );           /* the arm list      */
        }
    break;

  case 80:
#line 680 "nidl_y.y"
    {
        yyval.y_type = AST_disc_union_node(
                         yyvsp[-7].y_id,              /* tag name          */
                         yyvsp[-1].y_id,              /* union name        */
                         yyvsp[-3].y_id,              /* discriminant name */
                         yyvsp[-4].y_type,            /* discriminant type */
                         yyvsp[0].y_arm );           /* the arm list      */
        }
    break;

  case 81:
#line 689 "nidl_y.y"
    {
            yyval.y_type = AST_type_from_tag (AST_disc_union_k, yyvsp[0].y_id);
        }
    break;

  case 82:
#line 696 "nidl_y.y"
    {
                yyval.y_arm = yyvsp[-1].y_arm;
        }
    break;

  case 83:
#line 702 "nidl_y.y"
    {
                yyval.y_arm = yyvsp[-1].y_arm;
        }
    break;

  case 85:
#line 710 "nidl_y.y"
    {
            yyval.y_arm = (AST_arm_n_t *) AST_concat_element(
                                        (ASTP_node_t *) yyvsp[-2].y_arm,
                                        (ASTP_node_t *) yyvsp[0].y_arm);
        }
    break;

  case 87:
#line 719 "nidl_y.y"
    {
            yyval.y_arm = (AST_arm_n_t *) AST_concat_element(
                                        (ASTP_node_t *) yyvsp[-2].y_arm,
                                        (ASTP_node_t *) yyvsp[0].y_arm);
        }
    break;

  case 88:
#line 728 "nidl_y.y"
    {
            yyval.y_arm = yyvsp[0].y_arm;
        }
    break;

  case 89:
#line 734 "nidl_y.y"
    {
            yyval.y_arm = AST_label_arm(yyvsp[0].y_arm, yyvsp[-1].y_label) ;
        }
    break;

  case 91:
#line 742 "nidl_y.y"
    {
            yyval.y_label = (AST_case_label_n_t *) AST_concat_element(
                                        (ASTP_node_t *) yyvsp[-2].y_label,
                                        (ASTP_node_t *) yyvsp[0].y_label);
        }
    break;

  case 93:
#line 751 "nidl_y.y"
    {
            yyval.y_label = (AST_case_label_n_t *) AST_concat_element(
                                        (ASTP_node_t *) yyvsp[-1].y_label,
                                        (ASTP_node_t *) yyvsp[0].y_label);
        }
    break;

  case 94:
#line 760 "nidl_y.y"
    {
            yyval.y_label = AST_case_label_node(yyvsp[0].y_constant);
        }
    break;

  case 95:
#line 766 "nidl_y.y"
    {
            yyval.y_label = AST_case_label_node(yyvsp[-1].y_constant);
        }
    break;

  case 96:
#line 770 "nidl_y.y"
    {
            yyval.y_label = AST_default_case_label_node();
        }
    break;

  case 97:
#line 777 "nidl_y.y"
    {
            yyval.y_arm = AST_declarator_to_arm(NULL, NULL, &yyvsp[-1].y_attributes);
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-1].y_attributes.bounds);
        }
    break;

  case 98:
#line 782 "nidl_y.y"
    {
            yyval.y_arm = AST_declarator_to_arm(yyvsp[-2].y_type,
                                yyvsp[-1].y_declarator, &yyvsp[-3].y_attributes);
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-3].y_attributes.bounds);
        }
    break;

  case 99:
#line 790 "nidl_y.y"
    {
            yyval.y_arm = AST_arm_node(NAMETABLE_NIL_ID,NULL,NULL);
        }
    break;

  case 100:
#line 794 "nidl_y.y"
    {
            if (ASTP_TEST_ATTR(&yyvsp[-3].y_attributes, ASTP_CASE))
            {
                ASTP_attr_flag_t attr1 = ASTP_CASE;
                acf_error(nidl_yylineno, NIDL_EUMEMATTR,
                      KEYWORDS_lookup_text(AST_attribute_to_token(&attr1)),
		      NULL);
            }
            if (ASTP_TEST_ATTR(&yyvsp[-3].y_attributes, ASTP_DEFAULT))
            {
                ASTP_attr_flag_t attr1 = ASTP_DEFAULT;
                acf_error(nidl_yylineno, NIDL_EUMEMATTR,
                      KEYWORDS_lookup_text(AST_attribute_to_token(&attr1)),
		      NULL);
            }
            yyval.y_arm = AST_declarator_to_arm(yyvsp[-2].y_type,
                                yyvsp[-1].y_declarator, &yyvsp[-3].y_attributes);
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-3].y_attributes.bounds);
        }
    break;

  case 101:
#line 817 "nidl_y.y"
    {
            yyval.y_type = AST_structure_node(yyvsp[-1].y_field, NAMETABLE_NIL_ID) ;
        }
    break;

  case 102:
#line 821 "nidl_y.y"
    {
            yyval.y_type = AST_structure_node(yyvsp[-1].y_field, yyvsp[-3].y_id) ;
        }
    break;

  case 103:
#line 825 "nidl_y.y"
    {
            yyval.y_type = AST_type_from_tag (AST_structure_k, yyvsp[0].y_id);
        }
    break;

  case 105:
#line 833 "nidl_y.y"
    {
            yyval.y_field = (AST_field_n_t *)AST_concat_element(
                                    (ASTP_node_t *) yyvsp[-2].y_field,
                                    (ASTP_node_t *) yyvsp[0].y_field) ;
        }
    break;

  case 106:
#line 842 "nidl_y.y"
    {
            yyval.y_field = AST_declarators_to_fields(yyvsp[-1].y_declarator,
                                                    yyvsp[-3].y_type,
                                                    &yyvsp[-4].y_attributes);
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-4].y_attributes.bounds);
        }
    break;

  case 107:
#line 852 "nidl_y.y"
    {
             yyval.y_type = AST_enumerator_node(yyvsp[0].y_constant, AST_short_integer_k);
        }
    break;

  case 108:
#line 859 "nidl_y.y"
    {
		}
    break;

  case 110:
#line 866 "nidl_y.y"
    {
            yyval.y_constant = yyvsp[-2].y_constant ;
        }
    break;

  case 112:
#line 874 "nidl_y.y"
    {
            yyval.y_constant = (AST_constant_n_t *) AST_concat_element(
                                    (ASTP_node_t *) yyvsp[-2].y_constant,
                                    (ASTP_node_t *) yyvsp[0].y_constant) ;
        }
    break;

  case 113:
#line 883 "nidl_y.y"
    {
            yyval.y_constant = AST_enum_constant(yyvsp[-1].y_id, yyvsp[0].y_exp) ;
        }
    break;

  case 114:
#line 890 "nidl_y.y"
    {
            yyval.y_type = AST_pipe_node (yyvsp[0].y_type);
        }
    break;

  case 115:
#line 897 "nidl_y.y"
    {
			 yyval.y_exp = AST_exp_integer_constant(0, true);
		}
    break;

  case 116:
#line 901 "nidl_y.y"
    {
	 		 ASTP_validate_integer(yyvsp[0].y_exp);
			 yyval.y_exp = yyvsp[0].y_exp;
		}
    break;

  case 117:
#line 909 "nidl_y.y"
    {
				yyval.y_declarator =  yyvsp[0].y_declarator;
		  }
    break;

  case 118:
#line 913 "nidl_y.y"
    {
            yyval.y_declarator = (ASTP_declarator_n_t *) AST_concat_element(
                                            (ASTP_node_t *) yyvsp[-2].y_declarator,
                                            (ASTP_node_t *) yyvsp[0].y_declarator) ;
        }
    break;

  case 119:
#line 924 "nidl_y.y"
    { yyval.y_declarator = yyvsp[0].y_declarator; }
    break;

  case 120:
#line 929 "nidl_y.y"
    { yyval.y_declarator = yyvsp[0].y_declarator; }
    break;

  case 121:
#line 931 "nidl_y.y"
    {
                yyval.y_declarator = yyvsp[0].y_declarator;
                AST_declarator_operation(yyval.y_declarator, AST_pointer_k,
                        (ASTP_node_t *)NULL, yyvsp[-1].y_ptrlevels );
            }
    break;

  case 122:
#line 940 "nidl_y.y"
    { yyval.y_ptrlevels = 1;}
    break;

  case 123:
#line 942 "nidl_y.y"
    { yyval.y_ptrlevels = yyvsp[0].y_ptrlevels + 1; }
    break;

  case 124:
#line 947 "nidl_y.y"
    { yyval.y_declarator = AST_declarator_node ( yyvsp[0].y_id ); }
    break;

  case 125:
#line 949 "nidl_y.y"
    {
                yyval.y_declarator = yyval.y_declarator;
                AST_declarator_operation(yyval.y_declarator, AST_array_k,
                        (ASTP_node_t *) yyvsp[0].y_index, 0 );
            }
    break;

  case 126:
#line 955 "nidl_y.y"
    {
            yyval.y_declarator = yyvsp[-1].y_declarator;
            }
    break;

  case 127:
#line 959 "nidl_y.y"
    {
                yyval.y_declarator = yyval.y_declarator;
                AST_declarator_operation(yyval.y_declarator, AST_function_k,
                        (ASTP_node_t *) yyvsp[0].y_parameter, 0 );
            }
    break;

  case 128:
#line 987 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node ( NULL, ASTP_default_bound,
                                                 NULL, ASTP_open_bound);
        }
    break;

  case 129:
#line 992 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node  ( NULL, ASTP_default_bound,
                                                 NULL, ASTP_open_bound);
        }
    break;

  case 130:
#line 997 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node  ( NULL, ASTP_default_bound,
                                                 yyvsp[-1].y_constant, ASTP_constant_bound);
        }
    break;

  case 131:
#line 1002 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node  ( NULL, ASTP_open_bound,
                                                 NULL, ASTP_open_bound);
        }
    break;

  case 132:
#line 1007 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node  ( NULL, ASTP_open_bound,
                                                 yyvsp[-1].y_constant, ASTP_constant_bound);
        }
    break;

  case 133:
#line 1012 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node  ( yyvsp[-3].y_constant, ASTP_constant_bound,
                                                 NULL, ASTP_open_bound);
        }
    break;

  case 134:
#line 1017 "nidl_y.y"
    {
            yyval.y_index = ASTP_array_index_node  ( yyvsp[-3].y_constant, ASTP_constant_bound,
                                                 yyvsp[-1].y_constant, ASTP_constant_bound);
        }
    break;

  case 135:
#line 1026 "nidl_y.y"
    {
            if (ASTP_parsing_main_idl)
                yyval.y_operation = AST_operation_node (
                                    yyvsp[-2].y_type,         /*The type node*/
                                    yyvsp[-1].y_declarator,   /* Declarator list */
                                   &yyvsp[-3].y_attributes);  /* attributes */
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-3].y_attributes.bounds);
        }
    break;

  case 136:
#line 1035 "nidl_y.y"
    {
        acf_error(nidl_yylineno,NIDL_MISSONOP, NULL);
        yyval.y_operation = NULL;
        }
    break;

  case 137:
#line 1043 "nidl_y.y"
    {
            yyval.y_parameter = yyvsp[-2].y_parameter;
        }
    break;

  case 138:
#line 1050 "nidl_y.y"
    {
        NAMETABLE_push_level ();
        }
    break;

  case 139:
#line 1057 "nidl_y.y"
    {
        ASTP_patch_field_reference ();
        NAMETABLE_pop_level ();
        }
    break;

  case 141:
#line 1066 "nidl_y.y"
    {
            if (ASTP_parsing_main_idl)
                yyval.y_parameter = (AST_parameter_n_t *) AST_concat_element(
                                    (ASTP_node_t *) yyvsp[-2].y_parameter,
                                    (ASTP_node_t *) yyvsp[0].y_parameter);
        }
    break;

  case 142:
#line 1073 "nidl_y.y"
    {
            yyval.y_parameter = (AST_parameter_n_t *)NULL;
        }
    break;

  case 143:
#line 1080 "nidl_y.y"
    {
            /*
             * We have to use special code here to allow (void) as a parameter
             * specification.  If there are no declarators, then we need to
             * make sure that the type is void and that there are no attributes .
             */
            if (yyvsp[0].y_declarator == NULL)
            {
                /*
                 * If the type is not void or some attribute is specified,
                 * there is a syntax error.  Force a yacc error, so that
                 * we can safely recover from the lack of a declarator.
                 */
                if ((yyvsp[-2].y_type->kind != AST_void_k) ||
                   (yyvsp[-3].y_attributes.bounds != NULL) ||
                   (yyvsp[-3].y_attributes.attr_flags != 0))
                {
                    yywhere();  /* Issue a syntax error for this line */
                    YYERROR;    /* Allow natural error recovery */
                }

                yyval.y_parameter = (AST_parameter_n_t *)NULL;
            }
            else
            {
                if (ASTP_parsing_main_idl)
                    yyval.y_parameter = AST_declarator_to_param(
                                            &yyvsp[-3].y_attributes,
                                            yyvsp[-2].y_type,
                                            yyvsp[0].y_declarator);
            }
            ASTP_free_simple_list((ASTP_node_t *)yyvsp[-3].y_attributes.bounds);
        }
    break;

  case 144:
#line 1114 "nidl_y.y"
    {
            acf_error(nidl_yylineno, NIDL_MISSONPARAM, NULL);
            yyval.y_parameter = (AST_parameter_n_t *)NULL;
        }
    break;

  case 145:
#line 1122 "nidl_y.y"
    { yyval.y_declarator = yyvsp[0].y_declarator; }
    break;

  case 146:
#line 1124 "nidl_y.y"
    { yyval.y_declarator = NULL; }
    break;

  case 147:
#line 1140 "nidl_y.y"
    {
            search_attributes_table = true;
        }
    break;

  case 148:
#line 1147 "nidl_y.y"
    {
            search_attributes_table = false;
        }
    break;

  case 149:
#line 1154 "nidl_y.y"
    {
            search_attributes_table = false;
        }
    break;

  case 150:
#line 1161 "nidl_y.y"
    {
            search_attributes_table = true;
        }
    break;

  case 151:
#line 1173 "nidl_y.y"
    {
            /* Give an error on notranslated sources */
            if ((yyvsp[0].y_attributes.bounds != NULL) ||
               (yyvsp[0].y_attributes.attr_flags != 0))
            {
                acf_error(nidl_yylineno,NIDL_ATTRTRANS, NULL);
                ASTP_free_simple_list((ASTP_node_t *)yyvsp[0].y_attributes.bounds);
            }
        }
    break;

  case 153:
#line 1194 "nidl_y.y"
    {
            acf_error(nidl_yylineno,NIDL_ERRINATTR, NULL);
        }
    break;

  case 158:
#line 1209 "nidl_y.y"
    {
            acf_error(nidl_yylineno,NIDL_SYNTAXUUID, NULL);
        }
    break;

  case 159:
#line 1213 "nidl_y.y"
    {
            {
                if (ASTP_IF_AF_SET(the_interface,ASTP_IF_UUID))
                        acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);
                ASTP_SET_IF_AF(the_interface,ASTP_IF_UUID);
                the_interface->uuid = yyvsp[0].y_uuid;
            }
        }
    break;

  case 160:
#line 1222 "nidl_y.y"
    {
            if (ASTP_IF_AF_SET(the_interface,ASTP_IF_PORT))
                    acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);
            ASTP_SET_IF_AF(the_interface,ASTP_IF_PORT);
        }
    break;

  case 161:
#line 1228 "nidl_y.y"
    {
            if (ASTP_IF_AF_SET(the_interface, ASTP_IF_EXCEPTIONS))
                acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);
            ASTP_SET_IF_AF(the_interface, ASTP_IF_EXCEPTIONS);
        }
    break;

  case 162:
#line 1234 "nidl_y.y"
    {
            {
                if (ASTP_IF_AF_SET(the_interface,ASTP_IF_VERSION))
                        acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);
                ASTP_SET_IF_AF(the_interface,ASTP_IF_VERSION);
            }

        }
    break;

  case 163:
#line 1243 "nidl_y.y"
    {
            {
                if (AST_LOCAL_SET(the_interface))
                        acf_warning(nidl_yylineno, NIDL_MULATTRDEF, NULL);
                AST_SET_LOCAL(the_interface);
            }
        }
    break;

  case 164:
#line 1251 "nidl_y.y"
    {
            if (the_interface->pointer_default != 0)
                    acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);
            the_interface->pointer_default = yyvsp[-1].y_ptrclass;
        }
    break;

  case 165:
#line 1258 "nidl_y.y"
    {
				if (AST_OBJECT_SET(the_interface))
					 acf_warning(nidl_yylineno, NIDL_MULATTRDEF, NULL);
				AST_SET_OBJECT(the_interface);
			}
    break;

  case 166:
#line 1264 "nidl_y.y"
    {
				/* complain about compat here */
			}
    break;

  case 167:
#line 1271 "nidl_y.y"
    {
		if (the_interface->implicit_handle_name != NAMETABLE_NIL_ID)
			 acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);

		ASTP_set_implicit_handle(the_interface, NAMETABLE_NIL_ID, yyvsp[-1].y_id);
	}
    break;

  case 168:
#line 1279 "nidl_y.y"
    {
		/*AST_type_n_t * type_p;*/
		if (the_interface->implicit_handle_name != NAMETABLE_NIL_ID)
			acf_error(nidl_yylineno, NIDL_ATTRUSEMULT, NULL);
	
		ASTP_set_implicit_handle(the_interface, yyvsp[-2].y_id, yyvsp[-1].y_id);
	}
    break;

  case 169:
#line 1289 "nidl_y.y"
    { yyval.y_ptrclass = ASTP_REF; }
    break;

  case 170:
#line 1290 "nidl_y.y"
    { yyval.y_ptrclass = ASTP_PTR; }
    break;

  case 171:
#line 1291 "nidl_y.y"
    { yyval.y_ptrclass = ASTP_UNIQUE; }
    break;

  case 172:
#line 1296 "nidl_y.y"
    {
            the_interface->version = yyvsp[0].y_int_info.int_val;
            if (the_interface->version > /*(unsigned int)*/ASTP_C_USHORT_MAX)
                acf_error(nidl_yylineno, NIDL_MAJORTOOLARGE,
			  ASTP_C_USHORT_MAX, NULL);
        }
    break;

  case 173:
#line 1303 "nidl_y.y"
    {
            char const *float_text;
            unsigned int            major_version,minor_version;
            STRTAB_str_to_string(yyvsp[0].y_string, &float_text);
            sscanf(float_text,"%d.%d",&major_version,&minor_version);
            if (major_version > (unsigned int)ASTP_C_USHORT_MAX)
                acf_error(nidl_yylineno, NIDL_MAJORTOOLARGE,
			  ASTP_C_USHORT_MAX, NULL);
            if (minor_version > (unsigned int)ASTP_C_USHORT_MAX)
                acf_error(nidl_yylineno, NIDL_MINORTOOLARGE,
			  ASTP_C_USHORT_MAX, NULL);
            the_interface->version = (minor_version * 65536) + major_version;
        }
    break;

  case 176:
#line 1325 "nidl_y.y"
    {
            the_interface->exceptions = yyvsp[0].y_exception;
        }
    break;

  case 177:
#line 1329 "nidl_y.y"
    {
            yyval.y_exception = (AST_exception_n_t *) AST_concat_element(
                                (ASTP_node_t *) the_interface->exceptions,
                                (ASTP_node_t *) yyvsp[0].y_exception );
        }
    break;

  case 178:
#line 1338 "nidl_y.y"
    {
            ASTP_parse_port(the_interface,yyvsp[0].y_string);
        }
    break;

  case 179:
#line 1345 "nidl_y.y"
    {
            if (ASTP_parsing_main_idl)
                yyval.y_exception = AST_exception_node(yyvsp[0].y_id);
            else
                yyval.y_exception = NULL;
        }
    break;

  case 180:
#line 1363 "nidl_y.y"
    {
            yyval.y_attributes.bounds = yyvsp[-1].y_attributes.bounds;
            yyval.y_attributes.attr_flags = 0;
        }
    break;

  case 181:
#line 1368 "nidl_y.y"
    {
            yyval.y_attributes.bounds = yyvsp[-1].y_attributes.bounds;
            yyval.y_attributes.attr_flags = 0;
        }
    break;

  case 182:
#line 1376 "nidl_y.y"
    {
            ASTP_bound_type = first_is_k;
        }
    break;

  case 183:
#line 1380 "nidl_y.y"
    {
            ASTP_bound_type = last_is_k;
        }
    break;

  case 184:
#line 1384 "nidl_y.y"
    {
            ASTP_bound_type = length_is_k;
        }
    break;

  case 185:
#line 1388 "nidl_y.y"
    {
            ASTP_bound_type = max_is_k;
        }
    break;

  case 186:
#line 1392 "nidl_y.y"
    {
            ASTP_bound_type = min_is_k;
        }
    break;

  case 187:
#line 1396 "nidl_y.y"
    {
            ASTP_bound_type = size_is_k;
        }
    break;

  case 189:
#line 1405 "nidl_y.y"
    {
        yyval.y_attributes.bounds = (ASTP_type_attr_n_t *) AST_concat_element (
                                (ASTP_node_t*) yyvsp[-2].y_attributes.bounds,
                                (ASTP_node_t*) yyvsp[0].y_attributes.bounds);
        }
    break;

  case 190:
#line 1415 "nidl_y.y"
    {
				 yyval.y_attributes.bounds = AST_array_bound_from_expr(yyvsp[0].y_exp, ASTP_bound_type);
			}
    break;

  case 191:
#line 1419 "nidl_y.y"
    {
        yyval.y_attributes.bounds = AST_array_bound_info (NAMETABLE_NIL_ID, ASTP_bound_type, FALSE);
        }
    break;

  case 192:
#line 1426 "nidl_y.y"
    {
            ASTP_bound_type = switch_is_k;
        }
    break;

  case 193:
#line 1433 "nidl_y.y"
    {
        yyval.y_attributes.bounds = AST_array_bound_info(yyvsp[0].y_id, ASTP_bound_type, FALSE);
        }
    break;

  case 194:
#line 1437 "nidl_y.y"
    {
        yyval.y_attributes.bounds = AST_array_bound_info(yyvsp[0].y_id, ASTP_bound_type, TRUE);
        }
    break;

  case 195:
#line 1447 "nidl_y.y"
    { yyval.y_attributes = yyvsp[0].y_attributes; }
    break;

  case 196:
#line 1450 "nidl_y.y"
    {
        yyval.y_attributes.bounds = NULL;
        yyval.y_attributes.attr_flags = 0;
        }
    break;

  case 198:
#line 1460 "nidl_y.y"
    {
        /*
         * Can't tell if we had any valid attributes in the list, so return
         * none.
         */
        yyval.y_attributes.bounds = NULL;
        yyval.y_attributes.attr_flags = 0;
        acf_error(nidl_yylineno, NIDL_ERRINATTR, NULL);
        }
    break;

  case 199:
#line 1470 "nidl_y.y"
    {
        /*
         * No closer to the attribute, so give a different message.
         */
        yyval.y_attributes.bounds = NULL;
        yyval.y_attributes.attr_flags = 0;
        acf_error(nidl_yylineno, NIDL_MISSONATTR, NULL);
        search_attributes_table = false;
        }
    break;

  case 200:
#line 1484 "nidl_y.y"
    { yyval.y_attributes = yyvsp[0].y_attributes; }
    break;

  case 201:
#line 1487 "nidl_y.y"
    {
          /*
           * If the same bit has been specified more than once, then issue
           * a message.
           */
          if ((yyvsp[-2].y_attributes.attr_flags & yyvsp[0].y_attributes.attr_flags) != 0)
                acf_warning(nidl_yylineno, NIDL_MULATTRDEF, NULL);
          yyval.y_attributes.attr_flags = yyvsp[-2].y_attributes.attr_flags |
                                        yyvsp[0].y_attributes.attr_flags;
          yyval.y_attributes.bounds = (ASTP_type_attr_n_t *) AST_concat_element (
                                (ASTP_node_t*) yyvsp[-2].y_attributes.bounds,
                                (ASTP_node_t*) yyvsp[0].y_attributes.bounds);
        }
    break;

  case 202:
#line 1505 "nidl_y.y"
    { yyval.y_attributes = yyvsp[0].y_attributes; }
    break;

  case 203:
#line 1508 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_BROADCAST;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 204:
#line 1510 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_MAYBE;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 205:
#line 1512 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_IDEMPOTENT;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 206:
#line 1514 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_REFLECT_DELETIONS;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 207:
#line 1516 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_LOCAL;
	                               yyval.y_attributes.bounds = NULL;       }
    break;

  case 208:
#line 1518 "nidl_y.y"
    {	}
    break;

  case 209:
#line 1521 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_PTR;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 210:
#line 1523 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_IN;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 211:
#line 1526 "nidl_y.y"
    { yyval.y_attributes.attr_flags =
                                        ASTP_IN | ASTP_IN_SHAPE;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 212:
#line 1529 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_OUT;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 213:
#line 1532 "nidl_y.y"
    { yyval.y_attributes.attr_flags =
                                        ASTP_OUT | ASTP_OUT_SHAPE;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 214:
#line 1536 "nidl_y.y"
    { yyval.y_attributes.iid_is_name = yyvsp[-1].y_id; 
                                   yyval.y_attributes.bounds = NULL;
                                   yyval.y_attributes.attr_flags = 0;
											}
    break;

  case 215:
#line 1541 "nidl_y.y"
    { yyval.y_attributes.iid_is_name = yyvsp[-1].y_id; 
                                   yyval.y_attributes.bounds = NULL;
                                   yyval.y_attributes.attr_flags = 0;
											}
    break;

  case 216:
#line 1547 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_SMALL;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 217:
#line 1549 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_STRING;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 218:
#line 1551 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_STRING0;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 219:
#line 1553 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_UNIQUE;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 220:
#line 1555 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_REF;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 221:
#line 1557 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_IGNORE;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 222:
#line 1559 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_CONTEXT;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 223:
#line 1563 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_UNALIGN;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 224:
#line 1565 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_V1_ENUM;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 225:
#line 1568 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_ALIGN_SMALL;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 226:
#line 1571 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_ALIGN_SHORT;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 227:
#line 1574 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_ALIGN_LONG;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 228:
#line 1577 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_ALIGN_HYPER;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 229:
#line 1579 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_HANDLE;
                                  yyval.y_attributes.bounds = NULL;       }
    break;

  case 230:
#line 1582 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_TRANSMIT_AS;
                                  yyval.y_attributes.bounds = NULL;
                                  ASTP_transmit_as_type = yyvsp[-1].y_type;
                                }
    break;

  case 231:
#line 1587 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_SWITCH_TYPE;
                                  yyval.y_attributes.bounds = NULL;
                                  ASTP_switch_type = yyvsp[-1].y_type;
                                }
    break;

  case 232:
#line 1594 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_CASE;
                                  yyval.y_attributes.bounds = NULL;
                                  ASTP_case = yyvsp[-1].y_label;
                                }
    break;

  case 233:
#line 1598 "nidl_y.y"
    { yyval.y_attributes.attr_flags = ASTP_DEFAULT;
                                  yyval.y_attributes.bounds = NULL;
                                }
    break;

  case 234:
#line 1602 "nidl_y.y"
    {
                char const *identifier; /* place to receive the identifier text */
                NAMETABLE_id_to_string (yyvsp[0].y_id, &identifier);
                acf_error (nidl_yylineno, NIDL_UNKNOWNATTR, identifier, NULL);
                yyval.y_attributes.attr_flags = 0;
                yyval.y_attributes.bounds = NULL;
        }
    break;

  case 235:
#line 1618 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 236:
#line 1623 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 237:
#line 1625 "nidl_y.y"
    {
	 			yyval.y_exp = AST_expression(AST_EXP_TERNARY_OP, yyvsp[-4].y_exp, yyvsp[-2].y_exp, yyvsp[0].y_exp);
        }
    break;

  case 238:
#line 1632 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 239:
#line 1634 "nidl_y.y"
    {
	 			yyval.y_exp = AST_expression(AST_EXP_BINARY_LOG_OR, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 240:
#line 1641 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 241:
#line 1643 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_LOG_AND, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 242:
#line 1650 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 243:
#line 1652 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_OR, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 244:
#line 1659 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 245:
#line 1661 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_XOR, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 246:
#line 1668 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 247:
#line 1670 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_AND, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 248:
#line 1677 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 249:
#line 1679 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_EQUAL, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 250:
#line 1683 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_NE, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);

        }
    break;

  case 251:
#line 1691 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 252:
#line 1693 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_LT, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 253:
#line 1697 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_GT, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 254:
#line 1701 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_LE, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 255:
#line 1705 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_GE, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);

        }
    break;

  case 256:
#line 1713 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 257:
#line 1715 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_LSHIFT, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 258:
#line 1719 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_RSHIFT, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);

        }
    break;

  case 259:
#line 1727 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 260:
#line 1729 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_PLUS, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);

        }
    break;

  case 261:
#line 1734 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_MINUS, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 262:
#line 1741 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 263:
#line 1743 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_STAR, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
				/*
            if (($<y_exp>$.exp.constant.val.integer < $<y_exp>1.exp.constant.val.integer) &&
                ($<y_exp>$.exp.constant.val.integer < $<y_exp>3.exp.constant.val.integer))
                acf_error (nidl_yylineno, NIDL_INTOVERFLOW,
			   KEYWORDS_lookup_text(LONG_KW), NULL);
					*/
        }
    break;

  case 264:
#line 1753 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_SLASH, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
        }
    break;

  case 265:
#line 1757 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_BINARY_PERCENT, yyvsp[-2].y_exp, yyvsp[0].y_exp, NULL);
            /*    acf_error (nidl_yylineno, NIDL_INTDIVBY0, NULL); */
        }
    break;

  case 266:
#line 1764 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 267:
#line 1769 "nidl_y.y"
    {yyval.y_exp = yyvsp[0].y_exp;}
    break;

  case 268:
#line 1771 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_UNARY_PLUS, yyvsp[0].y_exp, NULL, NULL);
		  }
    break;

  case 269:
#line 1775 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_UNARY_MINUS, yyvsp[0].y_exp, NULL, NULL);
        }
    break;

  case 270:
#line 1779 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_UNARY_TILDE, yyvsp[0].y_exp, NULL, NULL);
        }
    break;

  case 271:
#line 1783 "nidl_y.y"
    {
				yyval.y_exp = AST_expression(AST_EXP_UNARY_NOT, yyvsp[0].y_exp, NULL, NULL);
        }
    break;

  case 272:
#line 1787 "nidl_y.y"
    {
			  yyval.y_exp = AST_expression(AST_EXP_UNARY_STAR, yyvsp[0].y_exp, NULL, NULL);
		  }
    break;

  case 273:
#line 1794 "nidl_y.y"
    { yyval.y_exp = yyvsp[-1].y_exp; }
    break;

  case 274:
#line 1796 "nidl_y.y"
    {
				yyval.y_exp = AST_exp_integer_constant(
					yyvsp[0].y_int_info.int_val,
					yyvsp[0].y_int_info.int_signed);
        }
    break;

  case 275:
#line 1802 "nidl_y.y"
    {
				yyval.y_exp = AST_exp_char_constant(yyvsp[0].y_char);
        }
    break;

  case 276:
#line 1806 "nidl_y.y"
    {
			  	yyval.y_exp = AST_exp_identifier(yyvsp[0].y_id);
        }
    break;

  case 277:
#line 1810 "nidl_y.y"
    {
            yyval.y_exp = AST_exp_string_constant(yyvsp[0].y_string);
        }
    break;

  case 278:
#line 1814 "nidl_y.y"
    {
            yyval.y_exp = AST_exp_null_constant();
        }
    break;

  case 279:
#line 1819 "nidl_y.y"
    {
            yyval.y_exp = AST_exp_boolean_constant(true);
        }
    break;

  case 280:
#line 1824 "nidl_y.y"
    {
            yyval.y_exp = AST_exp_boolean_constant(false);
        }
    break;

  case 281:
#line 1828 "nidl_y.y"
    {
				yyval.y_exp = AST_exp_integer_constant(0,0);
            acf_error(nidl_yylineno, NIDL_FLOATCONSTNOSUP, NULL);
        }
    break;


    }

/* Line 1000 of yacc.c.  */
#line 3717 "nidl_y.c"

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


#line 1833 "nidl_y.y"


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

struct nidl_bisonparser_state
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


typedef struct nidl_bisonparser_state nidl_bisonparser_activation_record;

/*****************************************************************
 *
 * Basic constructors/destructors for FLEX activation states
 *
 *****************************************************************/

void *
new_nidl_bisonparser_activation_record()
  {
    return (malloc(sizeof(nidl_bisonparser_activation_record)));
  }

void
delete_nidl_bisonparser_activation_record(void * p)
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
get_current_nidl_bisonparser_activation()
  {
    nidl_bisonparser_activation_record * p;

    p = (nidl_bisonparser_activation_record * )
                new_nidl_bisonparser_activation_record();

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
set_current_nidl_bisonparser_activation(void * ptr)
  {

    nidl_bisonparser_activation_record * p =
      (nidl_bisonparser_activation_record *)ptr;

    // restore the statics


     yychar = p->yychar;
     yynerrs = p->yynerrs;
     yylval = p->yylval;


  }

void
init_new_nidl_bisonparser_activation()
  {
    // set some initial conditions for a new Bison parser state

    yynerrs = 0;

  }

/* preserve coding style vim: set tw=78 sw=3 ts=3 : */

