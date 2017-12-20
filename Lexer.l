%{
/**********************************************************************************************************************************************************************************************
                                                                                    SCANNER
**********************************************************************************************************************************************************************************************/

/*=============================================================================================================================================================================================
                                                                        C++ libraries & other C++ code
=============================================================================================================================================================================================*/

using namespace std;
#include <string>
#include <string.h>
#include <stdlib.h>
#include "Parser.tab.h"

bool comment = false;
char linebuff[500];
%}

%option noyywrap
%option yylineno

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                            Tokens definitions
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

DIGIT               [0-9]
ID                  [_a-z]+

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                            Regular expressions defining the tokens
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

%%
\n.*                { 
                        strcpy(linebuff, yytext+1);                        
                        yyless(1);
                    }
[ \t\n\r]           ;

\(                  {
                        if (comment)
                            printf("Zagnieżdżone komentarze są niedozwolone!\n");
                        else
                            comment = true;
                    }
                    
\)                  {
                        if (!comment)
                            printf("Rozpoznano znak końca komentarza bez znaku jego rozpoczęcia!\n");
                        else
                            comment = false;
                    }
                    				
-{DIGIT}+		    {   if (!comment) return INVALID_NUM; }

[_a-z]+[0-9]+       {   if(!comment) return INVALID_SYMBOL; }

{DIGIT}+            {
                        if (!comment){
                            yylval.string = (yytext);
                            return NUM;
                        }
                    }
                    
{ID}                {
                        if (!comment){
                            yylval.string = (yytext);
                            return PIDENTIFIER;
                        }
                    }
                    
"["                 { if (!comment) return LEFT_SQUARE_BRACKET;                    }
"]"                 { if (!comment) return RIGHT_SQUARE_BRACKET;                   }
";"                 { if (!comment) return SEMICOLON;                              }
":="                { if (!comment) return ASSIGN;                                 }
"+"                 { if (!comment) return ADD;                                    }
"-"                 { if (!comment) return SUB;                                    }
"<"                 { if (!comment) return LESS;                                   }
"<="                { if (!comment) return LESS_EQUAL;                             }
">"                 { if (!comment) return GREATER;                                }
">="                { if (!comment) return GREATER_EQUAL;                          }
"="                 { if (!comment) return EQUAL;                                  }
"<>"                { if (!comment) return NOT_EQUAL;                              }
VAR                 { if (!comment) return VAR;                                    }
BEGIN               { if (!comment) return BEGIN_PROGRAM;                          }
END                 { if (!comment) return END;                                    }
READ                { if (!comment) return READ;                                   }
WRITE               { if (!comment) return WRITE;                                  }
IF                  { if (!comment) return IF;                                     }
THEN                { if (!comment) return THEN;                                   }
ELSE                { if (!comment) return ELSE;                                   }
ENDIF               { if (!comment) return ENDIF;                                  }
WHILE               { if (!comment) return WHILE;                                  }
DO                  { if (!comment) return DO;                                     }
ENDWHILE            { if (!comment) return ENDWHILE;                               }
FOR                 { if (!comment) return FOR;                                    }
FROM                { if (!comment) return FROM;                                   }
TO                  { if (!comment) return TO;                                     }
DOWNTO              { if (!comment) return DOWNTO;                                 }
ENDFOR              { if (!comment) return ENDFOR;                                 }
.                   { if (!comment) return ERROR;                                  }
%%
