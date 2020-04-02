//
// Created by Teodora Dan on 2019-04-27.
//

#include "Coat.h"

Coat::Coat(const std::string& coat_name, const std::string& coat_size, int coat_price, const std::string& coat_photo):
        name(coat_name), size(coat_size), price(coat_price), photo(coat_photo)
{
}

/*Coat::Coat(): name(""), size(""), price(), photo("")
{
}*/

Coat::~Coat()
{
}
