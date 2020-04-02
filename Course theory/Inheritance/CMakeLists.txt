cmake_minimum_required(VERSION 3.13)
project(Inheritance)

set(CMAKE_CXX_STANDARD 14)

add_executable(Inheritance main.cpp Animal.cpp Animal.h Penguin.cpp Penguin.h Dog.cpp Dog.h)