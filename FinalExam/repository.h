#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "question.h"
#include <iostream>
#include <vector>
#include <fstream>

class repository
{
public:
    std::vector<question> questions;
public:
    repository();
    std::vector<question> readFromFile();
};

#endif // REPOSITORY_H
