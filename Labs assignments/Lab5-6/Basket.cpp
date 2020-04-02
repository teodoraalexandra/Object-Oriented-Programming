//
// Created by Teodora Dan on 2019-03-30.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Basket.h"
using namespace std;

template <typename T>
Basket<T>::Basket()
{
}

template <typename T>
void Basket<T>::add_basket(const coat& element)
{
    vector_basket.add_basket(element);
}

template <typename T>
Coat Basket<T>::getCoat_basket(int position) {
    return vector_basket.getCoat_basket(position);
}

template <typename T>
Basket<T>::~Basket()
{
}

template class Basket<DynamicVector_basket>;

