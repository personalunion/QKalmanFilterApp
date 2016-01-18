#ifndef DELTATHREAD_H
#define DELTATHREAD_H

#include <QObject>
#include <QHash>

class DeltaThread : public QObject
{
    Q_OBJECT
public:
    DeltaThread(float delta, QObject *parent = 0);

private:
    float _delta;
    float _x;
    float _y;
    float _z;


public slots:
    void startFiltering(QHash<QString, float> values);


signals:
    void x_changed(float new_x);
    void y_changed(float new_y);
    void z_changed(float new_z);
};

#endif // DELTATHREAD_H
