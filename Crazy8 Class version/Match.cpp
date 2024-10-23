#include "MatchHeader.h"

bool Match::matches(Card* c) {
    if (c->getRank() == this->getRank()
        || c->getSuit() == this->getSuit()
        || c->getRank() == 8
        || this->getRank() == 8) {
        return true;
    }
    else {
        return false;
    }
}
