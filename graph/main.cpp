#include <bits/stdc++.h>
using namespace std;
const int MAX_NODES = 100;

struct Node{
    int numIn,numOut;
    Node() : numIn(0), numOut(0) {
    }

    void incIn(){
        ++numIn;
    }
    void incOut(){
        ++numOut;
    }
};

Node nodes[MAX_NODES];

struct Edge
{
    int inIdx, outIdx;
    Edge() {}
    friend istream & operator >> (istream & in, Edge & edge){
        in >> edge.inIdx >> edge.outIdx; 
        nodes[edge.inIdx].incOut();
        nodes[edge.outIdx].incIn();
        return in;
    }
    friend ostream& operator << (ostream& os, Edge const& edge){ 
        return os << edge.inIdx << ' ' << edge.outIdx << endl;
    }
    bool isLoop(){
        return inIdx == outIdx;
    }
};


int main(){
    //ifstream input("in.txt");
    /*if(input){
        copy(istream_iterator<Edge>(input), 
             istream_iterator<Edge>(), back_inserter(a));
        for(auto i : a){
            cout << i << endl;
        }
    }*/


    //сам нод даже не хранит свое значение, тк это его номер в массиве
    //TODO сделай перебор ребер и подсчет inOut из каждой ноды которая !isLoop()
    int n;
    cin >> n;
    Edge edges[n];
    for(int i=0;i<n;++i){
        cin >> edges[i];
    }
    for(int i=0;i<n;++i){
        cout << edges[i];
    }
    //todo print what you need
    /*TODO: у тебя есть класс ребер из классов вершин. Надо найти сколько ребер
    исходит из вершин каждого ребра.*/ 
    return 0;
}