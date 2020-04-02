cmake_minimum_required(VERSION 3.13)
project(Lab9)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-ftest-coverage -fprofile-arcs)

add_link_options(-fprofile-arcs)

add_executable(Lab9 main.cpp Basket.cpp Basket.h Coat.cpp Coat.h Controller.cpp Controller.h Repository.cpp Repository.h Test.cpp Test.h)