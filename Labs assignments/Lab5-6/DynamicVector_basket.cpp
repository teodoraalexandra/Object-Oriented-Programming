//
// Created by Teodora Dan on 2019-04-07.
//

#include "DynamicVector_basket.h"
#include <iostream>
#include <cstring>
using namespace std;

DynamicVector_basket::DynamicVector_basket(int dynamicVector_capacity)
{
    this->size = 0;
    this->capacity = dynamicVector_capacity;

    this->elements = new coat[this->capacity];
}

DynamicVector_basket::DynamicVector_basket(const DynamicVector_basket & vector_basket)
{
    this->size = vector_basket.size;
    this->capacity = vector_basket.capacity;
    this->elements = new coat[this->capacity];

    for (int i = 0; i < vector_basket.size; i++)
        this->elements[i] = vector_basket.elements[i];
}

Coat DynamicVector_basket::getCoat_basket(int position) {
    return this->elements[position];
}

DynamicVector_basket & DynamicVector_basket::operator=(const DynamicVector_basket & vector_basket)
{
    if (this == &vector_basket)
        return *this;

    this->capacity = vector_basket.capacity;
    this->size = vector_basket.size;

    delete[] this->elements;

    this->elements = new coat[this->capacity];
    for (int i = 0; i < vector_basket.size; i++)
        this->elements[i] = vector_basket.elements[i];

    return *this;
}


DynamicVector_basket::~DynamicVector_basket()
{
    delete[] this->elements;
}

void DynamicVector_basket::add_basket(const coat & coat)
{
    this->elements[this->size++] = coat;
}
