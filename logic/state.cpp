#include "state.h"


State::State(const unsigned int b1,
             const unsigned int s,
             const Player p,
             const unsigned int l):
    _first_ballot(b1),
    _second_ballot(s),
    _last_player(p),
    _last_move(l)
{
    return;
}

State::State(const State& s):
    _first_ballot(s._first_ballot),
    _second_ballot(s._second_ballot),
    _last_player(s._last_player),
    _last_move(s._last_move)
{
    return;
}

State& State::operator=(const State& s) {
    if (this != &s) {
        _first_ballot = s._first_ballot;
        _second_ballot = s._second_ballot;
        _last_player = s._last_player;
        _last_move = s._last_move;
    }
    return *this;
}
