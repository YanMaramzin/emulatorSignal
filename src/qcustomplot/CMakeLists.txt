cmake_minimum_required(VERSION 3.28)
project(qmlqcustomplot)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS Widgets Quick PrintSupport Qml REQUIRED)

add_library(${PROJECT_NAME}
    qcustomplot.h
    qcustomplot.cpp
    qmlqcustomplot.h
    qmlqcustomplot.cpp
)

target_link_libraries(${PROJECT_NAME}
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::PrintSupport
    Qt6::Qml
    Qt6::Quick)
