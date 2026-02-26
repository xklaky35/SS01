#ifndef HIDDENTREASURE_H
#define HIDDENTREASURE_H

#include <string>

#define SIZE_X 20
#define SIZE_Y 20
#define NEGATIVE_OFFSET_X (SIZE_X/2)
#define NEGATIVE_OFFSET_Y (SIZE_Y/2)

struct Treasure {
    std::string name;
    int x;
    int y;
};

// holds position and direction values
struct Vector2d {
    int x;
    int y;
};

class HiddenTreasure {
public:
    // variables
    bool is_running;
    int map[SIZE_X][SIZE_Y];
    Vector2d* currentPos;
    Treasure treasureCollection[5];

    // *structors
    HiddenTreasure();
    ~HiddenTreasure();

    // methods
    void Play();
    bool Move(Vector2d) const;
    bool HandleDirection(char);
    Treasure* SearchForTreasure();
};


#endif