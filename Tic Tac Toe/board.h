#ifndef BOARD_H
#define BOARD_H

class Board {
    public: 
        Board();
        bool isFull();
        bool isLegalMove(int move);
        bool isWinner(char piece);
        void Display();
        void Reset();
        void ReceiveMove(char piece, int move);

        static const int NUM_SQUARES = 9; 
        static const char EMPTY = ' '; 
    
    private: 
        static const int NUM_COMBOS = 8; 
        static const int NUM_IN_COMBO = 3; 
        static const int WINNING_COMBOS[NUM_COMBOS][NUM_IN_COMBO];
        char mSquares[NUM_SQUARES];
};


#endif