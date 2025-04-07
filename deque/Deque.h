#pragma once
#include <string>
#include <iostream>
struct Student{
    std::string name;
    int score;
};
const int DEFAULT_SIZE = 5;

template<typename T>
class iterator {
public:
    iterator(T* node, int cur, int cap) : node_(node), cur_(cur), cap_(cap) {}
    iterator& operator ++() {
        cur_ = (cur_+1)%cap_;
        return *this;
    }
    iterator operator ++(int) {
        iterator t(node_, cur_, cap_);
        cur_ = (cur_+1)%cap_;
        return t;
    }
    T& operator * () {
        return *(node_ + cur_);
    }
    bool operator != (const iterator<T>& rhs){
        return node_ != rhs.node_ || cur_ != rhs.cur_;
    }
private:
    T* node_;
    int cur_, cap_;
};

template <typename T>
class Deque {
public:
/*todo:
ctors
*/
explicit Deque(int n = DEFAULT_SIZE) {
    cap = n+1;
    b = 0;
    e = 0;
    node = new T[cap];
}
Deque(std::initializer_list<T> list) {
    cap = 2 * list.size() + 1;
    node = new T[cap];
    b = 0;
    e = 0;
    for(T i : list){
        pushBack(i);
    }
}
Deque(Deque const& rhs) {
    cap = rhs.cap;
    b = rhs.b;
    e = rhs.e;
    node = new T[cap];
    for(int i=b; i!=e; i=(i+1)%cap){
        node[i] = rhs.node[i];
    }
}
Deque(Deque&& rhs) {
    Swap(rhs);
    rhs.node = nullptr;
    rhs.b = rhs.e = rhs.cap = 0;
}

friend std::ostream& operator<< <>(std::ostream& , const Deque<T>&);

void Swap(Deque& rhs){
    std::swap(node,rhs.node);
    std::swap(cap,rhs.cap);
    std::swap(b,rhs.b);
    std::swap(e,rhs.e);
}
Deque& operator = (Deque const& rhs){
    if(this != &rhs){
        Deque t(rhs);
        swap(t);
    }
    return *this;
}
Deque& operator = (Deque&& rhs) {
    Swap(rhs);
    rhs.node = nullptr;
    rhs.b = rhs.e = rhs.cap = 0;
    return *this;
}
~Deque() {
    delete[] node;
}
T& Front(){
    return node[b];
}
T& Back(){
    return node[(e-1+cap)%cap];
}
const T& Front() const {
    return node[b];
}
const T& Back() const {
    return node[(e-1+cap)%cap];
}
int size() const {
    return (e+cap-b) % cap;
}
int capacity() const {
    return cap;
}
bool isEmpty() const {
    return b==e;
}
void clear(){
    b = 0;
    e = 0;
}
void checkMem(){
    if((e+1)%cap == b){//if the deque is fully loaded
        extend();
    } 
}
void pushBack(T const& x){
    checkMem();
    node[e] = x;
    e = (e+1)%cap; //"increment" the position in deque
}
void pushFront(T const& x){
    checkMem();
    b = (b-1+cap)%cap;
    node[b] = x; 
}
void popBack(){
    e = (e-1+cap)%cap;
}
void popFront(){
    b = (b+1)%cap;
}
void show(){ //i=(i+1)%cap is the loop condition
    for(int i=b; i!=e; i = (i+1)%cap){ 
        std::cout << node[i] << ' ';
    }
    std::cout << '\n';
}
void extend(){
    std::cout << "extend" << std::endl;
    T* newnode= new T[2*cap+ 1];
    int newb = 0, newe = 0;
    for(int i=b; i!=e; i = (i+1)%cap){
        newnode[newe++] = node[i];
    }
    delete [] node;
    node = newnode;
    cap = 2 * cap + 1;
    b = newb;
    e = newe;
}
iterator<T> begin() {
    return iterator(node, b, cap);
}
iterator<T> end() {
    return iterator(node, e, cap);
}
private:
    T* node; //ptr to memory for deque
    int cap; //total capacity 
    int b; //index of first
    int e; //index of element after the last 
};

template<class T>
std::ostream& operator << (std::ostream& os, const Deque<T>& rhs){
    for(int i=rhs.b; i!=rhs.e; i = (i+1)%rhs.capacity()){ 
        os << rhs.node[i] << ' ';
    }
    os << '\n';
    return os;
}