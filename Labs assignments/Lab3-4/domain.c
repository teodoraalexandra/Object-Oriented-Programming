//
// Created by Teodora Dan on 2019-03-10.
//

#include "domain.h"
#include <string.h>

Offer *create_offer(int id, char* type, char* destination, int price)
{
    Offer *new_offer = (Offer*)malloc(sizeof(Offer));

    new_offer->id = id;

    new_offer->type = (char*)malloc(sizeof(char)*(strlen(type) + 1));
    strcpy(new_offer->type, type);

    new_offer->destination = (char*)malloc(sizeof(char)*(strlen(destination) + 1));
    strcpy(new_offer->destination, destination);

    new_offer->price = price;

    return new_offer;
}

void destroy_offer(Offer* offer)
{
    if (offer == NULL)
        return;

    free(offer->destination);
    free(offer->type);

    free(offer);
}

int get_id(Offer* offer)
{
    return offer->id;
}

char* get_type(Offer* offer)
{
    return offer->type;
}

char* get_destination(Offer* offer)
{
    return offer->destination;
}

int get_price(Offer* offer)
{
    return offer->price;
}

void set_id(Offer* offer, int newId)
{
    offer->id = newId;
}

void set_type(Offer* offer, char* newType)
{
    strcpy(offer->type, newType);
}

void set_destination(Offer* offer, char* newDestination)
{
    strcpy(offer->destination, newDestination);
}

void set_price(Offer* offer, int newPrice)
{
    offer->price= newPrice;
}
