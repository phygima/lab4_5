#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "StringWithTime.h"
#include "BinaryStr.h"
#include "EncoderAtbash.h"


using namespace std;



int main()
{
    String str0="Hello wooooooldjfdiojsadopifjipjsapdfjpsadfjld";
    String str1="world";

    char* FileName = "/Users/vikulya/Desktop/lab1/lab/lab/labb/test.dat";
  
   str0.writeBin(FileName, 0);
 
   str0.readBin(FileName, 0);

    EncoderAtbash a ="sjska";
    
    //a.writeBin(FileName, 0);
    //a.readBin(FileName, 0);
    cout<< str0<<endl;
    
    
    //cout<< a<<endl;
    
  

    ifstream fin(FileName, ios::binary | ios::in);
//    fin >> str0;
    
    fin >> a;
    
    fin.close();
    
    
    
//    setlocale(LC_ALL, "ru");
//
//    //HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    cout << "---------------------------" << endl;
//    EncoderAtbash encoderAtbash = "Hello\n";
//    try
//    {
//        encoderAtbash.encode();
//        cout << "Ecncoded: " << encoderAtbash.getEncStr() << endl;
//        /*encoderAtbash.decode();
//        cout << "Decoded: " << encoderAtbash.getDecStr() << endl;*/
//    }
//    catch (EncoderException& ex)
//    {
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
//        cout << "Error: ";
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        cout << ex.what() << ',' << " Index: " << ex.GetIndex() << endl;
//    }
//    catch (exception& ex)
//    {
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
//        cout << "Error: ";
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        cout << ex.what() << endl;
//    }
//    cout << "\n" << encoderAtbash.getDoc() << endl << endl;
//
//    cout << "---------------------------" << endl;
//    EncoderTransposition encoderTransposition = "eHllo";
//    try
//    {
//        /*encoderTransposition.encode()
//        cout << "Encoded: " << encoderTransposition.getEncStr() << endl;*/
//        encoderTransposition.decode();
//        cout << "Decoded: " << encoderTransposition.getDecStr() << endl;
//    }
//    catch (EncoderException& ex)
//    {
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
//        cout << "Error: ";
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        cout << ex.what() << ',' << " Index: " << ex.GetIndex() << endl;
//    }
//    catch (exception& ex)
//    {
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY); //Red alert
//        cout << "Error: ";
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        cout << ex.what() << endl;
//    }
//    cout << "\n" << encoderTransposition.getDoc() << endl << endl;
//
//    cout << "---------------------------" << endl;
//    EncoderROT1 encoderROT1 = "œÓÎË ˆËˇ"; //WARN: Error
//    try
//    {
//        /*encoderROT1.encode();
//        cout << "Encoded: " << encoderROT1.getEncStr() << endl;*/
//        encoderROT1.decode();
//        cout << "Decoded: " << encoderROT1.getDecStr() << endl;
//    }
//    catch (EncoderException& ex)
//    {
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
//        cout << "Error: ";
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        cout << ex.what() << ',' << " Index: " << ex.GetIndex() << endl;
//    }
//    catch (exception& ex)
//    {
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_INTENSITY);
//        cout << "Error: ";
//        //SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
//        cout << ex.what() << endl;
//    }
//    cout << "\n" << encoderROT1.getDoc() << endl;
    
//    str1.setTime("21:00 ", "22.09.22");
//    cout<<"time string str1\t"<<str1.getTime()<<endl;
//    
//    StringWithTime  str2 = "world";
//    cout<<"time string str2\t"<<str2.getTimeAvto();
    
    
   
    //BinaryStr str4=str3.getDec();
    
    //cout<<"!!!"<<str4.cStr()<<endl;
//    cout<<str1.cStr()<<endl;
//
//    BinaryStr str2="01001";
//    cout<<str2.binToDec()<<endl<<endl;
//
//
//    EncoderAtbash encoderAtbash = "Hello";
//        encoderAtbash.encode();
//        cout << "Ecncoded: " << encoderAtbash.getEncStr() << endl;
//        cout << "\n" << encoderAtbash.getDoc() << endl << endl;
//
//
//        EncoderTransposition encoderTransposition = "eHllo";
//        encoderTransposition.decode();
//        cout << "Decoded: " << encoderTransposition.getDecStr() << endl;
//        cout << "\n" << encoderTransposition.getDoc() << endl << endl;
//
//
//        EncoderROT1 encoderROT1 = "Hello";
//        encoderROT1.encode();
//        cout << "Encoded: " << encoderROT1.getEncStr() << endl;
//        cout << "\n" << encoderROT1.getDoc() << endl;
//
    
   
    
	system("pause");
	return 0;
}
