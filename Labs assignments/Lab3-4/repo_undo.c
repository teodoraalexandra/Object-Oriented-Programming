//
// Created by Teodora Dan on 2019-03-17.
//

#include "repo_undo.h"

Repository_undo* createRepoUndo()
{
    Repository_undo* repository_undo = (Repository_undo*)malloc(sizeof(Repository_undo));
    repository_undo->offers = createDynamicArray(20);

    return repository_undo;
}

void destroyRepo_undo(Repository_undo *repository_undo)
{
    if (repository_undo == NULL)
        return;

    destroy(repository_undo->offers);
    free(repository_undo);
}

void add_undo(Repository_undo* repository_undo, Offer* offer)
{
    add_dynamic_array(repository_undo->offers, offer);
}

void delete_undo(Repository_undo* repository_undo, int* offer_id)
{
    delete_dynamic_array(repository_undo->offers, *offer_id);
}
