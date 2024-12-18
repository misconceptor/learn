#pragma once
#include <string>
#include "Date.h"
#include "spdlog/spdlog.h"

class AbstractAnimal {
public:
    AbstractAnimal() = delete; //forbid the def. ctor
    AbstractAnimal(std::string nickName, Date dateOfBirth) 
    : dateOfBirth_(dateOfBirth) {
	    //log_->trace("Animal Ctor");
        nickName_ = new char[nickName.size() + 1];
        std::strcpy(nickName_, nickName.c_str());
    }

    AbstractAnimal(const AbstractAnimal& rhs) : dateOfBirth_(rhs.dateOfBirth()) {
        nickName_ = new char[strlen(rhs.nickName_) + 1];
        std::strcpy(nickName_, rhs.nickName_);
    } 
    AbstractAnimal& operator=(const AbstractAnimal& rhs) {
        dateOfBirth_ = rhs.dateOfBirth_;
        nickName_ = new char[strlen(rhs.nickName_) + 1];
        std::strcpy(nickName_, rhs.nickName_);
        return *this;
    }

    AbstractAnimal(AbstractAnimal&& rhs) : nickName_(nullptr) {
        swap(std::move(rhs));
    }
    void swap(AbstractAnimal&& rhs) {
        std::swap(nickName_, rhs.nickName_);
        std::swap(dateOfBirth_, rhs.dateOfBirth_);
    }
    AbstractAnimal& operator=(AbstractAnimal&& rhs) {
        swap(std::move(rhs));
        return *this;
    }
    virtual ~AbstractAnimal() {
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

    virtual std::string toString() const noexcept = 0;//for inheritance

    virtual std::string description() const = 0;
protected:
    char* nickName_;
    Date dateOfBirth_;
    //std::shared_ptr<spdlog::logger> log_;
};