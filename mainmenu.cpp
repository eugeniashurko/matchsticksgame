#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_newGameButton_clicked()
{
    emit newGameCalled();
}

void MainMenu::on_loadGameButton_clicked()
{
    emit loadGameCalled();
}

void MainMenu::on_howToPlayButton_clicked()
{
    emit howToPlayCalled();
}
