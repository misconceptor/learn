#include <iostream>
#include <memory>
#include "Book.cpp"
#include "Library.cpp"
#include "User.cpp"
using namespace std;

//task 1
void bookInfo(unique_ptr<Book> ptr){
    if(!ptr){
        cout << "unknown\n";
        return;
    }
    cout << "title: " << ptr->getTitle() << '\n';
    cout << "author: " << ptr->getAuthor() << '\n';
    cout << "year: " << ptr->getYear() << '\n';
}
Book makeBook(string _title, string _author, int _year){
    cout <<"stage0\n";
    unique_ptr<Book> ptr = make_unique<Book>(_title,_author,_year);
    return *ptr;
}
void foo(unique_ptr<Book> &p){
    cout << "author is " << p->getAuthor() << '\n';
}
//end of task 1



int main(){
    //rules: unique books and users,
    //find books and users only with all the parameters
    Library lib;
    shared_ptr<User> u1 = make_shared<User>(3,"user");
    shared_ptr<User> u2 = make_shared<User>(4,"bb");
    shared_ptr<Book> b1 = make_shared<Book>("b1","a1",22);
    shared_ptr<Book> b2 = make_shared<Book>("b2","a2",33);
    shared_ptr<Book> b3 = make_shared<Book>("b3","a3",44);
    lib.addUser(u1);
    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(b3);

    lib.assignBook(b1,u1);
    lib.assignBook(b2,u1);
    lib.assignBook(b3,u1);

    lib.deleteBook(b2);
    return 0; 

    /*
        completed : deleting books and users with respect to pointers and assignments
        TODO: 

        qt integration

    
    */
    return 0;
}