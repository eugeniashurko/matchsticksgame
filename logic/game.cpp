#include "game.h"

Save* Game::createMemento(QDateTime dt) {
    return new Save(this, dt);
}

void Game::setMemento(Save* m) {
    _state = m->getGame()->_state; _name = m->getGameName();
}
