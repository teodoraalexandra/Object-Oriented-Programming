//
// Created by Teodora Dan on 2019-06-12.
//

#ifndef QUIZ2_PARTICIPANT_H
#define QUIZ2_PARTICIPANT_H


#include <iostream>
#include <string>
#include <sstream>

class participant
{
public:
    std::string name;
    int score;
public:
    participant();
    std::string getName() const {return this->name;}
    int getScore() const {return this->score;}

    std::string toString();
};


#endif //QUIZ2_PARTICIPANT_H
