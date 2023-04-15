#ifndef EPISODE
#define EPISODE

#include "question.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std; 

class Episode {
    public:
        Episode(const string& filename);
        void Introduce();
        bool isOn(); 
        Question NextQuestion(); 
    private:
        string mName;
        ifstream mEpisodeFile; 
};


#endif 