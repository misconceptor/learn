#include "io.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    if(0){
        cout << cin.get() << endl; //это вернуть код введенного символа
    }
    if(0){
        char x;
        cin.get(x); //извлечь из потока символ,поместить его в x
        cout << x << endl;
    }
    if(0){
        char s[10];
        //cin.get(s,10,'%'); //streambuf, size, delimiter
        //cout.put(s[4]); //вывeсти символ в поток
        //cout.put('\n'); 
        const char* s1 = "hello\n";
        cout.write(s1,6);
    }


    //seekget seekput tellget tellput
    if(0){
        ifstream file("in.txt");
        file.seekg(3,file.beg); //or ios::beg
        char ch;
        file.get(ch);
        cout << ch << endl;
        file.close();
    }
    if(0){
        ifstream i("in.txt");
        i.seekg(1);
        cout << i.tellg() << endl; //position of the pointer
    }
    if(1){
        ifstream i("in.txt");
        ofstream o("out.txt");
        string s;
        i >> s;
        o << s;
        cout << o.tellp() << endl;
    }


    return 0;
}