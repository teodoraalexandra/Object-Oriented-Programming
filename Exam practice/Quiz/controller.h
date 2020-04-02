//
// Created by Teodora Dan on 2019-06-12.
//

#ifndef QUIZ2_CONTROLLER_H
#define QUIZ2_CONTROLLER_H


#pragma once
#include "question.h"
#include "repository.h"
#include <vector>
#include <observer.h>

class controller : public Observable
{
private:
    std::vector<question> questions;

public:
    controller() {
        repository repo;
        questions = repo.readFromFile();
    }
    void addQuestion(question q);
    std::vector<question> getQuestions();
    std::vector<question> getQuestionsByIdAscending();
    std::vector<question> getQuestionsByScoreDescending();
    ~controller();
};


#endif //QUIZ2_CONTROLLER_H
