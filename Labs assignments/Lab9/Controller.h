//
// Created by Teodora Dan on 2019-04-23.
//

#ifndef LAB9_CONTROLLER_H
#define LAB9_CONTROLLER_H

#endif //LAB9_CONTROLLER_H

#pragma once

#include "Repository.h"

class Controller
{
private:
    Repository & repository;

public:
    Controller(Repository & repo);
    std::vector<Coat> myVectors;
    void add(const std::string& name, const std::string& size, int price, const std::string& photo);
    void update(const std::string& name, const std::string& size, int price, const std::string& photo, int position);
    void remove(int position);
    Coat getCoat(int position);
    int size();
    ~Controller();
};