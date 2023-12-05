#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T19:03:43
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serialportTest
TEMPLATE = app


SOURCES += main.cpp\
        console.cpp

HEADERS  += console.h

FORMS    += console.ui

RESOURCES += \
    data.qrc
RC_ICONS += terminal.ico
