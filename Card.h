#ifndef CARD_H
#define CARD_H

#include "CardType.h"
#include <string>
#include "CardCollection.h"

class CardCollection;

class Card
{
    CardType typ;

protected:
    // A specific variable for MakiRoll and Nigiri types, in which they need to differentiate each others
    // E.g: MakiRoll has 1,2,3 variants, Nigiri has Egg,Salmon,Squid variants
    // For every other types, this remains zero
    int count = 0;

public:
    Card(CardType typ, int count = 0);
    const CardType& type() const;
    // virtual std::string str() const = 0;
    virtual std::string toString() const = 0;
    virtual int score(CardCollection* tableau, CardCollection* other) const = 0;
    int getCount() const;
};

#endif