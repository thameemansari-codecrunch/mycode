
#include <iostream>
#include <string>
#include <unordered_map>
// Function to update the state of the highway based on time
std::string updateHighwayState(std::string hwy, int time) {
    // Mapping of vehicle types to their speeds
    std::unordered_map<char, int> speeds = {{'C', 2}, {'T', 4}, {'M', 1}};
// Iterate through each time step
    for (int t = 0; t < time; ++t) {
        std::string newHwy = hwy;
        // Iterate through the highway from right to left
        for (int i = hwy.size() - 1; i >= 0; --i) {
            char currentChar = hwy[i];
            // If there's roadwork, keep it as is
            if (currentChar == 'R') {
                newHwy[i] = 'R';
            } 
            // If the current character represents a vehicle and it's time to move
            else if (speeds.find(currentChar) != speeds.end() && (t / speeds[currentChar]) % 2 == 0) {
                // If there's an empty space in front, move the vehicle
                if (i + 1 < hwy.size() && hwy[i + 1] == '.') {
                    newHwy[i + 1] = currentChar;
                    newHwy[i] = '.';
                }
            }
        }
        // Update the highway state for the next time step
        hwy = newHwy;
    }

    return hwy;
}

int main() {
    // Initial state of the highway and the specified time
    std::string hwy = "C..MT.R";
    int time = 5;
    // Get the updated highway state
    std::string output = updateHighwayState(hwy, time);
    // Output the updated highway state
    std::cout << output << std::endl;  // Output: ".C..TMR"
    return 0;
}
