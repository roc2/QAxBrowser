#-------------------------------------------------
#
# Project created by QtCreator 2018-12-11T16:36:16
#
#-------------------------------------------------

QT       += core gui axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QAxBrowser
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        QAxBrowser.cpp

HEADERS  += QAxBrowser.h

FORMS    += QAxBrowser.ui

#TYPELIBS = $$system(dumpcpp -getfile {8856F961-340A-11D0-A96B-00C04FD705A2})

#isEmpty(TYPELIBS) {
#    message("Microsoft ie type library not found!")
#    REQUIRES += Outlook
#}
# else {
#    HEADERS  = addressview.h
#    SOURCES  = addressview.cpp main.cpp
#}
