#include "Player.h"

Player::Player(std::string name)
{
    this->name = name;
}
Player::~Player()
// Free memory of 3 heaps allocated
{
    delete tableau;
    delete hand;
    delete next;
}
void Player::addCardsToTableau(Card* card)
{
    tableau->add(card);
    hand->remove(card);
}
std::string Player::toString() const
{
    return name;
}
void Player::printTableau() const
{
    std::cout << tableau->toString();
}
int Player::calculateScore() const
// Calculate score is tableau's responsibility
{
    return tableau->calculate(tableau, next->tableau);
}
void Player::setNext(Player* next)
{
    this->next = next;
}
Player* Player::getNext() const
{
    return next;
}
CardCollection* Player::getTableau() const
{
    return tableau;
}
CardCollection* Player::getHand() const
{
    return hand;
}
void Player::setHand(CardCollection* hand)
{
    this->hand = hand;
}
void Player::setScore(const int score)
{
    this->score = score;
}
int Player::getScore() const {
    return score;
}