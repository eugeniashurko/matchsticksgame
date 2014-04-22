#ifndef GAMEMEMENTO_H
#define GAMEMEMENTO_H

#include <QString>
#include <QDateTime>

#include "state.h"

class Game;
class GameMemento
{
public:

    virtual ~GameMemento();

private:
    // originator friend class
    friend class Game;
    // private constructor (only originator can create an object)
    GameMemento(Game * state) { _state = state; }

    Game * getSate() { return _state; }

    Game * _state;
    QDateTime _dt;
};

#endif // GAMEMEMENTO_H
