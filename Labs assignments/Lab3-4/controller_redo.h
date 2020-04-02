//
// Created by Teodora Dan on 2019-03-17.
//

#ifndef LAB3_CONTROLLER_REDO_H
#define LAB3_CONTROLLER_REDO_H

#endif //LAB3_CONTROLLER_REDO_H

#pragma once
#ifndef controller_redo_h
#define controller_redo_h
#include "repo_redo.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct my_controller_redo
{
    Repository_redo* repository_redo;
} Controller_redo;

Controller_redo* createControllerRedo(Repository_redo* repo_redo);
void destroy_controller_redo(Controller_redo* controller_redo);
void controller_add_redo(Controller_redo* controller_redo, Offer* offer);
void controller_update_redo(Controller_redo* controller_redo, Offer* offer, int* offer_id);
void controller_delete_redo(Controller_redo* controller_redo, int* offer_id);
bool offer_with_a_given_id_exists_redo(Repository_redo* repository_redo, Offer* offer);

#endif //controller_h