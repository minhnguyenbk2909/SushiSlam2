#ifndef NIGIRI_H
#define NIGIRI_H

#include "Card.h"

class Nigiri : public Card
{
protected:
    Nigiri(int count); // Protected constructor

public:
    std::string toString() const override;
    int score(CardCollection* tableau, CardCollection* other) const override;
};

class NigiriEgg : public Nigiri
{
public:
    NigiriEgg();
};

class NigiriSquid : public Nigiri
{
public:
    NigiriSquid();
};

class NigiriSalmon : public Nigiri
{
public:
    NigiriSalmon();
};

#endif