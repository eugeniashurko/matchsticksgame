#include "windialogue.h"
#include "ui_windialogue.h"

WinDialogue::WinDialogue(const unsigned int i, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinDialogue)
{
    ui->setupUi(this);
    if (i == 0) {
        ui->userWonLabel->show();
        ui->compWonLabel->close();
    } else {
        ui->userWonLabel->close();
        ui->compWonLabel->show();
    }
}

WinDialogue::~WinDialogue()
{
    delete ui;
}

void WinDialogue::on_pushButton_clicked()
{
    this->close();
    emit goToMenuCalled();

}
