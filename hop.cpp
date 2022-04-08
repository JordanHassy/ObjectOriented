#include <iostream>
#include <vector>

using namespace std;

/*this function does the actual hopscotch part. The vector "ladders"
holds every value in the input file, and the "start" and "end" integers
tell us which index of the vector our current ladder starts and ends
*/
void hopscotch(vector<int> ladders, int start, int end) {
    //this block creates a bool array of all false to keep track of visited values
    bool visited[(int)ladders.size()];
    for(int i = 0; i < (int)ladders.size(); i++) {
        visited[i] = false;
    }

    //This loop hops around the current ladder
    int hopper = start;
    while(true) {
        //causes the hopper to hop around the ladder depending on the current index
        hopper += ladders[hopper];

        //checks to see if the current ladder spot is within range, or if it was already visited
        if (hopper < start){
            cout << "invalid\n";
            break;
        }else if(hopper > end) {
            cout << "valid\n";
            break;
        }else if(visited[hopper]) {
            cout << "invalid\n";
            break;
        }

        //marks the current ladder spot as visited
        visited[hopper] = true;
    }
}


int main(int, char**) {
    //creates a variable for the number of ladders using the first value in input file
    string numOfLadderString {};
    cin >> numOfLadderString;
    int numOfLadders = stoi(numOfLadderString);

    //puts the rest of the inputfile into the vector "allLadders"
    vector<int> allLadders;
    int testArray[10000];
    int y = 0;
    while (cin >> testArray[y]) {
        allLadders.push_back(testArray[y]);
        y++;
    }

    //creates two lists to hold the length and starting index of all of the ladders
    int ladderLength[numOfLadders];
    int ladderLengthIndex[numOfLadders];
    int holder{0};
    for (int i = 0; i < numOfLadders; i++) {
        ladderLength[i] = allLadders[holder];
        ladderLengthIndex[i] = holder;
        holder += (ladderLength[i] + 1);
    }

    //uses hopscotch function on all ladders using new "start" and "end" variables
    int start, end;
    for (int i = 0; i < numOfLadders; i++) {
        start = ladderLengthIndex[i] + 1;
        end = start + ladderLength[i] - 1;
        hopscotch(allLadders, start, end);
    }
    return 0;
}