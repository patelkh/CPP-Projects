#include <istream>
#include <iostream>
#include <string>
#include "game.h"
using namespace std; 


//g++ -std=c++03 -o trivia-challenge main.cpp episode.cpp game.cpp question.cpp
//./trivia-challenge
int main() {

    Game trivia;
    trivia.DisplayInstructions();
    trivia.Play(); 

    return 0;
}