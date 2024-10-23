#ifndef CARD_H
#define CARD_H

#include <string>
#include "Exceptions.h"

using namespace std;

class Card {
public:
	Card(int rank, char suit);
	~Card() {}

	//Getter return char data of suit
	char getSuit() const;

	//Getter return chat data of rank
	int getRank() const;
	
	//Getter return string of suit
	virtual string getSuitStr() = 0;

	//Getter return string data of rank
	virtual string getRankStr() = 0;

	//Getter return string of card info
	virtual string getName() = 0;

	//Getter return string data of card info (abbreviation)
	virtual string getAbbreName() = 0;

	//Check card match
	virtual bool matches(Card* c) = 0;

protected:
	const int rank;
	const char suit;
};

#endif
