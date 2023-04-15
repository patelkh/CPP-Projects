#include "board.h"
#include <iostream>
using namespace std;

const int Board::WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO] = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6},
}; 

Board::Board() {
    Reset();
};

bool Board::isFull() {
    bool full = true;
    int i=0;
    while(full && i<NUM_SQUARES) {
        if(mSquares[i] == EMPTY) {
            full = false; 
        }
        i++;
    }
    return full; 
};

bool Board::isLegalMove(int move) {
    return (move >= 0 && move < NUM_SQUARES && mSquares[move] == EMPTY);
};

bool Board::isWinner(char piece) {
    bool winner = false;
    int i=0; 
    while(!winner && i< NUM_COMBOS) {
        int piecesInCombo = 0; 
        for(int j=0; j<NUM_IN_COMBO; ++j) {
            if(mSquares[WINNING_COMBOS[i][j]] == piece) {
                ++piecesInCombo;
            };
            if(piecesInCombo == NUM_IN_COMBO) {
                winner = true; 
            }
        }
        ++i; 
    }
    return winner; 
};

void Board::Display() {
    cout << endl << "\t" << mSquares[0] << " | " << mSquares[1];
     cout << " | " << mSquares[2];
     cout << endl << "\t" << "---------";
     cout << endl << "\t" << mSquares[3] << " | " << mSquares[4];
     cout << " | " << mSquares[5];
     cout << endl << "\t" << "---------";
     cout << endl << "\t" << mSquares[6] << " | " << mSquares[7];
     cout << " | "  << mSquares[8];
     cout << endl << endl;
};

void Board::Reset() {
    for(int i=0; i<NUM_SQUARES; i++) {
        mSquares[i] = EMPTY; 
    }
}

void Board::ReceiveMove(char piece, int move) {
    mSquares[move] = piece; 
}