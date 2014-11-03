#-------------------------------------------------
#
# Project created by QtCreator 2014-11-01T12:23:03
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

#TARGET = tst_magiczoocoretest
TARGET=test_ByteArray
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_magiczoocoretest.cpp \
    tst_ByteArray.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/release/ -lMagicZooCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/debug/ -lMagicZooCore
else:unix: LIBS += -L$$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/ -lMagicZooCore

INCLUDEPATH += $$PWD/../MagicZooCore
DEPENDPATH += $$PWD/../MagicZooCore

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/release/libMagicZooCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/debug/libMagicZooCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/release/MagicZooCore.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/debug/MagicZooCore.lib
else:unix: PRE_TARGETDEPS += $$PWD/../build-MagicZooCore-Desktop_Qt_5_3_GCC_64bit-Debug/libMagicZooCore.a
