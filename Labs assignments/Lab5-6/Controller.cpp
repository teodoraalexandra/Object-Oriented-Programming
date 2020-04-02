//
// Created by Teodora Dan on 2019-03-23.
//

#include "Controller.h"


Controller::Controller(Repository<DynamicVector>& otherRepository): repository{otherRepository}
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

int Controller::size()
{
    return this->repository.size();
}

Coat Controller::getCoat(int position) {
    return this->repository.getCoat(position);
}

Controller::~Controller()
{
}
