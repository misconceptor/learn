#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include "Book.h" 
//#include "Book.cpp"
#pragma once
using namespace std;
class Book;
class User{
public:
    User(){
        //cout << "def ctor\n";
    }
    User(int _id, string _name) : id(_id),name(_name) {
        //cout << "user par ctor\n";
    } 
    ~User(){
        //cout << "user dtor\n";
    } 
    int getId() const {
        return id;
    }
    string getName() const {
        return name;
    }
    void print() const {
        cout << id << ' ' << name << '\n';
    }
    bool operator==(const User& rhs) const {
        return id == rhs.id && name==rhs.name;
    }
    vector<weak_ptr<Book>> borrowedBooks;
private:
    int id;
    string name;
};