#include "Repository.h"
#include <fstream>
#include <string>
#include <sstream>

Repository::Repository(std::vector<Coat> _coats, const std::string & filename):
        coats {_coats}, fileName{filename}
{
    this->loadFromFile();
}

Repository::~Repository()
{
}

void Repository::loadFromFile()
{
    std::ifstream f{ this->fileName };
    if (!f.is_open())
        return;

    Coat g;
    while (f >> g)
    {
        this->coats.push_back(g);
    }
}

//void Repository::loadFromFile()
//{
   // std::ifstream f{ this->fileName };
    //if (!f.is_open())
    //    return;

    //std::string name, size, price, photo;
    //while (f >> name)
    //{
     //   Coat c{ name, size, price, photo };
     //   this->coats.push_back(c);
    //}
//}

void Repository::addCoat(const Coat &g)
{
    this->coats.push_back(g);
}

void Repository::updateCoat(int index, const Coat & g)
{
    if (index < 0 || index >= this->coats.size())
        return;

    this->coats.erase(this->coats.begin() + index);
    this->coats.insert(this->coats.begin() + index, g);

    this->saveToFile();
}

void Repository::saveToFile()
{
    std::ofstream f{this->fileName};
    if (!f.is_open())
        return;

    for (auto g : this->coats)
        f << g.toString();
}
