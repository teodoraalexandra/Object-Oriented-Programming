//
// Created by Teodora Dan on 2019-04-23.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Basket.h"
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