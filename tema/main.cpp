#include <iostream>
#include "Rat.cpp"
using namespace std;

int main(){
    Rat a,b;
    cin >> a;
    a.Normalize();
    int x = 5;
    cout << a << endl;
    cout << (a==x) << endl; 
    return 0;
}