//
// Created by Teodora Dan on 2019-05-13.
//

#include "Basket.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

Basket::Basket()
{
}

void Basket::add_basket(const Coat& element)
{
    myBasket.push_back(element);
}

Coat Basket::getCoat_basket(int position) {
    return myBasket.at(position);
}

Basket::~Basket()
{
}