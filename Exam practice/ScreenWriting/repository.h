#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <idea.h>
#include <fstream>
#include <iostream>

class repository
{
private:
    std::vector<idea> ideas;

public:
    repository();
    std::vector<idea> readFromFile();
};

#endif // REPOSITORY_H
