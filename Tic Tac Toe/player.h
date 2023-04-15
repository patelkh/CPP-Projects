//ifndef checks whether the given token has been defined
//earlier in the file or in an included file; if not
//it includes the code between it and the closing #endif 
#ifndef PLAYER_H 
#define PLAYER_H

class Board; 

class Player {
    public: 
        Player();
        char GetPiece(); 
        void MakeMove(Board& aBoard);
    
    private: 
        static const int NUM_PIECE = 2; 
        static const char PIECES[NUM_PIECE]; 
        static int current;
        char mPiece; 
};


#endif