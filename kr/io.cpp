#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>

void readFromFile(std::string in, std::string out){
    std::ifstream f(in); // Экземпляр класса ifstream
    std::ofstream o(out);
    if(f.is_open()){ // if the file is opened
        while(!f.eof()){
            int x;
            f >> x; //в переменную Х направляем поток ввода
            o << x << ' '; // заполняем output.txt
        }
        o << '\n';
        f.close();
        o.close();
    }
}

void readPixels(std::string fileName, std::vector<std::tuple<int,int,int>> &t){
    std::ifstream input(fileName);
    if(input.is_open()){
        while(!input.eof()){
            int color,x,y;
            input >> color >> x >> y;
            t.push_back(std::make_tuple(color,x,y));
        }
    }
    input.close();
}

void show(const std::vector<std::tuple<int,int,int>> &t){
    for(auto i : t){
        std::cout << std::get<0>(i) << ' ' << std::get<1>(i) << ' ' << std::get<2>(i) << '\n'; 
    }
}