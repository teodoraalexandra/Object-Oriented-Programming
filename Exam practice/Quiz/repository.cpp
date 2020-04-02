//
// Created by Teodora Dan on 2019-06-12.
//

#include "repository.h"

repository::repository()
{
}

std::vector<question> repository::readFromFile() {
    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/questions.txt");
    if (!input_file) {
        std::cerr << "Error in opening the file" << std::endl;
    }

    question question;
    while (input_file >> question.id >> question.text >> question.answer >> question.score) {
        questions.push_back(question);
    }
    return questions
}
