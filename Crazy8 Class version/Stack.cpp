#include <random>
#include <algorithm>
#include <iostream>
#include "Stack.h"
#include "Card.h"

using namespace std;

Card* Stack::getTopCard() 
{
  if (this -> isEmpty())
    cout << "No Cards In Stack";
  else
    return cards.back();
}

void Stack::shuffle() 
{
  std::random_device rd;
  std::shuffle(std::begin(cards), std::end(cards), rd);
}
