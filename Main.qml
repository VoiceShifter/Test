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
        Component.onCompleted:
        {

            //_Parser._FillCurrentDayS()
            _Parser._PrintAmount()

        }

    }

    Rectangle
    {

        id: _Backwards

        width: 100
        height: 100
        color: "black"
        x: 30; y: 30;
        MouseArea{
            anchors.fill: parent
            onClicked:
            {
                _Parser._DecrementDay()

            }
        }

    }
    Rectangle
    {
        id: _Forward
        width: 100
        height: 100
        color: "white"
        x: 300; y: 30;
        border.color: "black"
        border.width: 1
        anchors.verticalCenter: _Backwards.verticalCenter
        MouseArea{
            anchors.fill: parent
            onClicked:
            {
                _Parser._IncrementDay()

            }
        }
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
                _Parser._GetReply("ИКБО-07-21")
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
        Text {
            id: _Read
            text: qsTr("Print Items")
            font.bold: true
            font.pointSize: 12
            color: "black"
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                //_Parser._ReadValue(_Day.text) //deprecated
                _Parser._FillCurrentDayS()
            }
        }
    }


    ListView
    {
        z: -1
        id: _ListLines
        anchors.top: _Button2.bottom
        width: parent.width
        height: 50 * 60
        spacing: -1

        model: _Parser._ItemName
        delegate:

            Rectangle
                {
                    id: _Deligated
                    border.color: "black"
                    border.width: 1
                    width: parent.width
                    height: 60
                    Text {

                        id: name
                        font.bold: true
                        text: modelData

                        anchors.verticalCenter: parent.verticalCenter
                        // anchors.horizontalCenter: parent.horizontalCenter
                        font.pointSize: 12
                        color: "black"

                    }
                }
    }


}
