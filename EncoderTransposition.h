#pragma once
#include "AbstractEcoder.hpp"


class EncoderTransposition : public AbstractEncoder
{
public:

	EncoderTransposition();

	EncoderTransposition(const char* str);

	~EncoderTransposition();

	//string encoding method
	void encode() override;

	void decode() override;

	char* getDoc();
    
    
    
    friend ostream& operator << (ostream& fout, EncoderTransposition& str)
    {
        fout << str.cStr() << endl;
        return fout;
    }
    
    friend istream& operator >>(istream& fin, EncoderTransposition& str)
      {
        String tmp = str.cStr();
        for (int i = 0; i < strlen(tmp.cStr());)
        {
            fin >> tmp[i];
            i++;
        }
        return fin;
        
      }

protected:

private:
	String doc1 = { "In a transposition cipher, letters are rearranged " };
	String doc2 = { "according to a predetermined rule. For example, swap " };
	String doc3 = { "every two letters." };
};
