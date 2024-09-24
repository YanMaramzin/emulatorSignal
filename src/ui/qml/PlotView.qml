import QtQuick 2.0
import CustomPlot 1.0

Item {
    id: plotForm

    Text {
        id: text
        text: qsTr("Plot form")
    }

    CustomPlot {
        id: customPlot
        anchors.fill: parent

        Component.onCompleted: initCustomPlot()
    }
}