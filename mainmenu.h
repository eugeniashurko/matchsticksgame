#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();

signals:
    void howToPlayCalled();
    void newGameCalled();
    void loadGameCalled();

private slots:
    void on_newGameButton_clicked();
    void on_loadGameButton_clicked();
    void on_howToPlayButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
