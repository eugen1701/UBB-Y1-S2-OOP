cmake_minimum_required(VERSION 3.16)
project(test_model)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_model main.cpp Aircraft.cpp Aircraft.h Repository.cpp Repository.h UI.cpp UI.h)