#ifndef REPOSITORY_H
#define REPOSITORY_H

#pragma once
#include <string>
#include <vector>
#include "Coat.h"

class Repository
{
private:
    std::vector<Coat> coats;
    std::string fileName;

public:
    Repository(std::vector<Coat> coats, const std::string& filename);
    Repository() {}
    ~Repository();
    std::vector<Coat> getCoats() const { return this->coats; }

    int getSize() const { return this->coats.size(); }

    void addCoat(const Coat& g);
    void updateCoat(int index, const Coat& g);

private:
    void loadFromFile();
    void saveToFile();
};

#endif // REPOSITORY_H



