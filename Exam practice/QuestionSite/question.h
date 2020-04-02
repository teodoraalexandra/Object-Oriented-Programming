#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>

class question
{
public:
    int id;
    std::string text;
    std::string name;

public:
    question() : id(), text(""), name("") {}
    question( int _id, std::string _text, std::string _name) : id { _id }, text { _text }, name { _name } {}
    int getId() {return this->id ;}
    std::string getText() {return this->text;}
    std::string getName() {return this->name;}

    std::string toPrint();
};

#endif // QUESTION_H
