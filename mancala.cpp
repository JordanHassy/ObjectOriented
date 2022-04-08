#include <iostream>
#include "mancala.h"
using namespace std;

class Mancala;

int main()
{
    int playerMove;
    Mancala g;
    cout << g.getBoard();

    while (g.getPlayer() != -1) {
        cout << "Player " << g.getPlayer() << " move: ";
        cin >> playerMove;
        if(!g.move(playerMove)) {
            cout << "You can't do that move!\n\n";
            continue;
        }else {
            cout << g.getBoard();
        }

        cout << "score: " << g.getScore(0) << " to " << g.getScore(1) << endl;

    }

}