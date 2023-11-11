
//Author:S.Thameem Ansari
//Including necessary header file 
//My output is wrong I recheck and correct it 
#include <iostream>
#include <vector>
using namespace std;
string escapeCave(vector<int>& levels, int initialLife) {
    int currentLife = initialLife;
for (int i = 0; i < levels.size(); ++i) {
        currentLife -= levels[i];
        if (currentLife <= 0) {
            return to_string(levels[i]); // Return the danger level of the last room where life drops to zero or below
        }
    }
return "Safe"; // If you can reach the exit with a positive life value
}
int main() {
    vector<int> levels = {3, 2, 5, 1, 4};
    int initialLife = 10;
    string result = escapeCave(levels, initialLife);
if (result == "Safe") {
        cout << "You escaped safely!" << endl;
    } else {
        cout << "You couldn't escape. Your life dropped to zero or below in a room with danger level " << result << "." << endl;
    }
return 0;
}
