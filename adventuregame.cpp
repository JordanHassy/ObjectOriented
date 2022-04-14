#include <iostream>
#include <vector>
#include <sstream>
#include "adventure.h"
using namespace std;

string toStr(Path path) {
    stringstream ss;
    ss << path;
    string s;
    ss >> s;
    return s;
}

char doorChar(Door door) {
    Path path;
    path.add(door);
    stringstream ss;
    ss << path;
    string s;
    ss >> s;
    return s[0];
}

char opposite (char c) {
    switch(c) { case 'N': return 'S'; case 'E': return 'W';
    case 'S': return 'N';}
    return 'E';
}


bool checkDeadEnd(string path, char door, bool deadEnd[][1000]) {
    if (path == "")
        return false;
    int row = 500, collumn = 500;
    path += door;
    for(int i = 0; i < (int)path.length(); i++) {
        if (path[i] == 'E') {
            collumn++;
        }else if (path[i] == 'S') {
            row--;
            }else if (path[i] == 'N') {
            row++;
        }else if (path[i] == 'W') {
            collumn--;
        }
    }
    return deadEnd[row][collumn];


}

int main() {
    Adventure game;
    vector<Path> vPath{};
    vPath.push_back(game.getStart());

    Room startingRoom = game.getRoom(vPath[0]);
    Room *currentRoom = &startingRoom;
    Door firstDoor = currentRoom->getFirstDoor();
    Door currentDoor = firstDoor;

    int pathCount = 0, doorsDeep = 0;
    vector<int> doorsTried{0};

    bool deadEnd[1000][1000];
    int row = 500, collumn = 500;
    for(;;) {
        if(doorsTried[doorsDeep] >= 7) {
            doorsTried[doorsDeep] = 0;
            string pathString = toStr(vPath[pathCount]);
            for (int i = 0; i < (int)pathString.length(); i++) {
                if (pathString[i] == 'E') {
                    collumn++;
                }else if (pathString[i] == 'S') {
                    row--;
                    }else if (pathString[i] == 'N') {
                    row++;
                }else if (pathString[i] == 'W') {
                    collumn--;
                }
            }
            deadEnd[row][collumn] = true;
            vPath.push_back(game.getStart());
            pathCount++;
            doorsDeep = 0;
            *currentRoom = game.getRoom(vPath[pathCount]);
            firstDoor = currentRoom->getFirstDoor();
            currentDoor = firstDoor;
            row = 500;
            collumn = 500;

        }
        if(currentRoom->isValidDoor(currentDoor) && !(checkDeadEnd(toStr(vPath[pathCount]), doorChar(currentDoor), deadEnd))) {
            doorsTried[doorsDeep]++;
            if(doorsDeep > 0) {
                if(doorChar(currentDoor) == opposite(toStr(vPath[pathCount])[doorsDeep-1])) {
                    currentDoor = currentRoom->getNextDoor(currentDoor);
                    continue;
                }
            } 
            if(vPath[pathCount].add(currentDoor)){
                doorsTried.push_back(0);
                doorsDeep++;
                *currentRoom = game.getRoom(vPath[pathCount]);
                if(currentRoom->isExit()) {
                    break;
                }
                firstDoor = currentRoom->getFirstDoor();
                currentDoor = firstDoor;
                doorsTried[doorsDeep] = 0;
            }else{
                currentDoor = currentRoom->getNextDoor(currentDoor);
                doorsTried[doorsDeep]++;
            }
            

        }else{
            doorsTried[doorsDeep]++;
            currentDoor = currentRoom->getNextDoor(currentDoor);
        }
    }
    cout << vPath[pathCount] << endl;


    return 0;
}
