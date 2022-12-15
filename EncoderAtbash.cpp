#include <iostream>
#include "EncoderAtbash.h"


using namespace std; 


EncoderAtbash::EncoderAtbash(const char* str) :AbstractEncoder(str)
{
	
}


EncoderAtbash::~EncoderAtbash()
{

}

//string encoding method
void EncoderAtbash::encode() //-----------------------------------
{
	if (length == 0)
		throw ("Length = 0!");
	for (int i = 0; i < length; i++)
	{
		if (!(str[i] > ' ' || str[i] < 'a'))
		{
			throw ("", i);
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (isupper(this->str[i]) && isalpha(this->str[i]))
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (upperDecoded[j] == this->str[i])
				{
					step = j;
				}
			}
			encStr.setElement(upperEncoded[step], i);
		}
		else if (isalpha(this->str[i]))
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (lowerDecoded[j] == this->str[i])
				{
					step = j;
				}
			}
			encStr.setElement(lowerEncoded[step], i);
		}
		else if (this->str[i] >= '0' && this->str[i] <= '9')
		{
			int step;
			for (int j = 0; j < 10; j++)
				if (decArrNumb[j] == this->str[i])
				{
					step = j;
				}
			encStr.setElement(encArrNumb[step], i);
		}
		else if (this->str[i] == ' ')
		{
			encStr.setElement(' ', i);
		}
	}
}

//string decoding method
void EncoderAtbash::decode() //-----------------------------------
{
	if (length == 0)
		throw ("Length = 0!");
	for (int i = 0; i < length; i++)
	{
		if (!(str[i] > ' ' || str[i] < 'a'))
		{
			throw ("", i);
		}
	}
	for (int i = 0; i < length; i++)
	{
		if (isupper(this->str[i]) && isalpha(this->str[i])) //Capital + letter
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (upperEncoded[j] == this->str[i])
				{
					step = j;
				}
			}
			decStr.setElement(upperDecoded[step], i);
		}
		else if (isalpha(this->str[i])) //just a letter
		{
			int step;
			for (int j = 0; j < 26; j++)
			{
				if (lowerEncoded[j] == this->str[i])
				{
					step = j;
				}
			}
			encStr.setElement(lowerDecoded[step], i);
		}
		else if (this->str[i] >= '0' && this->str[i] <= '9')
		{
			int step;
			for (int j = 0; j < 10; j++)
				if (encArrNumb[j] == this->str[i])
				{
					step = j;
				}
			decStr.setElement(decArrNumb[step], i);
		}
		else if (this->str[i] == ' ')
		{
			decStr.setElement(' ', i);
		}
	}
}

char* EncoderAtbash::getDoc()
{
	String doc = doc1 + doc2 + doc3 + doc4 + doc5;
	return doc.cStr();
}


