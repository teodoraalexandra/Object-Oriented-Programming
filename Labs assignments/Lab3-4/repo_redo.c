//
// Created by Teodora Dan on 2019-03-17.
//

#include "repo_redo.h"

Repository_redo* createRepoRedo()
{
    Repository_redo* repository_redo = (Repository_redo*)malloc(sizeof(Repository_redo));
    repository_redo->offers = createDynamicArray(20);

    return repository_redo;
}

void destroyRepo_redo(Repository_redo *repository_redo)
{
    if (repository_redo == NULL)
        return;

    destroy(repository_redo->offers);
    free(repository_redo);
}

void add_redo(Repository_redo* repository_redo, Offer* offer)
{
    add_dynamic_array(repository_redo->offers, offer);
}

void update_redo(Repository_redo* repository_redo, Offer* offer, int* offer_id) {
    update_dynamic_array(repository_redo->offers, offer, *offer_id);
}

void delete_redo(Repository_redo* repository_redo, int* offer_id)
{
    delete_dynamic_array(repository_redo->offers, *offer_id);
}