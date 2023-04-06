#include "Game.h"
#include "CardCount.h"
#include "Dumpling.h"
#include "MakiRoll.h"
#include "Nigiri.h"
#include "Sashimi.h"
#include "Tempura.h"
#include <sstream>
#include <algorithm>

Game::Game()
{

}

Game::~Game()
// Freeing memory for 2 pointers
{
	delete currentPlayer;
	delete deck;
}
Game* Game::getInstance()
// OOP Singleton pattern, only through this static method call to get static Game object
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
	// Set each player to be the other's next, forming circular queue
	p1->setNext(p2);
	p2->setNext(p1);
	currentPlayer = p1;
	addCardsToDeck();
	deck->shuffle();
}
void Game::addCardsToDeck()
// Add default 88 cards to game deck
{
	/*
	Card* t = new Tempura();
	deck->add(t, TempuraCount);
	t = new Sashimi();
	deck->add(t, SashimiCount);
	t = new NigiriEgg();
	deck->add(t, NigiriEggCount);
	t = new NigiriSquid;
	deck->add(new NigiriSquid(), NigiriSquidCount);
	t = new NigiriSalmon();
	deck->add(t, NigiriSalmonCount);
	t = new MakiRoll2();
	deck->add(new MakiRoll2(), MakiRoll2Count)->add(new MakiRoll3(), MakiRoll3Count)->add(new MakiRoll1(), MakiRoll1Count);
	deck->add(new Dumpling(), DumplingCount);
	*/
	for (int i = 0; i < TempuraCount; i++)
		deck->add(new Tempura());
	for (int i = 0; i < SashimiCount; i++)
		deck->add(new Sashimi());
	for (int i = 0; i < NigiriEggCount; i++)
		deck->add(new NigiriEgg());
	for (int i = 0; i < NigiriSquidCount; i++)
		deck->add(new NigiriSquid());
	for (int i = 0; i < NigiriSalmonCount; i++)
		deck->add(new NigiriSalmon());
	for (int i = 0; i < MakiRoll1Count; i++)
		deck->add(new MakiRoll1());
	for (int i = 0; i < MakiRoll2Count; i++)
		deck->add(new MakiRoll2());
	for (int i = 0; i < MakiRoll3Count; i++)
		deck->add(new MakiRoll3());
}
void test()
// External test function
{
	CardCollection g1, g2;
	g1.add(new Dumpling(), 5)->add(new Tempura(), 2);
	g2.add(new MakiRoll2(), 3)->add(new NigiriSalmon(), 3);
	std::cout << "\n" << g1.calculate(&g1, &g2) << " " << g2.calculate(&g2, &g1);
}
void Game::progress(std::vector<int>& this_score, std::vector<int>& other_score)
{
	std::cout << "\n";
	std::cout << "~~~ round " << round << '/' << MAX_ROUNDS << " ~~~" << std::endl;
	// Keep looping until size of hand is empty
	while (1)
	{
		std::cout << "PLAYER " << currentPlayer->toString() << " TURN\n";
		std::cout << "Tableau:\n";
		currentPlayer->printTableau();
		printPlayerCards(currentPlayer);
		askForCard(currentPlayer);

		currentPlayer = currentPlayer->getNext(); // Advance to the other player

		std::cout << "PLAYER " << currentPlayer->toString() << " TURN\n";
		std::cout << "Tableau:\n";
		currentPlayer->printTableau();
		printPlayerCards(currentPlayer);
		askForCard(currentPlayer);

		currentPlayer = currentPlayer->getNext();

		swapHands(currentPlayer, currentPlayer->getNext()); // Once both players have picked their cards, swap the hands

		if ((currentPlayer->getHand()->size() < 1) || (currentPlayer->getNext()->getHand()->size() < 1))
			break;
	}
	std::cout << "~~~ end of round scoring ~~~\n";
	int ts = currentPlayer->calculateScore();
	int os = currentPlayer->getNext()->calculateScore();
	std::cout << "\tPLAYER " << currentPlayer->toString() << " round score: " << ts << "\n";
	std::cout << "\tPLAYER " << currentPlayer->getNext()->toString() << " round score: " << os << "\n";
	round++;
	// Add this round's score to each player
	this_score.push_back(ts);
	other_score.push_back(os);
}
void Game::begin()
{
	printLogo();
	std::vector<int> this_score, other_score; // Since each rounds require distinct scoring number, vetor remembers each round score and adds up to final player score
	round = 1;
	// test();
	for (int i = 0; i < MAX_ROUNDS; i++)
	{
		// Split the first 10 cards from deck to each players
		splitCards(currentPlayer);
		splitCards(currentPlayer->getNext());
		// Clearing tableau, freeing card pointer memory
		currentPlayer->getTableau()->clear();
		currentPlayer->getNext()->getTableau()->clear();
		// Progress the round
		progress(this_score, other_score);
	}
	std::cout << "~~~ End of game! ~~~\n";
	// Add up player final score from vector score
	int ts = 0, os = 0;
	for (int i = 0; i < this_score.size(); i++)
		ts += this_score[i];
	for (int i = 0; i < other_score.size(); i++)
		os += other_score[i];
	std::cout << "\tPLAYER " << currentPlayer->toString() << " final score: " << ts << "\n";
	std::cout << "\tPLAYER " << currentPlayer->getNext()->toString() << " final score: " << os << "\n";
	currentPlayer->setScore(ts);
	currentPlayer->getNext()->setScore(os);
	if (ts == os)
		std::cout << "GAME TIE!";
	else if (ts > os)
		std::cout << "PLAYER " << currentPlayer->toString() << " WINS!";
	else
		std::cout << "PLAYER " << currentPlayer->getNext()->toString() << " WINS!";
}
void Game::splitCards(Player* p)
// Split first 10 cards to player's hand
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
// Get input from user, from [1,maxRange]
{
	int res = 0;
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::stringstream ss(line);
		if (ss >> res)
			if (ss.eof())
				if (res > 0 && res <= maxRange)
					break;
	}
	return res;
}
void Game::askForCard(Player* p)
{
	std::cout << "Select a card to add to your tableau:\n";
	int inp = getInput(p->getHand()->size());
	p->addCardsToTableau(p->getHand()->getCard(inp - 1)); // Since input received from user ranges [1,maxRange], subtracting by 1 corresponds to card's index in vector
}
void Game::swapHands(Player* p1, Player* p2)
{
	CardCollection* t = p1->getHand();
	p1->setHand(p2->getHand());
	p2->setHand(t);
}