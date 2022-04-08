#include <iostream>

//included iomanip in order to be able to use setw() function to format numbers in line 27
#include <iomanip>

using namespace std;



int main(int argc, char *argv[]) 
{

    //if no arguments are entered with the program, it outputs required text
    if (argc == 1) 
    {
        cout << "usage: bargraph integer-list\n";
    } 
    

    else 
    {

        //loops through each argument entered in order to print out bar graph for each argument
        for (int argument = 1; argument < argc; argument++)
        {
            //outputs the formatted argument value along with a bar to keep things organized
            cout << setw(3) << argv[argument] << " |";

            //prints number of pounds based on the integer value of the current argument
            for (int pound = 0; pound < stoi(argv[argument]); pound++)
            {
                cout << "#";
            }
            cout << "\n";
        } 
    } 


    return 0;
}
