cmake_minimum_required(VERSION 3.15)
project(test_qt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(test_qt MainWindow.ui main.cpp Repository.cpp Repository.h MainWindow.cpp MainWindow.h Domain.cpp Domain.h Tests.cpp Tests.h)
target_link_libraries(test_qt PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Charts
        yaml-cpp)