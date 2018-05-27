#ifndef SERIALHANDLER_H
#define SERIALHANDLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QSerialPort>
#include <QDebug>

class SerialHandler : public QObject
{
    Q_OBJECT
public:
    explicit SerialHandler(QObject *parent = nullptr, QQmlApplicationEngine *engine = nullptr);

private:
    QQmlApplicationEngine *engine;
    QSerialPort *serial_port;
    QString line;

    int speed, altitude, temperature, humidity, heading;
    double pitch, roll;
    bool locked;

    QStringList lineData;

signals:
    void pitchChanged(double value);
    void rollChanged(double value);
    void headingChanged(int value);
    void speedChanged(int value);
    void altitudeChanged(int value);
    void temperatureChanged(int value);
    void humidityChanged(int value);
    void lockedChanged(bool value);

public slots:
    void DataReceived();
};

#endif // SERIALHANDLER_H
