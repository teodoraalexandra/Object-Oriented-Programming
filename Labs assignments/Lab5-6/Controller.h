//
// Created by Teodora Dan on 2019-03-23.
//

#ifndef LAB5_CONTROLLER_H
#define LAB5_CONTROLLER_H

#endif //LAB5_CONTROLLER_H
#pragma once

#include "Repository.h"
#include "DynamicVector.h"

class Controller
{
private:
    Repository<DynamicVector>& repository;
public:
    Controller(Repository<DynamicVector>& otherRepository);
    void add(const std::string& name, const std::string& size, int price, const std::string& photo);
    void update(const std::string& name, const std::string& size, int price, const std::string& photo, int position);
    void remove(int position);
    int size();
    Coat getCoat(int position);
    ~Controller();
};
