#-------------------------------------------------
#
# Project created by QtCreator 2012-10-27T09:23:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oipmsg
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/config.cpp \
    src/log.cpp \
    src/systray.cpp \
    src/protocol.cpp \
    src/comm.cpp \
    src/version.cpp \
    src/whiteboard.cpp

HEADERS  += src/mainwindow.h \
    src/config.h \
    src/log.h \
    src/systray.h \
    src/protocol.h \
    src/comm.h \
    src/version.h \
    src/whiteboard.h

FORMS    += src/mainwindow.ui
