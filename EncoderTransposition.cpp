#include <iostream>
#include "EncoderTransposition.h"

using namespace std; 

EncoderTransposition::EncoderTransposition() :AbstractEncoder()
{

}

EncoderTransposition::EncoderTransposition(const char* str) :AbstractEncoder(str)
{
}

EncoderTransposition::~EncoderTransposition()
{

}

//string encoding method
void EncoderTransposition::encode() //-----------------------------------
{	
	if (length == 0)
		throw ("Length = 0!");
	for (int i = 0; i < length; i++)
	{
		if (!(str[i] > ' ' || str[i] < 'z'))
		{
			throw EncoderException("A character missing from a valid list was found in the string!", i);
		}
	}
	if (length % 2 == 0)
	{		
		for (int i = 0; i < length / 2; i + 2)
		{
			encStr.setElement(str[i], i+1);
			encStr.setElement(str[i+1], i);
		}
	}
	else
	{		
		for (int i = 0; i <= length / 2; i = i + 2)
		{
			encStr.setElement(str[i], i + 1); 
			encStr.setElement(str[i + 1], i);
		}
	}
}

void EncoderTransposition::decode() //-----------------------------------
{
	if (length == 0)
		throw ("Length = 0!");
	for (int i = 0; i < length; i++)
	{
		if (!(str[i] > ' ' || str[i] < 'z'))
		{
			throw EncoderException("A character missing from a valid list was found in the string!", i);
		}
	}
	if (length % 2 == 0)
	{
		for (int i = 0; i < length / 2; i + 2)
		{
			decStr.setElement(str[i], i + 1);;
			decStr.setElement(str[i + 1], i);
		}
	}
	else
	{
		for (int i = 0; i <= length / 2; i = i + 2)
		{
			decStr.setElement(str[i], i + 1); 
			decStr.setElement(str[i + 1], i);
		}
	}
}

char* EncoderTransposition::getDoc()
{
	String doc = doc1 + doc2 + doc3;
	return doc.cStr();
}
