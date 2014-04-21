#ifndef NEWGAMEWIDGET_H
#define NEWGAMEWIDGET_H

#include <QWidget>
#include "game.h"

namespace Ui {
class NewGameWidget;
}

class NewGameWidget : public QWidget
{
    Q_OBJECT

public:
    explicit NewGameWidget(QWidget *parent = 0);
    ~NewGameWidget();

signals:
    void startGameCalled(Game* g);

private slots:
    void on_startGameButton_clicked();

private:
    Ui::NewGameWidget *ui;
};

#endif // NEWGAMEWIDGET_H
