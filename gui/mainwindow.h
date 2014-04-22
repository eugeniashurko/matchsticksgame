#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDebug>
#include <QJsonParseError>
#include <QJsonObject>
#include <list>

#include "mainmenu.h"
#include "howtoplaywidget.h"
#include "newgamewidget.h"
#include "loadgamewidget.h"
#include "gameplaywidget.h"
#include "../logic/save.h"
#include "../logic/game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initialize();
    void switchWidgetTo(QWidget* w);
    void loadSaves(const QString &file_name);
    void writeSavesToFile(const QString &file_name);

private slots:
    void on_howToPlayFromMenu();
    void on_newGameCalled();
    void on_loadGameFromMenu();
    void on_startGame(Game*);

    void on_toMainMenuButton_clicked();

    void on_saveButton_clicked();

signals:
    void gameInitialized(std::string);

private:
    Ui::MainWindow *ui;
    QWidget * _current_widget;
    Game * _current_game;
    std::list<Game> _games;
    std::list<Save> _saves;
};

#endif // MAINWINDOW_H
