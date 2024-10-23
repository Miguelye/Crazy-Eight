#ifndef CRAZY8_H
#define CRAZY8_H

#include <string>
#include "Game.h"
#include "Stack.h"
#include "Crazy8Player.h"

class Crazy8 : public Game {
public:
	Crazy8() :Game() {}
	
	//Start the game
	void run();
	
	//Code for each round
	void round();

	//Code for the the current player turn
	void takeTurn(Player* p);

	//set the number of players before running game
	void setPlayerNum(int p);

	//This is the code for the AI
	void AITurn(Player* p);

	//Code for the Human Player Turn
	void PlayerTurn(Player* p);

	//Draw the cards.
	void drawCards(Player* p);

	//Create the Stack of the deck as well has the discard card.
	void createStack();

	//Deal the cards of on the beginning of the game
	void dealCards(int numOfCards);

	//Return value of card as an int
	int returnCardRank(std::string s);

	//Code for when stack runs out of cards, creating a new stack
	void recycleStack();
};

#endif
