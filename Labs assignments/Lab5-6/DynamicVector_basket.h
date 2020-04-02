//
// Created by Teodora Dan on 2019-04-07.
//

#ifndef LAB5_DYNAMICVECTOR_BASKET_H
#define LAB5_DYNAMICVECTOR_BASKET_H

#endif //LAB5_DYNAMICVECTOR_BASKET_H

#pragma once
#include "Coat.h"

typedef Coat coat;

class DynamicVector_basket
{
private:
    int size, capacity;
    coat* elements;

public:
    DynamicVector_basket(int dynamicVector_capacity = 10);
    DynamicVector_basket(const DynamicVector_basket& vector_basket);
    DynamicVector_basket& operator=(const DynamicVector_basket& vector_basket);
    ~DynamicVector_basket();

    void add_basket(const coat& coat);
    Coat getCoat_basket(int position);
};