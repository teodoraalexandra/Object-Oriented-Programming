//
// Created by Teodora Dan on 2019-06-08.
//

#ifndef INHERITANCE_ANIMAL_H
#define INHERITANCE_ANIMAL_H


#pragma once
#include <string>

#pragma once
#include <string>

class Animal
{
protected:
    std::string colour;
    double weight;

public:
    Animal(std::string _colour, double _weight);
    //~Animal();
    virtual ~Animal();

    std::string getColour() const;
    double getWeight() const;

    //std::string toString() const;

    virtual std::string toString() const;	// allows polymorphism
};

#endif //INHERITANCE_ANIMAL_H
