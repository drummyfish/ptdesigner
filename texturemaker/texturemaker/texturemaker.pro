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
    addblockbutton.cpp \
    colorbufferdisplay.cpp

HEADERS  += mainwindow.h \
    editareaframe.h \
    ../../sources/proctextures.h \
    ../../sources/ptdesigner.h \
    addblockbutton.h \
    ../../sources/general.h \
    colorbufferdisplay.h

FORMS    += mainwindow.ui

INCLUDEPATH += $$PWD/../../sources

DEPENDPATH += $$PWD/../../sources

win32:LIBS += -L$$PWD/../../lib/win32/ -lptdesigner
!win32:LIBS += -L$$PWD/../../lib/linux64/ -lptdesigner

DEPENDPATH += $$PWD/../../sources

RESOURCES += \
    resources.qrc
