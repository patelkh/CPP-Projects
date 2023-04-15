#include "question.h"
#include <string>
#include <istream>
#include <fstream>
#include <iostream>
using namespace std; 

const string Question::CORRECT = "Correct!";
const string Question::WRONG = "Wrong!";

Question::Question(istream& episodeFile) {
    getline(episodeFile, mQuestion);
    for(int i=0; i<NUM_ANSWERS; i++) {
        getline(episodeFile, mAnswers[i]);
    };
    episodeFile >> mCorrectAnswer; 
    episodeFile.ignore();
};

void Question::Ask() {
    cout << "Question: " << mQuestion << endl; 
    for(int i=0; i<NUM_ANSWERS; i++) {
        cout << i+1 << " - " << mAnswers[i] << endl;
    };
}

int Question::ScoreAnswer(int answer) {
    int score =0; 
    if(answer == mCorrectAnswer) {
        cout << CORRECT << endl << endl;
        score = POINTS;
    } else {
        cout << WRONG << endl << endl;
    }
    return score;
}

