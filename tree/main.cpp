#include <bits/stdc++.h>
#include "Tree.cpp"
using namespace std;

int main(){
    Tree t;
    int n;
    cin >> n;
    while(n--){
        int k;
        cin >> k;
        t.insert(k);
    }
    Node* a = t.task();
    cout << a->val << endl;
    return 0;
}