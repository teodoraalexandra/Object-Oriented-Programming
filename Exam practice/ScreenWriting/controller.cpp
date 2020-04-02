#include "controller.h"

void controller::addIdea(idea i) {
    this->ideas.push_back(i);
    this->notify();
}

controller::~controller()
{
}

std::vector<idea> controller::getIdeas() {
    return this->ideas;
}
