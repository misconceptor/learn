#include <iostream>
#include "header.cpp"
#include "spdlog/spdlog.h"
using namespace std;
namespace spd = spdlog;
int main(){
    auto makaka = spd::stdout_color_mt("console");
    makaka->critical("Welcome to spdlog!");
    return 0;
}