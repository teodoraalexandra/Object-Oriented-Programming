cmake_minimum_required(VERSION 3.13)
project(Shapes)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shapes main.cpp Shape.cpp Shape.h Drawing.cpp Drawing.h)