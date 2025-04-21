#pragma once
#include <vector>
#include <memory>
#include <cstdarg>
#include "Book.cpp"
#include "User.cpp"
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
    void printUsers();
    void addBook(...);
    bool addUser(shared_ptr<User> &user);
    bool deleteUser(shared_ptr<User> &user);
    weak_ptr<Book> searchBook(string _title,string _author);
    void findAndShow(string _title, string _author);
    vector<weak_ptr<User>> getUserVector();
    vector<weak_ptr<Book>> getBookVector();
    bool assignBook(const shared_ptr<Book>& book, const shared_ptr<User>& user);
    void showStatus() const;
private:
    vector<shared_ptr<Book>> books;
    vector<shared_ptr<User>> users;
};
