#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "io.cpp"
#include "functional.cpp"
using namespace std;



int main(){
    std::vector<std::tuple<int,int,int>> t;
    readPixels("input.txt", t); //вектор кортежей заполнили из файла

    std::vector<std::tuple<int,int,int>> ptsInCir;
    double radius = 5;
    ptsInCir = pointsInCircle(radius,t);
    show(ptsInCir);
    //ЗАКОНЧИЛ НА ЗАДАНИИ 3


    /*ifstream input("input.txt"); 
    ofstream output("output.txt"); 
    vector<tuple<int,int,int>> t; //прочитать вектор кортежей
    if(input.is_open()){
        while(!input.eof()){
            int color,x,y;
            input >> color >> x >> y;
            t.push_back(make_tuple(color,x,y));
        }
    }



    for(auto i : t){ // вывести вектор кортежей в output.txt
        int color,x,y;
        color = std::get<0>(i);
        x = std::get<1>(i);
        y = std::get<2>(i);
        output << color << ' ' << x << ' ' << y << '\n';
    }*/
    return 0;
}