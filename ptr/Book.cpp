#include "Book.h"
#include <iostream>

Book::Book () : 
title("unknown"),author("unknown"),year(2000) {}

Book::~Book(){
    std::cout << "dtor\n";
}
void Book::print(){
    std::cout << title << ' ' << author << ' ' << year << '\n';
}