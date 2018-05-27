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

signals:

public slots:
};

#endif // DISPLAYHANDLER_H
