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
                    
\n.*                { 
                        strcpy(linebuff, yytext+1);                        
                        yyless(1);
                    }
                    
{DIGIT}+            {
                        if (!comment){
                            yylval.string = (yytext);
                            return NUM;
                        }
                    }
                    
":="                { if (!comment) return ASSIGN;                                 }
"="                 { if (!comment) return EQUAL;                                  }
"<>"                { if (!comment) return NOT_EQUAL;                              }
"<"                 { if (!comment) return LESS;                                   }
">"                 { if (!comment) return GREATER;                                }
"<="                { if (!comment) return LESS_EQUAL;                             }
">="                { if (!comment) return GREATER_EQUAL;                          }
"["                 { if (!comment) return *yytext;                                }
"]"                 { if (!comment) return *yytext;                                }
"+"                 { if (!comment) return *yytext;                                }
"-"                 { if (!comment) return *yytext;                                }
"*"                 { if (!comment) return *yytext;                                }
";"                 { if (!comment) return *yytext;                                }
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
{ID}                {
                        if (!comment){
                            yylval.string = (char*) strdup(yytext);
                            return PIDENTIFIER;
                        }
                    }
[ \t]+              ;
.                   { if (!comment) printf("ERROR\n");                                  }
%%
