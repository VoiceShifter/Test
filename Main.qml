import QtQuick
import QtQuick.Controls
import ServerCall 1.0
import JsonParser 1.0
import "CustomColors"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    ServerCall
    {
        id: _ServerCall

    }
    JsonParser
    {
        id: _Parser
    }

    Switch
    {
        id: control
                checked: true

        indicator: Rectangle {
                    implicitWidth: 48
                    implicitHeight: 26
                    x: control.width - width - control.rightPadding
                    y: parent.height / 2 - height / 2
                    radius: 13
                    color: control.checked ? CustomColors._LightThemeColor: CustomColors._DarkThemeColor
                    border.color: "black"

                    Rectangle {
                        x: control.checked ? parent.width - width : 0
                        width: 26
                        height: 26
                        radius: 13
                        border.color: "black"
                    }
                }

        onClicked:
        {
            if (checked)
            {
                CustomColors._CurrentTheme = CustomColors.themes._Light

            }
            else
            {
                CustomColors._CurrentTheme = CustomColors.themes._Dark

            }


            console.log(_Switch.position)
        }
    }

    Rectangle
    {
        id: _Button
        width: 50
        height: 50
        anchors.centerIn: parent
        color: CustomColors._PrimaryBlue
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                CustomColors._CurrentTheme = CustomColors.themes._Light
                _Parser._GetReply(_Group.text)
            }
        }
    }
    Rectangle
    {
        id: _Button2
        width: 50
        height: 50

        anchors.horizontalCenter: _Button.horizontalCenter
        anchors.top: _Button.bottom
        color: "red"
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                _Parser._ReadValue()

            }
        }
    }
    TextField
    {
        id: _Group
        width: 300
        height: 100
        anchors.top: _Button2.bottom
        anchors.horizontalCenter: _Button2.horizontalCenter
    }


}
