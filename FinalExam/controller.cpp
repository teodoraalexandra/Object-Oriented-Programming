#include "controller.h"

struct sortScore
{
    inline bool operator() (const question& q1, const question& q2)
    {
        return (q1.getScore() > q2.getScore());
    }
};

struct sortId
{
    inline bool operator() (const question& q1, const question& q2)
    {
        return (q1.getId() < q2.getId());
    }
};

std::vector<question> controller::getQuestions() {
    return this->questions;
}

std::vector<question> controller::getQuestionSortId() {
    std::sort(questions.begin(), questions.end(), sortId());
    return this->questions;
}

std::vector<question> controller::getQuestionDescendingScore() {
    std::sort(questions.begin(), questions.end(), sortScore());
    return this->questions;
}

void controller::addQuestion(question q) {
    this->questions.push_back(q);
    this->notify();
}

