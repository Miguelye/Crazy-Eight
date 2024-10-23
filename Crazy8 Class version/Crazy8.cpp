#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "Crazy8.h"
#include "Stack.h"
#include "Card.h"
#include "MatchHeader.h"
#include "Crazy8Player.h"
#include "Player.h"
#include "StackCreation.h"

using namespace std;

void Crazy8::run() 
{
    cout << "\n Unpacking cards...";
    cout << "\n Setting table...";
    cout << "\n You should probably grab some snacks";
    cout << "\n Ready?... okay!\n";

    string name;
    int AIPlayers;
    cout << "\nWhat is your name?: ";
    cin >> name;
    players.push_back(new Crazy8Player(name, true));

    if (name == "Ahmet")
    {
        std::cout << "Hello, Ahmet. "
            << "I apologize for the late submussion, I hope you enjoy this game.\n";
    }
    do 
    {
        std::cout << "\nHow many AI players would you like? (1 to 4): ";
        std::cin >> AIPlayers;

        if (AIPlayers < 1 || AIPlayers > 4) {
            std::cout << "****Invalid number of AI Entered****" << "Please try again\n";
        }
    } while (AIPlayers < 1 || AIPlayers > 4);

    setPlayerNum(AIPlayers);

    cout << "Player taking their seats...\n";

    createStack();

    cout << "Created and shuffled deck ...\n";

    dealCards(5);

    cout << "Hands dealt...\n";

    cout << getDrawStack()->getSize() << endl;

    cout << "\n****Starting Game****\n";
    getDiscardStack()->grabCard(getDrawStack(), getDrawStack()->getTopCard());

    do 
    {
        round();
    } while (!isWinner);
    cout << "\n*******Thanks for playing!!!*********";
}

void Crazy8::round() {
    for (auto PlayerDummy : getPlayers()) 
    {
        cout << "\n\n*****" << PlayerDummy->getName() << "'s turn*****\n" << PlayerDummy->getNumOfCards() << " cards left\nDiscard Stack Card: " << getDiscardStack()->getTopCard()->getName() << std::endl;

        takeTurn(PlayerDummy);

        if (PlayerDummy->getNumOfCards() == 0) 
        {
            isWinner = true;
            cout << "\n" << PlayerDummy->getName() << " IS THE WINNER!\n";
            break;
        }
    }
}

void Crazy8::takeTurn(Player* PlayerDummy) 
{
    if (PlayerDummy->getIsHuman()) 
    {
        PlayerTurn(PlayerDummy);
    }
    else {
        AITurn(PlayerDummy);
    }
}

void Crazy8::AITurn(Player* PlayerDummy) 
{
    bool playedCard = false;
    for (auto CardDummy : PlayerDummy->getHand()->getCards()) 
    {
        if (getDiscardStack()->getTopCard()->matches(CardDummy)) 
        {
            PlayerDummy->getHand()->PlayCard(getDiscardStack(), CardDummy);
            std::cout << PlayerDummy->getName() << " played " << CardDummy->getName();
            playedCard = true;
            break;
        }
    }
    if (!(playedCard))
        drawCards(PlayerDummy);
}

void Crazy8::PlayerTurn(Player* PlayerDummy) 
{
    char cardSuit;
    string input;
    int cardRank;
    bool IsPlayed = false;
    bool cardInHand = false;
    bool IsPlayable = false;
    do 
    {
        cout << "****Your Hand****\n" << PlayerDummy->getHand()->displayHand()
            << "\nEnter the card to play (as it is shown in your hand) or type 'draw': ";
        cin >> input;
        input += " ";

        if (input == "draw ") 
        {
            IsPlayed = true;
            cardInHand = true;
            IsPlayable = true;
            drawCards(PlayerDummy);
        }
        else if (input.length() != 2 && input.length() != 3)
        {
            cout << "***ERROR, input is isvalid, please try again, type as it's shown***\n";
            continue;
        }
        else 
        {
            cardSuit = input[0];
            cardRank = returnCardRank(input.substr(1, 2));

            if (PlayerDummy->getHand()->CheckCard(cardRank, cardSuit) == nullptr) 
            {
                cout << "The card is not on hand, try again.\n";
            }
            else 
            {
                cardInHand = true;
                Match* selectedCard = static_cast<Match*>(PlayerDummy->getHand()->CheckCard(cardRank, cardSuit));

                if (!(getDiscardStack()->getTopCard()->matches(selectedCard))) 
                {
                    IsPlayable = false;
                    cout << "Card unable to be played! Please try again!\n";
                }
                else 
                {
                    IsPlayable = true;
                    PlayerDummy->getHand()->PlayCard(getDiscardStack(), selectedCard);
                    cout << PlayerDummy->getName() << " played " << selectedCard->getName() << endl;
                    IsPlayed = true;
                    selectedCard = nullptr;
                }
            }
        }
    } while (!IsPlayable || IsPlayed == false || !cardInHand);
}

int Crazy8::returnCardRank(std::string StringParam) 
{
    if (StringParam == "k ")
        return 13;
    else if (StringParam == "q ")
        return 12;
    else if (StringParam == "j ")
        return 11;
    else if (StringParam == "a ")
        return 1;
    else
        return stoi(StringParam);
}

void Crazy8::recycleStack() 
{
    while (!getDiscardStack()->isEmpty()) 
    {
        getDrawStack()->grabCard(getDiscardStack(), getDiscardStack()->getTopCard());
    }
    getDrawStack()->shuffle();
}

void Crazy8::drawCards(Player* PlayerDummy) 
{
    bool IsCardPlayed = false;
    for (size_t i = 0; i < 3; i++) 
    {
        Match* topCard;
        topCard = static_cast<Match*>(getDrawStack()->getTopCard());

        cout << "\nDrew a " << topCard->getName() << endl;

        PlayerDummy->drawCard(getDrawStack());
        if (getDrawStack()->isEmpty())
        {
            recycleStack();
        }

        if (topCard->matches(getDiscardStack()->getTopCard())) 
        {
            PlayerDummy->getHand()->PlayCard(getDiscardStack(), topCard);
            cout << "Played the " << topCard->getName() << endl;
            IsCardPlayed = true;
            break;
        }
        else 
        {
            cout << "Cannot play that card..." << endl;
            if (i < 2)
            {
                std::cout << "Drawing Another Card" << endl;
            }
        }
        topCard = nullptr;
    }
    if (!IsCardPlayed)
    {
        cout << "Cannot play any of the new cards, next player's turn" << endl;
    }
}

void Crazy8::createStack() 
{
    StackCreation* factory = nullptr;
    drawStack = factory->createStack(StackCreation::CRAZY8);
    discardStack = new Stack();
    getDrawStack()->shuffle();
}

void Crazy8::setPlayerNum(int p) 
{
    for (int i = 0; i < p; i++) 
    {
        players.push_back(new Crazy8Player("CPU" + std::to_string(i + 1), false));
    }
}

void Crazy8::dealCards(int numOfCards) 
{
    for (auto p : getPlayers())
    {
        p->drawCard(getDrawStack(), numOfCards);
    }
}