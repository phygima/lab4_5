
#include "AbstractEcoder.hpp"
#include "MyException.hpp"

class EncoderAtbash : public AbstractEncoder
{                                                                                                
public:                                                                                         

    EncoderAtbash(const char* str);


    ~EncoderAtbash();

    //string encoding method
    void encode() override;
    
    //string decoding method
    void decode() override;

    char* getDoc();
    
    
    
    
    friend ostream& operator << (ostream& fout, EncoderAtbash& str)
    {
        fout << str.cStr() << endl;
        return fout;
    }
    
    friend istream& operator >>(istream& fin, EncoderAtbash& str)
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
    const char upperDecoded[26] = {'A','B','C','D','E','F','G','H','I','J','K',  
                                   'L','M','N','O','P','Q','R','S','T','U','V',
                                   'W','X','Y','Z'};

    //upper case alphabet (encoded)
    const char upperEncoded[26] = {'Z','Y','X','W','V','U','T','S','R','Q','P',
                                   'O','N','M','L','K','J','I','H','G','F','E',
                                   'D','C','B','A'};

    //алфавит нижнего регистра (uncoded)
    const char lowerDecoded[26] = {'a','b','c','d','e','f','g','h','i','j','k',
                                   'l','m','n','o','p','q','r','s','t','u','v',
                                   'w','x','y','z'};

    //lower case alphabet (uncoded)
    const char lowerEncoded[26] = {'z','y','x','w','v','u','t','s','r','q','p',
                                   'o','n','m','l','k','j','i','h','g','f','e',
                                   'd','c','b','a'};
    //digit set (uncoded)
    const int decArrNumb[10] = { '0','1','2','3','4','5','6','7','8','9' };

    //digit set (encoded)
    const int encArrNumb[10] = { '9','8','7','6','5','4','3','2','1','0' };

    //documentation {
    String doc1 = { "The cipher used in the program is the simple substit" };
    String doc2 = { "ition cipher used for the Hebrew alphabetand from th" };
    String doc3 = { "ere it got its name(Atbash). Encryption occurs by re" };
    String doc4 = { "placing the first letter of the alphabet with the la" };
    String doc5 = { "st, the second with the penultimate one." };

};
