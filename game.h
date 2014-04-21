#ifndef GAME_H
#define GAME_H

#include <string>
#include <QString>
#include <QDateTime>
#include <QDebug>
#include "state.h"
#include "save.h"

class GamePlayWidget;
class Save;
class Game
{
// this class handles gameplay
friend class GamePlayWidget;

public:
    Game(): _name("No name"), _state(State()) {}
    Game(QString name): _name(name), _state(State()) {}
    Game(QString name, State& s): _name(name), _state(s) {}
    Game(const Game& g): _name(g._name), _state(g._state) {}
    ~Game() {}

    const QString getName() const { return _name; }
    void setName(const QString& n) { _name = n;}

    Save* createMemento(QDateTime dt = QDateTime::currentDateTime());
    void setMemento(Save* m);

private:
    QString _name;
    State _state;
};

#endif // GAME_H
