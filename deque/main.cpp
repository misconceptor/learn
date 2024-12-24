#include "Deque.cpp"
#include <iostream>
using namespace std;
struct Student{
    std::string name_;
    int score_;
    Student(std::string name, int score) : name_(name), score_(score) {}
};
int main(){
    Deque<Student> s(1);
    Student a ("Name", 1);
    s.pushBack(a);
    return 0;
}