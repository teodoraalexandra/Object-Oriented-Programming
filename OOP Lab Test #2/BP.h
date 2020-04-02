//
// Created by Teodora Dan on 2019-05-06.
//

#ifndef TEST_BP_H
#define TEST_BP_H

#endif //TEST_BP_H

#pragma once
#include <iostream>
#include "MedicalAnalysis.h"

class BP : public MedicalAnalysis {
private:
    int systoicValue;
    int diastolicValue;
public:
    BP(const std::string& date, int systoicValue, int diastolicValue);
    bool isResultOk() override;
    void toString() override;
};