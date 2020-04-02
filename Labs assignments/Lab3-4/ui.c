//
// Created by Teodora Dan on 2019-03-10.
//

#include "ui.h"
#include "string.h"
#include "limits.h"
int how_much_undo = 0;

UI* createUI(Controller* controller, Controller_undo* controller_undo, Controller_redo* controller_redo)
{
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->controller = controller;
    ui->controller_undo = controller_undo;
    ui->controller_redo = controller_redo;

    return ui;
}

void destroy_ui(UI* ui)
{
    destroy_controller(ui->controller);
    destroy_controller_undo(ui->controller_undo);
    destroy_controller_redo(ui->controller_redo);

    free(ui);
}

void printMenu()
{
    printf("Commands: \n\n");
    printf("        Add an offer.		add <id, type, destination, price>\n");
    printf("       Update an offer.		update <id, newType, newDestination, newPrice>\n");
    printf("       Delete an offer.		delete <id>\n");
    printf("       List all offers.		list\n");
    printf("    List by a destination.	list <destination>\n");

    printf("     List maximum price.    list maxPrice\n");
    printf("      List below price.     list <price>\n");
    printf("    Undo a functionality.   undo\n");
    printf("    Redo a functionality.   redo\n\n");
}

void ui_add(UI* ui, char* inputCommand)
{
    //Delete everything from undo repo
    int position = 0;
    for (int i= 0; i < ui->controller_undo->repository_undo->offers->length; i++)
    {
        controller_delete_undo(ui->controller_undo, &position);
        i--;
    }
    //Add to undo repo the whole repository
    for (int i = 0; i < ui->controller->repo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller->repo->offers, i);
        controller_add_undo(ui->controller_undo, offer);
    }

    char* parameter[5];
    //parameter will be an array where we will have the input command split with delimiter

    Offer* offer;
    for (int i = 0; i < 5; i++)
    {
        parameter[i] = malloc(sizeof(char) * 50);
    }

    char* buffer;
    int i = 0;

    buffer = strtok (inputCommand, ",");
    while (buffer) {
        parameter[i] = buffer;
        buffer = strtok (NULL, ",");
        while (buffer && *buffer == '\040')
            buffer++;
        i++;
    }

    int offer_id = atoi(parameter[0]);
    char *offer_type = parameter[1];
    char *offer_destination = parameter[2];
    int offer_price = atoi(parameter[3]);
    offer = create_offer(offer_id, offer_type, offer_destination, offer_price);

    if (!offer_with_a_given_id_exists(ui->controller->repo, offer))
    {
        controller_add(ui->controller, offer);
        //Delete everything from redo repository
        int position_redo = 0;
        for (i = 0; i < ui->controller_redo->repository_redo->offers->length; i++)
        {
            controller_delete_redo(ui->controller_redo, &position_redo);
            i--;
        }
        printf("The offer was successfully added!\n");
    }
    else
    {
        printf("This offer already exists!\n");
    }
}

void ui_list(UI* ui, char* inputCommand)
{
    //const int MAX_LENGTH= 5;
    char* parameter[5];
    //parameter will be an array where we will have the input command split with delimiter
    int max = INT_MIN;

    for (int i = 0; i < 5; i++)
    {
        parameter[i] = malloc(sizeof(char) * 50);
    }

    char delimiter[] = " ";
    char *split_commands = strtok(inputCommand, delimiter);

    int i = 0;
    while(split_commands != NULL)
    {
        parameter[i] = split_commands;
        i = i+1;

        split_commands = strtok(NULL, delimiter);
    }

    if (strcmp(parameter[1],"")== 0 ) {
        for (i = 0; i < ui->controller->repo->offers->length; i++)
        {
            Offer* offer = getOffer(ui->controller->repo->offers, i);
            printf("| %12d | %15s | %15s | %10d | \n", get_id(offer), get_type(offer), get_destination(offer), get_price(offer));

        }

    } else if  (strcmp(parameter[1], "maxPrice")==0){
        for (i = 0; i < ui->controller->repo->offers->length; i++)
        {
            Offer* offer = getOffer(ui->controller->repo->offers, i);
            if (get_price(offer) > max) {
                max = get_price(offer);
            }
        }

        for (i = 0; i < ui->controller->repo->offers->length; i++)
        {
            Offer* offer = getOffer(ui->controller->repo->offers, i);
            if (get_price(offer) == max) {
                printf("| %12d | %15s | %15s | %10d | \n", get_id(offer), get_type(offer), get_destination(offer), get_price(offer));
            }
        }
    }

    else {
        for (i = 0; i < ui->controller->repo->offers->length; i++) {
            Offer *offer = getOffer(ui->controller->repo->offers, i);
            if (strcmp(parameter[1], get_destination(offer)) == 0 ) {
                printf("| %12d | %15s | %15s | %10d | \n", get_id(offer), get_type(offer), get_destination(offer),
                       get_price(offer));
            }
            if (atoi(parameter[1]) >= get_price(offer)) {
                printf("| %12d | %15s | %15s | %10d | \n", get_id(offer), get_type(offer), get_destination(offer),
                       get_price(offer));
            }
        }
    }
}

