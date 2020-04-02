//
// Created by Teodora Dan on 2019-03-10.
//

#include "repo.h"

Repository* createRepo()
{
    Repository* repository = (Repository*)malloc(sizeof(Repository));
    repository->offers = createDynamicArray(20);

    return repository;
}

void destroyRepo(Repository *repository)
{
    if (repository == NULL)
        return;

    destroy(repository->offers);
    free(repository);
}

void add(Repository* repository, Offer* offer)
{
    add_dynamic_array(repository->offers, offer);
}

void update(Repository* repository, Offer* offer, int* offer_id) {
    update_dynamic_array(repository->offers, offer, *offer_id);
}

void delete(Repository* repository, int* offer_id)
{
    delete_dynamic_array(repository->offers, *offer_id);
}
