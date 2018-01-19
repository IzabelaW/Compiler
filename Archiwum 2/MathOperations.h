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
    else if (a->isArray == true && b->isNumber == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE",1);
            loadNumber(stoll(b->number));
            generateCodeAtAddress("ADDI",1);
        }
    }
    else if (a->isNumber == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            loadArray(b);
            generateCodeAtAddress("STORE",1);
            loadNumber(stoll(a->number));
            generateCodeAtAddress("ADDI",1);
        }
    }
    else if (a->isArray == true && b->isVariable == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE",1);
            checkContext("LOAD", b->variable);
            generateCodeAtAddress("ADDI",1);
        }
    }
    else if (a->isVariable == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            loadArray(b);
            generateCodeAtAddress("STORE",1);
            checkContext("LOAD", a->variable);
            generateCodeAtAddress("ADDI",1);
        }
    }
    else if (a->isArray == true && b->isArray == true){
        if (arrayExists(a->arrayName) && arrayExists(b->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE",1);
            loadArray(b);
            generateCodeAtAddress("STORE",2);
            generateCodeAtAddress("LOADI",1);
            generateCodeAtAddress("ADDI",2);
        }
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
        if (stoll(a->number)-stoll(b->number) <= 0)
            generateCode("ZERO");
        else
            loadNumber(stoll(a->number)-stoll(b->number));
    }
    else if (a->isArray == true && b->isNumber == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE",1);
            loadNumber(stoll(b->number));
            generateCodeAtAddress("STORE",3);
            generateCodeAtAddress("LOADI",1);
            generateCodeAtAddress("SUB",3);
        }
    }
    else if (a->isNumber == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            loadArray(b);
            generateCodeAtAddress("STORE",1);
            loadNumber(stoll(a->number));
            generateCodeAtAddress("SUBI",1);
        }
    }
    else if (a->isArray == true && b->isVariable == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE",1);
            generateCodeAtAddress("LOADI",1);
            checkContext("SUB", b->variable);
        }
    }
    else if (a->isVariable == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            loadArray(b);
            generateCodeAtAddress("STORE",1);
            checkContext("LOAD",a->variable);
            generateCodeAtAddress("SUBI",1);
        }
    }
    else if (a->isArray == true && b->isArray == true){
        if (arrayExists(a->arrayName) && arrayExists(b->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE",1);
            loadArray(b);
            generateCodeAtAddress("STORE",2);
            generateCodeAtAddress("LOADI",1);
            generateCodeAtAddress("SUBI",2);
        }
    }
}

