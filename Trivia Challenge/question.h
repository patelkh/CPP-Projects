#ifndef QUESTION
#define QUESTION
#include <string>
using namespace std;  

class Question {
    public: 
        static const int NUM_ANSWERS = 4; 
        Question(istream& episodeFile); 
        void Ask();
        int ScoreAnswer(int answer);
    private:
        static const string CORRECT; 
        static const string WRONG; 
        static const int POINTS = 1000; 
        string mQuestion;
        string mAnswers[NUM_ANSWERS]; 
        int mCorrectAnswer;
};


#endif