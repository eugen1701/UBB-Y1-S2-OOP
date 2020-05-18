cmake_minimum_required(VERSION 3.15)
project(Lab9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra --coverage")
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets Charts)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(Lab9 main.cpp Domain.cpp Domain.h Repository.cpp Repository.h Service.cpp Service.h Tests.cpp
        Tests.h FileRepository.cpp FileRepository.h DogValidator.cpp DogValidator.h HtmlRepository.cpp HtmlRepository.h
        MainWindow.cpp MainWindow.h FileDialogBox.cpp FileDialogBox.h DisplayWidget.cpp DisplayWidget.h ChartWidget.cpp
        ChartWidget.h DogTableModel.cpp DogTableModel.h)

target_link_libraries(Lab9 PUBLIC
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Charts
        yaml-cpp)
