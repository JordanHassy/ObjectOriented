#include <iostream>
using namespace std;




int main(int, char**) {
    double x[1000];
    int i = 0;
    while (cin >> x[i]) {
        cout << x[i];
        i++;
    }
    cout << sizeof(x);


    return 0;
}