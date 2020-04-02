#include "repository.h"

repository::repository()
{
}

std::vector<question> repository::readFromFile() {
    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/questions.txt");
    if (!input_file) {
        std::cerr << "Error in opening file";
    }

    question question;
    while ( input_file >> question.id >> question.text >> question.answer >> question.score ) {
        this->questions.push_back(question);
    }
    return questions;
}

