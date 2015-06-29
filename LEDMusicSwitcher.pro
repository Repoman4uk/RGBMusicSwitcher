#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T23:00:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LEDMusicSwitcher
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    trackbar.cpp \
    light.cpp

HEADERS  += mainwindow.h \
    trackbar.h \
    light.h \
    oneLight.h

FORMS    += mainwindow.ui
