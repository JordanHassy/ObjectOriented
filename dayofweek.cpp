#include <iostream>

using namespace std;

/*returns an integer 0-6 which correlates to Sunday through Saturday respectively.
Equation was given, so no explaining there. */
int dayofweek(int month, int day, int year) {
    int y = year - ((14-month)/12);
    int x = y + (y/4) - (y/100) + (y/400);
    int m = month + 12*((14-month)/12) - 2;
    int d = (day + x + ((31 * m)/12))%7;

    return d;
}

/*when given a number 0-6, returns a string containing the day of the week that
number correlates to */
string getDayName(int dayNum) {
    if (dayNum == 0) {
        return "Sunday";
    }else if (dayNum == 1) {
        return "Monday";
    }else if (dayNum == 2) {
        return "Tuesday";
    }else if (dayNum == 3) {
        return "Wednesday";
    }else if (dayNum == 4) {
        return "Thursday";
    }else if (dayNum == 5) {
        return "Friday";
    }else
        return "Saturday";
}

int main(int , char *argv[]) {
    int dayNum = dayofweek(stoi(argv[1]), stoi(argv[2]), stoi(argv[3]));

    string dayName = getDayName(dayNum);

    cout << argv[1]<< "/" << argv[2] << "/" << argv[3] << " falls on " << dayName << ".\n";

    return 0;
}