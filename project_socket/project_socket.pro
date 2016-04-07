#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T14:25:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project_socket
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    DHT.cpp \
    ledrgb.cpp \
    potenciometro.cpp \
    update_interval.cpp \
    servidor.cpp \
    beaglebone.cpp

HEADERS  += mainwindow.h \
    time.h

FORMS    += mainwindow.ui
