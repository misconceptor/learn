#include <bits/stdc++.h>
using namespace std;
const int MAX_NODES = 100;

struct Node{
    int numIn,numOut;
    Node() : numIn(0), numOut(0) {}

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
        return os << edge.inIdx << ' ' << edge.outIdx;// << endl;
    }
    bool isLoop(){
        return inIdx == outIdx;
    }
};

int main(){
    map<pair<int, int>, int> m;
    vector<Edge> edges, e1;
    int n;
    ifstream input("in.txt");

    if(!input) {
        cout << "error\n";
        return 0;
    }
    //PROBLEM: DOUBLE CIN FOR THE LAST EDGE
    /*for(int i=0;i<2;++i){
        Edge e;
        cin >> e;
        edges.push_back(e);
    }*/
    input >> n;
    for(int i=0;i<n;++i){
        Edge t;
        input >> t;
        e1.push_back(t); 
    }
    
    copy(e1.begin(), e1.end(), back_inserter(edges));
    /*cout << "size=" << edges.size() << endl;
    for(int i=0;i<edges.size();++i){
        cout << "(" << edges[i] << "):";
        if(edges[i].isLoop()) cout << "loop ";
        cout << nodes[edges[i].inIdx].numIn <<' '<< nodes[edges[i].inIdx].numOut <<"   ";
        cout << nodes[edges[i].outIdx].numIn <<' '<< nodes[edges[i].outIdx].numOut << endl;
    }
    return 0;*/
    for(int i=0;i<edges.size();++i){
        pair<int,int> curEdge = make_pair(edges[i].inIdx, edges[i].outIdx);
        m[curEdge] = nodes[edges[i].inIdx].numIn + nodes[edges[i].inIdx].numOut;
        if(!edges[i].isLoop()){
            m[curEdge] += nodes[edges[i].outIdx].numIn + nodes[edges[i].outIdx].numOut;
        }
    }
    for(auto i = m.begin(); i != m.end(); ++i){
        cout << "("<<i->first.first << '-' << i->first.second << "):  " << i->second << endl;
    }
    return 0;
}