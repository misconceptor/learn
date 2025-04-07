#include <iostream>
#include <memory>
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
        cout << "par_ctor\n";
        title = _title;
        author = _author; 
        year = _year;
    }
    ~Book(){
        cout << "dtor\n";
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
private:
    std::string title, author;
    int year;
};

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
    cout <<"stage1\n";
    return *ptr;
}

void foo(Book rhs){
    cout << rhs.getYear() << endl;
}

int main(){
    //unique_ptr<Book> ptr1 = make_unique<Book>("tit","aut",2000);
    foo(makeBook("a","b",1987));
    //todo copy ctor
    return 0;
}