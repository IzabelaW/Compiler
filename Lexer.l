/*******************************************************************************
                                SCANNER
*******************************************************************************/
%{
/*==============================================================================
                     C - libraries and Token definitions
==============================================================================*/
#define YYSTYPE std::string
#include <string>
#include <string.h> // for strdup
#include <stdlib.h> // for atoi
#include "Parser.tab.h" // for token definitions and yyval

bool comment = false;
%}

%option noyywrap
%option yylineno
/*==============================================================================
                   C - libraries and Token definitions
==============================================================================*/
DIGIT                [0-9]
ID                   [_a-z]+
/*==============================================================================
               Regular expressions defining the tokens
==============================================================================*/
%%
[ \t\n\r]            ;
\(                   {
                     if (comment)
                       printf("Zagnieżdżone komentarze są niedozwolone!\n");
                     else
                       comment = true;
                     }
\)                   {
                     if (!comment)
                       printf("Rozpoznano znak końca komentarza bez znaku jego rozpoczęcia!\n");
                     else
                       comment = false;
                     }
{DIGIT}+             {
                     if (!comment){
                       yylval = (yytext);
                       return NUM;
                     }
                     }
{ID}                 {
                     if (!comment){
                        yylval = (yytext);
                        return PIDENTIFIER;
                     }
                     }
"["                  { if (!comment) return LEFT_SQUARE_BRACKET;                    }
"]"                  { if (!comment) return RIGHT_SQUARE_BRACKET;                   }
";"                  { if (!comment) return SEMICOLON;                              }
":="                 { if (!comment) return ASSIGN;                                 }
"+"                  { if (!comment) return ADD;                                    }
"-"                  { if (!comment) return SUB;                                    }
"<"                  { if (!comment) return LESS;                                   }
"<="                 { if (!comment) return LESS_EQUAL;                             }
">"                  { if (!comment) return GREATER;                                }
">="                 { if (!comment) return GREATER_EQUAL;                          }
"="                  { if (!comment) return EQUAL;                                  }
"<>"                 { if (!comment) return NOT_EQUAL;                              }
VAR                  { if (!comment) return VAR;                                    }
BEGIN                { if (!comment) return BEGIN_PROGRAM;                          }
END                  { if (!comment) return END;                                    }
READ                 { if (!comment) return READ;                                   }
WRITE                { if (!comment) return WRITE;                                  }
IF                   { if (!comment) return IF;                                     }
THEN                 { if (!comment) return THEN;                                   }
ELSE                 { if (!comment) return ELSE;                                   }
ENDIF                { if (!comment) return ENDIF;                                  }
WHILE                { if (!comment) return WHILE;                                  }
DO                   { if (!comment) return DO;                                     }
ENDWHILE             { if (!comment) return ENDWHILE;                               }
.                    { if (!comment) printf("Nieprawidłowy znak!\n");               }
%%
