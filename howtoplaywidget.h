#ifndef HOWTOPLAYWIDGET_H
#define HOWTOPLAYWIDGET_H

#include <QWidget>

namespace Ui {
class HowToPlayWidget;
}

class HowToPlayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HowToPlayWidget(QWidget *parent = 0);
    ~HowToPlayWidget();

private:
    Ui::HowToPlayWidget *ui;
};

#endif // HOWTOPLAYWIDGET_H
