#include <iostream>
#include <compare>
#include "Rat.cpp"
using namespace std;

int main(){
    cout << __cplusplus << '\n';
    Rat a,b;
    cin >> a;
    cin >> b;
    auto res = a <=> b;
    if(res<0) cout << "<\n";
	else if(res>0) cout << ">\n";
	else cout << "=\n"; 
    return 0;
}