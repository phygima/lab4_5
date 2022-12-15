//
//  AbstractEcoder.hpp
//  labb
//
//  Created by Виктория Гладкова on 15.12.2022.
//

#ifndef AbstractEcoder_hpp
#define AbstractEcoder_hpp

#include <stdio.h>
#include "String.h"
#include "MyException.hpp"

class AbstractEncoder
{
public:
    AbstractEncoder(); //default constructor


    AbstractEncoder(const char* str); //constructor with parameter


    AbstractEncoder(const String& other); //copy constructor


    ~AbstractEncoder(); //destructor

    virtual void encode() = 0; //virtual string encoding method
    virtual void decode() = 0;

    //encoded string output method
    char* getEncStr();

    //decoded string output method
    char* getDecStr();

    //metod cStr()
    char* cStr();

    char getElement(int indexE);

    char* getSubStr(int start, int len);

    char* erase(int start, int len);

    char* getStrchr(char ch);

    AbstractEncoder& operator=(const AbstractEncoder& other);
    
    void writeBin(const char* FileName, int pos);

    void readBin(const char* FileName, int pos);
    
    char operator[] ( int index);
    
    


protected:
    String str; //input string field
    String encStr; //encoded string field
    String decStr; //decoded string field
    int length; //string length field

private:
    
};

#endif /* AbstractEcoder_hpp */
