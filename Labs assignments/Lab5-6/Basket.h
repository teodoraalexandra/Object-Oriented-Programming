//
// Created by Teodora Dan on 2019-03-30.
//

#ifndef LAB5_BASKET_H
#define LAB5_BASKET_H

#endif //LAB5_BASKET_H

#pragma once

#include "DynamicVector_basket.h"

template <typename T>

class Basket
{
private:
    T vector_basket;

public:
    Basket<T>();
    void add_basket(const coat& element);
    Coat getCoat_basket(int position);
    ~Basket();
};