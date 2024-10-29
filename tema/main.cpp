#include <iostream>
#include "Rat.cpp"
using namespace std;

int main(){
    Rat a(1,2), b(2);
    Rat c = a-b;
    c.Show();
    return 0;
}