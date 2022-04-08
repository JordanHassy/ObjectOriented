#include <iostream>
using namespace std;

void printPyramid(int value)
{
    //this loops through the rows from row 1 to the value of rows inputted by the user
    for (int row = 1; row<=value; ++row) {
        
        /*
        the number of whitespaces on each row is found by subtracting the number of stars
        in the row(1 + 2*row) from the number of stars in the biggest row(1 + 2*value)
        and dividing that by two, since each row of a pyramid has its whitespaces half on 
        one side, and half on the other, and we don't need to print the whitespace
        on the pyramids right side since there is already spcae there. So I just loop
        from 0 to the number of whitespaces I need to print, printing one whitespace 
        each time through the loop, and then I print the stars needed for that row.
        */
        for (int spaces = 0;      spaces < ( ((1 + 2*value) - (1 + 2*row))/2 );     ++spaces)
        {
            cout << " ";
        }


        /*
        This for loop prints the number of stars needed on the current row, which can be
        found using an arithmatic series formula from way back in Algebra 2. Since 
        each row of the pyramid is an odd number 2 greater than the row before, and your
        starting number is 1, the arithmatic series formula would be 1 + 2*(row-1). I 
        subtract one from x because on the first row, you need to start with one star, 
        so you need your formulat to be (1 + 2*0), and you get that number to start at 0 
        by subtracting 1 from row. I didn't subtract one in the whitespace loop because
        the variable spaces started at 0 and not 1 like row did
        */
        for (int stars = 1;     stars <= (1 + 2*(row-1));     ++stars) {
            cout << "*";
        }

        cout << "\n";
    }
    
}


int main(int argc,char *argv[])
{
    //if there is no second argument entered, num of rows defaults to 5
    if (argc == 1) {
        printPyramid(5);
    }else{
        printPyramid(stoi(argv[1]));
    }
    
    return 0;
}