#include "repository.h"

repository::repository()
{
}

std::vector<idea> repository::readFromFile() {
    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/ideas.txt");
    if (!input_file) {
        std::cerr << "Error in opening file." << std::endl;
    }

    idea idea;
    while (input_file >> idea.description >> idea.status >> idea.creator >> idea.act) {
        ideas.push_back(idea);
    }
    return ideas;
}
