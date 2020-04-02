//
// Created by Teodora Dan on 2019-05-06.
//

#ifndef TEST_BMI_H
#define TEST_BMI_H

#endif //TEST_BMI_H

#pragma once
#include <iostream>
#include "MedicalAnalysis.h"

class BMI : public MedicalAnalysis {
private:
  double value;
public:
    BMI(const std::string& date, double value);
    bool isResultOk() override;
    void toString() override;
};