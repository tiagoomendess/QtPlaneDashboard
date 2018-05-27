import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("Trabalho 2")

    Text {
        id: speed_text
        x: 383
        y: 345
        z: 31
        text: qsTr("230")
        font.pixelSize: 26
    }

    Text {
        id: locked_text
        x: 729
        y: 147
        z: 31
        color: "pink"
        text: qsTr("LCKD")
        font.bold: true
        font.pixelSize: 28
    }

    Text {
        id: temperature_text
        x: 505
        y: 543
        z: 35
        color: "lightblue"
        text: qsTr("0 Cº")
        font.pixelSize: 28
    }

    Text {
        id: humidity_text
        x: 729
        y: 543
        z: 35
        color: "lightblue"
        text: qsTr("0%")
        font.pixelSize: 28
    }

    Text {
        id: altitude_text
        x: 855
        y: 345
        z: 31
        text: qsTr("230")
        font.pixelSize: 28
    }

    Text {
        id: heading_text
        x: 613
        y: 147
        z: 31
        color: "green"
        text: qsTr("280")
        font.bold: true
        font.pixelSize: 28
    }

    Image {
        id: layer1
        x: 0
        y: 0
        z: 30
        width: parent.width
        height: parent.height
        source: "layer1.png"
    }

    Image {
        id: layer2
        x: 0
        y: 0
        z: 20
        width: parent.width
        height: parent.height
        source: "layer2.png"
    }

    Image {
        id: layer3
        x: 0
        y: 0
        z: 10
        width: parent.width
        height: parent.height
        source: "layer3.png"
    }
}
