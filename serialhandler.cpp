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

    this->line = new QString("");

    qDebug() << "Contrutor Serial Handler!";

    connect(serial_port, SIGNAL(readyRead()), this, SLOT(DataReceived()));

    this->serial_port->open(QSerialPort::ReadWrite);

}

void SerialHandler::DataReceived() {

    if (serial_port->canReadLine()) {

        for (int i = 0; i < serial_port->readLine().length(); i++) {

        }

        line = serial_port->readLine();

    }

    qDebug() << line;
}
