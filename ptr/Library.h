#pragma once
#include <vector>
#include <memory>
#include <cstdarg>
#include "Book.cpp"
using namespace std;
class Library{
public:
    Library(){
        //cout << "lib ctor\n";
    }
    ~Library(){
        //cout << "lib dtor\n";
    }
    bool addBook(shared_ptr<Book> &book);
    bool deleteBook(shared_ptr<Book> &book);
    void printBooks();
    void addBook(...);

    //weak_ptr<Book> searchBook(string _title = "def",string _author="def") const;

private:
    vector<shared_ptr<Book>> books;
};
