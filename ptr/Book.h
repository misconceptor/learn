#pragma once
#include <string>
#include <iostream>
#include "User.h"
#pragma once
using namespace std;
class Book{
public:
    Book(){
        cout << "def_ctor\n";
        title = "unknown";
        author = "unknown";
        year = -1;
    }
    Book(string _title, string _author, int _year){
        //cout << "par_ctor\n";
        title = _title;
        author = _author; 
        year = _year;
    }
    Book(const Book& rhs){
        cout << "copy ctor\n";
        title = rhs.title;
        author = rhs.author; 
        year = rhs.year;
    }
    ~Book(){
        //cout << "dtor\n";
    }
    void print(){
        cout << title << ' ' << author << ' ' << year << '\n';
    }
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    int getYear() const {
        return year;
    }
    bool operator==(const Book& rhs) const {
        return title == rhs.title && author==rhs.author && year==rhs.year;
    }
    bool isAvailable() const {
        return borrower.expired();
    }
    weak_ptr<User> borrower;
private:
    string title, author;
    int year;
};