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


unordered_map<string,int> symbolMap;
unordered_map<string,bool> assignedSymbolMap;
int offset = 10;

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
    pair<string,int> symbol (name, offset);
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
   else{
        string errorStr = "Zmienna " + symbolName + " jest już zadeklarowana!";
        const char* error = errorStr.c_str();
        yyerror(error);
   }
}

#endif
