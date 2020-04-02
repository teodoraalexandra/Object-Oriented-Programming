#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <iostream>

class question
{
public:
    int id;
    std::string text;
    std::string answer;
    int score;
public:
    question(): id(), text(""), answer(""), score() {}
    question(int _id, std::string _text, std::string _answer, int _score) : id {_id}, text{_text}, answer{_answer}, score{_score} {}
    int getId() const {return this->id;}
    std::string getText() const  {return this->text;}
    std::string getAnswer() const {return this->answer;}
    int getScore() const {return this->score;}

    std::string toString();
    std::string withoutAnswer();
};

#endif // QUESTION_H
