#ifndef SENSORHANDLER_H
#define SENSORHANDLER_H

#include "deltathread.h"
#include "sensorkalmanfilter.h"

#include <QObject>
#include <QtSensors/QAccelerometer>
#include <QAccelerometerFilter>

#include <QtSensors/qsensor.h>
#include <QSensorBackendFactory>
#include <QThread>

class SensorHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float x READ x WRITE setX NOTIFY xChanged)
    Q_PROPERTY(float y READ y WRITE setY NOTIFY yChanged)
    Q_PROPERTY(float z READ z WRITE setZ NOTIFY zChanged)
    Q_PROPERTY(float delta READ delta_acc WRITE setDelta_acc NOTIFY deltaChanged)
    Q_PROPERTY(bool filter_enabled READ filter_enabled WRITE setFilter_enabled NOTIFY filter_enabledChanged)
public:
    explicit SensorHandler(QObject *parent = 0);
    DeltaThread* _deltaFilter;
    QThread* _filterthread;

    void filterWithDelta(float delta, QHash<QString, float> values);

    float x() const;
    void setX(float x);

    float y() const;
    void setY(float y);

    float z() const;
    void setZ(float z);

    bool filter_enabled() const;
    void setFilter_enabled(bool filter_enabled);
    void sendRawData(QHash<QString, float>);
    float _delta_acc;

    float delta_acc() const;
    void setDelta_acc(float delta_acc);

private:
    QAccelerometer* _acc;
    QAccelerometerFilter *_filter;
    SensorKalmanFilter *_kalmanFilter;
    float _x;
    float _y;
    float _z;
    bool _filter_enabled;

signals:
    void xChanged();
    void yChanged();
    void zChanged();
    void filter_enabledChanged();
    void deltaChanged();
    void filterValues(QHash<QString, float> values);
    void sendNewValues(QHash<QString, float> values);

public slots:
    void handleData();
    void sendX(float x);
    void sendY(float y);
    void sendZ(float z);
};

#endif // SENSORHANDLER_H
