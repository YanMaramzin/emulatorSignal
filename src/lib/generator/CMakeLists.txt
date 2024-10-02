cmake_minimum_required(VERSION 3.28)
project(generator)

add_library(${PROJECT_NAME}
    basegenerator.h
    basegenerator.cpp
    customgeneratorparametrs.h
    customgeneratorparametrs.cpp
    generatorcos.h
    generatorcos.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
)