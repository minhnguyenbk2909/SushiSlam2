#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
private:
    static Game* instance;
    int round = 0;
    Player* currentPlayer = NULL;
    CardCollection* deck = new CardCollection();
    Game() {}

public:
    ~Game();
    static Game* getInstance();
    void printLogo() const;
    void initialize(const std::string* names);
    void addCardsToDeck();
    void begin(const int MAX_ROUNDS);
    void splitCards(Player* p);
    void printPlayerCards(Player* p);
    int getInput(int maxRange);
    void askForCard(Player* p);
    void swapHands(Player* p1, Player* p2);
};

#endif