#-------------------------------------------------
#
# Project created by QtCreator 2017-10-24T01:08:13
#
#-------------------------------------------------

QT       += core gui sql
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = xiangmu
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    keyboard.cpp \
    zhuce.cpp \
    shexiang.cpp \
    qcustomplot.cpp

HEADERS  += widget.h \
    keyboard.h \
    zhuce.h \
    shexiang.h \
    qcustomplot.h

FORMS    += widget.ui \
    keyboard.ui \
    zhuce.ui \
    shexiang.ui

RESOURCES += \
    picture.qrc
