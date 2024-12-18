#pragma once
//#define _SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING
//#include "spdlog/spdlog.h"

#include <string>
#include "Date.h"

class Animal {
public:
    Animal() = delete;
    Animal(std::string nickName, Date dateOfBirth) 
    : dateOfBirth_(dateOfBirth) {
	    //log_->trace("Animal Ctor");
        nickName_ = new char[nickName.size() + 1];
        std::strcpy(nickName_, nickName.c_str());
    }

    Animal(const Animal& rhs) : dateOfBirth_(rhs.dateOfBirth()) {
        nickName_ = new char[strlen(rhs.nickName_) + 1];
        std::strcpy(nickName_, rhs.nickName_);
    } 
    Animal& operator=(const Animal& rhs) {
        dateOfBirth_ = rhs.dateOfBirth_;
        nickName_ = new char[strlen(rhs.nickName_) + 1];
        std::strcpy(nickName_, rhs.nickName_);
        return *this;
    }

    Animal(Animal&& rhs) : nickName_(nullptr) {
        swap(std::move(rhs));
    }
    void swap(Animal&& rhs) {
        std::swap(nickName_, rhs.nickName_);
        std::swap(dateOfBirth_, rhs.dateOfBirth_);
    }
    Animal& operator=(Animal&& rhs) {
        swap(std::move(rhs));
        return *this;
    }
    ~Animal() {
	    //log_->debug("Animal Dtor");
        delete nickName_;
    }

    std::string name() const noexcept;
    Date dateOfBirth() const noexcept;

    int age() const noexcept {
        return dateOfBirth_.age();
    } 
    int age(const Date& date) const noexcept {
        return dateOfBirth_.age(date);
    }

    virtual std::string toString() const noexcept;

   // virtual std::string description() const = 0;
protected:
    char* nickName_;
    Date dateOfBirth_;
    //std::shared_ptr<spdlog::logger> log_;
};