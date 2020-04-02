//
// Created by Teodora Dan on 2019-05-06.
//

#ifndef TEST_MEDICALANALYSIS_H
#define TEST_MEDICALANALYSIS_H

#endif //TEST_MEDICALANALYSIS_H

#pragma once
#include <iostream>

class MedicalAnalysis {
protected:
    std::string date;
public:
    MedicalAnalysis(const std::string& date);
    ~MedicalAnalysis();
    virtual bool isResultOk();
    virtual void toString();
};