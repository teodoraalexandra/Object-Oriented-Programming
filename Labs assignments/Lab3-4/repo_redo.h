//
// Created by Teodora Dan on 2019-03-17.
//

#ifndef LAB3_REPO_REDO_H
#define LAB3_REPO_REDO_H

#endif //LAB3_REPO_REDO_H

#pragma once
#ifndef repository_redo_h
#define repository_redo_h
#include "domain.h"
#include <stdlib.h>
#include"DynamicArray.h"

typedef struct my_repository_redo
{
    DynamicArray* offers;
} Repository_redo;

Repository_redo* createRepoRedo();
void destroyRepo_redo(Repository_redo *repository_redo);
void add_redo(Repository_redo* repository_redo, Offer* offer);
void update_redo(Repository_redo* repository_redo, Offer* offer, int* offer_id);
void delete_redo(Repository_redo* repository_redo, int* offer_id);

#endif // repository_h