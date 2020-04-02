//
// Created by Teodora Dan on 2019-06-12.
//

#ifndef QUIZ2_REPOSITORY_H
#define QUIZ2_REPOSITORY_H


#include <vector>
#include <fstream>
#include "question.h"

class repository
{
private:
    std::vector<question> questions;

public:
    repository();
    std::vector<question> readFromFile();
};


#endif //QUIZ2_REPOSITORY_H
