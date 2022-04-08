#include <iostream>
#include <vector>

using namespace std;

int main(int, char**) 
{
    int dimentions[2];
    int i = 0;
    while (cin >> dimentions[i]) {
        i++;
        if (i >= 2) {
            break;
        }
    }

    
    int rows = dimentions[0];
    int collumns = dimentions[1];
    
    int matrix[rows * collumns];
    i = 0;
    while (cin >> matrix[i]) {
        i++;
    }


    cout << dimentions[1] << " " << dimentions[0] << "\n";
    for (int c = 0; c < collumns; c++) {
        for (int r = 0; r < rows; r++) {
            cout << matrix[c + (r * collumns)] << " ";
        }
        cout << "\n";
    }
    

    return 0;
}