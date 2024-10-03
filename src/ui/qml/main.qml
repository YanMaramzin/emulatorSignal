import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ApplicationWindow {
    id: window
    visible: true

    width: 640
    height: 480

    ListModel {
        id: modelList
        ListElement { name: "Эмулятор 1"; connected: true;  ip: "172.22.18.195"; port: "5802"}
        ListElement { name: "Эмулятор 2"; connected: false; ip: "172.22.18.195"; port: "5803"}
        ListElement { name: "Эмулятор 3"; connected: true;  ip: "172.22.18.195"; port: "5804"}
    }

    Page {
        anchors.fill: parent
        header: TabBar {
            id: bar
            width: parent.width
            TabButton {
                text: qsTr("Генератор")
            }
            TabButton {
                text: qsTr("Home")
            }
        }

        contentItem: StackLayout {
            width: parent.width
            currentIndex: bar.currentIndex
            GeneratorPage {
                width: window.width
                height: window.height
            }
            Item {
                Page {
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
            }
        }
    }
}
