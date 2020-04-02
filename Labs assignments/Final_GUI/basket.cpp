#include "Basket.h"
#include <fstream>

Basket::Basket(std::vector<Coat> _coats):
        coats {_coats}
{
}

Basket::~Basket()
{
}

void Basket::addCoat(const Coat &g)
{
    this->coats.push_back(g);
}

void Basket::updateCoat(int index, const Coat & g)
{
    if (index < 0 || index >= this->coats.size())
        return;

    this->coats.erase(this->coats.begin() + index);
    this->coats.insert(this->coats.begin() + index, g);
}
