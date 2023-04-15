#include "game.h"
#include <iostream>
#include <string>
using namespace std; 

Game::Game() : mCurrent(FIRST) {}; 


bool Game::isPlaying() {
    return(!mBoard.isFull() && 
            !mBoard.isWinner(mPlayers[FIRST].GetPiece()) &&
            !mBoard.isWinner(mPlayers[SECOND].GetPiece()));
};

bool Game::isTie() {
    return(mBoard.isFull() &&
            !mBoard.isWinner(mPlayers[FIRST].GetPiece()) &&
            !mBoard.isWinner(mPlayers[SECOND].GetPiece()));
};

void Game::DisplayInstructions() {
    cout << "\tWelcome to the ultimate intellectual showdown: Tic-Tac-Toe."; 
    cout << endl << endl;
    cout << "Make your move by entering a number, 0 - 8.  The number" << endl;
    cout << "corresponds with board position, as illustrated:" << endl << endl;
    cout << endl << "\t" << "0 | 1 | 2";
    cout << endl << "\t" << "---------";
    cout << endl << "\t" << "3 | 4 | 5";
    cout << endl << "\t" << "---------";
    cout << endl << "\t" << "6 | 7 | 8";
    cout << endl << endl << "Prepare yourself. The battle is about to begin.";
    cout << endl << endl;
}; 

void Game::NextPlayer() {
    mCurrent = (mCurrent+1) % NUM_PLAYERS; 
}

void Game::AnnounceWinner() {
    cout << "The raging battle has come to a final end." << endl; 
    if(isTie()) {
        cout << "Sadly, no player emerged victorious." <<endl << endl; 
    } else {
        cout << "The winner of this climatic confrontation is Player "; 
        if(mBoard.isWinner(mPlayers[FIRST].GetPiece())) {
            cout << mPlayers[FIRST].GetPiece() << "!" << endl; 
        } else {
            cout << mPlayers[SECOND].GetPiece() << "!" << endl; 
        };
    }
};

void Game::Play() {
    mCurrent = FIRST; 
    mBoard.Reset();

    while(isPlaying()) {
        mBoard.Display();
        mPlayers[mCurrent].MakeMove(mBoard);
        NextPlayer(); 
    }
    mBoard.Display();
    AnnounceWinner(); 
}