//
// Created by Teodora Dan on 2019-03-10.
//

#ifndef LAB3_REPO_H
#define LAB3_REPO_H

#endif //LAB3_REPO_H

#pragma once
#ifndef repository_h
#define repository_h
#include "domain.h"
#include <stdlib.h>
#include"DynamicArray.h"

typedef struct my_repository
{
    DynamicArray* offers;
} Repository;

Repository* createRepo();
void destroyRepo(Repository *repository);
void add(Repository* repository, Offer* offer);
void update(Repository* repository, Offer* offer, int* offer_id);
void delete(Repository* repository, int* offer_id);

#endif // repository_h
