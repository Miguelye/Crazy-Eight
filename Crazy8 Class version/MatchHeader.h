#pragma once
#ifndef MATCHHEADER_H
#define MATCHHEADER_H

#include "PlayingCard.h"

class Match : public PlayingCard {
public:

	Match(int face, char suit) : PlayingCard(face, suit) {}

	bool matches(Card* c);
};

#endif
