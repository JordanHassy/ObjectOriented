#include <iostream> 

using namespace std;

int main(int, char* argv[]) 
{
    int collumns {stoi(argv[1])};
    int rows {stoi(argv[2])};

    //creates a boolean array pointer with all values set to false
    bool * p = new bool[collumns*rows];
    for (int i = 0; i<(collumns*rows); i++) {
        *(p+i) = false;
    }
    
    //initializing all of the variables I'm using in the following loop
    int counterX = 0, counterY = 0, counterReflection = 0, loopCounter = 0;
    bool addX = true, addY = true;

    //if the current cell we are on is already visited(has the value "true"), the loop breaks
    while (!*(p+ (counterX + collumns*counterY))) {

        //sets the current cell to true, telling the program we have visited that cell
        *(p + (counterX + collumns*counterY)) = true;

        //increments counterX and counterY depending on the value of addX and addY
        if (addX) {
            counterX++;
        }else {
            counterX--;
        }
        if (addY) {
            counterY++;
        } else {
            counterY--;
        }

        /*checks if counterX has gone past either side of the "grid", corrects
        it, changes addX, and adds to the reflection counter */
        if(counterX >= collumns) {
            addX = false;
            counterX -= 2;
            counterReflection++;
        }else if (counterX < 0) {
            addX = true;
            counterX += 2;
            counterReflection++;
        }

        /*checks if counterY has gone past too high or low on the "grid", corrects
        it, changes addY, and adds to the reflection counter */
        if(counterY >= rows) {
            addY = false;
            counterY -= 2;
            counterReflection++;
        } else if (counterY < 0) {
            addY = true;
            counterY += 2;
            counterReflection++;
        }

        loopCounter++;
    }

    cout << loopCounter << " cells, " << counterReflection << " reflections\n";

    delete [] p;
    return 0;
}