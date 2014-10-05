#-------------------------------------------------
#
# Project created by QtCreator 2014-10-04T16:31:28
#
#-------------------------------------------------

QT       -= core gui

TARGET = magiczoo
TEMPLATE = lib

DEFINES += MAGICZOO_LIBRARY

SOURCES += magiczoo.cpp

HEADERS += magiczoo.h\
        magiczoo_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
