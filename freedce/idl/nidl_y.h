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
/* Line 1275 of yacc.c.  */
#line 292 "nidl_y.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE nidl_yylval;



