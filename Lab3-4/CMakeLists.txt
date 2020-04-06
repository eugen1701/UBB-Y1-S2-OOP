cmake_minimum_required(VERSION 3.15)
project(Lab3_4 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra --coverage")

add_executable(Lab3_4 main.c domain.c domain.h repo.c repo.h controller.c controller.h DynamicArray.c DynamicArray.h OperationStack.c OperationStack.h UI.c UI.h)