#include <iostream>
#include <vector>
#include "adventure.h"
using namespace std;


int main() {
    Adventure game;
    vector<Path> vPath{};
    vPath.push_back(game.getStart());

    vector<Path> allPaths{};
    allPaths.push_back(vPath[0]);

    cout << allPaths[0];
}