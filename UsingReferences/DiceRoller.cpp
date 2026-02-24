#include "DiceRoller.h"

#include <cstring>
#include <iostream>
#include <random>

DiceRoller::DiceRoller() {
    dice_1 = 0;
    dice_2 = 0;

    std::cout << "Dice 1 setup:" << dice_1 << std::endl;
    std::cout << "Dice 2 setup:" << dice_2 << std::endl;
}
void DiceRoller::roll(const char* mode) {
    // the task was to pass the dice by reference so...
    if (strcmp(mode, "normal") == 0) {
        rollTwoDice(dice_1, dice_2);
    }
    else if (strcmp(mode, "cpp11") == 0) {
        rollTwoDiceCpp11(dice_1, dice_2);
    }
    else {
        std::cout << "Unknown mode: " << mode << std::endl;
    }

    std::cout << "Dice 1 rolled:" << dice_1 << std::endl;
    std::cout << "Dice 2 rolled:" << dice_2 << std::endl;
}

// outdated variant with rand()
void DiceRoller::rollTwoDice(int &d1, int &d2)
{
    d1 = (rand() % 6) + 1;
    d2 = (rand() % 6) + 1;
}

// more modern c++11 style of random number generation
void DiceRoller::rollTwoDiceCpp11(int &d1, int &d2) {
    //https://learn.microsoft.com/en-us/cpp/standard-library/random
    // first we need a generator that can generates random sequences of values
    std::random_device random_device;

    // most of the time the mersenne twister generator is used to generate random numbers
    // he has to be seeded (provided with a starting number) to not be deterministic
    // otherwise he would create always the same output
    std::mt19937 engine(random_device());

    // then a distribution is needed to distribute this valued in a specified way (in this case 1 to 6)
    std::uniform_int_distribution distribution(1,6);

    // then you use the distribution and provide it with the generator to generate random numbers
    //d1 = dist(rd);
    //d2 = dist(rd);
    d1 = distribution(engine);
    d2 = distribution(engine);
}

