cmake_minimum_required(VERSION 3.16)
project(test)

set(CMAKE_CXX_STANDARD 17)

add_executable(test main.cpp Repository.cpp Repository.h UI.cpp UI.h Domain.cpp Domain.h)