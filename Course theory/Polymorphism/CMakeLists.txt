cmake_minimum_required(VERSION 3.13)
project(polymorphism)

set(CMAKE_CXX_STANDARD 14)

add_executable(polymorphism main.cpp Animal.cpp Animal.h Mammal.cpp Mammal.h)