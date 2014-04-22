#-------------------------------------------------
#
# Project created by QtCreator 2014-04-06T18:05:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = matchsticksgame
TEMPLATE = app


SOURCES += main.cpp\
        gui/mainwindow.cpp \
    gui/mainmenu.cpp \
    gui/howtoplaywidget.cpp \
    gui/newgamewidget.cpp \
    gui/loadgamewidget.cpp \
    gui/gameplaywidget.cpp \
    logic/game.cpp \
    logic/state.cpp \
    logic/save.cpp \
    gui/windialogue.cpp \
    logic/gamememento.cpp

HEADERS  += gui/mainwindow.h \
    gui/mainmenu.h \
    gui/howtoplaywidget.h \
    gui/newgamewidget.h \
    gui/loadgamewidget.h \
    gui/gameplaywidget.h \
    logic/game.h \
    logic/state.h \
    logic/save.h \
    gui/windialogue.h \
    logic/gamememento.h

FORMS    +=  gui/mainwindow.ui \
     gui/mainmenu.ui \
     gui/howtoplaywidget.ui \
     gui/newgamewidget.ui \
     gui/loadgamewidget.ui \
     gui/gameplaywidget.ui \
     gui/windialogue.ui
