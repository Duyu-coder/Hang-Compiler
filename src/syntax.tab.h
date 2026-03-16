/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOK_ID = 258,                  /* TOK_ID  */
    TOK_INT = 259,                 /* TOK_INT  */
    TOK_FLOAT = 260,               /* TOK_FLOAT  */
    TOK_TRUE = 261,                /* TOK_TRUE  */
    TOK_FALSE = 262,               /* TOK_FALSE  */
    TOK_INT_TYPE = 263,            /* TOK_INT_TYPE  */
    TOK_FLOAT_TYPE = 264,          /* TOK_FLOAT_TYPE  */
    TOK_BOOL_TYPE = 265,           /* TOK_BOOL_TYPE  */
    TOK_HANG = 266,                /* TOK_HANG  */
    TOK_IN = 267,                  /* TOK_IN  */
    TOK_OUT = 268,                 /* TOK_OUT  */
    TOK_WHEN = 269,                /* TOK_WHEN  */
    TOK_ADD = 270,                 /* TOK_ADD  */
    TOK_SUB = 271,                 /* TOK_SUB  */
    TOK_MUL = 272,                 /* TOK_MUL  */
    TOK_DIV = 273,                 /* TOK_DIV  */
    TOK_ASSIGN = 274,              /* TOK_ASSIGN  */
    TOK_FEN = 275,                 /* TOK_FEN  */
    TOK_DOU = 276,                 /* TOK_DOU  */
    TOK_LY = 277,                  /* TOK_LY  */
    TOK_RY = 278,                  /* TOK_RY  */
    TOK_LH = 279,                  /* TOK_LH  */
    TOK_RH = 280,                  /* TOK_RH  */
    TOK_ERROR = 281,               /* TOK_ERROR  */
    TOK_GT = 282,                  /* TOK_GT  */
    TOK_LT = 283,                  /* TOK_LT  */
    TOK_GE = 284,                  /* TOK_GE  */
    TOK_LE = 285,                  /* TOK_LE  */
    TOK_EQ = 286,                  /* TOK_EQ  */
    TOK_NE = 287                   /* TOK_NE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "syntax.y"

    char* string_value;
    ASTNode* node;

#line 101 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
