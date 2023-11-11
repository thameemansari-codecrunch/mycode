
//Author:S.Thameem Ansari
//Including necessary header file 
#include <iostream>
#include <string>
using namespace std;
bool isClosedPath(string directions) {
    int vertical = 0, horizontal = 0;
for (char direction : directions) {
        if (direction == 'U') {
            vertical++;
        } else if (direction == 'D') {
            vertical--;
        } else if (direction == 'L') {
            horizontal--;
        } else if (direction == 'R') {
            horizontal++;
        }
    }
// Check if the final position is the same as the starting position
    return (vertical == 0 && horizontal == 0);
}
int main() {
    string directions = "UDLR"; // Example sequence of directions
    bool isClosed = isClosedPath(directions);

    if (isClosed) {
        cout << "The sequence forms a closed path." << endl;
    } else {
        cout << "The sequence does not form a closed path." << endl;
    }
return 0;
}
