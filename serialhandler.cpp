#include "serialhandler.h"

SerialHandler::SerialHandler(QObject *parent, QQmlApplicationEngine *engine) : QObject(parent)
{
    this->engine = engine;

    this->serial_port = new QSerialPort();
    this->serial_port->setBaudRate(QSerialPort::Baud9600);
    this->serial_port->setStopBits(QSerialPort::OneStop);
    this->serial_port->setDataBits(QSerialPort::Data8);
    this->serial_port->setParity(QSerialPort::NoParity);
    this->serial_port->setFlowControl(QSerialPort::NoFlowControl);
    this->serial_port->setPortName("COM4");

    qDebug() << "Contrutor Serial Handler!";

    connect(serial_port, SIGNAL(readyRead()), this, SLOT(DataReceived()));

    this->serial_port->open(QSerialPort::ReadWrite);

}

void SerialHandler::DataReceived() {

    qDebug() << serial_port->readLine();
}
