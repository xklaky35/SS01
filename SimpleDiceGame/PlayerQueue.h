#ifndef PLAYERQUEUE_H
#define PLAYERQUEUE_H

#include "Player.h"

class PlayerQueue {
public:
    // variables
    Player* firstPlayer;
    Player* lastPlayer;

    // *structor
    PlayerQueue();
    ~PlayerQueue();

    // methods
    void rotate();
    void enqueue(Player* p);
    Player* dequeue();
    bool is_empty() const;
    int get_size() const;
    Player* find_first_player_of_type(Player::PLAYER_TYPE) const;

private:
    int size;
};


#endif
