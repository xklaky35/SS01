#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    enum PLAYER_TYPE {AI, HUMAN};

    // Variables
    int id;
    Player* follower;
    PLAYER_TYPE type;

    // Constructors
    Player(int id, PLAYER_TYPE, int dice_count);

    // Methods
    void roll_dice() const;
    void print_results() const;
    bool has_all_of_same_kind() const;
    int get_sum() const;


private:
    int dice_count;
    int* dice_results;
};


#endif
