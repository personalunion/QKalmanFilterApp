#include "deltathread.h"
#include <qdebug.h>

DeltaThread::DeltaThread(float delta, QObject *parent) : QObject(parent)
{
    _delta = delta;
    _x = 0;
    _y = 0;
    _z = 0;
}

void DeltaThread::startFiltering(QHash<QString, float> values)
{
//    qDebug() << "delta" << _delta;
//    qDebug() << "x" << values["x"] << _x;
//    qDebug() << "y" << values["y"] << _y;
//    qDebug() << "z" << values["z"] << _z;
    if(_x - _delta > values["x"])
    {
        qDebug() << "Changing x";
        _x = values["x"];
        emit x_changed(_x);
    }
    if(_y - _delta > values["y"])
    {
        qDebug() << "Changing y";
        _y = values["y"];
        emit y_changed(_y);
    }
    if(_z - _delta > values["z"])
    {
        qDebug() << "Changing z";
        _z = values["z"];
        emit z_changed(_z);
    }
}
