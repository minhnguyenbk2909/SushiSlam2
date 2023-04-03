#include "Dumpling.h"

Dumpling::Dumpling() : Card(DumplingsType) {}
std::string Dumpling::toString() const
{
    return "Dumpling";
}
int Dumpling::score(CardCollection* tableau, CardCollection* other) const
{
    int count = 0;
    for (int i = 0; i < tableau->size(); i++)
        if (tableau->getCard(i)->type() == DumplingsType)
            count += 1;
    if (count > 4)
        return 15;
    else if (count == 4)
        return 10;
    else if (count == 3)
        return 6;
    else if (count == 2)
        return 3;
    else if (count == 1)
        return 1;
    return 0;
}