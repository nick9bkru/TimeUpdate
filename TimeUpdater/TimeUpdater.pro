#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T10:37:10
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeUpdater
TEMPLATE = app


SOURCES += main.cpp\
        MainWidjet.cpp \
    TimeDateEdit.cpp \
    UdpClient.cpp \
    ServersIp.cpp \
    ResFrame.cpp \
    OneCopyStart.cpp

HEADERS  += MainWidjet.h \
    TimeDateEdit.h \
    UdpClient.h \
    ServersIp.h \
    Singleton.h \
    ResFrame.h \
    OneCopyStart.h

FORMS    += MainWidjet.ui \
    TimeDateEdit.ui \
    ResFrame.ui
