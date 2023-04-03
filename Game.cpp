#include "Game.h"
#include "CardCount.h"
#include "Dumpling.h"
#include "MakiRoll.h"
#include "Nigiri.h"
#include "Sashimi.h"
#include "Tempura.h"

Game::~Game()
{
    delete currentPlayer;
    delete deck;
}
Game* Game::getInstance()
{
    if (Game::instance == NULL)
        instance = new Game();
    return instance;
}
void Game::printLogo() const
{
    std::cout << "|       |  | |  |       |  | |  |   |       |   |   |   _   |  |_|  |  |\n";
    std::cout << "|  _____|  | |  |  _____|  |_|  |   |  _____|   |   |  |_|  |       |  |\n";
    std::cout << "| |_____|  |_|  | |_____|       |   | |_____|   |   |       |       |  |\n";
    std::cout << "|_____  |       |_____  |       |   |_____  |   |___|       |       |__|\n";
    std::cout << " _____| |       |_____| |   _   |   |_____| |       |   _   | ||_|| |__\n";
    std::cout << "|_______|_______|_______|__| |__|___|_______|_______|__| |__|_|   |_|__|\n";
    std::cout << "\n";
}
void Game::initialize(const std::string* names)
{
    Player* p1 = new Player(names[rand() % 10]);
    Player* p2 = new Player(names[rand() % 10]);
    p1->setNext(p2);
    p2->setNext(p1);
    currentPlayer = p1;
    addCardsToDeck();
    deck->shuffle();
    splitCards(p1);
    splitCards(p2);
}
void Game::addCardsToDeck()
{
    deck->add(new Tempura(), TempuraCount)->add(new Sashimi(), SashimiCount)->add(new NigiriEgg(), NigiriEggCount);
    deck->add(new NigiriSquid(), NigiriSquidCount)->add(new NigiriSalmon(), NigiriSalmonCount);
    deck->add(new MakiRoll2(), MakiRoll2Count)->add(new MakiRoll3(), MakiRoll3Count)->add(new MakiRoll1(), MakiRoll1Count);
    deck->add(new Dumpling(), DumplingCount);
}
void Game::begin(const int MAX_ROUNDS)
{
    printLogo();
    round = 1;
    std::cout << "~~~ round " << round << '/' << MAX_ROUNDS << " ~~~" << std::endl;
    while (1)
    {
        std::cout << "PLAYER " << currentPlayer->toString() << " TURN\n";
        std::cout << "Tableau:\n";
        currentPlayer->printTableau();
        printPlayerCards(currentPlayer);
        askForCard(currentPlayer);
        currentPlayer = currentPlayer->getNext();
        std::cout << "PLAYER " << currentPlayer->toString() << " TURN\n";
        std::cout << "Tableau:\n";
        currentPlayer->printTableau();
        printPlayerCards(currentPlayer);
        askForCard(currentPlayer);
        currentPlayer = currentPlayer->getNext();
        swapHands(currentPlayer, currentPlayer->getNext());
        if ((currentPlayer->getHand()->size() < 1) || (currentPlayer->getNext()->getHand()->size() < 1))
            break;
    }
    std::cout << "~~~ end of round scoring ~~~\n";
    std::cout << "\tPLAYER " << currentPlayer->toString() << " round score: " << currentPlayer->calculateScore() << "\n";
    std::cout << "\tPLAYER " << currentPlayer->getNext()->toString() << " round score: " << currentPlayer->getNext()->calculateScore() << "\n";
}
void Game::splitCards(Player* p)
{
    for (int i = 0; i < 10; i++)
    {
        p->getHand()->add(deck->getCard(0));
        deck->remove(deck->getCard(0));
    }
}
void Game::printPlayerCards(Player* p)
{
    std::cout << "Current hand:\n";
    for (int i = 0; i < p->getHand()->size(); i++)
        std::cout << i + 1 << ". " << p->getHand()->getCard(i)->toString() << std::endl;
}
int Game::getInput(int maxRange)
{
    while (1)
    {
        int res = 0;
        std::cin >> res;
        if (std::cin.good())
            if (res > 0 && res <= maxRange)
                return res;
    }
}
void Game::askForCard(Player* p)
{
    std::cout << "Select a card to add to your tableau:\n";
    int inp = getInput(p->getHand()->size());
    p->addCardsToTableau(p->getHand()->getCard(inp - 1));
}
void Game::swapHands(Player* p1, Player* p2)
{
    CardCollection* t = p1->getHand();
    p1->setHand(p2->getHand());
    p2->setHand(t);
}