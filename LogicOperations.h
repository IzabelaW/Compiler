/**********************************************************************************************************************************************************************************************
                                                                                    LOGIC OPERATIONS
**********************************************************************************************************************************************************************************************/

/*=============================================================================================================================================================================================
                                                                            C++ Libraries & other C++ code
=============================================================================================================================================================================================*/

#ifndef LOGICOPERATIONS_H
#define LOGICOPERATIONS_H

using namespace std;
#include <stdio.h>
#include <string>

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        bool isNumber(string line) - checks if the string value is a number or not
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isNumber(string line){
    int n = line.length();
    for(int i = 0; i < n; i++)
        if(!isdigit(line[i]))
            return false;
    return true;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void equal(string a, string b) - generates assembler code for "value a is equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void equal(string a, string b){
   int line;
   if (!isNumber(a) && !isNumber(b)){
        line = getNumberOfAsmInstructions();
        checkContext("LOAD", a);
        checkContext("SUB", b);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        checkContext("LOAD", b);
        checkContext("SUB", a);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");
   }
   else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        generateCodeAtAddress("STORE", 0);
        line = getNumberOfAsmInstructions();
        checkContext("LOAD", a);
        generateCodeAtAddress("SUB", 0);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        generateCodeAtAddress("LOAD", 0);
        checkContext("SUB", a);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");
   }
   else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a));
        generateCodeAtAddress("STORE", 0);
        line = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOAD", 0);
        checkContext("SUB", b);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        checkContext("LOAD", b);
        generateCodeAtAddress("SUB", 0);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");
   }
   else if (isNumber(a) && isNumber(b)){
        if (stoll(a) == stoll(b)){
            generateCode("ZERO");
            generateCode("INC");
        }
        else if (stoll(a) != stoll(b)){
            generateCode("ZERO");
        }
   }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void notEqual(string a, string b) - generates assembler code for "value a is not equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void notEqual(string a, string b){
   if (!isNumber(a) && !isNumber(b)){
        checkContext("LOAD", a);
        checkContext("SUB", b);
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", b);
        checkContext("SUB", a);
        generateCodeAtAddress("ADD", 0);
   }
   else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", a);
        generateCodeAtAddress("SUB", 0);
        generateCodeAtAddress("STORE", 1);
        generateCodeAtAddress("LOAD", 0);
        checkContext("SUB", a);
        generateCodeAtAddress("ADD", 1);
   }
   else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a));
        generateCodeAtAddress("STORE", 0);
        checkContext("SUB", b);
        generateCodeAtAddress("STORE", 1);
        checkContext("LOAD", b);
        generateCodeAtAddress("SUB", 0);
        generateCodeAtAddress("ADD", 1);
   }
   else if (isNumber(a) && isNumber(b)){
        if (stoll(a) == stoll(b)){
            generateCode("ZERO");
        }  
        else if (stoll(a) != stoll(b)){
            generateCode("ZERO");
            generateCode("INC");
        }  
   }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void lessThan(string a, string b) - generates assembler code for "value a is less than value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void lessThan(string a, string b){
   if (!isNumber(a) && !isNumber(b)){
        checkContext("LOAD", b);
        checkContext("SUB", a);
   }
   else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        checkContext("SUB", a);
   }
   else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a));
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", b);
        generateCodeAtAddress("SUB", 0);
   }
   else if (isNumber(a) && isNumber(b)){
        loadNumber(stoll(a));
        generateCodeAtAddress("STORE", 0);
        loadNumber(stoll(b));
        generateCodeAtAddress("SUB", 0);
   }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void greaterThan(string a, string b) - generates assembler code for "value a is greater than value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void greaterThan(string a, string b){
    if (!isNumber(a) && !isNumber(b)){
        checkContext("LOAD", a);
        checkContext("SUB", b);
   }
   else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", a);
        generateCodeAtAddress("SUB", 0);
   }
   else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a));
        checkContext("SUB", b);
   }
   else if (isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        generateCodeAtAddress("STORE", 0);
        loadNumber(stoll(a));
        generateCodeAtAddress("SUB", 0);
   }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void lessEqualThan(string a, string b) - generates assembler code for "value a is less or equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void lessEqualThan(string a, string b){
    if (!isNumber(a) && !isNumber(b)){
        checkContext("LOAD", b);
        generateCode("INC");
        checkContext("SUB", a);
    }
    else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b)+1);
        checkContext("SUB", a);
    }
    else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a));
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", b);
        generateCode("INC");
        generateCodeAtAddress("SUB", 0);
    }
    else if (isNumber(a) && isNumber(b)){
        if (stoll(a) < stoll(b)+1){
            generateCode("ZERO");
            generateCode("INC");
        } else if (stoll(a) >= stoll(b)+1){
            generateCode("ZERO");
        }
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void greaterEqualThan(string a, string b) - generates assembler code for "value a is greater equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void greaterEqualThan(string a, string b){
    if (!isNumber(a) && !isNumber(b)){
        checkContext("LOAD", a);
        generateCode("INC");
        checkContext("SUB", b);
    }
    else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", a);
        generateCode("INC");
        generateCodeAtAddress("SUB", 0);
    }
    else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a)+1);
        checkContext("SUB", b);
    }
    else if (isNumber(a) && isNumber(b)){
        if (stoll(a)+1 > stoll(b)){
            generateCode("ZERO");
            generateCode("INC");
        } else if (stoll(a)+1 <= stoll(b)){
            generateCode("ZERO");
        }
    }
}

#endif