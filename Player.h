#ifndef PLAYER_H
#define PLAYER_H

#include "CardCollection.h"
#include <iostream>

class Player
{
private:
    std::string name;
    CardCollection* tableau = new CardCollection();
    CardCollection* hand = new CardCollection();
    int score = 0;
    Player* next = NULL; // pointer to other player

public:
    Player(std::string name);
    ~Player();
    void addCardsToTableau(Card* card);
    std::string toString() const;
    void printTableau() const;
    int calculateScore() const;
    void setNext(Player* next);
    Player* getNext() const;
    CardCollection* getTableau() const;
    CardCollection* getHand() const;
    void setHand(CardCollection* hand);
    void setScore(const int score);
    int getScore() const;
};

#endif