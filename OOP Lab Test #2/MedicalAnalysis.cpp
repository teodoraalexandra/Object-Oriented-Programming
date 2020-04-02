//
// Created by Teodora Dan on 2019-05-06.
//

#include "MedicalAnalysis.h"

MedicalAnalysis::MedicalAnalysis (const std::string &date) : date {date}
{
}

MedicalAnalysis::~MedicalAnalysis() {}


void MedicalAnalysis::toString()
{
    std::cout << "Medical analysis: " << this->date << std::endl;
}

bool MedicalAnalysis::isResultOk()
{
    return true;
}