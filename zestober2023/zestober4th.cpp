
//Author:S.Thameem ansari
//including necessary header file
//In this code, maxScore function calculates 
//the maximum score achievable within the given time limit based on the given difficulty levels of the questions.
#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std; 
int maxScore(vector<int>& questions, int timeLimit) { 
    int n = questions.size();
    // dp[i][j] represents the maximum score achievable with first i questions
    // and time limit j
    vector<vector<int>> dp(n + 1, vector<int>(timeLimit + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int difficulty = questions[i - 1];
        for (int j = 1; j <= timeLimit; ++j) {
            // If the current question can be answered within the time limit
            if (j >= difficulty) {
                // Choose the maximum score between not answering the current question
                // and answering the current question
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - difficulty] + 1);
            } else {
                // If the current question cannot be answered within the time limit,
                // choose the same score as the previous state
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][timeLimit];
}

int main() {
    vector<int> questions = {2, 3, 1, 4};
    int timeLimit = 5;
    int result = maxScore(questions, timeLimit);
    cout << "Maximum score: " << result << endl;
    return 0;
}
