#ifndef PARTICIPANT_H
#define PARTICIPANT_H

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
    std::string getName() { return this-> name; }
    int getScore() { return this->score; }

    std::string toString();
};

#endif // PARTICIPANT_H
