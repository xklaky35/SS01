#include <iostream>
#include "SimpleDiceGame.h"
#include "List.h"

int get_random_number(int,int);

SimpleDiceGame::SimpleDiceGame() {
    playerQueue = new PlayerQueue();
    playerList =  new List<Player>();

    auto* human = new Player(1, Player::HUMAN, 2);
    auto* ai = new Player(3, Player::AI, 2);

    register_player(human);
    register_player(ai);
}

SimpleDiceGame::~SimpleDiceGame() {
    delete_all_players();
    delete playerQueue;
    delete playerList;
}

void SimpleDiceGame::play() const {
    bool is_running = true;

    // gameloop
    while (is_running) {

        start_rolling_dice();

        const Player* winner = calculate_winner();
        if (winner != nullptr) {
            std::cout << "The winner is: " << winner->id << std::endl;
        }
        else {
            std::cout << "It's a draw!" << std::endl;
        }

        rotate_players();

        std::cout << "Do you want to continue (y/n): ";
        char c;
        std::cin >> c;
        if (c != 'y') {
            is_running = false;
        }

    }
}

// adds the player into the playerlist and queues him up for the game
void SimpleDiceGame::register_player(Player* p) const {
    playerList->add(p);
    playerQueue->enqueue(p);
}

void SimpleDiceGame::delete_all_players() const {
    Player* first_player_to_delete = playerQueue->firstPlayer;
    while ( first_player_to_delete != nullptr) {
        Player* new_first_player = first_player_to_delete->follower;
        delete first_player_to_delete;
        first_player_to_delete = new_first_player;
    }
}

// let the first player roll the dice
// he gives the turn automatically to the next person
void SimpleDiceGame::start_rolling_dice() const {
    playerQueue->firstPlayer->make_turn();
}

bool SimpleDiceGame::has_player_chance_to_win() {
    return get_random_number(1,10) > 5;
}

// calculates the winner depending on the players dice throw results
Player* SimpleDiceGame::calculate_winner() const {

    // artificial difficulty to win
    // the player needs to hit a 50% chance to have a chance to win (also 50%) resulting in 25% to win
    if (!has_player_chance_to_win()) {
        return playerQueue->find_first_player_of_type(Player::AI);
    }



    List<Player> potential_winner = get_all_players_with_all_of_a_kind();

    // The player that gets a double (or highest double) wins the round.
    if (potential_winner.get_size() == 0) {
        // If no player has all of a kind, the highest total wins.
        return find_highest_total_winner(playerList);
    }
    else if (potential_winner.get_size() == 1) {
        return potential_winner[0];
    }
    else {
        // if multiple players have all of a kind the highest total of those wins
        return find_highest_total_winner(&potential_winner);
    }
}

// find all player that have all of a kind
 List<Player> SimpleDiceGame::get_all_players_with_all_of_a_kind() const {
    List<Player> potentialWinners = List<Player>();
    for (int i = 0; i < playerList->get_size(); i++) {
        if ((*playerList)[i]->has_all_of_same_kind()) {
            potentialWinners.add((*playerList)[i]);
        }
    }
    return potentialWinners;
}

// initiates player rotation
void SimpleDiceGame::rotate_players() const {
    playerQueue->rotate();
}

// returns the player with the highest sum of the dice results of the provided player list
Player* SimpleDiceGame::find_highest_total_winner(List<Player>* p) {
    int max = 0;
    Player* current_winner =  nullptr;

    // find max value and winner
    for (int i = 0; i < p->get_size(); i++) {
        if ((*p)[i]->get_sum() > max) {
            max = (*p)[i]->get_sum();
            current_winner = (*p)[i];
        }
    }

    if (is_draw(max, p)) {
        return nullptr;
    }

    return current_winner;
}

// counts the occurrences a specific dice sum in a list of players
bool SimpleDiceGame::is_draw(const int n, List<Player>* p) {

    // check if multiple players have same value
    int max_count = 0;
    for (int i = 0; i < p->get_size(); i++) {
        if ((*p)[i]->get_sum() == n) {
            max_count++;
        }
    }

    // check the draw condition
    if (max_count > 1) {
        return true;
    }
    return false;
}


