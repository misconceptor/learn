#include <iostream>
#include "Date.cpp"
#include "Animal.cpp"
#include "AbstractAnimal.cpp"
#include "MicAnimal.cpp"
int main(){
    Date date(2007,7,25);
    std::string n = "tema";
    std::string ch = "88";

    MicAnimal a(n,date,ch); 
    std::cout << a.description() << '\n';
    return 0;
}