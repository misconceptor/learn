#pragma once
#include <string>
#include <iostream>
struct Student{
    std::string name;
    int score;
};

template <typename T>
class Deque {
public:
/*todo:
ctors, dtor, extend pushb pushf popb popf
accessors
swap, iterators
show()
*/
explicit Deque(int n) {
    size = n+1;
    b = 0;
    e = 0;
    node = new T[this->size];
}
~Deque() {
    delete[] node;
}
T& Front(){
    return node[b];
}
int get_size() const {
    return (e+size-b) % size;
}
int capacity() const {
    return size;
}
bool isEmpty() const {
    return b==e;
}
void clear(){
    b = 0;
    e = 0;
}
/*Deque(std::initializer_list<T> list){
}*/
void extend(){
    T* newnode= new T[2*size + 1];
    int newb = 0, newe = 0;
    for(int i=b; i!=e; i = (i+1)%size){
        newnode[newe++] = node[i];
    }
    delete [] node;
    node = newnode;
    size = 2 * size + 1;
    b = newb;
    e = newe;
}


private:
    T* node; //ptr to memory for deque
    int size; //size of FULL memory
    int b; //index of first
    int e; //index of element after the last 
};
