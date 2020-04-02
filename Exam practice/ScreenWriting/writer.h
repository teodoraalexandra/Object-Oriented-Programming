#ifndef WRITER_H
#define WRITER_H

#include <iostream>
#include <sstream>
#include <string>

class writer
{
public:
    std::string name;
    std::string expertise;
public:
    writer();
    std::string getName() const {return this->name;}
    std::string getExpertise() const {return this->expertise;}

    std::string toString();
};

#endif // WRITER_H
