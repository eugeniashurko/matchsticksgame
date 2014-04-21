#ifndef STATE_H
#define STATE_H

enum Player {NONE, COMP, USER};

const unsigned int DEF1 = 110;
const unsigned int DEF2 = 83;

class State
{
public:
    State(const unsigned int f=DEF1, const unsigned int s=DEF2, const Player p=NONE,
          const unsigned int l=0);
    State(const State&);

    State& operator=(const State&);

    unsigned int getFirstBallot() const {return _first_ballot;}
    unsigned int getSecondBallot() const {return _second_ballot;}
    Player getLastPlayer() const {return _last_player;}
    unsigned int getLastMove() const {return _last_move;}

    void setFirstBallot(const unsigned int b) {_first_ballot=b;}
    void setSecondBallot(const unsigned int b) {_second_ballot=b;}
    void setLastPlayer(const Player p) {_last_player=p;}
    void setLastMove(const unsigned int m) {_last_move=m;}


private:
    unsigned int _first_ballot;
    unsigned int _second_ballot;

    Player _last_player;
    unsigned int _last_move;
};

#endif // STATE_H
