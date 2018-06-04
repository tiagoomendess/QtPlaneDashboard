import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1280
    height: 720
    title: qsTr("Trabalho 2")

    Text {
        objectName: "speedText"
        id: speed_text
        x: parent.width * 0.29
        y: parent.height * 0.478
        z: 32
        text: qsTr("0")
        font.pixelSize: parent.width * 0.0195
    }

    Text {
        objectName: "lockedText"
        id: locked_text
        x: parent.width * 0.56
        y: parent.height * 0.20
        z: 31
        color: "pink"
        text: qsTr("LCKD")
        font.bold: true
        font.pixelSize: parent.width * 0.0250
    }

    Text {
        objectName: "temperatureText"
        id: temperature_text
        x: parent.width * 0.39
        y: parent.height * 0.75
        z: 35
        color: "lightblue"
        text: qsTr("0 Cº")
        font.pixelSize: 28
    }

    Text {
        objectName: "humidityText"
        id: humidity_text
        x: parent.width * 0.58
        y: parent.height * 0.75
        z: 35
        color: "lightblue"
        text: qsTr("0%")
        font.pixelSize: 28
    }

    Text {
        objectName: "altitudeText"
        id: altitude_text
        x: parent.width * 0.655
        y: parent.height * 0.478
        z: 32
        text: qsTr("00000")
        font.pixelSize: parent.width * 0.0195
        horizontalAlignment: AlignRight

    }

    Text {
        objectName: "headingText"
        id: heading_text
        x: parent.width * 0.48
        y: parent.height * 0.20
        z: 31
        color: "green"
        text: qsTr("280")
        font.bold: true
        font.pixelSize: parent.width * 0.0250
    }

    Image {
        objectName: "imageLayer1"
        id: layer1
        x: 0
        y: 0
        z: 30
        width: parent.width
        height: parent.height
        source: "layer1.png"
    }

    Image {
        objectName: "imageLayer2"
        id: layer2
        x: 0
        y: 0
        z: 20
        width: parent.width
        height: parent.height
        source: "layer2.png"
    }

    Image {
        objectName: "imageLayer3"
        id: layer3
        x: 0
        y: 0
        z: 10
        width: parent.width
        height: parent.height
        source: "layer3.png"
    }
}
