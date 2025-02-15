#include <math.h>
#include <algorithm>
struct Node { 
    explicit Node(int _val = 0,Node* _left = nullptr, Node* _right = nullptr):
        val(_val), left(_left), right(_right) {}

    bool isLeaf() {
        return left==nullptr && right==nullptr;
    }

    int val;
    Node* left;
    Node* right;
};

class Tree {
private:
    Node* ptr;
    void erase(Node* &t) {
        if(t){
            erase(t->left);
            erase(t->right);
            delete t;
        }
    }
public:
    Tree() : ptr(nullptr) {}
    ~Tree() {
        erase(ptr);
    }
    void insert(int value){
        Node** ptr_to = &ptr;
        while(*ptr_to){
            if(value < (*ptr_to)->val){
                ptr_to = &(*ptr_to)->left;
            } else ptr_to = &(*ptr_to)->right;
        }
        *ptr_to = new Node(value);
    }
    std::ostream& printIn(std::ostream& os) const {
        return printIn(os,ptr);
    } 
    std::ostream& printIn(std::ostream& os, Node* n) const {
        if(n){
            printIn(os,n->left);
            os << n->val << ' ';
            printIn(os,n->right);
        }
        return os;
    }
    friend std::ostream& operator<< (std::ostream& os, const Tree &t) {
        return t.printIn(os,t.ptr);
    }    

    int height() {
        return height(ptr);
    }
    int height(Node* t) {
        if (!t) return 0;
        return 1 + std::max(height(t->left), height(t->right));
    }

    int size(Node* t){ //counts itself
        if(!t) return 0;
        return 1 + size(t->left) + size(t->right);
    }
    int size(){
        return size(ptr);
    }/*найти максимальное поддерево 
    с наибольшим числом вершин, в котором для каждой нелистьевой 
    вершины  число вершин в левом поддереве больше числа 
    вершин в правом поддереве*/
    
    Node* task(){
        int s;
        return task(ptr,s);
    }
    Node* task(Node* t, int &s){
        if(t==nullptr){
            s = 0;
            return nullptr;
        }
        if(t->isLeaf()) {
            s = 1;
            return nullptr;
        }

        int sl,sr,hl,hr;
        Node *l = task(t->left,sl);
        Node *r = task(t->right,sr);
        s = sl+sr+1;
        std::cout << t->val << ' ' << s << ' ' << sl << ' '<<sr <<'\n';

        /*if(sl==sr){
            return 
        }*/
        if(sl > sr) return t;
        else if(r) return r;
        else return l;
        //вопрос - как выбрать вершину основываясь на ее глубине,числе вершин и хорошести
        //например если 2 поддерева удовлетворяют, надо вырбать то 
        //которое ближе к корню и в котором больше вершин
    }
};