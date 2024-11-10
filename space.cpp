#include <compare>
#include <iostream>
using namespace std;
struct MyInt {
    int value;
    explicit MyInt(int val): value{val} { }
    auto operator<=>(const MyInt& rhs) const {
        return value <=> rhs.value;
    }
};

int main(){
    MyInt a(5);
    MyInt b(8);
    auto c = (a<=>b);
    cout << (c<0) << endl;
}
