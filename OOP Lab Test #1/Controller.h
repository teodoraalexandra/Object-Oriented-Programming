//
// Created by Teodora Dan on 2019-04-08.
//

#ifndef MODEL1_CONTROLLER_H
#define MODEL1_CONTROLLER_H

#endif //MODEL1_CONTROLLER_H

#pragma once

#include "Repository.h"

class Controller{
private:
    Repository<DynamicVector>& repository;
public:
    Controller(Repository<DynamicVector>& repository);
    void add(const std::string name, const std::string nationality, const std::string team, int goals);
    int size();
    ~Controller();
};