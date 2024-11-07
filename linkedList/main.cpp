#include <iostream>
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
    ~LinkedList(){
        erase(first);
    }
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
    int size(){
        Node* head = first;
        int ans = 0;
        while(head){
            ++ans;
            head = head->next;
        }
        return ans;
    }
    void insert(int value,int pos){
        if(pos == 1){
            push_front(value);
            return;
        }
        if(pos == size()){
            push_back(value);
            return;
        }
        if(pos > size()){
            return; //position is out of range
        }
        Node* head = first;
        for(int i=0; i<pos-2; ++i){
            head = head->next;
        }
        Node* node = new Node(value,head->next);
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

    Node *first;
    Node **ptr_last;
};
int main(){
    LinkedList a;
    a.push_back(7);
    a.push_back(51);
    a.push_back(18);
    a.push_back(5);
    a.push_back(87);
    a.show();
    a.insert(2,5);
    a.show();

    return 0;
}