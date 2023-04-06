#include "MakiRoll.h"

MakiRoll::MakiRoll(int count) : Card(MakiRollType,count)
{
}

std::string MakiRoll::toString() const
{
    std::string res = "MakiRoll (";
    res += std::to_string(count);
    res += ')';
    return res;
}
int MakiRoll::score(CardCollection* tableau, CardCollection* other) const
{
    // Count the actual MakiRolls on player tableau
    int this_count = 0;
    int other_count = 0;
    // If the card is MakiRoll1() -> count+1, MakiRoll2() -> count+2, etc..
    for (int i = 0; i < tableau->size(); i++)
        if (tableau->getCard(i)->type() == MakiRollType)
            this_count += tableau->getCard(i)->getCount();
    for (int i = 0; i < other->size(); i++)
        if (other->getCard(i)->type() == MakiRollType)
            other_count += other->getCard(i)->getCount();
    if (this_count <= other_count)
        return 3;
    else
        return 6;
}

MakiRoll1::MakiRoll1() :MakiRoll(1) {} // count=1
MakiRoll2::MakiRoll2() :MakiRoll(2) {} // count=2
MakiRoll3::MakiRoll3() :MakiRoll(3) {} // count=3
