//
// Created by Teodora Dan on 2019-06-12.
//

#include "controller.h"

struct sortId
{
    inline bool operator() (const question& q1, const question& q2)
    {
        return (q1.getId() < q2.getId());
    }
};

struct sortScore
{
    inline bool operator() (const question& q1, const question& q2)
    {
        return (q1.getScore() > q2.getScore());
    }
};

void controller::addQuestion(question q)
{
    this->questions.push_back(q);

    this->notify();
}

controller::~controller()
{
}

std::vector<question> controller::getQuestions()
{
    return this->questions;
}

std::vector<question> controller::getQuestionsByIdAscending()
{
    sort(questions.begin(), questions.end(), sortId());
    return this->questions;
}

std::vector<question> controller::getQuestionsByScoreDescending()
{
    sort(questions.begin(), questions.end(), sortScore());
    return this->questions;
}
