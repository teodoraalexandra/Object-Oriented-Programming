#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "observer.h"
#include "question.h"
#include "repository.h"

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
    ~controller();
};

#endif // CONTROLLER_H
