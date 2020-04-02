//
// Created by Teodora Dan on 2019-04-08.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Repository.h"

template <typename T>
Repository<T>::Repository() {}

template <typename T>
void Repository<T>::add(const player& player) {
    //using the dynamic vector, we will add the player
    vector.add(player);
}

template <typename T>
int Repository<T>::size() {
    return vector.getSize();
}

template <typename T>
Player Repository<T>::getPlayer(int position) {
    return vector.getElement(position);
}

template <typename T>
Repository<T>::~Repository() {}

template class Repository<DynamicVector>;