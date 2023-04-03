#include "Tempura.h"

Tempura::Tempura() : Card(TempuraType) {}
std::string Tempura::toString() const
{
    return "Tempura";
}
int Tempura::score(CardCollection* tableau, CardCollection* other) const
{
    int count = 0;
    for (int i = 0; i < tableau->size(); i++)
        if (tableau->getCard(i)->type() == TempuraType)
            count += 1;
    return (count / 2) * 5;
}