#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString SAVES_FILE = "saves.json";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _current_widget(0),
    _current_game(0),
    _saves(std::list<Save>()),
    _games(std::list<Game>())
{
    ui->setupUi(this);
    initialize();
}

MainWindow::~MainWindow()
{
    if (_current_widget != 0) {
        delete _current_widget;
        _current_widget = 0;
    }

    if (_current_game != 0) {
        delete _current_game;
        _current_game = 0;
    }
    _saves.clear();
    _games.clear();

    delete ui;
}

void MainWindow::loadSaves(const QString& file_name) {
    // load saves from file
    QFile conf_file(file_name);
    if( ! conf_file.open( QIODevice::ReadOnly ))
    {
        qDebug() << "Cannot open configs!";
        return;
    }

    QByteArray json = conf_file.readAll();
    conf_file.close();

    QJsonParseError * err = new QJsonParseError;
    QJsonDocument doc = QJsonDocument::fromJson(json, err);

    if (err->error != 0) {
        qDebug() << err->errorString();
    }

    if (doc.isNull()) {
        qDebug() << "Invalid JSON-document 'config.json'";
    } else if (doc.isObject()) {
        QVariantMap result = doc.toVariant().toMap();
        QVariant rr = result["saves"];
        QVariantList ll = rr.toList();
        QString n;
        QDateTime d;
        QVariantMap state;
        unsigned int f,s,m;
        QString l;
        Player lp;
        State st;
        for (int i=0; i < ll.length(); i++) {
            n = ll[i].toMap()["name"].toString();
            d = ll[i].toMap()["datetime"].toDateTime();
            state = ll[i].toMap()["state"].toMap();
            f = state["first_ballot"].toUInt();
            s = state["second_ballot"].toUInt();
            l = state["last_player"].toString();
            if (l == "COMP") {
                lp = COMP;
            } else if (l == "USER") {
                lp = USER;
            } else {
                lp = NONE;
            }
            m = state["last_move"].toUInt();
            st = State(f, s, lp, m);
            _games.push_back(Game(n, st));
            _saves.push_back(*(_games.back().createMemento(d)));

        }
   }

}

void MainWindow::initialize() {

    if (_saves.size() == 0) {
        loadSaves(SAVES_FILE);
    }
    // initialize main menu and corresponding signals
    MainMenu * m = new MainMenu;
    connect(m, SIGNAL(newGameCalled()), this, SLOT(on_newGameCalled()));
    connect(m, SIGNAL(howToPlayCalled()), this, SLOT(on_howToPlayFromMenu()));
    connect(m, SIGNAL(loadGameCalled()), this, SLOT(on_loadGameFromMenu()));
    switchWidgetTo(m);
    ui->toMainMenuButton->close();
    ui->saveButton->close();
    return;
}

void MainWindow::switchWidgetTo(QWidget* w)
{
    if (_current_widget != 0) {
        delete _current_widget;
        _current_widget = 0;
    }
    _current_widget = w;
    ui->widgetsVerticalLayout->addWidget(w);
    return;
}

void MainWindow::on_howToPlayFromMenu() {
    ui->toMainMenuButton->show();
    HowToPlayWidget * w = new HowToPlayWidget;
    switchWidgetTo(w);
    return;
}

void MainWindow::on_newGameCalled() {
    ui->toMainMenuButton->show();
    NewGameWidget * w = new NewGameWidget;
    connect(w, SIGNAL(startGameCalled(Game*)), this, SLOT(on_startGame(Game*)));
    switchWidgetTo(w);
    return;
}

void MainWindow::on_loadGameFromMenu() {
    ui->toMainMenuButton->show();
    LoadGameWidget * w = new LoadGameWidget(&_saves);
    connect(w, SIGNAL(gameToLoadCalled(Game*)), this, SLOT(on_startGame(Game*)));
    switchWidgetTo(w);
    return;
}

void MainWindow::on_startGame(Game *game) {
    ui->toMainMenuButton->show();
    ui->saveButton->show();
    _current_game = game;
    GamePlayWidget * w = new GamePlayWidget(_current_game);
    connect(w, SIGNAL(goToMenuCalled()),this, SLOT(on_toMainMenuButton_clicked()));
    switchWidgetTo(w);
    return;
}


void MainWindow::on_toMainMenuButton_clicked()
{
    initialize();
}

void MainWindow::writeSavesToFile(const QString &file_name) {

}

void MainWindow::on_saveButton_clicked()
{
    if (_current_game != 0) {
        _games.push_back(*(_current_game));
        _saves.push_back(*(_current_game->createMemento()));
        _saves.sort();
        writeSavesToFile(SAVES_FILE);
    }
}
