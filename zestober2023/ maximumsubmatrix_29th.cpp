
//Author:S.Thameem Ansari
//including necessary header file
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxSubmatrixSum(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxSum = INT_MIN;

    // Calculate the sum of the first k rows in each column
    vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
        }
    }

    // Calculate the sum of each kxk submatrix using sliding window technique
    for (int i = k; i <= rows; ++i) {
        for (int j = k; j <= cols; ++j) {
            int submatrixSum = dp[i][j] - dp[i - k][j] - dp[i][j - k] + dp[i - k][j - k];
            maxSum = max(maxSum, submatrixSum);
        }
    }

    return maxSum;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 2;
    int result = maxSubmatrixSum(matrix, k);
    cout << "Maximum sum of " << k << "x" << k << " submatrix: " << result << endl;
    return 0;
}
