#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include <fstream>
#include <question.h>

class repository
{
private:
    std::vector<question> questions;
public:
    repository();
    std::vector<question> readFromFile();
};

#endif // REPOSITORY_H
