QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = udp_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

INCLUDEPATH = \
            details

SOURCES += main.cpp \
    cmanager.cpp \
    cshell.cpp \
    details/cudp.cpp


HEADERS += \
    cshell.h \
    cmanager.h \
    details/cstatus.hpp \
    details/cudp.h \
    details/udpmanager.hpp \
    details/cooperator.hpp \
    details/ifilemock.h \
    details/ifilereader.h \
    details/icooperator.h \
    details/bufferholder.hpp \
    details/iudpmanager.h


