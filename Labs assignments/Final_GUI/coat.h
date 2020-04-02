#ifndef COAT_H
#define COAT_H

#pragma once
#include <string.h>
#include <QString>
#include <vector>

class Coat
{
public:
    std::string name;
    std::string size;
    std::string price;
    std::string photo;

    Coat(): name(""), size(""), price(""), photo("") {}
    Coat(std::string _name, std::string _size, std::string _price, std::string _photo) : name(_name), size(_size), price(_price), photo(_photo) {}
    std::string getName() const { return this->name; }
    std::string getSize() const { return this->size; }
    std::string getPrice() const { return this->price; }
    std::string getPhoto() const { return this->photo; }

    void setName(const std::string& val) { this->name = val; }
    void setSize(const std::string& val) { this->size = val; }
    void setPrice(const std::string& val) { this->price = val; }
    void setPhoto(const std::string& val) { this->photo = val; }

    std::string toString();
private:
    std::vector<std::string> tokenize(std::string str, char delimiter);

    friend std::istream & operator>>(std::istream& is, Coat& c);
};

#endif // COAT_H

