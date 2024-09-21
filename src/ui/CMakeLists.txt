cmake_minimum_required(VERSION 3.28)
project(emulQml)

set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

set_source_files_properties(qml/main.qml PROPERTIES
        QT_RESOURCE_ALIAS main.qml
)

set_source_files_properties(model/emullistmodel.h PROPERTIES
        QT_RESOURCE_ALIAS emullistmodel.h
)

set_source_files_properties(model/emullistmodel.cpp PROPERTIES
        QT_RESOURCE_ALIAS emullistmodel.cpp
)

qt_add_qml_module(emulQml
        URI EmulQml
        QML_FILES
        qml/main.qml
        SOURCES
        model/emullistmodel.h
        model/emullistmodel.cpp
)
target_link_libraries(emulQml PRIVATE Qt6::Core)
