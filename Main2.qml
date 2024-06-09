import QtQuick
import JsonParser



Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    function _SaveToFile(n)
    {
        _Parser._StartCycle()
        for(var _Iterator in _List.contentItem.children)
        {
            var _Shorter = _List.contentItem.children[_Iterator]
            console.log(_Shorter._StudentName)
            var _Results = _Shorter._First !== "" ? _Shorter._First : (_Shorter._Second !== "" ? _Shorter._Second : _Shorter._Third);
            console.log(_Results)
            _Parser._IterateCycle(_Shorter._StudentName, _Results)
        }
        _Parser._SaveResults()

        // _Parser._StartCycle()
        // for (var i=0; i < n; i++)
        // {
        //     var _Results = _First !== "" ? _First : (_Second !== "" ? _Second : _Third);
        //     _Parser._IterateCycle(_Parser._Students[i], )
        // }
    }

    Rectangle //breaker
    {
        id: _Breaker
        color: "blue"
        width: parent.width - 60
        height: 5
        y: 5
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Component.onCompleted:
        {
            console.log("Breaker")
        }

    }

    Text
    {
        z:5
        anchors.top: _Breaker.bottom
        color:"black"
        anchors.horizontalCenter: parent.horizontalCenter
        text: _Parser._CurrentSubject
        Component.onCompleted:
        {
            console.log("Text")
        }
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                console.log(text)
            }
        }
    }



    AttendanceLine
    {
        z: 5
        id: _Template
        _StudentName: ""
        anchors.top: _Breaker.bottom
        anchors.topMargin: 20
        _First: "+"
        _Second: "-"
        _Third: "?"
        MouseArea
        {
            anchors.fill: parent
        }
        Component.onCompleted:
        {
            console.log("Example line")
        }
    }

    ListView
    {
        id: _List
        anchors.top: _Template.bottom
        width: parent.width
        height: parent.height
        model: _Parser._Students
        delegate: AttendanceLine
        {
            id: _Line
            _StudentName: modelData
        }
        Component.onCompleted:
        {
            console.log("List")
        }
    }
    Rectangle
    {
        id: _SaveButton
        width: 100
        height: 50
        color: "red"
        radius: 60
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        MouseArea
        {
            anchors.fill: parent
            onClicked:
            {
                _SaveToFile(_Parser._GetAmountStudents())
            }
        }

    }

    JsonParser
    {

        id: _Parser
        Component.onCompleted:
        {
            _Parser._FillCurrentDayS()
            _Parser._ChangeCurentSubject()
            console.log("_Parser")
        }

    }
}
