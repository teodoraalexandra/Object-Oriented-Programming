//
// Created by Teodora Dan on 2019-04-23.
//

#ifndef LAB9_BASKET_H
#define LAB9_BASKET_H

#endif //LAB9_BASKET_H

#pragma once

#include "Coat.h"
#include <vector>

class Basket
{
private:
    //std::vector<Coat> myBasket;

public:
    Basket();
    std::vector<Coat> myBasket;
    void add_basket(const Coat& element);
    Coat getCoat_basket(int position);
    ~Basket();
};