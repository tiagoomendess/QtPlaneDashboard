#include "serialhandler.h"

SerialHandler::SerialHandler(QObject *parent, QQmlApplicationEngine *engine, DisplayHandler *display) : QObject(parent)
{
    this->engine = engine;
    this->display = display;

    this->serial_port = new QSerialPort();
    this->serial_port->setBaudRate(QSerialPort::Baud9600);
    this->serial_port->setStopBits(QSerialPort::OneStop);
    this->serial_port->setDataBits(QSerialPort::Data8);
    this->serial_port->setParity(QSerialPort::NoParity);
    this->serial_port->setFlowControl(QSerialPort::NoFlowControl);
    this->serial_port->setPortName("COM4");

    this->speed = 0;
    this->heading = 0;
    this->altitude = 0;
    this->pitch = 0.0;
    this->roll = 0.0;
    this->locked = true;
    this->temperature = 0;
    this->humidity = 0;

    qDebug() << "Contrutor SerialHandler!";

    //Connects
    connect(serial_port, SIGNAL(readyRead()), this, SLOT(DataReceived()));
    connect(this, SIGNAL(speedChanged(int)), display, SLOT(setSpeedText(int)));
    connect(this, SIGNAL(lockedChanged(bool)), display, SLOT(setLockedText(bool)));

    this->serial_port->open(QSerialPort::ReadWrite);

}

void SerialHandler::DataReceived() {

    if (serial_port->canReadLine()) {

        QByteArray arr = serial_port->readLine();

        line = QString::fromStdString(arr.toStdString());
        line = line.replace("\r\n", "");
        //pitch,roll,heading,speed,altitude,temperature,humidity,locked
        lineData = line.split(",");

        if (lineData.length() != 8)
            return;

        //Get pitch
        if (lineData.at(0).toDouble() != pitch) {
            qDebug() << "Pitch Changed";
            pitch = lineData.at(0).toDouble();
            emit this->pitchChanged(pitch);
        }

        //Get roll
        if (lineData.at(1).toDouble() != roll) {
            qDebug() << "Roll Changed";
            roll = lineData.at(1).toDouble();
            emit this->rollChanged(roll);
        }

        //Get heading
        if (lineData.at(2).toInt() != heading) {
            qDebug() << "Heading Changed";
            heading = lineData.at(2).toInt();
            emit this->headingChanged(heading);
        }

        //Get speed
        if (lineData.at(3).toInt() != speed) {
            qDebug() << "Speed Changed";
            speed = lineData.at(3).toInt();
            emit this->speedChanged(speed);
        }

        //Get altitude
        if (lineData.at(4).toInt() != altitude) {
            qDebug() << "Altitude Changed";
            altitude = lineData.at(4).toInt();
            emit this->altitudeChanged(altitude);
        }

        //Get temperature
        if (lineData.at(5).toInt() != temperature) {
            qDebug() << "Temperature Changed";
            temperature = lineData.at(5).toInt();
            emit this->temperatureChanged(temperature);
        }

        //Get humidity
        if (lineData.at(6).toInt() != humidity) {
            qDebug() << "Humidity Changed";
            humidity = lineData.at(6).toInt();
            emit this->humidityChanged(humidity);
        }

        //Get locked
        if ((bool)lineData.at(7).toInt() != locked) {
            qDebug() << "Locked Changed";
            locked = (bool)lineData.at(7).toInt();
            emit this->lockedChanged(locked);
        }

    }

}
/*
int SerialHandler::temperatureChanged() {
    return temperature
}*/
