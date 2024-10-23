#ifndef HAND_H
#define HAND_H

#include <string>
#include "Deck.h"
#include "Stack.h"

class Hand : public Deck {
public:

	//Show card hand
	std::string displayHand();

	//Check if selected card is a match (rank)
	Card* CheckRank(int rank);

	//Check if selected card is a match (suit)
	Card* CheckSuit(char suit);

	//Check if both the rank and suit matches
	Card* CheckCard(int rank, char suit);
	
	//if Card matches, play the card.
	void PlayCard(Stack* p, Card* c);

	//check if hand is empty
	void checkEmptyHand();
};

//Function that helps to sort hand cards.
bool SortCard(Card* a, Card* b);

#endif