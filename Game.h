#ifndef GAME_H
#define GAME_H

#include "Player.h"

class Game
{
private:
    static Game* instance; // Private static member, this holds reference to the ONLY Game object
    int round = 0;
    static const int MAX_ROUNDS = 3;
    Player* currentPlayer = NULL;
    CardCollection* deck = new CardCollection();
    Game(); // Private constructor preventing instantiate

public:
    ~Game();
    static Game* getInstance();
    void printLogo() const;
    void initialize(const std::string* names);
    void addCardsToDeck();
    void progress(std::vector<int>&,std::vector<int>&);
    void begin();
    void splitCards(Player* p);
    void printPlayerCards(Player* p);
    int getInput(int maxRange);
    void askForCard(Player* p);
    void swapHands(Player* p1, Player* p2);
};

#endif