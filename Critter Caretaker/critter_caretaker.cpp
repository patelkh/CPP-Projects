#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std; 

class Critter {

    public: 
        //rectangle(int a, int b): length(a), breath(b) {. . . } The initialize list is placed between the parameters list and the opening brace of the body of the constructor. The list begins with the colon(:)and is separated by commas. Each initialize clause simply names the data members and in the parentheses lists the value to be used to initialize the data member.
        Critter(int hunger = 0, int bordem = 0):
            mHunger(hunger),
            mBordem(bordem) {}
        
        void Talk() {
            cout << "I'm a critter and I feel " << GetMood() << "." << endl; 
        };


        //reduces a critter's hunger level by the amount passed to the parameter food
        void Eat(int food = 5) {
            cout << "Brrupp." << endl; 
            mHunger -= food; 
            if(mHunger < 0) {
                mHunger = 0; 
            }
            PassTime(); 
        };


        //reduce a critter's bordem level by the amount passed to the parameter fun
        void Play(int fun = 5) {
            cout << "Wheee!" << endl; 
            if(mBordem < 0) {
                mBordem = 0; 
            }
            PassTime(); 
        };


        void PerformTrick() {
            if(GetMood() != "Happy") {
                cout << "I don't feel like doing a trick." << endl;
            } else {
                int choice = (rand() % NUM_TRICKS);
                string trick = TRICKS[choice];
                cout << "I " << trick << "." << endl; 
            }
            PassTime(); 
        }; 
    

    private: 
        enum Mood {Happy, OKAY = 5, FRUSTRATED = 10, MAD = 15 }; //mood levels
        static const int NUM_TRICKS = 3; 
        static const string TRICKS[NUM_TRICKS]; 

        //hunger and bordem levels; higher numbers mean a hungrier and more bored critter
        int mHunger; 
        int mBordem;

        string GetMood() {
            string mood; 
            if(mHunger + mBordem > MAD) {
                mood = "mad";
            } else if(mHunger + mBordem > FRUSTRATED) {
                mood = "frustrated";
            } else if(mHunger + mBordem > OKAY) {
                mood = "okay";
            } else {
                mood = "happy";
            }
            return mood; 
        }; 


        //increases critter's hunger and bordem levels
        void PassTime(int time = 1) {
            mHunger += time; 
            mBordem += time; 
        }; 

};

//tricks are stored once rather than having each Critter object store its own copies since all critters will be able to perform this set of tricks
const string Critter :: TRICKS[NUM_TRICKS] = {"roll over", "jump", "do a backflip"};

int main() {

    srand(static_cast<unsigned int>(time(0)));
    Critter crit; 

    int choice; 
    do
     {
        cout << endl << "Critter Caretaker" << endl;
        cout << "-----------------" << endl << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Listen to your critter" << endl;
        cout << "2 - Feed your critter" << endl;
        cout << "3 - Play with your critter" << endl;
        cout << "4 - Ask your critter to perform a trick." << endl << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "Good-bye." << endl;
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.PerformTrick();
            break;
        default:
            cout << endl << "Sorry, but " << choice; cout << " isn't a valid choice." << endl;
        }
    } while (choice != 0);


    return 0;
}