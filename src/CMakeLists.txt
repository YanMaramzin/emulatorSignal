cmake_minimum_required(VERSION 3.28)
project(emulQml)

set_source_files_properties(qml/main.qml PROPERTIES
        QT_RESOURCE_ALIAS main.qml
)

qt_add_qml_module(emulQml
        URI EmulQml
        QML_FILES
        qml/main.qml
)