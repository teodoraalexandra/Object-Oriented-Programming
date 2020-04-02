cmake_minimum_required(VERSION 3.13)
project(Lab8)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

add_executable(Lab8 main.cpp Basket.cpp Basket.h Coat.cpp Coat.h Repository.cpp Repository.h Controller.cpp Controller.h Test.cpp Test.h)