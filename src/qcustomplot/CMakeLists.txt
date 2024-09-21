cmake_minimum_required(VERSION 3.28)
project(qcustomplot)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(${PROJECT_NAME}
    qcustomplot.h
    qcustomplot.cpp
)

target_link_libraries(${PROJECT_NAME} Qt6::Core)
