cmake_minimum_required(VERSION 3.13)
project(quiz2)

set(CMAKE_CXX_STANDARD 14)

add_executable(quiz2 main.cpp controller.cpp controller.h repository.cpp repository.h question.cpp question.h participant.cpp participant.h presentergui.cpp presentergui.h participantgui.cpp participantgui.h observer.h)