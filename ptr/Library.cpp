#include "Library.h"
#include "User.h"
#include "Book.h"
using namespace std;
const string noName = "-1";

void Library::printBooks(){
    cout << "Books:\n";
    for(const auto& b : books){
        if(b){
            b->print();
        } else cout << "empty\n";
    }
    cout << endl;
}
void Library::printUsers(){
    cout << "Users:\n";
    for(const auto& b : users){
        if(b){
            cout << b.use_count() << ",, ";
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
bool Library::addUser(shared_ptr<User> &user){
    for(const auto& u : users){
        if(user==u){
            return false;
        }
    }
    users.push_back(user);
    return true;
}
// bool Library::addUser(shared_ptr<User> &user){
//     for(const auto& u : users){
//         if(user==u){
//             return false;
//         }
//     }    
//     users.push_back(user);
//     return true;
// }
bool Library::deleteBook(shared_ptr<Book> &book){
    int index = 0;
    bool result = false;
    for(int i=0; i<books.size(); ++i){
        if(book == books[i]){
            result = true;
            weak_ptr<User> brw = books[i]->borrower;
            for(auto& i : brw.lock()->borrowedBooks){
                if(i.lock() == book){
                    cout << "match\n";
                    i.reset();
                }
            }
            books[i]->borrower.reset();
            books[i].reset();
            index = i;
        }
    }
    if(result){
        books.erase(books.begin()+index);
    }
    return result;
}

weak_ptr<Book> Library::searchBook(string _title = noName,string _author=noName) {
    weak_ptr<Book> result;
    //HANDLING IDEAL CASE WHERE ALL THE ARGUMENTS ARE NON-DEFAULT
    //if(_title!=noName && _author!=noName){
        for(auto i : books){
            if(i->getTitle()==_title && i->getAuthor()==_author){
                return i;
            }
        }
    // } else if(_title!=noName) {
    //     for(auto i : books){
    //         if(i->getTitle()==_title){
    //             return i;
    //         }
    //     }
    // } else {
    //     for(auto i : books){
    //         if(i->getAuthor()==_author){
    //             return i;
    //         }
    //     }
    // }
    return result;
}

void Library::findAndShow(string _title, string _author){
    weak_ptr b = searchBook(_title,_author);
    if(!b.expired()){
        b.lock()->print();
    } else {
        cout << "Not found\n";
    }
}

bool Library::deleteUser(shared_ptr<User> &user){
    int index = 0;
    bool result = false;
    for(int i=0; i<users.size(); ++i){
        if(user == users[i]){
            result = true;
            for(auto& j : users[i]->borrowedBooks){ //make his books available
                j.lock()->borrower.reset();
                j.reset();
            }
            users[i].reset();
            index = i;
        }
    }
    if(result){
        users.erase(users.begin()+index);
    }
    return result;
}

vector<weak_ptr<User>> Library::getUserVector() {
    vector<weak_ptr<User>> ans;
    for(auto u : users){
        ans.push_back(weak_ptr<User>(u));
    }
    return ans;
}
vector<weak_ptr<Book>> Library::getBookVector() {
    vector<weak_ptr<Book>> ans;
    for(auto b : books){
        ans.push_back(weak_ptr<Book>(b));
    }
    return ans;
}
bool Library::assignBook(const shared_ptr<Book>& book, const shared_ptr<User>& user){
    if(book->isAvailable()){ 
        book->borrower = user;
        user->borrowedBooks.push_back(book);
        return true;
    } else { //if book has a user
        return false;
    }
}

void Library::showStatus() const{
    for(auto u : users){
        cout << u->getName() << ":\n";
        vector<weak_ptr<Book>> b = u->borrowedBooks;
        for(auto i : b){
            if(!i.expired()){
                i.lock()->print();
            }
        }
    }
}