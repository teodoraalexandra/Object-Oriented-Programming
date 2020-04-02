#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "repository.h"
#include "observer.h"
#include "question.h"
#include <vector>
#include <algorithm>
#include <iostream>

class controller : public observable
{
public:
    std::vector<question> questions;
public:
    controller() {
        repository repo;
        questions = repo.readFromFile();
    }
    void addQuestion(question q);
    std::vector<question> getQuestions();
    std::vector<question> getQuestionSortId();
    std::vector<question> getQuestionDescendingScore();
    ~controller() {}
};

#endif // CONTROLLER_H
