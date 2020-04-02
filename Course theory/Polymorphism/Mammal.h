//
// Created by Teodora Dan on 2019-05-05.
//

#include <string>

#ifndef POLYMORPHISM_MAMMAL_H
#define POLYMORPHISM_MAMMAL_H

#endif //POLYMORPHISM_MAMMAL_H

#pragma once

class Mammal {
protected:
    std:: string name;
public:
    Mammal(const std::string& name);
    virtual ~Mammal();

    virtual void breath() = 0;
};

class Horse : public Mammal {
private:
    int id_horse;
public:
    Horse(const std::string& name, int id_horse);
    void breath() override;
};