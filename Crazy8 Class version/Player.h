#ifndef PLAYER_H
#define PLAYER_H

#include "Deck.h"
#include "Stack.h"
#include "Hand.h"
#include <string>

class Player {
public:
	Player(std::string name, bool isHuman);
	virtual ~Player();


	//Draw from top of Stack
	void drawCard(Stack* d);
	
	//Draw more than one card
	void drawCard(Stack* d, int numb);
	
	//getter for hand
	Hand* getHand();
	
	//Getter for number of hands
	int getNumOfCards();
	
	//Getter for name
	std::string getName();
	
	//Check is human
	bool getIsHuman();

protected:
	Hand* hand;
	bool isHuman;
	std::string name;
};

#endif