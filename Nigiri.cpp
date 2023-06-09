#include "Nigiri.h"

Nigiri::Nigiri(int count) : Card(NigiriType,count) {}
std::string Nigiri::toString() const
{
    if (count == 1)
        return "Nigiri (Egg)";
    if (count == 3)
        return "Nigiri (Squid)";
    if (count == 2)
        return "Nigiri (Salmon)";
    return "";
}
int Nigiri::score(CardCollection* tableau, CardCollection* other) const
// count is also used as point
// Egg has 1 point, Squid 2p, etc..
{
    int point = 0;
    for (int i = 0; i < tableau->size(); i++)
        if (tableau->getCard(i)->type() == NigiriType)
            point += tableau->getCard(i)->getCount();
    return point;
}
NigiriEgg::NigiriEgg():Nigiri(1) {}
NigiriSquid::NigiriSquid() :Nigiri(3) {}
NigiriSalmon::NigiriSalmon() :Nigiri(2) {}