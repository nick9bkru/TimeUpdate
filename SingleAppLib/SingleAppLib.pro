#-------------------------------------------------
#
# Project created by QtCreator 2016-05-20T11:41:33
#
#-------------------------------------------------

QT       += network core

QT       -= gui

TARGET = SingleApplication
TEMPLATE = lib

DEFINES += SINGLEAPPLICATION_LIBRARY



greaterThan ( QT_VERSION, 4.4 ) {
  #DEFINES += QT42
  message("QT Version == " $$QT_VERSION )
  message( "Compile Library Singl App")

  HEADERS += \
    include/OneCopyStart.h \
    include/qtlocalpeer.h \
    include/qtlockedfile.h \
    include/qtsingleapplication.h \
    include/qtsinglecoreapplication.h

  SOURCES += \
    src/OneCopyStart.cpp\
    src/qtlocalpeer.cpp \
    src/qtlockedfile.cpp \
    src/qtlockedfile_unix.cpp \
    src/qtlockedfile_win.cpp \
    src/qtsingleapplication.cpp \
    src/qtsinglecoreapplication.cpp
}
unix {
    target.path = /usr/lib
    INSTALLS += target
}

