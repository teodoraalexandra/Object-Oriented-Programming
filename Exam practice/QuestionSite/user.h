#ifndef USER_H
#define USER_H

#include <iostream>

class user
{
public:
    std::string name;
public:
    user() : name("") {}
    user(std::string _name) : name { _name } {}
};

#endif // USER_H
