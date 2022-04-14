#include <iostream>
using namespace std;
class Room;
class Door {
    string way;
    Room * room;
public:
    Door() { room = nullptr; }
    Door(string name,Room *r) {
        way = name;
        room = r;
    }
    string getName() { return way; }
    Room * getRoom() { return room; }
};
class Room {
    string description;
    Door exits[10];
    int doors;
public:
    Room(string d) { 
        description = d; 
        doors = 0; 
    }
    
    void addExit(Door d) {
        exits[doors] = d;
        doors++;
    }
    void describe() {
        cout << "You are in " << description << endl;
        cout << "You can go ";
        for (int i=0; i<doors; i++)
            cout << exits[i].getName() << " ";
        cout << endl;
    }
    Room * getNextRoom(string s) {
        for (int i=0; i<doors; i++)
            if (exits[i].getName() == s)
                return exits[i].getRoom();
        return nullptr;
    }
};
int main()
{
    Room kitchen("a kitchen with a stove\nand lots of cabinets.");
    Room dining("a dining room. The table\nis set for a formal dinner.");
    Room hall("a hallway that connects the\ndining room and the kitchen.");
    kitchen.addExit(Door("west",&hall));
    hall.addExit(Door("east",&kitchen));
    hall.addExit(Door("south",&dining));
    dining.addExit(Door("north",&hall));
    dining.addExit(Door("secret",&kitchen));
    Room * currentRoom = &hall;
    cout << "Let's have an adventure.\n\n";
    for(;;) {
        currentRoom->describe();
        cout << "\n> ";
        string cmd;
        cin >> cmd;
        if (cmd == "exit")
            break;
        Room *other = currentRoom->getNextRoom(cmd);
        if (other != nullptr) { // if (other)
            cout << "You go " << cmd << ".\n";
            currentRoom = other;
        }
        else {
            cout << "You can't do that right now.\n";
        }
    }
    cout << "You have left the game.\n";
}