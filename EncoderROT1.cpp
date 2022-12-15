#include <iostream>
#include "EncoderROT1.h"

using namespace std;

//default constructor
EncoderROT1::EncoderROT1(const char* str) :AbstractEncoder(str)
{

}

EncoderROT1::~EncoderROT1()
{

}

//string encoding method
void EncoderROT1::encode() //-----------------------------------
{
	if (length == 0)
		throw ("Length = 0");
	for (int i = 0; i < length; i++)
	{
		if (str[i] == 'z')
		{
			throw ("A character was found in the string that is not suitable for encoding!", i);
		}
		if (!(str[i] > ' ' || str[i] < 'z'))
		{
			throw ("A character missing from a valid list was found in the string!", i);
		}
	}
	for (int i = 0; i < length; i++)
	{
		str[i] = str[i] + 1;
		encStr.setElement(str[i], i);
	}
}

void EncoderROT1::decode() //-----------------------------------
{
	if (length == 0)
		throw ("Length = 0!");
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			throw ("A character was found in the string that is not suitable for encoding!", i);
		}
		if (!(str[i] > ' ' || str[i] < 'z'))
		{
			throw ("A character missing from a valid list was found in the string!", i);
		}
	}
	for (int i = 0; i < length; i++)
	{
		str[i] = str[i] - 1;
		encStr.setElement(str[i], i);
	}
}

char* EncoderROT1::getDoc()
{
	String doc = doc1 + doc2 + doc3;
	return doc.cStr();
}
