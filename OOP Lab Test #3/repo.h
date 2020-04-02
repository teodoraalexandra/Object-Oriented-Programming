#ifndef REPO_H
#define REPO_H
#include <vector>
#include <equation.h>
#include <fstream>

class repo
{
private:
    std::vector<equation> equations;

public:
    repo();
    std::vector<equation> readFromFile();
};

#endif // REPO_H
