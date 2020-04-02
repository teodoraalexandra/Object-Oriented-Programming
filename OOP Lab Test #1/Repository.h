//
// Created by Teodora Dan on 2019-04-08.
//

#ifndef MODEL1_REPOSITORY_H
#define MODEL1_REPOSITORY_H

#endif //MODEL1_REPOSITORY_H

#pragma once

#include "DynamicVector.h"

template <typename T>

class Repository {
private:
    T vector;
public:
    Repository<T>();

    void add(const player &player);

    int size();

    Player getPlayer(int position);

    ~Repository();
};
