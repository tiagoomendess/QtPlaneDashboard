#include "displayhandler.h"

DisplayHandler::DisplayHandler(QObject *parent, QQmlApplicationEngine *engine) : QObject(parent)
{

    qDebug() << "Contrutor DisplayHandler!";

    this->engine = engine;

    this->speedText = engine->rootObjects().at(0)->findChild<QObject*>("speedText");
    this->altitudeText = engine->rootObjects().at(0)->findChild<QObject*>("altitudeText");
    this->headingText = engine->rootObjects().at(0)->findChild<QObject*>("headingText");
    this->lockedText = engine->rootObjects().at(0)->findChild<QObject*>("lockedText");
    this->angleImage = engine->rootObjects().at(0)->findChild<QObject*>("angleImage");
    this->temperatureText = engine->rootObjects().at(0)->findChild<QObject*>("temperatureText");
    this->humidityText = engine->rootObjects().at(0)->findChild<QObject*>("humidityText");

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

    temperatureText->setProperty("text", valor);
}

void DisplayHandler::setHumidityText(int valor) {

    humidityText->setProperty("text", valor);
}

void DisplayHandler::setLockedText(bool valor) {

    if (valor)
        lockedText->setProperty("text", "LCKD");
    else
        lockedText->setProperty("text", "");

}

void DisplayHandler::setImageAngle(double roll) {
    //GG
}

void DisplayHandler::setImageDisplacement(double pitch) {
    //GG
}

