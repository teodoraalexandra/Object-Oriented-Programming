//
// Created by Teodora Dan on 2019-06-09.
//

#ifndef ABSTRACTCLASSES_PENGUIN_H
#define ABSTRACTCLASSES_PENGUIN_H


#pragma once
#include "Animal.h"

class Penguin: public Animal
{
private:
    std::string type;

public:
    Penguin(std::string _colour, double _weight, std::string _type);
    ~Penguin();

    std::string getType() const;

    std::string toString() const override;

    void speak() const override;
};



#endif //ABSTRACTCLASSES_PENGUIN_H
