#ifndef WINDIALOGUE_H
#define WINDIALOGUE_H

#include <QDialog>

namespace Ui {
class WinDialogue;
}

class WinDialogue : public QDialog
{
    Q_OBJECT
signals:
    void goToMenuCalled();

public:
    explicit WinDialogue(const unsigned int i, QWidget *parent = 0);
    ~WinDialogue();

private slots:
    void on_pushButton_clicked();

private:
    Ui::WinDialogue *ui;
};

#endif // WINDIALOGUE_H
