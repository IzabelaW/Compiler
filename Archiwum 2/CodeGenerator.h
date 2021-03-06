/**********************************************************************************************************************************************************************************************
                                                                                    CODE GENERATOR
**********************************************************************************************************************************************************************************************/

/*=============================================================================================================================================================================================
                                                                            C++ Libraries & other C++ code
=============================================================================================================================================================================================*/

#ifndef CODEGENERATOR_H
#define CODEGENERATOR_H

using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <stack>

vector<string> code;

stack<int> ifStack;
stack<int> whileStack;
stack<int> forStack;

extern struct Value value; 

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                        void generateCodeAtAddress(string asmCodeOperation, int address) - generates assembler code with memory address
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void generateCodeAtAddress(string asmCodeOperation, int address) {
    code.push_back(asmCodeOperation + " " + to_string(address) + "\n");
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void generateCode(string asmCodeOperation) - generates assembler code without memory address
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void generateCode(string asmCodeOperation){
    code.push_back(asmCodeOperation + "\n");
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    void checkContext(string asmCodeOperation, string symbolName) - generates assembler code with memory address of previoulsy delared symbol or prints error if symbol wasn't declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void checkContext(string asmCodeOperation, string symbolName){
    if(symbolExists(symbolName)){
        generateCodeAtAddress(asmCodeOperation, getSymbol(symbolName));
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void changeCodeAtLine(string newCode, int line) - changes assembler code at concrete line
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void changeCodeAtLine(string newCode, int line){
    code[line] = newCode;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    int getNumberOfAsmInstructions() - returns number of assembler instructions
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int getNumberOfAsmInstructions(){
    return code.size();
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void pushOnIntStack() - pushes number of actual line of assembler instruction to IF stack
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void pushOnIntStack(){
    ifStack.push(code.size());
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            int popFromIntStack() - returns value from the top of INT stack
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int popFromIntStack(){
    int top = ifStack.top();
    ifStack.pop();
    return top;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void pushOnWhileStack() - pushes number of actual line of assembler instruction to WHILE stack
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void pushOnWhileStack(){
    whileStack.push(code.size());
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            int popFromWhileStack() - returns value from the top of WHILE stack
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int popFromWhileStack(){
    int top = whileStack.top();
    whileStack.pop();
    return top;
}

void pushOnForStack(){
    forStack.push(code.size());
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            int popFromWhileStack() - returns value from the top of WHILE stack
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int popFromForStack(){
    int top = forStack.top();
    forStack.pop();
    return top;
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            void loadNumber(long long number) - builds a binary representation of the number with assembler code
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void loadNumber(long long number){
    if (number == 0){
        generateCode("ZERO");
    }
    else if (number == 1){
        generateCode("ZERO");
        generateCode("INC");
    }
    else {
        deque<int> binaryRepresentation;
        while (number != 0){
            binaryRepresentation.push_front(number % 2);
            number = number / 2;
        }
        generateCode("ZERO");
        generateCode("INC");
        for (long long i = 1; i < binaryRepresentation.size(); i++){
            if(binaryRepresentation[i] == 1){
                generateCode("SHL");
                generateCode("INC");
            } else if(binaryRepresentation[i] == 0)
                generateCode("SHL");
        }
    }
}

void loadArray(Value* array){
    if(array->isVariableIterator == true){
        checkContext("LOAD", array->arrayName);
        checkContext("ADD", array->variableIterator);
    }
    else if (array->isConstantIterator == true){
        long long firstAddress = getSymbol(array->arrayName);
        loadNumber(firstAddress + array->constantIterator + 1);
    }   
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            void printCode() - prints finished assembler code of the user program
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void printCode(){
    for(int i = 0; i < code.size(); i++)
        cout << code[i] << endl;
}

#endif
