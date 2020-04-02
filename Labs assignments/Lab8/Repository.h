//
// Created by Teodora Dan on 2019-04-27.
//

#ifndef LAB8_9_REPOSITORY_H
#define LAB8_9_REPOSITORY_H

#endif //LAB8_9_REPOSITORY_H

#pragma once

#include "Coat.h"
#include <vector>

class Repository
{
public:
    Repository();
    std::vector<Coat> vector_of_coats;
    virtual void add(const Coat& coat);
    virtual void remove(int position);
    virtual void update(const Coat& coat, int position);
    int size();
    Coat getCoat(int position);
    ~Repository();
};

class FakeRepository : public Repository {
public:
    FakeRepository();
    void add(const Coat &coat) override;
    void remove(int position) override;
    void update(const Coat &coat, int position) override;
};