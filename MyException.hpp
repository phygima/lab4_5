#include <iostream>
#include <stdio.h>

#pragma once

class MyException : public std::exception
{
public:
    MyException(char* msg, int data)
    {
        this->msg = msg;
        this->data = data;
    }
    ~MyException() {}
    int getData() const {
        
        return this->data;
    }
    const char * what() const noexcept override {
        return msg;
    }
    
    
private:
    char* msg;
    int data;
};
