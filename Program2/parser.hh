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

#ifndef YY_YY_PARSER_HH_INCLUDED
# define YY_YY_PARSER_HH_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 17 "parser.y"

  #include "tree_node.h"

#line 53 "parser.hh"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    ID = 265,                      /* ID  */
    INT_LIT = 266,                 /* INT_LIT  */
    FP_LIT = 267,                  /* FP_LIT  */
    CHAR_LIT = 268,                /* CHAR_LIT  */
    STRING_LIT = 269,              /* STRING_LIT  */
    EQUAL = 270,                   /* EQUAL  */
    PLUS = 271,                    /* PLUS  */
    MINUS = 272,                   /* MINUS  */
    STAR = 273,                    /* STAR  */
    FORWARD_SLASH = 274,           /* FORWARD_SLASH  */
    EQUAL_EQUAL = 275,             /* EQUAL_EQUAL  */
    NOT_EQUAL = 276,               /* NOT_EQUAL  */
    LESS_THAN = 277,               /* LESS_THAN  */
    LESS_THAN_OR_EQUAL = 278,      /* LESS_THAN_OR_EQUAL  */
    GREATER_THAN = 279,            /* GREATER_THAN  */
    GREATER_THAN_OR_EQUAL = 280,   /* GREATER_THAN_OR_EQUAL  */
    AND = 281,                     /* AND  */
    OR = 282,                      /* OR  */
    COMMA = 283,                   /* COMMA  */
    SEMICOLON = 284,               /* SEMICOLON  */
    OPEN_PARANTHESIS = 285,        /* OPEN_PARANTHESIS  */
    CLOSE_PARANTHESIS = 286,       /* CLOSE_PARANTHESIS  */
    OPEN_BRACE = 287,              /* OPEN_BRACE  */
    CLOSE_BRACE = 288,             /* CLOSE_BRACE  */
    THEN = 289                     /* THEN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef tree_node * YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HH_INCLUDED  */
