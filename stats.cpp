#include <iostream>
#include <iomanip> 
#include <cmath>
#include <vector>


using namespace std;


//returns the size of the vector
int getCount(vector<double> numbers) {
    return (int)numbers.size();
}

//returns sum of all numbers in vector
double getSum(vector<double> numbers) {
    double sum = 0;

    //adds each number of the vector to the variable sum
    for (int i = 0; i < (int)numbers.size(); i++) {
        sum = sum + numbers[i];
    }
    return sum;
}

//returns the average value of the vector
double getMean(vector<double> numbers, double sum) {
    double mean = sum/((int)numbers.size());
    return mean;
}

//returns the largest number in the vector
double getLargest(vector<double> numbers) {
    /* largest set to the first value of the vector, because if
    we set it to 0 or some concrete number, the vector could contain only
    numbers smaller than that, and this function wouldn't work */
    double largest = numbers[0];

    //assigns largest value in vector to "largest" variable
    for (int i = 0; i < (int)numbers.size(); i++) {
        if (largest < numbers[i]) {
            largest = numbers[i];
        }
    }
    return largest;
}


//returns the smallest value in vector
double getSmallest(vector<double> numbers) {
    //same reasoning as in getLargest function
    double smallest = numbers[0];
    for (int i = 0; i < (int)numbers.size(); i++) {
        if (smallest > numbers[i]) {
            smallest = numbers[i];
        }
    }
    return smallest;
}

//returns the differene between the greatest and smallest value in vector
double getRange(double largest, double smallest) {
    return (largest - smallest);
}

//returns the average deviation of each number in the vector from the mean
double getDeviation(vector<double> numbers, double mean) {
    
    double absDifferenceSum = 0;

    /*for each number in the vector, this loop takes the absolute value of
    the mean of the vector minus the number and adds it to the "absDifferenceSum"
    variable. This essentially creates a sum of the deviation of each number of 
    the vector from the mean, which we then use to get standard deviation.
     */
    for (int i = 0; i < (int)numbers.size(); i++) {
        absDifferenceSum += abs(mean - numbers[i]);
    }

    double deviation = absDifferenceSum / (int)numbers.size();
    return deviation;
}

/*
double getMode(vector<double> numbers) {
}
*/

int main(int, char**) 
{
    //this creates array of limit 1000
    double file[1000];

    /* this block creates a vector, "numbers", and pushes each value of the
    array into the vector. */
    vector<double> numbers;
    int i = 0;
    while (cin >> file[i]) {
        numbers.push_back(file[i]);
        i++;
    }


    //creates each variable
    int count = getCount(numbers);
    double sum = getSum(numbers);
    double mean = getMean(numbers, sum);
    double largest = getLargest(numbers);
    double smallest = getSmallest(numbers);
    double range = getRange(largest, smallest);
    double deviation = getDeviation(numbers, mean);

    //gives output
    cout << fixed << setprecision(6);
    cout << setw(12) << left << "count:" << count << "\n";
    cout << setw(12) << left << "sum:" << sum << "\n";
    cout << setw(12) << left << "mean:" << mean << "\n";
    cout << setw(12) << left << "largest:" << largest << "\n";
    cout << setw(12) << left << "smallest:" << smallest << "\n";
    cout << setw(12) << left << "range:" << range << "\n";
    cout << setw(12) << left << "deviation:" << deviation << "\n";


    return 0;
}