#include "newgamewidget.h"
#include "ui_newgamewidget.h"

NewGameWidget::NewGameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewGameWidget)
{
    ui->setupUi(this);
}

NewGameWidget::~NewGameWidget()
{
    delete ui;
}

void NewGameWidget::on_startGameButton_clicked()
{
    QString name = ui->nameInput->text();
    Game * game = new Game(name);
    emit startGameCalled(game);
}
