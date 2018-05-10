import QtQuick 2.10
import QtQuick.Controls 2.2
import QtQuick.Window 2.10

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        text: "Send message"
        onClicked: {
            connectorHandler.sendRequest("Hello from client!")
        }
    }
}
