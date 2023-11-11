
//Author: S.Thameem Ansari
//Including necessary header file 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Function to remove characters from each string based on the pattern
vector<string> removeCharacters(const vector<string>& strings, const string& pattern) {
    vector<string> modifiedStrings;

    for (const string& str : strings) {
        string modifiedStr = str;
        // Remove characters in the pattern from the current string
        modifiedStr.erase(remove_if(modifiedStr.begin(), modifiedStr.end(), 
                                    [&pattern](char c) { return pattern.find(c) != string::npos; }), 
                                    modifiedStr.end());
        modifiedStrings.push_back(modifiedStr);
    }

    return modifiedStrings;
}

int main() {
    vector<string> strings = {"apple", "banana", "cherry", "date"};
    string pattern = "aeiou";
    vector<string> modifiedStrings = removeCharacters(strings, pattern);

    // Print modified strings
    cout << "Modified strings: ";
    for (const string& str : modifiedStrings) {
        cout << "\"" << str << "\" ";
    }
    cout << endl;

    return 0;
}
