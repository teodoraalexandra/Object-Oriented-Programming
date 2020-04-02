//
// Created by Teodora Dan on 2019-03-10.
//

#ifndef LAB3_UI_H
#define LAB3_UI_H

#endif //LAB3_UI_H

#ifndef UI_h
#define UI_h
#include "controller.h"
#include "controller_undo.h"
#include "controller_redo.h"
#include<stdbool.h>

typedef struct my_ui
{
    Controller* controller;
    Controller_undo* controller_undo;
    Controller_redo* controller_redo;
} UI;

UI* createUI(Controller* controller, Controller_undo* controller_undo, Controller_redo* controller_redo);
void destroy_ui(UI* ui);
void printMenu();
void ui_add(UI* ui, char* inputCommand);
void ui_list(UI* ui, char* inputCommand);
void ui_update(UI* ui, char* inputCommand);
void ui_delete(UI* ui, char* inputCommand);
void ui_undo(UI* ui);
void ui_redo(UI* ui);

#endif // !UI_h