#include "repo.h"
#include <exception>

repo::repo()
{
}

std::vector<vegetable> repo::readFromFile() {
    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/vegetables.txt");
    if (!input_file) {
        std::cerr << "Error in opening the file" << std::endl;
    }

    vegetable vegetable;
    while (input_file >> vegetable.family >> vegetable.name >> vegetable.part) {
         vegetables.push_back(vegetable);
    }
    return vegetables;
}
