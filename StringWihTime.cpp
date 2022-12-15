//
//  stringWihTime.cpp
//  labb
//
//  Created by Виктория Гладкова on 09.11.2022.
//
#include <iostream>
#include "StringWithTime.h"
#include <ctime>

using namespace std;

StringWithTime::StringWithTime() : String()
{
    date= nullptr;
    timee = nullptr;
}



StringWithTime::StringWithTime(const char* str) : String(str)
{
    time_t datee = time(NULL);
    tm* timeinfo = localtime(&datee);
    timee=asctime(timeinfo);
}



StringWithTime::~StringWithTime()
{
    
}

void StringWithTime::setTimeAvto()
{
    time_t datee = time(NULL);
    tm* timeinfo = localtime(&datee);
    timee=asctime(timeinfo);
}


char* StringWithTime::getTimeAvto()
{
    return timee;
}


void StringWithTime::setTime(const char* time, const char* date)
{

        if(time==""){ throw ("Time is empty");}
    
        if(date==""){ throw ("Date is empty",time);}
        
        this->timee = new char[strlen(time)+1];
        strcpy(this->timee, time);
        
        this->date = new char[strlen(date)+1];
        strcpy(this->date, date);
 

}


char* StringWithTime::getTime()
{
    char* time = strcat(timee, date);
    
    return time;
    
    delete[] this->timee;
    delete[] this->date;
    
}




