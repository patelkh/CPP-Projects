#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; 

int main() {
    srand(static_cast<unsigned int>(time(0)));
    const int NUM_WORDS = 5; 
    const string WORDS[NUM_WORDS] = {
        "guest",
        "midnight",
        "freedom",
        "diamond",
        "airport"
    }; 

    int choice = (rand() % NUM_WORDS);
    string secretWord = WORDS[choice]; 
    string jumbled = secretWord; 
    size_t length = jumbled.size(); 
    //mix up letters in jumbled
    for (size_t i = 0; i<length; ++i) {
        size_t randomIndex = (rand() % length);
        char temp = jumbled[i];
        jumbled[i] = jumbled[randomIndex];
        jumbled[randomIndex] = temp; 
    }

    //start the game
    cout << "\tWelcome to Word Jumble!" << endl << endl;
    cout << "Unscamble the letters to make a word." << endl;
    cout << "Enter 'quit' to quit the game." << endl << endl; 

    //guessing loop 
    string guess; 
    do {
        cout << "The jumble is: " << jumbled;
        cout << endl << endl << "Your guess: "; 
        cin >> guess; 
        if ((guess != secretWord) && (guess != "quit")) {
            cout << "Sorry, that's not it." << endl << endl;
        }
    } while ((guess != secretWord) && (guess != "quit"));

    //end the game 
    if (guess == secretWord) {
        cout << endl << "That's it! You guessed it!"; 
    }
    cout  << endl << "Thanks for playing!" << endl << endl; 
    return 0; 
}