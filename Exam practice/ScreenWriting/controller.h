#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <vector>
#include "repository.h"
#include "idea.h"
#include "observer.h"

class controller : public observable
{
private:
    std::vector<idea> ideas;
public:
    controller() {
        repository repo;
        ideas = repo.readFromFile();
    }

    void addIdea(idea i);
    std::vector<idea> getIdeas();
    ~controller();
};

#endif // CONTROLLER_H
