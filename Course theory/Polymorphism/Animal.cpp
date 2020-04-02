//
// Created by Teodora Dan on 2019-05-05.
//

#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string &name) : Mammal {name}
{
}

Animal::~Animal()
{
}

void Animal::breath()
{
    std::cout << "pfuuu" << this->name << std::endl;

    for (auto mammal : this->mammals) {
        mammal -> breath();
    }
}

void Animal::add(Mammal* mammal)
{
    this->mammals.push_back(mammal);
}