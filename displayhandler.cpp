#include "displayhandler.h"

DisplayHandler::DisplayHandler(QObject *parent, QQmlApplicationEngine *engine) : QObject(parent)
{

    qDebug() << "Contrutor DisplayHandler!";

    this->engine = engine;

    this->speedText = this->engine->rootObjects().at(0)->findChild<QObject*>("speedText");
    this->altitudeText = this->engine->rootObjects().at(0)->findChild<QObject*>("altitudeText");
    this->headingText = this->engine->rootObjects().at(0)->findChild<QObject*>("headingText");
    this->lockedText = this->engine->rootObjects().at(0)->findChild<QObject*>("lockedText");
    this->angleImage = this->engine->rootObjects().at(0)->findChild<QObject*>("imageLayer3");
    this->temperatureText = this->engine->rootObjects().at(0)->findChild<QObject*>("temperatureText");
    this->humidityText = this->engine->rootObjects().at(0)->findChild<QObject*>("humidityText");

}

void DisplayHandler::setSpeedText(int valor) {

    speedText->setProperty("text", valor);
}


void DisplayHandler::setAltitudeText(int valor) {

    altitudeText->setProperty("text", valor);
}

void DisplayHandler::setHeadingText(int valor) {

    headingText->setProperty("text", valor);
}

void DisplayHandler::setTemperatureText(int valor) {

    temperatureText->setProperty("text", QString::number(valor) + " ºC");
}

void DisplayHandler::setHumidityText(int valor) {

    humidityText->setProperty("text", QString::number(valor) + "%");
}

void DisplayHandler::setLockedText(bool valor) {

    if (valor)
        qDebug() << lockedText->setProperty("text", "LCKD");
    else
        qDebug() << lockedText->setProperty("text", "");

}

void DisplayHandler::setImageAngle(double roll) {
    angleImage->setProperty("rotation", roll);
}

void DisplayHandler::setImageDisplacement(double pitch) {

    if (pitch > 0.2 || pitch < -0.2)
        angleImage->setProperty("y", pitch *5);
    else
        angleImage->setProperty("y", 0);
}

