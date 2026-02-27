#include <random>

int get_random_number(const int min, const int max) {

    // setup random number generator with device and distribution
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(min, max);

    // generate random numbers
    return distribution(gen);
}

// returns true if the provided char is a letter, false otherwise
bool isInAlphabet(char input) {
    if ((input >= 65 && input <= 90) || (input >= 97 && input <= 122)) {
        return true;
    }
    return false;
}

// returns true if the provided char is a number, false otherwise
bool isNumber(char input) {
    if (input >= 48 && input <= 57) {
        return true;
    }
    return false;
}

// returns true if the provided char is a special charater, false otherwise
bool isSpecialCharacter(char input) {
    if (!isInAlphabet(input) && !isNumber(input)) {
        return true;
    }
    return false;
}
