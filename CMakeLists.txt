cmake_minimum_required(VERSION 3.16)

project(PcTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)

qt_standard_project_setup()

qt_add_executable(appPcTest
    main.cpp
)

qt_add_qml_module(appPcTest
    URI PcTest
    VERSION 1.0
    QML_FILES
        Main.qml
        MyDrawer.qml
        ColorsNSizes.qml
        CustomColors/qmldir
        CustomColors/CustomColors.qml

    SOURCES
        ServerCall.h ServerCall.cpp
        JsonParser.h JsonParser.cpp
        SOURCES Subject.h Subject.cpp
        QML_FILES Main2.qml

)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPcTest PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPcTest
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPcTest
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appPcTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

