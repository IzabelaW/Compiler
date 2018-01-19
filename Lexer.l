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
#include <iostream>
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
                    
{DIGIT}+            {
                        yylval.string = (yytext);
                        return NUM;
                    }
                    
\([^)]*[)\n]        {  /* do nothing */                              }
                    
":="                { return ASSIGN;                                 }
"="                 { return EQUAL;                                  }
"<>"                { return NOT_EQUAL;                              }
"<"                 { return LESS;                                   }
">"                 { return GREATER;                                }
"<="                { return LESS_EQUAL;                             }
">="                { return GREATER_EQUAL;                          }
"["                 { return *yytext;                                }
"]"                 { return *yytext;                                }
"+"                 { return *yytext;                                }
"-"                 { return *yytext;                                }
"*"                 { return *yytext;                                }
"/"                 { return *yytext;                                }
"%"                 { return *yytext;                                }
";"                 { return *yytext;                                }
VAR                 { return VAR;                                    }
BEGIN               { return BEGIN_PROGRAM;                          }
END                 { return END;                                    }
READ                { return READ;                                   }
WRITE               { return WRITE;                                  }
IF                  { return IF;                                     }
THEN                { return THEN;                                   }
ELSE                { return ELSE;                                   }
ENDIF               { return ENDIF;                                  }
WHILE               { return WHILE;                                  }
DO                  { return DO;                                     }
ENDWHILE            { return ENDWHILE;                               }
FOR                 { return FOR;                                    }
FROM                { return FROM;                                   }
TO                  { return TO;                                     }
DOWNTO              { return DOWNTO;                                 }
ENDFOR              { return ENDFOR;                                 }

{ID}                {
                        yylval.string = (char*) strdup(yytext);
                        return PIDENTIFIER;
                    }
[ \t]+              ;
.                   { cerr<<"Unknown character " << yytext <<endl;   }
%%
