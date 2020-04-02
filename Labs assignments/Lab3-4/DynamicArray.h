//
// Created by Teodora Dan on 2019-03-10.
//

#ifndef LAB3_DYNAMICARRAY_H
#define LAB3_DYNAMICARRAY_H

#endif //LAB3_DYNAMICARRAY_H

#pragma once

#ifndef dynamic_array_h
#define dynamic_array_h

#include <stdio.h>
#include "domain.h"

typedef Offer* TElement;
typedef void(*DestroyElementFunctionType)(void*);

typedef struct
{
    TElement* elements;
    int length;            // actual length of the array
    int capacity;        // maximum capacity of the array
    DestroyElementFunctionType destroyElemFct;
} DynamicArray;

void destroy(DynamicArray* array);
DynamicArray* createDynamicArray(int capacity);
int resize(DynamicArray* array);
void add_dynamic_array(DynamicArray *array, TElement t);
void delete_dynamic_array(DynamicArray *array, int position);
int getLength(DynamicArray* array);
//TElement get(DynamicArray* arr, int pos);
void update_dynamic_array(DynamicArray *array, TElement t, int position);
TElement getOffer(DynamicArray *array, int position);

#endif /* dynamic_array_h */
