#include "ui.h"
#include<string.h>
#include<stdio.h>
#include<stdbool.h>

int main()
{
    Repository* repository = createRepo();
    Repository_undo* repository_undo = createRepoUndo();
    Repository_redo* repository_redo = createRepoRedo();

    Controller* controller = createController(repository);
    Controller_undo* controller_undo = createControllerUndo(repository_undo);
    Controller_redo* controller_redo = createControllerRedo(repository_redo);

    UI* ui = createUI(controller, controller_undo, controller_redo);
    char inputCommand[100], inputCommand_copy[100];
    printMenu();

    while (1)
    {
        printf("Write down the command you want: ");

        gets(inputCommand);
        strcpy(inputCommand_copy, inputCommand);
        int j = 0;
        char* parameter[5];
        //parameter will be an array where we will have the input command split with delimiter

        Offer* offer;
        for (int i = 0; i < 5; i++)
        {
            parameter[i] = malloc(sizeof(char) * 50);
        }

        const char delimiter[] = " ";
        char *second_word_input; //for example: id, type, destination, price
        char *first_word_input = strtok(inputCommand, delimiter); //for example: add
        second_word_input = strtok(NULL, "\0");

        if (strcmp(first_word_input, "exit") == 0)
        {
            //destroy_ui(ui);
            break;
        }
        else if (strcmp(first_word_input,"add") == 0 )
        {
            ui_add(ui, second_word_input);
        }
        else if (strcmp(first_word_input, "list") == 0)
        {
            ui_list(ui, inputCommand_copy);
        }
        else if (strcmp(first_word_input, "update") == 0) {
            ui_update(ui, second_word_input);
        }
        else if (strcmp(first_word_input, "delete") == 0) {
            ui_delete(ui, inputCommand_copy);
        }
        else if (strcmp(first_word_input, "undo") == 0) {
            ui_undo(ui);
        }
        else if (strcmp(first_word_input, "redo") == 0) {
           ui_redo(ui);
        }
        else
        {
            printf("Wrong command!\n");
        }
    }
}
