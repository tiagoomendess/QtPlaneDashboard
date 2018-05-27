#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "serialhandler.h"
#include "displayhandler.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    SerialHandler serial(0, &engine);
    DisplayHandler display(0, &engine);

    return app.exec();
}
