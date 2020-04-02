//
// Created by Teodora Dan on 2019-05-06.
//

#ifndef TEST_PERSON_H
#define TEST_PERSON_H

#endif //TEST_PERSON_H

#pragma once
#include <iostream>
#include "MedicalAnalysis.h"
#include <vector>

class Person : public MedicalAnalysis{
private:
    std::string name;
    std::vector<MedicalAnalysis*> analize;
public:
    Person(const std::string &name);
    ~Person();
    void add (MedicalAnalysis * analize);
    void getAll();
    void getByMonth();
    bool isHealthy(int month);
    void getNewer(std::string date);
    void writeToFile(std::string filename, std::string date);
    int size();
};