#-------------------------------------------------
#
# Project created by QtCreator 2016-04-01T12:49:24
#
#-------------------------------------------------

QT       += core network

QT       -= gui

TARGET = TimeUpdateServ
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    UdpServ.cpp \
    ServManage.cpp

HEADERS += \
    UdpServ.h \
    ServManage.h
