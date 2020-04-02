cmake_minimum_required(VERSION 3.13)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp Person.cpp Person.h MedicalAnalysis.cpp MedicalAnalysis.h BMI.cpp BMI.h BP.cpp BP.h)