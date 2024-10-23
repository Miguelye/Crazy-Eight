#include <vector>
#include <iostream>
#include "Deck.h"
#include "Card.h"

using namespace std;
Deck::~Deck() 
{
    if (!cards.empty()) 
    {
        for (size_t i = 0; i < cards.size(); i++)
        {
            delete cards[i];
        }
        cards.clear();
    }
}

void Deck::addCard(Card* card) 
{
    cards.push_back(card);
}

void Deck::removeCard(Card* c) 
{

    // Check if card is actually in the deck before removing it
    bool exists = false;
    for (size_t i = 0; i < cards.size(); i++) 
    {
        if (cards[i] == c) 
        {
            exists = true;
            cards.erase(cards.begin() + i);
            break;
        }
    }
    if (exists == false)
    {
        cout << "Card not in deck\n";
    }
}

void Deck::grabCard(Deck* deck, Card* card) 
{
    deck->removeCard(card);
    this->addCard(card);
}

int Deck::getSize() 
{
    return cards.size();
}

std::vector<Card*> Deck::getCards() 
{
    return cards;
}

bool Deck::isEmpty() 
{
    return cards.empty();
}
