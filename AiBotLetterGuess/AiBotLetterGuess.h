#ifndef AIBOTLETTERGUESS_H
#define AIBOTLETTERGUESS_H
#include <string>


class AiBotLetterGuess {
public:
    // *structors
    AiBotLetterGuess();
    ~AiBotLetterGuess();


    // methods
    void Play();

private:
    // variables
    bool is_running;
    bool is_in_round;

    int roundCount;
    int turnNumber;

    char chosenLetter;
    char letterPool[26] = {'a', 'b', 'c', 'd', 'e', 'f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


    // methods
    char ChooseRandomLetter() const;
    void PlayRound();
    static bool AskPlayerToPlayAgain();
    char AskPlayerToGuess() const;

    std::string getPositionDirection(char input) const;
    bool IsLetterCorrect(char input) const;
    void PrintGoodbyeMessage() const;
    void PrintHint() const;
};

#endif