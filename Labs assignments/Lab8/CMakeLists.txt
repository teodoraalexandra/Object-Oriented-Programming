cmake_minimum_required(VERSION 3.13)
project(Lab8_9)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab8_9 main.cpp Basket.cpp Basket.h Coat.cpp Coat.h Controller.cpp Controller.h Repository.cpp Repository.h Mode_interface.cpp Mode_interface.h Test.cpp Test.h)
add_compile_options(-ftest-coverage -fprofile-arcs)

add_link_options(-fprofile-arcs)

