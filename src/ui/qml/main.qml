import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
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

        RowLayout {
            PlotView {
                width: 400
                height: 400
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


// ApplicationWindow {
//     visible: true
//     width: 640
//     height: 480
//     title: qsTr("Hello QCustomPlot in QML")

//     //    Item {
//     //        id: mainView
//     //        anchors.fill: parent
//     //        PlotView {
//     //        }
//     //    }
//     SwipeView {
//         id: swipeView
//         anchors.fill: parent
//         currentIndex: tabBar.currentIndex
//         interactive: false

//         PlotView {
//         }

//         Page {
//             Label {
//                 text: qsTr("This is implementation of http://www.qcustomplot.com/index.php/support/forum/172\n" +
//                     "Adding random data on 500 ms tick to plot")
//                 anchors.centerIn: parent
//             }
//         }
//     }

//     footer: TabBar {
//         id: tabBar
//         currentIndex: swipeView.currentIndex
//         TabButton {
//             text: qsTr("Plot")
//         }
//         TabButton {
//             text: qsTr("Info")
//         }
//     }
// }
