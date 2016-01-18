TEMPLATE = app

QT += qml quick sensors
CONFIG += c++11

SOURCES += main.cpp \
    sensorhandler.cpp \
    deltathread.cpp \
    sensorkalmanfilter.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    sensorhandler.h \
    deltathread.h \
    sensorkalmanfilter.h \
    kalman/ekfilter.hpp \
    kalman/ekfilter_impl.hpp \
    kalman/kfilter.hpp \
    kalman/kfilter_impl.hpp \
    kalman/kmatrix.hpp \
    kalman/kmatrix_impl.hpp \
    kalman/ktypes.hpp \
    kalman/kvector.hpp \
    kalman/kvector_impl.hpp \

#INCLUDEPATH += /usr/local/include/kalman
#LIBS += lkalman
