#ifndef BASKET_H
#define BASKET_H

#pragma once
#include <string>
#include <vector>
#include "Coat.h"

class Basket
{
private:
    std::vector<Coat> coats;

public:
    Basket(std::vector<Coat> coats);
    ~Basket();
    std::vector<Coat> getCoats() const { return this->coats; }

    int getSize() const { return this->coats.size(); }

    void addCoat(const Coat& g);
    void updateCoat(int index, const Coat& g);
};


#endif // BASKET_H

