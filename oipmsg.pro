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
    src/config.cpp \
    src/log.cpp \
    src/systray.cpp \
    src/protocol.cpp \
    src/comm.cpp \
    src/version.cpp \
    src/whiteboard.cpp \
    src/main_window.cpp \
    src/setup_window.cpp \
    src/about_dialog.cpp

HEADERS  += \
    src/config.h \
    src/log.h \
    src/systray.h \
    src/protocol.h \
    src/comm.h \
    src/version.h \
    src/whiteboard.h \
    src/main_window.h \
    src/about_dialog.h \
    src/setup_window.h \
    src/ipmsg.h

FORMS    += \
    src/about_dialog.ui \
    src/main_window.ui \
    src/setup_window.ui
