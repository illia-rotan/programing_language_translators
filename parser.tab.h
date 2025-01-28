/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 140 "parser.y"
{
    int intval;
    char* strval;
    Node* nodeptr;
}
/* Line 1529 of yacc.c.  */
#line 123 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

