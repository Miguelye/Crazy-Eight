#include <algorithm>
#include <string>
#include <random>
#include <iostream>
#include "Hand.h"
#include "Stack.h"
#include "Card.h"

using namespace std;

bool SortCard(Card* a, Card* b) 
{
    if (a->getSuit() > b->getSuit())
    {
        return false;
    }
    else if (a->getSuit() < b->getSuit())
    {
        return true;
    }
    else
    {
        return(a->getRank() < b->getRank());
    }
}

string Hand::displayHand() 
{
    sort(cards.begin(), cards.end(), SortCard);
    string output;

    output += '*';
    for (auto card : cards)
        output += card->getAbbreName() + '*';

    return output;
}

Card* Hand::CheckRank(int rank) 
{
    for (size_t i = 0; i < cards.size(); i++) 
    {
        if (cards[i]->getRank() == rank)
            return cards[i];
    }

    return nullptr;
}

Card* Hand::CheckSuit(char suit) 
{
    for (size_t i = 0; i < cards.size(); i++) 
    {
        if (cards[i]->getSuit() == suit) 
        {
            return cards[i];
        }
    }
    return nullptr;
}

Card* Hand::CheckCard(int rank, char suit) 
{
    for (int i = 0; i < cards.size(); i++) 
    {
        if ((cards[i]->getRank() == rank) && (cards[i]->getSuit() == suit))
        {
            return cards[i];
        }
    }
    return nullptr;
}

void Hand::PlayCard(Stack* player, Card* card) 
{
    checkEmptyHand();

    // Check if card properly was placed

    bool exists = false;
    for (auto card : cards) 
    {
        if (card == card) 
        {
            exists = true;
            break;
        }
    }
    if (!exists) 
    {
        cout << "Card does not exist in hand";
    }

    player->addCard(card);
    removeCard(card);
}

void Hand::checkEmptyHand() 
{
    if (this->isEmpty())
    {
        cout << "No cards in hand";
    }
}
