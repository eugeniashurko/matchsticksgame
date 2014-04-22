#ifndef SAVE_H
#define SAVE_H

#include <QDateTime>
#include "game.h"

class Game;
class Save
{
friend class Game;
private:
    // private constructor (only originator can create an object)
    Save(Game* g, QDateTime dt=QDateTime::currentDateTime());

    const Game* getGame() const;

    Game * _game;
    QDateTime _dt;
public:
    virtual ~Save();

    // narrow interface
    bool operator<(const Save&) const;
    const QDateTime& getDateTime() const { return _dt; }
    const QString getGameName() const;

};


#endif // SAVE_H
