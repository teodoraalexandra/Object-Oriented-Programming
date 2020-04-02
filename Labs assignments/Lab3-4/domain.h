//
// Created by Teodora Dan on 2019-03-10.
//

#ifndef LAB3_DOMAIN_H
#define LAB3_DOMAIN_H

#endif //LAB3_DOMAIN_H

#ifndef domain_h
#define domain_h
#include <stdlib.h>


typedef struct {
    int id;
    char* type;
    char* destination;
    int price;
}Offer;

Offer *create_offer(int id, char* type, char* destination, int price);
void destroy_offer(Offer* offer);
int get_id(Offer* offer);
char* get_type(Offer* offer);
char* get_destination(Offer* offer);
int get_price(Offer* offer);
void set_id(Offer* offer, int newId);
void set_type(Offer* offer, char* newType);
void set_destination(Offer* offer, char* newDestination);
void set_price(Offer* offer, int newPrice);


#endif // domain_h
