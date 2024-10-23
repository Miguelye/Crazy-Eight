#include "Card.h"
#include <iostream>

Card::Card(int rank, char suit) : rank{ rank }, suit{ suit } {}

char Card::getSuit() const {
	return suit;
}

int Card::getRank() const {
	return rank;
}
