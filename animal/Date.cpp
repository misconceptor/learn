//#define _CRT_SECURE_NO_WARNINGS
//#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
//#include "spdlog/spdlog.h"

#include <memory>
#include <exception>
#include <sstream>
#include <iostream>
#include <tuple>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

#include "Date.h"


/*int Date::age() const noexcept {
    Date today();
    return this->age(today);
}
int Date::age(const Date& date) const noexcept { // age in days
    return 0;
    //return age;
}*/
std::string Date::toString() const noexcept {
    std::string out;
    out = std::to_string(year_)+" "+std::to_string(month_)+" "+std::to_string(day_);
    return out; 
}
bool Date::isLeapYear(int year) noexcept {
    return (year % 4) == 0;
}

int Date::daysInMonth(int year, int month) noexcept {
    if(month == 2) {
        if(isLeapYear(year)){
            return 29;
        }
        return 28;
    }
    if(month == 1 || month == 3 || month == 5 ||
       month == 7 || month == 8 || month == 10 || month == 12) 
    {
        return 31;
    }
    return 30;
}

void Date::checkValid(int y, int m, int d) {
    if(m < 1 || m > 12 || d < 1 || d > daysInMonth(y,m)){
        throw std::invalid_argument("the date is incorrect");
    }
}

/*
Date Date::operator+(int days) const {
    return result;
}

Date Date::operator-(int days) const {
    return result;
}


bool Date::operator<(const Date& rhs) const {
// можно использовать std::tie

    return ...
}*/

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
    int y,m,d;
    is >> y >> m >> d;
    date.checkValid(y,m,d);
    date.year_ = y;
    date.month_= m;
    date.day_= d;
    return is;
}