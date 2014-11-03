#-------------------------------------------------
#
# Project created by QtCreator 2014-11-01T12:20:11
#
#-------------------------------------------------

QT       -= core gui

TARGET = MagicZooCore
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11
SOURCES += MagicZooCore.cpp \
    utils/ByteArray.cpp \
    network/NetDefinedObject.cpp \
    network/NetDefinedObjectProperty.cpp \
    network/NetObjectProtocol.cpp \
    network/NetObjectXmlExport.cpp \
    network/NetObjectJsExport.cpp \
    network/NetObjectCppExport.cpp \
    network/NetObjectLuaExport.cpp \
    network/NetObjectBase.cpp \
    network/NetScriptObjectBase.cpp

HEADERS += MagicZooCore.h \
    utils/ByteArray.h \
    network/NetDefinedObject.h \
    network/NetDefinedObjectProperty.h \
    network/NetObjectProtocol.h \
    network/INetObjectCodeExport.h \
    network/NetObjectXmlExport.h \
    network/NetObjectJsExport.h \
    network/NetObjectCppExport.h \
    network/NetObjectLuaExport.h \
    network/NetObjectBase.h \
    network/NetScriptObjectBase.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
