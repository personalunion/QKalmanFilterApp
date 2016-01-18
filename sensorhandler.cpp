#include "sensorhandler.h"
#include <qdebug.h>

SensorHandler::SensorHandler(QObject *parent)
    : QObject(parent)
{
    setDelta_acc(0.00000000001);
    setX(0);
    setY(0);
    setZ(0);

    _filter_enabled = false;
    filter_enabledChanged();

    _acc = new QAccelerometer(this);

    // Delta (difference) filter

    _filterthread = new QThread();
    _deltaFilter = new DeltaThread(_delta_acc, _filterthread);

    _deltaFilter->moveToThread(_filterthread);
    _acc->start();
    connect(_acc, SIGNAL(readingChanged()), this, SLOT(handleData()));
    connect(this, SIGNAL(filterValues(QHash<QString, float>)),
            _deltaFilter, SLOT(startFiltering(QHash<QString, float>)));
    connect(_deltaFilter, SIGNAL(x_changed(float)), this, SLOT(sendX(float)));
    connect(_deltaFilter, SIGNAL(y_changed(float)), this, SLOT(sendY(float)));
    connect(_deltaFilter, SIGNAL(z_changed(float)), this, SLOT(sendZ(float)));
    _filterthread->start();

    //Kalman Filter
    //_kalmanFilter = new SensorKalmanFilter();
    connect(this, SIGNAL(sendNewValues(QHash<QString, float>)),
            _kalmanFilter, SLOT(gotNewMeasurement(QHash<QString, float>)));
    connect(_kalmanFilter, SIGNAL(x_changed(float)), this, SLOT(sendX(float)));
    connect(_kalmanFilter, SIGNAL(y_changed(float)), this, SLOT(sendY(float)));
    connect(_kalmanFilter, SIGNAL(z_changed(float)), this, SLOT(sendZ(float)));

}

void SensorHandler::filterWithDelta(float delta,  QHash<QString, float> values)
{
//    qDebug() << "Sending data to thread";
    filterValues(values);
}

void SensorHandler::handleData()
{
    QSensorReading *reading = _acc->reading();
    //_filter->filter(reading);
    QHash<QString, float> values;
    values["x"] = reading->property("x").value<float>();
    values["y"] = reading->property("y").value<float>();
    values["z"] = reading->property("z").value<float>();
    if(!_filter_enabled){
        sendRawData(values);
    }else{
        //filterWithDelta(_delta_acc, values);
        sendNewValues(values);
    }
}

void SensorHandler::sendX(float x)
{
    setX(x);
}

void SensorHandler::sendY(float y)
{
    setY(y);
}

void SensorHandler::sendZ(float z)
{
    setZ(z);
}

void SensorHandler::sendRawData(QHash<QString, float> values)
{
    setX(values["x"]);
    setY(values["y"]);
    setZ(values["z"]);
}

float SensorHandler::delta_acc() const
{
    return _delta_acc;
}

void SensorHandler::setDelta_acc(float delta_acc)
{
    deltaChanged();
    _delta_acc = delta_acc;
}


float SensorHandler::x() const
{
    return _x;
}

void SensorHandler::setX(float x)
{
    xChanged();
    _x = x;
}

float SensorHandler::y() const
{
    return _y;
}

void SensorHandler::setY(float y)
{
    yChanged();
    _y = y;
}

float SensorHandler::z() const
{
    return _z;
}

void SensorHandler::setZ(float z)
{
    zChanged();
    _z = z;
}

bool SensorHandler::filter_enabled() const
{
    return _filter_enabled;
}

void SensorHandler::setFilter_enabled(bool filter_enabled)
{
    _filter_enabled = filter_enabled;
}


