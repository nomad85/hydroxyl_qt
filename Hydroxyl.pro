#-------------------------------------------------
#
# Project created by QtCreator 2013-06-19T13:18:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4) {
    QT *= printsupport
}

TARGET = Hydroxyl
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    initwindow.cpp \
    managewindow.cpp \
    ../CustomPlot/qcustomplot.cpp \
    optionswindow.cpp \
    acceptwindow.cpp \
    exitwindow.cpp \
    hydroxyl.cpp

HEADERS  += dialog.h \
    VisibleProperties.h \
    initwindow.h \
    managewindow.h \
    ../CustomPlot/qcustomplot.h \
    optionswindow.h \
    acceptwindow.h \
    exitwindow.h \
    hydroxyl.h

FORMS    += dialog.ui \
    init.ui \
    manage.ui \
    options.ui \
    acceptParams.ui \
    exitwindow.ui

RESOURCES += \
    resources_hydroxyl.qrc
INCLUDEPATH

