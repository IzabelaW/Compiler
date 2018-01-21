/**********************************************************************************************************************************************************************************************
                                                                                    SYMBOL MAP
**********************************************************************************************************************************************************************************************/

/*=============================================================================================================================================================================================
                                                                            C++ Libraries & other C++ code
=============================================================================================================================================================================================*/

#ifndef SYMBOLMAP_H
#define SYMBOLMAP_H

using namespace std;
#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
extern struct Value value;


unordered_map<string,long long> symbolMap;
unordered_map<string,bool> assignedSymbolMap;
unordered_map<string,Value*> declaredSymbols;

long long offset = 10;

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                       void yyerror(const char* error) - generates errors with number of line
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void yyerror (const char *error){
    extern int yylineno;
    extern char linebuff[500];
    cerr << "Błąd w linii " <<yylineno << ": " << error << "\n" << linebuff << "\n";
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                void putSymbol(string name) - puts symbol to symbolMap
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void putSymbol(string name){
    pair<string,long long> symbol (name, offset);
    symbolMap.insert(symbol);
    offset++;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            int getSymbol(string name) - return address of symbol by its name
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int getSymbol(string name){
    return symbolMap.at(name);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            void deleteSymbol(string name) - delete symbol from symbolMap
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void deleteSymbol(string name){
    symbolMap.erase(name);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                            bool symbolExists(string name) - checks if symbol was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool symbolExists(string name){
    if (symbolMap.find(name) == symbolMap.end())
        return false;
    else
        return true;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void checkIfSymbolIsDeclared(string symbolName) - checks if symbol was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void checkIfSymbolIsDeclared(string symbolName){
    if (!symbolExists(symbolName)){
        string errorStr = "Użycie niezadeklarowanej zmiennej " + symbolName + "!";
        const char* error = errorStr.c_str();
        yyerror(error);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                        void assignSymbol(string symbolName) - notes that symbol was already assigned
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void assignSymbol(string symbolName){
    pair<string,bool> symbol (symbolName, true);
    assignedSymbolMap.insert(symbol);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                            bool wasAssigned(string symbolName) - returns true if symbol was already assigned and false otherwise
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool wasAssigned(string symbolName){
    if (assignedSymbolMap.find(symbolName) == assignedSymbolMap.end())
        return false;
    else
        return true;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void checkIfSymbolIsAssigned(string symbolName) - checks if symbol was already assigned
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void checkIfSymbolIsAssigned(string symbolName){
    if (!wasAssigned(symbolName)){
        string errorStr = "Użycie niezainicjowanej zmiennej " + symbolName + "!";
        const char* error = errorStr.c_str();
        yyerror(error);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void installIdentifier(string symbolName) - puts symbol to symbolMap if it wasn't already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void installIdentifier(string symbolName){
   if(!symbolExists(symbolName)){
        putSymbol(symbolName);
   }
   else {
        string errorStr = "Zmienna " + symbolName + " jest już zadeklarowana!";
        const char* error = errorStr.c_str();
        yyerror(error);
   }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                bool arrayExists(string arrayName) - checks if array was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool arrayExists(string arrayName){
    if (symbolMap.find(arrayName) == symbolMap.end())
        return false;
    else
        return true;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                                void putArray(string arrayName, long long arraySize) - puts array to symbolMap
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void putArray(string arrayName, long long arraySize){
    pair<string,long long> array (arrayName, offset);
    symbolMap.insert(array);
    offset = offset + arraySize + 1;
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void installArray(string arrayName, long long arraySize) - puts array to symbolMap if it wasn't already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void installArray(string arrayName, long long arraySize){
    if(!arrayExists(arrayName)){
        putArray(arrayName, arraySize);
    }
    else {
        string errorStr = "Tablica " + arrayName + " jest już zadeklarowana!";
        const char* error = errorStr.c_str();
        yyerror(error);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void checkIfArrayIsDeclared(string arrayName) - checks if array was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void checkIfArrayIsDeclared(string arrayName){
    if (!arrayExists(arrayName)){
        string errorStr = "Użycie niezadeklarowanej tablicy " + arrayName + "!";
        const char* error = errorStr.c_str();
        yyerror(error);
    }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void declareSymbol(string symbolName, Value* symbol) - notes that symbol was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void declareSymbol(string symbolName, Value* symbol){
    pair<string,Value*> declaredSymbol (symbolName, symbol);
    declaredSymbols.insert(declaredSymbol);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void undeclareSymbol(string symbolName) - denotes that symbol was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void undeclareSymbol(string symbolName){
    declaredSymbols.erase(symbolName);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    Value* getDeclaredSymbol(string symbolName) - returns declared symbol
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

Value* getDeclaredSymbol(string symbolName){
    return declaredSymbols.at(symbolName);
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    bool isDeclared(string symbolName) - checks if symbol was already declared
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

bool isDeclared(string symbolName){
    if (declaredSymbols.find(symbolName) == declaredSymbols.end())
        return false;
    else
        return true;
}
#endif