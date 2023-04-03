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
        count += 1;
    return (count / 3) * 10;
}