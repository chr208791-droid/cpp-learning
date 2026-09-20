cmake_minimum_required(VERSION 3.16)

project(sensor_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_library(
    sensor_lib
    src/sensor.cpp
)


target_include_directories(
    sensor_lib
    PUBLIC
    include
)


add_executable(
    sensor_app
    app/main.cpp
)


target_link_libraries(
    sensor_app
    PRIVATE
    sensor_lib
)