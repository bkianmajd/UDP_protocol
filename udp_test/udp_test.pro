QT += core
QT -= gui
QT += network

CONFIG += c++11

TARGET = udp_test
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += \
    qudp.hpp \
    buffercommands.hpp \
    shelldiag.hpp
