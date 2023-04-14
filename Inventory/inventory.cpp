#include <iostream>
#include <string>
using namespace std; 

bool isEmpty(const string* container[], int capacity) {
    bool empty = true; 
    int i=0; 
    while(empty && i<capacity) {
        if(container[i] != NULL) {
            empty = false; 
        }
        i++;
    }
    return empty; 
}

bool isFull(const string* container[], int capacity) {
    bool full = true; 
    int i=0;
    while(full && i<capacity) {
        if(container[i] == NULL) {
            full = false;
        }
        i++; 
    }
    return full; 
}

void Initialize(const string* container[], int capacity) {
    for(int i=0; i<capacity; i++) {
        container[i] = NULL; 
    }
}

void Display(const string* container[], int capacity) {
    if(isEmpty(container, capacity)) {
        cout << "<Empty>" << endl; 
        return;
    }
    for(int i=0; i<capacity; i++) {
        if(container[i] != NULL) {
            cout << *(container[i]) << endl; 
        }
    }
    cout << endl; 
}

bool Contains(const string* pItem, const string* container[], int capacity) {
    bool has = false; 
    int i=0; 
    while(!has && i<capacity) {
        if(container[i] == pItem) {
            has = true;
        }
        i++; 
    }
    return has; 

}

void Add(const string* pItem, const string* container[], int capacity) {
    if(isFull(container, capacity)) {
        cout << "Your inventory container is full. Can't add." << endl << endl; 
        return;
    }
    if(Contains(pItem, container, capacity)) {
        cout << "Item already present. Can't add." << endl << endl; 
        return; 
    }
    bool found = false; 
    int i=0;
    while(!found && i<capacity) {
        if(container[i] == NULL) {
            container[i] = pItem; 
            cout << "Item added." << endl << endl; 
            found = true; 
        }
        i++; 
    }
}

void Remove(const string* pItem, const string* container[], int capacity) {
    if(!Contains(pItem, container, capacity)) {
        cout << "Item is not in your inventory. Can't remove." << endl << endl; 
    }

    bool found = false; 
    int i=0; 
    while(!found && i<capacity) {
        if(container[i] == pItem) {
            container[i] = NULL;
            found = true;
            cout << "Item Removed." << endl << endl; 
        }
        i++; 
    }
}


int main() {
    const int NUM_ITEMS = 5; 
    const string items[NUM_ITEMS] = {"sword", "axe", "shield", "gold", "potion"};
    const int INVENTORY_CAPACITY = 3; 
    //array of pointers 
    const string* inventory[INVENTORY_CAPACITY]; //player's inventory 
    Initialize(inventory, INVENTORY_CAPACITY);


    int choice; 
    int itemNumber; 

    //show menu 
    cout << endl << "Welcome to Inventory!" << endl;
    do {
        //show menu
        cout << "Inventory" << endl; 
        cout << "--------------------------" << endl << endl;
        cout << "0 - Quit" << endl;
        cout << "1 - Display items in the inventory" << endl;
        cout << "2 - Add an item to the inventory" << endl;
        cout << "3 - Remove an item from the inventory" << endl << endl;
        cout << "Choice: "; 
        cin >> choice; 
        cout << endl; 

        switch(choice) {
            case 0: 
                cout << "Good-bye." << endl; 
                break;
            case 1: 
                cout << "Inventory: " << endl;
                Display(inventory, INVENTORY_CAPACITY);
                break;
            case 2: 
                //display list of items
                for(int i=0; i<NUM_ITEMS; i++) {
                    cout << i << " - "<< items[i] << endl; 
                }
                //get item to add
                do {
                    cout << endl << "Enter the number of the item you wish to add: "; 
                    cin >> itemNumber; 
                } while(itemNumber < 0 || itemNumber >= NUM_ITEMS); 
                //add to player's inventory
                Add(&items[itemNumber], inventory, INVENTORY_CAPACITY); 
                break; 
            case 3: 
                //display list of items
                for(int i=0; i<NUM_ITEMS; i++) {
                    cout << i << " - "<< items[i] << endl; 
                }
                //get item to remove
                do {
                    cout << endl << "Enter the number of the item you wish to remove: ";
                    cin >> itemNumber;
                } while(itemNumber < 0 || itemNumber >= NUM_ITEMS); 
                // remove from player's inventory
                Remove(&items[itemNumber], inventory, INVENTORY_CAPACITY);
                break;
            default: 
                cout << "Sorry, " << choice << " isn't a valid choice." << endl; 
        }
    } while(choice != 0);
    return 0; 
}