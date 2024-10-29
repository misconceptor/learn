#include <bits/stdc++.h>
using namespace std;

class Car {
private:
    int power, cost;
    string name; 
public:
    Car (int p, int c, string s) {
        power = p;
        cost = c;
        name = s;
    }
    Car (int p, int c) : power(p), cost(c), name("default") {}
    void rename(string newName); 
    void showParameters(){
        cout << power << ' ' << cost << ' ' << name << endl;
    }
};
void Car::rename(string newName) {
    name = newName;
}

template <typename A> 
A add(A x, A y){
    return max(x,y);
}

int main(){
    Car a(1500,100);
    a.showParameters();
    return 0;
}
