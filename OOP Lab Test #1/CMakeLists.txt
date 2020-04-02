cmake_minimum_required(VERSION 3.13)
project(model1)

set(CMAKE_CXX_STANDARD 14)

add_executable(model1 main.cpp Player.cpp Player.h DynamicVector.cpp DynamicVector.h Controller.cpp Controller.h Repository.cpp Repository.h)