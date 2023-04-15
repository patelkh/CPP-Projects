#include "episode.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std; 

Episode::Episode(const string& filename) {
    //attempts to open the file with the episode
    mEpisodeFile.open(filename.c_str(), ios::in);

    if(mEpisodeFile.fail()){
        cout << "File " << filename << " failed to open." << endl; 
        exit(1);
    };
    //read episode file
    getline(mEpisodeFile, mName);
};

void Episode::Introduce() {
    cout << "Get ready to play..." << mName << endl << endl;
}

bool Episode::isOn() {
    return mEpisodeFile.good(); 
}

Question Episode::NextQuestion() {
    return Question(mEpisodeFile);
}