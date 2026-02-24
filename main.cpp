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
    SimpleDiceGame simple_dice_game = SimpleDiceGame();

    Player human = Player(1, Player::HUMAN, 2);
    Player human2 = Player(2, Player::HUMAN, 2);
    Player ai = Player(3, Player::AI, 2);
    Player ai2 = Player(4, Player::AI, 2);
    Player ai3 = Player(5, Player::AI, 2);

    simple_dice_game.register_player(&human);
    simple_dice_game.register_player(&human2);
    simple_dice_game.register_player(&ai);
    simple_dice_game.register_player(&ai2);
    simple_dice_game.register_player(&ai3);

    simple_dice_game.play();
}

