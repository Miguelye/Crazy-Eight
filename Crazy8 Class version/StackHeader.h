#pragma once

#ifndef STACKHEADER_H
#define STACKHEADER_H

#include "DeckHeader.h"
#include <string>

class Pile : public Deck {
public:
    /**
    * @return the top card from deck
    */
    Card* getTopCard();
    /**
    * Shuffles this deck
    */
    void shuffle();
};

#endif