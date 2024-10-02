import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import CustomPlot 1.0
import GeneratorBackend 1.0

Item {
    id: generatorPage

    GeneratorBackend {
        id: backend
    }

    Page {
        width: generatorPage.width
        height: generatorPage.height
        ColumnLayout {
            RowLayout {
                Label {
                    text: qsTr("Частота")
                }
                Rectangle {
                    width: 200
                    height: 20
                    color: "lightgrey"
                    border.color: "grey"
                    TextInput {
                        anchors.fill: parent
                        text: backend.frequency
                        validator: DoubleValidator {
                            bottom: 10; top: 20
                        }
                        clip: true

                        onTextChanged: backend.frequency = text
                    }
                }

                Label {
                    text: qsTr("Амплитуда")
                }
                Rectangle {
                    width: 200
                    height: 20
                    color: "lightgrey"
                    border.color: "grey"
                    TextInput {
                        anchors.fill: parent
                        text: backend.amplitude
                        validator: DoubleValidator {
                            bottom: 10; top: 20
                        }

                        onTextChanged: backend.amplitude = text
                    }
                }

                Button {
                    text: qsTr("Перерисовать")
                    onClicked: {
                        backend.replot()
                        console.log(customPlot.customPlot())
                        console.log(backend.customPlot())
                    }
                }
            }

            Item {
                width: generatorPage.width
                height: generatorPage.width
                CustomPlot {
                    id: customPlot
                    anchors.fill: parent

                    Component.onCompleted: {
                        customPlot.initCustomPlot()
                        backend.setQCustomPlot(customPlot)
                    }
                }
            }
        }
    }
}
