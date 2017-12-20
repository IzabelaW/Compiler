/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    PIDENTIFIER = 259,
    SEMICOLON = 260,
    ASSIGN = 261,
    LEFT_SQUARE_BRACKET = 262,
    RIGHT_SQUARE_BRACKET = 263,
    VAR = 264,
    BEGIN_PROGRAM = 265,
    END = 266,
    INVALID_NUM = 267,
    INVALID_SYMBOL = 268,
    READ = 269,
    WRITE = 270,
    ADD = 271,
    SUB = 272,
    EQUAL = 273,
    NOT_EQUAL = 274,
    LESS = 275,
    LESS_EQUAL = 276,
    GREATER = 277,
    GREATER_EQUAL = 278,
    IF = 279,
    THEN = 280,
    ELSE = 281,
    ENDIF = 282,
    WHILE = 283,
    DO = 284,
    ENDWHILE = 285,
    FOR = 286,
    FROM = 287,
    TO = 288,
    DOWNTO = 289,
    ENDFOR = 290,
    ERROR = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "Parser.y" /* yacc.c:1915  */

    struct Value* value;
    char* string;
		//Identifier* identifier;
		//Command* command;

#line 98 "Parser.tab.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
