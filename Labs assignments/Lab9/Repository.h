//
// Created by Teodora Dan on 2019-04-23.
//

#ifndef LAB9_REPOSITORY_H
#define LAB9_REPOSITORY_H

#endif //LAB9_REPOSITORY_H

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