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
    QString *line;

signals:

public slots:
    void DataReceived();
};

#endif // SERIALHANDLER_H
