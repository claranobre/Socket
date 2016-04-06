#-------------------------------------------------
#
# Project created by QtCreator 2016-04-06T11:55:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Servidor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    servidor.cpp \
    DHT.cpp \
    update_interval.cpp \
    ledrgb.cpp \
    potenciometro.cpp

HEADERS  += mainwindow.h \
    time.h

FORMS    += mainwindow.ui
