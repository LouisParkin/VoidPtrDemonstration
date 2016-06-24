#-------------------------------------------------
#
# Project created by QtCreator 2016-06-23T11:05:19
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VoidPtrExample
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myexamplebaseclass.cpp \
    myexamplederivedclassl1.cpp \
    myexamplederivedclassl2.cpp \
    myexamplederivedclassl3.cpp

HEADERS  += mainwindow.h \
    myexamplebaseclass.h \
    myexamplederivedclassl1.h \
    myexamplederivedclassl2.h \
    myexamplederivedclassl3.h

FORMS    += mainwindow.ui