void multiplyValues(Value* a, Value* b){
    int startLine;
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("STORE", 4);
        
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("STORE", 4);
        
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 4);
        
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isNumber == true && b->isNumber == true){
        loadNumber(stoll(a->number) * stoll(b->number));
        return;
    }
    else if (a->isArray == true && b->isNumber == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            loadNumber(stoll(b->number));
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isNumber == true && b->isArray == true){  
        if (arrayExists(b->arrayName)){
            loadNumber(stoll(a->number));
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isArray == true && b->isVariable == true){
        if (arrayExists(a->arrayName)){
            checkIfSymbolIsAssigned(b->variable);

            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            checkContext("LOAD", b->variable);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isVariable == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            checkIfSymbolIsAssigned(a->variable);

            checkContext("LOAD", a->variable);
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isArray == true && b->isArray == true){
        if (arrayExists(a->arrayName) && arrayExists(b->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 2);
            generateCodeAtAddress("LOADI", 2);
            generateCodeAtAddress("STORE", 5);
        }
    }
        generateCode("ZERO");
        generateCodeAtAddress("STORE", 6);
        
        startLine = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOAD", 4);
        generateCodeAtAddress("JZERO", startLine + 14);
        generateCodeAtAddress("JODD", startLine + 4);
        generateCodeAtAddress("JUMP", startLine + 7);
        generateCodeAtAddress("LOAD", 6);
        generateCodeAtAddress("ADD", 5);
        generateCodeAtAddress("STORE", 6);
        generateCodeAtAddress("LOAD", 4);
        generateCode("SHR");
        generateCodeAtAddress("STORE", 4);
        generateCodeAtAddress("LOAD", 5);
        generateCode("SHL");
        generateCodeAtAddress("STORE", 5);
        generateCodeAtAddress("JUMP", startLine);
        generateCodeAtAddress("LOAD", 6);
}

void divideValues(Value* a, Value* b){
    int startLine;
    int conditionLine;
    int jzeroLine;
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("STORE", 4);
        
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("STORE", 5);           
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("STORE", 4);
        
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 4);
        
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isNumber == true && b->isNumber == true){
        loadNumber(stoll(a->number) / stoll(b->number));
        return;
    }
    else if (a->isArray == true && b->isNumber == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            loadNumber(stoll(b->number));
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isNumber == true && b->isArray == true){      
        if (arrayExists(b->arrayName)){
            loadNumber(stoll(a->number));
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isArray == true && b->isVariable == true){
        if (arrayExists(a->arrayName)){
            checkIfSymbolIsAssigned(b->variable);

            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            checkContext("LOAD", b->variable);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isVariable == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            checkIfSymbolIsAssigned(a->variable);

            checkContext("LOAD", a->variable);
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isArray == true && b->isArray == true){
        if (arrayExists(a->arrayName) && arrayExists(b->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 2);
            generateCodeAtAddress("LOADI", 2);
            generateCodeAtAddress("STORE", 5);
        }
    }
        generateCode("ZERO");
        generateCodeAtAddress("STORE", 6);
        
        generateCode("ZERO");
        generateCodeAtAddress("STORE", 7);
        
        startLine = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOAD", 4);
        generateCode("INC");
        generateCodeAtAddress("SUB", 5);
        generateCodeAtAddress("JZERO", startLine + 11);
        generateCodeAtAddress("LOAD", 7);
        generateCode("INC");
        generateCodeAtAddress("STORE", 7);
        generateCodeAtAddress("LOAD", 5);
        generateCode("SHL");
        generateCodeAtAddress("STORE", 5);
        generateCodeAtAddress("JUMP", startLine);
        generateCodeAtAddress("LOAD", 5);
        generateCode("SHR");
        generateCodeAtAddress("STORE", 5);
        
        installIdentifier("ITERATOR-DZIELENIA-k");
        string endFor = "KONIEC-DZIELENIA";
        installIdentifier(endFor);
        generateCode("ZERO");
        generateCode("INC");
        checkContext("STORE", "ITERATOR-DZIELENIA-k");
        generateCodeAtAddress("LOAD", 7);
        generateCode("INC");
        checkContext("SUB", "ITERATOR-DZIELENIA-k");
        checkContext("STORE", endFor);
        checkContext("LOAD", endFor);
        generateCodeAtAddress("JZERO", startLine + 48);
        generateCodeAtAddress("LOAD", 4);            
        generateCode("INC");            
        generateCodeAtAddress("SUB", 5);            
        generateCodeAtAddress("JZERO", startLine + 35);
        generateCodeAtAddress("LOAD", 4);            
        generateCodeAtAddress("SUB", 5);            
        generateCodeAtAddress("STORE", 4);            
        generateCodeAtAddress("LOAD", 6);
        generateCode("SHL");
        generateCode("INC");
        generateCodeAtAddress("STORE", 6);            
        generateCodeAtAddress("JUMP", startLine + 38);            
        generateCodeAtAddress("LOAD", 6);            
        generateCode("SHL");            
        generateCodeAtAddress("STORE", 6);            
        generateCodeAtAddress("LOAD", 5);            
        generateCode("SHR");            
        generateCodeAtAddress("STORE", 5);
        checkContext("LOAD", endFor);
        generateCode("DEC");
        checkContext("STORE", endFor);
        checkContext("LOAD", "ITERATOR-DZIELENIA-k");
        generateCode("INC");
        checkContext("STORE", "ITERATOR-DZIELENIA-k");
        generateCodeAtAddress("JUMP", startLine + 21);            
        generateCodeAtAddress("LOAD", 6);    
    
        deleteSymbol("ITERATOR-DZIELENIA-k");
        deleteSymbol("KONIEC-DZIELENIA");
}

void moduloValues(Value* a, Value* b){
    int startLine;
    int conditionLine;
    int jzeroLine;
    if (a->isVariable == true && b->isVariable == true){
        checkIfSymbolIsAssigned(a->variable);
        checkIfSymbolIsAssigned(b->variable);
        
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("STORE", 4);
        
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("STORE", 5);           
    }
    else if (a->isVariable == true && b->isNumber == true){
        checkIfSymbolIsAssigned(a->variable);
        
        checkContext("LOAD", a->variable);
        generateCodeAtAddress("STORE", 4);
        
        loadNumber(stoll(b->number));
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isNumber == true && b->isVariable == true){
        checkIfSymbolIsAssigned(b->variable);
        
        loadNumber(stoll(a->number));
        generateCodeAtAddress("STORE", 4);
        
        checkContext("LOAD", b->variable);
        generateCodeAtAddress("STORE", 5);
    }
    else if (a->isNumber == true && b->isNumber == true){
        loadNumber(stoll(a->number) % stoll(b->number));
        return;
    }
    else if (a->isArray == true && b->isNumber == true){
        if (arrayExists(a->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            loadNumber(stoll(b->number));
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isNumber == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            loadNumber(stoll(a->number));
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isArray == true && b->isVariable == true){
        if (arrayExists(a->arrayName)){
            checkIfSymbolIsAssigned(b->variable);

            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            checkContext("LOAD", b->variable);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isVariable == true && b->isArray == true){
        if (arrayExists(b->arrayName)){
            checkIfSymbolIsAssigned(a->variable);

            checkContext("LOAD", a->variable);
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 5);
        }
    }
    else if (a->isArray == true && b->isArray == true){
        if (arrayExists(a->arrayName) && arrayExists(b->arrayName)){
            loadArray(a);
            generateCodeAtAddress("STORE", 1);
            generateCodeAtAddress("LOADI", 1);
            generateCodeAtAddress("STORE", 4);

            loadArray(b);
            generateCodeAtAddress("STORE", 2);
            generateCodeAtAddress("LOADI", 2);
            generateCodeAtAddress("STORE", 5);
        }
    }   
        generateCode("ZERO");
        generateCodeAtAddress("STORE", 7);
        
        startLine = getNumberOfAsmInstructions();
        generateCodeAtAddress("LOAD", 4);
        generateCode("INC");
        generateCodeAtAddress("SUB", 5);
        generateCodeAtAddress("JZERO", startLine + 11);
        generateCodeAtAddress("LOAD", 7);
        generateCode("INC");
        generateCodeAtAddress("STORE", 7);
        generateCodeAtAddress("LOAD", 5);
        generateCode("SHL");
        generateCodeAtAddress("STORE", 5);
        generateCodeAtAddress("JUMP", startLine);
        generateCodeAtAddress("LOAD", 5);
        generateCode("SHR");
        generateCodeAtAddress("STORE", 5);
        
        installIdentifier("ITERATOR-DZIELENIA-k");
        string endFor = "KONIEC-DZIELENIA";
        installIdentifier(endFor);
        generateCode("ZERO");
        generateCode("INC");
        checkContext("STORE", "ITERATOR-DZIELENIA-k");
        generateCodeAtAddress("LOAD", 7);
        generateCode("INC");
        checkContext("SUB", "ITERATOR-DZIELENIA-k");
        checkContext("STORE", endFor);
        checkContext("LOAD", endFor);
        generateCodeAtAddress("JZERO", startLine + 40);
        generateCodeAtAddress("LOAD", 4);            
        generateCode("INC");            
        generateCodeAtAddress("SUB", 5);            
        generateCodeAtAddress("JZERO", startLine + 30);
        generateCodeAtAddress("LOAD", 4);            
        generateCodeAtAddress("SUB", 5);            
        generateCodeAtAddress("STORE", 4);                       
        generateCodeAtAddress("LOAD", 5);            
        generateCode("SHR");            
        generateCodeAtAddress("STORE", 5);
        checkContext("LOAD", endFor);
        generateCode("DEC");
        checkContext("STORE", endFor);
        checkContext("LOAD", "ITERATOR-DZIELENIA-k");
        generateCode("INC");
        checkContext("STORE", "ITERATOR-DZIELENIA-k");
        generateCodeAtAddress("JUMP", startLine + 21);            
        generateCodeAtAddress("LOAD", 4);    
    
        deleteSymbol("ITERATOR-DZIELENIA-k");
        deleteSymbol("KONIEC-DZIELENIA");
}

#endif