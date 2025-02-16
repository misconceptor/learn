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
    Node* ptr; //TODO RENAME TO PTR_HEAD
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
            if(n->left) std::cout << "(";
            printIn(os,n->left);
            if(n->left) std::cout << ") <- ";
            os << n->val;
            if(n->right) std::cout << " -> (";
            printIn(os,n->right);
            if(n->right) std::cout << ")";
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
    }
    /*найти максимальное поддерево 
    с наибольшим числом вершин, в котором для каждой нелистьевой 
    вершины  число вершин в левом поддереве больше числа 
    вершин в правом поддереве*/
    
    Node* maxsub(){
        int s;
        bool b;
        return maxsub(ptr, b, s);
    }
    Node* maxsub(Node* t, bool& b, int &s){
        if (t == nullptr){
            b = true;
            s = 0;
            return nullptr;
        }
        if (t->isLeaf()) {
            b = true;
            s = 1;
            return t; //?
        }

        bool bl,br;
        int sl,sr,hl,hr;
        Node *l = maxsub(t->left, bl, sl);
        Node *r = maxsub(t->right, br, sr);
        if (b = (bl&&br) && (sl > sr)) {
            s = sl+sr+1;
            return t;
        }
        s = std::max(sl, sr);
        return sl > sr ? l : r;
        //вопрос - как выбрать вершину основываясь на ее глубине,числе вершин и хорошести
        //например если 2 поддерева удовлетворяют, надо вырбать то 
        //которое ближе к корню и в котором больше вершин
    }
};