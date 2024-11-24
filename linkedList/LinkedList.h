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
            return;
        }
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
    void push_front(int);
    void push_back(int);
    void pop_front();
    void pop_back();
    void show();
    int size();
    void insert(int, int); 
    void insert_to_sorted(int);
    int task23();

private:
    void erase(Node* &cur);
    friend std::ostream& operator <<(std::iostream& os, LinkedList& list);
    friend std::istream& operator >>(std::istream& is, LinkedList& list);
    friend std::istringstream& operator >>(std::istringstream& iss, LinkedList& list);
    Node *first;
    Node **ptr_last;
};