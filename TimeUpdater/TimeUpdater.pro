#-------------------------------------------------
#
# Project created by QtCreator 2016-04-04T10:37:10
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TimeUpdater
TEMPLATE = app

lessThan ( QT_VERSION, 4.4 ) {
  DEFINES += QT42
  message("QT Version < " $$QT_PATCH_VERSION )
}

SOURCES += main.cpp\
        MainWidjet.cpp \
    TimeDateEdit.cpp \
    UdpClient.cpp \
    ServersIp.cpp \
    ResFrame.cpp


HEADERS  += MainWidjet.h \
    TimeDateEdit.h \
    UdpClient.h \
    ServersIp.h \
    Singleton.h \
    ResFrame.h 

FORMS    += MainWidjet.ui \
    TimeDateEdit.ui \
    ResFrame.ui

unix:!macx: LIBS += -L$$OUT_PWD/../SingleAppLib/ -lSingleApplication

unix:{
  QMAKE_RPATHDIR +=$$OUT_PWD/../SingleAppLib/
 #QMAKE_LFLAGS += -Wl,--rpath=$$OUT_PWD/../SingleAppLib/
}

INCLUDEPATH += $$PWD/../SingleAppLib
DEPENDPATH += $$PWD/../SingleAppLib
