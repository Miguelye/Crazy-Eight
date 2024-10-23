#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
public:
	virtual ~Deck();

	//Code to add card to deck
	void addCard(Card* card);

	//Remove card form deck
	void removeCard(Card* card);

	//Grab Card from drack
	void grabCard(Deck* d, Card* card);

	//Getter for the size of the deck
	int getSize();

	//getter for cards in deck
	std::vector<Card*> getCards();

	//Check if deck is empty
	bool isEmpty();

protected:
	std::vector<Card*> cards;
};

#endif
