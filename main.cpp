#include <iostream>

#include "SimpleDiceGame/SimpleDiceGame.h"
#include "UsingReferences/DiceRoller.h"
#include "HiddenTreasure/HiddenTreasure.h"
#include "AiBotLetterGuess/AiBotLetterGuess.h"
#include "MontyHall/MontyHall.h"
#include "CppAndHGenerator/CppAndHGenerator.h"

void PrintWelcome();
void PrintMenu();
void RollDice();
void PlaySimpleDiceGame();
void PlayHiddenTreasure();
void PlayAiBotLetterGuess();
void PlayMontyHall();
void GenerateFiles();
bool ValidateInput(const std::string&, bool&);

int main()
{
    PrintWelcome();
    bool isRunning = true;

    // main gameloop
    while (isRunning) {
        PrintMenu();

        std::string userChoice;
        do {
            std::cout << "Select an option: ";
            std::cin >> userChoice;
        }
        while (!ValidateInput(userChoice, isRunning));
    }
    return 0;
}

void PrintWelcome() {
    std::cout << "****************************************\n";
    std::cout << "*                                      *\n";
    std::cout << "*        >>>  WELCOME PLAYER  <<<      *\n";
    std::cout << "*                                      *\n";
    std::cout << "*        COMP710 GAME PROJECT          *\n";
    std::cout << "*                                      *\n";
    std::cout << "****************************************\n";
    std::cout << "\nPress ENTER to start...";
    std::cin.get();
}

void PrintMenu() {
    std::cout << "\n=====================================" << std::endl;
    std::cout << "           GAME SELECTION            " << std::endl;
    std::cout << "=====================================" << std::endl;
    puts("");
    std::cout << "1. Roll Dice" << std::endl;
    std::cout << "2. Simple Dice Game" << std::endl;
    std::cout << "3. Hidden Treasure" << std::endl;
    std::cout << "4. AI Bot Letter Guess" << std::endl;
    std::cout << "5. Monty Hall" << std::endl;
    std::cout << "6. Generate Files" << std::endl;
    puts("");
    std::cout << "Exit with ':q'" << std::endl;
    std::cout << "=====================================" << std::endl;
}

bool ValidateInput(const std::string& input, bool& isRunning) {
    if (input == "1") {
        RollDice();
        return true;
    }
    else if (input == "2") {

        PlaySimpleDiceGame();
        return true;
    }
    else if (input == "3") {

        PlayAiBotLetterGuess();
        return true;
    }
    else if (input == "4") {
        PlayHiddenTreasure();
        return true;

    }
    else if (input == "5") {

        PlayMontyHall();
        return true;
    }
    else if (input == "6") {

        GenerateFiles();
        return true;
    }
    else if (input == ":q") {
        isRunning = false;
        return true;
    }
    else {
        return false;
    }
}

void RollDice() {
    // Task 1 test
    DiceRoller game;
    game.roll("normal");
    game.roll("cpp11");
}
void PlaySimpleDiceGame() {
    auto simpleDiceGame = SimpleDiceGame();
    simpleDiceGame.play();
}
void PlayHiddenTreasure() {
    auto hiddenTreasureGame = HiddenTreasure();
    hiddenTreasureGame.Play();
}
void PlayAiBotLetterGuess() {
    auto aiBotLetterGuess = AiBotLetterGuess();
    aiBotLetterGuess.Play();
}
void PlayMontyHall() {
    auto montyHall = MontyHall();
    montyHall.Play();
}
void GenerateFiles() {
    CppAndHGenerator::StartGenerator();
}