#ifndef PLAYERQUEUE_H
#define PLAYERQUEUE_H

#include "Player.h"

class PlayerQueue {
public:
    PlayerQueue();

    void enqueue(Player* p);
    void rotate();
    Player* dequeue();

    bool is_empty() const;
    int get_size() const;

    Player* firstPlayer;
    Player* lastPlayer;

private:
    int size;
};


#endif
