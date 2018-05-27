#ifndef DISPLAYHANDLER_H
#define DISPLAYHANDLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QDebug>

class DisplayHandler : public QObject
{
    Q_OBJECT
public:
    explicit DisplayHandler(QObject *parent = nullptr, QQmlApplicationEngine *engine = nullptr);

private:
    QQmlApplicationEngine *engine;
    QObject *speedText;
    QObject *altitudeText;
    QObject *headingText;
    QObject *lockedText;
    QObject *angleImage;
    QObject *temperatureText;
    QObject *humidityText;

signals:

public slots:
    void setSpeedText(int valor);
    void setAltitudeText(int valor);
    void setHeadingText(int valor);
    void setTemperatureText(int valor);
    void setHumidityText(int valor);
    void setLockedText(bool valor);
    void setImageAngle(double roll);
    void setImageDisplacement(double pitch);

};

#endif // DISPLAYHANDLER_H
