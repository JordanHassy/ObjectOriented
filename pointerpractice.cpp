// fill n elements starting a p with the value v
void arrayFill(int *p, int n, int v) {
    for (int i = 0; i < n; i++) {
        *(p + i) = v;
    }
}

// reverse the order of n elements starting a p
void arrayReverse(int *p, int n) {
    //first and second are made to hold the values I want to swap
    int first;
    int second;

    /*This loop swaps the outside elements of the array section I am
    reversing and works to the center. This reverses the array.
    I do ground division by 2 on 'n' in this loop because
    I am swapping two integers at a time, and therefore only need n
    to be half of its value */
    for (int i = 0; i < (n/2); i++) {

        //puts the to-be-swapped values in variables
        first = *(p + i);
        second = *(p + (n-1-i));

        //swaps the values 
        *(p + i) = second;
        *(p + (n-1-i)) = first;
    }
}

//copy n elements from q to p
void arrayCopy(int *p, int n, int *q) {
    for (int i = 0; i < n; i++) {
        *(p + i) = *(q + i);
    }
}

//iff n consecutive elements of p and q are equal
bool arrayEqual(int *p, int n, int *q) {

    /*loops through all chosen elements of arrays,
    and if any two values are not equal, returns false.
    If this loop finishes without returning false, it 
    returns true as all values must have been equal.*/
    for (int i = 0; i < n; i++) {
        if (*(q + i) != *(p + i)) {
            return false;
        }

    }
    return true;
}
