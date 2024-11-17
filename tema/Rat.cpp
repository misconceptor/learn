#include "Rat.h"
#include <math.h>
#include <iostream>
#include <compare>

Rat::Rat() : num(0), denom(1) {};
Rat::Rat(int n) : num(n), denom(1) {}
Rat::Rat(int n, int m) : num(n), denom(m) {}

const int& Rat::Numerator (){
    return num;
}
const int& Rat::Denominator (){
    return denom;
}
Rat const Rat::operator+(const Rat& other) const {
    Rat r1 = Rat(num*other.denom + other.num*denom, denom*other.denom);
    r1.Normalize();
    return r1;
}
Rat const Rat::operator*(const Rat& other) const{
    Rat r1 = Rat(num * other.num, denom * other.denom);
    r1.Normalize();
    return r1;
}
Rat const Rat::operator-(const Rat& other) const {
    Rat r1 = Rat(num*other.denom - other.num*denom, denom*other.denom);
    r1.Normalize();
    return r1;
}
Rat const Rat::operator/(const Rat& other) const {
    Rat r1 = Rat(num*other.denom, denom*other.num);
    r1.Normalize();
    return r1;
}

void Rat::Normalize(){
    int a = num;
    int b = denom;
    a = abs(a);
    b = abs(b);
    while(a>0 && b>0){
        a>b ? a%=b : b%=a;
    }
    num /= (a+b);
    denom /= (a+b);
};
void Rat::Show(){
    std::cout << num << ' ' << denom << '\n';
}
std::istream& operator >>(std::istream& is, Rat& r){
    int n,d;
    is >> n;
    is >> d;
    r.num = n; 
    r.denom = d;
    return is;
}
std::ostream& operator <<(std::ostream& os, Rat& r){
    os << r.num << '/' << r.denom;
    return os;
}