void ui_update(UI* ui, char *inputCommand) {
    //Delete everything from undo repo
    int position_undo = 0;
    for (int i = 0; i < ui->controller_undo->repository_undo->offers->length; i++)
    {
        controller_delete_undo(ui->controller_undo, &position_undo);
        i--;
    }
    //Add to undo repo the whole repository
    for (int i = 0; i < ui->controller->repo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller->repo->offers, i);
        controller_add_undo(ui->controller_undo, offer);
    }

    Offer* new_offer;
    //if ok remain 0, it means that the id is wrong or the offer does not exist

    char* parameter[5];
    //parameter will be an array where we will have the input command split with delimiter

    for (int i = 0; i < 5; i++)
    {
        parameter[i] = malloc(sizeof(char) * 50);
    }

    char* buffer;
    int i = 0;

    buffer = strtok (inputCommand, ",");
    while (buffer) {
        parameter[i] = buffer;
        buffer = strtok (NULL, ",");
        while (buffer && *buffer == '\040')
            buffer++;
        i++;
    }

    int new_offer_id = atoi(parameter[0]);
    char *new_offer_type = parameter[1];
    char *new_offer_destination = parameter[2];
    int new_offer_price = atoi(parameter[3]);
    new_offer = create_offer(new_offer_id, new_offer_type, new_offer_destination, new_offer_price);

    for (i = 0; i < ui->controller->repo->offers->length; i++) {
        Offer *offer = getOffer(ui->controller->repo->offers, i);
        if (get_id(offer) == new_offer_id)
        {
            controller_update(ui->controller, new_offer, &i);
            //Delete everything from redo repository
            int position_redo = 0;
            for (i = 0; i < ui->controller_redo->repository_redo->offers->length; i++)
            {
                controller_delete_redo(ui->controller_redo, &position_redo);
                i--;
            }
        }
    }
}

void ui_delete(UI* ui, char* inputCommand) {
    //Delete everything from undo repo
    int position_undo = 0;
    for (int i = 0; i < ui->controller_undo->repository_undo->offers->length; i++)
    {
        controller_delete_undo(ui->controller_undo, &position_undo);
        i--;
    }
    //Add to undo repo the whole repository
    for (int i = 0; i < ui->controller->repo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller->repo->offers, i);
        controller_add_undo(ui->controller_undo, offer);
    }
    int j = 0;
    int ok = 0;
    //if ok remain 0, it means that the id is wrong or the offer does not exist

    //const int MAX_LENGTH= 5;
    char* parameter[5];
    //parameter will be an array where we will have the input command split with delimiter

    for (int i = 0; i < 5; i++)
    {
        parameter[i] = malloc(sizeof(char) * 50);
    }

    char delimiter[] = " ";
    char *split_commands = strtok(inputCommand, delimiter);

    int i = 0;
    while(split_commands != NULL)
    {
        parameter[i] = split_commands;
        i = i+1;

        split_commands = strtok(NULL, delimiter);
    }

    for (i = 0; i < ui->controller->repo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller->repo->offers, i);

        if (atoi(parameter[1]) == get_id(offer)) {
            printf("%d has been deleted...\n", atoi(parameter[1]));
            controller_delete(ui->controller, &i);
            //Delete everything from redo repository
            int position = 0;
            for (i = 0; i < ui->controller_redo->repository_redo->offers->length; i++)
            {
                controller_delete_redo(ui->controller_redo, &position);
                i--;
            }
            ok = 1;
        }
    }
    if (ok == 0) {
        printf("None has been deleted. Check the ID again.\n");
    }
}

void ui_undo(UI* ui) {
    how_much_undo += 1;
    //Delete everything from redo-repo
    int position_redo = 0;
    for (int i = 0; i < ui->controller_redo->repository_redo->offers->length; i++)
    {
        controller_delete_redo(ui->controller_redo, &position_redo);
        i--;
    }

    //Copy everything from repo to redo-repo
    for (int i = 0; i < ui->controller->repo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller->repo->offers, i);
        controller_add_redo(ui->controller_redo, offer);
    }

    //Delete everything from the actual repository
    int position = 0;
    for (int i = 0; i < ui->controller->repo->offers->length; i++)
    {
        controller_delete(ui->controller, &position);
        i--;
    }

    //Add to the actual repository everything from undo-repository
    for (int i = 0; i < ui->controller_undo->repository_undo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller_undo->repository_undo->offers, i);
        controller_add(ui->controller, offer);
    }

    //Delete last element from undo-repository
    int last_element_position = ui->controller_undo->repository_undo->offers->length;
    controller_delete_undo(ui->controller_undo, &last_element_position);

    ui->controller_undo->repository_undo->offers->length--;
}

void ui_redo(UI* ui) {
    //Delete everything from the actual repository
    int position = 0;
    for (int i = 0; i < ui->controller->repo->offers->length; i++)
    {
        controller_delete(ui->controller, &position);
        i--;
    }

    //Copy from redo-repository to actual repository
    int parsing_redo_repository = 0;
    parsing_redo_repository = ui->controller_redo->repository_redo->offers->length;
    int i = 0;
    while (i < parsing_redo_repository)
    {
        Offer* offer = getOffer(ui->controller_redo->repository_redo->offers, i);
        controller_add(ui->controller, offer);
        i++;
    }

    //Copy from redo-repository to undo-repository
    for (i = 0; i < ui->controller_redo->repository_redo->offers->length; i++)
    {
        Offer* offer = getOffer(ui->controller_redo->repository_redo->offers, i);
        controller_add_undo(ui->controller_undo, offer);
    }

    how_much_undo -= 1;
}


