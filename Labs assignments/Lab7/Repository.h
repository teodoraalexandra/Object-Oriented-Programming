//
// Created by Teodora Dan on 2019-04-11.
//

#ifndef LAB8_REPOSITORY_H
#define LAB8_REPOSITORY_H

#endif //LAB8_REPOSITORY_H

#pragma once

#include "Coat.h"
#include <vector>

class Repository
{
private:
    //std::vector<Coat> myVector;

public:
    Repository();
    std::vector<Coat> myVector;
    void add(const Coat& element);
    void remove(int position);
    void update(const Coat& element, int position);
    int size();
    Coat getCoat(int position);
    ~Repository();
};
