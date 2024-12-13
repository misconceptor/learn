#include <iostream>
#include "Date.cpp"

int main(){
    Date d(1999,1,1);
    std::cout << d.toString() << std::endl;
    return 0;
}