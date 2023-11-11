
//Author:S.Thameem Ansari
//including necessary header file
//In this code, the findSpiceCombinations function uses backtracking to explore all possible combinations of dishes,
//allowing reuse of the same dish in the combination if it helps achieve the target spiciness level. 
//The program prints all combinations that achieve the target spiciness level.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void findSpiceCombinations(vector<pair<string, int>>& dishes, int targetSpiciness, vector<int>& currentCombination, int currentSpiciness, int index) {
    if (currentSpiciness == targetSpiciness) {
        // Print the current combination
        cout << "Combination: ";
        for (int i = 0; i < currentCombination.size(); ++i) {
            cout << dishes[currentCombination[i]].first << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index; i < dishes.size(); ++i) {
        if (currentSpiciness + dishes[i].second <= targetSpiciness) {
            // Include the current dish in the combination
            currentCombination.push_back(i);
            currentSpiciness += dishes[i].second;
            // Recur with the same index to allow reuse of the current dish
            findSpiceCombinations(dishes, targetSpiciness, currentCombination, currentSpiciness, i);
            // Exclude the last added dish from the combination (backtrack)
            currentCombination.pop_back();
            currentSpiciness -= dishes[i].second;
        }
    }
}

int main() {
    vector<pair<string, int>> dishes = {{"Dish1", 4}, {"Dish2", 2}, {"Dish3", 5}};
    int targetSpiciness = 7;

    vector<int> currentCombination;
    int currentSpiciness = 0;
    int startIndex = 0;

    cout << "Possible combinations to achieve spiciness level " << targetSpiciness << ":\n";
    findSpiceCombinations(dishes, targetSpiciness, currentCombination, currentSpiciness, startIndex);

    return 0;
}
