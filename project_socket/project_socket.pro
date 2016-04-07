#-------------------------------------------------
#
# Project created by QtCreator 2016-04-07T14:25:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project_socket
TEMPLATE = app

CONFIG += c++11
CONFIG -= qt
LIBS += -pthread

SOURCES += main.cpp\
        mainwindow.cpp \
    DHT.cpp \
    ledrgb.cpp \
    potenciometro.cpp \
    update_interval.cpp \
    servidor.cpp \
    beaglebone.cpp \
    Beaglebone_Black/beaglebone.cpp \
    Beaglebone_Black/bbb_dht_read.c \
    Beaglebone_Black/bbb_mmio.c \
    Beaglebone_Black/bbb_dht_read.cpp \
    Beaglebone_Black/bbb_mmio.cpp

HEADERS  += mainwindow.h \
    time.h \
    Beaglebone_Black/bbb_dht_read.h \
    Beaglebone_Black/bbb_mmio.h \
    ledrgb.h

FORMS    += mainwindow.ui
