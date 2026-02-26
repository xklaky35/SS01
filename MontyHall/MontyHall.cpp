#include "MontyHall.h"

#include <iostream>
#include <vector>

int get_random_number(int, int);

MontyHall::MontyHall() {
    winningDoor = 0;
    playerDoorChoice = 0;
    is_running = true;
}

MontyHall::~MontyHall() {
    is_running = false;
}



void MontyHall::Play() {
    std::cout << "The Monty Hall Game Show!" << std::endl;
    std::cout << "------------------------" << std::endl;

    while (is_running) {
        InitGame();

        winningDoor = get_random_number(0,2);

        PrintDoors();

        // player chooses first door
        while (!IsInputValid()) {
            std::cout << "Which door does the player choose (1/2/3)? ";
            std::cin >> playerDoorChoice;
        }
        // to make it usable as index
        playerDoorChoice--;

        // game chooses loosing door from the rest and marks it
        int gameHostChoice = FindDoorBetween(winningDoor, playerDoorChoice);
        doors[gameHostChoice].content = 'X';
        std::cout << "The game host chooses door number " << gameHostChoice+1 << "..." << std::endl;
        PrintDoors();

        // asks if user wants to switch to the other door
        int lastDoor = FindDoorBetween(playerDoorChoice, gameHostChoice);
        std::cout << "Does the player want to switch from door " << playerDoorChoice + 1 << " to door " << lastDoor+1 << " (y/n)? ";

        // check choice to swap doors
        char switchChoice ;
        std::cin >> switchChoice;
        if ((char)tolower(switchChoice) == 'y') {
            std::cout << "Player swaps to door " << lastDoor + 1 << "..." << std::endl;
            playerDoorChoice = lastDoor;
        }
        else if ((char)tolower(switchChoice) == 'n') {
            std::cout << "Player chooses to stay with door " << playerDoorChoice + 1<< "..." << std::endl;
        }


        // shows winner door
        std::cout << "It's time to reveal the prizes!" << std::endl;
        RevealPrices();
        PrintDoors();

        // checks if user won the prize
        if (winningDoor == playerDoorChoice) {
            std::cout << "Congratulations! The player wins!" << std::endl;
        }
        else {
            std::cout << "Oh on! The player loses!" << std::endl;
        }

        std::cout << "Play again (y/n)? ";
        char playAgainChoice ;
        std::cin >> playAgainChoice;
        if ((char)tolower(playAgainChoice) == 'n') {
            is_running = false;
        }
    }
}


int MontyHall::FindDoorBetween(const int d1, const int d2) {
    std::pmr::vector choices = {0,1,2};

    choices[d1] = -1;
    choices[d2] = -1;

    /*
     * In the case that d1 and d2 are the same, there are two options left to choose from.
     * If we only take the first one from one side, it is predictable.
     * Now we introduced a 50/50 chance of starting on either side
     */
    if (get_random_number(0,1) == 0) {
        for (int i = 0; i < choices.size(); i++) {
            if (choices[i] != -1) {
                return choices[i];
            }
        }
    }
    else {
        for (int i = (int)choices.size()-1; i >= 0; i--) {
            if (choices[i] != -1) {
                return choices[i];
            }
        }
    }

    return -1;
}

bool MontyHall::IsInputValid() const {
    if (playerDoorChoice > 0 && playerDoorChoice <= 3) {
        return true;
    }
    return false;
}

void MontyHall::RevealPrices() {
    for (int i = 0; i < 3; i++) {
        doors[i].content = 'X';
    }
    doors[winningDoor].content = '$';
}

void MontyHall::PrintDoors() const {
    puts("");
    std::cout << "Door1\t\tDoor2\t\tDoor3\n";
    std::cout << "+---+\t\t+---+\t\t+---+\n";
    std::cout << "|   |\t\t|   |\t\t|   |\n";
    std::cout << "| " << doors[0].content << " |\t\t| " << doors[1].content << " |\t\t| " << doors[2].content << " |\n";
    std::cout << "|   |\t\t|   |\t\t|   |\n";
    std::cout << "+---+\t\t+---+\t\t+---+\n";
    puts("");
}

void MontyHall::InitGame() {
    playerDoorChoice = 0;
    winningDoor = 0;

    for (int i = 0; i < 3; i++) {
        doors[i] = Door((char)(i + 1)+'0');
    }
};
