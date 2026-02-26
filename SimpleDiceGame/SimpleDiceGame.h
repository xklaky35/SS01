#ifndef SIMPLEDICEGAME_H
#define SIMPLEDICEGAME_H

#include "PlayerQueue.h"
#include "List.h"

class SimpleDiceGame {
public:
    // *structors
    SimpleDiceGame();
    ~SimpleDiceGame();

    // methods
    void play() const;

private:
    // variables
    PlayerQueue* playerQueue;
    List<Player>* playerList;

    // methods
    static Player* find_highest_total_winner(List<Player>*);
    static bool is_draw(int n, List<Player>*);
    static bool has_player_chance_to_win();
    Player* calculate_winner() const;
    List<Player> get_all_players_with_all_of_a_kind() const;
    void register_player(Player* p) const;
    void delete_all_players() const;
    void rotate_players() const;
    void start_rolling_dice() const;

};

#endif
