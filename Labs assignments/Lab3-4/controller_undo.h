//
// Created by Teodora Dan on 2019-03-17.
//

#ifndef LAB3_CONTROLLER_UNDO_H
#define LAB3_CONTROLLER_UNDO_H

#endif //LAB3_CONTROLLER_UNDO_H

#pragma once
#ifndef controller_undo_h
#define controller_undo_h
#include "repo_undo.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct my_controller_undo
{
    Repository_undo* repository_undo;
} Controller_undo;

Controller_undo* createControllerUndo(Repository_undo* repo_undo);
void destroy_controller_undo(Controller_undo* controller_undo);
void controller_add_undo(Controller_undo* controller_undo, Offer* offer);
void controller_delete_undo(Controller_undo* controller_undo, int* offer_id);
bool offer_with_a_given_id_exists_undo(Repository_undo* repository_undo, Offer* offer);

#endif //controller_h
