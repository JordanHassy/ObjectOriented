#include <iostream>
using namespace std;

void printTriangle(int value)
{
    for (int x = 1; x<=value; ++x) {
        for (int y = 1; y<=x; ++y) {
            cout << "*";
        }

        cout << "\n";
    }
    
}


int main(int argc,char *argv[])
{
    if (argc == 1) {
        printTriangle(8);
    }else{
        printTriangle(stoi(argv[1]));
    }
    
    return 0;
}