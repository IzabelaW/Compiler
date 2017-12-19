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
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                    void addValues(string a, string b) - generates assembler code for adding two values 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void addValues(string a, string b){
   if (!isNumber(a) && !isNumber(b)){
        checkContext("LOAD", a);
        checkContext("ADD", b);
   }
   else if (!isNumber(a) && isNumber(b)){
        loadNumber(stoll(b));
        checkContext("ADD", a);
   }
   else if (isNumber(a) && !isNumber(b)){
        loadNumber(stoll(a));
        checkContext("ADD", b);
   }
   else if (isNumber(a) && isNumber(b)){
        loadNumber(stoll(a));
        generateCodeAtAddress("STORE", 0);
        loadNumber(stoll(b));
        generateCodeAtAddress("ADD", 0);
   }
}

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                                                void subValues(string a, string b) - generates assembler code for subtraction of two values 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void subValues(string a, string b){
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

#endif