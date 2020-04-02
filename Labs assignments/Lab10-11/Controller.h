//
// Created by Teodora Dan on 2019-05-13.
//

#ifndef LAB10_11_CONTROLLER_H
#define LAB10_11_CONTROLLER_H

#endif //LAB10_11_CONTROLLER_H

#pragma once

#include "Repository.h"
#include <vector>

class Controller
{
private:
    Repository & repository;

public:
    Controller(Repository & repo);
    void add(const std::string& name, const std::string& size, int price, const std::string& photo);
    void update(const std::string& name, const std::string& size, int price, const std::string& photo, int position);
    void remove(int position);
    Coat getCoat(int position);
    std::vector<Coat> search() const;
    int size();
    ~Controller();
};