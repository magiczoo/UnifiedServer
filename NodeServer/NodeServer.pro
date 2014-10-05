TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()


INCLUDEPATH += $$PWD/../libevent-include
DEPENDPATH += $$PWD/../libevent-include


unix|win32: LIBS += -levent

unix|win32: LIBS += -levent_core

unix|win32: LIBS += -levent_extra

unix|win32: LIBS += -levent_pthreads
