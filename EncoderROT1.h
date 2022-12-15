#pragma once
#include "AbstractEcoder.hpp"


class EncoderROT1 : public AbstractEncoder
{
public:

	EncoderROT1(const char* str);


	~EncoderROT1();

	//string encoding method
	void encode() override;

	void decode() override;

	char* getDoc();
    
    
    
    friend ostream& operator << (ostream& fout, EncoderROT1& str)
    {
        fout << str.cStr() << endl;
        return fout;
    }
    
    friend istream& operator >>(istream& fin, EncoderROT1& str)
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
	String doc1 = { "This cipher is known to many children. The key is simple: " };
	String doc2 = { "each letter is replaced by the one following it in the " };
	String doc3 = { "alphabet." };
};
