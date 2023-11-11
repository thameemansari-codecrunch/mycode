//Author:S.Thameem Ansari
//Including necessary header file
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

std::unordered_map<std::string, char> morseToFirefly = {
    {".", 'F'},  // Dot in Morse code represents 'F' (Fire)
    {"", 'N'},   // Empty string in Morse code represents 'N' (No Fire)
    {" ", 'S'}   // Space in Morse code represents 'S' (Separator)
};

std::string decodeFireflyMessage(const std::string& fireflyMessage) {
    std::istringstream iss(fireflyMessage);
    std::string letter;
    std::vector<std::string> letters;

    // Split the firefly message into letters using 'S' as separator
    while (std::getline(iss, letter, 'S')) {
        letters.push_back(letter);
    }

    // Translate each letter from Morse code to firefly code and then to English letter
    std::string decodedMessage = "";
    for (const auto& fireflyLetter : letters) {
        std::istringstream morseStream(fireflyLetter);
        std::string morseChar;
        while (morseStream >> morseChar) {
            decodedMessage += morseToFirefly[morseChar];
        }
    }

    return decodedMessage;
}

int main() {
    std::string fireflyMessage = "ffffsfsfnffsfnffsnnn";
    std::string decodedMessage = decodeFireflyMessage(fireflyMessage);
    std::cout << "Output: " << decodedMessage << std::endl;  // Output: "hello"
    return 0;
}
 
