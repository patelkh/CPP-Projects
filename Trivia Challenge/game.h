#ifndef GAME
#define GAME

#include <istream>
#include <iostream>
#include <iomanip>
#include "episode.h"

class Game {
    public: 
        Game();
        void DisplayInstructions(); 
        int GetMenuResponse(int numChoices);
        int AskQuestion(Question& question);
        void SendScore(ostream& os); 
        void Play(); 
    private: 
        Episode mEpisode;
        int mScore;

};

#endif