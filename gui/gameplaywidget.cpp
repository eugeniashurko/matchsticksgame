#include "gameplaywidget.h"
#include "ui_gameplaywidget.h"

GamePlayWidget::GamePlayWidget(Game * g, QWidget *parent) :
    _game(g),
    ui(new Ui::GamePlayWidget), QWidget(parent)
{
    ui->setupUi(this);
    ui->nameLabel->setText(_game->getName());
    configureGame();
}

GamePlayWidget::~GamePlayWidget()
{
    delete ui;
}


void GamePlayWidget::configureGame() {
    ui->invalidInputLabel->close();
    ui->inFirstBallot->setText(QString::number(_game->_state.getFirstBallot()));
    ui->inSecondBallot->setText(QString::number(_game->_state.getSecondBallot()));
    QString last_player;
    if (_game->_state.getLastPlayer() == USER) {
        last_player = "The last player User made a move in ";
    } else if (_game->_state.getLastPlayer() == COMP) {
        last_player = "The last player Computer made a move in ";
    } else {
        last_player = "This is the first move and it is yours";
    }
    QString last_move;
    if (_game->_state.getLastMove() != 0) {
        last_move = QString::number(_game->_state.getLastMove());
    } else {
        last_move = "";
    }
    ui->lastMoveLog->setText(last_player+last_move);
    if (_game->_state.getFirstBallot() > _game->_state.getSecondBallot()) {
        ui->inFirstBallot->setStyleSheet("color:red;font-size:30px;");
        ui->inSecondBallot->setStyleSheet("font-size:30px;");
    } else {
         ui->inSecondBallot->setStyleSheet("color:red;font-size:30px;");
         ui->inFirstBallot->setStyleSheet("font-size:30px;");
    }
}

void GamePlayWidget::makeCompMove() {
    if (_game->_state.getLastPlayer() == USER) {
        unsigned int active = 0;
        unsigned int passive = 1;
        if (_game->_state.getFirstBallot() < _game->_state.getSecondBallot()) {
            active = 1;
            passive = 0;
        }
        unsigned int ballots[2] = {_game->_state.getFirstBallot(), _game->_state.getSecondBallot()};
        unsigned int move;
        if (ballots[passive] == 1) {
            move = ballots[active];
        } else  {
            move = ballots[passive];
        }
        if (ballots[active] - move > 0) {
            ballots[active] = ballots[active] - move;
            _game->_state.setFirstBallot(ballots[0]);
            _game->_state.setSecondBallot(ballots[1]);
            _game->_state.setLastMove(move);
            _game->_state.setLastPlayer(COMP);
            configureGame();
        } else {
            ballots[active] = 0;
            _game->_state.setFirstBallot(ballots[0]);
            _game->_state.setSecondBallot(ballots[1]);
            _game->_state.setLastMove(move);
            _game->_state.setLastPlayer(COMP);

            WinDialogue * d = new WinDialogue(1);
            connect(d, SIGNAL(goToMenuCalled()), this, SIGNAL(goToMenuCalled()));
            d->show();
        }
    } else {
        return;
    }
}

void GamePlayWidget::makeUserMove(const unsigned int move) {
    unsigned int active = 0;
    unsigned int passive = 1;
    if (_game->_state.getFirstBallot() < _game->_state.getSecondBallot()) {
        active = 1;
        passive = 0;
    }
    unsigned int ballots[2] = {_game->_state.getFirstBallot(), _game->_state.getSecondBallot()};
    if (ballots[active] - move > 0) {
        ballots[active] -= move;

        _game->_state.setFirstBallot(ballots[0]);
        _game->_state.setSecondBallot(ballots[1]);
        _game->_state.setLastMove(move);
        _game->_state.setLastPlayer(USER);

        makeCompMove();
        configureGame();

    } else {
        ballots[active] = 0;
        _game->_state.setFirstBallot(ballots[0]);
        _game->_state.setSecondBallot(ballots[1]);
        _game->_state.setLastMove(move);
        _game->_state.setLastPlayer(USER);


        WinDialogue * d = new WinDialogue(0);
        connect(d, SIGNAL(goToMenuCalled()), this, SIGNAL(goToMenuCalled()));
        d->show();
    }
}

void GamePlayWidget::on_makeMoveButton_clicked()
{
    bool ok;
    unsigned int move = ui->numberInput->text().toUInt(&ok);
    unsigned int active = 0;
    unsigned int passive = 1;
    if (_game->_state.getFirstBallot() < _game->_state.getSecondBallot()) {
        active = 1;
        passive = 0;
    }
    unsigned int ballots[2] = {_game->_state.getFirstBallot(), _game->_state.getSecondBallot()};
    if (!ok) {
        ui->invalidInputLabel->show();
    } else {
        if (move % ballots[passive] != 0) {
            ui->invalidInputLabel->show();
        } else {
            ui->invalidInputLabel->close();
            if (_game->_state.getLastPlayer() != USER) {
                 makeUserMove(move);
            } else {
                makeCompMove();
            }
        }
    }

}
