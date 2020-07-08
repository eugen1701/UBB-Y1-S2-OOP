cmake_minimum_required(VERSION 3.15)
project(exam_guide_model)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra --coverage")
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(exam_guide_model main.cpp Repository.h Domain.h StarTableModel.cpp StarTableModel.h Domain.cpp AstronomerWindow.cpp AstronomerWindow.h AstronomerWindow.ui tests.h tests.cpp)

target_link_libraries(exam_guide_model PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Charts
        yaml-cpp)