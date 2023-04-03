#include "Nigiri.h"

Nigiri::Nigiri(int count) : Card(NigiriType,count) {}
std::string Nigiri::toString() const
{
    if (count == 1)
        return "Nigiri (Egg)";
    if (count == 2)
        return "Nigiri (Squid)";
    if (count == 3)
        return "Nigiri (Salmon)";
    return "";
}
int Nigiri::score(CardCollection* tableau, CardCollection* other) const
{
    int point = 0;
    for (int i = 0; i < tableau->size(); i++)
        if (tableau->getCard(i)->type() == NigiriType)
            point += tableau->getCard(i)->getCount();
    return point;
}
NigiriEgg::NigiriEgg():Nigiri(1) {}
NigiriSquid::NigiriSquid() :Nigiri(2) {}
NigiriSalmon::NigiriSalmon() :Nigiri(3) {}