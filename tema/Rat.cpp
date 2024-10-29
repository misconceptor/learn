#include "Rat.h"
#include <math.h>
#include <iostream>

class Rat{
public:
    Rat() : num(0), denom(1) {}
    Rat(int n) : num(n), denom(1) {}
    Rat(int n, int m) : num(n), denom(m) {}

    const int& Numerator (){
        return num;
    }
    const int& Denominator(){
        return denom;
    }

    Rat const operator+(const Rat& other) const {
        return Rat(num*other.denom + other.num*denom, denom*other.denom);
    }
    Rat const operator-(const Rat& other) const {
        return Rat(num*other.denom - other.num*denom, denom*other.denom);
    }

    void Normalize(){
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

    void Show(){
        std::cout << num << ' ' << denom << '\n';
    };
private:
    int num,denom;
};