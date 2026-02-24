#ifndef SIMPLEDICEGAME_H
#define SIMPLEDICEGAME_H

#include "PlayerQueue.h"
#include "List.h"

class SimpleDiceGame {
public:
    SimpleDiceGame();

    // methods
    void register_player(Player* p);
    void play();


private:
    // methods
    static Player* find_highest_total_winner(List<Player>);
    static bool is_draw(int n, List<Player>);

    Player* calculate_winner();
    List<Player> get_all_players_with_all_of_a_kind();
    void rotate_players();

    void start_rolling_dice() const;


    // variables
    PlayerQueue playerQueue;
    List<Player> playerList;
};

#endif
