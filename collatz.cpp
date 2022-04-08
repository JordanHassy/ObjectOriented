#include <iostream>
using namespace std;

//returns the length of the collatz sequence when run on the given argument
int getCollatzLength(int num) {
    int length = 1;
    
    //does the collatz sequence on the the parameter num, incrementing length on each step
    while (num != 1) {
        length++;

        //if a number is even, using % 2 will give you 0 since there would be no remainder
        if (num % 2 == 0) {
            num /= 2;
        }else {
            num = num * 3 + 1;
        }
    }
    return length;
}


//returns the longest collatz length of each number from the first argument to the second
int getLongestCollatz(int firstNum, int secondNum) {
    int longest = 0;

    //lopos starting from the first parameter and ending at the second
    for (int i = firstNum; i <= secondNum; i++) {

        /*if the length of the collatz sequence run on the current number is larger than the
        current longest, longest takes on its value. This ensures by the time we get the 
        length of the sequence on all numbers from the first parameter to the second, we
        we will be left with the number of the longest sequence.*/
        if (getCollatzLength(i) > longest) {
            longest = getCollatzLength(i);
        }
    }
    return longest;
}

/*depending on how many arguments are entered, outputs the maximum collatz sequence length 
between two numbers, or outputs usage information.*/
int main(int argc, char *argv[]) {

    if (argc == 2){
        cout << "Maximum Collatz Sequence length between 1 and " << argv[1] << " is " 
        << getLongestCollatz(1, stoi(argv[1])) << ".\n";
    }else if (argc == 3) {
        cout << "Maximum Collatz Sequence length between " << argv[1] << " and " << argv[2] 
        << " is " << getLongestCollatz(stoi(argv[1]), stoi(argv[2])) << ".\n";
    }else {
        cout << "usage: collatz [min] max\n";
    }
    
}