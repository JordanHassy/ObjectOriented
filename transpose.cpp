#include <iostream>

using namespace std;

int main(int, char**) 
{

    /*This block of code creates an array, dimentions, 
    which contains the 2 numbers at the top of the text
    file that give the dimentions of the matrix.*/
    int dimentions[2];
    cin >> dimentions[0] >> dimentions[1];

    /*this makes it easier to follow and write the program
    especially when using loops */
    int rows = dimentions[0];
    int collumns = dimentions[1];
    
    /*this block creates an array with every value in the matrix
    in order */
    int matrix[rows * collumns];
    int i = 0;
    while (cin >> matrix[i]) {
        i++;
    }



    /*the following code outputs the transformed matrix. first by outputting
    the swapped dimentions, and then by giving output in a nested loop. The 
    transposing is done by printing the values of each collumn top
    to bottom instead of each row right to left */
    cout << collumns << " " << rows << "\n";

    /*this outside loop loops through each collumn of the matrix,
    as we need to print the values of the matrix collumn by collumn
    as stated in the last comment. */
    for (int c = 0; c < collumns; c++) {
        //this loop loops through the rows of the matrix.
        for (int r = 0; r < rows; r++) {
            /*to print the next row number in the collumn we are in, 
            we use this formula, which prints the matrix index of the
            collumn we are in, plus the row we are in multiplied by the
            number of collumns.*/
            cout << matrix[c + (r * collumns)];
            if ((r + 1) % rows != 0) 
                cout << " ";
        }
        /*once we are done outputting every number in the current collumn,
        we need a newline to keep the transposed matrix dimentions and shape 
        in tact */
        cout << "\n";
    }
    



    return 0;
}