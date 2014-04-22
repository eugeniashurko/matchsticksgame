#include "loadgamewidget.h"
#include "ui_loadgamewidget.h"

LoadGameWidget::LoadGameWidget(std::list<Save>* s, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadGameWidget),
    _saves(s)
{
    ui->setupUi(this);
    signalMapper = new QSignalMapper(this);
    connect(this, SIGNAL(clicked(const QString&)), this, SLOT(on_gameLoaded(const QString&)));
    if (s != 0 && s->size() > 0) {
        ui->noSavesLabel->close();
        _saves->sort();
        int j = 0;

        for(std::list<Save>::iterator i =_saves->begin(); i != _saves->end(); ++i) {
            ui->savesLayout->addWidget(new QLabel(i->getGameName() +
                                                  QString("      ") +
                                                  i->getDateTime().toString()), j, 0);

            QPushButton * button = new QPushButton("Load");
            connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
            signalMapper->setMapping(button, i->getDateTime().toString());
            ui->savesLayout->addWidget(button, j, 1);
            j++;
        }
        connect(signalMapper, SIGNAL(mapped(const QString&)),
                this, SIGNAL(clicked(const QString&)));
    }

}

LoadGameWidget::~LoadGameWidget()
{
    delete ui;
}


void LoadGameWidget::on_gameLoaded(const QString& dt) {
    QDateTime save_dt = QDateTime::fromString(dt);
    Game * current_game = new Game();
    // find save with this datetime
    for(std::list<Save>::iterator i =_saves->begin(); i != _saves->end(); ++i) {
        if (i->getDateTime().toTime_t() == save_dt.toTime_t()) {
            current_game->setName(i->getGameName());
            current_game->setMemento(&*i);
            break;
        }
    }
    emit gameToLoadCalled(current_game);
}
