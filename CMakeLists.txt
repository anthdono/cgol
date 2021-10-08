cmake_minimum_required(VERSION 3.18.4)
project(cgol)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/home/deb/Qt/6.1.3/gcc_64")

set(PROJECT_SOURCES
    widget.cpp
    widget.h
    app.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Qt6 REQUIRED Widgets Gui REQUIRED)

add_executable(cgol ${PROJECT_SOURCES})

target_link_libraries(cgol PRIVATE Qt6::Widgets Qt6::Gui)



