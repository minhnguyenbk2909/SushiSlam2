#include "CardCollection.h"
#include <algorithm>
#include <random>

CardCollection* CardCollection::add(Card* card, int num)
{
	for (int i = 0; i < num; ++i)
		cards.push_back(card);
	return this;
}
void CardCollection::remove(Card* card)
{
	for (int i = 0; i < cards.size(); i++)
		if (cards[i] == card)
		{
			cards.erase(cards.begin() + i);
			break;
		}
}
std::string CardCollection::toString() const
{
	std::string res = "";
	for (int i = 0; i < cards.size(); i++)
		res += cards[i]->toString() + "\n";
	return res;
}
void CardCollection::shuffle()
{
	std::shuffle(cards.begin(), cards.end(), std::mt19937{ std::random_device{}() });
}
int CardCollection::calculate(CardCollection* tableau, CardCollection* other) const
{
	int typ[5] = { -1, -1, -1, -1, -1 };
	for (int i = 0; i < cards.size(); i++)
	{
		if (cards[i]->type() == MakiRollType)
		{
			typ[0] = i;
			continue;
		}
		if (cards[i]->type() == TempuraType)
		{
			typ[1] = i;
			continue;
		}
		if (cards[i]->type() == SashimiType)
		{
			typ[2] = i;
			continue;
		}
		if (cards[i]->type() == DumplingsType)
		{
			typ[3] = i;
			continue;
		}
		if (cards[i]->type() == NigiriType)
		{
			typ[4] = i;
			continue;
		}
	}
	int total = 0;
	for (int i = 0; i < 5; i++)
		if (typ[i] >= 0)
			total += cards[typ[i]]->score(tableau, other);
	return total;
}
Card* CardCollection::getCard(int index)
{
	return cards[index];
}
int CardCollection::size()
{
	return cards.size();
}
CardCollection::~CardCollection()
{
	for (int i = 0; i < cards.size();i++)
		delete cards[i];
}
void CardCollection::clear()
{
	for (int i = 0; i < cards.size();i++)
		delete cards[i];
	cards.clear();
}