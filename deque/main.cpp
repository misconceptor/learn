#include "Deque.cpp"
#include <iostream>
using namespace std;

int main(){
    Deque<int> d{1,2,3,54,5};
    Deque<int> c = std::move(d);
    return 0;
}