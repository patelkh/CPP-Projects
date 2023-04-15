#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game {
    public: 
        Game();
        bool isPlaying();
        bool isTie();
        void DisplayInstructions();
        void NextPlayer();
        void AnnounceWinner();
        void Play();
    
    private: 
        static const int NUM_PLAYERS = 2;
        static const int FIRST = 0;
        static const int SECOND = 1; 

        Board mBoard;
        Player mPlayers[NUM_PLAYERS];
        int mCurrent; 

};


#endif 