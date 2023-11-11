
//Author:S.Thameem Ansari
I am not getting the output recheck and correct it
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

unordered_map<string, string> colorMap(const vector<string>& regions, const vector<pair<string, string>>& adjacency) {
    unordered_map<string, string> colors;
    unordered_set<string> availableColors = {"Red", "Blue", "Green", "Yellow", "Orange"};
    
    for (const auto& region : regions) {
        unordered_set<string> neighboringColors;
        for (const auto& neighborPair : adjacency) {
            if (neighborPair.first == region && colors.find(neighborPair.second) != colors.end()) {
                neighboringColors.insert(colors[neighborPair.second]);
            }
            else if (neighborPair.second == region && colors.find(neighborPair.first) != colors.end()) {
                neighboringColors.insert(colors[neighborPair.first]);
            }
        }
        
        string regionColor;
        for (const auto& color : availableColors) {
            if (neighboringColors.find(color) == neighboringColors.end()) {
                regionColor = color;
                break;
            }
        }
        
        colors[region] = regionColor;
        availableColors.erase(regionColor);
    }
    
    return colors;
}

int main() {
    vector<string> regions = {"A", "B", "C", "D"};
    vector<pair<string, string>> adjacency = {{"A", "B"}, {"A", "C"}, {"B", "D"}, {"C", "D"}};
    
    unordered_map<string, string> result = colorMap(regions, adjacency);
    
    // Print the result
    for (const auto& pair : result) {
        cout << "(" << pair.first << ": " << pair.second << ") ";
    }
    cout << endl;
    
    return 0;
}
 
