#include "displayhandler.h"

DisplayHandler::DisplayHandler(QObject *parent, QQmlApplicationEngine *engine) : QObject(parent)
{

    qDebug() << "Contrutor Display Handler!";

    this->engine = engine;

    this->speedText = engine->rootObjects().at(0)->findChild<QObject*>("speedText");
    this->altitudeText = engine->rootObjects().at(0)->findChild<QObject*>("altitudeText");
    this->headingText = engine->rootObjects().at(0)->findChild<QObject*>("headingText");
    this->lockedText = engine->rootObjects().at(0)->findChild<QObject*>("lockedText");
    this->angleImage = engine->rootObjects().at(0)->findChild<QObject*>("angleImage");

}

void DisplayHandler::setSpeedText(int valor) {

    speedText->setProperty("text", qsTr(valor));
}


void DisplayHandler::setAltitudeText(int valor) {

    altitudeText->setProperty("text", qsTr(valor));
}

void DisplayHandler::setHeadingText(int valor) {

    headingText->setProperty("text", qsTr(valor));
}

void DisplayHandler::setLockedText(bool valor) {

    if (valor)
        lockedText->setProperty("text", qsTr("LCKD"));
    else
        lockedText->setProperty("text", qsTr(""));

}

void DisplayHandler::setImageAngle(double roll) {
    //GG
}

void DisplayHandler::setImageDisplacement(double pitch) {
    //GG
}

