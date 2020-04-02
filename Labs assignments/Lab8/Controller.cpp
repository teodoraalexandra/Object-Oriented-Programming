//
// Created by Teodora Dan on 2019-04-27.
//

#include "Controller.h"
#include <vector>


Controller::Controller(Repository & otherRepo): repository(otherRepo)
{
}

std::vector<Coat> Controller::search() const {
    std::vector<Coat> vector_of_coats;
    for (int i =  0; i < this->repository.size(); i++) {
        vector_of_coats.push_back(this->repository.getCoat(i));
    }
    return vector_of_coats;
}

void Controller::add(const std::string & name, const std::string & size, int price, const std::string & photo)
{
    Coat coat( name, size, price, photo );
    this->repository.add(coat);
}

void Controller::update(const std::string & name, const std::string & size, int price, const std::string & photo, int position)
{
    Coat coat( name, size, price, photo );
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