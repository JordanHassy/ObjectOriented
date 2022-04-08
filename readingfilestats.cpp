#include <iostream>
#include <iomanip> 
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;



int getCount(vector<double> numbers) {
    return (int)numbers.size();
}

double getSum(vector<double> numbers) {
    double sum = 0;
    for (int i = 0; i < (int)numbers.size(); i++) {
        sum += numbers[i];
    }
    return sum;
}

double getMean(vector<double> numbers, double sum) {
    int count = (int)numbers.size();
    double mean = sum / count;
    return mean;
}

double getLargest(vector<double> numbers) {
    double largest = numbers[0];
    for (int i = 0; i < (int)numbers.size(); i++) {
        if (largest < numbers[i]) {
            largest = numbers[i];
        }
    }
    return largest;
}

double getSmallest(vector<double> numbers) {
    double smallest = numbers[0];
    for (int i = 0; i < (int)numbers.size(); i++) {
        if (smallest > numbers[i]) {
            smallest = numbers[i];
        }
    }

    return smallest;
}

double getRange(double largest, double smallest) {
    return largest - smallest;
}

double getDeviation(vector<double> numbers, double mean) {
    double absDeviationSum {0};
    for (int i = 0; i < (int)numbers.size(); i++) {
        absDeviationSum += abs(mean - numbers[i]);
    }
    double standardDeviation = absDeviationSum / (int)numbers.size();
    return standardDeviation;
}

int main(int argc, char *argv[]) 
{
    if (argc == 1) {
        cout << "please enter a filename in command line!\n";
        exit(1);
    }
    ifstream inFile (argv[1]);
    

    if (!inFile) {
        cout << "unable to open file\n";
        exit(1);
    }

    double input {};
    vector<double> numbers;
    while (inFile >> input) {
        numbers.push_back(input);
    }

    int count = getCount(numbers);
    double sum = getSum(numbers);
    double mean = getMean(numbers, sum);
    double largest = getLargest(numbers);
    double smallest = getSmallest(numbers);
    double range = getRange(largest, smallest);
    double deviation = getDeviation(numbers, mean);

    cout << fixed << setprecision(6);
    cout << setw(12) << left << "count:" << count << "\n";
    cout << setw(12) << left << "sum:" << sum << "\n";
    cout << setw(12) << left << "mean:" << mean << "\n";
    cout << setw(12) << left << "largest:" << largest << "\n";
    cout << setw(12) << left << "smallest:" << smallest << "\n";
    cout << setw(12) << left << "range:" << range << "\n";
    cout << setw(12) << left << "deviation:" << deviation << "\n";



    inFile.close();
    return 0;
}