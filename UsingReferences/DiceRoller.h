#ifndef USINGREFERENCES_DICE_H
#define USINGREFERENCES_DICE_H


class DiceRoller {
    public:
    DiceRoller();
    void roll(const char*);

    private:
    int dice_1;
    int dice_2;
    static void rollTwoDice(int&,int&);
    static void rollTwoDiceCpp11(int&,int&);
};


#endif //USINGREFERENCES_DICE_H
