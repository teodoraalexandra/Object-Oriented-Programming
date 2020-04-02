#ifndef VEGETABLE_H
#define VEGETABLE_H
#include <iostream>
#include <string>
#include <sstream>

class vegetable
{
public:
    std::string family;
    std::string name;
    std::string part;
public:
    vegetable();
    std::string getFamily() const {return this->family;}
    std::string getName() const {return this->name;}
    std::string getPart() const {return this->part;}

    std::string toString();
};

#endif // VEGETABLE_H
