#ifndef REPO_H
#define REPO_H
#include <vector>
#include "vegetable.h"
#include <fstream>

class repo
{
private:
    std::vector<vegetable> vegetables;

public:
    repo();
    std::vector<vegetable> readFromFile();
};

#endif // REPO_H
