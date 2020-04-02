//
// Created by Teodora Dan on 2019-06-08.
//

#ifndef INHERITANCE_PENGUIN_H
#define INHERITANCE_PENGUIN_H


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

    //std::string toString() const;
    std::string toString() const override;
};


#endif //INHERITANCE_PENGUIN_H
