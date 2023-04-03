#ifndef SASHIMI_H
#define SASHIMI_H

#include "Card.h"

class Sashimi : public Card
{
public:
    Sashimi();
    std::string toString() const override;
    int score(CardCollection* tableau, CardCollection* other) const override;
};

#endif