#ifndef GAMEPLAYWIDGET_H
#define GAMEPLAYWIDGET_H

#include <QWidget>
#include <QDebug>
#include "../logic/game.h"
#include "windialogue.h"


namespace Ui {
class GamePlayWidget;
}

class GamePlayWidget : public QWidget
{
    Q_OBJECT
signals:
    void goToMenuCalled();

public:
    explicit GamePlayWidget(Game * g, QWidget *parent = 0);
    ~GamePlayWidget();

private slots:
    void on_makeMoveButton_clicked();

private:
    Game * _game;
    Ui::GamePlayWidget *ui;
    void configureGame();
    void makeCompMove();
    void makeUserMove(const unsigned int move);

};

#endif // GAMEPLAYWIDGET_H
