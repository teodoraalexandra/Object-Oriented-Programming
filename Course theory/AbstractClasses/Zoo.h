//
// Created by Teodora Dan on 2019-06-09.
//

#ifndef ABSTRACTCLASSES_ZOO_H
#define ABSTRACTCLASSES_ZOO_H


#pragma once
#include <vector>
#include "Filter.h"

class Zoo
{
private:
    std::vector<Animal*> animals;

public:
    Zoo(const std::vector<Animal*> a) : animals(a) {}
    std::vector<Animal*> filterBy(const Filter& filter);
};



#endif //ABSTRACTCLASSES_ZOO_H
