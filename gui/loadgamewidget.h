#ifndef LOADGAMEWIDGET_H
#define LOADGAMEWIDGET_H

#include <QWidget>
#include "../logic/save.h"

#include <QPushButton>
#include <QDebug>
#include <QSignalMapper>

namespace Ui {
class LoadGameWidget;
}

class LoadGameWidget : public QWidget
{
    Q_OBJECT
private slots:
   void on_gameLoaded(const QString&);

public:
    explicit LoadGameWidget(std::list<Save>*, QWidget *parent = 0);
    ~LoadGameWidget();


signals:
    void clicked(const QString&);
    void gameToLoadCalled(Game*);

private:
    Ui::LoadGameWidget *ui;
    std::list<Save> *_saves;
    QSignalMapper * signalMapper;
};

#endif // LOADGAMEWIDGET_H
