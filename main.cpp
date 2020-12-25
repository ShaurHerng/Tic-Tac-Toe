// =================================================================================================
//
// Shaur Herng
//
// 21/12/2020
//
// Tic-Tac-Toe:
//      Expandable board X by X (square), X by Y (rectangle)
//      AI
//          With varying difficulties
//      User Interface :: Graphics
//      Using a database to store stats and scores of players (names, num of wins, opponents list)
//          Using online databases
//      Allow for multiple players
//
// ==================================================================================================


#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include "ttt.h"
using namespace std;



int main()
{
    int width;
    int height;
    int numPlayers;
    int winLen;

    cout << "Enter width, height, numPlayers, winLen: ";
    cin >> width >> height >> numPlayers >> winLen;


    TTT *game = new TTT(width, height, numPlayers, winLen);

    delete game;

    return 0;

}