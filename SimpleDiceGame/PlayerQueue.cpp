#include "PlayerQueue.h"

#include <iostream>

PlayerQueue::PlayerQueue() {
    size = 0;
    firstPlayer = nullptr;
    lastPlayer = nullptr;
}

PlayerQueue::~PlayerQueue() {
    size = 0;
    firstPlayer = nullptr;
    lastPlayer = nullptr;
}

// puts the first player in the queue to last position
void PlayerQueue::rotate() {
    if (size == 0) {
        throw 404;
    }

    Player* player_to_rotate = dequeue();
    enqueue(player_to_rotate);
}

// add a player to the end of the queue
void PlayerQueue::enqueue(Player* p) {
    if (!is_empty()) {
        lastPlayer->follower = p;
        lastPlayer = p;
    }
    else {
        firstPlayer = p;
        lastPlayer = p;
    }
    size++;
}

// remove the first player from the queue and return it
Player *PlayerQueue::dequeue() {
    Player* oldFirstPlayer = firstPlayer;
    firstPlayer = oldFirstPlayer->follower;
    oldFirstPlayer->follower = nullptr;
    size--;
    return oldFirstPlayer;
}

// size getter
int PlayerQueue::get_size() const {
    return size;
}

Player * PlayerQueue::find_first_player_of_type(Player::PLAYER_TYPE) const {
    Player* current = firstPlayer;
    while (current != nullptr) {
        if (current->type == Player::AI) {
            return current;
        }
        current = current->follower;
    }
    return nullptr;
}

// returns true if the queue is empty, false otherwise
bool PlayerQueue::is_empty() const {
    return size == 0;
}
