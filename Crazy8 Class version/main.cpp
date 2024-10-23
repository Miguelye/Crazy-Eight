#include <iostream>
#include "Game.h"
#include "Crazy8.h"

using namespace std;
void Opening();

int main() {

    Opening();
    char CheckPlay;

    cout << "Do you wish to play? (Y or N): ";
    cin >> CheckPlay;

    while (CheckPlay != 'Y' && CheckPlay != 'N')
    {
        cout << "Enter Y or N: ";
        cin >> CheckPlay;
        cout << endl;
    }

    Game* game = nullptr;


    if (CheckPlay == 'N')
        return 0;
    else
    {
        cout << "Let's play!!\n";
        game = new Crazy8();

    }
    game->run();

    return 0;
}

void Opening(void)
{
    cout << "     .-~~-.               /\\                   /\\                 .-~~~-__-~~~-." << endl;
    cout << "    {      }            .'  `.               .'  `.              {              }" << endl;
    cout << " .-~-.    .-~-.        '      `.            '      `.             `.          .'" << endl;
    cout << "{              }     <          >        .'          `.             `.      .'" << endl;
    cout << " `.__.'||`.__.'*      `.      .'        {              }              `.  .'" << endl;
    cout << "       ||               `.  .'           ~-...-||-...-~                 \\/" << endl;
    cout << "      '--`                \\/                   ||" << endl;
    cout << "                                              '--`" << endl;
    cout << "********************************* WELCOME TO CRAZY 8 ***********************************\n\n";
    cout << "The goal is to be the first player to get rid of all the cards in your hand.\n\n";
    cout << "*******CARD VALUES/SCORING*******\n\n";
    cout << "The player who is the first to have no cards left wins the game. There is a special card as well\n";
    cout << "The special cards effects i:\n";
    cout << "Rank: 8         Suit:Any = can be played onto any card.\n";
    cout << "*******THE RULES*******\n";
    cout << "If you do not have a play, draw 3 cards and if one still do not have a play, the player will end his turn\n\n";
}