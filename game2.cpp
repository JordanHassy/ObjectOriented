#include <iostream>
#include <fstream>
#include <random>
#include <time.h>
#include "guess.h"
using namespace std;

int main() {
    ifstream file("phrases.txt");
    string phrases[1000];
    int phrase_count {0};
    while(getline(file, phrases[phrase_count]))
        phrase_count++;
    
    string snowman[] = {
        "      __\n     |  |\n     |  |\n    /____\\\n   (  . . )\n    \\ --- /\n >--(  :  )--<\n    (  :  )\n     \\___/\n",
        "     ____\n   (  . . )\n    \\ --- /\n >--(  :  )--<\n    (  :  )\n     \\___/\n",
        "     ____\n   (  . . )\n    \\ --- /\n    (  :  )\n    (  :  )\n     \\___/\n",
        "     ____\n   (  . . )\n    \\ --- /\n    (  :  )\n     \\___/\n",
        "     ____\n   (  . . )\n    \\ --- /\n",
        "     ____\n   (  . . )\n"
    };

    srand(time(NULL));
    int word = rand() % 48;
    
    GuessingGame game(phrases[word]);

    while (!game.isComplete() && game.getMistakes() < 6) {
        cout << snowman[game.getMistakes()];
        cout << "\nMovie: " << game.getRevealed() << "\n\n";
        cout << "Letters incorrectly guessed: ";
        game.printLettersGuessed();
        cout << '\n';
        cout << "Guess a letter:  ";
        char guess;
        cin >> guess;
        game.makeGuess(guess);
        
    }

    if(game.isComplete()) {
        cout << "\n\nCongrats! You guessed the movie name with only " << game.getMistakes() << " mistakes!\nIt was " << game.getAnswer() << "\n";
    } else {
        cout << "\n\nYour snowman melted :(\nThe movie name was " << game.getAnswer() << '\n';
    }
}