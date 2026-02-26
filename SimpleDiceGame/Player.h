#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    enum PLAYER_TYPE {AI, HUMAN, UNDEFINED};

    // variables
    int id;
    Player* follower;
    PLAYER_TYPE type;


    // *structors
    Player();
    Player(int p_id, PLAYER_TYPE, int p_dice_count);
    ~Player();

    // methods
    void make_turn() const;
    void roll_dice() const;
    void print_results() const;
    bool has_all_of_same_kind() const;
    int get_sum() const;

private:
    int dice_count;
    int* dice_results;
};


#endif
