#include <iostream>

using namespace std;

/*the & is a pass by reference, which means the function
actually uses a reference to the actual variables passed
 instead of the value, which means we can actually change 
 the values in the functiom. Useful since functions can only
 return one value. You can effect more than one variable
 with this type of function. Avoid it tho.*/
void swap(int &a, int &b){
    int t = a;
    a=b;
    b=t;
}

int main(int, char *argv[]) 
{
    int x = stoi(argv[1]);
    int y = stoi(argv[2]);
    swap(x,y);
    //at this point the x and y variables are swapped
    cout << x << " " << y << "\n";
    

    return 0;
}