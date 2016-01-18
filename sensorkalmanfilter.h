#ifndef SENSORKALMANFILTER_H
#define SENSORKALMANFILTER_H

#include <QObject>
#include <QGenericMatrix>
#include "kalman/ekfilter.hpp"
#include "kalman/ktypes.hpp"
#define TIMESTEPS 1000

//namespace Kalman{

class SensorKalmanFilter :
        public QObject,
        public Kalman::EKFilter<float, 1>//, false, true, false>
{
    //using namespace Kalman;

    Q_OBJECT
public:
    //KFilter::~KFilter();
    explicit SensorKalmanFilter(QObject *parent = 0);

private:
    void makeBaseA();
    void makeA();

    //! Pre-creator of \a B.
    void makeBaseB();

    //! Creator of \a B.
    void makeB();

    //! Input matrix.
    //!
    //uint BEG;
    //type T;
    Matrix B;
    //! Process function overridden to be linear.
    virtual void makeProcess();

    //! Measurement function overridden to be linear.
    virtual void makeMeasure();

    //! Temporary vector.
    Vector x__;

signals:

public slots:
    void gotNewMeasurement(QHash<QString, float> values);
};

//}
#endif // SENSORKALMANFILTER_H
