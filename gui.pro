#-------------------------------------------------
#
# Project created by QtCreator 2016-04-05T13:54:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gui
TEMPLATE = app


SOURCES += main.cpp\
        logingui.cpp \
    mainwindow.cpp

HEADERS  += logingui.h \
    mainwindow.h

FORMS    += logingui.ui \
    mainwindow.ui

RESOURCES += \
    icons.qrc
