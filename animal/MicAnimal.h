#pragma once
#include "AbstractAnimal.h"
class MicAnimal : public AbstractAnimal {
public :
    MicAnimal(std::string nickName, Date dateOfBirth, std::string chip) 
    : AbstractAnimal(nickName, dateOfBirth), chip_(chip) {
	    //log_->trace("Animal Ctor");
    }

    MicAnimal(const MicAnimal& rhs) : AbstractAnimal(rhs), chip_(rhs.chip_){}
    /* 
    AbstractAnimal& operator=(const AbstractAnimal& rhs) {
        dateOfBirth_ = rhs.dateOfBirth_;
        nickName_ = new char[strlen(rhs.nickName_) + 1];
        std::strcpy(nickName_, rhs.nickName_);
    }
*/
    MicAnimal(MicAnimal&& rhs) : AbstractAnimal(std::move(rhs)) {
        swap(std::move(rhs));
    }
    void swap(MicAnimal&& rhs) {
        std::swap(chip_, rhs.chip_);
    }
    MicAnimal& operator=(MicAnimal&& rhs) {
        AbstractAnimal::swap(std::move(rhs)); 
        swap(std::move(rhs));
        return *this;
    }

    bool checkChip(const std::string& chip);
    std::string toString() const noexcept override {
        return "a";
    }
    std::string description() const override{ 
        std::string out = "Name: ";
        out += std::string(this->nickName_) + std::string(", ");
        
        out += std::string("DateOfBirth: ") + dateOfBirth_.toString() + ' ';
        out += std::string("Age: ") + std::to_string(this->age());
        out += std::string(", Chip: ") + this->chip_;
        return out;
    }
private:
    std::string chip_;
};