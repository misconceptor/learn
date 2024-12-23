#include "Deque.cpp"
#include <iostream>

using namespace std;

int main(){
    Deque<int> d(5);
    cout << d.capacity() << endl; 
    return 0;
}