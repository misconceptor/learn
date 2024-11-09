#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;

class Node{
public:
    //comment
    Node() : val(0), next(nullptr) {}
    explicit Node(int _val) : val(_val) {}
    Node(int _val, Node* _next) : val(_val), next(_next) {}

    int val;
    Node *next;    
};

class LinkedList{
public:
    LinkedList() : first(nullptr), ptr_last(&first) {}
    LinkedList(const LinkedList& list) { //copy constructor
        first = nullptr;
        ptr_last = &first;
        Node* head = list.first;
        while(head){
            push_back(head->val);
            head = head->next;
        }
    }
    //move constructor, which moves pointers on memory field from original to new
    //use std::move to access this constructor
    LinkedList(LinkedList && list) noexcept {
        first = list.first;
        ptr_last = list.ptr_last;
        list.first = nullptr;
        list.ptr_last = nullptr; 
    }
    
    ~LinkedList(){
        erase(first);
    }

    void push_front(int x){
        first = new Node(x,first); //it's a new head
        if(first->next == nullptr){ //case of empty list
            ptr_last = &first->next;
        }
    }
    void push_back(int x){
        Node* tail = new Node(x);
        *ptr_last = tail;
        ptr_last = &tail->next;
    }
    void pop_front(){
        if(first){ //if not empty
            Node *p = first;
            first = first->next;
            delete p;
        }
    }
    void pop_back(){
        if(first){ //if not empty
    
        }
    }
    void show(){
        Node *head = first;
        while(head){
            cout << head->val << ' ';
            head = head->next;
        }
        cout << endl;
    }
    int size(){
        Node* head = first;
        int ans = 0;
        while(head){
            ++ans;
            head = head->next;
        }
        return ans;
    }
    void insert(int pos,int value){
        if(pos == 1){
            push_front(value);//how to implement without this "if"?
            return;
        }
        if(pos == size()){
            push_back(value);//how to implement without this "if"?
            return;
        }
        if(pos > size()){
            return; //position is out of range
        }
        Node* head = first;
        for(int i=0; i<pos-2; ++i){
            head = head->next;
        }
        Node* node = new Node(value);
        node->next = head->next;
        head->next = node;
    }
private:
    void erase(Node* &cur){
        while(cur != nullptr){
            Node* p = cur;
            cur = cur->next;
            delete p;
        }
    }
    friend ostream& operator <<(ostream& os, LinkedList& list){
        os << "[ ";
        Node* head = list.first;
        while(head){
            os << head->val << " ";
            head = head->next;
        }
        os << "]";
        return os;
    }
    friend istream& operator >>(istream& is, LinkedList& list){
        char s[1024];
        is.getline(s,1024);
        istringstream iss(s);
        iss >> list;
        return is;
    }
    friend istringstream& operator >>(istringstream& iss, LinkedList& list){
        int x;
        while(iss >> x){
            list.push_back(x);
        }
        return iss;
    }

    Node *first;
    Node **ptr_last;
};
int main(){
    LinkedList a;
    string s;
    getline(cin,s);
    istringstream is(s);
    is >> a;
    cout << a << endl;

    return 0;
}