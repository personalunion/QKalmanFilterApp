#include "sensorkalmanfilter.h"

namespace Kalman {

}

SensorKalmanFilter::SensorKalmanFilter(QObject *parent) :
    QObject(parent)
{
}

void SensorKalmanFilter::makeBaseB()
{

}

void SensorKalmanFilter::makeB()
{

}

void SensorKalmanFilter::makeProcess()
{
    using namespace Kalman;
    // x = Ax + Bu + Ww    n.1 = n.n * n.1 + n.nu * nu.1
    makeB();

    K_UINT_32 i;
    K_UINT_32 j;
    x__.resize(n);


    for (i = EKFilter::beg; i < n + EKFilter::beg; ++i) {

      x__(i) = EKFilter::type(0.0);

      for (j = EKFilter::beg; j < n + EKFilter::beg; ++j)
        x__(i) += A(i,j) * x(j);

      for (j = EKFilter::beg; j < nu + EKFilter::beg; ++j)
        x__(i) += B(i,j) * u(j);

    }

    x.swap(x__);
}

void SensorKalmanFilter::gotNewMeasurement(QHash<QString, float> values)
{

}



