#include <iostream>

//iomanip included to use the setw function
#include <iomanip>

using namespace std;

/*prints the opertater being used and the collumn numbers 
from 1 to the ammount of collumns in the table */
void printCollumnNumbers(int collumns, char operation) {
    cout << setw(2) << operation << "|";
    for (int collumn = 1; collumn <= collumns; collumn++) {
        cout << setw(5) << collumn;
    }
    cout << "\n";
}

/* Prints dashes as a sort of horizontal line between 
the collumn numbers and the tables */
void printDashes(int collumns) {

    /* There are 3 spaces for the operator and there
     are 5 spaces of formatting for each collumn number,
     which is why the number of dashes I print is
     3 + (collumns * 5)
      */
    int dashes {3 + (collumns * 5)};

    //this loop prints the horizontal line of dashes
    for (int dash = 0; dash < dashes; dash++){
        cout << "-";
    }
    cout << "\n";
}

void printTable(int collumns, int rows, char operation) {
    //loops through each row of the table
    for (int row = 1; row <= rows; row++){

        //prints the current row number
        cout << setw(2) << row << "|";

        //prints each collumn of the current row
        for (int collumn = 1; collumn <= collumns; collumn++){

            /*checks what operator is being used, and prints
            out the number resulting from that operation in the 
            current collumn with width 5*/
            if (operation == '+'){
                cout << setw(5) << row + collumn;
            }else if(operation == '-'){
                cout << setw(5) << row - collumn;
            }else if(operation == 'x'){
                cout << setw(5) << row * collumn;
            }else if(operation == '/'){
                cout << setw(5) << row / collumn;
            }else if(operation == '%'){
                cout << setw(5) << row % collumn;
            }else if(operation == '&'){
                cout << setw(5) << (row & collumn);
            }else if(operation == '|'){
                cout << setw(5) << (row | collumn);
            }else if(operation == '^'){
                cout << setw(5) << (row ^ collumn);
            }
            
        }
        cout << "\n";
    }
}


/* This program takes two integer arguments from the user, and prints
a multiplication or other table using those two numbers*/
int main(int argc, char *argv[])
{
    /* if the user specifies an operator by entering a 3rd argument,
    that operator is used to print out the values of the table.
    Otherwise, the table defaults to a multiplication table*/
    if (argc == 4){
        printCollumnNumbers(stoi(argv[1]), argv[3][0]);
        printDashes(stoi(argv[1]));
        printTable(stoi(argv[1]), stoi(argv[2]), argv[3][0]);
    } else if (argc == 3) {
        char operation {'x'};
        printCollumnNumbers(stoi(argv[1]), operation);
        printDashes(stoi(argv[1]));
        printTable(stoi(argv[1]), stoi(argv[2]), operation);
    }

    return 0;
}