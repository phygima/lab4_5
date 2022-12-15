#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "String.h"
#include <assert.h>
#include "MyException.hpp"


using namespace std;


	//constructor without parameters
	String::String()
	{
		str = nullptr;
		length = 0;
		sz = 0;

	}


	/**
	* copy constructor, necessary to create an exact copy of
	* a class object but in a different memory area
	*/
	String::String(const char* str)
	{
		/**
		* the strlen function gets the number of characters in the string
		* we pass to the object
		*/
		length = strlen(str);


		this->str = new char[length + 1];

		// copy the characters of the string to the array of our class
        try        {
            if(length==0){ throw MyException("String is empty",length);}
            
            for (int i = 0; i < length; i++)
            {
                this->str[i] = str[i];
            }
            
            //close the line with a terminating zero
            this->str[length] = '\0';
        }
        
        catch(MyException &ex)
        {
            cout<< ex.what() <<endl;
        }

	}

	/**
	* copy constructor, necessary to create an exact copy of
	* a class object but in a different memory area
	*/
	String::String(const String& other)
	{
		length = strlen(other.str);
        
        try        {
            if(length==0){ throw MyException("String is empty",length);}
            this->str = new char[length + 1];
            
            for (int i = 0; i < length; i++)
            {
                this->str[i] = other.str[i];
            }
            
            this->str[length] = '\0';
        }
        catch(MyException &ex)
        {
            cout<< ex.what() <<endl;
        }
	}

	/**
	* destructor, responsible for freeing the resources occupied by the object,
	* called when the class object is destroyed
	*/
	String::~String()
	{
		delete[] this->str;
	
	}

	char* String::getString()
	{
		return this->cStr();
	}

	void String::setString(char* str) 
	{
		this->str = new char[strlen(str)+1];
		strcpy(this->str, str);
	}
	
	//reversive length method
	int String:: lengthStr()
	{
		return length;
	}

	//method cStr
	  char* String::cStr()
	{
		char* ch = new char[length + 1];
		int i;
		for (i = 0; i < length; i++) {
			ch[i] = str[i];
		}
		ch[i] = '\0';
          
		return ch;
          
	}

	 //substring method
	 char* String::getSubStr(int start, int len)
	 {
         try{
             CheckException(start);
             CheckException(len);
            
             
             int size = len - start;
             if(size<0) size = -size;
             char* result = new char[size + 1];
             
             strncpy(result, &str[start], size);
             
             result[size] = 0;
             
             return result;
         }
         
         catch(MyException &ex)
         {
             cout<< ex.what() <<endl;
             
             return 0;
         }
     }

	 

	 //metod get element of string
	 char String::getElement(int index)
	 {
         try{
             CheckException(index);
             
             int size = 1;
             char* result = new char[size + 1];
             
             strncpy(result, &str[index], size);
             
             return result[0];
         }
         
         catch(MyException &ex)
         {
             cout<< ex.what() <<endl;
             
             return 0;
         }

	 }

	 //metod set element of string
	 void String::setElement(char sym, int index)
	 {
         try
         {
             CheckException(index);
             this->str[index] = sym;
         }
       
         catch(MyException &ex)
         {
             cout<< ex.what() <<endl;
         }
	 }

	 //substring removal method
	 char* String::getErase(int start, int len)
	 {
         int size = strlen(getSubStr(start,len));
         int i,j;
         char* NewString = new char[strlen(str)-size+1];
         for (i = 0; i < start; i++)
         {
             NewString[i] = str[i];
         }
         for (i = start, j = start + len; j < strlen(str); i++, j++)
         {
             NewString[i] = str[j];
             
         }
         NewString[i] = '\0';
         
         
         return NewString;
         delete[] NewString;
             
       
	 }


	 //method to get the first occurrence of a  substring
	 char* String::getStrchr(char* str, char ch)
	 {

         try{
             if(strlen(str) == 0){ throw MyException("String is empty",length); }
             
             assert(str != NULL);
             while (*str)
             {
                 if (*str == ch)
                     return str;
                 else
                     str++;
             }
             return 0;
         }
         
         catch(MyException &ex)
         {
             cout<< ex.what() <<endl;
             
             return 0;
         }
         
	 }


	/**
	* overloaded assignment operator, called when it is necessary
	* to assign the value of one object to another
	*/
	String &String:: operator =(const String& other)
	{
		
		//standard operator overload syntax =

		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;

	}

	String& String::  operator =(const char* other)
	{
		
		//standard operator overload syntax =

		if (this->str != nullptr)
		{
			delete[] str;
		}

		length = strlen(other);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other[i];
		}

		this->str[length] = '\0';

		return *this;

	}

	String& String ::operator= (const char& ch)
	{
		//standard operator overload syntax =
		length = 1;
		str = new char[length];
		str[0] = ch;
        
		return *this;

	}



	//overloaded addition operator
	String String:: operator+(const String& other)
	{
		//create a new empty object
		String newStr;

		//get the number of characters
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.length = thisLength + otherLength;

		//allocate space in dynamic memory for a new line
		newStr.str = new char[thisLength + otherLength + 1];

		//copy data
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';


		//return the result of the concatenation
		return newStr;
	}



        //subtraction operator overload
        String String:: operator -(const String& other)
        {
            char *p = 0, *p1 = 0;
            
                size_t size = strlen(other.str);
                for(; p = strstr(str,other.str); )
                {
                    p1 = p + size;
                    while(*p++ = *p1++);
                }
           
            return str;
            
        }

        //subtraction operator overload by index
        String String::operator -(int index)
        {
            String NewStr=str;
            
            return NewStr.getErase(index, 1);
        }


        //implementation of the erase method via ()
        String String::operator ()(int start, int len)
        {
            //operator in case the string is removed from the end
            if(start<0)
            {
                for(int i=0;i<len;)
                {
                    start=strlen(str)-1;
                    str = this->getErase(start, 1);
                    i++;
                }
            }
            else
            {
                str = this->getErase(start, len);
            }
            
            return *this;
        }

        //decrement operator overload
        String String::operator --()
        {
            String NewStr=str;
            str=(char*)NewStr(-1, 1);
            
            return *this;
        }


        //overloading == operator
        bool String:: operator ==(const String& other)
        {
            if (this->length != other.length)
            {
                return false;
            }

            for (int i = 0; i < this->length; i++)
            {
                if (this->str[i] != other.str[i])
                {
                    return false;
                }
            }
            return true;
        }


        //overloading [] operator
        char& String:: operator [](int index)
        {
            if (index<=strlen(str)-1)
            {
                return this->str[index];
            }
            else
            {
                throw out_of_range("Out of range string index");
            }
        }



    //method for cheking exception
    void String:: CheckException(int err)
    {
        if( err < 0)
        {
            throw MyException("Tried to enter a negative value", err);
        }
        
        if( err > strlen(str))
        {
            throw MyException("Value exceeds the length of the string",err);
        }
    }


    //write to file method
    void String::writeBin(const char* FileName, int pos)
    {
    
        ofstream fout(FileName, ios::binary | ios:: out );
        if(!fout) throw ("cant open file");
        
        fout.seekp(pos);  //put pointer
        fout.write((char*)&str,sizeof(str));
        
       
        fout.close();
    }


    //file read method
    void String::readBin(const char* FileName, int pos)
    {
        ifstream fin(FileName, ios::binary | ios::in);
        
        if(!fin) throw ("cant open file");
        fin.seekg(pos); //move get pointer
        
        
        fin.read((char*)&str, sizeof(str));
        
        
        fin.close();
        
    }

