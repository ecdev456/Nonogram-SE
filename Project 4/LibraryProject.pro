#-------------------------------------------------
#
# Project created by QtCreator 2018-02-25T22:14:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
#
#LIBS += "C:\Users\Vero\Documents\build-LibraryProject-Desktop_Qt_5_10_0_MSVC2013_64bit-Debug\debug\timeLib.lib"
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    checkout.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    checkout.h \
    mainwindow.h \
    Model.h

FORMS += \
    checkout.ui \
    mainwindow.ui
