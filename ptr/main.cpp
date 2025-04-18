#include <iostream>
#include <memory>
#include "Book.cpp"
#include "Library.cpp"
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
    shared_ptr<Book> book[4];
    Library lib;

    book[0] = make_shared<Book>("t1","a1",1);
    book[1] = make_shared<Book>("t2","a2",2);
    book[2] = make_shared<Book>("t3","a3",3);
    book[3] = make_shared<Book>("t4","a4",4);



    // weak_ptr <Book> wp = book[0];
    // if(!wp.expired()){
    //     wp.lock()->print();
    // } else {
    //     cout << "exp\n";
    // }
    /*
        TODO: 
        1)add multiple books to library? 
        2)weak ptr method for searching a book
        3)the same function
        4)"user" class
        qt integration

    
    */
    return 0;
}