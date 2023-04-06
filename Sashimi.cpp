#include "Sashimi.h"

Sashimi::Sashimi() : Card(SashimiType) {}
std::string Sashimi::toString() const
{
    return "Sashimi";
}
int Sashimi::score(CardCollection* tableau, CardCollection* other) const
{
    int count = 0;
    for (int i = 0; i < tableau->size(); i++)
        if (tableau->getCard(i)->type() == SashimiType)
            count += 1;
    return (count / 3) * 10; // Use quotient to get each set of 3 sashimi
}