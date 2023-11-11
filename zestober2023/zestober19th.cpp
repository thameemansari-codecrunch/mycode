
//Author:S.Thameem Ansari//we include necessary header file
//we using std::string to store the vowels and iterate over each
//finally we check if num vowels is odd or even
#include <iostream>
#include <string>

std::string check_plumpness(std::string word) {
    std::string vowels = "aeiouAEIOU";
    int num_vowels = 0;
    for (char letter : word) {
        if (vowels.find(letter) != std::string::npos) {
            num_vowels++;
        }
    }
    if (num_vowels % 2 == 0) {
        return "PLUMP";
    } else {
        return "Super Plump";
    }
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";
    std::cin >> word;
    std::string result = check_plumpness(word);
    std::cout << "OUTPUT: " << result << std::endl;
    return 0;
}
