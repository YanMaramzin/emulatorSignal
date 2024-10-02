cmake_minimum_required(VERSION 3.28)
project(generatorbackend)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(${PROJECT_NAME}
    generatorbackend.h
    generatorbackend.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
)

target_link_libraries(${PROJECT_NAME} Qt6::Core qmlqcustomplot generator)

