//
// Created by Teodora Dan on 2019-04-11.
//

#ifndef LAB8_COAT_H
#define LAB8_COAT_H

#endif //LAB8_COAT_H

#include <string>
#include <iostream>

#pragma once

class Coat
{
private:
    std::string name;
    std::string size;
    int price;
    std::string photo;
public:
    Coat(const std::string& coat_name, const std::string& coat_size, int coat_price, const std::string& coat_photo);
    Coat();
    ~Coat();
    std::string getName() {return this->name;};
    std::string getSize() {return this->size;};
    int getPrice() {return this->price;};
    std::string getPhoto() {return this->photo;};
};