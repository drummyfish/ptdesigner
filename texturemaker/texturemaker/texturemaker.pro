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
    colorbufferdisplay.cpp \
    defaultblockdialog.cpp \
    previewdialog.cpp \
    colorfilldialog.cpp \
    lightdialog.cpp

HEADERS  += mainwindow.h \
    editareaframe.h \
    ../../sources/proctextures.h \
    ../../sources/ptdesigner.h \
    addblockbutton.h \
    ../../sources/general.h \
    colorbufferdisplay.h \
    defaultblockdialog.h \
    previewdialog.h \
    colorfilldialog.h \
    lightdialog.h

FORMS    += mainwindow.ui \
    defaultblockdialog.ui \
    previewdialog.ui \
    colorfilldialog.ui \
    lightdialog.ui

INCLUDEPATH += $$PWD/../../sources

DEPENDPATH += $$PWD/../../sources

win32:LIBS += -L$$PWD/../../lib/win32/ -lptdesigner
!win32:LIBS += -L$$PWD/../../lib/linux64/ -lptdesigner

LIBS += -lm

RESOURCES += \
    resources.qrc
