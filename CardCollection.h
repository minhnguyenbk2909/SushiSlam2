#ifndef CARDCOLLECTION_H
#define CARDCOLLECTION_H

#include "Card.h"
#include <vector>

class Card;

class CardCollection
{
private:
    // A vector holds pointers of card located on heap memory
    std::vector<Card*> cards;

public:
    ~CardCollection();
    CardCollection* add(Card* card, int num = 1);
    void remove(Card* card);
    std::string toString() const;
    void shuffle();
    int calculate(CardCollection* tableau, CardCollection* other) const;
    Card* getCard(int index);
    int size();
    void clear();
};

#endif
