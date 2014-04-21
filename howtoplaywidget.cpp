#include "howtoplaywidget.h"
#include "ui_howtoplaywidget.h"

HowToPlayWidget::HowToPlayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HowToPlayWidget)
{
    ui->setupUi(this);
}

HowToPlayWidget::~HowToPlayWidget()
{
    delete ui;
}
