import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
// import EmulListModel 1.0

ApplicationWindow {
    id: window
    visible: true

    Component {
        id: highlight1
        Rectangle {
            width: 180; height: 40
            // color: "lightsteelblue";
            border.width: 2
            border.color: "black"
        }
    }

    ListModel {
        id: modelList
        ListElement { name: "Эмулятор 1"; connected: true;  ip: "172.22.18.195"; port: "5802"}
        ListElement { name: "Эмулятор 2"; connected: false; ip: "172.22.18.195"; port: "5803"}
        ListElement { name: "Эмулятор 3"; connected: true;  ip: "172.22.18.195"; port: "5804"}
    }

    width: 640
    height: 480

    Page {
        anchors.fill: parent

        header: Text {
            text: qsTr("Эмуляторы")
        }

        ColumnLayout {
            Button {
                text: qsTr("Добавить")
            }

            ListView {
                id: listEmulators
                width: 400
                height: 400
                model: modelList
                delegate: RowLayout {
                    MouseArea {
                        anchors.fill: parent
                        onClicked: listEmulators.currentIndex = index
                    }

                    // Image {
                    //
                    // }

                    Text {
                        text: name
                    }
                    CheckBox {
                        checked: connected
                    }

                    Text {
                        text: ip
                    }

                    TextField {
                        text: port
                    }


                }

                // highlight: highlight1

            }

        }

    }

    // SplitView {
    //     anchors.fill: parent
    //     orientation: Qt.Horizontal
    //
    //
    //     Page {
    //
    //         header: Text {
    //             text: qsTr("Настройки")
    //         }
    //
    //         ColumnLayout {
    //             anchors.fill: parent
    //             Rectangle {
    //                 width: window.width / 2
    //                 height: 48
    //                 color: "red"
    //             }
    //         }
    //     }
    // }
}
