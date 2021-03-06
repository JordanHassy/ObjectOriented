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

/*
bool doorUsed(int pathCount, vector<Path> vPath, Door currentDoor) {
    char rooms[1000][1000];
    for(int i = 0; i < 1000; i++) 
        for(int j = 0; j < 1000; j++) 
            rooms[i][j] = '_';
    
    int row = 500, collumn = 500;
    for (int j = 0; j < pathCount; j++) { 
        for(int i = 0; i < (int)toStr(vPath[j]).length(); i++) {
            if (toStr(vPath[j])[i] == 'E'){
                collumn++;
                rooms[row][collumn] = 'X';
            } else if (toStr(vPath[j])[i] == 'N'){
                row++;
                rooms[row][collumn] = 'X';
            } else if (toStr(vPath[j])[i] == 'W'){
                collumn--;
                rooms[row][collumn] = 'X';
            } else {
                row--;
                rooms[row][collumn] = 'X';
            }
        }
    }
    if(doorChar(currentDoor) == 'E' && rooms[row][collumn+1] == 'X'){
        return true;
    }else if(doorChar(currentDoor) == 'N' && rooms[row+1][collumn] == 'X'){
        return true;
    }else if(doorChar(currentDoor) == 'W' && rooms[row][collumn-1] == 'X'){
        return true;
    }else if(doorChar(currentDoor) == 'S' && rooms[row-1][collumn] == 'X') {
        return true;
    }
    vPath[pathCount].add(currentDoor);
    for(int i = 0; i < pathCount - 1; i++) {
        if (toStr(vPath[i]) == toStr(vPath[pathCount]))
            return true;
    }
    return false;
}
*/

bool checkDeadEnd(string path, char door, bool deadEnd[][1000]) {
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
        if(doorsTried[doorsDeep] >= 5) {
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
        if(currentRoom->isValidDoor(currentDoor)) {
            doorsTried[doorsDeep]++;
            if (checkDeadEnd(toStr(vPath[pathCount]), doorChar(currentDoor), deadEnd)){
                currentDoor = currentRoom->getNextDoor(currentDoor);
                continue;
            }
            if(doorsDeep > 0) {
                if(doorChar(currentDoor) == opposite(toStr(vPath[pathCount])[doorsDeep-1])) {
                    currentDoor = currentRoom->getNextDoor(currentDoor);
                    continue;
                }
            } 
            Path hold = vPath[pathCount];
            vPath[pathCount].add(currentDoor);
            if(toStr(hold) == toStr(vPath[pathCount])) {
                doorsTried[doorsDeep] += 5;
                continue;
            }
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
            doorsTried[doorsDeep]++;
            currentDoor = currentRoom->getNextDoor(currentDoor);
        }
    }
    cout << vPath[pathCount] << endl;


    return 0;
}
