import QtQuick 2.0
import SFML 1.0

Item
{
    width: 320
    height: 480
    transformOrigin: Item.Center

    Rectangle
    {
        x: 5
        y: 5
        width: 100
        height: 100
        color: Qt.rgba(1, 1, 1, 0.7)
        radius: 10
        border.width: 1
        border.color: "#0e95d3"
        anchors.margins: -10

        SFMLItem
        {
            id: xSFMLItem
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5
            anchors.topMargin: 5

            sfmlEngine: SFMLEngine_instance
        }
    }

    Rectangle
    {
        x: 10
        y: 392
        width: 302
        height: 80
        color: Qt.rgba(1, 1, 1, 0.7)
        radius: 10
        border.width: 1
        border.color: "#0e95d3"
        anchors.margins: -10

        Text
        {
            id: label
            color: "black"
            wrapMode: Text.WordWrap
            text: "The background here is a squircle rendered with raw OpenGL using the 'beforeRender()' signal in QQuickWindow. This text label and its border is rendered using QML"
            anchors.rightMargin: 5
            anchors.leftMargin: 5
            anchors.bottomMargin: 5
            anchors.topMargin: 5
            anchors.fill: parent
            anchors.margins: 20
        }
    }

    GridView {
        id: grid_view1
        x: 8
        y: 8
        width: 304
        height: 376
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            height: 50
            Column {
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Text {
                    x: 5
                    text: name
                    font.bold: true
                    anchors.horizontalCenter: parent.horizontalCenter
                }
                spacing: 5
            }
        }
        cellWidth: 70
        cellHeight: 70

        MouseArea {
            id: mousearea1
            anchors.fill: parent
        }

        Rectangle {
            id: rectangle1
            x: 19
            y: 106
            width: 256
            height: 69
            color: "#ffffff"
            border.color: "#0e95d3"

            TextInput {
                id: text_input1
                color: "#e00202"
                text: qsTr("Text")
                anchors.fill: parent
                font.pixelSize: 12
            }
        }
    }
}
