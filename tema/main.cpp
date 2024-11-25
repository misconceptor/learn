#include <iostream>
#include <compare>
#include "Rat.cpp"
using namespace std;

int main(){
    Rat a(5,6), b(3,4);
    int c = 1;
    cout << (a-=c) << endl;
    return 0;
}