
//Author:S.Thameem Ansari
// including necessary header file
// first find the adjacent number
//And add the adjacent value
//findMaxNonAdjacentValue is the function responsible 
//for finding the maximum total value of non-adjacent gems
// iam learned how to find the maximum value using adjacent
#include <iostream>
#include <vector>
#include <algorithm>

// Function to calculate the maximum total value of non-adjacent gems from even-indexed positions
int maxNonAdjacentValue(const std::vector<int>& values) {
    int n = values.size();

    // Base cases
    if (n == 1) {
        return values[0];
    }
    if (n == 2) {
        return std::max(values[0], values[1]);
    }

    // Initialize an array to store the maximum total values
    std::vector<int> dp(n, 0);
    dp[0] = values[0];
    dp[1] = std::max(values[0], values[1]);

    // Iterate through the gems and calculate the maximum total value considering non-adjacent gems
    for (int i = 2; i < n; ++i) {
        // Calculate the maximum value either by excluding the current gem or by including it
        dp[i] = std::max(dp[i - 1], dp[i - 2] + values[i]);
    }

    // Return the maximum total value considering the last gem or the second last gem
    return std::max(dp[n - 1], dp[n - 2]);
}

int main() {
    // Example input: values of gems
    std::vector<int> values = {3, 2, 5, 1, 4, 6, 1};

    // Calculate the maximum total value of non-adjacent gems
    int result = maxNonAdjacentValue(values);

    // Output the result
    std::cout << "Maximum Non-Adjacent Value: " << result << std::endl; // Output: 14

    return 0;
}
