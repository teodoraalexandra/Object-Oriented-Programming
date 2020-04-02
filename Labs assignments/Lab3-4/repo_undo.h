//
// Created by Teodora Dan on 2019-03-17.
//

#ifndef LAB3_REPO_UNDO_H
#define LAB3_REPO_UNDO_H

#endif //LAB3_REPO_UNDO_H

#pragma once
#ifndef repository_undo_h
#define repository_undo_h
#include "domain.h"
#include <stdlib.h>
#include"DynamicArray.h"

typedef struct my_repository_undo
{
    DynamicArray* offers;
} Repository_undo;

Repository_undo* createRepoUndo();
void destroyRepo_undo(Repository_undo *repository_undo);
void add_undo(Repository_undo* repository_undo, Offer* offer);
void delete_undo(Repository_undo* repository_undo, int* offer_id);

#endif // repository_h
