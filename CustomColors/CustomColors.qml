pragma Singleton
import QtQuick 2.15

Item {
    QtObject{
        id: _Themes
        readonly property var _Dark: ["#dbe2ef", "#7881ae", "#aab2cf", "#848cb5"]
        readonly property var _Light: ["#10439F", "#874CCC", "#C65BCF", "#F27BBD"]
    }
    property var _CurrentTheme: _Themes._Dark
    property var themes: _Themes

    readonly property string _DarkThemeColor: "#1E0342"
    readonly property string _LightThemeColor: "#9AC8CD"

    readonly property string _PrimaryPurple: _CurrentTheme[0]
    readonly property string _SecondaryPurple: _CurrentTheme[1]
    readonly property string _PrimaryBlue: _CurrentTheme[2]
    readonly property string _PrimaryGray: _CurrentTheme[3]


}
