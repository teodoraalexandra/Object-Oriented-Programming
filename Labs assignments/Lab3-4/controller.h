//
// Created by Teodora Dan on 2019-03-10.
//

#ifndef LAB3_CONTROLLER_H
#define LAB3_CONTROLLER_H

#endif //LAB3_CONTROLLER_H

#pragma once
#ifndef controller_h
#define controller_h
#include "repo.h"
#include <stdio.h>
#include <stdbool.h>


typedef struct my_controller
{
    Repository* repo;
} Controller;

Controller* createController(Repository* repo);
void destroy_controller(Controller* controller);
//void split_cmd(char* cmd[], char* parameter[20]);
void controller_add(Controller* controller, Offer* offer);
void controller_delete(Controller* controller, int* offer_id);
void controller_update(Controller* controller, Offer* offer, int* offer_id);
bool offer_with_a_given_id_exists(Repository* repository, Offer* offer);




#endif //controller_h
