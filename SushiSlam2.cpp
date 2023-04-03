#include "Game.h"

Game* Game::instance;

int main()
{
    const int MAX_ROUNDS = 3;
    const std::string names[10] = { "Sam",
                                   "Billy",
                                   "Jen",
                                   "Bob",
                                   "Sally",
                                   "Joe",
                                   "Sue",
                                   "Sasha",
                                   "Tina",
                                   "Marge" };
    Game* g = Game::getInstance();
    g->initialize(names);
    g->begin(MAX_ROUNDS);
    return 0;
}