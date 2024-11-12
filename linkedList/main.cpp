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
    LinkedList& operator=(const LinkedList& rhs){ //assingment operator
        if(rhs.first == first){
            return *this;
        }
        first = nullptr;
        ptr_last = &first;
        Node* head = rhs.first;
        while(head){
            push_back(head->val);
            head = head->next;
        }
        return *this;
    }
    //move constructor, which moves pointers on memory field from original to new
    //use std::move to access this constructor
    LinkedList(LinkedList && list) noexcept {
        if(list.first==first){
            cout << "case1\n";
            return;
        }
        cout << "case2\n";
        first = list.first;
        ptr_last = list.ptr_last;
        list.first = nullptr;
        list.ptr_last = nullptr; 
    }
    
    ~LinkedList(){
        erase(first);
    }
    class iterator {
    public:
        iterator(Node* node) {
            cur = node;
        }
        iterator(const iterator& rhs) { //copy constructor
            cur = rhs.cur;
        }
        iterator& operator=(const iterator& rhs){
            cur = rhs.cur;
            return *this;
        }
        iterator(iterator && rhs) noexcept { //move constructor
            cur = rhs.cur;
            rhs.cur = nullptr;
        }
        int operator*(){
            return cur->val;
        }
        iterator& operator++(){
            cur = cur->next;
            return *this;
        }
        bool operator!=(iterator/*&*/ rhs){
            return cur != rhs.cur;
        }
    private:
        Node* cur;
    };
    iterator begin() { 
        return iterator(first);
    } 
    iterator end() { 
        return iterator(nullptr);
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
    void insert(int pos, int x) {
        Node** ptr_prev = &first;
        Node* cur = first;
        int i = 1;
        while (i < pos && cur) {
            ptr_prev = &cur->next;
            cur = cur->next;
            ++i;
        }
        Node* node = new Node(x, cur);
        *ptr_prev = node;
    }
    //insert an element to a sorted list
    void insert_to_sorted(int x) {
        Node** ptr_prev = &first;
        Node* cur = first;
        while (cur) {
            if (x <= cur->val) {
                Node* node = new Node(x, cur);//it's also the solution for insert-method
                *ptr_prev = node;//redefine the pointer from prev to new node
                break;
            }
            ptr_prev = &cur->next;
            cur = cur->next;
        }
        if (!cur) { //case of empty list, loop hasn't started
            push_back(x);
        }
    } 
    int task23() {
        int ans=1,num=1;
        Node* head = first;
        while(head->next != *ptr_last){
            if(head->val == head->next->val){
                ++num;
                ans = max(ans,num);
            } else {
                num = 1;
            }
            head = head->next;
        }
        return ans;
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
    cout << a.task23() << endl;
    return 0;
}