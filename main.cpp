#include <iostream>
#include <random>

#include "SimpleDiceGame/SimpleDiceGame.h"
#include "UsingReferences/DiceRoller.h"
#include "HiddenTreasure/HiddenTreasure.h"
#include "AiBotLetterGuess/AiBotLetterGuess.h"
#include "MontyHall/MontyHall.h"

void rollDice();
void playSimpleDiceGame();
void playHiddenTreasure();
void playAiBotLetterGuess();
void playMontyHall();

int main()
{
    playMontyHall();
    return 0;
}
void rollDice() {
    // Task 1 test
    DiceRoller game;
    game.roll("normal");
    game.roll("cpp11");
}

void playSimpleDiceGame() {
    auto simple_dice_game = SimpleDiceGame();
    simple_dice_game.play();
}

void playHiddenTreasure() {
    auto hidden_treasure_game = HiddenTreasure();
    hidden_treasure_game.Play();
}

void playAiBotLetterGuess() {
    auto aiBotLetterGuess = AiBotLetterGuess();
    aiBotLetterGuess.Play();
}

void playMontyHall() {
    auto montyHall = MontyHall();
    montyHall.Play();
}


//####################
//#       MISC       #
//####################
int get_random_number(const int min, const int max) {

    // setup random number generator with device and distribution
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(min, max);

    // generate random numbers
    return distribution(gen);
}

bool isInAlphabet(char input) {
    if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)) {
        return true;
    }
    return false;
}

bool isNumber(char input) {
    if (input >= 48 && input <= 57) {
        return true;
    }
    return false;
}

bool isSpecialCharacter(char input) {
    if (!isInAlphabet(input) && !isNumber(input)) {
        return true;
    }
    return false;
}
