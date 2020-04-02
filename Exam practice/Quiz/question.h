//
// Created by Teodora Dan on 2019-06-12.
//

#ifndef QUIZ2_QUESTION_H
#define QUIZ2_QUESTION_H


#include <iostream>
#include <string>
#include <sstream>

class question
{
public:
    int id;
    std::string text;
    std::string answer;
    int score;

public:
    question(): id(), text(""), answer(""), score() {}
    question(int _id, std::string _text, std::string _answer, int _score) : id(_id), text(_text), answer(_answer), score(_score) {}
    int getId() const {return this->id;}
    std::string getText() const {return this->text;}
    std::string getAnswer() const {return this->answer;}
    int getScore() const {return this->score;}

    std::string toString();
    std::string onlyForParticipants();

};

#endif //QUIZ2_QUESTION_H
