//
//  stringWithTime.h
//  labb
//
//  Created by Виктория Гладкова on 09.11.2022.
//

#ifndef StringWithTime_h
#define StringWithTime_h

#include "String.h"

class StringWithTime:public String
{
public:
    //defult constructor
    StringWithTime();

    //copy
    StringWithTime(const char* str);


    //destructor
    ~StringWithTime();

    
    //method for string creation local time
    void setTimeAvto();
    
    char* getTimeAvto();
    
    void setTime(const char* time, const char* date);

    char* getTime();
    
    

    
    
private:
    char* timee;
    char* date;
};


#endif /* StringWithTime_h */
