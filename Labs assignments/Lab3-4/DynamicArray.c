//
// Created by Teodora Dan on 2019-03-10.
//

#include "DynamicArray.h"

DynamicArray* createDynamicArray(int capacity)
{
    DynamicArray* dynamic_array = (DynamicArray*)malloc(sizeof(DynamicArray));
    // make sure that the space was allocated
    if (dynamic_array == NULL)
        return NULL;

    dynamic_array->capacity = capacity;
    dynamic_array->length = 0;

    // allocate space for the elements
    dynamic_array->elements = (TElement*)malloc(capacity * sizeof(TElement));
    if (dynamic_array->elements == NULL)
        return NULL;

    return dynamic_array;
}

void destroy(DynamicArray* array)
{
    if (array == NULL)
        return;
    for (int i = 0; i < array->length; i++)
        destroy_offer(array->elements[i]);

    // free the space allocated for the elements
    free(array->elements);
    array->elements = NULL;

    // free the space allocated for the dynamic array
    free(array);
    array = NULL;
}

// Resizes the array, allocating more space.
// If more space cannot be allocated, returns -1, else it returns 0.
int resize(DynamicArray* array)
{
    if (array == NULL)
        return 1;

    array->capacity *= 2;

    TElement* aux = (TElement*)malloc(array->capacity * sizeof(TElement));
    if (aux == NULL)
        return -1;
    for (int i = 0; i < array->length; i++)
        aux[i] = array->elements[i];
    free(array->elements);
    array->elements = aux;

    return 0;
}


void add_dynamic_array(DynamicArray *array, TElement t)
{
    if (array == NULL)
        return;
    if (array->elements == NULL)
        return;

    // resize the array, if necessary
    if (array->length == array->capacity)
        resize(array);
    array->elements[array->length++] = t;
}

void delete_dynamic_array(DynamicArray *array, int position)
{
    if (array == NULL)
        return;
    if (array->elements == NULL)
        return;

    if (position < 0 || position >= array->length)
        return;

    for (int i = position; i < array->length - 1; i++)
        array->elements[i] = array->elements[i + 1];

    array->length--;
}

void update_dynamic_array(DynamicArray *array, TElement t, int position)
{
    if (array == NULL)
        return;
    if (array->elements == NULL)
        return;

    array->elements[position] = t;
}

int getLength(DynamicArray* array)
{
    if (array == NULL)
        return -1;

    return array->length;
}

TElement getOffer(DynamicArray *array, int position)
{
    if (array == NULL)
        return NULL;
    return array->elements[position];
}


