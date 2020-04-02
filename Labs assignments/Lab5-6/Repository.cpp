//
// Created by Teodora Dan on 2019-03-23.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Repository.h"
#include "Basket.h"
using namespace std;

//Basket basket;

template <typename T>
Repository<T>::Repository()
{
}

template <typename T>
void Repository<T>::add(const coat& element)
{
    vector.add(element);
}

template <typename T>
void Repository<T>::remove(int position)
{
    vector.remove(position);
}

template <typename T>
void Repository<T>::update(const coat& element, int position)
{
    vector.update(element, position);
}

template <typename T>
int Repository<T>::size()
{
    return vector.getSize();
}

template <typename T>
Coat Repository<T>::getCoat(int position) {
    return vector.getCoat(position);
}

template <typename T>
Repository<T>::~Repository()
{
}

template class Repository<DynamicVector>;

