#include <iostream>
#include <random>
#include <cmath>
#include "lightsout.h"
using namespace std;

int main(int argc, char* argv[]) {
    //either uses user input or generates a random number to turn off or on lights
    int number{};
    if (argc == 2){  
        number = stoi(argv[1]);
    }else{
        random_device roll;
        number = roll();

    }


    
    LightsOut game;
    //set certain lights on
    for (int i = 0; i < 25; i++){
        int row = i/5 + 1;
        int col = i%5 + 1;
        //uses the bits of the generated number to decide which lights are on
        if(((int)pow(2, i) & number) != 0) {
            game.on(row, col);
        }
    }


    int one = -1;
    int two = -1;
    //where the game is actually played
    while ((one != 0 && two != 0) && !game.success()) { 
        
        //print the board
        cout << "   1 2 3 4 5\n";
        for (int i = 1; i < 6; i++) {
            cout << i << " ";
            for (int j = 1; j < 6; j++) {
                if (game.get(i, j))
                    cout << "##";
                else
                    cout << "  ";
            }
            cout << '\n';
        }
        cout << "R C: ";
        
        cin >> one >> two;
        //check for correct input
        if (one > 0 && two > 0) {
            game.toggle(one, two);
        }
    }
    //only print "Congratulations!" if the game was actually completed
    if (game.success()) 
        cout << "Congratulations!\n";
    



    return 0;
}