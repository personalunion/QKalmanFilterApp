#include "sensorhandler.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QtQml>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    QQuickView view;
//    SensorHandler *handler = new SensorHandler();
//    view.rootContext()->setContextProperty("sensorhandler", handler);
//    view.setSource(QUrl("qrc:/main.qml"));
//    view.show();
    qmlRegisterType<SensorHandler>("QtKalmanSensors", 1, 0, "SensorHandler");
    QQmlApplicationEngine engine(QUrl("qrc:/main.qml"));

    return app.exec();
}
