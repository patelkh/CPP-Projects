#include <istream>
#include <iostream>
#include <iomanip>
#include "game.h"
using namespace std; 

Game::Game() : mEpisode("trivia.txt") {}; 

void Game::DisplayInstructions() {
    cout << "\tWelcome to Trivia Challenge!" << endl << endl; 
    cout << "Correctly answer as many questions as possible" << endl; 
    cout << "You earn 1,000 points for each question you answer correctly." << endl << endl; 
};

//get answer to trivia question
int Game::GetMenuResponse(int numChoices) {
    int response; 
    do {
        cout << "Enter your choice: ";
        cin >> response; 
    } while(cin.good() && (response < 1 || response > numChoices));

    if(cin.fail()) {
        cout << endl << "Good-bye!" << endl; 
        exit(1);
    }
    cout << endl; 
    return response;
};

int Game::AskQuestion(Question& question) {
    int response; 
    question.Ask(); 
    response = GetMenuResponse(Question::NUM_ANSWERS);
    return question.ScoreAnswer(response);
};

void Game::SendScore(ostream& os) {
    os << "Your final score is " << mScore << "." << endl; 
}

void Game::Play() {
    mScore = 0; 
    mEpisode.Introduce(); 
    //keep asking questions while there are more left
    while(mEpisode.isOn()) {
        Question question = mEpisode.NextQuestion();
        mScore += AskQuestion(question);
    };
    //display score
    SendScore(cout); 

    //write score
    ofstream scoreFile("trivia_score.txt", ios::out | ios::app); 
    SendScore(scoreFile);
    scoreFile.close(); 
}
