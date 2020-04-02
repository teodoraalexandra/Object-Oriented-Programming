//
// Created by Teodora Dan on 2019-04-08.
//

#include "Controller.h"

Controller::Controller(Repository<DynamicVector> &repo): repository{repo} {}

void Controller::add(const std::string name, const std::string nationality, const std::string team, int goals) {
    //we create the player and add it to the repository
    Player element {name, nationality, team, goals};
    this->repository.add(element);
}

int Controller::size() {
    return this->repository.size();
}

Controller::~Controller() {}