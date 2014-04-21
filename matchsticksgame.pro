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
        mainwindow.cpp \
    mainmenu.cpp \
    howtoplaywidget.cpp \
    newgamewidget.cpp \
    loadgamewidget.cpp \
    gameplaywidget.cpp \
    game.cpp \
    state.cpp \
    save.cpp \
    windialogue.cpp \
    gamememento.cpp

HEADERS  += mainwindow.h \
    mainmenu.h \
    howtoplaywidget.h \
    newgamewidget.h \
    loadgamewidget.h \
    gameplaywidget.h \
    game.h \
    state.h \
    save.h \
    windialogue.h \
    gamememento.h

FORMS    += mainwindow.ui \
    mainmenu.ui \
    howtoplaywidget.ui \
    newgamewidget.ui \
    loadgamewidget.ui \
    gameplaywidget.ui \
    windialogue.ui
