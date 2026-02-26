#include <iostream>
#include "HiddenTreasure.h"

HiddenTreasure::HiddenTreasure() {

    for (int i = 0; i < SIZE_X; i++) {
        for (int j = 0; j < SIZE_Y; j++) {
            map[i][j] = 0;
        }
    }

    // initial state is "running"
    is_running = true;

    // set start position as the offset to start in the middle
    currentPos = new Vector2d(NEGATIVE_OFFSET_X, NEGATIVE_OFFSET_Y);

    // register the treasure
    treasureCollection[0] = {Treasure("a pirate's chest", 2,3)};
    treasureCollection[1] = {Treasure("a golden idol", -5,3)};
    treasureCollection[2] = {Treasure("a precious gemstone", 1,-2)};
    treasureCollection[3] = {Treasure("a lost artwork", 5,2)};
    treasureCollection[4] = {Treasure("a dragons talon", 1,1)};
}

HiddenTreasure::~HiddenTreasure() {
    delete currentPos;
}

// executes the game loop
void HiddenTreasure::Play() {

    std::cout << "Find the hidden treasure!" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout<< "Press 'Q' to quit at any time..." << std::endl;
    puts("");

    // game loop
    while (is_running) {

        // ask for input
        char direction;

        // simulate a negative number space by subtracting the offset
        std::cout << "You are at (" << currentPos->x - NEGATIVE_OFFSET_X << ", " << currentPos->y - NEGATIVE_OFFSET_Y<< "). Move (N/E/S/W) > ";
        std::cin >> direction;

        // if the input was not right the loop is restarted
        if (!HandleDirection(direction)) {
            continue;
        }

        // check if treasure is found
        Treasure* found_treasure = SearchForTreasure();
        if (found_treasure != nullptr) {
            std::cout << "\n*******************************" << std::endl;
            std::cout << "* You found " << found_treasure->name << "! *" << std::endl;
            std::cout << "*******************************\n" << std::endl;
        }
    }
}

// checks world boundaries and moves the current position pointer in the specified direction
bool HiddenTreasure::Move(const Vector2d dir) const {
    int x_dest = currentPos->x + dir.x;
    int y_dest = currentPos->y + dir.y;
    if ((x_dest > SIZE_X || x_dest < 0) || (y_dest > SIZE_Y || y_dest < 0)) {
        std::cout << "+-----------------------------------------+" << std::endl;
        std::cout << "| You have reached the edge of the world! |" << std::endl;
        std::cout << "+-----------------------------------------+\n" << std::endl;
        return false;
    }
    currentPos->x += dir.x;
    currentPos->y += dir.y;
    return true;
}

// validates the input and
bool HiddenTreasure::HandleDirection(const char dir) {
    switch (tolower(dir)) {
        case 'e': {
            return Move(Vector2d(-1, 0));
        }
        case 's': {
            return Move(Vector2d(0, -1));
        }
        case 'n': {
            return Move(Vector2d(0, 1));
        }
        case 'w': {
            return Move(Vector2d(1, 0));
        }
        case 'q': {
            // shutdown the game by setting the flag
            is_running = false;
        }
        default: {
            std::cout << "Invalid command!" << std::endl;
            return false;
        }
    }
}

// checks if there is treasure on the current position of the player and returns a pointer to it
Treasure* HiddenTreasure::SearchForTreasure() {
    for (int i =0; i < 5; i++) {
        // the treasures use the simulated negative coordinates to we need to subtract the offset
        if (currentPos->x - NEGATIVE_OFFSET_X == treasureCollection[i].x && currentPos->y - NEGATIVE_OFFSET_Y == treasureCollection[i].y)
            return &(treasureCollection[i]);
    }
    return nullptr;
}




