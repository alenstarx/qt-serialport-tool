#-------------------------------------------------
#
# Project created by QtCreator 2014-04-12T12:07:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

TARGET = serialport
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -D_GLIBCXX_USE_CXX11_ABI

include(./qextserialport/qextserialport.pri)

INCLUDEPATH += src ./ include/
SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/qled.cpp \
    src/setupdialog.cpp \
    src/execdialog.cpp \
    src/mdialog.cpp \
    src/aerobutton/aerobutton.cpp \
    src/helper.cpp \
    src/messagebox.cpp \
    src/tcpserver.cpp \
    src/tcpclient.cpp \
    src/sessionlistmodel.cpp

HEADERS  += src/mainwindow.h \
    src/qled.h \
    src/setupdialog.h \
    src/execdialog.h \
    src/mdialog.h \
    src/aerobutton/aerobutton.h \
    src/helper.h \
    src/messagebox.h \
    src/tcpserver.h \
    src/tcpclient.h \
    src/sessionlistmodel.h

FORMS    += ui/mainwindow.ui \
    ui/setupdialog.ui \
    ui/execdialog.ui

RESOURCES += \
    res/mainwindow.qrc
