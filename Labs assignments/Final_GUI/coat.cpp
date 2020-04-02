#include "Coat.h"
#include <sstream>

std::string Coat::toString()
{
    std::stringstream string_coat;
    string_coat << this->name << " | " << this->size << " | " << this->price << " | " << this->photo<<std::endl;
    return std::string(string_coat.str());
}


std::vector<std::string> Coat::tokenize(std::string str, char delimiter)
{
    std::vector <std::string> result;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

std::istream& operator>>(std::istream& is, Coat& g)
{
    std::string line;
    getline(is, line);

    std::vector<std::string> tokens = g.tokenize(line, '|');
    if (tokens.size() != 4)
        return is;
    g.name = tokens[0];
    g.size = tokens[1];
    g.price = tokens[2];
    g.photo = tokens[3];

    return is;
}
