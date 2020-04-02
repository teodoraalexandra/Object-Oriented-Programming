//
// Created by Teodora Dan on 2019-05-06.
//

#include "BMI.h"
#include <iostream>
BMI::BMI(const std::string &date, double value) : MedicalAnalysis {date} , value {value}
{}

void BMI::toString() {
    std::cout << "BMI: " << this->date << " " << this->value << "\n";
}

bool BMI::isResultOk() {
    return true;
}