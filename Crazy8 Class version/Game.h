#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Stack.h"
#include <string>
#include <vector>

class Game {
public:
	Game() {}
	virtual ~Game();

	//Code that handles the run of the game
	virtual void run() = 0;

	//Deald with the rounds
	virtual void round() = 0;

	//Take turn
	virtual void takeTurn(Player* player) = 0;
	
	//Sets the number of player for the current game
	virtual void setPlayerNum(int players) = 0;

	//Keeps track of the players' turns
	void currentTurn();

	//Getter for numeros of player
	int getNumOfPlayers();

	//Getter for the stack
	Stack* getDrawStack();
	
	//Getter for the discard Stack
	Stack* getDiscardStack();

	//Getter for current turn
	std::vector<Player*> getPlayers();
	int getTurn();
	std::string displayPlayers();
	void deal(int n);

protected:
	Stack* drawStack = nullptr;
	Stack* discardStack = nullptr;
	bool reversedTurnOrder = false;
	std::vector<Player*> players;
	int turn = 0;
	bool isWinner = false;
};

#endif