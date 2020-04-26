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
    zhuceform.cpp \
    chakanform.cpp \
    weightform.cpp \
    jishuform.cpp

HEADERS  += mainwindow.h \
    datastruct.h \
    feedsql.h \
    jiezhongform.h \
    serialrfid.h \
    yimiaoform.h \
    chuankouform.h \
    zhuceform.h \
    chakanform.h \
    weightform.h \
    jishuform.h

FORMS    += mainwindow.ui \
    jiezhongform.ui \
    yimiaoform.ui \
    chuankouform.ui \
    zhuceform.ui \
    chakanform.ui \
    weightform.ui \
    jishuform.ui

unix|win32: LIBS += -L$$PWD/ -lReadDLL

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

RESOURCES += \
    img.qrc \
    img.qrc
