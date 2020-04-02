//
// Created by Teodora Dan on 2019-04-07.
//

#ifndef MODEL1_DYNAMICVECTOR_H
#define MODEL1_DYNAMICVECTOR_H

#endif //MODEL1_DYNAMICVECTOR_H

#pragma once
#include "Player.h"

typedef Player player;

class DynamicVector
{
private:
    int size, capacity;
    player* elements;

public:
    DynamicVector(int dynamicVector_capacity = 10);
    DynamicVector(const DynamicVector& vector);
    DynamicVector& operator=(const DynamicVector& vector);
    ~DynamicVector();

    void add(const player& element);
    void remove(int position);
    void update(const player& element, int position);
    int getSize();
    Player getElement(int position);
};