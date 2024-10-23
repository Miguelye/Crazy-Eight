#include "Game.h"
#include "Player.h"
#include "Stack.h"
#include <string>
#include <vector>
#include <random>

Game::~Game() 
{
    for (Player* player : players) 
    {
        delete player;
        player = nullptr;
    }

    delete drawStack;
    delete discardStack;
}

void Game::deal(int n) 
{
    for (auto player : players)
    {
        player->drawCard(drawStack, n);

    }
}

void Game::currentTurn() 
{
    // Increments the turn depending on turn order
    if (!reversedTurnOrder) 
    {
        turn += 1;
    }
    else 
    {
        turn -= 1;
    }
    // Trying to get math mod
    turn = ((turn) % getNumOfPlayers() + getNumOfPlayers()) % getNumOfPlayers();
}


int Game::getNumOfPlayers() 
{
    return players.size();
}

Stack* Game::getDrawStack() 
{
    return drawStack;
}

Stack* Game::getDiscardStack() 
{
    return discardStack;
}

int Game::getTurn() 
{
    return turn;
}

std::string Game::displayPlayers() 
{
    std::string output = "*";
    for (size_t i = 0; i < players.size(); i++) 
    {
        output += players[i]->getName();
        output += "*";
    }

    return output;
}

std::vector<Player*> Game::getPlayers() {
    return players;
}
