#include "game.h"
#include <iostream>
using namespace std;

//g++ -std=c++03 -o tic_tac_toe main.cpp board.cpp game.cpp player.cpp
//./tic_tac_toe

int main() {

    Game ticTacToe;
    ticTacToe.DisplayInstructions();
    char again;

    do 
    {
        ticTacToe.Play();
        cout << endl << "Play again? (y/n): ";
        cin >> again;
    } while(again != 'n');
    
    return 0; 
}
