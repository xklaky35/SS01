#include "Player.h"
#include <iostream>

int get_random_number(int,int);

Player::Player() {
    follower = nullptr;
    dice_count = 2;
    type = UNDEFINED;
    dice_results = new int[dice_count];
    id = -1;
}

Player::Player(const int p_id, const PLAYER_TYPE p_type, const int p_dice_count) {
    follower = nullptr;
    dice_count = p_dice_count;
    type = p_type;
    dice_results = new int[dice_count];
    id = p_id;
}

Player::~Player() {
    follower = nullptr;
    delete[] dice_results;
}

void Player::make_turn() const {
    // let player roll manually if the player is human
    if (type == HUMAN) {
        std::cout << "Player (id:" << id << ")! Roll your dice >" << std::endl;
        getchar();
    }
    else if (type == AI) {
        std::cout << "\nAI (id:" << id << ") is rolling..." << std::endl;
    }

    roll_dice();

    // hide result of AI to control winner
    if (type == HUMAN) {
        print_results();
    }

    // pass to next player
    if (follower != nullptr) {
        follower->make_turn();
    }
}

// display the current dice result on the screen
void Player::print_results() const {
    for (int i = 0; i < dice_count; i++) {
        printf("Player[%d]> Dice result %d: %d\n", id, i+1, dice_results[i]);
    }
}

// generate random numbers for each dice
void Player::roll_dice() const {
    // generate random numbers
    for (int i = 0; i < dice_count; i++) {
        dice_results[i] = get_random_number(1,6);
    }
}

// returns true if all dice are the same, false otherwise
bool Player::has_all_of_same_kind() const {
    if (dice_count <= 1) return false;

    for (int i = 0; i < dice_count; i++) {
        if (i+1 == dice_count) {
            break; // end is reached
        }

        if (dice_results[i] != dice_results[i+1]) {
            return false;
        }
    }
    return true;
}

// returns the sum of all dice
int Player::get_sum() const {
    int result = 0;
    for (int i = 0; i < dice_count; i++) {
        result += dice_results[i];

    }
    return result;
}
