#include "Library.h"
using namespace std;

void Library::printBooks(){
    cout << "Books:\n";
    for(const auto& b : books){
        if(b){
            b->print();
        } else cout << "empty\n";
    }
    cout << endl;
}
bool Library::addBook(shared_ptr<Book> &book){
    for(const auto& b : books){
        if(book==b){
            return false;
        }
    }    
    books.push_back(book);
    return true;
}
bool Library::deleteBook(shared_ptr<Book> &book){
    int index = 0;
    bool result = false;
    for(int i=0; i<books.size(); ++i){
        if(book == books[i]){
            result = true;
            books[i].reset();
            index = i;
        }
    }
    if(result){
        books.erase(books.begin()+index);
    }
    return result;
}


// weak_ptr<Book> Library::searchBook(string _title = "def",string _author="def") const {

//     weak_ptr<Book> result;
//     if(_title=="def"){ //author!=def
//         for(auto i : books){
//             if(_author == i->getAuthor()){
//                 cout << "found " << i->getAuthor() << endl;
//                 result = i;
//             }
//         } 
//     } 
//     return result;
// }