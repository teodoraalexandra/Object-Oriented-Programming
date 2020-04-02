//
// Created by Teodora Dan on 2019-05-06.
//
#include "Person.h"

Person::Person(const std::string &name) : MedicalAnalysis {name}
{
}

Person::~Person()
{
}

void Person::add(MedicalAnalysis* analize)
{
    this->analize.push_back(analize);
}

int Person::size() {
    return this->analize.size();
}

void Person::getAll() {
}

