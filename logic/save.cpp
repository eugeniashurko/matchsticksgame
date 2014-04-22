#include "save.h"

Save::Save(Game* g, QDateTime dt): _game(g), _dt(dt)
{
    return;
}

Save::~Save() {}

bool Save::operator<(const Save& s) const
{ return _dt > s.getDateTime(); }

const QString Save::getGameName() const {
    return _game->getName(); }

const Game* Save::getGame() const {
    return _game;
}
