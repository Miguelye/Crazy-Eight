#ifndef PLAYINGCARD_H
#define PLAYINGCARD_H

#include <string>
#include "Card.h"

const int MAX_NUM_SUITS = 4;
const int MAX_NUM_RANKS = 13;

class PlayingCard : public Card {
public:
    
    //Logic for playing card
    PlayingCard(int face, char suit);

    //getter
    std::string getSuitStr();

    std::string getRankStr();

    std::string getName();

    std::string getAbbreName();

    virtual bool matches(Card* c) {
        return true;
    }
};

#endif
