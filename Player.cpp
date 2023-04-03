#include "Player.h"

Player::Player(std::string name)
{
    this->name = name;
}
Player::~Player()
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