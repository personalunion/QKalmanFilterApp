import QtQuick 2.3
import QtQuick.Window 2.2
import QtQuick.Controls 1.1

import QtKalmanSensors 1.0

Window {
    width: 500
    height: 500
    visible: true
    id: mainWindow

    SensorHandler{
        id: handler
    }
    Grid{
        id: mainGrid
        anchors.fill: parent
        anchors.margins: 10
        rows: 10
        columns: 2
        rowSpacing: 10
        Text {
            text: "Accelerometer"
        }
        Text {
            text: ":"
        }
        Text {
            text: "X:"
        }
        Text {
            text: handler.x
        }
        Text {
            text: "Y:"
        }
        Text {
            text: handler.y
        }
        Text {
            text: "Z:"
        }
        Text {
            text: handler.z
        }
        Text {
            text: "Simple delta Filter"
        }
        Text {
            text: handler.delta
        }

        Switch {
            id: filter_switch
            checked: handler.filter_enabled
            onCheckedChanged:
            {
                handler.filter_enabled = filter_switch.checked
            }
        }
    }
}
