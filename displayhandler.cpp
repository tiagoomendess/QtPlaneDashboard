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

    temperatureText->setProperty("text", valor);
}

void DisplayHandler::setHumidityText(int valor) {

    humidityText->setProperty("text", valor);
}

void DisplayHandler::setLockedText(bool valor) {

    if (valor)
        qDebug() << lockedText->setProperty("text", "LCKD");
    else
        qDebug() << lockedText->setProperty("text", "");

}

void DisplayHandler::setImageAngle(double roll) {
    //GG
}

void DisplayHandler::setImageDisplacement(double pitch) {
    //GG
}

