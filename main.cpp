#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialhandler.h"
#include "displayhandler.h"
#include <QObject>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    DisplayHandler *display = new DisplayHandler(0, &engine);
    SerialHandler *serial = new SerialHandler(0, &engine, display);

    return app.exec();
}
