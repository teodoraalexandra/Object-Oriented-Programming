#ifndef EQUATION_H
#define EQUATION_H
#include <iostream>
#include <sstream>
#include <string>

class equation
{
public:
    std::string first;
    std::string second;
    std::string third;
public:
    equation(): first(""), second(""), third("") {}
    equation(std::string _first, std::string _second, std::string _third) : first(_first), second(_second), third(_third) {}
    std::string getFirst() const {return this->first;}
    std::string getSecond() const {return this->second;}
    std::string getThird() const {return this->third;}

    std::string toString();
};

#endif // EQUATION_H
