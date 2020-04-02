cmake_minimum_required(VERSION 3.13)
project(AbstractClasses)

set(CMAKE_CXX_STANDARD 14)

add_executable(AbstractClasses main.cpp Animal.cpp Animal.h Dog.cpp Dog.h Filter.h Penguin.cpp Penguin.h Zoo.cpp Zoo.h)