#ifndef SS01_MONTYHALL_H
#define SS01_MONTYHALL_H
#include <string>

struct Door {
    char content;
};

class MontyHall {
public:
    MontyHall();
    ~MontyHall();

    void Play();

private:
    bool is_running;
    int winningDoor;
    int playerDoorChoice;
    Door doors[3] = {
        Door('1'),
        Door('2'),
        Door('3')
    };

    static int FindDoorBetween(int, int);
    void PrintDoors() const;

    void InitGame();

    bool IsInputValid() const;
    void RevealPrices();
};

#endif