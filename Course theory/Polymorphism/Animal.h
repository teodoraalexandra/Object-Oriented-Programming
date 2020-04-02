//
// Created by Teodora Dan on 2019-05-05.
//

#ifndef POLYMORPHISM_ANIMAL_H
#define POLYMORPHISM_ANIMAL_H

#endif //POLYMORPHISM_ANIMAL_H

#include "Mammal.h"
#include <vector>

class Animal : public Mammal
        {
private:
    std::vector<Mammal*> mammals;
public:
            Animal(const std::string& name);
            ~Animal();

            void breath() override;
            void add(Mammal* mammal);
};