#include <iostream>
#include "Date.cpp"
#include "Animal.cpp"
#include "AbstractAnimal.cpp"
#include "MicAnimal.cpp"
#include "spdlog/spdlog.h"
int main(){
    Date date(2007,7,25);
    std::string n = "tema";
    std::string ch = "88";
    auto log = spdlog::stdout_color_mt("log");
    return 0;
}