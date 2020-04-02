//
// Created by Teodora Dan on 2019-06-08.
//

#ifndef INHERITANCE_DOG_H
#define INHERITANCE_DOG_H

#pragma once
#include "Animal.h"

#pragma once
#include "Animal.h"

class Dog :	public Animal
{
private:
    std::string breed;
    double furLength;

public:
    Dog(std::string _colour, double _weight, std::string _breed, double _furLength);
    ~Dog();

    std::string getBreed() const;
    double getFurLength() const;

    //std::string toString() const;

    std::string toString() const override;
};


#endif //INHERITANCE_DOG_H
