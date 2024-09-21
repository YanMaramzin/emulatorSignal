cmake_minimum_required(VERSION 3.28)
project(emulatorSignal)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Quick Qml Gui REQUIRED)

add_executable(emulatorSignal main.cpp)

add_subdirectory(src)

target_link_libraries(emulatorSignal PUBLIC
        Qt6::Quick
        Qt6::Qml
        Qt6::Gui
        emulQml
        qmlqcustomplot)

message(${PROJECT_SOURCE_DIR})
target_include_directories(emulatorSignal PUBLIC
        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/src/qcustomplot"
)