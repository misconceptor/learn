#include <iostream>
using namespace std;

class Node{
public:
    Node() : val(0), next(nullptr) {}
    explicit Node(int _val) : val(_val) {}
    Node(int _val, Node* _next) : val(_val), next(_next) {}

    int val;
    Node *next;    
};

class LinkedList{
public:
    LinkedList() : first(nullptr), ptr_last(&first) {}
    //destructor with erase-function

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
private:
    void Erase(Node* &cur){
        while(cur != nullptr){
            Node* p = cur;
            cur = cur->next;
            delete p;
        }
    }

    Node *first;
    Node **ptr_last;
};
int main(){
    LinkedList a;
    a.push_front(4);
    a.push_front(5);
    a.push_front(6);
    cout << "list=";
    a.show();

    a.pop_back();
    a.show();

    return 0;
}