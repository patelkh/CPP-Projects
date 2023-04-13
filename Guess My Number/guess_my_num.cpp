#include <iostream>
#include <cstdlib> //helps generate a random number 
#include <ctime>   //handles date and time 
using namespace std; 

int main() {
    //seed rand num generator based on current time
    srand(static_cast<unsigned int>(time(0)));

    //max possible secret number
    const int MAX_NUMBER = 100;

    //rand num between 1-100
    int secretNumber = (rand() % MAX_NUMBER) + 1; 

    int tries = 0;
    int guess; 

    cout << "\tWelcome to Guess My Number" << endl << endl;
    cout << "Guess my secret number between 1 and " << MAX_NUMBER << "." << endl;
    
    //guessing loop 
    do {
        cout << "Enter a guess: ";
        cin >> guess; 
        ++tries;
        if(guess > secretNumber) {
            cout << "Too high!" << endl << endl;
        }
        if (guess < secretNumber) {
            cout << "Too low!" << endl << endl;
        }
    } while(guess != secretNumber);

    //end the game
    cout << endl;
    cout << "You win! You got it in " << tries << " tries!" << endl; 

    return 0;

}