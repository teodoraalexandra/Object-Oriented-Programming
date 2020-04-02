//
// Created by Teodora Dan on 2019-03-17.
//

#include "string.h"
#include "controller_undo.h"

Controller_undo* createControllerUndo(Repository_undo* repository_undo)
{
    Controller_undo* controller_undo = (Controller_undo*)malloc(sizeof(Controller_undo));
    controller_undo->repository_undo = repository_undo;

    return controller_undo;
}

void destroy_controller_undo(Controller_undo* controller_undo)
{
    destroyRepo_undo(controller_undo->repository_undo);

    free(controller_undo);
}

bool offer_with_a_given_id_exists_undo(Repository_undo* repository_undo, Offer* offer)
{
    for (int i = 0; i < repository_undo->offers->length; i++)
    {
        if (get_id(repository_undo->offers->elements[i]) == get_id(offer))
        {
            return true;
        }
    }
    return false;
}

void controller_add_undo(Controller_undo* controller_undo, Offer* offer)
{
    add_undo(controller_undo->repository_undo, offer);
}

void controller_delete_undo(Controller_undo* controller_undo, int* offer_id)
{
    delete_undo(controller_undo->repository_undo, offer_id);
}