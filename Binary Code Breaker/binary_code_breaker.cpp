#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int main() {
    srand(static_cast<unsigned int>(time(0)));
    int MAX_LENGTH = 4; 
    string binary_string = "";

    //generate binary string 
    for(int i=0; i<MAX_LENGTH; i++) {
        int num = ((int)rand() % 2);
        binary_string += to_string(num); 
    }; 
    string guess; 
    int tries = 0; 
    cout << endl << "\tWelcome to the Binary Code Breaker!" << endl << endl;
    cout << "Guess the four-digit binary code (e.g., 1101)." << endl; 
    cout << "Enter 'quit' to quit the game." << endl; 
    
    do {
        cout << endl << "Enter a guess: ";
        getline(cin, guess);
        tries++;
        if ((guess != binary_string) && (guess != "quit")) {
            int matches = 0; 
            for(int i=0; i<MAX_LENGTH; ++i) {
                if (guess[i] == binary_string[i]) {
                    matches++; 
                };
            }
            cout << endl << "You matched " << matches << " out of " << MAX_LENGTH << " digits. Try again" << endl; 
        }
    } while (guess != binary_string && guess != "quit" && tries < 5);

    if (guess == binary_string) {
        cout << endl << endl << "That's it! You guessed it!!" << endl;
    }
    if (tries == 5) {
        cout << endl << "No more credits left, game over." << endl; 
    }
    cout << "Thank you for playing!" << endl << endl; 

    return 0;
}