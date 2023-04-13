#include <iostream>
#include <string>
using namespace std; 

void welcomePlayer() {
    cout << endl << "\tWelcome to Mad Libs!" << endl << endl; 
    cout << "Please provide the following to help create a new story." << endl; 
};

string getText(const string& prompt) {
    string text; 
    cout << prompt; 
    cin >> text; 
    return text; 
};

int getNumber(const string& prompt = "Enter a number: ") {
    int num; 
    cout << prompt;
    cin >> num; 
    return num; 

};

void tellStory(const string& aName,
                const string& aNoun,
                int aNumber,
                const string& aBodyPart,
                const string& aVerb) {
    cout << endl << "Here's your story:" << endl << endl;
    cout << "The famous explorer ";
    cout << aName;
    cout << " had nearly given up a life-long quest to find" << endl;
    cout << "The Lost City of ";
    cout << aNoun;
    cout << " when one day, the ";
    cout << aNoun;
    cout << " found the explorer." << endl;
    cout << "Surrounded by ";
    cout << aNumber;
    cout << " " << aNoun;
    cout << ", a tear came to ";
    cout << aName << "'s ";
    cout << aBodyPart << "." << endl;
    cout << "After all this time, the quest was finally over. ";
    cout << "And then, the ";
    cout << aNoun << endl;
    cout << "promptly devoured ";
    cout << aName << ". ";
    cout << "The moral of the story? Be careful what you "; cout << aVerb;
    cout << " for." << endl << endl;
    }


int main() {

    welcomePlayer();
    
    string name = getText("Enter a name: ");
    string noun = getText("Enter a plural name: ");
    int number = getNumber(); 
    string bodyPart = getText("Enter a body part: ");
    string verb = getText("Enter a verb: "); 

    tellStory(name, noun, number, bodyPart, verb);

    return 0; 
}