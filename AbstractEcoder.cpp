//
//  AbstractEcoder.cpp
//  labb
//
//  Created by Виктория Гладкова on 15.12.2022.
//

#include "AbstractEcoder.hpp"

#include <stdio.h>
#include <memory>
#include "String.h"


AbstractEncoder::AbstractEncoder()
{
    str = nullptr;
    length = 0;
}

//constructor with parameter
AbstractEncoder::AbstractEncoder(const char* accStr)
{
    str = String(accStr);
    length = str.lengthStr();
    encStr = str;
    decStr = str;
}

//copy constructor
AbstractEncoder::AbstractEncoder(const String& other)
{
    this->str = String(other);
    length = this->str.lengthStr();
    encStr = this->str;
    decStr = this->str;
}

AbstractEncoder::~AbstractEncoder() //destructor
{

}


//encoded string output method
char* AbstractEncoder::getEncStr()
{
    return encStr.getString();
}

//decoded string output method
char* AbstractEncoder::getDecStr()
{
    return decStr.getString();
}

//metod cStr()
char* AbstractEncoder::cStr()
{
    char* ch = new char[length + 1];
    int i;
    for (i = 0; i < length; i++) {
        ch[i] = str[i];
    }
    ch[i] = '\0';
    return ch;
}

char AbstractEncoder::getElement(int indexE) //Vika's method
{
    return str.getElement(indexE);;
}

char* AbstractEncoder::getSubStr(int start, int len) //Vika's method
{
    return str.getSubStr(start, len);
}

char* AbstractEncoder::erase(int start, int len) //Vika's method
{
    int size = strlen(getSubStr(start, len));
    return str.getErase(start, len);
}

char* AbstractEncoder::getStrchr(char ch) //Vika's method
{
    return str.getStrchr(str.cStr(), ch);
}

AbstractEncoder& AbstractEncoder::operator=(const AbstractEncoder& other)
{
    String tmpStr;

    this->str = tmpStr.cStr();

    length = strlen(tmpStr.cStr());
    this->str = new char[length + 1];

    for (int i = 0; i < length; i++)
    {
        this->str[i] = tmpStr[i];
    }

    this->str[length] = '\0';

    return *this;
}



void AbstractEncoder::writeBin(const char* FileName, int pos)
{

    ofstream fout(FileName, ios::binary | ios::out);
    if (!fout)
        throw ("can't open file");

    fout.seekp(pos);
    fout.write((char*)&encStr, sizeof(encStr));


    fout.close();
}


void AbstractEncoder::readBin(const char *FileName, int pos)
{
    ifstream fin(FileName, ios::binary | ios::in);

    if (!fin)
        throw ("can't open file");
    fin.seekg(pos);


    fin.read((char*)&encStr, sizeof(encStr));


    fin.close();
}

char AbstractEncoder::operator[] (const int index)
{
    return str.getElement(index);
}
