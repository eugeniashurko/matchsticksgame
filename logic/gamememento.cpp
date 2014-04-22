#include "gamememento.h"
GameMemento::~GameMemento() {
    delete _state;
    _state = 0;
}
