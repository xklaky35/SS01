#include <iostream>
#include <random>

#include "SimpleDiceGame/SimpleDiceGame.h"
#include "UsingReferences/DiceRoller.h"

void rollDice();
void playSimpleDiceGame();

int main()
{
    playSimpleDiceGame();
    return 0;
}
void rollDice() {
    // Task 1 test
    DiceRoller game;
    game.roll("normal");
    game.roll("cpp11");
}

void playSimpleDiceGame() {
    auto* simple_dice_game = new SimpleDiceGame();

    simple_dice_game->play();

    delete simple_dice_game;
}

int get_random_number(const int min, const int max) {

    // setup random number generator with device and distribution
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(min, max);

    // generate random numbers
    return distribution(gen);
}
