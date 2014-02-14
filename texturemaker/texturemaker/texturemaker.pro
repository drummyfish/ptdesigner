#-------------------------------------------------
#
# Project created by QtCreator 2013-10-24T12:49:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = texturemaker
TEMPLATE = app

RC_FILE = res.rc

SOURCES += main.cpp\
        mainwindow.cpp \
    editareaframe.cpp \
    addblockbutton.cpp \
    colorbufferdisplay.cpp \
    defaultblockdialog.cpp \
    previewdialog.cpp \
    colorfilldialog.cpp \
    lightdialog.cpp \
    voronoidialog.cpp \
    pointeditframe.cpp \
    perlindialog.cpp \
    convolutiondialog.cpp \
    customblockdialog.cpp \
    aboutdialog.cpp \
    mixdialog.cpp \
    saveloaddialog.cpp \
    lsystemdialog.cpp \
    colortransitiondialog.cpp \
    transitionpreviewframe.cpp \
    blurdialog.cpp \
    colorreplacedialog.cpp \
    mosaicdialog.cpp \
    mosaicsideeditframe.cpp \
    edgedetectiondialog.cpp \
    ditherdialog.cpp \
    cellulargeneraldialog.cpp \
    cellulardialog.cpp \
    substratedialog.cpp

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
    lightdialog.h \
    voronoidialog.h \
    pointeditframe.h \
    perlindialog.h \
    convolutiondialog.h \
    customblockdialog.h \
    aboutdialog.h \
    mixdialog.h \
    saveloaddialog.h \
    lsystemdialog.h \
    colortransitiondialog.h \
    transitionpreviewframe.h \
    blurdialog.h \
    colorreplacedialog.h \
    mosaicdialog.h \
    mosaicsideeditframe.h \
    edgedetectiondialog.h \
    ditherdialog.h \
    cellulargeneraldialog.h \
    cellulardialog.h \
    substratedialog.h

FORMS    += mainwindow.ui \
    defaultblockdialog.ui \
    previewdialog.ui \
    colorfilldialog.ui \
    lightdialog.ui \
    voronoidialog.ui \
    perlindialog.ui \
    convolutiondialog.ui \
    aboutdialog.ui \
    mixdialog.ui \
    saveloaddialog.ui \
    lsystemdialog.ui \
    colortransitiondialog.ui \
    blurdialog.ui \
    colorreplacedialog.ui \
    mosaicdialog.ui \
    edgedetectiondialog.ui \
    ditherdialog.ui \
    cellulargeneraldialog.ui \
    cellulardialog.ui \
    substratedialog.ui

INCLUDEPATH += $$PWD/../../sources

DEPENDPATH += $$PWD/../../sources

win32:LIBS += -L$$PWD/../../lib/win32/ -lptdesigner
!win32:LIBS += -L$$PWD/../../lib/linux64/ -lptdesigner

LIBS += -lm

RESOURCES += \
    resources.qrc
