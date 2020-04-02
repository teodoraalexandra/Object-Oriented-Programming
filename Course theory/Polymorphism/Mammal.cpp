//
// Created by Teodora Dan on 2019-05-05.
//

#include "Mammal.h"
#include <iostream>

Mammal::Mammal(const std::string &name) : name {name}
{
}

Mammal::~Mammal()
{
}

Horse::Horse(const std::string &name, int id_horse) :
    Mammal {name} , id_horse {id_horse}
{
}

void Horse::breath()
{
    std::cout << "Ihaa";
}