#include "controller.h"

controller::~controller()
{
}

void controller::addQuestion(question q) {
    this->questions.push_back(q);
    this->notify();
}

std::vector<question> controller::getQuestions() {
    return this->questions;
}
