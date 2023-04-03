#ifndef TEMPURA_H
#define TEMPURA_H

#include "Card.h"

class Tempura : public Card
{
public:
    Tempura();
    std::string toString() const override;
    int score(CardCollection* tableau, CardCollection* other) const override;
};

#endif