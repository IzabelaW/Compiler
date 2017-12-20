/**********************************************************************************************************************************************************************************************
                                                                                    MATH OPERATIONS
**********************************************************************************************************************************************************************************************/

/*=============================================================================================================================================================================================
                                                                            C++ Libraries & other C++ code
=============================================================================================================================================================================================*/

#ifndef MATHOPERATIONS_H
#define MATHOPERATIONS_H

using namespace std;
#include <stdio.h>
#include <string>

extern struct Value value; 
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void addValues(string a, string b) - generates assembler code for adding two values 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void addValues(Value* a, Value* b){
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        checkContext("LOAD", a->variable);
        checkContext("ADD", b->variable);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        checkContext("ADD", a->variable);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        checkContext("ADD", b->variable);
    }
    else if (a->isNumber == true && b->isNumber == true){
        loadNumber(stoll(a->number)+stoll(b->number));
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void subValues(string a, string b) - generates assembler code for subtraction of two values 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void subValues(Value* a, Value* b){
   if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        checkContext("LOAD", a->variable);
        checkContext("SUB", b->variable);
   }
   else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 0);
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("SUB", 0);
   }
   else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        loadNumber(stoll(a->number));
        checkContext("SUB", b->variable);
   }
   else if (a->isNumber == true && b->isNumber == true){
        if (stoll(a->number)-stoll(b->number) <= 0)
            generateCode("ZERO");
        else
            loadNumber(stoll(a->number)-stoll(b->number));
   }
}

#endif