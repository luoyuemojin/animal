#-------------------------------------------------
#
# Project created by QtCreator 2019-06-12T11:37:01
#
#-------------------------------------------------

QT       += core gui
QT += sql
QT+= serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = feedDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    feedsql.cpp \
    jiezhongform.cpp \
    serialrfid.cpp \
    yimiaoform.cpp \
    chuankouform.cpp \
    chakanform.cpp \
    weightform.cpp \
    jishuform.cpp \
    register.cpp

HEADERS  += mainwindow.h \
    datastruct.h \
    jiezhongform.h \
    serialrfid.h \
    yimiaoform.h \
    chuankouform.h \
    chakanform.h \
    weightform.h \
    jishuform.h \
    winesql.h \
    register.h

FORMS    += mainwindow.ui \
    jiezhongform.ui \
    yimiaoform.ui \
    chuankouform.ui \
    chakanform.ui \
    weightform.ui \
    jishuform.ui \
    register.ui

unix|win32: LIBS += -L$$PWD/ -lReadDLL

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

RESOURCES += \
    img.qrc \
    img.qrc
