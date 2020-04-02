//
// Created by Teodora Dan on 2019-03-23.
//

#ifndef LAB5_REPOSITORY_H
#define LAB5_REPOSITORY_H
#pragma once

#endif //LAB5_REPOSITORY_H

#include "DynamicVector.h"

template <typename T>

class Repository
{
private:
    T vector;

public:
    Repository<T>();
    void add(const coat& element);
    void remove(int position);
    void update(const coat& element, int position);
    int size();
    Coat getCoat(int position);
    ~Repository();
};
