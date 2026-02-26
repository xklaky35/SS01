#include "AiBotLetterGuess.h"
#include <iostream>

int get_random_number(int, int);
bool isInAlphabet(char);
bool isNumber(char);
bool isSpecialCharacter(char);


AiBotLetterGuess::AiBotLetterGuess() {
    is_running = true;
    is_in_round = true;
    chosenLetter = ' ';
    turnNumber = 0;
    roundCount = 0;
}

AiBotLetterGuess::~AiBotLetterGuess() {
    is_running = false;
}


void AiBotLetterGuess::Play() {
    std::cout << "BUZZ, HUM, ZAP... Powering up the AI-Bot..." << std::endl;
    std::cout << "  AI: Welcome to \"The 'Basic' Letter Guessing Game\"! AI: " << std::endl;

    // game loop
    while (is_running) {
        // choose letter and print it
        chosenLetter = ChooseRandomLetter();
        PrintHint();

        // round loop
        PlayRound();

    }
}

void AiBotLetterGuess::PlayRound() {
    // adjusts parameter for round
    is_in_round = true;
    turnNumber = 0;
    ++roundCount;

    // round loop
    while (is_in_round && is_running) {
        ++turnNumber;
        char playerGuess = AskPlayerToGuess();

        if (!IsLetterCorrect(playerGuess)) {
            continue;
        }

        if (AskPlayerToPlayAgain()) {
            // end round to play another one
            is_in_round = false;
        }
        else {
            // end the round and the game to quit
            is_in_round = false;
            is_running = false;
            PrintGoodbyeMessage();
        }
    }
}




std::string AiBotLetterGuess::getPositionDirection(char input) const {
    if (input < chosenLetter) {
        return "after ";
    }
    return "before ";
}

// chooses a random letter from the letter pool
char AiBotLetterGuess::ChooseRandomLetter() const {
    return letterPool[get_random_number(0,25)];
}


// asks the player to input a letter
// returns only lowercase letters
char AiBotLetterGuess::AskPlayerToGuess() const {
    if (turnNumber >= 26) {
        std::cout << "Not many made it this far warrior... " << std::endl;
    }
    std::cout << "  AI: Turn " << turnNumber << ", what is your guess?" << std::endl;
    std::cout << "Human: ";

    char playerGuess;
    std::cin >> playerGuess;

    return (char)tolower(playerGuess);
}

bool AiBotLetterGuess::AskPlayerToPlayAgain() {
    std::cout << "  AI: Play again (y/n)? ";
    char playAgainChoice;
    std::cin >> playAgainChoice;

    switch ((char)tolower(playAgainChoice)) {
        case 'y': {
            return true;
        }
        default: {
            return false;
        }
    }
}

// prints a hind for the user displaying the whole alphabet
void AiBotLetterGuess::PrintHint() const {
    std::cout << "  AI: Here we go! ...";
    for (int i = 0; i < 26; i++) {
        if (letterPool[i] == chosenLetter) {
            std::cout << (char)toupper(letterPool[i]);
        }
        else {
            std::cout << letterPool[i];
        }
    }
    std::cout << "..."<< std::endl;
    std::cout << "  AI: I'm thinking of a secret letter, can you guess it..." << std::endl;
}

void AiBotLetterGuess::PrintGoodbyeMessage() const {
    std::cout << "AI: Thanks for playing " << roundCount << (roundCount > 1 ? " rounds":" round") << " with me!" << std::endl;
    std::cout << "AI: G" << std::endl;
    std::cout << "AI:  o" << std::endl;
    std::cout << "AI:   o" << std::endl;
    std::cout << "AI:    d" << std::endl;
    std::cout << "AI:     b" << std::endl;
    std::cout << "AI:      y" << std::endl;
    std::cout << "AI:        " << std::endl;
    std::cout << "AI:        H" << std::endl;
    std::cout << "AI:         u" << std::endl;
    std::cout << "AI:          m" << std::endl;
    std::cout << "AI:           a" << std::endl;
    std::cout << "AI:            n" << std::endl;
    std::cout << "AI:             !" << std::endl;
    std::cout << "Powering down the AI-Bot... FIZZ, POP, BANG!" << std::endl;
}



// checks the player input and reacts depending on input type
bool AiBotLetterGuess::IsLetterCorrect(char input) const{
    if (isNumber(input)) {
        std::cout << "AI: Wrong... " << input << " is a digit, that is not a letter!" << std::endl;
        return false;
    }
    if (isSpecialCharacter(input)) {

        std::cout << "AI: Wrong... wow, " << input << " is not a letter!" << std::endl;
        return false;
    }

    // has to be in alphabet at this point
    if (chosenLetter == letterPool[input-97]) {
        std::cout << "  AI: Well done!" << std::endl;
        std::cout << "  AI: You took " << turnNumber << (turnNumber > 1 ? " turns":" turn") << "! Game over!" << std::endl;
        return true;
    }
    else {
        std::cout << "AI: Wrong... my secret letter comes " << getPositionDirection(input) << (char)toupper(input) << " in the alphabet..." << std::endl;
    }
    return false;
}



