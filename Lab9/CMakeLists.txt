cmake_minimum_required(VERSION 3.15)
project(Lab9)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra --coverage")
find_package(Qt5Widgets REQUIRED)
set(CMAKE_AUTOMOC ON)

add_executable(Lab9 main.cpp Domain.cpp Domain.h Repository.cpp Repository.h Service.cpp Service.h UI.cpp UI.h Tests.cpp Tests.h FileRepository.cpp FileRepository.h DogValidator.cpp DogValidator.h HtmlRepository.cpp HtmlRepository.h MainWindow.cpp MainWindow.h FileDialogBox.cpp FileDialogBox.h)

target_link_libraries(Lab9 Qt5::Widgets)