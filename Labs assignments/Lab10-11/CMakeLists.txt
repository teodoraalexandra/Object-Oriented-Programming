cmake_minimum_required(VERSION 3.13)
project(Lab10_11)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab10_11 main.cpp Basket.cpp Basket.h Coat.cpp Coat.h Controller.cpp Controller.h Repository.cpp Mode_interface.cpp Mode_interface.h Repository.h)
target_link_libraries(Lab10_11 Qt5::Widgets Qt5::Sql)