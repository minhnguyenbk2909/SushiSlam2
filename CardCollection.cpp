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
// Find and remove the pointer out of vector, but not freeing memory just yet
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
// Goal: A card must responsible for calculating its type
// Problem: Since a tableau can hold many cards of the same type, we can't just simply call calculate on each cards as it will create redundancy
// Solution: Keep track location of each card types in the array, we call calculate on each card types only once
{
	// Each elements corresponds to the index of each card types the last time they appear on vector
	// 0: MakiRollType ... 4: NigiriType
	// -1: that card type has not appeared in tableau
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
	// Loop through the vector and calculate each type of card
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
// Destructor, loop through vector and freeing each slots
{
	for (int i = 0; i < cards.size();i++)
		delete cards[i];
}
void CardCollection::clear()
// Clear the vector AND freeing the memories, must only be called on tableau
// If called on player hand, tableau will lose the pointer as well
{
	for (int i = 0; i < cards.size();i++)
		delete cards[i];
	cards.clear();
}