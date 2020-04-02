//
// Created by Teodora Dan on 2019-04-11.
//

#include "Controller.h"



Controller::Controller(Repository & otherRepo): repository{otherRepo}
{
}


void Controller::add(const std::string & name, const std::string & size, int price, const std::string & photo)
{
    Coat coat{ name, size, price, photo };
    this->repository.add(coat);
}

void Controller::update(const std::string & name, const std::string & size, int price, const std::string & photo, int position)
{
    Coat coat{ name, size, price, photo };
    this->repository.update(coat, position);
}

void Controller::remove(int position) {
    this->repository.remove(position);
}

Coat Controller::getCoat(int position) {
    return this->repository.getCoat(position);
}

int Controller::size()
{
    return this->repository.size();
}

Controller::~Controller()
{
}
