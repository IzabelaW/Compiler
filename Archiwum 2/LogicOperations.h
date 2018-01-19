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

extern struct Value value; 

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void equal(string a, string b) - generates assembler code for "value a is equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void equal(Value* a, Value* b){
    int line;
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        line = getNumberOfAsmInstructions();
        checkContext("LOAD", a->variable);
        checkContext("SUB", b->variable);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        checkContext("LOAD", b->variable);
        checkContext("SUB", a->variable);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 3);
        line = getNumberOfAsmInstructions();
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("SUB", 3);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        generateCodeAtAddress("LOAD", 3);
        checkContext("SUB", a->variable);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 3);
        line = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOAD", 3);
        checkContext("SUB", b->variable);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("SUB", 3);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");
    }
    else if (a->isNumber == true && b->isNumber == true){
        if (stoll(a->number) == stoll(b->number)){
            generateCode("ZERO");
            generateCode("INC");
        }
        else if (stoll(a->number) != stoll(b->number)){
            generateCode("ZERO");
        }
    }
    else if (a->isArray == true && b->isNumber == true){
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 3);
        loadArray(a);
        generateCodeAtAddress("STORE", 1);
        line = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOADI", 1);
        generateCodeAtAddress("SUB", 3);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        generateCodeAtAddress("LOAD", 3);
        generateCodeAtAddress("SUBI", 1);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC");   
    }
    else if (a->isNumber == true && b->isArray == true){
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 3);
        loadArray(b);
        generateCodeAtAddress("STORE", 1);
        line = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOAD", 3);
        generateCodeAtAddress("SUBI", 1);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        generateCodeAtAddress("LOADI", 1);
        generateCodeAtAddress("SUB", 3);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC"); 
    }
    else if (a->isArray == true && b->isVariable == true){
        loadArray(a);
        generateCodeAtAddress("STORE", 1);
        line = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOADI", 1);
        checkContext("SUB", b->variable);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("SUBI", 1);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC"); 
    }
    else if (a->isVariable == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE", 1);
        line = getNumberOfAsmInstructions();
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("SUBI", 1);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        generateCodeAtAddress("LOADI", 1);
        checkContext("SUB", a->variable);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC"); 
    }
    else if (a->isArray == true && b->isArray == true){
        loadArray(a);
        generateCodeAtAddress("STORE", 1);
        loadArray(b);
        generateCodeAtAddress("STORE", 2);
        line = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOADI", 1);
        generateCodeAtAddress("SUBI", 2);
        generateCodeAtAddress("JZERO", line+4);
        generateCodeAtAddress("JUMP", line+7);
        generateCodeAtAddress("LOADI", 2);
        generateCodeAtAddress("SUBI", 1);
        generateCodeAtAddress("JZERO", line+9);
        generateCode("ZERO");
        generateCodeAtAddress("JUMP", line+11);
        generateCode("ZERO");
        generateCode("INC"); 
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void notEqual(string a, string b) - generates assembler code for "value a is not equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void notEqual(Value* a, Value* b){
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);        
        checkContext("LOAD", a->variable);
        checkContext("SUB", b->variable);
        generateCodeAtAddress("STORE", 3);
        checkContext("LOAD", b->variable);
        checkContext("SUB", a->variable);
        generateCodeAtAddress("ADD", 3);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 3);
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("SUB", 3);
        generateCodeAtAddress("STORE", 4);
        generateCodeAtAddress("LOAD", 3);
        checkContext("SUB", a->variable);
        generateCodeAtAddress("ADD", 4);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 3);
        checkContext("SUB", b->variable);
        generateCodeAtAddress("STORE", 4);
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("SUB", 3);
        generateCodeAtAddress("ADD", 4);
    }
    else if (a->isNumber == true && b->isNumber == true){
        if (stoll(a->number) == stoll(b->number)){
            generateCode("ZERO");
        }  
        else if (stoll(a->number) != stoll(b->number)){
            generateCode("ZERO");
            generateCode("INC");
        }  
    }
    else if (a->isArray == true && b->isNumber == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE",3);
        generateCodeAtAddress("LOADI",1);
        generateCodeAtAddress("SUB",3);
        generateCodeAtAddress("STORE",4);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("SUBI",1);
        generateCodeAtAddress("ADD", 4);   
    }
    else if (a->isNumber == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE",3);
        generateCodeAtAddress("LOAD",3);
        generateCodeAtAddress("SUBI",1);
        generateCodeAtAddress("STORE",4);
        generateCodeAtAddress("LOADI",1);
        generateCodeAtAddress("SUB",3);
        generateCodeAtAddress("ADD", 4);
    }
    else if (a->isArray == true && b->isVariable == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        checkContext("SUB",b->variable);
        generateCodeAtAddress("STORE",4);
        checkContext("LOAD",b->variable);
        generateCodeAtAddress("SUBI",1);
        generateCodeAtAddress("ADD", 4);
    }
    else if (a->isVariable == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        checkContext("LOAD",a->variable);
        generateCodeAtAddress("SUBI",1);
        generateCodeAtAddress("STORE",4);
        generateCodeAtAddress("LOADI",1);
        checkContext("SUB",a->variable);
        generateCodeAtAddress("ADD", 4);
    }
    else if (a->isArray == true && b->isArray == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadArray(b);
        generateCodeAtAddress("STORE",2);
        generateCodeAtAddress("LOADI",1);
        generateCodeAtAddress("SUBI",2);
        generateCodeAtAddress("STORE",4);
        generateCodeAtAddress("LOADI",2);
        generateCodeAtAddress("SUBI",1);
        generateCodeAtAddress("ADD", 4);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void lessThan(string a, string b) - generates assembler code for "value a is less than value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void lessThan(Value* a, Value* b){
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        checkContext("LOAD", b->variable);
        checkContext("SUB", a->variable);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        checkContext("SUB", a->variable);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 3);
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("SUB", 3);
    }
    else if (a->isNumber == true && b->isNumber == true){
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 3);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("SUB", 3);
    }
    else if (a->isArray == true && b->isNumber == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isNumber == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE",3);
        generateCodeAtAddress("LOADI",1);
        generateCodeAtAddress("SUB",3);
    }
    else if (a->isArray == true && b->isVariable == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        checkContext("LOAD",b->variable);
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isVariable == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        generateCodeAtAddress("LOADI",1);
        checkContext("SUB", a->variable);
    }
    else if (a->isArray == true && b->isArray == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadArray(b);
        generateCodeAtAddress("STORE",2);
        generateCodeAtAddress("LOADI",2);
        generateCodeAtAddress("SUBI",1);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void greaterThan(string a, string b) - generates assembler code for "value a is greater than value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void greaterThan(Value* a, Value* b){
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        checkContext("LOAD", a->variable);
        checkContext("SUB", b->variable);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 3);
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("SUB", 3);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        checkContext("SUB", b->variable);
    }
    else if (a->isNumber == true && b->isNumber == true){
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 3);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("SUB", 3);
    }
    else if (a->isArray == true && b->isNumber == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE",3);
        generateCodeAtAddress("LOADI",1);
        generateCodeAtAddress("SUB",3);
    }
    else if (a->isNumber == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isArray == true && b->isVariable == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        generateCodeAtAddress("LOADI",1);
        checkContext("SUB", b->variable);
    }
    else if (a->isVariable == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        checkContext("LOAD",a->variable);
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isArray == true && b->isArray == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadArray(b);
        generateCodeAtAddress("STORE",2);
        generateCodeAtAddress("LOADI",1);
        generateCodeAtAddress("SUBI",2);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void lessEqualThan(string a, string b) - generates assembler code for "value a is less or equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void lessEqualThan(Value* a, Value* b){
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        checkContext("LOAD", b->variable);
        generateCode("INC");
        checkContext("SUB", a->variable);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number)+1);
        checkContext("SUB", a->variable);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 3);
        checkContext("LOAD", b->variable);
        generateCode("INC");
        generateCodeAtAddress("SUB", 3);
    }
    else if (a->isNumber == true && b->isNumber == true){
        if (stoll(a->number) < stoll(b->number)+1){
            generateCode("ZERO");
            generateCode("INC");
        } else if (stoll(a->number) >= stoll(b->number)+1){
            generateCode("ZERO");
        }
    }
    else if (a->isArray == true && b->isNumber == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(b->number)+1);
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isNumber == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE",3);
        generateCodeAtAddress("LOADI",1);
        generateCode("INC");
        generateCodeAtAddress("SUB",3);
    }
    else if (a->isArray == true && b->isVariable == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        checkContext("LOAD",b->variable);
        generateCode("INC");
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isVariable == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        generateCodeAtAddress("LOADI",1);
        generateCode("INC");
        checkContext("SUB", a->variable);
    }
    else if (a->isArray == true && b->isArray == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadArray(b);
        generateCodeAtAddress("STORE",2);
        generateCodeAtAddress("LOADI",2);
        generateCode("INC");
        generateCodeAtAddress("SUBI",1);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void greaterEqualThan(string a, string b) - generates assembler code for "value a is greater equal value b" condition
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void greaterEqualThan(Value* a, Value* b){
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        checkContext("LOAD", a->variable);
        generateCode("INC");
        checkContext("SUB", b->variable);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 3);
        checkContext("LOAD", a->variable);
        generateCode("INC");
        generateCodeAtAddress("SUB", 3);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number)+1);
        checkContext("SUB", b->variable);
    }
    else if (a->isNumber == true && b->isNumber == true){
        if (stoll(a->number)+1 > stoll(b->number)){
            generateCode("ZERO");
            generateCode("INC");
        } else if (stoll(a->number)+1 <= stoll(b->number)){
            generateCode("ZERO");
        }
    }
    else if (a->isArray == true && b->isNumber == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE",3);
        generateCodeAtAddress("LOADI",1);
        generateCode("INC");
        generateCodeAtAddress("SUB",3);
    }
    else if (a->isNumber == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        loadNumber(stoll(a->number)+1);
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isArray == true && b->isVariable == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        generateCodeAtAddress("LOADI",1);
        generateCode("INC");
        checkContext("SUB", b->variable);
    }
    else if (a->isVariable == true && b->isArray == true){
        loadArray(b);
        generateCodeAtAddress("STORE",1);
        checkContext("LOAD",a->variable);
        generateCode("INC");
        generateCodeAtAddress("SUBI",1);
    }
    else if (a->isArray == true && b->isArray == true){
        loadArray(a);
        generateCodeAtAddress("STORE",1);
        loadArray(b);
        generateCodeAtAddress("STORE",2);
        generateCodeAtAddress("LOADI",1);
        generateCode("INC");
        generateCodeAtAddress("SUBI",2);
    }
}

#endif