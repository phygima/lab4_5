//
//  binaryStr.h
//  labb
//
//  Created by Виктория Гладкова on 14.11.2022.
//

#ifndef BinaryStr_h
#define BinaryStr_h


#include <iostream>
#include "String.h"


class BinaryStr:public String
{
public:
    //defult constructor
    BinaryStr();
    
    //copy
    BinaryStr(const char* str);
    
    //destructor
    ~BinaryStr();
    
    
    void setBinStr(char* str);
    char* getBinStr();

    int BinstrToInt();
     
    char* IntToDecstr(int value);
    
    
protected:
    char* binStr;
    
};

#endif /* BinaryStr_h */
