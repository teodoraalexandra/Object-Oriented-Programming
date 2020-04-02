#ifndef IDEA_H
#define IDEA_H

#include <iostream>
#include <sstream>
#include <string>

class idea
{
public:
    std::string description;
    std::string status;
    std::string creator;
    std::string act;
public:
    idea(): description(""), status(""), creator(""), act("") {}
    idea(std::string _description, std::string _status, std::string _creator, std::string _act) : description(_description), status(_status), creator(_creator), act(_act) {}
    std::string getDescription() const {return this->description;}
    std::string getStatus() const {return this->status;}
    std::string getCreator() const {return this->creator;}
    std::string getAct() const {return this->act;}

    std::string toString();
};

#endif // IDEA_H
