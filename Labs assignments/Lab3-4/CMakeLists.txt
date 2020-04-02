cmake_minimum_required(VERSION 3.13)
project(Lab3 C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab3 main.c controller.c controller.h DynamicArray.c DynamicArray.h domain.c domain.h repo.c repo.h ui.c ui.h repo_undo.c repo_undo.h controller_undo.c controller_undo.h controller_redo.c controller_redo.h repo_redo.c repo_redo.h)