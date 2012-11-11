#-------------------------------------------------
#
# Project created by QtCreator 2012-10-27T09:23:36
#
#-------------------------------------------------

QT       += core gui network translation

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oipmsg
TEMPLATE = app


SOURCES += src/main.cpp\
    src/config.cpp \
    src/log.cpp \
    src/systray.cpp \
    src/protocol.cpp \
    src/version.cpp \
    src/whiteboard.cpp \
    src/main_window.cpp \
    src/setup_window.cpp \
    src/about_dialog.cpp \
    src/init.cpp \
    src/screenshot.cpp \
    src/oipmsg.cpp \
    src/tcpcomm.cpp \
    src/udpserver.cpp \
    src/udpclient.cpp \
    src/encrypt.cpp \
    src/host.cpp

HEADERS  += \
    src/config.h \
    src/log.h \
    src/systray.h \
    src/protocol.h \
    src/version.h \
    src/whiteboard.h \
    src/main_window.h \
    src/about_dialog.h \
    src/setup_window.h \
    src/ipmsg.h \
    src/init.h \
    src/screenshot.h \
    src/oipmsg.h \
    src/tcpcomm.h \
    src/udpserver.h \
    src/udpclient.h \
    src/ipmsgcmn.h \
    src/encrypt.h \
    src/host.h

FORMS    += \
    src/about_dialog.ui \
    src/main_window.ui \
    src/setup_window.ui
