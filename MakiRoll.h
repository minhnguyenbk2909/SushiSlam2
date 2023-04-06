#ifndef MAKIROLL_H
#define MAKIROLL_H

#include "Card.h"

class MakiRoll : public Card
{
protected:
    MakiRoll(int count); // Protected constructor, preventing instantiate abstract class

public:
    std::string toString() const override;
    int score(CardCollection* tableau, CardCollection* other) const override;
};

class MakiRoll1 : public MakiRoll
{
public:
    MakiRoll1();
};

class MakiRoll2 : public MakiRoll
{
public:
    MakiRoll2();
};

class MakiRoll3 : public MakiRoll
{
public:
    MakiRoll3();
};

#endif