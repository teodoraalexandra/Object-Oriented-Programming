#include "repo.h"

repo::repo()
{
}

std::vector<equation> repo::readFromFile() {
    std::ifstream input_file;
    input_file.open("/Users/teodoradan/Desktop/equations.txt");
    if (!input_file) {
        std::cerr << "Error" << std::endl;
    }

    equation e;
    while (input_file >> e.first >> e.second >> e.third) {
        equations.push_back(e);
    }
    return equations;
}
