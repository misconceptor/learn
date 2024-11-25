#include "Rat.h"
#include <math.h>
#include <iostream>
#include <compare>

Rat::Rat() : num(0), denom(1) {};
Rat::Rat(int n) : num(n), denom(1) {}
Rat::Rat(int n, int m) : num(n), denom(m) {}

int& Rat::Numerator() {
    return num;
}
const int& Rat::Numerator() const {
    std::cout << "constnum\n";
    return num;
}
int& Rat::Denominator() {
    return denom;
}
const int& Rat::Denominator() const {
    std::cout << "constdenom\n";
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
Rat& Rat::operator++() {
    num += denom;
    Normalize();
    return *this;
}
Rat const Rat::operator++(int){
    Rat result = *this;
    num += denom;
    Normalize();
    return result;
}
Rat& Rat::operator+=(const Rat& other){
    num = num * other.denom + other.num * denom;
    denom *= other.denom;
    Normalize();
    return *this;
}
Rat& Rat::operator+=(int other){
    num += denom * other;
    Normalize();
    return *this;
}
Rat& Rat::operator-=(const Rat& other){
    num = num * other.denom - other.num * denom;
    denom *= other.denom;
    Normalize();
    return *this;
}
Rat& Rat::operator-=(int other){
    num -= denom * other;
    Normalize();
    return *this;
}

Rat::operator double() const {
    return (double)num / denom;
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