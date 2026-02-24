#include "Player.h"

#include <cstdlib>
#include <iostream>
#include <random>


Player::Player(int id, PLAYER_TYPE type, int dice_count) {
    follower = nullptr;
    Player::dice_count = dice_count;
    Player::type = type;
    dice_results = (int*)malloc(sizeof(int)*dice_count);
    Player::id = id;
}

// display the current dice result on the screen
void Player::print_results() const {
    for (int i = 0; i < dice_count; i++) {
        printf("Player[%d]> Dice result %d: %d\n", id, i+1, dice_results[i]);
    }
}

// generate random numbers for each dice
void Player::roll_dice() const {

    // setup random number generator with device and distribution
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(1, 6);

    // let player roll manually if the player is human
    if (type == HUMAN) {
        std::cout << "\nPlayer (id:" << id << ") is rolling...";
        getchar();
    }
    else if (type == AI) {
        std::cout << "\nAI (id:" << id << ") is rolling..." << std::endl;
    }

    // generate random numbers
    for (int i = 0; i < dice_count; i++) {
        dice_results[i] = distribution(gen);
    }

    print_results();

    // pass to next player
    if (follower != nullptr) {
        follower->roll_dice();
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
