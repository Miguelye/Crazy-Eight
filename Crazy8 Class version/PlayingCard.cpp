#include <string>
#include "PlayingCard.h"
#include <iostream>

using namespace std;


PlayingCard::PlayingCard(int rank, char suit) : Card(rank, suit) 
{
    if (suit != 'c' && suit != 'd' && suit != 'h' && suit != 's')
    {
        cout << "****Invalid Suit Value****";
    }
    else if (rank > 13 || rank < 1)
    {
        cout << "****Invalid Rank Value*****";
    }
}

std::string PlayingCard::getSuitStr() 
{
  std::string suit;
  switch (getSuit()) 
  {
    case 'c':
      suit = "clubs";
      break;
    case 'h':
      suit = "hearts";
      break;
    case 'd':
      suit = "diamonds";
      break;
    case 's':
      suit = "spades";
      break;
    default:
        cout << "ERROR";
      break;
  }
  return suit;
}

std::string PlayingCard::getRankStr() {
  std::string face;
  switch (getRank()) {
    case 1:
      face = "ace";
      break;
    case 2:
      face = "two";
      break;
    case 3:
      face = "three";
      break;
    case 4:
      face = "four";
      break;
    case 5:
      face = "five";
      break;
    case 6:
      face = "six";
      break;
    case 7:
      face = "seven";
      break;
    case 8:
      face = "eight";
      break;
    case 9:
      face = "nine";
      break;
    case 10:
      face = "ten";
      break;
    case 11:
      face = "jack";
      break;
    case 12:
      face = "queen";
      break;
    case 13:
      face = "king";
      break;
    default:
        cout << "ERROR";
      break;
  }
  return face;
}

std::string PlayingCard::getName() 
{
  return (getRankStr() + " of " + getSuitStr());
}

std::string PlayingCard::getAbbreName() 
{
  std::string output;
  output += getSuit();

  switch (getRank()) 
  {
    case 1:
      output += 'a';
      break;
    case 11:
      output += 'j';
      break;
    case 12:
      output += 'q';
      break;
    case 13:
      output += 'k';
      break;
    default:
      output += std::to_string(getRank());
  }
  return output;
}
