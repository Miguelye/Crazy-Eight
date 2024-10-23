#pragma once
#ifndef STACK_H
#define STACK_H

#include "Deck.h"
#include <string>

class Stack : public Deck {
public:

	//Getter for top card of stack
	Card* getTopCard();

	//shuffle stack
	void shuffle();
};

#endif
