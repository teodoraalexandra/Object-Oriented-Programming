//
// Created by Teodora Dan on 2019-04-07.
//

#include "DynamicVector.h"
#include <iostream>
#include <cstring>
using namespace std;

DynamicVector::DynamicVector(int dynamicVector_capacity)
{
    this->size = 0;
    this->capacity = dynamicVector_capacity;

    this->elements = new player[this->capacity];
}

DynamicVector::DynamicVector(const DynamicVector & vector)
{
    this->size = vector.size;
    this->capacity = vector.capacity;
    this->elements = new player[this->capacity];

    for (int i = 0; i < vector.size; i++)
        this->elements[i] = vector.elements[i];
}

int DynamicVector::getSize() {
    return this->size;
}

Player DynamicVector::getElement(int position) {
    return this->elements[position];
}

DynamicVector & DynamicVector::operator=(const DynamicVector & vector)
{
    if (this == &vector)
        return *this;

    this->capacity = vector.capacity;
    this->size = vector.size;

    delete[] this->elements;

    this->elements = new player[this->capacity];
    for (int i = 0; i < vector.size; i++)
        this->elements[i] = vector.elements[i];

    return *this;
}


DynamicVector::~DynamicVector()
{
    delete[] this->elements;
}

void DynamicVector::add(const player & element)
{
    this->elements[this->size++] = element;
}

void DynamicVector::remove(int position) {
    for (int i = position; i < this->size - 1; i++)
        this->elements[i] = this->elements[i + 1];

    this->size--;
}

void DynamicVector::update(const player & element, int position) {
    this->elements[position] = element;
}
