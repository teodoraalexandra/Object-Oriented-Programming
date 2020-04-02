//
// Created by Teodora Dan on 2019-05-06.
//

#include "BP.h"
#include <iostream>
BP::BP(const std::string &date, int systoicValue, int diastolicValue) : MedicalAnalysis {date} , systoicValue{systoicValue}, diastolicValue{diastolicValue}
{}

void BP::toString() {
    std::cout << "BP: " << this->date << " " << this->systoicValue << " " << this->diastolicValue << "\n";
}

bool BP::isResultOk() {
    return true;
}