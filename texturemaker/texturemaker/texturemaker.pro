#-------------------------------------------------
#
# Project created by QtCreator 2013-10-24T12:49:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = texturemaker
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editareaframe.cpp \
    addblockbutton.cpp

HEADERS  += mainwindow.h \
    editareaframe.h \
    ../../sources/proctextures.h \
    ../../sources/ptdesigner.h \
    addblockbutton.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../../sources

INCLUDEPATH += $$PWD/../../sources
DEPENDPATH += $$PWD/../../sources

LIBS += -L$$PWD/../../lib/win32/ -lptdesigner

INCLUDEPATH += $$PWD/../../sources
DEPENDPATH += $$PWD/../../sources

RESOURCES += \
    resources.qrc
