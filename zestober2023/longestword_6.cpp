
//Author:S.Thameem Ansari
//Including necessary header file 
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
bool isGoldenWord(const string& word) {
    int vowels = 0, consonants = 0;
    for (char ch : word) {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }
    // Check if the ratio of vowels to consonants is approximately the golden ratio
    double goldenRatio = (1 + sqrt(5)) / 2;
    double ratio = static_cast<double>(vowels) / static_cast<double>(consonants);
    return abs(ratio - goldenRatio) < 0.01;
}

string findLongestGoldenWord(const vector<string>& words) {
    string longestGoldenWord = "";
    int maxLength = 0;

    for (const string& word : words) {
        if (isGoldenWord(word) && word.length() > maxLength) {
            longestGoldenWord = word;
            maxLength = word.length();
        }
    }

    return longestGoldenWord;
}

int main() {
    vector<string> words = {"apple", "banana", "grape", "pear", "orange"};
    string longestGoldenWord = findLongestGoldenWord(words);
    
    cout << "Longest golden word: " << longestGoldenWord << endl;

    return 0;
}
