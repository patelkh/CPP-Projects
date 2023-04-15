#include "player.h"
#include "board.h"
#include <iostream>
using namespace std; 

const char Player :: PIECES[NUM_PIECE] = {'X', 'O'};
int Player :: current = 0;

Player::Player() {
    mPiece = PIECES[current];
    current = (current+1) % NUM_PIECE; 
}

char Player::GetPiece() {
    return mPiece; 
}

void Player::MakeMove(Board& aBoard) {
    int move; 
    do {
        cout << "Player " << GetPiece();
        cout << ", where would you like to move? (0-8): ";
        cin >> move; 
    } while(!aBoard.isLegalMove(move));

    aBoard.ReceiveMove(GetPiece(), move);
}