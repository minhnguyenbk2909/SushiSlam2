#include "Card.h"

Card::Card(CardType typ, int count)
{
    this->typ = typ;
    this->count = count;
}
const CardType& Card::type() const
{
    return typ;
}
int Card::getCount() const
{
    return count;
}