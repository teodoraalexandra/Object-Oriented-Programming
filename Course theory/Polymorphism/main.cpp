#include <iostream>
#include "Mammal.h"
#include "Animal.h"
#include <fstream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class MyException : public std::exception
{
private:
    std::string message;

public:
    MyException(const std::string& s) : message{ s } {}

    const char* what() const throw() override {
        return this->message.c_str();
    }
};

int main() {
    Mammal * horse = new Horse {"Mircea", 100};
    Animal * animal1 = new Animal {"Mamifere"};

    animal1->add(horse);

    Animal * animal2 = new Animal {"Pasari"};
    animal2->add(horse);
    animal2->add(animal1);

    animal2->breath();

    std::fstream in ("/Users/teodoradan/CLionProjects/polymorphism/fisier.txt", std::ios::in | std::ios::out);
    in << "Ana are mere.";
    in << "\n";
    in << "Maria are pere.";
    in.close();

    std::ifstream infile("/Users/teodoradan/CLionProjects/polymorphism/fisier.txt");
    if (!infile) {
        std::cerr << "Could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(infile, line)) {  // Read file line by line.
        std::string field;
        std::vector<std::string> separated_fields;
        std::istringstream iss_line(line);
        while (std::getline(iss_line, field, ' ')) { // Split line on the ':' character
            separated_fields.push_back(field);    // Vector containing each field, i.e. name, address...
        }
        // Do something with the results
        std::cout << separated_fields[0]; // ID
        std::cout << separated_fields[1]; // Names
        std::cout << separated_fields[2]; // Number
    }

    try {
        if (2 == 3) {
            std::cout << "No";
        } else {
            throw MyException {"I'm throwing an exception.\n"};
        }
    } catch (std::exception &e) {
        std::cout << e.what();
    }
    return 0;
}