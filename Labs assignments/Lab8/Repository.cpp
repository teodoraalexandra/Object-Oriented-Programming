//
// Created by Teodora Dan on 2019-04-27.
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

FakeRepository::FakeRepository()
{
}

void Repository::add(const Coat& coat)
{
    vector_of_coats.push_back(coat);
}

void FakeRepository::add(const Coat &coat)
{
    cout << "Add to fake repository.\n";
}

void Repository::remove(int position)
{
    this->vector_of_coats.erase(vector_of_coats.begin() + position);
}

void FakeRepository::remove(int position)
{
    cout << "Delete from fake repository.\n";
}

void Repository::update(const Coat& coat, int position)
{
    vector_of_coats[position] = coat;
}

void FakeRepository::update(const Coat &coat, int position)
{
    cout << "Update the fake repository.\n";
}

int Repository::size()
{
    return vector_of_coats.size();
}

Coat Repository::getCoat(int position) {
    return vector_of_coats.at(position);
}

Repository::~Repository()
{
}