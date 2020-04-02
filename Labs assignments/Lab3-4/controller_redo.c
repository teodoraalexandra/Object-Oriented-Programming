//
// Created by Teodora Dan on 2019-03-17.
//

#include "string.h"
#include "controller_redo.h"

Controller_redo* createControllerRedo(Repository_redo* repository_redo)
{
    Controller_redo* controller_redo = (Controller_redo*)malloc(sizeof(Controller_redo));
    controller_redo->repository_redo = repository_redo;

    return controller_redo;
}

void destroy_controller_redo(Controller_redo* controller_redo)
{
    destroyRepo_redo(controller_redo->repository_redo);

    free(controller_redo);
}

bool offer_with_a_given_id_exists_redo(Repository_redo* repository_redo, Offer* offer)
{
    for (int i = 0; i < repository_redo->offers->length; i++)
    {
        if (get_id(repository_redo->offers->elements[i]) == get_id(offer))
        {
            return true;
        }
    }
    return false;
}

void controller_add_redo(Controller_redo* controller_redo, Offer* offer)
{
    add_redo(controller_redo->repository_redo, offer);
}

void controller_update_redo(Controller_redo* controller_redo, Offer* offer, int* offer_id)
{
    update_redo(controller_redo->repository_redo, offer, offer_id);
}

void controller_delete_redo(Controller_redo* controller_redo, int* offer_id)
{
    delete_redo(controller_redo->repository_redo, offer_id);
}