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




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 209 "acf_y.y"
typedef union YYSTYPE {
    NAMETABLE_id_t  y_id;       /* Identifier */
    STRTAB_str_t    y_string;   /* Text string */
} YYSTYPE;
/* Line 1275 of yacc.c.  */
#line 110 "acf_y.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE acf_yylval;



