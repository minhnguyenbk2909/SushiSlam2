#ifndef DUMPLING_H
#define DUMPLING_H

#include "Card.h"

class Dumpling : public Card
{
public:
    Dumpling();
    std::string toString() const override;
    int score(CardCollection* tableau, CardCollection* other) const override;
};

#endif