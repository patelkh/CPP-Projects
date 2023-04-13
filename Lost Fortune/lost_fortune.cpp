#include <iostream>
#include <string>
using namespace std;

int main() { 
    const int gold_pieces = 900;
    string leader;
    int adventurers;
    int killed;

    //get values from user
    cout << endl;  
    cout << "\tWelcome to Lost Fortune" << endl << endl;
    cout << "Please enter the following for a personalized adventure:" << endl;
    
    cout << "Enter your last name: ";
    cin >> leader;
    
    cout << "Enter a positive number: ";
    cin >> adventurers;

    cout << "Enter a positive number, less than the first: ";
    cin >> killed; 

    //calculate new values
    int survivors = adventurers - killed;
    int extraGoldPieces = gold_pieces % survivors; 

    //tell the story 
    cout << endl; 
    cout << "The brave " << leader << " led a group of adventurers on a quest. " << endl; cout << "They fought a band of ogres and lost " << killed << ". " << survivors << " survived!" << endl;
    cout << "The party was about to give up when they stumbled upon" << endl; 
    cout << "a buried fortune of " << gold_pieces << " gold pieces. They split the loot" << endl;
    cout << "and " << leader << " kept the extra " << extraGoldPieces << " gold pieces to keep things fair." << endl << endl;
}