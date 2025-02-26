#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    vector<int> adj;
    Node() : val(-1) {}
    Node(int a) : val(a) {}
    bool operator==(Node const& rhs) const {
        return val == rhs.val;
    }
    friend istream & operator >> (istream & in, Node & n){
        in >> n.val;
        return in;
    }
    friend ostream& operator << (ostream& os, Node const& n){ 
        return os << n.val; 
    }
};

struct Edge
{
    Node b,e;

    Edge() : b(), e() {}
    Edge(Node _b, Node _e) : b(_b), e(_e) {}

    bool operator==(Edge const& rhs) const {
        return (b == rhs.b) && (e == rhs.e);
    }

    friend istream & operator >> (istream & in, Edge & edge){
        in >> edge.b >> edge.e;
        return in;
    }
    friend ostream& operator << (ostream& os, Edge const& ed){ 
        return os << "(" << ed.b << "," << ed.e << ")"; 
    }
    bool isLoop(){
        return b==e;
    }
};


int main(){
    ifstream input("in.txt");
    //todo out
    /*if(input){
        copy(istream_iterator<Edge>(input), 
             istream_iterator<Edge>(), back_inserter(a));
        for(auto i : a){
            cout << i << endl;
        }
    }*/
    int n;//TODO СДЕЛАТЬ КАК ПАПА НАПИСАЛ
    vector<Edge> a;
    cin >> n;
    /*TODO: у тебя есть класс ребер из классов вершин. Надо найти сколько ребер
    исходит из вершин каждого ребра.*/ 
    return 0;
}