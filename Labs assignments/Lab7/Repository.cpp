//
// Created by Teodora Dan on 2019-04-11.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Repository.h"
#include "Basket.h"
using namespace std;

Repository::Repository()
{
}

void Repository::add(const Coat& element)
{
    myVector.push_back(element);
}

void Repository::remove(int position)
{
    this->myVector.erase(myVector.begin() + position);
}

void Repository::update(const Coat& element, int position)
{
    myVector[position] = element;
}

int Repository::size()
{
    return myVector.size();
}

Coat Repository::getCoat(int position) {
    return myVector.at(position);
}

Repository::~Repository()
{
}


