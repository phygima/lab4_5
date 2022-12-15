#ifndef LAB1_MYSTRING_H
#define LAB1_MYSTRING_H
#define _CRT_SECURE_NO_DEPRECATE
#include <fstream>
using namespace std;


class String {


public:
	//defult constructor
	String();

	//constructor with parameters
	String(const char* str);

	//copy constructor
	String(const String& other);

	//destructor
	~String();

	//method Get
	char* getString();
	
	//method Set
	void setString(char* str);

	//reversive length
	int lengthStr();

	//method cstr
    char* cStr();

	//metod get substring
	char* getSubStr(int start, int len);

	//metod get element of string
	char getElement(int index);

	void setElement(char sym, int index);
	
	 //substring removal method
	char* getErase(int start, int len);

	//method to get the first occurrence of a  substring
	char* getStrchr(char* s, char c);
    
    void CheckException(int err);
    
    //write to file method
    void writeBin(const char* FileName, int pos);
    
    //read file method
    void readBin(const char* FileName, int pos);

	// overloading = operator
	String& operator =(const String& other);

	String& operator =(const char* other);

	String& operator= (const char& ch);


	//overloading + operator
	String operator+(const String& other);
    
    //overloading - operator
    String operator -(const String& other);
    
    String operator -(int index);
    
    //overloading () operator
    String operator ()(int start, int len);
    
    
    //overloading  (char*) operator
    explicit operator char*()
    {
        return this->cStr();
    }

    //overloading -- operator
    String operator --();

	//overloading == operator
	bool operator ==(const String& other);

	//overloading [] operator
	char& operator [](int index);
    
    
    //overloading << operator
    friend ostream& operator <<(ostream& fout, String& str)
    {
         fout << str.cStr();
         return fout;
    }
  
    //overloading >> operator
    friend istream& operator >>(istream& fin, String& str)
    {
         for (int i = 0; i < strlen(str.cStr());)
         {
             fin >> str[i];
             i++;
         }
        return fin;
    }


protected:
    
	char* str;
	int length;
	int sz;

};



#endif //LAB1_MYSTRING_H
