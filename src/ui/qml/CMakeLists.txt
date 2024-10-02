cmake_minimum_required(VERSION 3.28)
project(emulQml)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

qt_add_qml_module(emulQml
    URI EmulQml
    QML_FILES
    main.qml
    PlotView.qml
    GeneratorPage.qml
)

target_link_libraries(emulQml PRIVATE Qt6::Core)
