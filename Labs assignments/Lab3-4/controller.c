//
// Created by Teodora Dan on 2019-03-10.
//

#include <string.h>
#include "controller.h"

Controller* createController(Repository* repo)
{
    Controller* controller = (Controller*)malloc(sizeof(Controller));
    controller->repo = repo;

    return controller;
}

void destroy_controller(Controller* controller)
{
    destroyRepo(controller->repo);

    free(controller);
}

bool offer_with_a_given_id_exists(Repository* repository, Offer* offer)
{
    for (int i = 0; i < repository->offers->length; i++)
    {
        if (get_id(repository->offers->elements[i]) == get_id(offer))
        {
            return true;
        }
    }
    return false;
}

void controller_add(Controller* controller, Offer* offer)
{
    add(controller->repo, offer);
}

void controller_update(Controller* controller, Offer* offer, int* offer_id)
{
    update(controller->repo, offer, offer_id);
}

void controller_delete(Controller* controller, int* offer_id)
{
    delete(controller->repo, offer_id);
}


