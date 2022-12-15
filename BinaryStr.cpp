//
//  binaryStr.cpp
//  labb
//
//  Created by Виктория Гладкова on 14.11.2022.
//



#include "BinaryStr.h"


using namespace std;

BinaryStr::BinaryStr() : String()
{
    
}

BinaryStr::BinaryStr(const char* str) : String(str)
{
    binStr = nullptr;
}


BinaryStr::~BinaryStr()
{
    delete[] this->binStr;
}

void BinaryStr::setBinStr(char* str)
{
    this->binStr= new char[strlen(str)+1];
    strcpy(this->binStr, str);
}



int BinaryStr::BinstrToInt(){
    
    int value=0;
    
    if(strlen(str)==0){throw ("String is empty");}
    for(int i=0; str[i]!=0; ++i){
        
        value<<=1;
        value+=str[i]-'0';
    }
    return value;
}
 
char* BinaryStr::IntToDecstr(int value){
    
    int sign=0;
    int size=2;
    
    if (value<0){
        
        ++size;
        value=-value;
        sign=1;
    }
 
    int place=10;
    while (value/place){
        
        place*=10;
        ++size;
    }
    place/=10;
 
    binStr=new char[size];
    
    if(sign) binStr[0]='-';
    binStr[size-1]=0;
 
    for(int i=sign; i<size-1; ++i){
        binStr[i]='0'+value/place%10;
        place/=10;
    }
    return binStr;
}





