//Implementation file for PlayingCardFactory class.

#include "StackCreation.h"
#include "Deck.h"
#include "Card.h"
#include "MatchHeader.h"
#include "Stack.h"
#include "Hand.h"
#include <iostream>

Stack* StackCreation::createStack(StackCreation::TYPE type) {
    Stack* newStack = new Stack;
    Card* c = nullptr;

    if (type == StackCreation::CRAZY8) {
        for (int i = 1; i < 14; i++)
            newStack->addCard(new Match(i, 'c'));

        for (int i = 1; i < 14; i++)
            newStack->addCard(new Match(i, 'd'));

        for (int i = 1; i < 14; i++)
            newStack->addCard(new Match(i, 'h'));

        for (int i = 1; i < 14; i++)
            newStack->addCard(new Match(i, 's'));

        return newStack;

    }
    else {
        return nullptr;
    }
}
