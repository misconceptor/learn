#pragma once
//#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
#include "spdlog/spdlog.h"

#include <iostream>
#include <tuple>
#include <cstdint>
#include <ctime>

class Date {
public:
    Date() {
        std::time_t now = std::time(nullptr);
        std::tm* local_time = std::localtime(&now);
        year_ = local_time->tm_year + 1900;
        month_ = local_time->tm_mon + 1;
        day_ = local_time->tm_mday;
    }
    Date(int year, int month = 1, int day = 1) {
        checkValid(year,month,day);
        year_ = year;
        month_ = month;
        day_ = day;
    }
    ~Date() {}
    
    //Date operator+(int days) const;
    //Date operator-(int days) const;

// TODO перегрузить операторы сравнения


    int day() const noexcept {
        return day_;
    }
    int month() const noexcept {
        return month_;
    }
    int year() const noexcept {
        return year_;
    }
    int age() const noexcept; // возраст существа, на сегодня, если *this - дата отсчета
    int age(const Date& date) const noexcept; // возраст существа, на date, если *this - дата отсчета

    void checkValid(int y, int m, int d); //completed
    static bool isLeapYear(int year)  noexcept; //completed
    static int daysInMonth(int year, int month) noexcept; //completed
    std::string toString() const noexcept; //completed

private:
    int day_;
    int month_;
    int year_;

    std::shared_ptr<spdlog::logger> log_; //pointer to class

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    friend std::istream& operator>>(std::istream& is, Date& date);
};