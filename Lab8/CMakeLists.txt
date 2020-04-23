cmake_minimum_required(VERSION 3.15)
project(Lab8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra --coverage")

add_executable(Lab8 main.cpp Domain.cpp Domain.h Repository.cpp Repository.h Service.cpp Service.h UI.cpp UI.h Tests.cpp Tests.h FileRepository.cpp FileRepository.h)
